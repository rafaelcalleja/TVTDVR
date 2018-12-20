
#ifndef _DVR_NET_SDK_H_
#define _DVR_NET_SDK_H_

#include "dvrdvstypedef.h"
#include "dvrdvsconfig.h"
#include "dvrdvsdefine.h"
#include "FrameInfo.h"

#ifdef WIN32

#define CALL_METHOD __stdcall

#ifdef __cplusplus
#define __EXTERN_C extern "C"
#else
#define __EXTERN_C extern
#endif

#ifdef DVR_NET_SDK_EXPORTS
#define NET_SDK_API __EXTERN_C __declspec(dllexport)
#else
#ifndef __STATIC__
#define NET_SDK_API __EXTERN_C __declspec(dllimport)
#else
#define NET_SDK_API
#endif
#endif

#else

#define CALL_METHOD
#define NET_SDK_API __attribute__ ((visibility("default")))

#endif

#if __cplusplus
extern "C"{
#endif

//#define gettid() syscall(__NR_gettid)

//LastError����
typedef enum
{
	NET_SDK_SUCCESS,
	NET_SDK_PASSWORD_ERROR,
	NET_SDK_NOENOUGH_AUTH,
	NET_SDK_NOINIT,
	NET_SDK_CHANNEL_ERROR,
	NET_SDK_OVER_MAXLINK,
	NET_SDK_LOGIN_REFUSED,
	NET_SDK_VERSION_NOMATCH,
	NET_SDK_NETWORK_FAIL_CONNECT,
	NET_SDK_NETWORK_NOT_CONNECT,
	NET_SDK_NETWORK_SEND_ERROR,
	NET_SDK_NETWORK_RECV_ERROR,
	NET_SDK_NETWORK_RECV_TIMEOUT,
	NET_SDK_NETWORK_ERRORDATA,
	NET_SDK_ORDER_ERROR,
	NET_SDK_OPER_BY_OTHER,
	NET_SDK_OPER_NOPERMIT,
	NET_SDK_COMMAND_TIMEOUT,
	NET_SDK_ERROR_SERIALPORT,
	NET_SDK_ERROR_ALARMPORT,
	NET_SDK_PARAMETER_ERROR,
	NET_SDK_CHAN_EXCEPTION,
	NET_SDK_NODISK,
	NET_SDK_ERROR_DISKNUM,
	NET_SDK_DISK_FULL,
	NET_SDK_DISK_ERROR,
	NET_SDK_NOSUPPORT,
	NET_SDK_BUSY,
	NET_SDK_MODIFY_FAIL,
	NET_SDK_PASSWORD_FORMAT_ERROR,
	NET_SDK_DISK_FORMATING,
	NET_SDK_DVR_NORESOURCE,
	NET_SDK_DVR_OPRATE_FAILED,
	NET_SDK_OPEN_HOSTSOUND_FAIL,
	NET_SDK_DVR_VOICEOPENED,
	NET_SDK_TIME_INPUTERROR,
	NET_SDK_NOSPECFILE,
	NET_SDK_CREATEFILE_ERROR,
	NET_SDK_FILEOPENFAIL,
	NET_SDK_OPERNOTFINISH,
	NET_SDK_GETPLAYTIMEFAIL,
	NET_SDK_PLAYFAIL,
	NET_SDK_FILEFORMAT_ERROR,
	NET_SDK_DIR_ERROR,
	NET_SDK_ALLOC_RESOURCE_ERROR,
	NET_SDK_AUDIO_MODE_ERROR,
	NET_SDK_NOENOUGH_BUF,
	NET_SDK_CREATESOCKET_ERROR,
	NET_SDK_SETSOCKET_ERROR,
	NET_SDK_MAX_NUM,
	NET_SDK_USERNOTEXIST,
	NET_SDK_WRITEFLASHERROR,
	NET_SDK_UPGRADEFAIL,
	NET_SDK_CARDHAVEINIT,
	NET_SDK_PLAYERFAILED,
	NET_SDK_MAX_USERNUM,
	NET_SDK_GETLOCALIPANDMACFAIL,
	NET_SDK_NOENCODEING,
	NET_SDK_IPMISMATCH,
	NET_SDK_MACMISMATCH,
	NET_SDK_UPGRADELANGMISMATCH,
	NET_SDK_MAX_PLAYERPORT,
	NET_SDK_NOSPACEBACKUP,
	NET_SDK_NODEVICEBACKUP,
	NET_SDK_PICTURE_BITS_ERROR,
	NET_SDK_PICTURE_DIMENSION_ERROR,
	NET_SDK_PICTURE_SIZ_ERROR,
	NET_SDK_LOADPLAYERSDKFAILED,
	NET_SDK_LOADPLAYERSDKPROC_ERROR,
	NET_SDK_LOADDSSDKFAILED,
	NET_SDK_LOADDSSDKPROC_ERROR,
	NET_SDK_DSSDK_ERROR,
	NET_SDK_VOICEMONOPOLIZE,
	NET_SDK_JOINMULTICASTFAILED,
	NET_SDK_CREATEDIR_ERROR,
	NET_SDK_BINDSOCKET_ERROR,
	NET_SDK_SOCKETCLOSE_ERROR,
	NET_SDK_USERID_ISUSING,
	NET_SDK_PROGRAM_EXCEPTION,
	NET_SDK_WRITEFILE_FAILED,
	NET_SDK_FORMAT_READONLY,
	NET_SDK_WITHSAMEUSERNAME,
	NET_SDK_DEVICETYPE_ERROR,
	NET_SDK_LANGUAGE_ERROR,
	NET_SDK_PARAVERSION_ERROR,
	NET_SDK_FILE_SUCCESS,
	NET_SDK_FILE_NOFIND,
	NET_SDK_NOMOREFILE,
	NET_SDK_FILE_EXCEPTION,
	NET_SDK_TRY_LATER,
	NET_SDK_DEVICE_OFFLINE,
	NET_SDK_CREATEJPEGSTREAM_FAIL,
    NET_SDK_USER_ERROR_NO_USER,
    NET_SDK_USER_ERROR_USER_OR_PASSWORD_IS_NULL,
    NET_SDK_USER_ERROR_ALREDAY_LOGIN,
    NET_SDK_USER_ERROR_SYSTEM_BUSY,
    NET_SDK_DEVICE_NOT_SUPPROT,////DEVICE��֧��
	NET_SDK_USER_ERROR_SYSTEM_NO_READY,//N9K�豸��û��׼���� �ոյ�¼��ȡԤ�õ�Ѳ����list��δ�ɹ�
	NET_SDK_CHANNEL_OFFLINE,//Ԥ��N9K�豸ʱͨ��������
	NET_SDK_GETREADYINFO_FAIL,//��ȡN9K������ʧ��
	NET_SDK_NORESOURCE,//SDK��Դ����
	NET_SDK_DEVICE_QUERYSYSTEMCAPS_FAIL,
	NET_SDK_INBUFFER_TOSMALL//����BUF����

}NET_SDK_ERROR;

enum NET_DEVICE_STATUS
{
	NET_DEVICE_STATUS_CONNECTED,
	NET_DEVICE_STATUS_DISCONNECT,
};

enum NET_SDK_STREAM_TYPE
{
	NET_SDK_MAIN_STREAM,
	NET_SDK_SUB_STREAM,
};

enum NET_SDK_PLAYCTRL_TYPE
{
	NET_SDK_PLAYCTRL_PAUSE,
	NET_SDK_PLAYCTRL_FF,
	NET_SDK_PLAYCTRL_REW,
	NET_SDK_PLAYCTRL_RESUME,
	NET_SDK_PLAYCTRL_STOP,
	NET_SDK_PLAYCTRL_FRAME,
	NET_SDK_PLAYCTRL_NORMAL,
	NET_SDK_PLAYCTRL_STARTAUDIO,	//�ÿ������ͼ�����������������ֻ����SDK�ڲ�������ʾʱ�Ż�������
	NET_SDK_PLAYCTRL_STOPAUDIO,
	NET_SDK_PLAYCTRL_AUDIOVOLUME,
	NET_SDK_PLAYCTRL_SETPOS,
};

enum NET_SDK_RPB_SPEED
{
	NET_SDK_RPB_SPEED_1_32X = 1,
	NET_SDK_RPB_SPEED_1_16X,
	NET_SDK_RPB_SPEED_1_8X,		//1/8
	NET_SDK_RPB_SPEED_1_4X,		//1/4
	NET_SDK_RPB_SPEED_1_2X,		//1/2
	NET_SDK_RPB_SPEED_1X,		//1
	NET_SDK_RPB_SPEED_2X,
	NET_SDK_RPB_SPEED_4X,
	NET_SDK_RPB_SPEED_8X,
	NET_SDK_RPB_SPEED_16X,
	NET_SDK_RPB_SPEED_32X,
};

const int MAX_NAMELEN			= 36;
const int MAX_CONTENTLEN		= 512;

#pragma pack(4)

//��¼�ṹ����
typedef struct _net_sdk_deviceinfo
{
	unsigned char	localVideoInputNum;		//������Ƶ����ͨ����Ŀ
	unsigned char	audioInputNum;			//��Ƶ����ͨ����Ŀ
	unsigned char	sensorInputNum;			//����������ͨ����Ŀ
	unsigned char	sensorOutputNum;		//�̵��������Ŀ
	unsigned int   displayResolutionMask;  //��������ѡ��ķֱ���

	unsigned char	videoOuputNum;			//��Ƶ�����Ŀ����֧�ֻط����ͨ������
	unsigned char	netVideoOutputNum;		//����ط����ͨ����Ŀ
	unsigned char	netVideoInputNum;		//�����źŽ���ͨ����Ŀ
	unsigned char	IVSNum;					//���ܷ���ͨ����Ŀ

	unsigned char	presetNumOneCH;			//ÿ��ͨ��Ԥ�õ���Ŀ
	unsigned char	cruiseNumOneCH;			//ÿ��ͨ��Ѳ������Ŀ
	unsigned char	presetNumOneCruise;		//ÿ��Ѳ���ߵ�Ԥ�õ���Ŀ
	unsigned char	trackNumOneCH;			//ÿ��ͨ���켣��Ŀ

	unsigned char	userNum;				//�û���Ŀ 
	unsigned char	netClientNum;			//���ͻ�����Ŀ
	unsigned char	netFirstStreamNum;		//�����������ͨ�������Ŀ����ͬʱ�����м����ͻ��˲鿴������
	unsigned char	deviceType;				// NET_SDK_DEVICE_TYPE

	unsigned char	doblueStream;			//�Ƿ����ṩ˫����
	unsigned char	audioStream;			//�Ƿ����ṩ��Ƶ��
	unsigned char	talkAudio;				//�Ƿ��жԽ�����: 1��ʾ�жԽ�����;0��ʾû��
	unsigned char	bPasswordCheck;			//�����Ƿ�Ҫ��������

	unsigned char	defBrightness;			//ȱʡ����
	unsigned char	defContrast;			//ȱʡ�Աȶ�
	unsigned char	defSaturation;			//ȱʡ���Ͷ�
	unsigned char	defHue;					//ȱʡɫ��

	unsigned short	videoInputNum;			//��Ƶ����ͨ����Ŀ�����ؼ����磩
	unsigned short  deviceID;				//�豸ID��
	unsigned int   videoFormat;            //ϵͳ��ǰ��ʽ

	//������FUNC_REMOTE_UPGRADE��Ӧ�Ĺ��ܣ���ô��FUNC_REMOTE_UPGRADE������Ϊ1������Ϊ�㡣
	unsigned int	function[8];			//��������

	unsigned int	deviceIP;				//�豸�����ַ
	unsigned char	deviceMAC[6];			//�豸�����ַ
	unsigned short	devicePort;				//�豸�˿�

	unsigned int	buildDate;				//��������:year<<16 + month<<8 + mday
	unsigned int	buildTime;				//����ʱ��:hour<<16 + min<<8 + sec

	char			deviceName[36];			//�豸����

	char	firmwareVersion[36];			//�̼��汾
	char	kernelVersion[64];				//�ں˰汾
	char	hardwareVersion[36];			//Ӳ���汾
	char	MCUVersion[36];					//��Ƭ���汾
    char	firmwareVersionEx[64];			//�̼��汾��չ����Ҫ����²�Ʒ
    unsigned int	softwareVer;//���Э��汾��Ŀǰ����IPC�İ汾����
    char	szSN[32];			//sn
    char	deviceProduct[28];			//�豸�ͺ�
}NET_SDK_DEVICEINFO, *LPNET_SDK_DEVICEINFO;

//����֡ͷ����
typedef struct _net_sdk_frame_info
{
	unsigned int		deviceID;
	unsigned int       channel;
	unsigned int		frameType;	//�ο�DD_FRAME_TYPE
	unsigned int		length;
	unsigned int		keyFrame;	//0���ǹؼ�֡ 1���ؼ�֡
	unsigned int       width;
	unsigned int       height;
	unsigned int		frameIndex;
	unsigned int		frameAttrib;//�ο�DD_FRAME_ATTRIB
	unsigned int		streamID;
	LONGLONG			time;	   //��1970��1��1��0��0��0�뿪ʼ�ľ���ʱ�䣬��λ΢��
	LONGLONG			relativeTime;//���ʱ�䣬��λ΢��
}NET_SDK_FRAME_INFO;

//¼��ʱ����Ϣ����
typedef struct _net_sdk_rec_time
{
	DWORD			dwChannel;	//ͨ����
	DD_TIME			startTime;	//�ö�¼��ʼʱ��
	DD_TIME			stopTime;	//�ö�¼�����ʱ��
}NET_SDK_REC_TIME;

typedef struct _net_sdk_rec_file
{
	DWORD			dwChannel;
	DWORD			bFileLocked;
	DD_TIME			startTime;
	DD_TIME			stopTime;
	DWORD			dwRecType;
	DWORD			dwPartition;
	DWORD			dwFileIndex;
}NET_SDK_REC_FILE;

typedef struct _net_sdk_rec_event
{
	DWORD			dwChannel;
	DD_TIME			startTime;
	DD_TIME			stopTime;
	DWORD			dwRecType;	//DD_RECORD_TYPE
}NET_SDK_REC_EVENT;

//��־��Ϣ����
typedef struct _net_sdk_log
{
	DD_TIME			strLogTime;
	DWORD			dwMajorType;
	DWORD			dwMinorType;
	char			sNetUser[MAX_NAMELEN];
	DWORD			dwRemoteHostAddr;
	char			sContent[MAX_CONTENTLEN];
}NET_SDK_LOG,*LPNET_SDK_LOG;

typedef struct _net_sdk_event
{
	unsigned short chnn;			//�¼���Ӧ��ͨ��
	unsigned short type;			//�¼����ͣ�DD_EVENT_TYPE
	DD_TIME        startTime;		//�¼������Ŀ�ʼʱ��
	DD_TIME        endTime;			//�¼��Ľ���ʱ��
}NET_SDK_EVENT,*LPNET_SDK_EVENT;

typedef struct _net_sdk_clientinfo
{
	LONG    lChannel;
	LONG    streamType;
	HWND    hPlayWnd;
    int     bNoDecode; //0:���룬 1�������� �����winƽ̨��Ĭ��0

}NET_SDK_CLIENTINFO, *LPNET_SDK_CLIENTINFO;

//�豸�ϴ���Ϣ����
enum NET_SDK_DEVICE_MSG_TYPE
{
	NET_SDK_ALARM,		//�豸������Ϣ
	NET_SDK_RECORD,		//�豸¼����Ϣ
	NET_SDK_IVM_RULE,	//������Ϊ������Ϣ(��ʱ����)
	NET_SDK_TRADEINFO,	//ATM������Ϣ(��ʱ����)
	NET_SDK_IPCCFG,		//�����DVR��IPC��Ϣ���(��ʱ����)
};

//�豸�ϴ���ϢΪ��������ʱ�ľ��屨������
enum NET_SDK_ALARM_TYPE
{
	NET_SDK_ALARM_TYPE_MOTION,		//�ƶ����
	NET_SDK_ALARM_TYPE_SENSOR,		//�ź�������
	NET_SDK_ALARM_TYPE_VLOSS,		//�źŶ�ʧ
	NET_SDK_ALARM_TYPE_SHELTER,		//�ڵ�����
	NET_SDK_ALARM_TYPE_DISK_FULL,	//Ӳ����
	NET_SDK_ALARM_TYPE_DISK_UNFORMATTED,//Ӳ��δ��ʽ��
	NET_SDK_ALARM_TYPE_DISK_WRITE_FAIL,	//��дӲ�̳���
	NET_SDK_ALARM_TYPE_EXCEPTION,
};


//�豸�ϴ���ϢΪ���ܱ������¼�����
enum NET_SDK_IVM_RULE_TYPE
{
    NET_SDK_IVM_RULE_TYPE_VFD, //����ʶ�𱨾�  NET_SDK_IVM_STATUS_INFO
    NET_SDK_IVM_RULE_TYPE_AVD_SCENE, //��Ƶ�쳣��ϳ����仯  NET_SDK_IVM_STATUS_INFO
    NET_SDK_IVM_RULE_TYPE_AVD_CLARITY, //��Ƶ�쳣�����Ƶģ��  NET_SDK_IVM_STATUS_INFO
    NET_SDK_IVM_RULE_TYPE_AVD_COLOR, //��Ƶ�쳣�����Ƶƫɫ  NET_SDK_IVM_STATUS_INFO
};


/************************************************************************/
    /*  ���屨��������������Դ    �ںܶ�ط�ʹ�����ö��ֵ��ʱ����ı�������BYTE����������
    ҪС�Ķ���*/
    /************************************************************************/

enum NET_SDK_N9000_ALARM_TYPE
{
    NET_SDK_N9000_ALARM_TYPE_RANGE_BEGIN,
    NET_SDK_N9000_ALARM_TYPE_MOTION=0x01,/////�ƶ���ⱨ������
    NET_SDK_N9000_ALARM_TYPE_SENSOR,/////��������������
    NET_SDK_N9000_ALARM_TYPE_VLOSS,////��Ƶ��ʧ��������
    NET_SDK_N9000_ALARM_TYPE_FRONT_OFFLINE, //////ǰ���豸���߱���
    NET_SDK_N9000_ALARM_TYPE_OSC,           ////��Ʒ������ⱨ��
    NET_SDK_N9000_ALARM_TYPE_AVD,           ////��Ƶ�쳣��ⱨ��
    NET_SDK_N9000_ALARM_TYPE_AVD_SCENE,//only IPC
    NET_SDK_N9000_ALARM_TYPE_AVD_CLARITY,//only IPC
    NET_SDK_N9000_ALARM_TYPE_AVD_COLOR,//only IPC

    NET_SDK_N9000_ALARM_TYPE_PEA_TRIPWIRE,  ////Խ����ⱨ��
    NET_SDK_N9000_ALARM_TYPE_PEA_PERIMETER, ////����������ⱨ��
    //NET_SDK_N9000_ALARM_TYPE_PEA,           ////Խ�����������������⣨�ֳ���������ٴ�����
    NET_SDK_N9000_ALARM_TYPE_VFD,           ////������⣨Ŀǰ��IPC��
    NET_SDK_N9000_ALARM_TYPE_CDD,           ////Crowdy density
    NET_SDK_N9000_ALARM_TYPE_IPD,           ////people intrusion
    NET_SDK_N9000_ALARM_TYPE_CPC,           ////people counting
    NET_SDK_N9000_ALARM_TYPE_FACE_MATCH,    ////�����ȶԱ���

    NET_SDK_N9000_ALARM_TYPE_GPS_SPEED_OVER=0x21,//�ͳ����йصı���������
    NET_SDK_N9000_ALARM_TYPE_GPS_CROSS_BOADER,//Խ��
    NET_SDK_N9000_ALARM_TYPE_GPS_TEMPERATURE_OVER,//�¶ȱ���
    NET_SDK_N9000_ALARM_TYPE_GPS_GSENSOR_X,//GSENSOR����
    NET_SDK_N9000_ALARM_TYPE_GPS_GSENSOR_Y,
    NET_SDK_N9000_ALARM_TYPE_GPS_GSENSOR_Z,

    NET_SDK_N9000_ALARM_TYPE_EXCEPTION = 0x41,
    NET_SDK_N9000_ALARM_TYPE_IP_CONFLICT,   /////IP��ַ��ͻ
    NET_SDK_N9000_ALARM_TYPE_DISK_IO_ERROR, /////����IO����
    NET_SDK_N9000_ALARM_TYPE_DISK_FULL,	   /////������
    NET_SDK_N9000_ALARM_TYPE_RAID_SUBHEALTH, //�����ǽ���
    NET_SDK_N9000_ALARM_TYPE_RAID_UNAVAILABLE, //���в�����
    NET_SDK_N9000_ALARM_TYPE_ILLEIGAL_ACCESS,  /////�Ƿ�����
    NET_SDK_N9000_ALARM_TYPE_NET_DISCONNECT,  /////����Ͽ�
    NET_SDK_N9000_ALARM_TYPE_NO_DISK,		////������û�д���
    NET_SDK_N9000_ALARM_TYPE_SIGNAL_SHELTER, //�ź��ڵ�
    NET_SDK_N9000_ALARM_TYPE_HDD_PULL_OUT, //ǰ���Ӳ�̰γ�

    NET_SDK_N9000_ALARM_TYPE_ALARM_OUT = 0x51,  /////������������ͣ��������Ҳ��״̬��Ҫ����

    NET_SDK_N9000_ALARM_TYPE_RANGE_END = 0xFF,////���ܳ������ֵ  ��������
};


//�豸�ϴ���ϢΪ��������ʱ���ϴ���Ϣ�ṹ
typedef struct _net_sdk_alarminfo
{
	DWORD		dwAlarmType;
	DWORD		dwSensorIn;		//��������������˿ں�
	DWORD		dwChannel;		//�ڱ�����ͨ�����ʱ����ʾ������ͨ����
	DWORD		dwDisk;			//�ڴ��̱���ʱ����ʾ���������Ĵ��̺�
}NET_SDK_ALARMINFO;

typedef struct _net_sdk_record_status
{
	DWORD		dwRecordType;		//DD_RECORD_TYPE
	DWORD		dwChannel;
}NET_SDK_RECORD_STATUS;

typedef struct _net_sdk_IVM_rule_status
{
    DWORD		dwIVMType;		//NET_SDK_IVM_RULE_TYPE
    DWORD		dwIVMSize;      //NET_SDK_IVM_RULE_TYPE���¼���Ӧ�Ľṹ���С
}
NET_SDK_IVM_RULE_STATUS;

//�������澯�ϱ�
typedef struct _net_sdk_IVM_status_info
{
    DWORD		dwAlarmType;    //NET_SDK_IVM_RULE_TYPE
    DWORD		dwChannel;		//�澯ͨ����

}NET_SDK_IVM_STATUS_INFO;

typedef enum _net_sdk_disk_status
{	
	NET_SDK_DISK_NORMAL,				//���� 
	NET_SDK_DISK_NO_FORMAT,				//δ��ʽ��
    NET_SDK_DISK_FORMATTING,				//���ڸ�ʽ��
    NET_SDK_DISK_EXCEPTION,				//  exception
}NET_SDK_DISK_STATUS;

typedef enum _net_sdkdisk_property
{
	NET_SDK_DISK_READ_WRITE = 0,			//��������д
	NET_SDK_DISK_ONLY_READ,					//ֻ�ܶ�������д
	NET_SDK_DISK_REDUNDANCY					//����
}NET_SDK_DISK_PROPERTY;

typedef enum _net_sdk_connect_type
{
	NET_SDK_CONNECT_TCP		= 0,			//TCP��ʽ��½
	NET_SDK_CONNECT_NAT		= 1,			//NAT��ʽ��½
    NET_SDK_CONNECT_NAT_TCP		= 2,			//��NAT���е�TCP����

	NET_SDK_CONNECT_END
}NET_SDK_CONNECT_TYPE;

typedef enum _net_sdk_camera_type
{
	NET_SDK_NOT_SUPPORT_PTZ		= 0,		//��֧����̨��ǹ��
	NET_SDK_DOME_SUPPORT_PTZ	= 1,		//֧����̨��ǹ��
	NET_SDK_SUPPORT_PTZ			= 2,		//֧����̨�����
	NET_SDK_PTZ_END
}NET_SDK_CAMERA_TYPE;

typedef struct _net_sdk_disk_info
{
	LONG		diskIndex;			//���̱��
	short		diskStatus;			//����״̬���ο�NET_SDK_DISK_STATUS
	short		diskProperty;		//����״̬���ο�NET_SDK_DISK_PROPERTY
	DWORD		diskTotalSpace;		//�����ܿռ䣬��λMB
	DWORD		diskFreeSpace;		//����ʣ��ռ䣬��λMB
}NET_SDK_DISK_INFO;

typedef struct
{
	WORD     wPicSize;
	WORD     wPicQuality;
}NET_SDK_JPEGPARA,*LPNET_SDK_JPEGPARA;

typedef enum _net_sdk_exception_type
{
	NETWORK_DISCONNECT = 0,
	NETWORK_RECONNECT,
	NETWORK_CH_DISCONNECT,	//ͨ������
	NETWORK_CH_RECONNECT,	//ͨ������
}NET_SDK_EXCEPTION_TYPE;

enum NET_SDK_DEVICE_TYPE
{
	NET_SDK_DVR,
	NET_SDK_DVS,
	NET_SDK_IPCAMERA,
	NET_SDK_NVR,
	NET_SDK_SUPERDVR,
	NET_SDK_DECODER,
};

typedef enum _net_sdk_device_firmware_type
{
	NET_SDK_DEVICE_FIRMWARE_V3,			
	NET_SDK_DEVICE_FIRMWARE_IPC,		
	NET_SDK_DEVICE_FIRMWARE_NVMS_V1,
	NET_SDK_DEVICE_FIRMWARE_OTHER,
}NET_SDK_DEVICE_FIRMWARE_TYPE;

typedef struct _net_sdk_device_discovery_info
{
	unsigned int		deviceType;		//NET_SDK_DEVICE_TYPE
	char				productType[16];
	char				strIP[16];
	char				strNetMask[16];
	char				strGateWay[16];
	unsigned char		byMac[8];
	unsigned short		netPort;
	unsigned short		httpPort;
	unsigned int		softVer;
	unsigned int		softBuildDate;
	unsigned char		ucIPMode;			//0 ��̬IP 1 dhcp
}NET_SDK_DEVICE_DISCOVERY_INFO;

typedef struct _net_sdk_device_ip_info_
{
	char szMac[36];					//�豸��ǰmac��ַ
	char szIpAddr[64];				//Ҫ�޸ĳɵ�ip
	char szMark[36];
	char szGateway[36];
	char szPassword[64];			//admin�û�������
	char szDdns1[36];
	char szDdns2[36];
	char ucIPMode;					//0Ϊ��̬IP, 1ΪDHCP
}NET_SDK_DEVICE_IP_INFO;

typedef struct _net_sdk_ipc_device_info_
{
	unsigned int	deviceID;				//�豸ID(��ʱδ����)
	unsigned short	channel;				//�������豸�ڱ��ط����ͨ��(��0��ʼ)
	unsigned short	status;					//����״̬��0�������ߣ�1��ʾ���ߣ�
	char			szEtherName[16];		//���Ϊ�գ�Ĭ��Ϊeth0
	char			szServer[64];			//�����豸IP��ַ
	unsigned short	nPort;					//�����豸�˿ں�
	unsigned short	nHttpPort;				//HTTP�˿�
	unsigned short	nCtrlPort;				//���ƶ˿ڣ�һ����nPort��ͬ
	char			szID[64];				//�����豸��ʶ(����MAC��ַ)
	char			username[36];			//�û���

	unsigned int	manufacturerId;			//�豸����ID(��ʱδ����)
	char			manufacturerName[36];	//�豸������(��ʱδ����)
	char			productModel[36];		//��Ʒ�ͺ�(��ʱδ����)
	unsigned char	bUseDefaultCfg;			//��ʱδ����
	unsigned char	bPOEDevice;				//��ʱδ����
	unsigned char	resv[2];				//��ʱδ����
}NET_SDK_IPC_DEVICE_INFO;

//ץͼ����
enum IMAGE_EVENT_TYPE
{
    IMAGE_TYPE_ALARM,
    IMAGE_TYPE_MANUAL,
};
//��������˳��
enum IMAGE_SORT_TYPE
{
    IMAGE_SORT_ASC,
    IMAGE_SORT_DESC,
};


typedef struct _net_sdk_image_
{
    DWORD			dwChannel; //ץͼͨ��
    DWORD			dwImageType; //ץͼ���� IMAGE_EVENT_TYPE
    DD_TIME_EX			captureTime;//ʱ��
    DWORD			totalNum;//ͼƬ����
    unsigned char	resv[8];
}NET_SDK_IMAGE;

typedef struct _net_sdk_image_sreach
{
    DWORD			dwChannel;//ץͼͨ��
    DD_TIME_EX			StartTime; //ʱ��
    DD_TIME_EX			StopTime; //ʱ��
    DWORD			pageIndex;//�ڼ�ҳ
    DWORD			pageSize;//ÿҳ��
    unsigned int sort; //��������˳�� //IMAGE_SORT_TYPE
    unsigned char	resv[8];
}NET_SDK_IMAGE_SREACH;


//ͼƬ����
enum IMAGE_MODE
{
    IMAGE_MODE_JPG,
    IMAGE_MODE_PNG,
    IMAGE_MODE_BMP,
};
typedef struct _net_sdk_image_info
{
    unsigned int	imageSize;
    unsigned int		imageMode; //IMAGE_MODE ͼƬ��ʽ
    unsigned char	resv[8];
}NET_SDK_IMAGE_INFO;

typedef enum __Channel_type__
{
    E_NULL_CHL_TYPE,
    E_DIGITAL_CHL_TYPE,     //����ͨ��
    E_ANALOG_CHL_TYPE,      //ģ��ͨ��
    E_ALARMOUT_CHL_TYPE,	  //�������ͨ��
    E_SENSOR_CHL_TYPE,	  //������ͨ��
}CHANNEL_TYPE;

typedef struct _net_sdk_channel_ptz
{
    unsigned int	dwChannel;
    unsigned int      eChanneltype;//CHANNEL_TYPE
    unsigned char	resv[8];
}NET_SDK_CHANNEL_PTZ;

typedef enum __IVM_rule_config_type__
{
    IVM_RULE_VFD_CONFIG, //����ʶ������
    IVM_RULE_VFD_TRIGGER_CONFIG, //����ʶ����������
    IVM_RULE_VFD_SCHEDULE_CONFIG, //����ʶ���ų�
    IVM_RULE_AVD_CONFIG, //�쳣��Ƶ����

}IVM_RULE_CONFIG_TYPE;

typedef struct _rectangle_
{
    unsigned int X1;
    unsigned int Y1;
    unsigned int X2;
    unsigned int Y2;
}RECTANGLE;
//IVM_RULE_VFD_CONFIG
typedef struct _net_sdk_Vfd_Config
{
    unsigned int      bSwitch; //ʹ�ܣ�0 or 1
    unsigned int      alarmHoldTime;//��������ʱ��
    unsigned int      saveFacePicture;//�������������ͼƬ
    unsigned int      saveSourcePicture;//�����������ԴͼƬ
    unsigned int      rectangleNum;
    RECTANGLE	rectangle;
    unsigned char	resv[40];
}NET_SDK_VFD_CONFIG;

//IVM_RULE_VFD_TRIGGER_CONFIG
typedef struct _net_sdk_Vfd_trigger_Config
{
    unsigned short    snapCHNum ; //֧�����ץͼͨ����
    unsigned char     snapChannelId;//ץͼͨ��
    unsigned char     snapBswitch ;//ץͼʹ��
    unsigned short    recordCHNum ; //֧�����¼��ͨ����
    unsigned char     recordChannelId;//¼��ͨ��
    unsigned char     recordBswitch ;//¼��ʹ��
    unsigned short    alarmOutCHNum ; //֧����󱨾������
    unsigned char     alarmOutChannelId;//�������ͨ��
    unsigned char     alarmOutBswitch ;//�������ʹ��
    unsigned char     Resv[256];//����������������չ��ͨ��

}NET_SDK_VFD_TRIGGER_CONFIG;

typedef struct
{
    unsigned char    byStartHour;
    unsigned char    byStartMin;
    unsigned char    byStopHour;
    unsigned char    byStopMin;
}NET_DVR_SCHEDTIME, *LPNET_DVR_SCHEDTIME;

typedef struct
{
    unsigned char    mounth;
    unsigned char    day;
    unsigned char    Resv[2];
    NET_DVR_SCHEDTIME sScheduleTime;

}NET_DVR_SCHEDDATE, *LPNET_DVR_SCHEDDATE; //���ض����ڶ����ų�

typedef struct
{
    unsigned int    wDay; //�������е�����������Ϊ0����������Ϊ6
    NET_DVR_SCHEDTIME sScheduleTime;

}NET_DVR_SCHEDWEEK, *LPNET_DVR_SCHEDWEEK;//���������������ų�

//IVM_RULE_VFD_SCHEDULE_CONFIG
typedef struct
{
    unsigned int wDayCount; //sScheduleWeek��Ч����
    unsigned int dayCount;  //sScheduleDate ��Ч����
    NET_DVR_SCHEDWEEK sScheduleWeek[70]; //�����Զ�70��
    NET_DVR_SCHEDDATE sScheduleDate[31]; //�����Զ�31��  ֵ��С����ipc��Э��

}NET_SDK_VFD_SCHEDULE_CONFIG;

//�뱸�����
typedef enum _net_sdk_backup_data_type
{
    NET_DVR_BACKUP_DATA_TYPE_DVR,
    NET_DVR_BACKUP_DATA_TYPE_AVI,
    NET_DVR_BACKUP_DATA_TYPE_NULL,
}NET_DVR_BACKUP_DATA_TYPE;

typedef struct _download_sdk_frame_info
{
    unsigned int		nLength;	//֡���ݳ���
    unsigned short		frameType;	//�ο�DD_FRAME_TYPE
    unsigned short		keyFrame;	//0���ǹؼ�֡ 1���ؼ�֡
    unsigned short		nWidth;		//�����, ��λ����, �������Ƶ������Ϊ0
    unsigned short		nHeight;	//�����, �������Ƶ������Ϊ0
    LONGLONG			nStamp;		//֡ʱ��, ��λ����, ��1970��1��1��0��0��0�뿪ʼ�ľ���ʱ��
}NET_DVR_DOWNlOAD_FRAME_INFO;

typedef enum _net_sdk_backup_status
{
    NET_DVR_BACKUP_STOP,
    NET_DVR_BACKUP_END,

}NET_DVR_BACKUP_STATUS;

typedef struct
{
    char                            serverAddress[256];             // ���ı�ʶ ���ڵ��������˶�ʹ��
    long long                          currentTime;                    // ��ǰʱ��
    long long                          terminationTime;                // ��ֹʱ��
    char                            resv[64];                       // ������չ��
}NET_DVR_SUBSCRIBE_REPLY;


// �����¼�����
typedef enum
{
    NET_DVR_SMART_AVD,            // ��Ƶ�쳣��Ϲ��ܼ��
    NET_DVR_SMART_VFD,            // �������

}NET_DVR_SMART_TYPE;

typedef struct
{
    int X;
    int Y;
}NET_DVR_IVE_POINT_T;
typedef struct
{
    LONGLONG      time;            //���Դ���ݵ�ǰʱ�� /* ΢�뼶 */
    LONGLONG      relativeTime;    //���Դ�������ʱ�� /* ΢�뼶 */
    unsigned int     detectDataLen;   //���Դ���ݳ���
    unsigned int     softwareVersion; //����汾��, 0xABCDEFGH,AB������ CD�����汾 EFGH���Ӱ汾 ���� 1:ŷķ�� �汾:V5.00
    unsigned int     softwareBuildDate;//�����������,0xYYYYMMDD
    unsigned int     faceCnt;         //�����ĸ��������40��
    unsigned int     faceDataLen[40]; //ÿ�������ĳ���
}NET_DVR_IVE_VFD_RESULT_HEAD_T;

typedef struct
{
    unsigned int     type;  ///<: 0, JPG; 1, YUV
    unsigned int     status; ///<:0, INVALID; 1, VALID; 2, SAVED
    unsigned int     width;
    unsigned int     height;
    unsigned int     dataLen;
}NET_DVR_IVE_VFD_RESULT_DATA_INFO_T;

typedef struct
{
    int                      faceId;         /* face ID Number */
    unsigned int                     ptWidth;        /*���������*/
    unsigned int                     ptHeight;       /*���������*/
    NET_DVR_IVE_POINT_T                 ptLeftTop;      /* Left-Top     Face Coordinates    */
    NET_DVR_IVE_POINT_T                 ptRightTop;     /* Right-Top    Face Coordinates    */
    NET_DVR_IVE_POINT_T                 ptLeftBottom;   /* Left-Bottom  Face Coordinates    */
    NET_DVR_IVE_POINT_T                 ptRightBottom;  /* Right-Bottom Face Coordinates    */
    int                      nPose;          /* Face Pose                        */
    int                      nConfidence;    /* Confidence Degree                */
    int                      age;
    int                      sex;
    int                      dtFrames;
    int                         featureSize;
    NET_DVR_IVE_POINT_T                 stPosFaceImg;  //�������Ͻ�����(�ڼ��ԴͼƬ��λ��)
    int                         reserved[14];
    NET_DVR_IVE_VFD_RESULT_DATA_INFO_T  stFaceImgData;
}NET_DVR_IVE_VFD_RESULT_FACE_DATA_INFO_T;


//IVM_RULE_AVD_CONFIG
typedef struct _net_sdk_AVD_Config
{
    unsigned int      alarmHoldTime; //��������ʱ��
    unsigned int      sceneChangeSwitch;//�������ʹ�ܣ�0 or 1
    unsigned int      clarityAbnormalSwitch;//��Ƶģ��ʹ�ܣ�0 or 1
    unsigned int      colorAbnormalSwitch;//��Ƶƫɫʹ�ܣ�0 or 1
    unsigned int      sensitivity;
    unsigned int      maxSensitivity;
    unsigned int      minSensitivity;
    char              resv[40];

}NET_SDK_AVD_CONFIG;

typedef struct
{
    unsigned int      eventId;               // �¼�ID
    unsigned int      status;                // ����״̬,0:none 1:start 2:end 3:procedure
    unsigned int      type;                  // ��������,0:none 1:Scene 2:Clarity 3:Color
}NET_SDK_IVE_AVD_INFO_T;

typedef struct
{
    unsigned int          count;             // ����
    NET_SDK_IVE_AVD_INFO_T   avdInfo[32];       // �쳣�����Ϣ
}NET_SDK_IVE_AVD_T;

typedef struct
{
    DD_TIME_EX  frameTime;   //֡ʱ��
	unsigned int dwRealFaceID;  //ץ������ID
	unsigned int dwGrpID;       //������ID
	unsigned int dwLibFaceID;   //����������ID
	unsigned int dwSimilar;     //���ƶ�
	unsigned char byName[32]; //����
    LONG Channel;         //ͨ��ID
	#ifdef __CHONGQING_ZHONGRAN__
	char    szCredential[DD_MAX_CERTIFICATE_NUM];  //֤������, '\0' ����,����Ψһ��
	char    serialNumber[32];  //���к�
	
	#endif
	unsigned int imgLen;      //�������ݳ���
	#ifdef __CHONGQING_ZHONGRAN__
	unsigned int BackLen;     //������ͼ���ݳ���
	#endif
}NET_SDK_IVE_FACE_MATCH_T;

typedef struct
{
    unsigned int          minValue;             // ��Сֵ
    unsigned int          maxValue;             // ���ֵ
    unsigned int          curValue;             // ��ǰֵ
    unsigned int          defaultValue;             // Ĭ��ֵ

}NET_SDK_IMAGE_EFFECT_T;

typedef struct _net_sdk_ch_device_status_
{
    unsigned short	channel;				//ͨ��(��0��ʼ)
    unsigned short	status;					//����״̬��0:offline��videoloss. 1: online,signal��
    unsigned int    chlType;               //E_DIGITAL_CHL_TYPE,����ͨ�� E_ANALOG_CHL_TYPE,ģ��ͨ��
    char	         name [DD_MAX_CAMERA_NAME_BUF_LEN];
    unsigned char	resv[32];				//��ʱδ����
}NET_SDK_CH_DEVICE_STATUS;

//�����Ա�
typedef enum _net_sdk_face_info_group__property_type
{
    NET_SDK_FACE_INFO_GROUP_PROPERTY_ALLOW,
    NET_SDK_FACE_INFO_GROUP_PROPERTY_REJECT,
    NET_SDK_FACE_INFO_GROUP_PROPERTY_LIMITED,

}NET_SDK_FACE_INFO_GROUP_PROPERTY_TYPE;

typedef struct _net_sdk_face_info_group_item_
{
    unsigned char	guid[48];				//GROUP GUID
    char	         name[DD_MAX_NAME_LEN];//GROUP NAME
    unsigned int	property;		//NET_SDK_FACE_INFO_GROUP_PROPERTY_TYPE
    unsigned int    groupId;               //
    unsigned int    enableAlarmSwitch;

}NET_SDK_FACE_INFO_GROUP_ITEM;

typedef struct _net_sdk_face_info_group_add_
{
    char	         name[DD_MAX_NAME_LEN];//GROUP NAME
    unsigned int	property;		//NET_SDK_FACE_INFO_GROUP_PROPERTY_TYPE
}NET_SDK_FACE_INFO_GROUP_ADD;

typedef struct _net_sdk_face_info_group_del_
{
    unsigned char	guid[48];				//GROUP GUID
}NET_SDK_FACE_INFO_GROUP_DEL;

//���߿���ѡ��һ
typedef struct _net_sdk_face_info_group_del_ex_
{
    unsigned int	groupId;				//GROUP ID ���ڶ��ư汾�ô˲���
    unsigned char   guid[48];				//GROUP GUID ͨ�ð汾�ô˲���
}NET_SDK_FACE_INFO_GROUP_DEL_EX;

typedef struct _net_sdk_face_info_list_get_
{			
    unsigned int	pageIndex;		//����1��2��3...
    unsigned int    pageSize;   //����
    unsigned int    groupId;//���� 1��2��3....

    char	        name[DD_MAX_NAME_LEN];//����ʱ��� NET_SDK_FACE_INFO_LIST_ITEM�е�name
    unsigned int    itemId;				//����ʱ���� NET_SDK_FACE_INFO_LIST_ITEM�е�itemId
    #ifdef __CHONGQING_ZHONGRAN__
    char	        certificateNum[DD_MAX_CERTIFICATE_NUM];		//
    #endif
}NET_SDK_FACE_INFO_LIST_GET;

typedef struct _net_sdk_face_info_list_item_groups_
{
    unsigned int    groupId;        //GROUP id ��ȡĿ��list���ص�ʱ��û�� guid
    unsigned char	guid[48];				//GROUP GUID ���ӣ��༭Ŀ�����Ҫ�� guid
    DD_TIME_EX    validStartTime;//propertyΪlimitedʱ����validStartTime��validEndTime
    DD_TIME_EX    validEndTime;//propertyΪlimitedʱ����validStartTime��validEndTime
}NET_SDK_FACE_INFO_LIST_ITEM_GROUPS;

typedef struct _net_sdk_face_info_list_item_
{
    unsigned int    itemId;				//id
    char	        name[DD_MAX_NAME_LEN];		//����
    unsigned int    sex; //0:male 1:female
    unsigned int    birthday;//eg:19900707
    char	        nativePlace[DD_MAX_NAME_LEN];		//
    unsigned int    certificateType; //0:idCard
    char	        certificateNum[DD_MAX_CERTIFICATE_NUM];		//
    char	        mobile[20];		//
    char	        number[20];		//
    unsigned int    faceImgCount;
    NET_SDK_FACE_INFO_LIST_ITEM_GROUPS    groups[DD_MAX_FACE_INFO_GROUPS];

}NET_SDK_FACE_INFO_LIST_ITEM;

typedef struct _net_sdk_face_info_list_
{
    unsigned int    totalNum;				//
    unsigned int    listNum;//return NET_SDK_FACE_INFO_LIST_ITEM num
    NET_SDK_FACE_INFO_LIST_ITEM *pFaceInfoListItem;
}NET_SDK_FACE_INFO_LIST;

typedef struct _net_sdk_face_img_info_ch_
{
    DD_TIME_EX         frameTime;
    unsigned int    imgId;
    unsigned int    chl; //����ֵ 255 ��ʾ�Ѿ�ɾ����ͨ��
    unsigned char   resv[8];//����

}NET_SDK_FACE_IMG_INFO_CH;

typedef struct _net_sdk_face_info_add_
{

    NET_SDK_FACE_INFO_LIST_ITEM sFaceInfoItem;
    unsigned int                imgNum;
    NET_SDK_FACE_IMG_INFO_CH       sFaceImgInfo[DD_MAX_FACE_INFO_IMG];//���5��
    unsigned int                haveImgData;//0��1
    unsigned int                imgWidth;//haveImgData ==1 ��Ч
    unsigned int                imgHeight;//haveImgData ==1 ��Ч
    unsigned int                imgLen;//haveImgData ==1 ��Ч
    unsigned char               *imgData;//haveImgData ==1 ��Ч
}NET_SDK_FACE_INFO_ADD;

typedef struct _net_sdk_face_info_edit_
{
    unsigned int            delFaceImgs[DD_MAX_FACE_INFO_IMG];
    NET_SDK_FACE_INFO_ADD   sFaceInfoItem;

}NET_SDK_FACE_INFO_EDIT;

typedef struct _net_sdk_face_info_del_
{
    unsigned int    faceInfoListItemId;//NET_SDK_FACE_INFO_LIST_ITEM�е�itemId
    unsigned int    groupsId[DD_MAX_FACE_INFO_GROUPS];//NET_SDK_FACE_INFO_LIST_ITEM�е�itemId-->groups-->groupId

}NET_SDK_FACE_INFO_DEL;

typedef struct _net_sdk_face_match_alarm_trigger_
{
    unsigned char	guid[48];	//GROUP GUID
    unsigned int    groupId;    //��ID
    unsigned char    groupSwitch;//����
    unsigned char    alarmOutSwitch;//�����������
    unsigned char    alarmOut[16];//�����������Ĭ�����16�� �±��1��ʼ
    unsigned char    recSwitch;//¼��
    unsigned int    recCH[128];//����¼��ͨ�� �±��1��ʼ
    unsigned char    snapSwitch;//ץͼ
    unsigned int    snapCH[128];//����ץͼͨ�� �±��1��ʼ
    unsigned int    popVideo;//��Ƶ����
    unsigned char    msgPushSwitch;
    unsigned char    buzzerSwitch;
    unsigned char    popMsgSwitch;
    unsigned char    emailSwitch;

}NET_SDK_FACE_MATCH_ALARM_TRIGGER;

typedef struct _net_sdk_face_match_chan_group_
{
	unsigned int    faceFeatureGroupsNum;  //ͨ��ӵ�е�Ŀ�������
    unsigned int    pfaceFeatureGroupIDs[16]; //ͨ��ӵ�е�Ŀ����ID�б�,��Ч����ΪfaceFeatureGroupsNum
}NET_SDK_FACE_MATCH_CHAN_GROUP;

typedef struct _net_sdk_face_match_alarm_
{
    unsigned int    similarity;//���ƶ�
    unsigned int    enableCH[128];//������ͨ���� ͨ���±��1��ʼ
	#ifdef __CHONGQING_ZHONGRAN__
	NET_SDK_FACE_MATCH_CHAN_GROUP FaceMatchChanGroup[128]; //�롾����ͨ�����ϸ��Ӧ
	#endif
    unsigned int    faceFeatureGroupsNum;//Ŀ�������
    NET_SDK_FACE_MATCH_ALARM_TRIGGER *pFaceMatchAlarmTrigger;

}NET_SDK_FACE_MATCH_ALARM;

typedef struct _net_sdk_face_info_img_get_
{

    unsigned int    itemId;	//Ŀ��id
    unsigned int    index;//faceImgCount�е�index 1��ʼ

}NET_SDK_FACE_INFO_IMG_GET;

typedef struct _net_sdk_face_info_img_data_
{
    unsigned int                imgLen;//Ŀ��ͼƬ����
    unsigned char               *imgData;//Ŀ��ͼƬ����
}NET_SDK_FACE_INFO_IMG_DATA;

typedef enum _net_sdk_search_image_by_image_type_
{
    SEARCH_IMAGE_BY_FACE_FEATURES,//ͨ��������������
    SEARCH_IMAGE_BY_FACE_IMAGES,//ͨ������ͼƬ����
    SEARCH_IMAGE_BY_FACE_FEATURE_GROUPS,//ͨ������������������
    SEARCH_IMAGE_BY_RECONGNIZED_FILTER,//ͨ����ָ��������������ȶ��Ƿ�ʶ����й���
    SEARCH_IMAGE_BY_FACE_IMAGE_DATA,//ͨ��ͼƬ���ݽ�������

}NET_SDK_SEARCH_IMAGE_BY_IMAGE_TYPE;

typedef struct _net_sdk_search_image_by_image_
{
    unsigned int	pageIndex;		//����1��2��3...
    unsigned int    pageSize;   //����
    unsigned int    similarity;		//���ƶ�
    unsigned int    resultCountLimit;		//�����������
    DD_TIME_EX    startTime;
    DD_TIME_EX    endTime;
    unsigned int searchType;//NET_SDK_SEARCH_IMAGE_BY_IMAGE_TYPE
    struct
    {
       unsigned int itemId;	//Ŀ��id
    } sfaceFeatures;//SEARCH_IMAGE_BY_FACE_FEATURES
    NET_SDK_FACE_IMG_INFO_CH sfaceImgs;//SEARCH_IMAGE_BY_FACE_IMAGES

    struct
    {
       unsigned int	groupsId;				//GROUP Id
    }sfaceFeatureGroups ;//SEARCH_IMAGE_BY_FACE_FEATURE_GROUPS

    struct
    {
       unsigned int     isContainRecognized; //0 or 1
       unsigned int     isContainNotRecognized; //0 or 1
       unsigned int     groupsId;				//GROUP Id
    }srecognizedFilter ;//SEARCH_IMAGE_BY_RECONGNIZED_FILTER
    struct
    {
        unsigned int                imgWidth;//
        unsigned int                imgHeight;//
        unsigned int                imgLen;//
        unsigned char               *imgData;//
    }sfaceImgData;//SEARCH_IMAGE_BY_FACE_IMAGE_DATA

}NET_SDK_SEARCH_IMAGE_BY_IMAGE;


typedef struct _net_sdk_search_image_item_
{
    DD_TIME_EX     recStartTime;
    DD_TIME_EX     recEndTime;
    unsigned int    similarity;		//���ƶ�
    unsigned int    faceFeatureId; //ͨ��������������ʱ�����ĸ�����ƥ��
    NET_SDK_FACE_IMG_INFO_CH sfaceImg; //ͨ������ͼƬ����ʱ�����ĸ�ͼƬƥ��
    unsigned char       resv[4];//����

}NET_SDK_SEARCH_IMAGE_ITEM;

typedef struct _net_sdk_search_image_by_image_list_
{
    unsigned int    bEnd; //Ϊ1������ͼ�����ѽ����� 0��ʾ���滹��
    unsigned int    listNum;//return NET_SDK_SEARCH_IMAGE_ITEM num
    NET_SDK_SEARCH_IMAGE_ITEM *pSearchImageItem;
}NET_SDK_SEARCH_IMAGE_BY_IMAGE_LIST;


typedef struct _net_sdk_ch_snap_face_img_list_
{
    unsigned int    bEnd; //Ϊ1������ͼ�����ѽ����� 0��ʾ���滹��
    unsigned int    listNum;//return NET_SDK_FACE_IMG_INFO_CH num
    NET_SDK_FACE_IMG_INFO_CH *pCHFaceImgItem;
}NET_SDK_CH_SNAP_FACE_IMG_LIST;

typedef struct _net_sdk_ch_snap_face_img_list_sreach_
{
    DWORD			dwChannel;//ץͼͨ��
    DD_TIME_EX			startTime; //ʱ��
    DD_TIME_EX			endTime; //ʱ��
    DWORD			pageIndex;//�ڼ�ҳ
    DWORD			pageSize;//ÿҳ��

    unsigned char	resv[8];
}NET_SDK_CH_SNAP_FACE_IMG_LIST_SEARCH;

//���������
typedef enum _net_sdk_face_match_operate_type
{
    NET_SDK_GET_FACE_MATCH_SUPPORT=0x01,//in:NULL, out:DWORD
    //Ŀ����
    NET_SDK_GET_FACE_INFO_GROUP_LIST,//queryFacePersonnalInfoGroupList in:NULL, out:NET_SDK_FACE_INFO_GROUP_ITEM list
    NET_SDK_ADD_FACE_INFO_GROUP,//createFacePersonnalInfoGroup in:NET_SDK_FACE_INFO_GROUP_ADD out:NULL
    NET_SDK_SET_FACE_INFO_GROUP,//editFacePersonnalInfoGroup in:NET_SDK_FACE_INFO_GROUP_ITEM  out:NULL
    NET_SDK_DEL_FACE_INFO_GROUP,//delFacePersonnalInfoGroups in:NET_SDK_FACE_INFO_GROUP_DEL  out:NULL
    //Ŀ��
    NET_SDK_GET_FACE_INFO_LIST,//queryFacePersonnalInfoList in:NET_SDK_FACE_INFO_LIST_GET, out:NET_SDK_FACE_INFO_LIST
    NET_SDK_ADD_FACE_INFO,//createFacePersonnalInfo in:NET_SDK_FACE_INFO_ADD out:DWORD
    NET_SDK_SET_FACE_INFO,//editFacePersonnalInfo in:NET_SDK_FACE_INFO_EDIT out:NULL
    NET_SDK_DEL_FACE_INFO,//delFacePersonnalInfo in:NET_SDK_FACE_INFO_DEL  out:NULL
    //�Աȱ�������
    NET_SDK_GET_FACE_MATCH_ALARM,//queryFaceMatchAlarm  in:NULL out:NET_SDK_FACE_MATCH_ALARM
    NET_SDK_SET_FACE_MATCH_ALARM,//editFaceMatchAlarm in:NET_SDK_FACE_MATCH_ALARM out:NULL
    //��������Ŀ��ͼƬ
    NET_SDK_GET_FACE_INFO_IMG,//requestFacePersonnalInfoImage in:NET_SDK_FACE_INFO_IMG_GET out:NET_SDK_FACE_INFO_IMG_DATA
    //��ͼ��ͼ searchImageByImage
    NET_SDK_SEARCH_IMAGE_BY_IMG, //searchImageByImage in:NET_SDK_SEARCH_IMAGE_BY_IMAGE out:NET_SDK_SEARCH_IMAGE_BY_IMAGE_LIST
    //��ѯͨ������ͼƬ
    NET_SDK_SEARCH_CH_SNAP_FACE_IMG_LIST,//queryChSnapFaceImageList in:NET_SDK_CH_SNAP_FACE_IMG_LIST_SEARCH out:NET_SDK_CH_SNAP_FACE_IMG_LIST
    //����ͨ������ͼƬ����
    NET_SDK_SEARCH_CH_SNAP_FACE_IMG,//requestChSnapFaceImage in:NET_SDK_FACE_IMG_INFO_CH out:NET_SDK_FACE_INFO_IMG_DATA
}NET_SDK_FACE_MATCH_OPERATE_TYPE;


#pragma pack()

////////////////////////////////////////�ص���������////////////////////////////////////////
typedef void (CALLBACK *EXCEPTION_CALLBACK)(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser);
typedef void (CALLBACK *DRAW_FUN_CALLBACK)(POINTERHANDLE lLiveHandle, HDC hDC, void *pUser);
typedef void (CALLBACK *LIVE_DATA_CALLBACK)(POINTERHANDLE lLiveHandle, NET_SDK_FRAME_INFO frameInfo, BYTE *pBuffer, void *pUser);
typedef void (CALLBACK *YUV_DATA_CALLBACK)(POINTERHANDLE lLiveHandle, DECODE_FRAME_INFO frameInfo, void *pUser);
typedef void (CALLBACK *LIVE_DATA_CALLBACK_EX)(POINTERHANDLE lLiveHandle, UINT dataType, BYTE *pBuffer, UINT dataLen, void *pUser);
typedef BOOL (CALLBACK *NET_MESSAGE_CALLBACK)(LONG lCommand, LONG lUserID, char *pBuf, DWORD dwBufLen, void *pUser);
typedef void (CALLBACK *PLAY_DATA_CALLBACK)(POINTERHANDLE lPlayHandle, NET_SDK_FRAME_INFO frameInfo, BYTE *pBuffer, void *pUser);
typedef void (CALLBACK *TALK_DATA_CALLBACK)(POINTERHANDLE lVoiceComHandle, char *pRecvDataBuffer, DWORD dwBufSize, BYTE byAudioFlag, void *pUser);
typedef void (CALLBACK *ACCEPT_REGISTER_CALLBACK)(LONG lUserID, LONG lRegisterID, LPNET_SDK_DEVICEINFO pDeviceInfo, void *pUser);
typedef void (CALLBACK *BACKUP_DATA_CALLBACK)(POINTERHANDLE lFileHandle, UINT dataType, BYTE *pBuffer, UINT dataLen, void *pUser);


////////////////////////////////////////////////////////////////////////////////
/********************************SDK�ӿں�������*********************************/
////////////////////////////////////////������Ϣ����¼�豸////////////////////////////////////////
//SDK��ʼ�����˳�
NET_SDK_API BOOL CALL_METHOD NET_SDK_Init();
NET_SDK_API BOOL CALL_METHOD NET_SDK_Cleanup();
//������������
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetConnectTime(DWORD dwWaitTime = 5000, DWORD dwTryTimes = 3);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetReconnect(DWORD dwInterval = 5000, BOOL bEnableRecon = TRUE);
//������ǰ���豸����
NET_SDK_API int CALL_METHOD NET_SDK_DiscoverDevice(NET_SDK_DEVICE_DISCOVERY_INFO *pDeviceInfo, int bufNum, int waitSeconds);
//SDK��������DVRע�� �ı��ض˿ں�
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetRegisterPort(WORD wRegisterPort);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetRegisterCallback(ACCEPT_REGISTER_CALLBACK fRegisterCBFun, void *pUser);
//�쳣��Ϣ�ص�����
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetSDKMessageCallBack(UINT nMessage, HWND hWnd, EXCEPTION_CALLBACK fExceptionCallBack, void *pUser);
//�汾��Ϣ
NET_SDK_API DWORD CALL_METHOD NET_SDK_GetSDKVersion();
NET_SDK_API DWORD CALL_METHOD NET_SDK_GetSDKBuildVersion();
//�����ѯ
NET_SDK_API DWORD CALL_METHOD NET_SDK_GetLastError();
//��¼�ǳ��豸
NET_SDK_API LONG CALL_METHOD NET_SDK_Login(char *sDVRIP,WORD wDVRPort,char *sUserName,char *sPassword,LPNET_SDK_DEVICEINFO lpDeviceInfo);
NET_SDK_API LONG CALL_METHOD NET_SDK_LoginEx(char *sDVRIP,WORD wDVRPort,char *sUserName,char *sPassword,LPNET_SDK_DEVICEINFO lpDeviceInfo, NET_SDK_CONNECT_TYPE eConnectType, const char *sDevSN = NULL);
NET_SDK_API BOOL CALL_METHOD NET_SDK_Logout(LONG lUserID);


////////////////////////////////////////�豸������Ϣ////////////////////////////////////////
//�豸������״̬�ص�
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetDVRMessageCallBack(NET_MESSAGE_CALLBACK fMessageCallBack, void *pUser);
NET_SDK_API LONG CALL_METHOD NET_SDK_SetupAlarmChan(LONG lUserID);
NET_SDK_API BOOL CALL_METHOD NET_SDK_CloseAlarmChan(LONG lAlarmHandle);
//������ѯ��ǰ������Ϣ��N9000��ǰ������ IPC��3.0�豸�����ϱ��ı���
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetAlarmStatus(LONG lUserID, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned);
//�ֶ�����\�رձ���
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetDeviceManualAlarm(LONG lUserID, LONG *pAramChannel, LONG *pValue, LONG lAramChannelCount, BOOL bAlarmOpen);


////////////////////////////////////////��ȡ�豸��Ϣ////////////////////////////////////////
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDeviceInfo(LONG lUserID, LPNET_SDK_DEVICEINFO pdecviceInfo);
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDeviceTime(LONG lUserID,DD_TIME *pTime);//��ȡ�豸��ǰʱ��
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDeviceIPCInfo(LONG lUserID, NET_SDK_IPC_DEVICE_INFO* pDeviceIPCInfo, LONG lBuffSize, LONG* pIPCCount);//��ȡNVR��IPCͨ����Ϣ
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDeviceCHStatus(LONG lUserID, NET_SDK_CH_DEVICE_STATUS* pDeviceCHStatus, LONG lBuffSize, LONG* pCHCount);//��ȡNVR��ͨ��״̬


////////////////////////////////////////Ԥ����ؽӿ�////////////////////////////////////////
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_LivePlay(LONG lUserID, LPNET_SDK_CLIENTINFO lpClientInfo, LIVE_DATA_CALLBACK fLiveDataCallBack = NULL, void* pUser = NULL);
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_LivePlayEx(LONG lUserID, LPNET_SDK_CLIENTINFO lpClientInfo, LIVE_DATA_CALLBACK_EX fLiveDataCallBack = NULL, void* pUser = NULL);
NET_SDK_API BOOL CALL_METHOD NET_SDK_StopLivePlay(POINTERHANDLE lLiveHandle);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetLiveDataCallBack(POINTERHANDLE lLiveHandle, LIVE_DATA_CALLBACK fLiveDataCallBack, void *pUser);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetLiveDataCallBackEx(POINTERHANDLE lLiveHandle, LIVE_DATA_CALLBACK_EX fLiveDataCallBack, void *pUser);
// ����YUV�ص��󣬿��ڻص�������YUV���ݣ������辡�췵�أ�����������ײ�����̡߳�������SDK��ʾʱ������NET_SDK_LivePlayʱ�����ھ����NULL���ɣ�
// ע�⣺�ù���Ŀǰ����windows�汾��Ч
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetYUVCallBack(POINTERHANDLE lLiveHandle, YUV_DATA_CALLBACK fYuvCallBack, void *pUser);

//��̬����I֡
NET_SDK_API BOOL CALL_METHOD NET_SDK_MakeKeyFrame(LONG lUserID, LONG lChannel);//������
NET_SDK_API BOOL CALL_METHOD NET_SDK_MakeKeyFrameSub(LONG lUserID, LONG lChannel);//������
//Ԥ��ʱ����Ч���Ŀ��Ʋ���
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetPlayerBufNumber(POINTERHANDLE lLiveHandle, DWORD dwBufNum);
//��������ַ���ͼ��
NET_SDK_API BOOL CALL_METHOD NET_SDK_RegisterDrawFun(POINTERHANDLE lLiveHandle, DRAW_FUN_CALLBACK fDrawFun, void *pUser);
//����
NET_SDK_API BOOL CALL_METHOD NET_SDK_OpenSound(POINTERHANDLE lLiveHandle);
NET_SDK_API BOOL CALL_METHOD NET_SDK_CloseSound();
NET_SDK_API BOOL CALL_METHOD NET_SDK_Volume(POINTERHANDLE lLiveHandle, WORD wVolume);
//���汾��¼��
NET_SDK_API BOOL CALL_METHOD NET_SDK_SaveLiveData(POINTERHANDLE lLiveHandle, char *sFileName);
NET_SDK_API BOOL CALL_METHOD NET_SDK_StopSaveLiveData(POINTERHANDLE lLiveHandle);
//Ԥ����ʾ��������
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetVideoEffect_Ex(LONG lUserID, LONG lChannel, NET_SDK_IMAGE_EFFECT_T *pBrightValue, NET_SDK_IMAGE_EFFECT_T *pContrastValue, NET_SDK_IMAGE_EFFECT_T *pSaturationValue, NET_SDK_IMAGE_EFFECT_T *pHueValue);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetVideoEffect_Ex(LONG lUserID, LONG lChannel, DWORD dwBrightValue, DWORD dwContrastValue, DWORD dwSaturationValue, DWORD dwHueValue);


////////////////////////////////////////��Ƶץͼ
//JPEGץͼ���ڴ�
NET_SDK_API BOOL CALL_METHOD NET_SDK_CaptureJPEGData_V2(LONG lUserID, LONG lChannel, char *sJpegPicBuffer, DWORD dwPicSize, LPDWORD lpSizeReturned);
NET_SDK_API BOOL CALL_METHOD NET_SDK_CaptureJPEGFile_V2(LONG lUserID, LONG lChannel, char *sPicFileName);
NET_SDK_API BOOL CALL_METHOD NET_SDK_CaptureJPEGPicture(LONG lUserID, LONG lChannel, LPNET_SDK_JPEGPARA lpJpegPara, char *sJpegPicBuffer, DWORD dwPicSize, LPDWORD lpSizeReturned);
//�豸�ϵ�ͼƬ��N9000֧��
NET_SDK_API BOOL CALL_METHOD NET_SDK_SearchPictures(LONG lUserID, NET_SDK_IMAGE_SREACH sInSreachImage, LONG lInImageBufferSize, NET_SDK_IMAGE *pOutImageInfo, LONG *pOutImageNum);
NET_SDK_API BOOL CALL_METHOD NET_SDK_RemoteSnap(LONG lUserID, int lChannel);//Զ��ץͼ
NET_SDK_API BOOL CALL_METHOD NET_SDK_DownLoadPicture(LONG lUserID, NET_SDK_IMAGE captureImage, NET_SDK_IMAGE_INFO *pOutImageInfo, char* pOutBuffer, int outBufferSize);


////////////////////////////////////////�豸¼���ļ��طš����غ�����////////////////////////////////////////
//�����ļ�ʱ�����¼���ļ�
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_FindFile(LONG lUserID, LONG lChannel, DD_TIME *lpStartTime, DD_TIME *lpStopTime);
NET_SDK_API LONG CALL_METHOD NET_SDK_FindNextFile(POINTERHANDLE lFindHandle, NET_SDK_REC_FILE *lpFindData);
NET_SDK_API BOOL CALL_METHOD NET_SDK_FindClose(POINTERHANDLE lFindHandle);
//�������ڲ���¼���ļ�
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_FindRecDate(LONG lUserID);
NET_SDK_API LONG CALL_METHOD NET_SDK_FindNextRecDate(POINTERHANDLE lFindHandle, DD_DATE *lpRecDate);
NET_SDK_API BOOL CALL_METHOD NET_SDK_FindRecDateClose(POINTERHANDLE lFindHandle);
//�����¼�����¼���ļ�
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_FindEvent(LONG lUserID, LONG lChannel, DWORD dwRecType, DD_TIME *lpStartTime, DD_TIME *lpStopTime);
NET_SDK_API LONG CALL_METHOD NET_SDK_FindNextEvent(POINTERHANDLE lFindHandle, NET_SDK_REC_EVENT *lpRecEvent);
NET_SDK_API BOOL CALL_METHOD NET_SDK_FindEventClose(POINTERHANDLE lFindHandle);
//����ʱ�����¼���ļ�
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_FindTime(LONG lUserID, LONG lChannel, DD_TIME *lpStartTime, DD_TIME *lpStopTime);
NET_SDK_API LONG CALL_METHOD NET_SDK_FindNextTime(POINTERHANDLE lFindHandle, NET_SDK_REC_TIME *lpRecTime);
NET_SDK_API BOOL CALL_METHOD NET_SDK_FindTimeClose(POINTERHANDLE lFindHandle);
//��ʱ��ط�¼���ļ�
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_PlayBackByTime(LONG lUserID, LONG *pChannels, LONG channelNum, DD_TIME *lpStartTime, DD_TIME *lpStopTime, HWND *hWnds);//main stream
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_PlayBackByTimeEx(LONG lUserID, LONG *pChannels, LONG channelNum, DD_TIME *lpStartTime, DD_TIME *lpStopTime, HWND *hWnds, BOOL bFirstStream);
NET_SDK_API BOOL CALL_METHOD NET_SDK_PlayBackControl(POINTERHANDLE lPlayHandle, DWORD dwControlCode, DWORD dwInValue, DWORD *lpOutValue);
NET_SDK_API BOOL CALL_METHOD NET_SDK_StopPlayBack(POINTERHANDLE lPlayHandle);
//ע��ص�����������¼������
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetPlayDataCallBack(POINTERHANDLE lPlayHandle, PLAY_DATA_CALLBACK fPlayDataCallBack, void *pUser);
//����طŵ�¼�����ݣ���������ļ�
NET_SDK_API BOOL CALL_METHOD NET_SDK_PlayBackSaveData(POINTERHANDLE lPlayHandle, LONG lChannel, char *sFileName);
NET_SDK_API BOOL CALL_METHOD NET_SDK_StopPlayBackSave(POINTERHANDLE lPlayHandle, LONG lChannel);
//�طŵ���������
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetPlayBackOsdTime(POINTERHANDLE lPlayHandle, DD_TIME *lpOsdTime);//��ȡ¼��ط�ʱ��ʾ��OSDʱ��
NET_SDK_API BOOL CALL_METHOD NET_SDK_PlayBackCaptureFile(POINTERHANDLE lPlayHandle, LONG lChannel, char *sFileName);//¼��ط�ʱץͼ�����������ļ���
NET_SDK_API BOOL CALL_METHOD NET_SDK_RefreshPlay(POINTERHANDLE lPlayHandle);//ˢ����ʾ�طŴ���
//����¼���ļ�
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_GetFileByTime(LONG lUserID, LONG lChannel, DD_TIME *lpStartTime, DD_TIME *lpStopTime, char *sSavedFileName);
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_GetFileByTimeEx(LONG lUserID,LONG lChannel, DD_TIME * lpStartTime, DD_TIME * lpStopTime, char *sSavedFileName, BOOL bCustomFormat, BOOL bUseCallBack=false, BACKUP_DATA_CALLBACK fBackupDataCallBack= NULL, void* pUser = NULL); //bCustomFormat���Ƿ�ʹ��˽���ļ���ʽ
NET_SDK_API BOOL CALL_METHOD NET_SDK_StopGetFile(POINTERHANDLE lFileHandle);
NET_SDK_API int CALL_METHOD NET_SDK_GetDownloadPos(POINTERHANDLE lFileHandle);
//¼���ļ�������������ɾ��
NET_SDK_API BOOL CALL_METHOD NET_SDK_LockFile(LONG lUserID, NET_SDK_REC_FILE *pFileToLock, LONG fileNum);
NET_SDK_API BOOL CALL_METHOD NET_SDK_UnlockFile(LONG lUserID, NET_SDK_REC_FILE *pFileToUnlock, LONG fileNum);
NET_SDK_API BOOL CALL_METHOD NET_SDK_DeleteRecFile(LONG lUserID, NET_SDK_REC_FILE *pFileToUnlock, LONG fileNum);
//Զ�̿����豸���ֶ�¼��
NET_SDK_API BOOL CALL_METHOD NET_SDK_StartDVRRecord(LONG lUserID, LONG lChannel, LONG lRecordType);
NET_SDK_API BOOL CALL_METHOD NET_SDK_StopDVRRecord(LONG lUserID, LONG lChannel);


////////////////////////////////////////��̨������ؽӿ�////////////////////////////////////////
//��̨����
NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZControl(POINTERHANDLE lLiveHandle, DWORD dwPTZCommand, DWORD dwSpeed);
NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZControl_Other(LONG lUserID, LONG lChannel, DWORD dwPTZCommand, DWORD dwSpeed);
NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZControl_3D(POINTERHANDLE lLiveHandle, LONG lChannel, PTZ_3D_POINT_INFO *pPtz3DInfo);
//Ԥ�õ�
NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZPreset(POINTERHANDLE lLiveHandle, DWORD dwPTZPresetCmd, DWORD dwPresetIndex);
NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZPreset_Other(LONG lUserID, LONG lChannel, DWORD dwPTZPresetCmd, DWORD dwPresetIndex);
//Ѳ����
NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZCruise(POINTERHANDLE lLiveHandle, DWORD dwPTZCruiseCmd, BYTE byCruiseRoute);
NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZCruise_Other(LONG lUserID, LONG lChannel, DWORD dwPTZCruiseCmd, BYTE byCruiseRoute);
NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZSetCruise(POINTERHANDLE lLiveHandle, BYTE byCruiseRoute, DD_CRUISE_POINT_INFO *pCruisePoint, WORD pointNum);
NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZSetCruise_Other(LONG lUserID, LONG lChannel, BYTE byCruiseRoute, DD_CRUISE_POINT_INFO *pCruisePoint, WORD pointNum);
//�켣
NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZTrack(POINTERHANDLE lLiveHandle, DWORD dwPTZTrackCmd);
NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZTrack_Other(LONG lUserID, LONG lChannel, DWORD dwPTZTrackCmd);
//�Զ�ɨ������ɨ�趼����ӿ�,bIsAutoScan = true,�Զ�ɨ�衣
NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZAutoScan(POINTERHANDLE lLiveHandle, DWORD dwPTZAutoScanCmd, DWORD dwSpeed, BOOL bIsAutoScan = TRUE);
NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZAutoScan_Other(LONG lUserID, LONG lChannel, DWORD dwPTZAutoScanCmd);
//��ȡ��̨��Ϣ����ȡԤ�õ��Ѳ����get Preset or Cruise
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetPTZConfig(LONG lUserID, LONG lChannel, DWORD dwPTZCmd,LPVOID lpInBuffer, DWORD dwInBufferSize, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned);
//��ȡͨ��֧��PTZ���б�
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetSupportPtzList(LONG lUserID, int listNum, NET_SDK_CHANNEL_PTZ* pOutChannelPtz, int *returnListNum);
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetPTZCameraType(LONG lUserID, NET_SDK_CAMERA_TYPE *pCameraType);


////////////////////////////////////////�����Խ���ת��////////////////////////////////////////
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_StartVoiceCom(LONG lUserID, BOOL bNeedCBNoEncData, TALK_DATA_CALLBACK fVoiceDataCallBack, void* pUser);
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetAudioInfo(POINTERHANDLE lVoiceComHandle, void *pAudioInfo, LONG infoLen);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetVoiceComClientVolume(POINTERHANDLE lVoiceComHandle, WORD wVolume);
NET_SDK_API BOOL CALL_METHOD NET_SDK_StopVoiceCom(POINTERHANDLE lVoiceComHandle);
//����ת��
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_StartVoiceCom_MR(LONG lUserID, BOOL bNeedNoEncodeData, TALK_DATA_CALLBACK fVoiceDataCallBack, void* pUser);
NET_SDK_API BOOL CALL_METHOD NET_SDK_VoiceComSendData(POINTERHANDLE lVoiceComHandle, char *pSendBuf, DWORD dwBufSize);
//��Ƶ����
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_InitAudioDecoder(void *pAudioInfo, LONG infoLen);
NET_SDK_API BOOL CALL_METHOD NET_SDK_DecodeAudioFrame(POINTERHANDLE lDecHandle, unsigned char *pInBuffer, LONG inLen, unsigned char *pOutBuffer, int *pOutLen);
NET_SDK_API void CALL_METHOD NET_SDK_ReleaseAudioDecoder(POINTERHANDLE lDecHandle);
//��Ƶ����
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_InitAudioEncoder(void *pAudioInfo, LONG infoLen);
NET_SDK_API BOOL CALL_METHOD NET_SDK_EncodeAudioFrame(POINTERHANDLE lEncodeHandle, unsigned char *pInBuffer, LONG inLen, unsigned char *pOutBuffer, int *pOutLen);
NET_SDK_API void CALL_METHOD NET_SDK_ReleaseAudioEncoder(POINTERHANDLE lEncodeHandle);


////////////////////////////////////////�豸ά������////////////////////////////////////////
//����
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_Upgrade(LONG lUserID, char *sFileName);
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_UpgradeEx(LONG lUserID, char *sFileName);
NET_SDK_API int CALL_METHOD NET_SDK_GetUpgradeState(POINTERHANDLE lUpgradeHandle);
NET_SDK_API int CALL_METHOD NET_SDK_GetUpgradeProgress(POINTERHANDLE lUpgradeHandle);
NET_SDK_API BOOL CALL_METHOD NET_SDK_CloseUpgradeHandle(POINTERHANDLE lUpgradeHandle);
//��־����
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_FindDVRLog(LONG lUserID, DWORD dwType, DD_TIME *lpStartTime, DD_TIME *lpStopTime);
NET_SDK_API LONG CALL_METHOD NET_SDK_FindNextLog(POINTERHANDLE lLogHandle, LPNET_SDK_LOG lpLogData);
NET_SDK_API BOOL CALL_METHOD NET_SDK_FindLogClose(POINTERHANDLE lLogHandle);
//�¼�����
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_FindEventInfo(LONG lUserID, DWORD dwType, ULONGLONG channlMask, DD_TIME *lpStartTime, DD_TIME *lpStopTime);
NET_SDK_API LONG CALL_METHOD NET_SDK_FindNextEventInfo(POINTERHANDLE lEventHandle, LPNET_SDK_EVENT lpEventData);
NET_SDK_API BOOL CALL_METHOD NET_SDK_FindEventInfoClose(POINTERHANDLE lEventHandle);
//�ָ�Ĭ��ֵ
NET_SDK_API BOOL CALL_METHOD NET_SDK_RestoreConfig(LONG lUserID);
//�����ļ���������
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetConfigFile(LONG lUserID, char *sFileName);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetConfigFile(LONG lUserID, char *sFileName);
//�ػ�������
NET_SDK_API BOOL CALL_METHOD NET_SDK_ShutDownDVR(LONG lUserID);
NET_SDK_API BOOL CALL_METHOD NET_SDK_RebootDVR(LONG lUserID);
//Զ�̲�ѯӲ��
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_FindDisk(LONG lUserID);
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetNextDiskInfo(POINTERHANDLE lDiskHandle, NET_SDK_DISK_INFO *pDiskInfo);
NET_SDK_API BOOL CALL_METHOD NET_SDK_FindDiskClose(POINTERHANDLE lDiskHandle);
//��ʽ��Ӳ��
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_FormatDisk(LONG lUserID, LONG lDiskNumber);
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetFormatProgress(POINTERHANDLE lFormatHandle, LONG *pCurrentFormatDisk, LONG *pCurrentDiskPos, LONG *pFormatStatic);
NET_SDK_API BOOL CALL_METHOD NET_SDK_CloseFormatHandle(POINTERHANDLE lFormatHandle);


////////////////////////////////////////�豸��������////////////////////////////////////////
NET_SDK_API LONG CALL_METHOD NET_SDK_EnterDVRConfig(LONG lUserID);
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDVRConfig(LONG lUserID, DWORD dwCommand, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned, BOOL bDefautlConfig);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetDVRConfig(LONG lUserID, DWORD dwCommand, LONG lChannel, LPVOID lpInBuffer,  DWORD dwInBufferSize);
NET_SDK_API BOOL CALL_METHOD NET_SDK_ExitDVRConfig(LONG lUserID);

NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDVRConfig_SubStreamEncodeInfo(LONG lUserID, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned, BOOL bDefautlConfig);	//For N9000
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetDVRConfig_SubStreamEncodeInfo(LONG lUserID, LONG lChannel, LPVOID lpInBuffer,  DWORD dwInBufferSize);													//For N9000
//���NET_SDK_GetDVRConfig_SubStreamEncodeInfo�����ؽṹ���ж���֧�ֵ�����ѡ��; ���ص���֧�ֵı�����Ϣ
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDVRConfig_SubStreamEncodeInfo_Ex(LONG lUserID, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned, BOOL bDefautlConfig);	//For N9000
NET_SDK_API BOOL CALL_METHOD NET_SDK_SaveConfig(LONG lUserID);//�������
NET_SDK_API BOOL CALL_METHOD NET_SDK_ChangTime(LONG lUserID, unsigned int time);//�޸��豸ϵͳʱ��
//NET_SDK_API BOOL CALL_METHOD NET_SDK_ModifyDeviceNetInfo(NET_SDK_DEVICE_IP_INFO *pDeviceIPInfo);//�޸��豸IP
NET_SDK_API void CALL_METHOD NET_SDK_FormatTime(LONGLONG intTime, DD_TIME *pFormatTime);//����ʱ��ת��Ϊ��ʽ����ʱ��


////////////////////////////////////////���ܱ�����ֻ�������IPC��////////////////////////////////////////
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetIVMRuleConfig(LONG lUserID, DWORD dwCommand, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetIVMRuleConfig(LONG lUserID, DWORD dwCommand, LONG lChannel, LPVOID lpInBuffer,  DWORD dwInBufferSize);
//dwCommand NET_DVR_SMART_TYPE
//NET_DVR_IVE_VFD_RESULT_HEAD_T+[NET_DVR_IVE_VFD_RESULT_DATA_INFO_T+Դ����]+[NET_DVR_IVE_VFD_RESULT_FACE_DATA_INFO_T+��������+����Ŀ��ֵ]+...+[NET_DVR_IVE_VFD_RESULT_FACE_DATA_INFO_T+��������+����Ŀ��ֵ]
typedef void (CALLBACK *SUBSCRIBE_CALLBACK)(LONG lUserID, DWORD dwCommand, char *pBuf, DWORD dwBufLen, void *pUser);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetSubscribCallBack(SUBSCRIBE_CALLBACK fSubscribCallBack, void *pUser);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SmartSubscrib(LONG lUserID, DWORD dwCommand, LONG lChannel, NET_DVR_SUBSCRIBE_REPLY *pOutBuffer);
NET_SDK_API BOOL CALL_METHOD NET_SDK_UnSmartSubscrib(LONG lUserID, DWORD dwCommand, LONG lChannel, char *pInServerAddress, int *dwResult);
//FaceMatch NET_SDK_FACE_MATCH_OPERATE_TYPE
NET_SDK_API BOOL CALL_METHOD NET_SDK_FaceMatchOperate(LONG lUserID, DWORD dwCommand,LPVOID lpInBuffer, DWORD dwInBufferSize,LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned);
//͸��API�ӿں�����ʵ�����豸��ֱ��xml��ͨ
NET_SDK_API BOOL CALL_METHOD NET_SDK_ApiInterface(LONG lUserID, char *sendXML, char *strUrl, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned);

////////////////////The following interfaces will stop updating, they are not recommended.
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDeviceFirmwareType(LONG lUserID, NET_SDK_DEVICE_FIRMWARE_TYPE *pFirmwareType);
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDeviceIPByName(char *sSerIP,DWORD wSerPort,char *sDvrName,char *sDvrIP);//ͨ���豸���ƻ�ȡIP��ַ
NET_SDK_API LONG CALL_METHOD NET_SDK_GetProductSubID(char *sDVRIP,WORD wDVRPort);
NET_SDK_API char* CALL_METHOD NET_SDK_GetErrorMsg(LONG *pErrorNo = NULL);
NET_SDK_API LONG CALL_METHOD NET_SDK_GetDeviceTypeName(LONG lUserID, char *pNameBuffer, int bufferLen);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetLogToFile(BOOL bLogEnable = FALSE, char *strLogDir = NULL, BOOL bAutoDel = TRUE);//������־�ļ�д��ӿ�
NET_SDK_API BOOL CALL_METHOD NET_SDK_ChangeDiskProperty(LONG lUserID, LONG lDiskNumber, short newProperty);
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetVideoEffect(LONG lUserID, LONG lChannel, DWORD *pBrightValue, DWORD *pContrastValue, DWORD *pSaturationValue, DWORD *pHueValue);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetVideoEffect(LONG lUserID, LONG lChannel, DWORD dwBrightValue, DWORD dwContrastValue, DWORD dwSaturationValue, DWORD dwHueValue);
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDefaultVideoEffect(LONG lUserID, DWORD *pBrightValue, DWORD *pContrastValue, DWORD *pSaturationValue, DWORD *pHueValue);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SaveVideoEffect(LONG lUserID, LONG lChannel, DWORD dwBrightValue, DWORD dwContrastValue, DWORD dwSaturationValue, DWORD dwHueValue);
NET_SDK_API BOOL CALL_METHOD NET_SDK_CapturePicture(POINTERHANDLE lLiveHandle, char *sPicFileName);//bmp
NET_SDK_API BOOL CALL_METHOD NET_SDK_CapturePicture_Other(LONG lUserID, LONG lChannel,char *sPicFileName);//bmp
NET_SDK_API BOOL CALL_METHOD NET_SDK_CaptureJpeg(LONG lUserID, LONG lChannel, LONG dwResolution, char *sJpegPicBuffer, DWORD dwPicBufSize, LPDWORD lpSizeReturned);

#ifdef __cplusplus
}
#endif

#endif
