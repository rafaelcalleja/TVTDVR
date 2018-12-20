#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <windows.h>
#include <iostream>
#include "DVR_NET_SDK.h"

int main(int argc, char *argv[])
{
  char m_remoteIP[64];
  long m_remotePort;
  char m_username[64];
  char m_password[64];
  char m_deviceType[64];
  long m_userId;
  long channelId;
  char* filename = new char(255);

  memset(m_remoteIP, 0, sizeof(m_remoteIP));
  memset(m_username, 0, sizeof(m_username));
  memset(m_deviceType, 0, sizeof(m_password));
  memset(m_password, 0, sizeof(m_deviceType));

  // Check the number of parameters
  if (argc < 5) {
      // Tell the user how to run the program
      std::cerr << "Usage: " << argv[0] << " $IP $PORT $USERNAME $PASSWORD [$CHANNEL=1] [$FILEPATH=./screenshot.bmp]" << std::endl;
      /* "Usage messages" are a conventional way of telling the user
        * how to run a program if they enter the command incorrectly.
        */
      return EXIT_FAILURE;
  }

  channelId = 1;
  sprintf(filename, "./screenshot.bmp");
  
  std::string::size_type sz;   
  strcpy(m_remoteIP, argv[1]);
  m_remotePort = std::stoi(argv[2]);
  strcpy(m_username, argv[3]);
  strcpy(m_password, argv[4]);

  if (argc > 5) {
     channelId = std::stoi(argv[5], &sz);
  }

  if (argc > 6) {
	   sprintf(filename, argv[6]);
  }

  printf("IP %s\n", m_remoteIP);
  printf("Port %d\n", m_remotePort);
  printf("user %s\n", m_username);
  printf("pass %s\n", m_password);
  printf("channel %d\n", channelId);
  printf("file %s\n", filename);

  HMODULE h;
  HMODULE sdk;
  
  h = LoadLibrary("mfc90.dll");
  sdk = LoadLibrary("DVR_NET_SDK.dll");
 
  int(__cdecl * init)(void) = NULL;
  int(__cdecl * connect)(DWORD dwWaitTime, DWORD dwTryTimes) = NULL;
  int(__cdecl * reconnect)(DWORD dwInterval, DWORD bEnableRecon) = NULL;
  int(__cdecl * login)(char *sDVRIP,WORD wDVRPort,char *sUserName,char *sPassword,LPNET_SDK_DEVICEINFO lpDeviceInfo) = NULL;
  int(__cdecl * livePlay) (LONG lUserID, LPNET_SDK_CLIENTINFO lpClientInfo, LIVE_DATA_CALLBACK fLiveDataCallBack, void* pUser) = NULL;
  int(__cdecl * capturePicture) (POINTERHANDLE lLiveHandle, char *sPicFileName) = NULL;
  int(__cdecl * stopLive) (POINTERHANDLE lLiveHandle) = NULL;
  int(__cdecl * cleanUp)(void) = NULL;
  int(__cdecl * logout)(LONG lUserID) = NULL;

  (FARPROC&) init = GetProcAddress(sdk, "NET_SDK_Init");
  (FARPROC&) connect = GetProcAddress(sdk, "NET_SDK_SetConnectTime");
  (FARPROC&) reconnect = GetProcAddress(sdk, "NET_SDK_SetReconnect");
  (FARPROC&) login = GetProcAddress(sdk, "NET_SDK_Login");
  (FARPROC&) livePlay = GetProcAddress(sdk, "NET_SDK_LivePlay");
  (FARPROC&) capturePicture = GetProcAddress(sdk, "NET_SDK_CapturePicture");
  (FARPROC&) stopLive = GetProcAddress(sdk, "NET_SDK_StopLivePlay");
  (FARPROC&) cleanUp = GetProcAddress(sdk, "NET_SDK_Cleanup");
  (FARPROC&) logout = GetProcAddress(sdk, "NET_SDK_Logout");
   
  strcpy(m_deviceType, "");

  init();
  connect(4000, 1);
  reconnect(5000, TRUE);

  NET_SDK_DEVICEINFO info;
  m_userId = login(m_remoteIP, m_remotePort, m_username, m_password, &info);

  if (m_userId < 0)
  {
    printf("Error login as: %s\n", m_username);
    return FALSE;
  }  

	NET_SDK_CLIENTINFO clientInfo = { 0 };
	clientInfo.lChannel = channelId - 1;
	clientInfo.streamType = NET_SDK_MAIN_STREAM;
	clientInfo.hPlayWnd = NULL;

	LONG playHandle = livePlay(m_userId, &clientInfo, NULL, NULL);
	capturePicture(playHandle, filename);

	stopLive(playHandle);
	cleanUp();
	logout(m_userId);
	
  printf("Screenshot save at: %s\n", filename);

  return 1;
}
