#ifndef PARADEF_H
#define PARADEF_H

#include <QString>

typedef char s8;
typedef short s16;
typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

enum MainWidget_id{
    Login_id=0,      //权限登录界面ID
    Main_id,     //主界面ID
    SubSet_id,   //子设置界面ID
    SubRun_id,  //配方和生产参数界面ID
    SubManual_id, //手动子界面系列ID
};
enum Status{
    Stop_id=0,
    Run_id,
    Manual_id,
};

//设置界面按钮id
enum setSwitch{
    User_id=0,      //用户设定ID
    Signal_id,      //信号设定ID
    Safe_id,        //安全设定ID
    System_id,      //系统设定ID
    Program_id,     //程序管理ID
    ExFunction_id   //扩展功能ID
};

//IO设置子界面id
enum IOSetSwitch{
    IOSetSel_id=0,      //输入输出设置选择ID
    InputSet_id,      //输入设置ID
    OutputSet_id,      //输出设置ID
};

//IO设置编辑对话框界面id
enum IOSetDialog{
    InputSetDialog_id=0,      //输入设置对话框ID
    OutputSetDialog_id,      //输出设置对话框ID
};

//系统设置子界面按钮id
enum sysSetSwitch{
    ArmSet_id=0,      //机械手设定ID
    AxisParaSet_id,      //轴参数设定ID
    ValParaSet_id,        //绝对值参数设定ID
    UserVarSet_id,      //用户变量设定ID
    CoordSet_id,     //笛卡尔坐标系设定ID
};

//用户设置子界面按钮id
enum UserSetSwitch{
    UserSet_id=0,      //用户设定主界面ID
    UserSetDialog_id,      //用户设置弹窗界面ID
    TimeSet_id,        //时间设置界面ID
    ModPassword_id,      //修改密码ID
    EncryptionSet_id,     //加密设置ID
};

//用户设置子界面按钮id
enum CodeDialogSwitch{
    Rst_id=0,      //恢复出厂设置弹窗ID
    PasswordErrorTip_id,      //密码错误提示弹窗ID
    EncryptionErrorTip_id,        //加密错误提示弹窗ID
};

enum EditDialogSwitch{
    CondSel_id=0,   //条件选择
    AxisSelCmp_id,    //轴选择比较
    VarCmp_id,  //变量比较
};

//存储点对话框id
enum ModDialog{
    PosMod_id=0,
    NameMod_id,
    Del_id,
};



//安全设置子界面按钮id
enum safeSetSwitch{
    LimPosSet_id=0,      //软限位设置ID
    SafeAreaSet_id,      //安全区设置ID
};

//程序相关界面id(0~3为程序设定提供，4为编程界面的程序选择按钮提供)
enum ProgWidget{
    ProgMgt_id=0,   //程序管理界面ID
    CopySel_id,    //拷贝选择界面ID
    CtoU_id,    //控制器拷贝到U盘界面ID
    UtoC_id,    //U盘拷贝到控制器界面ID
    ProgSel,    //程序选择界面ID
};


//IO调试界面id
enum IOSetWidget{
    InputPort_id=0,      //输入口界面ID
    OutputPort_id,      //输出口界面ID
};

//菜单界面按钮id
enum MenuWidget{
    MainMenu_id=0,
    BasicCmd_id,
    AxisCtlCmd_id,
};

//菜单界面按钮id
enum FreeProgWidget{
    Prog_id=0,
    Input_id,
    Output_id,
};

//编程界面编辑对话框ID
enum DialogSwitch{
    MainProg_id=0,
    SubProg_id,
    AxisMove_id,
    IncMotion_id,
    StackPos_id,
    StackCnt_id,
    UserVar_id,
    PulseWidthOutput_id,
    JudgeCond_id,
    LoopCond_id,
    Jump_id,
    Delay_id,
    Otherwise_id,
    SpecialCmd_id,
    OutputDetect_id,
    SearchMotion_id,
    MachBack0_id,
    CoordRst_id,
    SlowDownPoint_id,
    InterpolationStart_id,
    AdvConfirm_id,
    LineInterpolation_id,
    TransPoint_id,
    OutputCtl_id,
    InputDetect_id,
};

#define FALSE     	0
#define TRUE     	1


#define	TIM3_TEMP	30000

//------------主界面页码------------//
#define START_UP       1
#define FREE_PROGRAMME 2
#define IO_CONTROL     3
#define MANUL_DEBUG    4
#define SYSTEM_SETTING 5
#define ALARM_HISTORY  6

/**------------命令--------------**/
#define   ROBOT_ENABLE_A_ORIGIN  0x0A	//机械手使能和回原点
#define   WORK_MODE              0x0B	//机械手工作模式
#define   AUTO_RUN               0x0C	//机械手自动运行
#define   FREE_PROGRAM_SEND      0x0D	//自由编程程序下发
#define   WATCH_COMMAND          0x0E	//监视命令
#define   READ_IIC	             0x0F	//开机读IIC
#define   IO_DEBUG_OUTPUT1       0x1A	//IO调试-输出1
#define   IO_DEBUG_OUTPUT2       0x1B	//IO调试-输出2
#define   IO_DEBUG_OUTPUT3       0x1C	//IO调试-输出3
#define   MANUL_OPERATE          0x1D	//手动调试
#define   PARAMETER_ORDER        0x1E	//参数命令
#define   SYSTEM_SET_SEND        0x1F   //设置拷贝下发
#define   MDPARA_COPY_SEND		 0x2A   //码垛拷贝下发

/**-------0x0A-----使能和回原点--------------**/
#define   ROBOT_ORIGIN   	     	0x01	//机械手回原点
#define		ORIGNSETTING			0x02	//原点设置
#define		ORIGNRESETTING			0x03	//原点重置
#define		MACHINEORIGIN			0x04	//机械回零
#define   	ROBOT_ENABLE	    	0x07	//机械手是否使能

/**-------0x0B-----工作模式--------------**/
#define   WAIT_MODE			     0x00   //等待模式
#define   AUTO_MODE              0x01	//自动模式
#define   FREE_PROGRAM           0x02	//自由编程
#define   IO_MODE                0x03	//IO调试
#define   MANUL_MODE             0x04	//手动调试


/**-------0x0C-----自动运行--------------**/
#define ONCE_MODE               0x0C	//单次模式
#define	CYCLE_MODE				0x01	//循环模式
#define	SINGLE_MODE				0x02	//单步模式
#define	ACTION_RUN				0x03	//启动
#define	ACTION_PAUSE			0x04	//暂停
#define	ACTION_STOP				0x05	//停止
#define	ACTION_PROGRAM			0x06	//选择运行的程序
#define	ACTION_RESET			0x07	//机械手复位
#define	ACTION_DEBUG			0x08	//机械手调试-自由编程的调试按钮
#define	ACTION_LORIGIN			0x09	//机械手L轴回零
#define	ACTION_COMMUTE			0x0A	//机械手下班指令
#define	ACTION_SPEEDADJ			0X0B	//总速度调节---20181120

/**-------0x0D-----自由编程--------------**/
#define   PROGRAM_START          0xE1	//程序开始
#define   PROGRAM_INFO           0xE2	//程序信息描述
#define   PROGRAM_CONT           0xE3	//程序内容
#define   PROGRAM_DELETE         0xE4	//程序删除
#define   PROGRAM_FROM_USB_START 0xE5	//USB程序拷贝发送开始
#define   PROGRAM_FROM_USB_END   0xE6	//USB程序拷贝发送结束
#define   PROGRAM_END            0xED	//程序结束
#define   DELETE_ALL_PROGRAM     0xE7   //删除所有程序

/**-------0x0E-----监视命令--------------**/
#define   IO_DEBUG_INPUT1        	0x02	//IO调试-输入1
#define   IO_DEBUG_INPUT2        	0x03	//IO调试-输入2
#define   IO_DEBUG_INPUT3        	0x04	//IO调试-输入3
#define   IO_DEBUG_OUTPUT1_LCD   	0x05	//IO调试-输出1界面
#define   IO_DEBUG_OUTPUT2_LCD   	0x06	//IO调试-输出2界面
#define   IO_DEBUG_OUTPUT3_LCD   	0x07	//IO调试-输出3界面
#define   ROBOT_ORIGINED		 	0x08	//机械手是否已回原点
#define   ACTION_RESET_SCAN	     	0x09	//机械手复位状态查询
#define   ALARM_CLEAR	         	0x0A	//清除当前报警信息
#define   ROBOT_STATUS      	 	0x0B	//查询机械手状态
#define   AUTO_PARAMETER         	0x0C	//自动运行参数-当前行-产量
#define   X_AXSIS_POSITION	     	0x0D	//X轴坐标
#define   L_AXSIS_POSITION       	0x0E	//L轴坐标
#define   Z_AXSIS_POSITION       	0x0F	//Z轴坐标
#define   O_AXSIS_POSITION       	0x10	//O轴坐标
#define   ROBOT_PRE_STATUS       	0x11	//机械手运行状态
#define   ROBOT_DEBUG_STATUS     	0x12	//机械手调试状态
#define   DELETE_POINT_STATUS    	0x13	//查询点是否删除完
#define   DELETE_PROGRAM_STATUS  	0x14	//查询程序是否删除完
#define	  ORIGIN_SETTING_STATUS		0x15	//获取原点设置状态
#define	  ORIGIN_RESETTING_STATUS	0x16	//获取原点重置状态
#define	  MACHINE_ORIGIN_STATUS		0x17	//获取机械回原点状态
#define   USER_CURNUM        		0x18	//用户变量
#define   DELETE_MD_STATUS  		0x19	//查询码垛是否删除完
#define   EXTENDCOM_STATUS			0x1A	//获取机械手485通信状态变量
#define	  ONE_POINT_POSITON			0x1B	//获取某一个点的位置信息
#define	  EXTEND_SERIAL_NUM			0x1C	//获取序列号
#define   MD_CURLAYER_CURNUM        0x1E	//查询物品当前层和当前个数

/**-------0x0F-----开机读IIC--------------**/
#define   READ_IIC_1	         0x01	//设置参数
#define   READ_IIC_2	         0x02	//存储点参数
#define   READ_IIC_3	         0x03	//程序信息
#define   READ_IIC_4	         0x04	//程序
#define   READ_IIC_5	         0x05	//软限位
#define   READ_IIC_6	         0x06	//安全区
#define   READ_IIC_7	         0x07	//IO检测参数
#define   READ_IIC_8	         0x08	//码垛点
#define   READ_IIC_9	         0x09	//码垛参数
#define   READ_IIC_10	         0x0A	//码垛名称信息
#define   READ_IIC_11	         0x0B	//输出复位
#define   READ_IIC_12	         0x0C	//参数拷贝-读参数
#define   READ_IIC_13	         0x0D	//码垛拷贝-读参数

/**-------0x1A-----IO调试-输出1---0x01 Y0--0x0F Y14--------**/
#define   IODEBUG_OUTPUT1_1      0x01	//
#define   IODEBUG_OUTPUT1_2      0x02	//
#define   IODEBUG_OUTPUT1_3      0x03	//
#define   IODEBUG_OUTPUT1_4      0x04	//
#define   IODEBUG_OUTPUT1_5      0x05	//
#define   IODEBUG_OUTPUT1_6      0x06	//
#define   IODEBUG_OUTPUT1_7      0x07	//
#define   IODEBUG_OUTPUT1_8      0x08	//
#define   IODEBUG_OUTPUT1_9      0x09	//
#define   IODEBUG_OUTPUT1_10     0x0A	//
#define   IODEBUG_OUTPUT1_11     0x0B	//
#define   IODEBUG_OUTPUT1_12     0x0C	//
#define   IODEBUG_OUTPUT1_13     0x0D	//
#define   IODEBUG_OUTPUT1_14     0x0E	//
#define   IODEBUG_OUTPUT1_15     0x0F	//

/**-------0x1B-----IO调试-输出2--- 0X01 Y15---0X0F Y29--------**/
#define   IODEBUG_OUTPUT2_1      0x01	//
#define   IODEBUG_OUTPUT2_2      0x02	//
#define   IODEBUG_OUTPUT2_3      0x03	//
#define   IODEBUG_OUTPUT2_4      0x04	//
#define   IODEBUG_OUTPUT2_5      0x05	//
#define   IODEBUG_OUTPUT2_6      0x06	//
#define   IODEBUG_OUTPUT2_7      0x07	//
#define   IODEBUG_OUTPUT2_8      0x08	//
#define   IODEBUG_OUTPUT2_9      0x09	//
#define   IODEBUG_OUTPUT2_10     0x0A	//
#define   IODEBUG_OUTPUT2_11     0x0B	//
#define   IODEBUG_OUTPUT2_12     0x0C	//
#define   IODEBUG_OUTPUT2_13     0x0D	//
#define   IODEBUG_OUTPUT2_14     0x0E	//
#define   IODEBUG_OUTPUT2_15     0x0F	//

/**-------0x1C-----IO调试-输出3--- 0X01 Y30---0X0F Y35--------**/
#define   IODEBUG_OUTPUT3_1      0x01	//
#define   IODEBUG_OUTPUT3_2      0x02	//
#define   IODEBUG_OUTPUT3_3      0x03	//
#define   IODEBUG_OUTPUT3_4      0x04	//
#define   IODEBUG_OUTPUT3_5      0x05	//
#define   IODEBUG_OUTPUT3_6      0x06	//

/**-------0x1D-----手动调试-----------------**/
#define	  AXIS_MANUL_SPEED		 0x01	//轴-手动速度值
#define	  AXIS_STEP_MM		     0x02	//轴-寸动距离 mm为单位

#define   XAXIS_MOVE_LEFT      0x03	//X轴-左移
#define   XAXIS_MOVE_RIGHT     0x04	//X轴-右移

#define   YAXIS_MOVE_LEFT      0x05	//Y轴-左移
#define   YAXIS_MOVE_RIGHT     0x06	//Y轴-右移

#define   ZAXIS_MOVE_LEFT      0x07	//Z轴-左移
#define   ZAXIS_MOVE_RIGHT     0x08	//Z轴-右移

#define   OAXIS_MOVE_LEFT      0x09	//O轴-左移
#define   OAXIS_MOVE_RIGHT     0x0A	//O轴-右移

#define   MANUL_FINE_ADJUST		0x0B	//微调命令

#define   POINT_SAVE           0x10	//点保存
#define   DELETE_ONEPOINT      0x11	//存储点管理中删除一个点信息
#define   MODIFY_ONEAXSIS      0x12	//存储点管理中修改一个点中的一个轴坐标
#define   RENAME_ONEPOINT      0x13	//存储点管理中修改一个点的名称

#define   DELETE_ALLPOINT  		 0x20	//删除所有点


/**-------0x1E-----参数命令-----------------**/
#define	  PARAMETER_SOFT_LIMIT		   			0x01	//软限位
#define   PARAMETER_SAFE_AREA        			0x02	//安全区
#define   PARAMETER_FUCTION_SET      			0x03	//功能参数
#define   PARAMETER_IO_DETECT_SET    			0x04	//输入参数
#define   PARAMETER_OUTPUT_SET       			0x05	//输出IO复位选择
#define   PARAMETER_INPUT_SWITCH_SET 			0x06	//输入复用开关
#define   PARAMETER_OUTPUT_SWITCH_SET           0x07	//输出复用开关
#define   PARAMETER_MD_PARA   					0x08	//码垛参数
#define   PARAMETER_MD_POINT      				0x09	//码垛点参数
#define   PARAMETER_MD_DELETE      				0x0A	//码垛参数-恢复出厂

#define   ALARMHISTORY_CLEAR		0x07	//历史报警清除

#define   JOG_MOVE_MODE          	0x01	//寸动模式
#define   LINK_MOVE_MODE         	0x02	//连动模式

#define   X_AXIS     0x00
#define   L_AXIS     0x01
#define   Z_AXIS     0x02
#define   O_AXIS     0x03
#define   NO_AXIS    0x04
#define   POINT_NAME	0x05	  					//用在存储点管理，选中的是一个点的名字而不是轴坐标

#define   POINT_PAGE1		0x00
#define   POINT_PAGE2		0x01
#define   POINT_PAGE3		0x02

#define SAVEPROGRAMNUM  				20	 					//存储程序的数目上限
#define SAVEPROGRAMNUM_MAIN  			10						//存储主程序个数
#define SAVEPROGRAMNUM_SUB				10						//存储子程序个数
#define MAXSAVEPROINT 					40						//每个轴最多能保存的点

/**-------外部485通信控制机械手状态--------------**/
#define	EXTEND_RESET			0x01	//机械手复位
#define	EXTEND_ORIGIN			0x02	//回零
#define	EXTEND_RUN				0x03	//启动
#define	EXTEND_STOP				0x04	//停止
#define	EXTEND_PAUSE			0x05	//暂停

extern const QString g_AxiseCarteTypeString[3];

extern const QString Beyond_LastDay;
extern const QString Beyond_Forever;
extern const QString MachineNum_Err[3];
extern const QString Decrypt_ResDis[2];
extern const QString MachineNum_Setted[2];
extern const QString JurisType_Dis[3];

//////////////////////////////DGUS//////////////////////////////
#define ORDINARY_AUTHORITY  1	//普通权限
#define MANAGE_AUTHORITY  2	//管理员权限

//------------弹出菜单------------//
#define PW_1_PASSWORDERROR      0x10   //密码错误
#define PW_5_SOFTLIMITERROR     0x15   //软限位参数错误
#define PW_5_SAFEAREAERROE      0x02   //安全区参数错误(mod)
#define PW_1_HOMEFIRST          0x30   //请先回零
#define PW_1_CHOOSEPROGRAM      0x35   //请先选择运行程序
#define PW_1_STOPROBOT          0x50   //请先停止机械手
#define PW_5_UNLOCKCODEEROOR    0x65   //解锁密码错误
#define PW_6_HOMEFIRST1         0xB0   //报警历史-请先回零1
#define PW_5_PASSWORDERROR      0xB5   //固件更新密码错误
#define PW_6_HOMEFIRST2         0xC0   //报警历史-请先回零2
#define PW_4_HOMEFIRST          0xD0   //系统设置-请先回零

//IIC地址表
#define IIC_Ordinary_Password								0x0000									//普通权限密码
#define IIC_Adminastration_Password							(IIC_Ordinary_Password+4)				//管理员权限密码
#define IIC_BG_Time											(IIC_Adminastration_Password+4)			//背光时间
#define IIC_STARTUP_PASSWORD_flag							(IIC_BG_Time+4)							//开机密码显示

//真实时间和设定时间的时间差
#define	IIC_RealTimeCount									0x00A0

//加解密权限个数
#define UnLock_Jurisd_Num									3

//加密锁初始时间地址及标志
#define IIC_InitDataFlag									0x0100									//加密锁初始时间设置标志地址

//加密锁永久解密标志地址
#define IIC_UnLock_Forever_flag_1							0x010A									//开发者解密锁永久标志位
#define IIC_UnLock_Forever_flag_2							0x010B									//代理商解密锁永久标志位
#define IIC_UnLock_Forever_flag_3							0x010C									//机器厂家解密锁永久标志位

//加密锁起始时间、结束时间存放地址
#define IIC_UnLock_EndTime_1								0x0114									//开发者解密锁结束时间
#define IIC_UnLock_EndTime_2								0x011C									//代理商解密锁结束时间
#define IIC_UnLock_EndTime_3								0x0124									//机器厂家解密锁结束时间

//加密锁上次时间存放地址
#define IIC_UnLock_LastTime									0x0130									//上次开机时间

//加密锁机器编码已设置标志存放地址
#define IIC_UnLock_Seted_1									0x0140									//开发者解密锁已设置标志
#define IIC_UnLock_Seted_2									0x0141									//代理商解密锁已设置标志
#define IIC_UnLock_Seted_3									0x0142									//机器厂家解密锁已设置标志

//加密锁机器编码存放地址
#define IIC_UnLock_MacCode_1								0x0150									//开发者解密锁机器编码
#define IIC_UnLock_MacCode_2								0x0154									//代理商解密锁机器编码
#define IIC_UnLock_MacCode_3								0x0158									//机器厂家解密锁机器编码

#define IIC_AlarmHistory									0x0200									//报警历史记录

extern const QString Authority_Change[2];

extern const QString Admin_Authority_Dis[2];

extern const QString USBH_And_Control[2];
extern const QString USBH_CopyStatus_String[21];
extern const QString USB_Update_Choice[4];
extern const QString USB_UpdateStatus_String[8];


//////////////////////////////SystemSetting//////////////////////////////
//轴个数
#define AXIS_NUM	4
//轴选择
#define FAN_X     	0
#define FAN_Z     	1
#define FAN_Y     	2
#define FAN_O     	3
#define FAN_X_Y     4
#define FAN_X_Z     5
#define FAN_X_O     6
#define FAN_X_Z_L   7
#define FAN_X_Z_L_O 8
//回原点方式
#define FOM_X     	0
#define FOM_Z     	1
#define FOM_Y     	2
#define FOM_O     	3
#define FOM_Y_X     4
#define FOM_X_Y     5
#define FOM_Z_X     6
#define FOM_X_Z     7
#define FOM_O_X     8
#define FOM_Z_X_L   9
#define FOM_Z_L_X   10
#define FOM_Z_L_X_O 11
#define FOM_Z_X_L_O 12
#define FOM_L_O_Z_X 13
#define FOM_Z_O_X_L 14
#define FOM_O_Z_X_L 15
#define FOM_X_Z_L_O 16

//加速度类型 S/T
#define FAN_S       0
#define FAN_T       1

//伺服报警信号类型 常闭/常开
#define FAN_B       0
#define FAN_K       1

//原点方向
#define OR_LEFT     0
#define OR_RIGHT    1

//输入输出个数
#define	OUTPUT_NUM	30
#define	INPUT_NUM	30
#define PROGRAM_STRING_OUTPUT_SET_OFFSET        20
#define PROGRAM_STRING_OUTPUT_RESET_OFFSET      21
#define PROGRAM_STRING_REGOUTPUT_SET_OFFSET     12
#define PROGRAM_STRING_REGOUTPUT_RESET_OFFSET	13
#define PROGRAM_STRING_INPUT_OFFSET             72
#define ALARM_STRING_INPUT_OFFSET               24

//U盘拷贝程序
#define USBTOCONTROLER 0	  //U盘到控制器
#define CONTROLERTOUSB 1	  //控制器到U盘
#define USBWAIT        2	  //等待状态

#define USBHSTATUS_NOUDISK 		   		0
#define USBHSTATUS_UDISKATTACHED   	    2
#define USBHSTATUS_FINISHEDCOPY         3
#define USBHSTATUS_FAILEDCOPY           4
#define USBHSTATUS_UDISKPULLOUT         5
#define USBHSTATUS_UDISKERROR           6
#define USBHSTATUS_UDISKWIRTEPRO        7
#define USBHSTATUS_UDISKNOFILES         8
#define USBHSTATUS_UDISKFAMMAT          9
#define USBHSTATUS_PROGRAMDOWNLOAD      10
#define USBHSTATUS_FILEREAD 	   		11
#define USBHSTATUS_MAINPROGRAMCOPY_ERR	12
#define USBHSTATUS_SUBPROGRAMCOPY_ERR	13
#define USBHSTATUS_FILE_SEARCH			14
#define USBHSTATUS_OPEN_DIR_ERR			15
#define USBHSTATUS_OPEN_FILE_ERR		16
#define USBHSTATUS_READ_FILE_ERR		17
#define USBHSTATUS_FILE_OPENING 	   	18
#define USBHSTATUS_ParameterCOPING 	   	19
#define USBHSTATUS_PARAFINISHED 	   	20


#define Handset     2    //手持器
#define Controller  3    //控制器

#define USBSTATUS_NOUDISK         0
#define USBSTATUS_UDISKATTACHED   1
#define USBSTATUS_UDISKPULLOUT    2
#define USBSTATUS_UDISKERROR      3
#define USBSTATUS_UDISKWIRTEPRO   4
#define USBSTATUS_UDISKNOFILES    5
#define USBSTATUS_UDISKFAMMAT     6

#define OUTPUT_ASSOCIATE_NUM      2					//输出关联组

//复位选择
#define NotSel				  			0x00	   	//未选择
#define Before_Origin				  	0x01	   	//回零前
#define After_Origin				  	0x02	   	//回零后
#define Common_Alarm				  	0x03	   	//普通报警
#define Emerge_Alarm				  	0x04	   	//急停报警
#define PAUSE				  		    0x05	   	//暂停
#define STOP				  		    0x06	   	//停止

#define Input_Special         			18          //特殊输入口从X18开始

//夹爪个数
#define MDgrip_Num	      				6

//用户个数
#define USER_NUM		8
//用户变量分类
#define USER_Name  		1
#define USER_Init  		2
#define USER_Curr  		3
#define USER_Elec  		4
#define USER_Start 		5

typedef struct
{
    u16 year;	//年
    u8 month;	//月
    u8 day;		//日
    u8 hour;	//时
    u8 minute;  //分
    u8 sec;		//秒
    u8 week;	//周
} DateTable;

typedef struct
{
    u32 Left_Limit  ; //-
    u32 Right_Limit ; //+
    u8  Switch_Limit; //开关
} SoftLimit;

typedef struct
{
    u32 X_Left;
    u32 Z_Left;
    u32 X_Right;
    u32 Z_Right;
    u8  SafeArea_Switch;
} SafeArea;

typedef struct
{
    u16 Time[AXIS_NUM];
} ACC;

typedef struct
{
    u32 MaxDistance;						//X轴和O轴最大距离
    u32 MinDistance;						//X轴和O轴最小安全距离
} SoftDistance;//安全行程

typedef struct
{
    u8 carCoordSwitch;						//笛卡尔坐标开关 0关 1开
    u8 MDCoordType;							//机器类型 0桁架 1立柱 2SCARA
    u32 pitchLength;						//丝杆螺距
    u32 length[2];							//机械臂1、2长度
    u16 maxSpeed;							//笛卡尔坐标系的最大速度
    u16 accTime;							//笛卡尔坐标系的加速时间
    u16 accAcc;								//笛卡尔坐标系的加加速
    u8 axisType[AXIS_NUM];                  //轴类型 0直线轴 1旋转轴
    u8 axisBackMinDir[AXIS_NUM];            //轴回最小位置的方向 0顺时针 1逆时针
    u8 axisInterpFlag[AXIS_NUM];            //轴插补开关 0关 1开
} ST_Cartesian; //笛卡尔坐标系

typedef struct
{
    u8  Axis ;
    u8  Origin ;
    ACC Accelerate ;
    u8  SpeedLevel;
    u8  Outport_Pause;
    u8  Outport_Run;
    u8  Outport_Orign;
    u8  Outport_Stop;
    u8  AlarmSignal;
    u8  LCcirculation;							//料仓循环方式-参数暂时留存
    u32 OriginOffset[AXIS_NUM];
    u8  OriginDiretion[AXIS_NUM];
    u8  OriginSpeed[AXIS_NUM];
    u8  OriginPosition[AXIS_NUM];
    u8 	Alarm_Axis;
    u8 	Alarm_Switch[AXIS_NUM];
    u8  MDgripSwitch;                           //码垛夹爪IO开关
    u8  MDgripNum;                              //码垛夹爪IO序号
    u8  MDgripPort[MDgrip_Num];                 //码垛夹爪IO端口
    u32 A_Circle_Pulse[AXIS_NUM];               //单圈脉冲
    u32 A_Circle_Distance[AXIS_NUM];            //单圈距离
    u8  OutputAssociate[OUTPUT_ASSOCIATE_NUM];	//输出关联开关Y0Y1,Y2Y3
    u8  ZAxsisAvoidace;							//Z轴防撞
    u32 ZAxsisLimit;							//Z轴下限
    u8  AccAcc[AXIS_NUM];						//四轴的加加速度 10-200
    u16 JDZ_AllowError[AXIS_NUM];               //四周绝对值的动作确认
} JXSParameter;

typedef struct
{
    u32 Name1;
    u32 Name2;
    u32 Name3;
    u32 Name4;
    u32 Name5;
}NamePara;//拷贝文件名

typedef struct
{
    u32  Name;
    u32  Name1;
    u32  Name2;
} IONameParameter;

#define LOOP_MAX						10		//最多循环层数

#define MD_GOOD_NUM						60		//物品数量：15*4=60
#define MD_GOOD_PAGE_NUM				4
#define MD_GOOD_PAGE_PER				15

#define MD_POINT_NUM					64		//示教点：8*8=64
#define MD_POINT_PAGE_NUM				8
#define MD_POINT_PAGE_PER				8

#define PF_IONUM						4


typedef struct
{
    s32 point[AXIS_NUM];		//码垛点
    s32 waitPoint[AXIS_NUM];	//等待点
} ST_MDPostion; //码垛位置

typedef struct
{
    u8 code;                                    //编号：1，2，3，...
    u32 name1;                                  //物品名称：只显示本页的名称
    u32 name2;                                  //物品名称：只显示本页的名称
    u32 name3;                                  //物品名称：只显示本页的名称
    u8 stackType;                               //垛型：0示教、1矩形、2品字形、3横向缩、4纵向缩
    u8 property;                                //属性：0：码垛，1：拆垛
    u8 revolveMode;                             //旋转方式:0:电机，1：气缸
    u8 gasPort;                                 //气缸端口
    u8 topSwitch;                               //顶层功能
    s32 goodOffset[AXIS_NUM];                   //物料偏移——笛卡尔坐标系
    s32 goodheight;                             //物品高度
    u8 stackLayer;                              //堆叠层数
    u8 loopLayer;                               //循环层数：最多LOOP_MAX层，顶层功能开启时，最后一层为顶层
    u8 cycleStartLayer;                         //循环起始层数
    u8 teachLayer;                              //示教第几层
    u8 layerNum[LOOP_MAX];                      //本层个数
    u8 horNum;                                  //横向个数
    u8 verNum;                                  //纵向个数
    ST_MDPostion sPostion[MD_POINT_PAGE_PER];	//只显示本页的点
} ST_MDParameter; //码垛参数

typedef struct
{
    u8 mdMethed;					//码垛方式:0:连续，1：分拣
    u8 totalGood;					//总物品数
    u8 startGood;					//起始物品
    u8 curGood;						//当前物品
    u8 curLayer;					//当前层数
    u8 curNum;						//当前个数
    IONameParameter startName;		//起始物品-名称（仅用来显示）
    IONameParameter curName;		//当前物品-名称（仅用来显示）
} ST_MDRunPara; //码垛运行参数


typedef struct
{
    u8	pfIOnum[PF_IONUM];					//配方端口
    u8	pfGood[PF_IONUM];					//配方物品
    u8	pfSwitch[PF_IONUM];					//配方开关
} PFParameter; //配方参数


typedef struct
{
    u32  RW_Num ;	//任务计划
    u32  SC_Num ;	//生产
    u32  CJ_Num ;	//抽检
    u32  JG_Num ;	//间隔
    u32  LJ_Num ;	//累计
    u32	 NG_Num;	//NG数量
} SCParameter; //生产


typedef struct
{
    u32  USER_Name1[USER_NUM] ;
    u32  USER_Name2[USER_NUM] ;
    u32  USER_Name3[USER_NUM] ;
    s32  INIT_Num[USER_NUM] ;		//初始值
    s32  CURR_Num[USER_NUM] ;		//当前值
    u8   ELEC_RESET[USER_NUM] ;	 	//开机置0
    u8   START_RESET[USER_NUM] ; 	//启动置0
}USERParameter; //用户变量

typedef struct
{
    u8   Switch;
    u16  minTime;
    u16  maxTime;
} InputIOParameter;

typedef struct
{
    u8   BeforeOrigin;
    u8   AfterOrigin;
    u8   CommonAlarm;
    u8   EmergeAlarm;
    u8   Pause;
    u8   Stop;
} IOResetSelect;

typedef struct
{
    u32  Code;
    u32  Code2;
    u32  Code3;
    u32  Position;
}PointCodeParameter;

typedef struct
{
    u8  Switch;						//功能开关
    u8  Server;						//伺服选择
    u8  PreSwitch;					//记录上一次功能开关
    u8  PreServer;					//伺服选择
    u8  Resolu; 					//分辨率
    u32 Circle_Pluse[AXIS_NUM];		//单圈脉冲
    u8  Motion_Dir[AXIS_NUM];		//运动方向
    u8  OriginSetting[AXIS_NUM] ;	//绝对值原点设置
}JDZParameter;//绝对值参数设定

typedef struct
{
    u8   Switch;
    u8   Sequence[12];
} InternetParameter;

extern const QString SavePoint_Modify_String[5];

extern const QString Output_Reset_Select_String[6];

extern const QString  Buzzer_Switch_On;                       //蜂鸣器：开
extern const QString  Buzzer_Switch_Off;                      //蜂鸣器：关
extern const QString  gs_Pass_Word_String;                //显示的隐藏字符
extern const QString  SoftLimit_On;                           //X轴限位：开
extern const QString  SoftLimit_Off;                          //X轴限位：关
extern const QString  X_SafeArea_On;                        //X轴安全区：启用
extern const QString  X_SafeArea_Off;                       //X轴安全区：关闭
extern const QString  StartUp_Password_Switch[2];
extern const QString  Edition;                         //版本号

extern const QString FucSet_Axis[9];

extern const QString FucSet_Origin[17];

extern const QString FucSet_Acc_Axis[AXIS_NUM];

extern const QString Outport_Switch[5];

extern const QString Origin_Position[2];

extern const QString Origin_Direction[2];

extern const QString Alarm_Signal_Dis[2];

extern const QString Alarm_Switch_Dis[2];

extern const QString InputIO_Detect_IO[INPUT_NUM];

extern const QString OutputIO_Detect_IO[OUTPUT_NUM];

extern const QString IO_Detect_Switch[2];

extern const QString LC_Circulation_Mode[3];

extern const QString Function_switch[2];

extern const QString Servo_selection[16];

extern const QString Encoder_resolution[4];

extern const QString Move_Direction[2];

extern const QString JDZ_Axis[AXIS_NUM+1];

extern const QString MD_gripSwitch[2];

extern const QString MD_gripNum[MDgrip_Num];

extern const QString MD_InvalidGrip;
extern const QString MD_InvalidGrip2;

extern const QString JDZ_OriginSetting_Dis[3];
extern const QString ELECRESET_Switch[2];
extern const QString STARTRESET_Switch[2];

extern const QString ZAxis_Avoidance[2];
extern const QString CarCoord_Switch[2];
extern const QString AXISType_Switch[2];
extern const QString MD_CoordType[4];
extern const QString MD_axisBackMinDir[2];
extern const QString PF_Switch[2];

extern const QString MD_Methed_String[2];
extern const QString StackType_String[5];
extern const QString Property_String[2];
extern const QString RevolveMode_String[2];
extern const QString MD_goodOffset[2];

//码垛参数拷贝提示
extern const QString MDPARA_COPY_String[2];

//////////////////////////////StartUp//////////////////////////////
#define AUTO_WAITE					0
#define AUTO_RUNNING				1
#define AUTO_PAUSE					2
#define AUTO_ERROR					3

extern const QString BlankNon;

//////////////////////////////FreeProgramme//////////////////////////////
#define LARGESTPROGRAMNUM 200							//编程最多指令数
//主要指令--order------//
#define   OR_BASICORDER      	  0x01  	//基本指令
#define   OR_AXISORDER       	  0x02  	//轴控指令
#define   OR_IOORDER         	  0x03  	//IO指令

//子命令---key------//
#define   K_PROGRAMSTART          0x01	 	//主程序开始
#define   K_PROGRAMEND            0x02	 	//主程序结束
#define   K_DELAY                 0x03	 	//延时
#define   K_SUBPROGRAM	          0x04  	//子程序
#define   K_JUMP          		  0x05  	//跳转指令
#define   K_WHILE            	  0x06  	//While指令
#define   K_CYCLEOVER          	  0x07  	//循环结束
#define   K_IF                    0x08  	//执行IF语句
#define   K_ELSE                  0x09  	//执行ELSE语句
#define   K_OVER                  0x0A 		//执行ELSE语句
#define   K_SPECIAL               0x0B 		//执行特殊指令
#define   K_OUTDETECT             0x0C	    //输出检测
#define   K_PULSE_OUTPUT          0x67	    //脉宽输出
#define   K_USER                  0x68	    //用户变量

#define   K_AXIS_RUNNING          0x0D	 	//正向搜索
#define   K_MDPOSITION         	  0x0E	 	//码垛位置
#define   K_MDCOUNT		          0x0F	 	//码垛计数
#define   K_XAXIS                 0x10	 	//X轴
#define   K_LAXIS                 0x11	 	//L轴
#define   K_ZAXIS                 0x12	 	//Z轴
#define   K_OAXIS                 0x13	 	//O轴
#define   K_INCREMENT_RUNNING     0x66	 	//102增量运动
#define   K_NEGTIVE_SEARCH        0x69	 	//105反向搜索
#define   K_MACHINE_ORIGIN        0x6A	 	//106机械回零
#define   K_POSSET				  0x6B	 	//107位置设置
#define		K_SLOWPOINT			  0x6C		//108减速点
#define		K_INTER_START		  0x6D		//109插补开始
#define		K_INTER_OVER		  0x6E		//110插补结束
#define		K_ADVENCE			  0x6F		//111插补速度-改为提前动作
#define		K_INTER_LINE		  0x70		//112直线插补
#define		K_POINT_ARC			  0x71		//113三点圆弧
#define		K_ANGLE_ARC			  0x72		//114圆心角圆弧
#define		K_AXISMOVE			  0x73		//109轴移动


//输出指令
#define   K_IOINSTRUCT_OUTPUT1     0x14	//输出指令1-Y0
#define   K_IOINSTRUCT_OUTPUT2     0x15	//输出指令2-Y1
#define   K_IOINSTRUCT_OUTPUT3     0x16	//输出指令3-Y2
#define   K_IOINSTRUCT_OUTPUT4     0x17	//输出指令4-Y3
#define   K_IOINSTRUCT_OUTPUT5     0x18	//输出指令5-Y4
#define   K_IOINSTRUCT_OUTPUT6     0x19	//输出指令6-Y5
#define   K_IOINSTRUCT_OUTPUT7     0x1A	//输出指令7-Y6
#define   K_IOINSTRUCT_OUTPUT8     0x1B	//输出指令8-Y7
#define   K_IOINSTRUCT_OUTPUT9     0x1C	//输出指令9-Y8
#define   K_IOINSTRUCT_OUTPUT10    0x1D	//输出指令10-Y9
#define   K_IOINSTRUCT_OUTPUT11    0x1E	//输出指令11-Y10
#define   K_IOINSTRUCT_OUTPUT12    0x1F	//输出指令12-Y11
#define   K_IOINSTRUCT_OUTPUT13    0x20	//输出指令13-Y12
#define   K_IOINSTRUCT_OUTPUT14    0x21	//输出指令14-Y13
#define   K_IOINSTRUCT_OUTPUT15    0x22	//输出指令15-Y14
#define   K_IOINSTRUCT_OUTPUT16    0x23	//输出指令16-Y15
#define   K_IOINSTRUCT_OUTPUT17    0x24	//输出指令17-Y16
#define   K_IOINSTRUCT_OUTPUT18    0x25	//输出指令18-Y17
#define   K_IOINSTRUCT_OUTPUT19    0x26	//输出指令19-Y18
#define   K_IOINSTRUCT_OUTPUT20    0x27	//输出指令20-Y19
#define   K_IOINSTRUCT_OUTPUT21    0x28	//输出指令21-Y20
#define   K_IOINSTRUCT_OUTPUT22    0x29	//输出指令22-Y21
#define   K_IOINSTRUCT_OUTPUT23    0x2A	//输出指令23-Y22
#define   K_IOINSTRUCT_OUTPUT24    0x2B	//输出指令24-Y23
#define   K_IOINSTRUCT_OUTPUT25    0x2C	//输出指令25-Y24
#define   K_IOINSTRUCT_OUTPUT26    0x2D	//输出指令26-Y25
#define   K_IOINSTRUCT_OUTPUT27    0x2E	//输出指令27-Y26
#define   K_IOINSTRUCT_OUTPUT28    0x2F	//输出指令28-Y27
#define   K_IOINSTRUCT_OUTPUT29    0x30	//输出指令29-RY0
#define   K_IOINSTRUCT_OUTPUT30    0x31	//输出指令30-RY1

#define   K_IOINSTRUCT_INPUT0      0x48	//输入指令0
#define   K_IOINSTRUCT_INPUT1      0x49	//输入指令1
#define   K_IOINSTRUCT_INPUT2      0x4A	//输入指令2
#define   K_IOINSTRUCT_INPUT3      0x4B	//输入指令3
#define   K_IOINSTRUCT_INPUT4      0x4C	//输入指令4
#define   K_IOINSTRUCT_INPUT5      0x4D	//输入指令5
#define   K_IOINSTRUCT_INPUT6      0x4E	//输入指令6
#define   K_IOINSTRUCT_INPUT7      0x4F	//输入指令7
#define   K_IOINSTRUCT_INPUT8      0x50 //输入指令8
#define   K_IOINSTRUCT_INPUT9      0x51	//输入指令9
#define   K_IOINSTRUCT_INPUT10     0x52	//输入指令10
#define   K_IOINSTRUCT_INPUT11     0x53	//输入指令11
#define   K_IOINSTRUCT_INPUT12     0x54	//输入指令12
#define   K_IOINSTRUCT_INPUT13     0x55	//输入指令13
#define   K_IOINSTRUCT_INPUT14     0x56	//输入指令14
#define   K_IOINSTRUCT_INPUT15     0x57	//输入指令15
#define   K_IOINSTRUCT_INPUT16     0x58	//输入指令16
#define   K_IOINSTRUCT_INPUT17     0x59	//输入指令17
#define   K_IOINSTRUCT_INPUT18     0x5A	//输入指令18
#define   K_IOINSTRUCT_INPUT19     0x5B	//输入指令19
#define   K_IOINSTRUCT_INPUT20     0x5C	//输入指令20
#define   K_IOINSTRUCT_INPUT21     0x5D	//输入指令21
#define   K_IOINSTRUCT_INPUT22     0x5E	//输入指令22
#define   K_IOINSTRUCT_INPUT23     0x5F	//输入指令23
#define   K_IOINSTRUCT_INPUT24     0x60	//输入指令24
#define   K_IOINSTRUCT_INPUT25     0x61	//输入指令25
#define   K_IOINSTRUCT_INPUT26     0x62	//输入指令26
#define   K_IOINSTRUCT_INPUT27     0x63	//输入指令27
#define   K_IOINSTRUCT_INPUT28     0x64	//输入指令28
#define   K_IOINSTRUCT_INPUT29     0x65	//输入指令29

//value值
#define V_BLANK						0X00	//0空白行
#define V_IOPOSITION				0X01	//1IO口
#define V_IOSTATUS					0X02	//2IO状态
#define V_NUM_TO_CYCLE              0X03	//3循环次数
#define V_Z_POSITION				0X04	//4Z轴坐标
#define V_DELAY_TIME				0X05	//5延时时间
#define V_POSITION					0X06	//6移动坐标
#define V_SPEED						0X07	//7速度
#define V_ONCE						0X08	//8单次
#define V_CYCLE						0X09	//9循环
#define V_O_METHOD					0X0A	//10-O方式
#define V_X_POSITION				0X0B	//11X轴坐标
#define V_Y_POSITION				0X0C	//12Y轴坐标
#define V_MORETHAN_E				0X0D	//13大于等于
#define V_LESSTHAN_E				0X0E	//14小于等于
#define V_DETECT_TIME				0X0F	//15检测时间
#define V_PROGRAM_START             0X10	//16程序开始
#define V_PROGRAM_END				0X11	//17程序结束
#define V_ONCE_RUN					0X12	//18单次执行
#define V_aPOSITION					0X13	//19
#define V_ONLY_EQUAL				0X14	//20只等于
#define V_EQUAL						0X15	//21等于（倍数）
#define V_NOT_EQUAL					0X16	//22不等于
#define V_NOTONLY_EQUAL             0X17	//23不等于（倍数）
#define V_R_METHOD					0X18	//24R方式
#define V_I_METHOD					0X19	//25I方式
#define V_R_LINE_NUM_IO             0X1A	//26R行号/IO口
#define V_R_NUM						0X1B	//27R数量/H&L
#define V_RI_NULL					0X1C	//28NULL
#define V_MD_AXSIS					0X1D	//29-36 码垛轴选择
#define V_SUBPROGRAM_SEQ            0X25	//37子程序编号
#define V_JUMP_TO					0X26	//38跳转到的行数
#define V_HIGH_STATUS				0X27	//39高电平
#define V_LOW_STATUS				0X28	//40低电平
#define V_RISING_EDGE				0X29	//41上升沿
#define V_FALLING_EDGE              0X2A	//42下降沿
#define V_XAXIS						0X2B	//43X轴
#define V_YAXIS						0X2C	//44Y轴
#define V_ZAXIS						0X2D	//45Z轴
#define V_OAXIS						0X2E	//46O轴
#define V_SUSPEND					0X2F	//特殊指令-暂停
#define V_STOP						0X30	//特殊指令停止
#define V_COUNTER					0X31	//R方式-计数器
#define V_JUMP_LABEL				0X32	//标签
#define V_LABEL_NUM                 0X33	//标签号
#define V_DISTANCE   				0X34	//52增量位移
#define V_USEFUL					0X35	//53有效
#define V_USELESS    				0X36	//54无效
#define V_OUT_NUM    				0X37	//55输出口
#define V_SET						0X38	//56置位
#define V_RESET                     0X39	//57复位
#define V_USER1                     0X3A	//58user1
#define V_USER2                     0X3B	//59user2
#define V_USER3                     0X3C	//60user3
#define V_USER4                     0X3D	//61user4
#define V_USER5                     0X3E	//62user5
#define V_USER6                     0X3F	//63user6
#define V_USER7                     0X40	//64user7
#define V_USER8                     0X41	//65user8
#define V_ADD                       0X42	//66 +
#define V_MINUS                     0X43	//67 -
#define V_UEQUAL					0X44	//68 =
#define V_MULTIP                    0X45	//69 *
#define V_DIVIDE    				0X46	//70 /
#define V_EXCESS    				0X47	//71 %
#define V_VALUE_SET  				0X48	//72坐标设置
#define V_SLOWPOS					0X49	//73减速点
#define V_AXIS1						0X4A	//74轴选择1
#define V_AXIS2						0X4B	//75轴选择2
#define V_AXIS3						0X4C	//76轴选择3
#define V_MAX_SPEED					0X4D	//77最大速度
#define V_TURN_SPEED				0X4E	//78拐点速度
#define V_TARGET_POINT              0X4F	//79目标点
#define V_MID_POINT					0X50	//80中间点
#define V_END_POINT					0X51	//81终点
#define V_CENTER					0X52	//82圆心
#define V_RADIUS					0X53	//83半径
#define V_ARC_LENGTH				0X54	//84弧长
#define V_MDGOOD					0X55	//85物品
#define V_NUMBER					0X56	//86个数
#define V_LAYER_NUM					0X57	//87层数
#define V_LAYER_FULL				0X58	//88层满
#define V_STACK_FULL				0X59	//89垛满
#define V_MORE_THAN					0X5A	//90大于
#define V_LESS_THAN					0X5B	//91小于
#define V_AUTO						0X5C	//92自动
#define V_P_METHOD					0X5D	//93P方式
#define V_AXISCHOOSE                0X5E	//94轴选择
#define V_SETPOSITION               0X5F	//95设置坐标值
#define V_XAXISGREATER              0X60	//96X轴大于等于
#define V_YAXISGREATER              0X61	//97Y轴大于等于
#define V_ZAXISGREATER              0X62	//98Z轴大于等于
#define V_OAXISGREATER              0X63	//99O轴大于等于
#define V_XAXISEQUAL                0X64	//100X轴等于
#define V_YAXISEQUAL                0X65	//101Y轴等于
#define V_ZAXISEQUAL                0X66	//102Z轴等于
#define V_OAXISEQUAL                0X67	//103O轴等于
#define V_XAXISLESS                 0X68	//104X轴小于等于
#define V_YAXISLESS                 0X69	//105Y轴小于等于
#define V_ZAXISLESS                 0X6A	//106Z轴小于等于
#define V_OAXISLESS                 0X6B	//107O轴小于等于
#define V_FORMULATION               0X6C	//108配方
#define V_ADVANCE					0X6D	//109提前确认量

//自由编程
typedef struct
{
    u8  Flag;  			//标志位
    u8  List;  			//程序编号
    u8  Order; 			//指令类型
    u8  Key;   			//子命令
    u32 Value1;			//参数1-坐标
    u32 Value2;			//参数2-速度+延时+IO检测
    s32 Value3;			//参数3-动作延时
} FreeProgram; //15Byte


extern const QString  ProgramCode_String[201];

extern const QString Md_DuoPanNum[4];//垛盘号
extern const QString Axsis_Choose_String[4];

extern u8 Program_String[116][20];
extern u8 Parameter_String[120][20];


//////////////////////////////ManualOperate//////////////////////////////
extern const QString SavePoint_Group_Choose_String[5]; //用在40页点保存

extern const QString FucSet_Point_Axis[AXIS_NUM];

//////////////////////////////AlarmHistory//////////////////////////////
typedef struct {
    u8  Flag;  //是否有错误
    u16 year;   //日期
    u8  month;  //时间
    u8  day;
    u8  week;
    u8  hour;
    u8  minute;
    u8  second;
    u8  Type;  //错误类型
} AlarmHistory;
//extern AlarmHistory Alarm_History_Display;

typedef struct {
    u8  Flag;
    u8  Day[10];
    u8  Time[8];
    u8  Value;
    u8  Type;  //错误类型
} AlarmHistoryDisplay;

extern const QString Auto_Status_String[4];

union Conefficient{  //轴步长系数
                       float Step_Coefficient;
                       char Coefficient[4];
                  };

//点存储
typedef struct
{
    u8  Flag;			//是否有点
    u32 Name;		  //点的名称
    u32 Name2;
    u32 Name3;
    u32 Point[4];
}SavePoint;

//程序信息存储
typedef struct
{
    u8  Flag;	   		//是否有程序
    u8  Code;	   		//程序的编号，下发给主控制板是识别用
    u32 Name;	   		//N
    u32 Name2;
    u32 Name3;
    u8  Num;	   		//S:Scale保存程序的规模大小，用于运行时显示判断
    u16 Address;   	//IIC的存储地址
}SaveProgramInf;  //7

//程序存储
typedef struct
{
    u8  Flag;	   //是否有程序
    u8  Code;	   //程序的编号，下发给主控制板是识别用
    u32 Name;	   //N
    u32 Name2;
    u32 Name3;
    u8  Num;	   //S:Scale保存程序的规模大小，用于运行时显示判断
  FreeProgram	Program[LARGESTPROGRAMNUM];
}SaveProgram;	  //7+1500

extern u8 Alarm_String[80][50];

//////////////////////////////MD//////////////////////////////
#define SCARA_PI                    (3.1415926f)            //定义Π的rad值
#define SCARA_JOINT_NUM             4						//Scara关节个数

//关节角度
typedef struct
{
    double theta[SCARA_JOINT_NUM];	//4个旋转轴的角度
                                    //theta[0]是关节1转过的角度，一般为关节电机
                                    //theta[1]是关节2转过的角度，一般为关节电机
                                    //theta[2]是关节3转过的角度，一般为垂直方向的丝杆
                                    //theta[3]是关节4转过的角度，一般为顶端的关节电机
}ST_SCARA_JOINT_ANGLE;

//关节位置
typedef struct
{
    double x;											//x和y为平面坐标系中的位置
    double y;
    double z;											//z是垂直方向的下降高度
    double c;											//末端与平面坐标系X轴的夹角
}ST_SCARA_JOINT_POS;

#endif // PARADEF_H
