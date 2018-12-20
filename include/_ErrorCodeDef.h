
#ifndef __EROORCODE_DEF__
#define __EROORCODE_DEF__
/*
1、错误码定义的标准为一个DWORD类型的值，第29位必须为1以保证与MS定义的错误码做区分。
2、所有用户函数返回错误的地方都可以通过GetLastError获取最终错误码。


这样做的好处：可以随时获取函数返回错误的原因，不需要错误码在函数中层层上传。

*/


#define USER_ERROR_FLAG             0x20000000 ///////////////用户错误都需要这个位为1


//
// MessageId: USER_ERROR_NODE_ID_EXISTS
//
// MessageText:节点ID已经存在
//
#define USER_ERROR_NODE_ID_EXISTS              USER_ERROR_FLAG+0x01
#define USER_ERROR_NODE_EXISTS                 USER_ERROR_NODE_ID_EXISTS
//
// MessageId: USER_ERROR_UNKNOWN
//
// MessageText:未知错误
//
#define USER_ERROR_UNKNOWN              USER_ERROR_FLAG+0x02


//
// MessageId: USER_ERROR_DISK_SPACE_NO_ENOUGH
//
// MessageText:磁盘空间不足
//
#define USER_ERROR_DISK_SPACE_NO_ENOUGH              USER_ERROR_FLAG+0x03


//
// MessageId: USER_ERROR_NETNODE_ID_CONFLICT
//
// MessageText:网络节点ID冲突 一般在加入网络节点时出现
//
#define USER_ERROR_NETNODE_ID_CONFLICT            USER_ERROR_FLAG+0x04

//
// MessageId: USER_ERROR_NETNODE_INITIAL_ERROR
//
// MessageText:网络节点初始化错误
//
#define USER_ERROR_NETNODE_INITIAL_ERROR            USER_ERROR_FLAG+0x05

//
// MessageId: USER_ERROR__CREATE_MSU_CHAL_TABLE_ERROR
//
// MessageText:创建MSU服务器所存储通道的表不成功！
//
#define USER_ERROR__CREATE_MSU_CHAL_TABLE_ERROR            USER_ERROR_FLAG+0x06

//
// MessageId: USER_ERROR__DELETE_MSU_CHAL_TABLE_ERROR
//
// MessageText:删除MSU服务器所存储通道的表不成功！
//
#define USER_ERROR__DELETE_MSU_CHAL_TABLE_ERROR            USER_ERROR_FLAG+0x07

//
// MessageId: USER_ERROR__CREATE_MDU_DEVICE_TABLE_ERROR
//
// MessageText:创建MDU服务器所存转发设备的表不成功！
//
#define USER_ERROR__CREATE_MDU_DEVICE_TABLE_ERROR            USER_ERROR_FLAG+0x08

//
// MessageId: USER_ERROR__DELETE_MDU_DEVICE_TABLE_ERROR
//
// MessageText删除MDU服务器所存转发设备的表不成功！
//
#define USER_ERROR__DELETE_MDU_DEVICE_TABLE_ERROR            USER_ERROR_FLAG+0x09


//
// MessageId: USER_ERROR__GET_INFO_ITEMID_ERROR
//
// 获取信息时ItemID错误
//
#define USER_ERROR__GET_INFO_ITEMID_ERROR            USER_ERROR_FLAG+0x0A

//
// MessageId: USER_ERROR__CANNOT_FIND_NODE_ERROR
//
// 不能找到节点
//
#define USER_ERROR__CANNOT_FIND_NODE_ERROR            USER_ERROR_FLAG+0x0B

//
// MessageId: USER_ERROR__CANNOT_FIND_NODE_ERROR
//
// 此节点没有子节点
//
#define USER_ERROR__NO_CHILD_NODE_ERROR            USER_ERROR_FLAG+0x0C


//
// MessageId: USER_ERROR__NO_PARENT_NODE_ERROR
//
// 此节点没有父节点
//
#define USER_ERROR__NO_PARENT_NODE_ERROR			USER_ERROR_FLAG+0x0D

//
// MessageId: USER_ERROR_ADD_FRAME_TYPE_INEXISTENT
//
// 加入错误的帧数据到列表,说明加入的帧类型不存在
//
#define USER_ERROR_ADD_FRAME_TYPE_INEXISTENT			USER_ERROR_FLAG+0x0E

//
// MessageId: USER_ERROR_SEND_OVERTIME
//
// 发送数据超时
//
#define USER_ERROR_SEND_OVERTIME			            USER_ERROR_FLAG+0x0F

//
// MessageId: USER_ERROR_MODULE_NO_INITIAL
//
// 发送数据超时
//
#define USER_ERROR_MODULE_NO_INITIAL			            USER_ERROR_FLAG+0x10

//
// MessageId: USER_ERROR_INVALID_POINT
//
// 无效的坐标值 
//
#define USER_ERROR_INVALID_POINT			            USER_ERROR_FLAG+0x11

//
// MessageId: USER_ERROR_CANNOT_FIND_CHMDU
//
// 找不到转发通道的转发服务器 
//
#define USER_ERROR_CANNOT_FIND_CHMDU			            USER_ERROR_FLAG+0x12

//
// MessageId: USER_ERROR_NODE_NET_DISCONNECT
//
// 节点网络连接断开
//
#define USER_ERROR_NODE_NET_DISCONNECT			            USER_ERROR_FLAG+0x13

//
// MessageId: USER_ERROR_CHANNEL_NO_OPEN_VIDEO
//
// 通道没有打开视频
//
#define USER_ERROR_CHANNEL_NO_OPEN_VIDEO   USER_ERROR_FLAG+0x14


//
// MessageId: USER_ERROR_STREAM_PENDING
//
// 此流的请求稍后会被完成
//
#define USER_ERROR_STREAM_PENDING		            USER_ERROR_FLAG+0x15

//
// MessageId: USER_ERROR_FAIL
//
// 失败
//
#define USER_ERROR_FAIL			                            USER_ERROR_FLAG+0x16



//
// MessageId: USER_ERROR_NODE_NET_DISCONNECT
//
// 节点不在线,当不能与这个节点链接时,这个节点不在线 
//
#define USER_ERROR_NODE_NET_OFFLINE			    USER_ERROR_FLAG+0x17

//
// MessageId: USER_ERROR_UNSUPPORTED_NODE
//
// 不支持的节点
//
#define USER_ERROR_UNSUPPORTED_NODE			    USER_ERROR_FLAG+0x18

//路由错误，注册服务器不在线或者注册服务器找不到相关路由信息
#define USER_ERROR_ROUTE_ERROR						    USER_ERROR_FLAG+0x19

//使用的节点ID是无效的
#define USER_ERROR_INVLID_NODE						    USER_ERROR_FLAG+0x1A
	
//服务还没准备好
#define USER_ERROR_NO_READY								USER_ERROR_FLAG+0x1C

//任务不存在
#define USER_ERROR_TASK_NO_EXISTS						USER_ERROR_FLAG+0x1D

//无录像数据
#define USER_ERROR_NO_RECORDDATA					USER_ERROR_FLAG+0x1E

//无效参数,在命令传输的参数里出现没法处理的参数时返回此值
#define USER_ERROR_INVALID_PARAM						USER_ERROR_FLAG+0x1F

//不支持的命令
#define USER_ERROR_UNSUPPORTED_CMD			    USER_ERROR_FLAG+0x20

//设备忙,不能请求
#define USER_ERROR_DEVICE_BUSY				            USER_ERROR_FLAG+0x21

//端口监听失败
#define USER_ERROR_LISTEN_FAIL				            USER_ERROR_FLAG+0x22

//此用户不存在
#define USER_ERROR_NO_USER								USER_ERROR_FLAG+0x23

//密码错误
#define USER_ERROR_PWD_ERR								USER_ERROR_FLAG+0x24

//用户已经登陆
#define USER_ERROR_USER_ALREDAY_LOGIN			USER_ERROR_FLAG+0x25

//用户被限制在特有的电脑上MAC、IP
#define USER_ERROR_USER_LIMITED							USER_ERROR_FLAG+0x26

//用户被锁定，暂时无法使用
#define USER_ERROR_USER_LOCKED							USER_ERROR_FLAG+0x27

//自己登陆自己
#define USER_ERROR_LOGIN_SELF							USER_ERROR_FLAG+0x28

//权限不够
#define USER_ERROR_NO_AUTH								USER_ERROR_FLAG+0x29

//系统忙,不能请求
#define USER_ERROR_SYSTEM_BUSY				            USER_ERROR_FLAG+0x30

//文件流被完成，不是用户主动结束的，而是由于网络原因或者文件结束后自动完成的
#define USER_ERROR_FILE_STREAM_COMPLETED				USER_ERROR_FLAG+0x31

//获取配置信息失败
#define USER_ERROR_GET_CONFIG_INFO_FAIL					USER_ERROR_FLAG+0x32

//正在被另外一个用户配置，请等待退出后再进入
#define USER_ERROR_ANOTHER_USER_HASENTER					USER_ERROR_FLAG+0x33

//登录超时错误
#define USER_ERROR_LOGIN_OVERTIME					USER_ERROR_FLAG+0x34

//用户音频打开失败，由于视频没有打开导致的 
#define USER_ERROR_CHANNEL_AUDIO_OPEN_FAIL					USER_ERROR_FLAG+0x35

//未登陆成功的情况下发送了指令，返回此值
#define USER_ERROR_NOLOGIN					USER_ERROR_FLAG+0x36

//找不到地图
#define USER_ERROR_CANNOT_FIND_MAP_ERROR			USER_ERROR_FLAG+0x37

//没有父地图
#define USER_ERROR_NO_PARENT_MAP_ERROR				USER_ERROR_FLAG+0x38

//没有子地图
#define USER_ERROR_NO_CHILD_MAP_ERROR				USER_ERROR_FLAG+0x39

//名称已经存在
#define USER_ERROR_NAME_EXISTED					    USER_ERROR_FLAG + 0x3a

//保存地图文件失败
#define USER_ERROR_MAP_SAVE_ERROR		            USER_ERROR_FLAG + 0x3B

//没有电子地图的信息
#define USER_ERROR_EMAP_NO_INFO		                USER_ERROR_FLAG + 0x3C


//
// MessageId: USER_ERROR_NOSUPPORT_DEV_VERSION
//
// 不支持的前端设备的版本
//
#define USER_ERROR_NOSUPPORT_DEV_VERSION		            USER_ERROR_FLAG+0x3D

//设备回放请求才用此状,等待上一个请求返回
#define USER_ERROR_STREAM_WAITING							USER_ERROR_FLAG+0x3E

//设备不支持此功能
#define USER_ERROR_UNSUPPORTED_FUNC							USER_ERROR_FLAG+0x3F

//设备类型错误
#define USER_ERROR_DEVICE_TYPE_ERROR						USER_ERROR_FLAG+0x40

//文件类型错误
#define USER_ERROR_FILE_TYPE_ERROR						   USER_ERROR_FLAG+0x41

//文件已经存在
#define USER_ERROR_FILE_EXISTED								USER_ERROR_FLAG + 0x42

//文件不存在
#define USER_ERROR_FILE_NO_EXISTED							USER_ERROR_FLAG + 0x43

//文件打开(创建)错误
#define USER_ERROR_OPEN_FILE_ERROR							USER_ERROR_FLAG + 0x44


//
// MessageId: USER_ERROR_EXISTED_CHILD_NODE
//
// 此节点有子节点
//
#define USER_ERROR_EXISTED_CHILD_NODE            USER_ERROR_FLAG+0x45


//
// MessageId: USER_ERROR_DEV_RESOURCE_LIMITED
//
// 设备资源限制
//
#define USER_ERROR_DEV_RESOURCE_LIMITED            USER_ERROR_FLAG+0x46

//
// MessageId: USER_ERROR_DECODE_RESOURCE_LACK
//
// 没有解码资源,没有解码引擎
//
#define USER_ERROR_DECODE_RESOURCE_LACK				USER_ERROR_FLAG+0x47

//
// MessageId: USER_ERROR_DECODE_RESOURCE_LIMITED
//
// 解码资源限制,丢帧解码
//
#define USER_ERROR_DECODE_RESOURCE_LIMITED			USER_ERROR_FLAG+0x48

//无对应的录像日志
#define USER_ERROR_NO_RECORD_LOG								USER_ERROR_FLAG+0x49

//录像读取任务过多
#define USER_ERROR_READ_TASK_TOO_MUCH						USER_ERROR_FLAG+0x4A

//IP地址格式错误
#define USER_ERROR_INVALID_IP           USER_ERROR_FLAG+0x50
//子网掩码格式错误
#define USER_ERROR_INVALID_SUBMASK      USER_ERROR_FLAG+0x51
//无效IP地址和子网掩码合并。IP地址的主机地址部分里的所有字节都被设置为1
#define USER_ERROR_IP_MASK_ALL1      USER_ERROR_FLAG+0x52
//无效IP地址和子网掩码合并。IP地址的主机地址部分里的所有字节都被设置为0
#define USER_ERROR_IP_MASK_ALL0      USER_ERROR_FLAG+0x53
//无效网关地址和子网掩码合并。网关的主机地址部分里的所有字节都被设置为1
#define USER_ERROR_ROUTE_MASK_ALL1      USER_ERROR_FLAG+0x54
//无效网关地址和子网掩码合并。网关的主机地址部分里的所有字节都被设置为0
#define USER_ERROR_ROUTE_MASK_ALL0      USER_ERROR_FLAG+0x55
//以127起头的IP地址无效，因为它们保留用作环回地址。请指定一个介于 1 和 223 之间的数值
#define USER_ERROR_USE_LOOPBACK      USER_ERROR_FLAG+0x56
//IP地址或网关不是以一个有效的值开头。请指定一个介于 1 和 223 之间的数值
#define USER_ERROR_IP_ROUTE_INVALID      USER_ERROR_FLAG+0x57
//输入一个无效的子网掩码，子网掩码必须是相邻的
#define USER_ERROR_MASK_NOT_CONTINE      USER_ERROR_FLAG+0x58
//网关不在由IP地址和子网掩码定义的同一网段上
#define USER_ERROR_DIFFERENT_SEGMENT      USER_ERROR_FLAG+0x59
//网关地址格式错误
#define USER_ERROR_INVALID_GATEWAY           USER_ERROR_FLAG+0x5A
//域名格式错误
#define USER_ERROR_INVALID_DOMAIN_NAME    USER_ERROR_FLAG+0x5B

//超出数量限制
#define USER_ERROR_OVER_LIMIT    USER_ERROR_FLAG+0x5C

//超出流量限制
#define USER_ERROR_OVER_BANDWIDTH_LIMIT		USER_ERROR_FLAG+0x5D

//双网口IP不能在同一个网段
#define USER_ERROR_IP_SAME_NETWORK_SEGMENT USER_ERROR_FLAG+0x5E

//资源冲突
#define USER_ERROR_RESOURCE_CONFLICT USER_ERROR_FLAG+0x5F

//子码流自适应未打开
#define MOBILE_STREAM_ADAPTION_NOT_OPEN USER_ERROR_FLAG+0x60

//HTTP端口错误
#define USER_ERROR_HTTP_PORT_ERROR USER_ERROR_FLAG+0x61

// RTSP URL错误
#define USER_ERROR_RTSP_URL_ERROR  USER_ERROR_FLAG+0x62

//session ID 校验失败
#define USER_CHECK_SESSIONID_FAIL  USER_ERROR_FLAG+0x63

// 修改磁盘组信息错误
#define USER_ERROR_DISK_IN_GROUP_ERROR  USER_ERROR_FLAG+0x63


// 创建阵列失败
#define CREATE_RAID_ERROR  USER_ERROR_FLAG+0x64

// 删除阵列失败
#define DELETE_RAID_ERROR  USER_ERROR_FLAG+0x65

// 配置热备盘失败
#define CONFIG_HOT_DISK_ERROR  USER_ERROR_FLAG+0x66

// 配置普通盘失败
#define CONFIG_NORMAL_DISK_ERROR  USER_ERROR_FLAG+0x67

// 重建阵列失败
#define REPAIR_RAID_ERROR  USER_ERROR_FLAG+0x68



// 版本不兼容
#define USER_ERROR_INCOMPATIBLE_VERSION  USER_ERROR_FLAG+0x69

// 相同版本
#define USER_ERROR_SAME_VERSION  USER_ERROR_FLAG+0x70


//人脸错误码起始值
//#define USER_ERROR_FACE_BEGIN  USER_ERROR_FLAG+0x71

//图片尺寸太大，超过规定的
#define USER_ERROR_PICTURE_TOO_LARGE  USER_ERROR_FLAG+0x71

//人脸图片无法提取特征（清晰度不够或非人脸图片）
#define USER_ERROR_FACE_EXTRACT_FAILED  USER_ERROR_FLAG+0x72

// 特征提取任务队列已满，提取资源不足
// #define USER_ERROR_FACE_EXTRACT_QUEUE_FULL  USER_ERROR_DEV_RESOURCE_LIMITED

//目标库的分组不存在
#define USER_ERROR_FACE_TARGET_GROUP_NOT_EXIST  USER_ERROR_FLAG+0x74

//目标人员信息错误（例如，某些字段超过限制或包含非法字符）
//#define USER_ERROR_FACE_PERSON_INFO_INVALID  USER_ERROR_INVALID_PARAM

//无磁盘（例如，添加人脸到目标库，因为没有接入磁盘而报添加失败的错误）
#define USER_ERROR_NO_DISK  USER_ERROR_FLAG+0x76

//目标库的分组已经满
#define USER_ERROR_FACE_TARGET_GROUP_FULL  USER_ERROR_FLAG+0x77

//目标库已经满
#define USER_ERROR_FACE_TARGET_DATABASE_FULL  USER_ERROR_FLAG+0x78

//人脸图片不存在，即找不到这张人脸图片
#define USER_ERROR_FACE_NOT_EXIST  USER_ERROR_FLAG+0x79

//人脸图片转码失败(例如JPG转RGB失败)
#define USER_ERROR_FACE_PICTURE_DECODE_FAILED  USER_ERROR_FLAG+0x7A

//人脸错误码结束值
//#define USER_ERROR_FACE_END  USER_ERROR_FLAG+0xA0

//磁盘读写错误
#define USER_ERROR_RW_HARD_DISK  USER_ERROR_FLAG+0x7B

//人脸识别错误
#define USER_ERROR_FACE_RECOGNIZE  USER_ERROR_FLAG+0x7C

//目标库分组数量达到上限
#define USER_ERROR_FACE_GROUP_NUM_LIMITED USER_ERROR_FLAG+0x7D

//外部中断
#define USER_ERROR_EXTERNAL_INTERRUPTION   USER_ERROR_FLAG+0x7E

// (XSS攻击) 非法参数
#define USER_ERROR_ILLEGAL_PARAM  USER_ERROR_FLAG+0x7F

#define USER_ERROR_PWD_SECURE     USER_ERROR_FLAG+0x72

#endif
