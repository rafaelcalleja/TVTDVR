
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

//LastError定义
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
    NET_SDK_DEVICE_NOT_SUPPROT,////DEVICE不支持
	NET_SDK_USER_ERROR_SYSTEM_NO_READY,//N9K设备还没有准备好 刚刚登录获取预置点巡航线list还未成功
	NET_SDK_CHANNEL_OFFLINE,//预览N9K设备时通道不在线
	NET_SDK_GETREADYINFO_FAIL,//获取N9K能力集失败
	NET_SDK_NORESOURCE,//SDK资源不足
	NET_SDK_DEVICE_QUERYSYSTEMCAPS_FAIL,
	NET_SDK_INBUFFER_TOSMALL//输入BUF不足

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
	NET_SDK_PLAYCTRL_STARTAUDIO,	//该控制类型及以下两个控制类型只有在SDK内部解码显示时才会起作用
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

//登录结构定义
typedef struct _net_sdk_deviceinfo
{
	unsigned char	localVideoInputNum;		//本地视频输入通道数目
	unsigned char	audioInputNum;			//音频输入通道数目
	unsigned char	sensorInputNum;			//传感器输入通道数目
	unsigned char	sensorOutputNum;		//继电器输出数目
	unsigned int   displayResolutionMask;  //监视器可选择的分辨率

	unsigned char	videoOuputNum;			//视频输出数目（及支持回放最大通道数）
	unsigned char	netVideoOutputNum;		//网络回放最大通道数目
	unsigned char	netVideoInputNum;		//数字信号接入通道数目
	unsigned char	IVSNum;					//智能分析通道数目

	unsigned char	presetNumOneCH;			//每个通道预置点数目
	unsigned char	cruiseNumOneCH;			//每个通道巡航线数目
	unsigned char	presetNumOneCruise;		//每个巡航线的预置点数目
	unsigned char	trackNumOneCH;			//每个通道轨迹数目

	unsigned char	userNum;				//用户数目 
	unsigned char	netClientNum;			//最多客户端数目
	unsigned char	netFirstStreamNum;		//主码流传输的通道最大数目，即同时可以有几个客户端查看主码流
	unsigned char	deviceType;				// NET_SDK_DEVICE_TYPE

	unsigned char	doblueStream;			//是否有提供双码流
	unsigned char	audioStream;			//是否有提供音频流
	unsigned char	talkAudio;				//是否有对讲功能: 1表示有对讲功能;0表示没有
	unsigned char	bPasswordCheck;			//操作是否要输入密码

	unsigned char	defBrightness;			//缺省亮度
	unsigned char	defContrast;			//缺省对比度
	unsigned char	defSaturation;			//缺省饱和度
	unsigned char	defHue;					//缺省色调

	unsigned short	videoInputNum;			//视频输入通道数目（本地加网络）
	unsigned short  deviceID;				//设备ID号
	unsigned int   videoFormat;            //系统当前制式

	//假如是FUNC_REMOTE_UPGRADE对应的功能，那么第FUNC_REMOTE_UPGRADE个比特为1，否则为零。
	unsigned int	function[8];			//功能描述

	unsigned int	deviceIP;				//设备网络地址
	unsigned char	deviceMAC[6];			//设备物理地址
	unsigned short	devicePort;				//设备端口

	unsigned int	buildDate;				//创建日期:year<<16 + month<<8 + mday
	unsigned int	buildTime;				//创建时间:hour<<16 + min<<8 + sec

	char			deviceName[36];			//设备名称

	char	firmwareVersion[36];			//固件版本
	char	kernelVersion[64];				//内核版本
	char	hardwareVersion[36];			//硬件版本
	char	MCUVersion[36];					//单片机版本
    char	firmwareVersionEx[64];			//固件版本扩展，主要针对新产品
    unsigned int	softwareVer;//软件协议版本，目前用于IPC的版本兼容
    char	szSN[32];			//sn
    char	deviceProduct[28];			//设备型号
}NET_SDK_DEVICEINFO, *LPNET_SDK_DEVICEINFO;

//数据帧头定义
typedef struct _net_sdk_frame_info
{
	unsigned int		deviceID;
	unsigned int       channel;
	unsigned int		frameType;	//参考DD_FRAME_TYPE
	unsigned int		length;
	unsigned int		keyFrame;	//0：非关键帧 1：关键帧
	unsigned int       width;
	unsigned int       height;
	unsigned int		frameIndex;
	unsigned int		frameAttrib;//参考DD_FRAME_ATTRIB
	unsigned int		streamID;
	LONGLONG			time;	   //从1970年1月1日0点0分0秒开始的绝对时间，单位微秒
	LONGLONG			relativeTime;//相对时间，单位微秒
}NET_SDK_FRAME_INFO;

//录像时间信息定义
typedef struct _net_sdk_rec_time
{
	DWORD			dwChannel;	//通道号
	DD_TIME			startTime;	//该段录像开始时间
	DD_TIME			stopTime;	//该段录像结束时间
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

//日志信息定义
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
	unsigned short chnn;			//事件对应的通道
	unsigned short type;			//事件类型：DD_EVENT_TYPE
	DD_TIME        startTime;		//事件产生的开始时间
	DD_TIME        endTime;			//事件的结束时间
}NET_SDK_EVENT,*LPNET_SDK_EVENT;

typedef struct _net_sdk_clientinfo
{
	LONG    lChannel;
	LONG    streamType;
	HWND    hPlayWnd;
    int     bNoDecode; //0:解码， 1：不解码 仅针对win平台，默认0

}NET_SDK_CLIENTINFO, *LPNET_SDK_CLIENTINFO;

//设备上传信息类型
enum NET_SDK_DEVICE_MSG_TYPE
{
	NET_SDK_ALARM,		//设备报警消息
	NET_SDK_RECORD,		//设备录像信息
	NET_SDK_IVM_RULE,	//智能行为分析信息(暂时保留)
	NET_SDK_TRADEINFO,	//ATM交易信息(暂时保留)
	NET_SDK_IPCCFG,		//混合型DVR的IPC信息变更(暂时保留)
};

//设备上传信息为报警类型时的具体报警类型
enum NET_SDK_ALARM_TYPE
{
	NET_SDK_ALARM_TYPE_MOTION,		//移动侦测
	NET_SDK_ALARM_TYPE_SENSOR,		//信号量报警
	NET_SDK_ALARM_TYPE_VLOSS,		//信号丢失
	NET_SDK_ALARM_TYPE_SHELTER,		//遮挡报警
	NET_SDK_ALARM_TYPE_DISK_FULL,	//硬盘满
	NET_SDK_ALARM_TYPE_DISK_UNFORMATTED,//硬盘未格式化
	NET_SDK_ALARM_TYPE_DISK_WRITE_FAIL,	//读写硬盘出错
	NET_SDK_ALARM_TYPE_EXCEPTION,
};


//设备上传信息为智能报警的事件类型
enum NET_SDK_IVM_RULE_TYPE
{
    NET_SDK_IVM_RULE_TYPE_VFD, //人脸识别报警  NET_SDK_IVM_STATUS_INFO
    NET_SDK_IVM_RULE_TYPE_AVD_SCENE, //视频异常诊断场景变化  NET_SDK_IVM_STATUS_INFO
    NET_SDK_IVM_RULE_TYPE_AVD_CLARITY, //视频异常诊断视频模糊  NET_SDK_IVM_STATUS_INFO
    NET_SDK_IVM_RULE_TYPE_AVD_COLOR, //视频异常诊断视频偏色  NET_SDK_IVM_STATUS_INFO
};


/************************************************************************/
    /*  定义报警输入和输出的资源    在很多地方使用这个枚举值的时候定义的变量都是BYTE的所以这里
    要小心定义*/
    /************************************************************************/

enum NET_SDK_N9000_ALARM_TYPE
{
    NET_SDK_N9000_ALARM_TYPE_RANGE_BEGIN,
    NET_SDK_N9000_ALARM_TYPE_MOTION=0x01,/////移动侦测报警输入
    NET_SDK_N9000_ALARM_TYPE_SENSOR,/////传感器报警输入
    NET_SDK_N9000_ALARM_TYPE_VLOSS,////视频丢失报警输入
    NET_SDK_N9000_ALARM_TYPE_FRONT_OFFLINE, //////前端设备掉线报警
    NET_SDK_N9000_ALARM_TYPE_OSC,           ////物品看护侦测报警
    NET_SDK_N9000_ALARM_TYPE_AVD,           ////视频异常侦测报警
    NET_SDK_N9000_ALARM_TYPE_AVD_SCENE,//only IPC
    NET_SDK_N9000_ALARM_TYPE_AVD_CLARITY,//only IPC
    NET_SDK_N9000_ALARM_TYPE_AVD_COLOR,//only IPC

    NET_SDK_N9000_ALARM_TYPE_PEA_TRIPWIRE,  ////越界侦测报警
    NET_SDK_N9000_ALARM_TYPE_PEA_PERIMETER, ////区域入侵侦测报警
    //NET_SDK_N9000_ALARM_TYPE_PEA,           ////越界侦测与区域入侵侦测（分成俩子项，不再触发）
    NET_SDK_N9000_ALARM_TYPE_VFD,           ////人脸侦测（目前仅IPC）
    NET_SDK_N9000_ALARM_TYPE_CDD,           ////Crowdy density
    NET_SDK_N9000_ALARM_TYPE_IPD,           ////people intrusion
    NET_SDK_N9000_ALARM_TYPE_CPC,           ////people counting
    NET_SDK_N9000_ALARM_TYPE_FACE_MATCH,    ////人脸比对报警

    NET_SDK_N9000_ALARM_TYPE_GPS_SPEED_OVER=0x21,//和车载有关的报警，超速
    NET_SDK_N9000_ALARM_TYPE_GPS_CROSS_BOADER,//越界
    NET_SDK_N9000_ALARM_TYPE_GPS_TEMPERATURE_OVER,//温度报警
    NET_SDK_N9000_ALARM_TYPE_GPS_GSENSOR_X,//GSENSOR报警
    NET_SDK_N9000_ALARM_TYPE_GPS_GSENSOR_Y,
    NET_SDK_N9000_ALARM_TYPE_GPS_GSENSOR_Z,

    NET_SDK_N9000_ALARM_TYPE_EXCEPTION = 0x41,
    NET_SDK_N9000_ALARM_TYPE_IP_CONFLICT,   /////IP地址冲突
    NET_SDK_N9000_ALARM_TYPE_DISK_IO_ERROR, /////磁盘IO错误
    NET_SDK_N9000_ALARM_TYPE_DISK_FULL,	   /////磁盘满
    NET_SDK_N9000_ALARM_TYPE_RAID_SUBHEALTH, //阵列亚健康
    NET_SDK_N9000_ALARM_TYPE_RAID_UNAVAILABLE, //阵列不可用
    NET_SDK_N9000_ALARM_TYPE_ILLEIGAL_ACCESS,  /////非法访问
    NET_SDK_N9000_ALARM_TYPE_NET_DISCONNECT,  /////网络断开
    NET_SDK_N9000_ALARM_TYPE_NO_DISK,		////盘组下没有磁盘
    NET_SDK_N9000_ALARM_TYPE_SIGNAL_SHELTER, //信号遮挡
    NET_SDK_N9000_ALARM_TYPE_HDD_PULL_OUT, //前面板硬盘拔出

    NET_SDK_N9000_ALARM_TYPE_ALARM_OUT = 0x51,  /////报警输出的类型，报警输出也有状态需要管理

    NET_SDK_N9000_ALARM_TYPE_RANGE_END = 0xFF,////不能超过这个值  否则会出错
};


//设备上传信息为报警类型时的上传信息结构
typedef struct _net_sdk_alarminfo
{
	DWORD		dwAlarmType;
	DWORD		dwSensorIn;		//传感器报警输入端口号
	DWORD		dwChannel;		//在报警与通道相关时，表示报警的通道号
	DWORD		dwDisk;			//在磁盘报警时，表示产生报警的磁盘号
}NET_SDK_ALARMINFO;

typedef struct _net_sdk_record_status
{
	DWORD		dwRecordType;		//DD_RECORD_TYPE
	DWORD		dwChannel;
}NET_SDK_RECORD_STATUS;

typedef struct _net_sdk_IVM_rule_status
{
    DWORD		dwIVMType;		//NET_SDK_IVM_RULE_TYPE
    DWORD		dwIVMSize;      //NET_SDK_IVM_RULE_TYPE中事件对应的结构体大小
}
NET_SDK_IVM_RULE_STATUS;

//人脸检测告警上报
typedef struct _net_sdk_IVM_status_info
{
    DWORD		dwAlarmType;    //NET_SDK_IVM_RULE_TYPE
    DWORD		dwChannel;		//告警通道号

}NET_SDK_IVM_STATUS_INFO;

typedef enum _net_sdk_disk_status
{	
	NET_SDK_DISK_NORMAL,				//正常 
	NET_SDK_DISK_NO_FORMAT,				//未格式化
    NET_SDK_DISK_FORMATTING,				//正在格式化
    NET_SDK_DISK_EXCEPTION,				//  exception
}NET_SDK_DISK_STATUS;

typedef enum _net_sdkdisk_property
{
	NET_SDK_DISK_READ_WRITE = 0,			//可正常读写
	NET_SDK_DISK_ONLY_READ,					//只能读，不能写
	NET_SDK_DISK_REDUNDANCY					//冗余
}NET_SDK_DISK_PROPERTY;

typedef enum _net_sdk_connect_type
{
	NET_SDK_CONNECT_TCP		= 0,			//TCP方式登陆
	NET_SDK_CONNECT_NAT		= 1,			//NAT方式登陆
    NET_SDK_CONNECT_NAT_TCP		= 2,			//用NAT库中的TCP连接

	NET_SDK_CONNECT_END
}NET_SDK_CONNECT_TYPE;

typedef enum _net_sdk_camera_type
{
	NET_SDK_NOT_SUPPORT_PTZ		= 0,		//不支持云台的枪机
	NET_SDK_DOME_SUPPORT_PTZ	= 1,		//支持云台的枪机
	NET_SDK_SUPPORT_PTZ			= 2,		//支持云台的球机
	NET_SDK_PTZ_END
}NET_SDK_CAMERA_TYPE;

typedef struct _net_sdk_disk_info
{
	LONG		diskIndex;			//磁盘编号
	short		diskStatus;			//磁盘状态，参考NET_SDK_DISK_STATUS
	short		diskProperty;		//磁盘状态，参考NET_SDK_DISK_PROPERTY
	DWORD		diskTotalSpace;		//磁盘总空间，单位MB
	DWORD		diskFreeSpace;		//磁盘剩余空间，单位MB
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
	NETWORK_CH_DISCONNECT,	//通道掉线
	NETWORK_CH_RECONNECT,	//通道上线
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
	unsigned char		ucIPMode;			//0 静态IP 1 dhcp
}NET_SDK_DEVICE_DISCOVERY_INFO;

typedef struct _net_sdk_device_ip_info_
{
	char szMac[36];					//设备当前mac地址
	char szIpAddr[64];				//要修改成的ip
	char szMark[36];
	char szGateway[36];
	char szPassword[64];			//admin用户的密码
	char szDdns1[36];
	char szDdns2[36];
	char ucIPMode;					//0为静态IP, 1为DHCP
}NET_SDK_DEVICE_IP_INFO;

typedef struct _net_sdk_ipc_device_info_
{
	unsigned int	deviceID;				//设备ID(暂时未用上)
	unsigned short	channel;				//该网络设备在本地分配的通道(从0开始)
	unsigned short	status;					//连接状态（0代表离线，1表示在线）
	char			szEtherName[16];		//如果为空，默认为eth0
	char			szServer[64];			//网络设备IP地址
	unsigned short	nPort;					//网络设备端口号
	unsigned short	nHttpPort;				//HTTP端口
	unsigned short	nCtrlPort;				//控制端口，一般与nPort相同
	char			szID[64];				//网络设备标识(或是MAC地址)
	char			username[36];			//用户名

	unsigned int	manufacturerId;			//设备厂商ID(暂时未用上)
	char			manufacturerName[36];	//设备厂商名(暂时未用上)
	char			productModel[36];		//产品型号(暂时未用上)
	unsigned char	bUseDefaultCfg;			//暂时未用上
	unsigned char	bPOEDevice;				//暂时未用上
	unsigned char	resv[2];				//暂时未用上
}NET_SDK_IPC_DEVICE_INFO;

//抓图类型
enum IMAGE_EVENT_TYPE
{
    IMAGE_TYPE_ALARM,
    IMAGE_TYPE_MANUAL,
};
//返回排列顺序
enum IMAGE_SORT_TYPE
{
    IMAGE_SORT_ASC,
    IMAGE_SORT_DESC,
};


typedef struct _net_sdk_image_
{
    DWORD			dwChannel; //抓图通道
    DWORD			dwImageType; //抓图类型 IMAGE_EVENT_TYPE
    DD_TIME_EX			captureTime;//时间
    DWORD			totalNum;//图片总数
    unsigned char	resv[8];
}NET_SDK_IMAGE;

typedef struct _net_sdk_image_sreach
{
    DWORD			dwChannel;//抓图通道
    DD_TIME_EX			StartTime; //时间
    DD_TIME_EX			StopTime; //时间
    DWORD			pageIndex;//第几页
    DWORD			pageSize;//每页数
    unsigned int sort; //返回排列顺序 //IMAGE_SORT_TYPE
    unsigned char	resv[8];
}NET_SDK_IMAGE_SREACH;


//图片类型
enum IMAGE_MODE
{
    IMAGE_MODE_JPG,
    IMAGE_MODE_PNG,
    IMAGE_MODE_BMP,
};
typedef struct _net_sdk_image_info
{
    unsigned int	imageSize;
    unsigned int		imageMode; //IMAGE_MODE 图片格式
    unsigned char	resv[8];
}NET_SDK_IMAGE_INFO;

typedef enum __Channel_type__
{
    E_NULL_CHL_TYPE,
    E_DIGITAL_CHL_TYPE,     //数字通道
    E_ANALOG_CHL_TYPE,      //模拟通道
    E_ALARMOUT_CHL_TYPE,	  //报警输出通道
    E_SENSOR_CHL_TYPE,	  //传感器通道
}CHANNEL_TYPE;

typedef struct _net_sdk_channel_ptz
{
    unsigned int	dwChannel;
    unsigned int      eChanneltype;//CHANNEL_TYPE
    unsigned char	resv[8];
}NET_SDK_CHANNEL_PTZ;

typedef enum __IVM_rule_config_type__
{
    IVM_RULE_VFD_CONFIG, //人脸识别配置
    IVM_RULE_VFD_TRIGGER_CONFIG, //人脸识别联动配置
    IVM_RULE_VFD_SCHEDULE_CONFIG, //人脸识别排程
    IVM_RULE_AVD_CONFIG, //异常视频配置

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
    unsigned int      bSwitch; //使能，0 or 1
    unsigned int      alarmHoldTime;//报警持续时间
    unsigned int      saveFacePicture;//保存人脸检测脸图片
    unsigned int      saveSourcePicture;//保存人脸检测源图片
    unsigned int      rectangleNum;
    RECTANGLE	rectangle;
    unsigned char	resv[40];
}NET_SDK_VFD_CONFIG;

//IVM_RULE_VFD_TRIGGER_CONFIG
typedef struct _net_sdk_Vfd_trigger_Config
{
    unsigned short    snapCHNum ; //支持最大抓图通道数
    unsigned char     snapChannelId;//抓图通道
    unsigned char     snapBswitch ;//抓图使能
    unsigned short    recordCHNum ; //支持最大录像通道数
    unsigned char     recordChannelId;//录像通道
    unsigned char     recordBswitch ;//录像使能
    unsigned short    alarmOutCHNum ; //支持最大报警输出数
    unsigned char     alarmOutChannelId;//报警输出通道
    unsigned char     alarmOutBswitch ;//报警输出使能
    unsigned char     Resv[256];//保留，将来用于扩展多通道

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

}NET_DVR_SCHEDDATE, *LPNET_DVR_SCHEDDATE; //按特定日期订的排程

typedef struct
{
    unsigned int    wDay; //在星期中的天数，周天为0，，，周六为6
    NET_DVR_SCHEDTIME sScheduleTime;

}NET_DVR_SCHEDWEEK, *LPNET_DVR_SCHEDWEEK;//根据星期数订的排程

//IVM_RULE_VFD_SCHEDULE_CONFIG
typedef struct
{
    unsigned int wDayCount; //sScheduleWeek有效个数
    unsigned int dayCount;  //sScheduleDate 有效个数
    NET_DVR_SCHEDWEEK sScheduleWeek[70]; //最多可以订70个
    NET_DVR_SCHEDDATE sScheduleDate[31]; //最多可以订31个  值大小来自ipc的协议

}NET_SDK_VFD_SCHEDULE_CONFIG;

//与备份相关
typedef enum _net_sdk_backup_data_type
{
    NET_DVR_BACKUP_DATA_TYPE_DVR,
    NET_DVR_BACKUP_DATA_TYPE_AVI,
    NET_DVR_BACKUP_DATA_TYPE_NULL,
}NET_DVR_BACKUP_DATA_TYPE;

typedef struct _download_sdk_frame_info
{
    unsigned int		nLength;	//帧数据长度
    unsigned short		frameType;	//参考DD_FRAME_TYPE
    unsigned short		keyFrame;	//0：非关键帧 1：关键帧
    unsigned short		nWidth;		//画面宽, 单位像素, 如果是音频数据则为0
    unsigned short		nHeight;	//画面高, 如果是音频数据则为0
    LONGLONG			nStamp;		//帧时间, 单位毫秒, 从1970年1月1日0点0分0秒开始的绝对时间
}NET_DVR_DOWNlOAD_FRAME_INFO;

typedef enum _net_sdk_backup_status
{
    NET_DVR_BACKUP_STOP,
    NET_DVR_BACKUP_END,

}NET_DVR_BACKUP_STATUS;

typedef struct
{
    char                            serverAddress[256];             // 订阅标识 后期的续订和退订使用
    long long                          currentTime;                    // 当前时间
    long long                          terminationTime;                // 终止时间
    char                            resv[64];                       // 后期扩展用
}NET_DVR_SUBSCRIBE_REPLY;


// 智能事件类型
typedef enum
{
    NET_DVR_SMART_AVD,            // 视频异常诊断功能检测
    NET_DVR_SMART_VFD,            // 人脸检测

}NET_DVR_SMART_TYPE;

typedef struct
{
    int X;
    int Y;
}NET_DVR_IVE_POINT_T;
typedef struct
{
    LONGLONG      time;            //检测源数据当前时间 /* 微秒级 */
    LONGLONG      relativeTime;    //检测源数据相对时间 /* 微秒级 */
    unsigned int     detectDataLen;   //检测源数据长度
    unsigned int     softwareVersion; //软件版本号, 0xABCDEFGH,AB：厂家 CD：主版本 EFGH：子版本 厂商 1:欧姆龙 版本:V5.00
    unsigned int     softwareBuildDate;//软件生成日期,0xYYYYMMDD
    unsigned int     faceCnt;         //人脸的个数，最大40个
    unsigned int     faceDataLen[40]; //每个人脸的长度
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
    unsigned int                     ptWidth;        /*坐标比例宽*/
    unsigned int                     ptHeight;       /*坐标比例高*/
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
    NET_DVR_IVE_POINT_T                 stPosFaceImg;  //人脸左上角坐标(在检测源图片的位置)
    int                         reserved[14];
    NET_DVR_IVE_VFD_RESULT_DATA_INFO_T  stFaceImgData;
}NET_DVR_IVE_VFD_RESULT_FACE_DATA_INFO_T;


//IVM_RULE_AVD_CONFIG
typedef struct _net_sdk_AVD_Config
{
    unsigned int      alarmHoldTime; //报警持续时间
    unsigned int      sceneChangeSwitch;//场景变更使能，0 or 1
    unsigned int      clarityAbnormalSwitch;//视频模糊使能，0 or 1
    unsigned int      colorAbnormalSwitch;//视频偏色使能，0 or 1
    unsigned int      sensitivity;
    unsigned int      maxSensitivity;
    unsigned int      minSensitivity;
    char              resv[40];

}NET_SDK_AVD_CONFIG;

typedef struct
{
    unsigned int      eventId;               // 事件ID
    unsigned int      status;                // 报警状态,0:none 1:start 2:end 3:procedure
    unsigned int      type;                  // 报警类型,0:none 1:Scene 2:Clarity 3:Color
}NET_SDK_IVE_AVD_INFO_T;

typedef struct
{
    unsigned int          count;             // 个数
    NET_SDK_IVE_AVD_INFO_T   avdInfo[32];       // 异常侦测信息
}NET_SDK_IVE_AVD_T;

typedef struct
{
    DD_TIME_EX  frameTime;   //帧时间
	unsigned int dwRealFaceID;  //抓拍人脸ID
	unsigned int dwGrpID;       //特征组ID
	unsigned int dwLibFaceID;   //特征库人脸ID
	unsigned int dwSimilar;     //相似度
	unsigned char byName[32]; //姓名
    LONG Channel;         //通道ID
	#ifdef __CHONGQING_ZHONGRAN__
	char    szCredential[DD_MAX_CERTIFICATE_NUM];  //证件号码, '\0' 结束,具有唯一性
	char    serialNumber[32];  //序列号
	
	#endif
	unsigned int imgLen;      //人脸数据长度
	#ifdef __CHONGQING_ZHONGRAN__
	unsigned int BackLen;     //背景大图数据长度
	#endif
}NET_SDK_IVE_FACE_MATCH_T;

typedef struct
{
    unsigned int          minValue;             // 最小值
    unsigned int          maxValue;             // 最大值
    unsigned int          curValue;             // 当前值
    unsigned int          defaultValue;             // 默认值

}NET_SDK_IMAGE_EFFECT_T;

typedef struct _net_sdk_ch_device_status_
{
    unsigned short	channel;				//通道(从0开始)
    unsigned short	status;					//连接状态（0:offline，videoloss. 1: online,signal）
    unsigned int    chlType;               //E_DIGITAL_CHL_TYPE,数字通道 E_ANALOG_CHL_TYPE,模拟通道
    char	         name [DD_MAX_CAMERA_NAME_BUF_LEN];
    unsigned char	resv[32];				//暂时未用上
}NET_SDK_CH_DEVICE_STATUS;

//人脸对比
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

//两者可任选其一
typedef struct _net_sdk_face_info_group_del_ex_
{
    unsigned int	groupId;				//GROUP ID 国内定制版本用此参数
    unsigned char   guid[48];				//GROUP GUID 通用版本用此参数
}NET_SDK_FACE_INFO_GROUP_DEL_EX;

typedef struct _net_sdk_face_info_list_get_
{			
    unsigned int	pageIndex;		//必填1、2、3...
    unsigned int    pageSize;   //必填
    unsigned int    groupId;//必填 1、2、3....

    char	        name[DD_MAX_NAME_LEN];//不填时清空 NET_SDK_FACE_INFO_LIST_ITEM中的name
    unsigned int    itemId;				//不填时清零 NET_SDK_FACE_INFO_LIST_ITEM中的itemId
    #ifdef __CHONGQING_ZHONGRAN__
    char	        certificateNum[DD_MAX_CERTIFICATE_NUM];		//
    #endif
}NET_SDK_FACE_INFO_LIST_GET;

typedef struct _net_sdk_face_info_list_item_groups_
{
    unsigned int    groupId;        //GROUP id 获取目标list返回的时候没有 guid
    unsigned char	guid[48];				//GROUP GUID 增加，编辑目标必须要用 guid
    DD_TIME_EX    validStartTime;//property为limited时才有validStartTime，validEndTime
    DD_TIME_EX    validEndTime;//property为limited时才有validStartTime，validEndTime
}NET_SDK_FACE_INFO_LIST_ITEM_GROUPS;

typedef struct _net_sdk_face_info_list_item_
{
    unsigned int    itemId;				//id
    char	        name[DD_MAX_NAME_LEN];		//必填
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
    unsigned int    chl; //返回值 255 表示已经删除的通道
    unsigned char   resv[8];//保留

}NET_SDK_FACE_IMG_INFO_CH;

typedef struct _net_sdk_face_info_add_
{

    NET_SDK_FACE_INFO_LIST_ITEM sFaceInfoItem;
    unsigned int                imgNum;
    NET_SDK_FACE_IMG_INFO_CH       sFaceImgInfo[DD_MAX_FACE_INFO_IMG];//最大5张
    unsigned int                haveImgData;//0、1
    unsigned int                imgWidth;//haveImgData ==1 有效
    unsigned int                imgHeight;//haveImgData ==1 有效
    unsigned int                imgLen;//haveImgData ==1 有效
    unsigned char               *imgData;//haveImgData ==1 有效
}NET_SDK_FACE_INFO_ADD;

typedef struct _net_sdk_face_info_edit_
{
    unsigned int            delFaceImgs[DD_MAX_FACE_INFO_IMG];
    NET_SDK_FACE_INFO_ADD   sFaceInfoItem;

}NET_SDK_FACE_INFO_EDIT;

typedef struct _net_sdk_face_info_del_
{
    unsigned int    faceInfoListItemId;//NET_SDK_FACE_INFO_LIST_ITEM中的itemId
    unsigned int    groupsId[DD_MAX_FACE_INFO_GROUPS];//NET_SDK_FACE_INFO_LIST_ITEM中的itemId-->groups-->groupId

}NET_SDK_FACE_INFO_DEL;

typedef struct _net_sdk_face_match_alarm_trigger_
{
    unsigned char	guid[48];	//GROUP GUID
    unsigned int    groupId;    //组ID
    unsigned char    groupSwitch;//启用
    unsigned char    alarmOutSwitch;//联动报警输出
    unsigned char    alarmOut[16];//联动报警输出默认最多16个 下标从1开始
    unsigned char    recSwitch;//录像
    unsigned int    recCH[128];//联动录像通道 下标从1开始
    unsigned char    snapSwitch;//抓图
    unsigned int    snapCH[128];//联动抓图通道 下标从1开始
    unsigned int    popVideo;//视频弹出
    unsigned char    msgPushSwitch;
    unsigned char    buzzerSwitch;
    unsigned char    popMsgSwitch;
    unsigned char    emailSwitch;

}NET_SDK_FACE_MATCH_ALARM_TRIGGER;

typedef struct _net_sdk_face_match_chan_group_
{
	unsigned int    faceFeatureGroupsNum;  //通道拥有的目标组个数
    unsigned int    pfaceFeatureGroupIDs[16]; //通道拥有的目标组ID列表,有效个数为faceFeatureGroupsNum
}NET_SDK_FACE_MATCH_CHAN_GROUP;

typedef struct _net_sdk_face_match_alarm_
{
    unsigned int    similarity;//相似度
    unsigned int    enableCH[128];//【开启通道】 通道下标从1开始
	#ifdef __CHONGQING_ZHONGRAN__
	NET_SDK_FACE_MATCH_CHAN_GROUP FaceMatchChanGroup[128]; //与【开启通道】严格对应
	#endif
    unsigned int    faceFeatureGroupsNum;//目标组个数
    NET_SDK_FACE_MATCH_ALARM_TRIGGER *pFaceMatchAlarmTrigger;

}NET_SDK_FACE_MATCH_ALARM;

typedef struct _net_sdk_face_info_img_get_
{

    unsigned int    itemId;	//目标id
    unsigned int    index;//faceImgCount中的index 1开始

}NET_SDK_FACE_INFO_IMG_GET;

typedef struct _net_sdk_face_info_img_data_
{
    unsigned int                imgLen;//目标图片长度
    unsigned char               *imgData;//目标图片数据
}NET_SDK_FACE_INFO_IMG_DATA;

typedef enum _net_sdk_search_image_by_image_type_
{
    SEARCH_IMAGE_BY_FACE_FEATURES,//通过人脸特征搜索
    SEARCH_IMAGE_BY_FACE_IMAGES,//通过人脸图片搜索
    SEARCH_IMAGE_BY_FACE_FEATURE_GROUPS,//通过人脸特征分组搜索
    SEARCH_IMAGE_BY_RECONGNIZED_FILTER,//通过与指定人脸特征分组比对是否识别进行过滤
    SEARCH_IMAGE_BY_FACE_IMAGE_DATA,//通过图片数据进行搜索

}NET_SDK_SEARCH_IMAGE_BY_IMAGE_TYPE;

typedef struct _net_sdk_search_image_by_image_
{
    unsigned int	pageIndex;		//必填1、2、3...
    unsigned int    pageSize;   //必填
    unsigned int    similarity;		//相似度
    unsigned int    resultCountLimit;		//结果个数限制
    DD_TIME_EX    startTime;
    DD_TIME_EX    endTime;
    unsigned int searchType;//NET_SDK_SEARCH_IMAGE_BY_IMAGE_TYPE
    struct
    {
       unsigned int itemId;	//目标id
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
    unsigned int    similarity;		//相似度
    unsigned int    faceFeatureId; //通过人脸特征搜索时，和哪个特征匹配
    NET_SDK_FACE_IMG_INFO_CH sfaceImg; //通过人脸图片搜索时，和哪个图片匹配
    unsigned char       resv[4];//保留

}NET_SDK_SEARCH_IMAGE_ITEM;

typedef struct _net_sdk_search_image_by_image_list_
{
    unsigned int    bEnd; //为1表述搜图个数已结束， 0表示后面还有
    unsigned int    listNum;//return NET_SDK_SEARCH_IMAGE_ITEM num
    NET_SDK_SEARCH_IMAGE_ITEM *pSearchImageItem;
}NET_SDK_SEARCH_IMAGE_BY_IMAGE_LIST;


typedef struct _net_sdk_ch_snap_face_img_list_
{
    unsigned int    bEnd; //为1表述搜图个数已结束， 0表示后面还有
    unsigned int    listNum;//return NET_SDK_FACE_IMG_INFO_CH num
    NET_SDK_FACE_IMG_INFO_CH *pCHFaceImgItem;
}NET_SDK_CH_SNAP_FACE_IMG_LIST;

typedef struct _net_sdk_ch_snap_face_img_list_sreach_
{
    DWORD			dwChannel;//抓图通道
    DD_TIME_EX			startTime; //时间
    DD_TIME_EX			endTime; //时间
    DWORD			pageIndex;//第几页
    DWORD			pageSize;//每页数

    unsigned char	resv[8];
}NET_SDK_CH_SNAP_FACE_IMG_LIST_SEARCH;

//人脸库相关
typedef enum _net_sdk_face_match_operate_type
{
    NET_SDK_GET_FACE_MATCH_SUPPORT=0x01,//in:NULL, out:DWORD
    //目标组
    NET_SDK_GET_FACE_INFO_GROUP_LIST,//queryFacePersonnalInfoGroupList in:NULL, out:NET_SDK_FACE_INFO_GROUP_ITEM list
    NET_SDK_ADD_FACE_INFO_GROUP,//createFacePersonnalInfoGroup in:NET_SDK_FACE_INFO_GROUP_ADD out:NULL
    NET_SDK_SET_FACE_INFO_GROUP,//editFacePersonnalInfoGroup in:NET_SDK_FACE_INFO_GROUP_ITEM  out:NULL
    NET_SDK_DEL_FACE_INFO_GROUP,//delFacePersonnalInfoGroups in:NET_SDK_FACE_INFO_GROUP_DEL  out:NULL
    //目标
    NET_SDK_GET_FACE_INFO_LIST,//queryFacePersonnalInfoList in:NET_SDK_FACE_INFO_LIST_GET, out:NET_SDK_FACE_INFO_LIST
    NET_SDK_ADD_FACE_INFO,//createFacePersonnalInfo in:NET_SDK_FACE_INFO_ADD out:DWORD
    NET_SDK_SET_FACE_INFO,//editFacePersonnalInfo in:NET_SDK_FACE_INFO_EDIT out:NULL
    NET_SDK_DEL_FACE_INFO,//delFacePersonnalInfo in:NET_SDK_FACE_INFO_DEL  out:NULL
    //对比报警配置
    NET_SDK_GET_FACE_MATCH_ALARM,//queryFaceMatchAlarm  in:NULL out:NET_SDK_FACE_MATCH_ALARM
    NET_SDK_SET_FACE_MATCH_ALARM,//editFaceMatchAlarm in:NET_SDK_FACE_MATCH_ALARM out:NULL
    //请求人脸目标图片
    NET_SDK_GET_FACE_INFO_IMG,//requestFacePersonnalInfoImage in:NET_SDK_FACE_INFO_IMG_GET out:NET_SDK_FACE_INFO_IMG_DATA
    //以图搜图 searchImageByImage
    NET_SDK_SEARCH_IMAGE_BY_IMG, //searchImageByImage in:NET_SDK_SEARCH_IMAGE_BY_IMAGE out:NET_SDK_SEARCH_IMAGE_BY_IMAGE_LIST
    //查询通道人脸图片
    NET_SDK_SEARCH_CH_SNAP_FACE_IMG_LIST,//queryChSnapFaceImageList in:NET_SDK_CH_SNAP_FACE_IMG_LIST_SEARCH out:NET_SDK_CH_SNAP_FACE_IMG_LIST
    //请求通道人脸图片数据
    NET_SDK_SEARCH_CH_SNAP_FACE_IMG,//requestChSnapFaceImage in:NET_SDK_FACE_IMG_INFO_CH out:NET_SDK_FACE_INFO_IMG_DATA
}NET_SDK_FACE_MATCH_OPERATE_TYPE;


#pragma pack()

////////////////////////////////////////回调函数定义////////////////////////////////////////
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
/********************************SDK接口函数声明*********************************/
////////////////////////////////////////基本信息及登录设备////////////////////////////////////////
//SDK初始化及退出
NET_SDK_API BOOL CALL_METHOD NET_SDK_Init();
NET_SDK_API BOOL CALL_METHOD NET_SDK_Cleanup();
//设置重连参数
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetConnectTime(DWORD dwWaitTime = 5000, DWORD dwTryTimes = 3);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetReconnect(DWORD dwInterval = 5000, BOOL bEnableRecon = TRUE);
//局域网前端设备发现
NET_SDK_API int CALL_METHOD NET_SDK_DiscoverDevice(NET_SDK_DEVICE_DISCOVERY_INFO *pDeviceInfo, int bufNum, int waitSeconds);
//SDK被动接收DVR注册 的本地端口号
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetRegisterPort(WORD wRegisterPort);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetRegisterCallback(ACCEPT_REGISTER_CALLBACK fRegisterCBFun, void *pUser);
//异常消息回调函数
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetSDKMessageCallBack(UINT nMessage, HWND hWnd, EXCEPTION_CALLBACK fExceptionCallBack, void *pUser);
//版本信息
NET_SDK_API DWORD CALL_METHOD NET_SDK_GetSDKVersion();
NET_SDK_API DWORD CALL_METHOD NET_SDK_GetSDKBuildVersion();
//错误查询
NET_SDK_API DWORD CALL_METHOD NET_SDK_GetLastError();
//登录登出设备
NET_SDK_API LONG CALL_METHOD NET_SDK_Login(char *sDVRIP,WORD wDVRPort,char *sUserName,char *sPassword,LPNET_SDK_DEVICEINFO lpDeviceInfo);
NET_SDK_API LONG CALL_METHOD NET_SDK_LoginEx(char *sDVRIP,WORD wDVRPort,char *sUserName,char *sPassword,LPNET_SDK_DEVICEINFO lpDeviceInfo, NET_SDK_CONNECT_TYPE eConnectType, const char *sDevSN = NULL);
NET_SDK_API BOOL CALL_METHOD NET_SDK_Logout(LONG lUserID);


////////////////////////////////////////设备报警信息////////////////////////////////////////
//设备报警或状态回调
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetDVRMessageCallBack(NET_MESSAGE_CALLBACK fMessageCallBack, void *pUser);
NET_SDK_API LONG CALL_METHOD NET_SDK_SetupAlarmChan(LONG lUserID);
NET_SDK_API BOOL CALL_METHOD NET_SDK_CloseAlarmChan(LONG lAlarmHandle);
//主动查询当前报警信息：N9000当前报警， IPC，3.0设备主动上报的报警
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetAlarmStatus(LONG lUserID, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned);
//手动开启\关闭报警
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetDeviceManualAlarm(LONG lUserID, LONG *pAramChannel, LONG *pValue, LONG lAramChannelCount, BOOL bAlarmOpen);


////////////////////////////////////////获取设备信息////////////////////////////////////////
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDeviceInfo(LONG lUserID, LPNET_SDK_DEVICEINFO pdecviceInfo);
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDeviceTime(LONG lUserID,DD_TIME *pTime);//获取设备当前时间
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDeviceIPCInfo(LONG lUserID, NET_SDK_IPC_DEVICE_INFO* pDeviceIPCInfo, LONG lBuffSize, LONG* pIPCCount);//获取NVR的IPC通道信息
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDeviceCHStatus(LONG lUserID, NET_SDK_CH_DEVICE_STATUS* pDeviceCHStatus, LONG lBuffSize, LONG* pCHCount);//获取NVR的通道状态


////////////////////////////////////////预览相关接口////////////////////////////////////////
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_LivePlay(LONG lUserID, LPNET_SDK_CLIENTINFO lpClientInfo, LIVE_DATA_CALLBACK fLiveDataCallBack = NULL, void* pUser = NULL);
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_LivePlayEx(LONG lUserID, LPNET_SDK_CLIENTINFO lpClientInfo, LIVE_DATA_CALLBACK_EX fLiveDataCallBack = NULL, void* pUser = NULL);
NET_SDK_API BOOL CALL_METHOD NET_SDK_StopLivePlay(POINTERHANDLE lLiveHandle);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetLiveDataCallBack(POINTERHANDLE lLiveHandle, LIVE_DATA_CALLBACK fLiveDataCallBack, void *pUser);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetLiveDataCallBackEx(POINTERHANDLE lLiveHandle, LIVE_DATA_CALLBACK_EX fLiveDataCallBack, void *pUser);
// 设置YUV回调后，可在回调处接收YUV数据，处理需尽快返回，否则会阻塞底层解码线程。（无需SDK显示时，调用NET_SDK_LivePlay时，窗口句柄传NULL即可）
// 注意：该功能目前仅在windows版本有效
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetYUVCallBack(POINTERHANDLE lLiveHandle, YUV_DATA_CALLBACK fYuvCallBack, void *pUser);

//动态生成I帧
NET_SDK_API BOOL CALL_METHOD NET_SDK_MakeKeyFrame(LONG lUserID, LONG lChannel);//主码流
NET_SDK_API BOOL CALL_METHOD NET_SDK_MakeKeyFrameSub(LONG lUserID, LONG lChannel);//子码流
//预览时解码效果的控制参数
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetPlayerBufNumber(POINTERHANDLE lLiveHandle, DWORD dwBufNum);
//画面叠加字符和图像
NET_SDK_API BOOL CALL_METHOD NET_SDK_RegisterDrawFun(POINTERHANDLE lLiveHandle, DRAW_FUN_CALLBACK fDrawFun, void *pUser);
//监听
NET_SDK_API BOOL CALL_METHOD NET_SDK_OpenSound(POINTERHANDLE lLiveHandle);
NET_SDK_API BOOL CALL_METHOD NET_SDK_CloseSound();
NET_SDK_API BOOL CALL_METHOD NET_SDK_Volume(POINTERHANDLE lLiveHandle, WORD wVolume);
//保存本地录像
NET_SDK_API BOOL CALL_METHOD NET_SDK_SaveLiveData(POINTERHANDLE lLiveHandle, char *sFileName);
NET_SDK_API BOOL CALL_METHOD NET_SDK_StopSaveLiveData(POINTERHANDLE lLiveHandle);
//预览显示参数配置
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetVideoEffect_Ex(LONG lUserID, LONG lChannel, NET_SDK_IMAGE_EFFECT_T *pBrightValue, NET_SDK_IMAGE_EFFECT_T *pContrastValue, NET_SDK_IMAGE_EFFECT_T *pSaturationValue, NET_SDK_IMAGE_EFFECT_T *pHueValue);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetVideoEffect_Ex(LONG lUserID, LONG lChannel, DWORD dwBrightValue, DWORD dwContrastValue, DWORD dwSaturationValue, DWORD dwHueValue);


////////////////////////////////////////视频抓图
//JPEG抓图到内存
NET_SDK_API BOOL CALL_METHOD NET_SDK_CaptureJPEGData_V2(LONG lUserID, LONG lChannel, char *sJpegPicBuffer, DWORD dwPicSize, LPDWORD lpSizeReturned);
NET_SDK_API BOOL CALL_METHOD NET_SDK_CaptureJPEGFile_V2(LONG lUserID, LONG lChannel, char *sPicFileName);
NET_SDK_API BOOL CALL_METHOD NET_SDK_CaptureJPEGPicture(LONG lUserID, LONG lChannel, LPNET_SDK_JPEGPARA lpJpegPara, char *sJpegPicBuffer, DWORD dwPicSize, LPDWORD lpSizeReturned);
//设备上的图片，N9000支持
NET_SDK_API BOOL CALL_METHOD NET_SDK_SearchPictures(LONG lUserID, NET_SDK_IMAGE_SREACH sInSreachImage, LONG lInImageBufferSize, NET_SDK_IMAGE *pOutImageInfo, LONG *pOutImageNum);
NET_SDK_API BOOL CALL_METHOD NET_SDK_RemoteSnap(LONG lUserID, int lChannel);//远程抓图
NET_SDK_API BOOL CALL_METHOD NET_SDK_DownLoadPicture(LONG lUserID, NET_SDK_IMAGE captureImage, NET_SDK_IMAGE_INFO *pOutImageInfo, char* pOutBuffer, int outBufferSize);


////////////////////////////////////////设备录像文件回放、下载和锁定////////////////////////////////////////
//根据文件时间查找录像文件
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_FindFile(LONG lUserID, LONG lChannel, DD_TIME *lpStartTime, DD_TIME *lpStopTime);
NET_SDK_API LONG CALL_METHOD NET_SDK_FindNextFile(POINTERHANDLE lFindHandle, NET_SDK_REC_FILE *lpFindData);
NET_SDK_API BOOL CALL_METHOD NET_SDK_FindClose(POINTERHANDLE lFindHandle);
//根据日期查找录像文件
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_FindRecDate(LONG lUserID);
NET_SDK_API LONG CALL_METHOD NET_SDK_FindNextRecDate(POINTERHANDLE lFindHandle, DD_DATE *lpRecDate);
NET_SDK_API BOOL CALL_METHOD NET_SDK_FindRecDateClose(POINTERHANDLE lFindHandle);
//根据事件查找录像文件
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_FindEvent(LONG lUserID, LONG lChannel, DWORD dwRecType, DD_TIME *lpStartTime, DD_TIME *lpStopTime);
NET_SDK_API LONG CALL_METHOD NET_SDK_FindNextEvent(POINTERHANDLE lFindHandle, NET_SDK_REC_EVENT *lpRecEvent);
NET_SDK_API BOOL CALL_METHOD NET_SDK_FindEventClose(POINTERHANDLE lFindHandle);
//根据时间查找录像文件
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_FindTime(LONG lUserID, LONG lChannel, DD_TIME *lpStartTime, DD_TIME *lpStopTime);
NET_SDK_API LONG CALL_METHOD NET_SDK_FindNextTime(POINTERHANDLE lFindHandle, NET_SDK_REC_TIME *lpRecTime);
NET_SDK_API BOOL CALL_METHOD NET_SDK_FindTimeClose(POINTERHANDLE lFindHandle);
//按时间回放录像文件
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_PlayBackByTime(LONG lUserID, LONG *pChannels, LONG channelNum, DD_TIME *lpStartTime, DD_TIME *lpStopTime, HWND *hWnds);//main stream
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_PlayBackByTimeEx(LONG lUserID, LONG *pChannels, LONG channelNum, DD_TIME *lpStartTime, DD_TIME *lpStopTime, HWND *hWnds, BOOL bFirstStream);
NET_SDK_API BOOL CALL_METHOD NET_SDK_PlayBackControl(POINTERHANDLE lPlayHandle, DWORD dwControlCode, DWORD dwInValue, DWORD *lpOutValue);
NET_SDK_API BOOL CALL_METHOD NET_SDK_StopPlayBack(POINTERHANDLE lPlayHandle);
//注册回调函数，捕获录像数据
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetPlayDataCallBack(POINTERHANDLE lPlayHandle, PLAY_DATA_CALLBACK fPlayDataCallBack, void *pUser);
//捕获回放的录像数据，并保存成文件
NET_SDK_API BOOL CALL_METHOD NET_SDK_PlayBackSaveData(POINTERHANDLE lPlayHandle, LONG lChannel, char *sFileName);
NET_SDK_API BOOL CALL_METHOD NET_SDK_StopPlayBackSave(POINTERHANDLE lPlayHandle, LONG lChannel);
//回放的其它操作
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetPlayBackOsdTime(POINTERHANDLE lPlayHandle, DD_TIME *lpOsdTime);//获取录像回放时显示的OSD时间
NET_SDK_API BOOL CALL_METHOD NET_SDK_PlayBackCaptureFile(POINTERHANDLE lPlayHandle, LONG lChannel, char *sFileName);//录像回放时抓图，并保存在文件中
NET_SDK_API BOOL CALL_METHOD NET_SDK_RefreshPlay(POINTERHANDLE lPlayHandle);//刷新显示回放窗口
//下载录像文件
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_GetFileByTime(LONG lUserID, LONG lChannel, DD_TIME *lpStartTime, DD_TIME *lpStopTime, char *sSavedFileName);
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_GetFileByTimeEx(LONG lUserID,LONG lChannel, DD_TIME * lpStartTime, DD_TIME * lpStopTime, char *sSavedFileName, BOOL bCustomFormat, BOOL bUseCallBack=false, BACKUP_DATA_CALLBACK fBackupDataCallBack= NULL, void* pUser = NULL); //bCustomFormat：是否使用私有文件格式
NET_SDK_API BOOL CALL_METHOD NET_SDK_StopGetFile(POINTERHANDLE lFileHandle);
NET_SDK_API int CALL_METHOD NET_SDK_GetDownloadPos(POINTERHANDLE lFileHandle);
//录像文件锁定、解锁、删除
NET_SDK_API BOOL CALL_METHOD NET_SDK_LockFile(LONG lUserID, NET_SDK_REC_FILE *pFileToLock, LONG fileNum);
NET_SDK_API BOOL CALL_METHOD NET_SDK_UnlockFile(LONG lUserID, NET_SDK_REC_FILE *pFileToUnlock, LONG fileNum);
NET_SDK_API BOOL CALL_METHOD NET_SDK_DeleteRecFile(LONG lUserID, NET_SDK_REC_FILE *pFileToUnlock, LONG fileNum);
//远程控制设备端手动录像
NET_SDK_API BOOL CALL_METHOD NET_SDK_StartDVRRecord(LONG lUserID, LONG lChannel, LONG lRecordType);
NET_SDK_API BOOL CALL_METHOD NET_SDK_StopDVRRecord(LONG lUserID, LONG lChannel);


////////////////////////////////////////云台控制相关接口////////////////////////////////////////
//云台控制
NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZControl(POINTERHANDLE lLiveHandle, DWORD dwPTZCommand, DWORD dwSpeed);
NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZControl_Other(LONG lUserID, LONG lChannel, DWORD dwPTZCommand, DWORD dwSpeed);
NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZControl_3D(POINTERHANDLE lLiveHandle, LONG lChannel, PTZ_3D_POINT_INFO *pPtz3DInfo);
//预置点
NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZPreset(POINTERHANDLE lLiveHandle, DWORD dwPTZPresetCmd, DWORD dwPresetIndex);
NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZPreset_Other(LONG lUserID, LONG lChannel, DWORD dwPTZPresetCmd, DWORD dwPresetIndex);
//巡航线
NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZCruise(POINTERHANDLE lLiveHandle, DWORD dwPTZCruiseCmd, BYTE byCruiseRoute);
NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZCruise_Other(LONG lUserID, LONG lChannel, DWORD dwPTZCruiseCmd, BYTE byCruiseRoute);
NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZSetCruise(POINTERHANDLE lLiveHandle, BYTE byCruiseRoute, DD_CRUISE_POINT_INFO *pCruisePoint, WORD pointNum);
NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZSetCruise_Other(LONG lUserID, LONG lChannel, BYTE byCruiseRoute, DD_CRUISE_POINT_INFO *pCruisePoint, WORD pointNum);
//轨迹
NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZTrack(POINTERHANDLE lLiveHandle, DWORD dwPTZTrackCmd);
NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZTrack_Other(LONG lUserID, LONG lChannel, DWORD dwPTZTrackCmd);
//自动扫描和随机扫描都这个接口,bIsAutoScan = true,自动扫描。
NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZAutoScan(POINTERHANDLE lLiveHandle, DWORD dwPTZAutoScanCmd, DWORD dwSpeed, BOOL bIsAutoScan = TRUE);
NET_SDK_API BOOL CALL_METHOD NET_SDK_PTZAutoScan_Other(LONG lUserID, LONG lChannel, DWORD dwPTZAutoScanCmd);
//获取云台信息：获取预置点和巡航线get Preset or Cruise
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetPTZConfig(LONG lUserID, LONG lChannel, DWORD dwPTZCmd,LPVOID lpInBuffer, DWORD dwInBufferSize, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned);
//获取通道支持PTZ的列表
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetSupportPtzList(LONG lUserID, int listNum, NET_SDK_CHANNEL_PTZ* pOutChannelPtz, int *returnListNum);
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetPTZCameraType(LONG lUserID, NET_SDK_CAMERA_TYPE *pCameraType);


////////////////////////////////////////语音对讲和转发////////////////////////////////////////
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_StartVoiceCom(LONG lUserID, BOOL bNeedCBNoEncData, TALK_DATA_CALLBACK fVoiceDataCallBack, void* pUser);
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetAudioInfo(POINTERHANDLE lVoiceComHandle, void *pAudioInfo, LONG infoLen);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetVoiceComClientVolume(POINTERHANDLE lVoiceComHandle, WORD wVolume);
NET_SDK_API BOOL CALL_METHOD NET_SDK_StopVoiceCom(POINTERHANDLE lVoiceComHandle);
//语音转发
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_StartVoiceCom_MR(LONG lUserID, BOOL bNeedNoEncodeData, TALK_DATA_CALLBACK fVoiceDataCallBack, void* pUser);
NET_SDK_API BOOL CALL_METHOD NET_SDK_VoiceComSendData(POINTERHANDLE lVoiceComHandle, char *pSendBuf, DWORD dwBufSize);
//音频解码
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_InitAudioDecoder(void *pAudioInfo, LONG infoLen);
NET_SDK_API BOOL CALL_METHOD NET_SDK_DecodeAudioFrame(POINTERHANDLE lDecHandle, unsigned char *pInBuffer, LONG inLen, unsigned char *pOutBuffer, int *pOutLen);
NET_SDK_API void CALL_METHOD NET_SDK_ReleaseAudioDecoder(POINTERHANDLE lDecHandle);
//音频编码
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_InitAudioEncoder(void *pAudioInfo, LONG infoLen);
NET_SDK_API BOOL CALL_METHOD NET_SDK_EncodeAudioFrame(POINTERHANDLE lEncodeHandle, unsigned char *pInBuffer, LONG inLen, unsigned char *pOutBuffer, int *pOutLen);
NET_SDK_API void CALL_METHOD NET_SDK_ReleaseAudioEncoder(POINTERHANDLE lEncodeHandle);


////////////////////////////////////////设备维护管理////////////////////////////////////////
//升级
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_Upgrade(LONG lUserID, char *sFileName);
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_UpgradeEx(LONG lUserID, char *sFileName);
NET_SDK_API int CALL_METHOD NET_SDK_GetUpgradeState(POINTERHANDLE lUpgradeHandle);
NET_SDK_API int CALL_METHOD NET_SDK_GetUpgradeProgress(POINTERHANDLE lUpgradeHandle);
NET_SDK_API BOOL CALL_METHOD NET_SDK_CloseUpgradeHandle(POINTERHANDLE lUpgradeHandle);
//日志查找
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_FindDVRLog(LONG lUserID, DWORD dwType, DD_TIME *lpStartTime, DD_TIME *lpStopTime);
NET_SDK_API LONG CALL_METHOD NET_SDK_FindNextLog(POINTERHANDLE lLogHandle, LPNET_SDK_LOG lpLogData);
NET_SDK_API BOOL CALL_METHOD NET_SDK_FindLogClose(POINTERHANDLE lLogHandle);
//事件搜索
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_FindEventInfo(LONG lUserID, DWORD dwType, ULONGLONG channlMask, DD_TIME *lpStartTime, DD_TIME *lpStopTime);
NET_SDK_API LONG CALL_METHOD NET_SDK_FindNextEventInfo(POINTERHANDLE lEventHandle, LPNET_SDK_EVENT lpEventData);
NET_SDK_API BOOL CALL_METHOD NET_SDK_FindEventInfoClose(POINTERHANDLE lEventHandle);
//恢复默认值
NET_SDK_API BOOL CALL_METHOD NET_SDK_RestoreConfig(LONG lUserID);
//配置文件导出导入
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetConfigFile(LONG lUserID, char *sFileName);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetConfigFile(LONG lUserID, char *sFileName);
//关机和重启
NET_SDK_API BOOL CALL_METHOD NET_SDK_ShutDownDVR(LONG lUserID);
NET_SDK_API BOOL CALL_METHOD NET_SDK_RebootDVR(LONG lUserID);
//远程查询硬盘
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_FindDisk(LONG lUserID);
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetNextDiskInfo(POINTERHANDLE lDiskHandle, NET_SDK_DISK_INFO *pDiskInfo);
NET_SDK_API BOOL CALL_METHOD NET_SDK_FindDiskClose(POINTERHANDLE lDiskHandle);
//格式化硬盘
NET_SDK_API POINTERHANDLE CALL_METHOD NET_SDK_FormatDisk(LONG lUserID, LONG lDiskNumber);
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetFormatProgress(POINTERHANDLE lFormatHandle, LONG *pCurrentFormatDisk, LONG *pCurrentDiskPos, LONG *pFormatStatic);
NET_SDK_API BOOL CALL_METHOD NET_SDK_CloseFormatHandle(POINTERHANDLE lFormatHandle);


////////////////////////////////////////设备参数配置////////////////////////////////////////
NET_SDK_API LONG CALL_METHOD NET_SDK_EnterDVRConfig(LONG lUserID);
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDVRConfig(LONG lUserID, DWORD dwCommand, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned, BOOL bDefautlConfig);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetDVRConfig(LONG lUserID, DWORD dwCommand, LONG lChannel, LPVOID lpInBuffer,  DWORD dwInBufferSize);
NET_SDK_API BOOL CALL_METHOD NET_SDK_ExitDVRConfig(LONG lUserID);

NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDVRConfig_SubStreamEncodeInfo(LONG lUserID, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned, BOOL bDefautlConfig);	//For N9000
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetDVRConfig_SubStreamEncodeInfo(LONG lUserID, LONG lChannel, LPVOID lpInBuffer,  DWORD dwInBufferSize);													//For N9000
//相对NET_SDK_GetDVRConfig_SubStreamEncodeInfo，返回结构体中多了支持的码率选项; 返回的是支持的编码信息
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDVRConfig_SubStreamEncodeInfo_Ex(LONG lUserID, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned, BOOL bDefautlConfig);	//For N9000
NET_SDK_API BOOL CALL_METHOD NET_SDK_SaveConfig(LONG lUserID);//保存参数
NET_SDK_API BOOL CALL_METHOD NET_SDK_ChangTime(LONG lUserID, unsigned int time);//修改设备系统时间
//NET_SDK_API BOOL CALL_METHOD NET_SDK_ModifyDeviceNetInfo(NET_SDK_DEVICE_IP_INFO *pDeviceIPInfo);//修改设备IP
NET_SDK_API void CALL_METHOD NET_SDK_FormatTime(LONGLONG intTime, DD_TIME *pFormatTime);//整型时间转换为格式化的时间


////////////////////////////////////////智能报警（只针对智能IPC）////////////////////////////////////////
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetIVMRuleConfig(LONG lUserID, DWORD dwCommand, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetIVMRuleConfig(LONG lUserID, DWORD dwCommand, LONG lChannel, LPVOID lpInBuffer,  DWORD dwInBufferSize);
//dwCommand NET_DVR_SMART_TYPE
//NET_DVR_IVE_VFD_RESULT_HEAD_T+[NET_DVR_IVE_VFD_RESULT_DATA_INFO_T+源数据]+[NET_DVR_IVE_VFD_RESULT_FACE_DATA_INFO_T+人脸数据+人脸目标值]+...+[NET_DVR_IVE_VFD_RESULT_FACE_DATA_INFO_T+人脸数据+人脸目标值]
typedef void (CALLBACK *SUBSCRIBE_CALLBACK)(LONG lUserID, DWORD dwCommand, char *pBuf, DWORD dwBufLen, void *pUser);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetSubscribCallBack(SUBSCRIBE_CALLBACK fSubscribCallBack, void *pUser);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SmartSubscrib(LONG lUserID, DWORD dwCommand, LONG lChannel, NET_DVR_SUBSCRIBE_REPLY *pOutBuffer);
NET_SDK_API BOOL CALL_METHOD NET_SDK_UnSmartSubscrib(LONG lUserID, DWORD dwCommand, LONG lChannel, char *pInServerAddress, int *dwResult);
//FaceMatch NET_SDK_FACE_MATCH_OPERATE_TYPE
NET_SDK_API BOOL CALL_METHOD NET_SDK_FaceMatchOperate(LONG lUserID, DWORD dwCommand,LPVOID lpInBuffer, DWORD dwInBufferSize,LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned);
//透传API接口函数，实现与设备端直接xml互通
NET_SDK_API BOOL CALL_METHOD NET_SDK_ApiInterface(LONG lUserID, char *sendXML, char *strUrl, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned);

////////////////////The following interfaces will stop updating, they are not recommended.
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDeviceFirmwareType(LONG lUserID, NET_SDK_DEVICE_FIRMWARE_TYPE *pFirmwareType);
NET_SDK_API BOOL CALL_METHOD NET_SDK_GetDeviceIPByName(char *sSerIP,DWORD wSerPort,char *sDvrName,char *sDvrIP);//通过设备名称获取IP地址
NET_SDK_API LONG CALL_METHOD NET_SDK_GetProductSubID(char *sDVRIP,WORD wDVRPort);
NET_SDK_API char* CALL_METHOD NET_SDK_GetErrorMsg(LONG *pErrorNo = NULL);
NET_SDK_API LONG CALL_METHOD NET_SDK_GetDeviceTypeName(LONG lUserID, char *pNameBuffer, int bufferLen);
NET_SDK_API BOOL CALL_METHOD NET_SDK_SetLogToFile(BOOL bLogEnable = FALSE, char *strLogDir = NULL, BOOL bAutoDel = TRUE);//启用日志文件写入接口
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
