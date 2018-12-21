#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#define WINE_NOWINSOCK
#include <windows.h>
#include <iostream>
#include "DVR_NET_SDK.h"
#include <iostream>
#include <ctime>
#include <boost/lexical_cast.hpp>
#include <string>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <algorithm>
#include <map>
#include <chrono>
#include <thread>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define PORT 7001

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    // Tell the user how to run the program
    std::cerr << "Usage: " << argv[0] << " config_file" << std::endl;
    /* "Usage messages" are a conventional way of telling the user
        * how to run a program if they enter the command incorrectly.
        */
    return EXIT_FAILURE;
  }

  std::map<std::string, std::string> config;

  std::ifstream cFile(argv[1]);
  if (cFile.is_open())
  {
    std::string line;
    while (getline(cFile, line))
    {
      line.erase(std::remove_if(line.begin(), line.end(), isspace),
                 line.end());
      if (line[0] == '#' || line.empty())
        continue;
      auto delimiterPos = line.find("=");
      auto name = line.substr(0, delimiterPos);
      auto value = line.substr(delimiterPos + 1);
      std::cout << name << " " << value << '\n';
      config[name] = value;
    }
  }
  else
  {
    std::cerr << "Couldn't open config file for reading.\n";
  }

  char m_remoteIP[64];
  long m_remotePort;
  char m_username[64];
  char m_password[64];
  char m_deviceType[64];
  long m_userId;
  long channelId;

  memset(m_remoteIP, 0, sizeof(m_remoteIP));
  memset(m_username, 0, sizeof(m_username));
  memset(m_deviceType, 0, sizeof(m_password));
  memset(m_password, 0, sizeof(m_deviceType));

  std::string::size_type sz;
  strcpy(m_remoteIP, config["ip"].c_str());
  m_remotePort = std::stoi(config["port"].c_str());
  strcpy(m_username, config["username"].c_str());
  strcpy(m_password, config["password"].c_str());
  channelId = std::stoi(config["channel"].c_str(), &sz);

  printf("IP %s\n", m_remoteIP);
  printf("Port %d\n", m_remotePort);
  printf("user %s\n", m_username);
  printf("pass %s\n", m_password);
  printf("channel %d\n", channelId);
  printf("directory %s\n", config["directory"].c_str());

  HMODULE h;
  HMODULE sdk;

  h = LoadLibrary("mfc90.dll");
  sdk = LoadLibrary("DVR_NET_SDK.dll");

  int(__cdecl * init)(void) = NULL;
  int(__cdecl * connect)(DWORD dwWaitTime, DWORD dwTryTimes) = NULL;
  int(__cdecl * reconnect)(DWORD dwInterval, DWORD bEnableRecon) = NULL;
  int(__cdecl * login)(char *sDVRIP, WORD wDVRPort, char *sUserName, char *sPassword, LPNET_SDK_DEVICEINFO lpDeviceInfo) = NULL;
  int(__cdecl * livePlay)(LONG lUserID, LPNET_SDK_CLIENTINFO lpClientInfo, LIVE_DATA_CALLBACK fLiveDataCallBack, void *pUser) = NULL;
  int(__cdecl * capturePicture)(POINTERHANDLE lLiveHandle, char *sPicFileName) = NULL;
  int(__cdecl * stopLive)(POINTERHANDLE lLiveHandle) = NULL;
  int(__cdecl * cleanUp)(void) = NULL;
  int(__cdecl * logout)(LONG lUserID) = NULL;

  (FARPROC &)init = GetProcAddress(sdk, "NET_SDK_Init");
  (FARPROC &)connect = GetProcAddress(sdk, "NET_SDK_SetConnectTime");
  (FARPROC &)reconnect = GetProcAddress(sdk, "NET_SDK_SetReconnect");
  (FARPROC &)login = GetProcAddress(sdk, "NET_SDK_Login");
  (FARPROC &)livePlay = GetProcAddress(sdk, "NET_SDK_LivePlay");
  (FARPROC &)capturePicture = GetProcAddress(sdk, "NET_SDK_CapturePicture");
  (FARPROC &)stopLive = GetProcAddress(sdk, "NET_SDK_StopLivePlay");
  (FARPROC &)cleanUp = GetProcAddress(sdk, "NET_SDK_Cleanup");
  (FARPROC &)logout = GetProcAddress(sdk, "NET_SDK_Logout");

  strcpy(m_deviceType, "");

  init();
  connect(4000, 1);
  reconnect(5000, TRUE);

  NET_SDK_DEVICEINFO info;
  m_userId = login(m_remoteIP, m_remotePort, m_username, m_password, &info);

  if (m_userId < 0)
  {
    printf("Error login as: %s\n", m_username);
    return EXIT_FAILURE;
  }

  NET_SDK_CLIENTINFO clientInfo = {0};
  clientInfo.streamType = NET_SDK_MAIN_STREAM;
  clientInfo.hPlayWnd = NULL;

  LONG playHandle;

  std::string directory = config["directory"];
  std::string extension = ".bmp";

  printf("%s\n", directory.c_str());

  struct dirent **namelist;
  int n;
  int filesCounter = 0;

  std::string channel_prefix = "_channel_";
  std::string filename;
  std::string ts;
  std::time_t timestamp;

  int server_fd, new_socket, valread;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  char buffer[1024] = {0};

  // Creating socket file descriptor
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
  {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  // Forcefully attaching socket to the port 8080
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                 &opt, sizeof(opt)))
  {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  // Forcefully attaching socket to the port 8080
  if (bind(server_fd, (struct sockaddr *)&address,
           sizeof(address)) < 0)
  {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  if (listen(server_fd, 3) < 0)
  {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  playHandle = livePlay(m_userId, &clientInfo, NULL, NULL);

  if (playHandle < 0)
  {
    printf("Error getting playHandle");
    return EXIT_FAILURE;
  }

  stopLive(playHandle);

  while (true)
  {
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                             (socklen_t *)&addrlen)) < 0)
    {
      perror("accept");
      exit(EXIT_FAILURE);
    }

    valread = read(new_socket, buffer, 1024);
    channelId = std::stoi(buffer, &sz);
    n = scandir(directory.c_str(), &namelist, 0, alphasort);

    if (n < 0)
    {
      perror("scandir");
      return EXIT_FAILURE;
    }
    else
    {
      filesCounter = 0;
      while (n--)
      {
        if (namelist[n]->d_name[0] != '.')
        {
          printf("%s\n", namelist[n]->d_name);
          filesCounter++;

          if (filesCounter > 10)
          {
            std::string removeFilename = directory + namelist[n]->d_name;
            printf("removed: %s\n", removeFilename.c_str());
            remove(removeFilename.c_str());
          }
        }

        free(namelist[n]);
      }

      free(namelist);
    }

    timestamp = std::time(0);
    ts = boost::lexical_cast<std::string>(timestamp);
    filename = directory + ts + channel_prefix + std::to_string(channelId) + extension;

    char *newFilename = new char[filename.size() + 1];
    std::strcpy(newFilename, filename.c_str());
    printf("Capturing Screenshot %s\n", newFilename);
    
    clientInfo.lChannel = channelId - 1;
    playHandle = livePlay(m_userId, &clientInfo, NULL, NULL);

    if (playHandle < 0)
    {
      printf("Error getting playHandle");
      return EXIT_FAILURE;
    }

    capturePicture(playHandle, newFilename);
    stopLive(playHandle);
    send(new_socket, newFilename, strlen(newFilename), 0 );
  }

  cleanUp();
  logout(m_userId);

  return EXIT_SUCCESS;
}
