#include "parasum.h"

//RunPage
u32 Global::Program_RunTime = 0;				//程序单次运行时间
u8  Global::Landing_Success = FALSE;		 //密码登陆标识位
u8  Global::PassWord_Input_Done = FALSE;
u32 Global::Pass_Word_Temp = 0;		         //输入的密码缓存
u8  Global::Package_Adj = 0;
u8  Global::Package_Point = 0;
u8  Global::Restore_setting = FALSE;
u8  Global::Change_User_Start = FALSE;
u8  Global::Change_User_Password = 0;	//修改用户权限密码，=0时修改普通权限密码，=1时修改管理员权限密码
u8  Global::gs_Run_Program_Num = 0;				                   	//当前选择运行程序的编号
u8  Global::g_Auto_Status = AUTO_WAITE;
s32 Global::gs_Run_PosValue[11] = {0};								//暂存当前坐标值
u8  Global::m_PF_Refresh = FALSE;									//配方参数刷新
u8  Global::ProgramSelect_PointNum[11] = {0};                        //轴移动指令中选择的点位编号 用于开机界面指令显示点位名称
u8  Global::g_Run_ProFirstLineNum = 0;          		            //开机页程序显示第一行行数

//TeachPage
u8  Global::gs_Current_Dispaly_Code[11] = {0};	    //当前显示的8个编码 !
u8  Global::gs_Current_Dispaly_Point[11] = {0};	    //当前显示的轴命令的点编号
u32 Global::gs_Code_Parameter_Display[11][3]= {0}; //编码命令对应的两位参数及显示 !
u8  Global::gs_IO_Instructions_Display_Refresh = FALSE;
u8  Global::SubProgram_Sequence = 0;//当前保存的子程序序号 !
u8  Global::BlankChar[12] = {0};
u8  Global::BlankChar48[48] = {0};     // !
u8  Global::gs_Current_Dispaly_List[11] = {0}; 						//当前显示的8条指令
u8  Global::gs_Current_Operate_List = 1;	         					//当前蓝色背景所在的指令编号
u8  Global::gs_Current_Program_Firstline = 0;                        //显示框第一条指令的行数
u8  Global::g_Refresh_Dispaly_List_Flag = FALSE;	 					//刷新程序显示列表
u8  Global::gs_Parameter_Unset = FALSE;			 					//程序参数未设置 !
FreeProgram Global::Program_Buffer = {};                           //用于缓存修改 添加是的程序指令参数
u8  Global::Program_StringSplic[16] = {0};
u8  Global::Parameter_Value[10] = {0};
s8  Global::Parameter_ValueS[10] = {0}; //有符号 !
u8  Global::g_Current_Program_Debug = FALSE;			 				//当前程序是否可以调试
u8  Global::g_Program_Is_Debuging = FALSE;			     			//程序调试中,所有按键失效
u8  Global::g_Link_Debug = FALSE;
u8  Global::g_USART1_SendProgram_Flag = FALSE;			 			//标志开始发送程序
u8  Global::g_Current_Program_Modify = FALSE; 			 			//修改
u8  Global::g_SubPro_Value_Flag = FALSE;						//子程序选择标志位 !
u8  Global::Number_SubProgram = 0;									//子程序序号 1-20 !
u8  Global::Number_JUMP = 0;										//跳转行号 !
u8  Global::Number_While = 0;										//循环次数 !
u8  Global::gs_Free_Point_Display_Refresh = FALSE; 					//坐标修改


//DebugPage
u8 Global::gs_IO_Name_Display_Refresh = FALSE;


//ManualPage
u32 Global::gs_Manul_Axis_Position[AXIS_NUM] = {0};     //轴位置
u8  Global::gs_Point_Display_Refresh_Step = 0;
u8  Global::gs_Save_Point_Num = 0;	           			//当前保存点的编号,比实际编号小1,可做数组下标 !
u8  Global::gs_Refresh_Speed_Para = TRUE;	     		//速度-步进刷新
u8  Global::g_Manul_Move_count = 0;	                    //左右移连动计数
u8  Global::g_Manul_Move_Flag = FALSE;                	//手动移动标志位，用于是否协议握手
u8  Global::g_Manul_Link_Flag = FALSE;                	//连动操作，主要标志蜂鸣器
u8  Global::Temp_Display_Data[12]= {0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20};
u8  Global::Temp_Display_Data1[12]= {0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20};
u8  Global::SavePoint_Group_Choose = 1;  	  //选中第一组---该变量是第40页的组界面切换时显示的下标索引 !
u8  Global::g_Current_Choose_Group = 1;	      //当前选择存储点的组别
u8  Global::g_Current_Choose_Point = 1;	      //当前选择点--存储点管理界面
u8  Global::g_Current_Choose_Axsis = 0;        //选中的是这个点的那个轴坐标
u8  Global::g_Pre_Choose_Group = 1;	      	  //当前选择存储点的组别
u8  Global::g_Pre_Choose_Point = 0;	          //先前选择点

//SetPage
u8                Global::gs_MDgripSetFlag = FALSE;	    			//码垛夹爪端口选择标志
SoftLimit         Global::Temp_Soft_Limit[AXIS_NUM]= {};   // !
SoftLimit         Global::Robot_SoftLimit[AXIS_NUM]= {};		//XZL软限位参数
SoftDistance      Global::Robot_SoftDistance= {};
SoftDistance      Global::Temp_SoftDistance= {};
u8                Global::gs_Pre_Choose_Area = 0;             		//先前选择区域
u8                Global::g_Current_Choose_Area = 0;          		//当前选择区域
u8                Global::gs_Reflash_Fuction_JXS = 0;	             	 			//机械手功能显示刷新
u8                Global::gs_Reflash_Fuction_SC = 0;	              				//生产功能显示刷新
u8                Global::gs_Reflash_Fuction_USER = 0;                             //生产功能显示刷新
u8                Global::gs_Reflash_Save_USER = 0;	              				//生产功能显示刷新
u8                Global::gs_Reflash_Fuction_JDZ = FALSE;	             	 	//机械手绝对值参数显示刷新  兼容绝对值
u8                Global::gs_Refresh_JDZOriginSetting_Text = FALSE;				//JDZ原点设置显示
u8                Global::JDZ_Machine_Ori_Axis_Num = 0 ;							//机械手回零：1-X 2-Z 3-Y 4-O
u8                Global::JDZ_Origin_Resetting_Axis_Num = 0;						//重置原点： 1-X 2-Z 3-Y 4-O
u8                Global::JDZ_Origin_Setting_Axis_Num = 0;							//原点设置： 1-X 2-Z 3-Y 4-O
u8                Global::Get_JDZ_Information = 0;	//区分获得那个JDZ信息	0X15:获取原点设置信息	0X16:获取原点重置信息	0X17:获取机械回零信息
u8                Global::gs_Refresh_MD_Circulation = FALSE;    	//码垛循环方式
u8                Global::Axis_Parameter_Select = 0;  				//原点参数轴选择刷新显示
JXSParameter      Global::JXS_Parameter = {};
JXSParameter      Global::Temp_JXS_Parameter = {};    // !
u8                Global::Temp_ACC_Axis = X_AXIS;   // !
SCParameter       Global::SC_Parameter = {};		               		//生产参数
USERParameter     Global::USER_Parameter = {};		               	//用户变量
USERParameter     Global::Temp_USER_Parameter = {};  // !
u8                Global::g_USART1_DeletePoint_Flag = FALSE;			 		//标志开始删除
u32               Global::Admin_Pass_Word = 0;
JDZParameter      Global::JDZ_Parameter = {};	//绝对值参数设定
JDZParameter      Global::Temp_JDZ_Parameter = {};					//绝对值参数设定
u8                Global::gs_Reflash_Fuction_Internet = FALSE;                  //物联网设定界面刷新
u8                Global::gs_Reflash_Internet_Switch = FALSE;                   //物联网功能开关刷新
InternetParameter Global::Internet_Parameter = {};              //物联网功能设置
IONameParameter   Global::sMD_Name[MD_GOOD_PAGE_PER] = {};        //码垛选择页面-名称显示
u8                Global::m_MD_Methed = 0;					//码垛方式：0：连续，1：分拣
u8                Global::m_MD_Good_Page = 1;				//物品选择当前页
u8                Global::m_MD_Point_Page = 1;				//示教点选则当前页
u8                Global::m_MD_Point_Code = 0;				//当前选择示教点编号：1，2，3，...
u8                Global::m_Choose_Good_Mode = 0;	   		//选取码垛物品标志：0：读参数，1：选取起始物品，2：选取当前物品，3：选取拷出物品参数
ST_MDParameter    Global::sMD_Parameter = {};  //码垛参数
ST_MDRunPara      Global::sMD_RunPara = {};		//码垛运行参数
u8                Global::m_Reflash_Name_MD = FALSE;		//码垛名称刷新
u8                Global::m_Reflash_Point_MD = FALSE;       //码垛点刷新
u8                Global::m_Reflash_Para_MD = FALSE;		//码垛参数刷新
u8                Global::m_Reflash_Run_MD = FALSE;         //码垛运行参数刷新
u8                Global::m_MD_TeachPoint_Flag = FALSE;     //码垛示教点标志
u8                Global::m_MD_GasPort_Flag = FALSE;		//气缸端口选择标志
u8                Global::m_GoodOffset_Refresh = FALSE;     //物料偏移刷新
PFParameter       Global::PF_Parameter = {};		//配方参数
u8                Global::Temp_PF_Ionum = 0;
u8                Global::m_MD_Copy_Code = 0;               //当前选择要拷贝的物品编号：1,2,3,...
//笛卡尔坐标系相关参数
ST_Cartesian      Global::sCartesian_Para = {};
u8                Global::m_Refresh_Cartesian = FALSE;      //坐标系参数刷新


IONameParameter Global::IO_Name_Parameter_Temp[OUTPUT_NUM] = {};
IONameParameter Global::IO_Name_Parameter[OUTPUT_NUM] = {};
IONameParameter Global::Temp_IO_Name_Parameter[OUTPUT_NUM] = {};
IOResetSelect Global::IO_Reset_Select[OUTPUT_NUM] = {};
IOResetSelect Global::Temp_IO_Reset_Select[OUTPUT_NUM] = {};
IONameParameter Global::IO_Name_Parameter_Input[INPUT_NUM] = {};
IONameParameter Global::Temp_IO_Name_Parameter_Input[INPUT_NUM] = {};
u8 Global::Temp_IO_Switch_Parameter[INPUT_NUM] = {0};
u8 Global::Temp_OUT_Switch_Parameter[OUTPUT_NUM] = {0};
u8 Global::gs_IO_Detect_Display_Refresh = 0;										//IO输入名刷新
u8 Global::gs_IO_Detect_Display_Refresh_Input = 0;

PointCodeParameter Global::Point_CodeParameter = {};
char Global::Temp_CopyFileName[17] = {0};
NamePara  Global::Copy_FileName = {};       						//文件名称
u8 Global::Current_Point_List = 0;
u32 Global::RealTimeCount = 0;
u8 Global::Set_LCPosition = 0;
SafeArea Global::Robot_Safe_Area[7] = {};
u8  Global::gs_Program_Display_Refresh = 0;
u8  Global::gs_Point_Display_Refresh = 0;
u8  Global::g_FucSet_Axis_Num = 0;
u8  Global::gs_Temp_Point_Display_Refresh = 0;
u8  Global::Temp_IO_Detect_Parameter = 0;							//当前选择的IO口号
InputIOParameter Global::IO_Parameter[INPUT_NUM] = {};              //输入口参数保存
InputIOParameter Global::Temp_IO_Parameter[INPUT_NUM] = {};         //修改的输入口参数
s32 Global::Modify_Point_Temp = 0;    								//修改存储点时输入的坐标值
s32 Global::Modify_MD_Point_Temp[AXIS_NUM] = {0};    		//修改存储点时输入的坐标值
u8 Global::gs_Point_Modify_Refresh = 0;    	//存储点修改弹框中的显示内容刷新

//AlarmPage
AlarmHistory        Global::Alarm_History_Time[20]= {};
AlarmHistoryDisplay Global::Alarm_History_Display[21]= {};
u8 Global::Cur_Alarm_Page = 0;      //报警页    !
u8 Global::gs_Robot_Error_Flag = 1; // !
u8 Global::g_Alarm_Buzzer = FALSE;
u8 Global::g_Alarm_Buzzer_Timer = TRUE;
u8 Global::g_Alarm_Buzzer_Count = 0;
u8 Global::g_Current_Alarm = 0;


//DGUS
/*----------------Start_Up--界面1操作标志位----------------*/
u8  Global::LCD_Main_Page = 0 ;                     //LCD当前主目录
s32 Global::LCD_Var_Data = 0;				        				//变量数据
s32 Global::LCD_Var_Data1 = 0;
s32 Global::LCD_Var_Data2 = 0;
u32 Global::Pass_Word[2] = {123456,111111};		      //开机密码:普通权限,管理员权限
u8 Global::Refresh_Admin_Flag = FALSE;
u8 Global::Admin_Authority = 0;
u8 Global::Robot_Admin_Authority = ORDINARY_AUTHORITY;
u8 Global::g_Robot_Enable_Flag = 0;	         						//使能
u8 Global::g_Emergency_Stop_Flag = 0;	     							//急停
u8 Global::g_Cycle_Run_Flag = 1;	 		 									//1:循环  0：单次
u8 Global::g_Robot_Restart_Flag = 0;										//重新启动标志位
u8 Global::g_Run_Program_Num = 0;			 									//当前运行的程序编号
u8 Global::g_Run_Program_Operater_List = 0;	 						//当前选择运行程序正在运行的指令条：由主控板返回
u8 Global::g_RunProgram_Refresh = FALSE;	 							//运行页面当前运行程序刷新
u8 Global::g_Run_Program_List_Num = 0;	     						//当前程序规模大小；
u8 Global::g_Reflash_Progress_Num = FALSE;	 						//刷新产量标志位
u8 Global::g_Reflash_Speed = FALSE;	 						     //刷新速度标志位
u8 Global::g_Robot_Auto_Reset = FALSE;
u8 Global::g_Robot_Auto_Reset_Scan = FALSE;
u8 Global::Axis_Position_Scan = FALSE;		 							//自动运行时，轴位置查询

/*----------------Free_Program--界面2操作标志位------------*/
u8 Global::g_Background_Color = 1;			      					//编辑背景色
u8 Global::g_Background_Color_Blink = FALSE;  					//背光闪烁标志位
u8 Global::g_Background_Blink_Delay = FALSE;  					//背景闪烁延时标志位
u8 Global::g_Background_Blink_Count = 0;  							//背景闪烁延时计数
u8 Global::g_Event_Done_Flag = FALSE;         					//当前事件是否处理-背光闪烁
u8 Global::g_SaveProgram_Flag = 0;            					//程序保存
u32 Global::Axis_Parameter_Speed = 50;        					//轴速度参数百分比
u32 Global::Delay_Parameter_Time = 0;		  							//延时时间参数
s32 Global::Distance_Parameter = 0;		        					//位移参数
s32 Global::User_Parameter = 0;		        					    //用户参数
u32 Global::Number_IOstatus_Input = 0; 									//R数量/IO状态参数
u32 Global::Number_IO_Input = 0;       									//行号/IO参数
u8 Global::g_Current_Paramter_Value = 0;		    				//设置参数1/2/3
u8 Global::g_Current_Paramter_Num = 0;		    					//参数设置行
u8 Global::g_Current_Paramter_Key = 0;		    					//参数设置指令编号
u8 Global::g_FreeProgram_Setting_XZ = FALSE;  					//自由编程X-Z轴设置参数标志位
u8 Global::gs_FreeProgram_Setting_XZ = FALSE;
u8 Global::g_SavePoint_Setting = FALSE;  								//存储点修改标志位
s32 Global::Coorinate_Parameter = 0;		        				//P方式坐标参数
u8 Global::g_FreeProgram_Axismove_Flag = FALSE;         //轴移动拾取坐标标志位

/*----------------IO_Control--界面3操作标志位--------------*/
u16 Global::g_Input1_Status  = 0;	 											//输入1状态
u16 Global::g_Input2_Status  = 0;	 											//输入2状态
u16 Global::g_Input3_Status  = 0;	 											//输入3状态
u16 Global::g_Output1_Status = 0;	 											//输出1状态
u16 Global::g_Output2_Status = 0;	 											//输出2状态
u16 Global::g_Output3_Status = 0;	 											//输出3状态
u8  Global::g_Output1Ack_Flag = FALSE;									//输入状态通信应答成功标志位
u8  Global::g_Output2Ack_Flag = FALSE;									//输入状态通信应答成功标志位
u8  Global::g_Output3Ack_Flag = FALSE;									//输入状态通信应答成功标志位

/*----------------Manul_Operate--界面4操作标志位------------*/
u8  Global::g_Current_Manul_Axis = NO_AXIS;			 				//手动微调时当前选择轴
u8  Global::g_Current_Manul_Axis_Refresh = 0;           			//手动微调时当前选择轴刷新
u16 Global::g_Manule_Pulse = 0 ;					 				//手动微调脉冲值
u16 Global::gs_Manule_Pulse = 0 ;					 				//手动微调脉冲值


/*----------------SystemSetting--界面5操作标志位------------*/
u8  Global::g_Buzzer_Switch_Flag = TRUE;
u32 Global::g_BackLight_Time = 360;		   								//背光时间
u32 Global::g_BackLight_Count=0;		   									//背光时间计数
u8  Global::g_BackLight_Dark = TRUE;
u8  Global::USBH_Process_Flag = FALSE;       						//U盘页面标志位
u8  Global::USBH_Direction = USBTOCONTROLER; 						//U盘和控制器拷贝方向
u8  Global::USBH_Dispaly_Fresh_Flag = FALSE;
u8  Global::USB_Dispaly_Fresh_Flag = FALSE;  						//U盘显示刷新标志位

u8 Global::USB_Update_Status = USBSTATUS_NOUDISK;    //---2018.5.28 U盘升级状态
u8 Global::USBH_Copy_Status = USBHSTATUS_NOUDISK;		 //U盘拷贝状态


//Parameter
volatile u8  Global::Robot_Status = ACTION_STOP;      //机械手状态
u8  Global::Robot_Auto_Mode = CYCLE_MODE;	 //机械手自动运行模式：循环-单次
u8  Global::Robot_Single_Mode = FALSE; 		 //单步模式使能
u8 	Global::Robot_Single_Mode_Pre = TRUE;

/*-----开机界面变量---StartUp-----*/
u8  Global::X_Axsis_Origin_Enable = FALSE;
u8  Global::Z_Axsis_Origin_Enable = FALSE;



u8  Global::Robot_Origining = FALSE;
u8  Global::Robot_Origined = FALSE;	   				//机械手回原点
u8  Global::Robot_Enable = FALSE;      				//机械手使能
u8  Global::Robot_Enable_Switch_On = FALSE;		//机械手使能钥匙开关
u8  Global::Robot_Enable_Pre_Switch = FALSE;

u8  Global::Program_Ready = FALSE;		     //程序准备OK
u8  Global::Data_Syc_Ready = FALSE;	       //是否读取开机程序
u8  Global::Setting_Syc_Ready = FALSE;	   //开机读取设定参数完成
u8  Global::Point_Syc_Ready = FALSE;	     //开机读取点完成
u8  Global::ProgramInf_Syc_Ready = FALSE;	 //开机读取程序信息参数完成
u8  Global::Program_Syc_Ready = FALSE;	   //开机读取程序完成
u8  Global::SoftLimit_Syc_Ready = FALSE;   //开机读取软限位完成
u8  Global::SafeArea_Syc_Ready = FALSE;    //开机读取安全区域完成
u8  Global::IODetect_Syc_Ready = FALSE;    //开机读取IO检测完成
u8  Global::OUTReset_Syc_Ready = FALSE;    //开机读取输出复位选择完成
u8  Global::MDNameDetect_Syc_Ready = FALSE;//开机读取码垛Name
u8  Global::MDPara_Syc_Ready = FALSE;			 //读取码垛参数
u8  Global::MDPoint_Syc_Ready = FALSE;			//读取码垛点
u8  Global::ParameterCopy_Ready = FALSE;	 	//读取拷贝参数完成
u8  Global::MDParaCopy_Ready = FALSE;	 			//码垛拷贝参数完成

u8  Global::DJParameter_Syc_Ready = FALSE; 						//开机读取导教参数完成 ---2019.8.3
u8  Global::Main_Init_Done = FALSE;		     						//主控板开机完成
s32 Global::g_Axis_Position[AXIS_NUM] = {};          //轴位置
s32 Global::g_Pre_Axis_Position[AXIS_NUM] = {};      //轴之前时刻的位置
u8  Global::g_AxiseCarteType = 0;			 								//轴坐标-笛卡尔坐标标志

u8 Global::gs_AxiseCarteType_Refresh = TRUE;	 //速度-步进刷新

union Conefficient Global::Axis_Step_Coefficient[AXIS_NUM];

u8 Global::StartUp_Password = FALSE;													//开机有密码标志位
u8 Global::StartUp_Password_Dis = 0;													//开机密码是否开启

u8 Global::g_Servo_Is_Run = FALSE;	  												//机械手正在运行标志位，用于自动和手动时查询机械手实时位置
u8 Global::g_Axis_Choose = NO_AXIS;
SavePoint Global::Manul_Save_Point[40]={};	  								//保存点的数组，Flag、Name、P-X，其中Flag表示是否有点保存
SaveProgram Global::Current_Operate_Program={};  						//当前操作的程序
SaveProgramInf Global::Free_Program_Save[SAVEPROGRAMNUM]={	  //保存程序的数组，Flag，Code，Num,其中Code表示序号，Num表示规模大小
    {0,1,0,0,0,0,0}, {0,2,0,0,0,0,0}, {0,3,0,0,0,0,0}, {0,4,0,0,0,0,0},
    {0,5,0,0,0,0,0}, {0,6,0,0,0,0,0}, {0,7,0,0,0,0,0}, {0,8,0,0,0,0,0},
    {0,9,0,0,0,0,0}, {0,10,0,0,0,0,0}, {0,11,0,0,0,0,0}, {0,12,0,0,0,0,0},
    {0,13,0,0,0,0,0}, {0,14,0,0,0,0,0}, {0,15,0,0,0,0,0}
};
SaveProgram Global::Free_Program_Operate = {};	  							//当前选中运行的程序
u8 Global::Robot_Error_Data[10] = {0};													//机械手报警信息记录
u8 Global::g_Robot_Error_Flag = FALSE;
u8 Global::Percentage_Value[4]={0};

u32 Global::DisplayDealTimeCounter = 30;												//防止操作过快引起的问题

//加密锁相关参数
u8  Global::CheckBatterySta = 0;																//电池拔出标志，1拔出，0没拔出
u8  Global::UnLock_RequestDecrypt = 0;

u8  Global::Axsis_Robot_Origined[AXIS_NUM] = {FALSE,FALSE,FALSE,FALSE};//各个轴回零完成标志位				绝对值优化20210304zcx

u8  Global::InitDataTimeFlag = 0xa4;														//加密锁初始时间标志开机默认需要初始化
u32 Global::InitDataTime = 460000000;														//加密锁初始时间，单位s
u8  Global::UnLock_Forever_flag[UnLock_Jurisd_Num] = {0};								//加密锁不同权限的长期有效标志位
u32 Global::CurSystemTime = 0;																	//当前读到的系统时间
u32 Global::UnLock_EndTime[UnLock_Jurisd_Num] = {0};  									//加密锁不同权限的结束时间
u32 Global::UnLock_LastSystemTime = 0;  												//上次开机的系统时间

u8  Global::MachineNumFlag[UnLock_Jurisd_Num] = {1, 0, 0};			//加密锁不同权限的机器编码已设标志
u32 Global::MachineNum[UnLock_Jurisd_Num] = {19981201, 0, 0};		//加密锁不同权限的机器编码

u32 Global::Unlock_SurplusDays[UnLock_Jurisd_Num] = {0, 0, 0};	//加密锁不同权限的剩余天数

u8  Global::UnLock_CurJurisType = 0;														//当前权限 0开发者 1代理商 2机器厂商

u16 Global::DecryptMachineDays = 0;															//解密后得到的解密天数
u32 Global::DecryptMachineQueueNum = 0;													//解密后得到的机器编码
u32 Global::DecryptMachinePassword = 0;													//解密用的解密密码
u32 Global::MachineQueueNum = 0;

//解密用的解密编码
u32 Global::MachineNumInPut = 0;																//解密用的机器编码

u8 Global::Beyond_Black[25] = {0};//请求解密标志


Global::Global()
{

}

Global::~Global()
{

}

u8 Global::getTemp_IO_Detect_Parameter()
{
    return Temp_IO_Detect_Parameter;
}

void Global::setTemp_IO_Detect_Parameter(const u8 &value)
{
    Temp_IO_Detect_Parameter = value;
}

QString Global::u8toqstr(u8 *data, int size)
{
    QString result;
    for (int i = 0; i < size; i++) {
        result.append(QChar(data[i]));
    }
    return result;
}

//按钮按下后，u8值若为0则变1，若为1则变0
u8 Global::ValSwitch(u8 val)
{
    if(val == 1){
        val = 0;
    }
    else{
        val = 1;
    }
    return val;
}

void Global::Robot_Init()
{
    u16 i = 0;
    u16 j = 0;
    IONameParameter Temp_Free_Output_Name;	//用于给自由编程输出指令赋值的临时变量
    IONameParameter Temp_Free_Input_Name;   //用于给自由编程输入指令赋值的临时变量

    //软限位参数初始化
    LimPos_Temp_Save();

    //功能设定参数初始化
    Temp_JXS_Parameter.Axis = JXS_Parameter.Axis;
    Temp_JXS_Parameter.Origin = JXS_Parameter.Origin;
    Temp_JXS_Parameter.SpeedLevel = JXS_Parameter.SpeedLevel;
    Temp_JXS_Parameter.Outport_Pause = JXS_Parameter.Outport_Pause;
    Temp_JXS_Parameter.Outport_Orign = JXS_Parameter.Outport_Orign;
    Temp_JXS_Parameter.Outport_Stop = JXS_Parameter.Outport_Stop;
    Temp_JXS_Parameter.Outport_Run = JXS_Parameter.Outport_Run;
    for(i=0; i<AXIS_NUM; i++)
    {
        Temp_JXS_Parameter.Alarm_Switch[i] = JXS_Parameter.Alarm_Switch[i];
        Temp_JXS_Parameter.Accelerate.Time[i] = JXS_Parameter.Accelerate.Time[i];
        Temp_JXS_Parameter.AccAcc[i] = JXS_Parameter.AccAcc[i];
        Temp_JXS_Parameter.JDZ_AllowError[i] = JXS_Parameter.JDZ_AllowError[i];
    }

    //绝对值参数初始化
    JDZ_Temp_Save();

    //用户变量初始化
    USER_Temp_Save();

    for(i=0; i<OUTPUT_NUM; i++)   //2020.5.11lmj 置位复位显示不下
    {
        if((IO_Name_Parameter[i].Name != 0||IO_Name_Parameter[i].Name1 != 0||IO_Name_Parameter[i].Name2 != 0))
        {
            IOName_To_FreeIO(IO_Name_Parameter[i],&Temp_Free_Output_Name);
            if(i < OUTPUT_NUM - 6)
            {//普通输出
                Parameter_StringChang(Program_String[i*2+PROGRAM_STRING_OUTPUT_SET_OFFSET], 0,
                        Temp_Free_Output_Name.Name, Temp_Free_Output_Name.Name1, Temp_Free_Output_Name.Name2);
                Program_String[i*2+PROGRAM_STRING_OUTPUT_SET_OFFSET][12] = 0xD6;
                Program_String[i*2+PROGRAM_STRING_OUTPUT_SET_OFFSET][13] = 0xC3;
                Program_String[i*2+PROGRAM_STRING_OUTPUT_SET_OFFSET][14] = 0xCE;
                Program_String[i*2+PROGRAM_STRING_OUTPUT_SET_OFFSET][15] = 0xBB;

                Parameter_StringChang(Program_String[i*2+PROGRAM_STRING_OUTPUT_RESET_OFFSET], 0,
                        Temp_Free_Output_Name.Name, Temp_Free_Output_Name.Name1, Temp_Free_Output_Name.Name2);
                Program_String[i*2+PROGRAM_STRING_OUTPUT_RESET_OFFSET][12] = 0xB8;
                Program_String[i*2+PROGRAM_STRING_OUTPUT_RESET_OFFSET][13] = 0xB4;
                Program_String[i*2+PROGRAM_STRING_OUTPUT_RESET_OFFSET][14] = 0xCE;
                Program_String[i*2+PROGRAM_STRING_OUTPUT_RESET_OFFSET][15] = 0xBB;
            }
            else if(i >= OUTPUT_NUM - 2)
            {//继电器输出
                Parameter_StringChang(Program_String[i*2+PROGRAM_STRING_REGOUTPUT_SET_OFFSET], 0,
                        Temp_Free_Output_Name.Name, Temp_Free_Output_Name.Name1, Temp_Free_Output_Name.Name2);
                Program_String[i*2+PROGRAM_STRING_REGOUTPUT_SET_OFFSET][12] = 0xD6;
                Program_String[i*2+PROGRAM_STRING_REGOUTPUT_SET_OFFSET][13] = 0xC3;
                Program_String[i*2+PROGRAM_STRING_REGOUTPUT_SET_OFFSET][14] = 0xCE;
                Program_String[i*2+PROGRAM_STRING_REGOUTPUT_SET_OFFSET][15] = 0xBB;

                Parameter_StringChang(Program_String[i*2+PROGRAM_STRING_REGOUTPUT_RESET_OFFSET], 0,
                        Temp_Free_Output_Name.Name, Temp_Free_Output_Name.Name1, Temp_Free_Output_Name.Name2);
                Program_String[i*2+PROGRAM_STRING_REGOUTPUT_RESET_OFFSET][12] = 0xB8;
                Program_String[i*2+PROGRAM_STRING_REGOUTPUT_RESET_OFFSET][13] = 0xB4;
                Program_String[i*2+PROGRAM_STRING_REGOUTPUT_RESET_OFFSET][14] = 0xCE;
                Program_String[i*2+PROGRAM_STRING_REGOUTPUT_RESET_OFFSET][15] = 0xBB;
            }
        }
    }

    for(i=0; i<INPUT_NUM; i++)
    {//输入显示初始化
        if((IO_Name_Parameter_Input[i].Name != 0||IO_Name_Parameter_Input[i].Name1 != 0||IO_Name_Parameter_Input[i].Name2 != 0))
        {
            IOName_To_FreeIO(IO_Name_Parameter_Input[i],&Temp_Free_Input_Name);
            Parameter_StringChang(Program_String[i+PROGRAM_STRING_INPUT_OFFSET], 0,
                    Temp_Free_Input_Name.Name, Temp_Free_Input_Name.Name1, Temp_Free_Input_Name.Name2);
            Program_String[i+PROGRAM_STRING_INPUT_OFFSET][12] = 0xBC;
            Program_String[i+PROGRAM_STRING_INPUT_OFFSET][13] = 0xEC;
            Program_String[i+PROGRAM_STRING_INPUT_OFFSET][14] = 0xB2;
            Program_String[i+PROGRAM_STRING_INPUT_OFFSET][15] = 0xE2;

            Parameter_StringChang(Alarm_String[i+ALARM_STRING_INPUT_OFFSET], 0,
                    Temp_Free_Input_Name.Name, Temp_Free_Input_Name.Name1, Temp_Free_Input_Name.Name2);
            Alarm_String[i+ALARM_STRING_INPUT_OFFSET][12] = 0xBC;
            Alarm_String[i+ALARM_STRING_INPUT_OFFSET][13] = 0xEC;
            Alarm_String[i+ALARM_STRING_INPUT_OFFSET][14] = 0xB2;
            Alarm_String[i+ALARM_STRING_INPUT_OFFSET][15] = 0xE2;
            Alarm_String[i+ALARM_STRING_INPUT_OFFSET][16] = 0xD2;
            Alarm_String[i+ALARM_STRING_INPUT_OFFSET][17] = 0xEC;
            Alarm_String[i+ALARM_STRING_INPUT_OFFSET][18] = 0xB3;
            Alarm_String[i+ALARM_STRING_INPUT_OFFSET][19] = 0xA3;
        }
    }

    Robot_Admin_Authority = ORDINARY_AUTHORITY;	//开机默认普通权限
    Admin_Authority = 0;

    Landing_Success = TRUE;
    g_Reflash_Progress_Num = TRUE;                    //刷新产量标志位
    g_RunProgram_Refresh = TRUE;
//    TIM_Cmd(TIM4,ENABLE);
//    LCD_Key_Value = 0;                                  //键值清零
//    LCD_Var_Data = 0;                                   //变量数据清零
//    g_Key_Scan = FALSE;
    g_BackLight_Dark = FALSE;
    Refresh_Admin_Flag = TRUE;
//    DelayNms(100);
//    WriteNum2(0x2630,50); //自由编程-参数-速度设置

    //伺服器使能
    Robot_Enable_Switch_On = TRUE;
    Robot_Enable = TRUE;
    g_Robot_Enable_Flag = 1;
}

//参数恢复出厂设置
void Global::Para_Rst()
{
    u8 data[1] = {0};
    u16 j = 0;
    u16 i = 0;
    IONameParameter Temp_Free_Output_Name;	//用于给自由编程输出指令赋值的临时变量
    IONameParameter Temp_Free_Input_Name;	//用于给自由编程输入指令赋值的临时变量
    u8 Delete_Point_Syc_Ready = 0;
    u8 Delete_Program_Syc_Ready = 0;
    u8 Delete_MD_Syc_Ready = 0;

    //软限位参数恢复
    for(j=0; j<AXIS_NUM; j++)
    {
        Robot_SoftLimit[j].Left_Limit  = 0;
        Robot_SoftLimit[j].Right_Limit = 0;
        Robot_SoftLimit[j].Switch_Limit = 0;
    }
    Robot_SoftDistance.MaxDistance  = 0;
    Robot_SoftDistance.MinDistance  = 0;

    //安全区参数恢复
    for(i=0; i<AXIS_NUM; i++)
    {
        Robot_Safe_Area[i].SafeArea_Switch = 0;
        Robot_Safe_Area[i].X_Left = 0;
        Robot_Safe_Area[i].Z_Left = 0;
        Robot_Safe_Area[i].X_Right = 0;
        Robot_Safe_Area[i].Z_Right = 0;
    }

    //物联网设定参数恢复
    Internet_Parameter.Switch = 0;

    //机械手设定参数恢复
    JXS_Parameter.Axis = 0;
    JXS_Parameter.Origin = 0;
    JXS_Parameter.SpeedLevel = 80;		//速度等级默认为80%
    JXS_Parameter.Outport_Pause = 0;
    JXS_Parameter.Outport_Run = 0;
    JXS_Parameter.Outport_Stop = 0;
    JXS_Parameter.Outport_Orign = 0;
    JXS_Parameter.LCcirculation = 0;
    JXS_Parameter.AlarmSignal = 0;

    for(i=0; i<AXIS_NUM; i++)
    {
        JXS_Parameter.Alarm_Switch[i] = 1;
    }

    JXS_Parameter.MDgripSwitch = 0;

    for(i=0; i<MDgrip_Num; i++)
    {
        JXS_Parameter.MDgripPort[i] = 0;
    }

    JXS_Parameter.OutputAssociate[0] = 0;
    JXS_Parameter.OutputAssociate[1] = 0;

    JXS_Parameter.ZAxsisAvoidace = 0;
    JXS_Parameter.ZAxsisLimit = 0;

    g_Reflash_Speed = TRUE;

    //原点参数设置参数恢复
    for(i=0; i<AXIS_NUM; i++)
    {
        JXS_Parameter.OriginPosition[i] = 0;
        JXS_Parameter.OriginSpeed[i] = 5;
        JXS_Parameter.OriginOffset[i] = 0;
        JXS_Parameter.OriginDiretion[i] = 0;
        JXS_Parameter.A_Circle_Pulse[i] = 10000;
        JXS_Parameter.A_Circle_Distance[i] = 100000;
        JXS_Parameter.Accelerate.Time[i] = 200;
        JXS_Parameter.AccAcc[i] = 20;
        JXS_Parameter.JDZ_AllowError[i] = 1000;
    }

    //笛卡尔坐标系参数恢复
    sCartesian_Para.length[0] = 0;
    sCartesian_Para.length[1] = 0;
    sCartesian_Para.maxSpeed = 500;
    sCartesian_Para.accTime = 200;
    sCartesian_Para.accAcc = 20;
    sCartesian_Para.carCoordSwitch = 0;
    sCartesian_Para.MDCoordType = 0;
    for(i=0; i<AXIS_NUM; i++)
    {//默认旋转轴
        sCartesian_Para.axisType[i] = 1;
    }
    sCartesian_Para.axisType[Z_AXIS] = 0;		//Z轴默认直线轴
    sCartesian_Para.pitchLength = 0;
    for(i=0; i<AXIS_NUM; i++)
    {
        sCartesian_Para.axisBackMinDir[i] = 0;
        sCartesian_Para.axisInterpFlag[i] = 1;		//默认支持插补
    }

    //码垛参数恢复
    sMD_Parameter.teachLayer = 1;

    //生产参数设定参数恢复
    SC_Parameter.RW_Num = 0;
    SC_Parameter.CJ_Num = 0;
    SC_Parameter.JG_Num = 0;
    SC_Parameter.SC_Num = 0;
    SC_Parameter.LJ_Num = 0;
    SC_Parameter.NG_Num = 0;
    sMD_RunPara.mdMethed = 0;
    sMD_RunPara.totalGood = 1;
    sMD_RunPara.startGood = 1;
    sMD_RunPara.curGood = 1;
    sMD_RunPara.curLayer = 1;
    sMD_RunPara.curNum = 1;
    g_Reflash_Progress_Num = TRUE;
    sMD_RunPara.startName.Name = 0x4D443031;
    sMD_RunPara.startName.Name1 = 0;
    sMD_RunPara.startName.Name2 = 0;
    sMD_RunPara.curName.Name = 0x4D443031;
    sMD_RunPara.curName.Name1 = 0;
    sMD_RunPara.curName.Name2 = 0;

    //配方参数恢复
    for(i=0; i<PF_IONUM; i++)
    {
        PF_Parameter.pfIOnum[i] = i;
        PF_Parameter.pfGood[i] = i + 1;
        PF_Parameter.pfSwitch[i] = 0;
    }

    //用户变量恢复
    for(i=0; i<USER_NUM; i++)
    {
        USER_Parameter.USER_Name1[i] = 0x75736572;
        USER_Parameter.USER_Name2[i] = 0x30200000+ ((u32)(i + 1) << 24);
        USER_Parameter.USER_Name3[i] = 0;
        USER_Parameter.INIT_Num[i] = 0;
        USER_Parameter.CURR_Num[i] = USER_Parameter.INIT_Num[i];
        USER_Parameter.ELEC_RESET[i]  = 1;
        USER_Parameter.START_RESET[i] = 1;

        Parameter_StringChang(Parameter_String[i+V_USER1], 0, USER_Parameter.USER_Name1[i],
                              USER_Parameter.USER_Name2[i], USER_Parameter.USER_Name3[i]);
    }
    gs_Reflash_Save_USER = TRUE;

    //绝对值参数恢复
    JDZ_Parameter.Switch = 0;
    JDZ_Parameter.Server = 0;
    JDZ_Parameter.Resolu = 0;

    for(i=0; i<AXIS_NUM; i++)
    {
        JDZ_Parameter.Circle_Pluse[i] = 10000;
        JDZ_Parameter.Motion_Dir[i] = 0;
        JDZ_Parameter.OriginSetting[i] = 0;
    }
    gs_Reflash_Fuction_JDZ = TRUE;

    //X18-X29当作特殊io参数恢复
    for(i=0; i<INPUT_NUM; i++)
    {
        if(i < Input_Special)
        {
            Temp_IO_Switch_Parameter[i] = 0;
        }
        else
        {
            Temp_IO_Switch_Parameter[i] = 1;
        }
    }

    //输入输出名字参数恢复//输入IO设定参数恢复
    for(i=0,j=0; i<INPUT_NUM; i++,j=j+12)
    {
        if(i < 10)
        {
            IO_Name_Parameter_Input[i].Name  = ('X'<<24)|((0x30+i)<<16)|0x0000;
            IO_Name_Parameter_Input[i].Name1 = 0x0;
            IO_Name_Parameter_Input[i].Name2 = 0x0;
        }
        else if(i < 18)
        {
            IO_Name_Parameter_Input[i].Name  = ('X'<<24)|(0x31<<16)|((0x30+(i-10))<<8)|0x00;
            IO_Name_Parameter_Input[i].Name1 = 0x0;
            IO_Name_Parameter_Input[i].Name2 = 0x0;
        }
        else if(i == 18)	//X轴最小限位
        {
            IO_Name_Parameter_Input[i].Name  = 0x5820D6E1;
            IO_Name_Parameter_Input[i].Name1 = 0xD7EED0A1;
            IO_Name_Parameter_Input[i].Name2 = 0xCFDECEBB;
        }
        else if(i == 19)	//Y轴最小限位
        {
            IO_Name_Parameter_Input[i].Name  = 0x5920D6E1;
            IO_Name_Parameter_Input[i].Name1 = 0xD7EED0A1;
            IO_Name_Parameter_Input[i].Name2 = 0xCFDECEBB;
        }
        else if(i == 20)	//Z轴最小限位
        {
            IO_Name_Parameter_Input[i].Name  = 0x5A20D6E1;
            IO_Name_Parameter_Input[i].Name1 = 0xD7EED0A1;
            IO_Name_Parameter_Input[i].Name2 = 0xCFDECEBB;
        }
        else if(i == 21)	//O轴最小限位
        {
            IO_Name_Parameter_Input[i].Name  = 0x4F20D6E1;
            IO_Name_Parameter_Input[i].Name1 = 0xD7EED0A1;
            IO_Name_Parameter_Input[i].Name2 = 0xCFDECEBB;
        }
        else if(i == 22)	//X轴最大限位
        {
            IO_Name_Parameter_Input[i].Name  = 0x5820D6E1;
            IO_Name_Parameter_Input[i].Name1 = 0xD7EEB4F3;
            IO_Name_Parameter_Input[i].Name2 = 0xCFDECEBB;
        }
        else if(i == 23)	//Y轴最大限位
        {
            IO_Name_Parameter_Input[i].Name  = 0x5920D6E1;
            IO_Name_Parameter_Input[i].Name1 = 0xD7EEB4F3;
            IO_Name_Parameter_Input[i].Name2 = 0xCFDECEBB;
        }
        else if(i == 24)	//Z轴最大限位
        {
            IO_Name_Parameter_Input[i].Name  = 0x5A20D6E1;
            IO_Name_Parameter_Input[i].Name1 = 0xD7EEB4F3;
            IO_Name_Parameter_Input[i].Name2 = 0xCFDECEBB;
        }
        else if(i == 25)	//O轴最大限位
        {
            IO_Name_Parameter_Input[i].Name  = 0x4F20D6E1;
            IO_Name_Parameter_Input[i].Name1 = 0xD7EEB4F3;
            IO_Name_Parameter_Input[i].Name2 = 0xCFDECEBB;
        }
        else if(i == 26)	//X轴原点
        {
            IO_Name_Parameter_Input[i].Name  = 0x5820D6E1;
            IO_Name_Parameter_Input[i].Name1 = 0xD4ADB5E3;
            IO_Name_Parameter_Input[i].Name2 = 0x0;
        }
        else if(i == 27)	//Y轴原点
        {
            IO_Name_Parameter_Input[i].Name  = 0x5920D6E1;
            IO_Name_Parameter_Input[i].Name1 = 0xD4ADB5E3;
            IO_Name_Parameter_Input[i].Name2 = 0x0;
        }
        else if(i == 28)    //Z轴原点
        {
            IO_Name_Parameter_Input[i].Name  = 0x5A20D6E1;
            IO_Name_Parameter_Input[i].Name1 = 0xD4ADB5E3;
            IO_Name_Parameter_Input[i].Name2 = 0x0;
        }
        else if(i == 29)	//O轴原点
        {
            IO_Name_Parameter_Input[i].Name  = 0x4F20D6E1;
            IO_Name_Parameter_Input[i].Name1 = 0xD4ADB5E3;
            IO_Name_Parameter_Input[i].Name2 = 0x0;
        }

        IOName_To_FreeIO(IO_Name_Parameter_Input[i],&Temp_Free_Input_Name);
        Parameter_StringChang(Program_String[i+PROGRAM_STRING_INPUT_OFFSET], 0,
                Temp_Free_Input_Name.Name, Temp_Free_Input_Name.Name1, Temp_Free_Input_Name.Name2);
        Program_String[i+PROGRAM_STRING_INPUT_OFFSET][12] = 0xBC;
        Program_String[i+PROGRAM_STRING_INPUT_OFFSET][13] = 0xEC;
        Program_String[i+PROGRAM_STRING_INPUT_OFFSET][14] = 0xB2;
        Program_String[i+PROGRAM_STRING_INPUT_OFFSET][15] = 0xE2;

        Parameter_StringChang(Alarm_String[i+ALARM_STRING_INPUT_OFFSET], 0,
                Temp_Free_Input_Name.Name, Temp_Free_Input_Name.Name1, Temp_Free_Input_Name.Name2);
        Alarm_String[i+ALARM_STRING_INPUT_OFFSET][12] = 0xBC;
        Alarm_String[i+ALARM_STRING_INPUT_OFFSET][13] = 0xEC;
        Alarm_String[i+ALARM_STRING_INPUT_OFFSET][14] = 0xB2;
        Alarm_String[i+ALARM_STRING_INPUT_OFFSET][15] = 0xE2;
        Alarm_String[i+ALARM_STRING_INPUT_OFFSET][16] = 0xD2;
        Alarm_String[i+ALARM_STRING_INPUT_OFFSET][17] = 0xEC;
        Alarm_String[i+ALARM_STRING_INPUT_OFFSET][18] = 0xB3;
        Alarm_String[i+ALARM_STRING_INPUT_OFFSET][19] = 0xA3;

        IO_Parameter[i].minTime = 0;
        IO_Parameter[i].maxTime = 0;
        IO_Parameter[i].Switch = 0;
    }

    //Y22-Y23当作特殊io参数恢复
    for(i=0; i<OUTPUT_NUM; i++)
    {
        if(i == 22 || i == 23)
        {
            Temp_OUT_Switch_Parameter[i] = 1;
        }
        else
        {
            Temp_OUT_Switch_Parameter[i] = 0;
        }
    }

    for(i=0,j=0; i<OUTPUT_NUM; i++,j=j+12)
    {
        if(i < 10)
        {
            IO_Name_Parameter[i].Name  = ('Y'<<24)|((0x30+i)<<16)|0x0000;
            IO_Name_Parameter[i].Name1 = 0x0;
            IO_Name_Parameter[i].Name2 = 0x0;
        }
        else if(i < 20)
        {
            IO_Name_Parameter[i].Name  = ('Y'<<24)|(0x31<<16)|((0x30+(i-10))<<8)|0x00;
            IO_Name_Parameter[i].Name1 = 0x0;
            IO_Name_Parameter[i].Name2 = 0x0;
        }
        else if(i < 22)
        {
            IO_Name_Parameter[i].Name  = ('Y'<<24)|(0x32<<16)|((0x30+(i-20))<<8)|0x0;
            IO_Name_Parameter[i].Name1 = 0x0;
            IO_Name_Parameter[i].Name2 = 0x0;
        }
        else if(i == 22)	//原点状态
        {
            IO_Name_Parameter[i].Name  = 0xD4ADB5E3;
            IO_Name_Parameter[i].Name1 = 0xD7B4CCAC;
            IO_Name_Parameter[i].Name2 = 0x0;
        }
        else if(i == 23)	//复位状态
        {
            IO_Name_Parameter[i].Name  = 0xB8B4CEBB;
            IO_Name_Parameter[i].Name1 = 0xD7B4CCAC;
            IO_Name_Parameter[i].Name2 = 0x0;
        }
        else if(i == 24)	//运行灯
        {
            IO_Name_Parameter[i].Name  = 0xD4CBD0D0;
            IO_Name_Parameter[i].Name1 = 0xB5C60000;
            IO_Name_Parameter[i].Name2 = 0x0;
        }
        else if(i == 25)	//待机灯
        {
            IO_Name_Parameter[i].Name  = 0xB4FDBBFA;
            IO_Name_Parameter[i].Name1 = 0xB5C60000;
            IO_Name_Parameter[i].Name2 = 0x0;
        }
        else if(i == 26)	//报警灯
        {
            IO_Name_Parameter[i].Name  = 0xB1A8BEAF;
            IO_Name_Parameter[i].Name1 = 0xB5C60000;
            IO_Name_Parameter[i].Name2 = 0x0;
        }
        else if(i == 27)	//蜂鸣器
        {
            IO_Name_Parameter[i].Name  = 0xB7E4C3F9;
            IO_Name_Parameter[i].Name1 = 0xC6F70000;
            IO_Name_Parameter[i].Name2 = 0x0;
        }
        else if(i == 28)	//RY0
        {
            IO_Name_Parameter[i].Name  = 0x52593000;
            IO_Name_Parameter[i].Name1 = 0x0;
            IO_Name_Parameter[i].Name2 = 0x0;
        }
        else if(i == 29)	//RY1
        {
            IO_Name_Parameter[i].Name  = 0x52593100;
            IO_Name_Parameter[i].Name1 = 0x0;
            IO_Name_Parameter[i].Name2 = 0x0;
        }
        IOName_To_FreeIO(IO_Name_Parameter[i],&Temp_Free_Output_Name);

        if(i < OUTPUT_NUM - 6)
        {//普通输出(不包括三色灯、蜂鸣器、继电器输出)
            Parameter_StringChang(Program_String[i*2+PROGRAM_STRING_OUTPUT_SET_OFFSET], 0,
                    Temp_Free_Output_Name.Name, Temp_Free_Output_Name.Name1, Temp_Free_Output_Name.Name2);
            Program_String[i*2+PROGRAM_STRING_OUTPUT_SET_OFFSET][12] = 0xD6;
            Program_String[i*2+PROGRAM_STRING_OUTPUT_SET_OFFSET][13] = 0xC3;
            Program_String[i*2+PROGRAM_STRING_OUTPUT_SET_OFFSET][14] = 0xCE;
            Program_String[i*2+PROGRAM_STRING_OUTPUT_SET_OFFSET][15] = 0xBB;

            Parameter_StringChang(Program_String[i*2+PROGRAM_STRING_OUTPUT_RESET_OFFSET], 0,
                    Temp_Free_Output_Name.Name, Temp_Free_Output_Name.Name1, Temp_Free_Output_Name.Name2);
            Program_String[i*2+PROGRAM_STRING_OUTPUT_RESET_OFFSET][12] = 0xB8;
            Program_String[i*2+PROGRAM_STRING_OUTPUT_RESET_OFFSET][13] = 0xB4;
            Program_String[i*2+PROGRAM_STRING_OUTPUT_RESET_OFFSET][14] = 0xCE;
            Program_String[i*2+PROGRAM_STRING_OUTPUT_RESET_OFFSET][15] = 0xBB;
        }
        else if(i >= OUTPUT_NUM - 2)
        {//继电器输出
            Parameter_StringChang(Program_String[i*2+PROGRAM_STRING_REGOUTPUT_SET_OFFSET], 0,
                    Temp_Free_Output_Name.Name, Temp_Free_Output_Name.Name1, Temp_Free_Output_Name.Name2);
            Program_String[i*2+PROGRAM_STRING_REGOUTPUT_SET_OFFSET][12] = 0xD6;
            Program_String[i*2+PROGRAM_STRING_REGOUTPUT_SET_OFFSET][13] = 0xC3;
            Program_String[i*2+PROGRAM_STRING_REGOUTPUT_SET_OFFSET][14] = 0xCE;
            Program_String[i*2+PROGRAM_STRING_REGOUTPUT_SET_OFFSET][15] = 0xBB;

            Parameter_StringChang(Program_String[i*2+PROGRAM_STRING_REGOUTPUT_RESET_OFFSET], 0,
                    Temp_Free_Output_Name.Name, Temp_Free_Output_Name.Name1, Temp_Free_Output_Name.Name2);
            Program_String[i*2+PROGRAM_STRING_REGOUTPUT_RESET_OFFSET][12] = 0xB8;
            Program_String[i*2+PROGRAM_STRING_REGOUTPUT_RESET_OFFSET][13] = 0xB4;
            Program_String[i*2+PROGRAM_STRING_REGOUTPUT_RESET_OFFSET][14] = 0xCE;
            Program_String[i*2+PROGRAM_STRING_REGOUTPUT_RESET_OFFSET][15] = 0xBB;
        }

        if((i<24)||(i>27))   //输出IO复位选择设定参数恢复
        {// Y0-Y23 RY0 RY1
            IO_Reset_Select[i].BeforeOrigin = 0;
            IO_Reset_Select[i].AfterOrigin = 0;
            IO_Reset_Select[i].CommonAlarm = 0;
            IO_Reset_Select[i].EmergeAlarm = 0;
            IO_Reset_Select[i].Pause = 0;
            IO_Reset_Select[i].Stop = 0;
        }
    }

    //点恢复出厂设置
    for(i=0; i<40; i++)
    {//保存点删除
        if(Manul_Save_Point[i].Flag)
        {
            Manul_Save_Point[i].Flag  = 0;
            Manul_Save_Point[i].Name  = 0;
            Manul_Save_Point[i].Name2 = 0;
            Manul_Save_Point[i].Name3 = 0;
            Manul_Save_Point[i].Point[X_AXIS] = 0;
            Manul_Save_Point[i].Point[L_AXIS] = 0;
            Manul_Save_Point[i].Point[Z_AXIS] = 0;
            Manul_Save_Point[i].Point[O_AXIS] = 0;
        }
    }

    //程序恢复出厂设置
    for(i=0; i<SAVEPROGRAMNUM; i++)
    {
        if(i == SAVEPROGRAMNUM_MAIN-1)
        {
            Free_Program_Save[i].Flag = 1;
            Free_Program_Save[i].Name = 0xB8B4CEBB;
            Free_Program_Save[i].Name2 = 0xB3CCD0F2;
            Free_Program_Save[i].Name3 = 0;
            Free_Program_Save[i].Num = 2;
        }
        else
        {
            Free_Program_Save[i].Flag = 0;
            Free_Program_Save[i].Name = 0;
            Free_Program_Save[i].Name2 = 0;
            Free_Program_Save[i].Name3 = 0;
            Free_Program_Save[i].Num = 0;
        }

        if(g_Run_Program_Num == i)
        {//删除程序正是在运行的程序
            g_Run_Program_Num = 0;
            g_Current_Program_Debug = FALSE;
            Free_Program_Operate.Flag = 0;
            Free_Program_Operate.Code = 0;
            Free_Program_Operate.Name = 0;
            Free_Program_Operate.Name2 = 0;
            Free_Program_Operate.Name3 = 0;
            Free_Program_Operate.Num  = 0;
            for(j=0; j<LARGESTPROGRAMNUM; j++)
            {
                Free_Program_Operate.Program[j].Flag  = 0;
                Free_Program_Operate.Program[j].List  = 0;
                Free_Program_Operate.Program[j].Order = 0;
                Free_Program_Operate.Program[j].Key   = 0;
                Free_Program_Operate.Program[j].Value1= 0;
                Free_Program_Operate.Program[j].Value2= 0;
                Free_Program_Operate.Program[j].Value3= 0;
            }
        }
    }

    Free_Program_Operate.Flag = 1;
    Free_Program_Operate.Code = SAVEPROGRAMNUM_MAIN;
    Free_Program_Operate.Name  = Free_Program_Save[SAVEPROGRAMNUM_MAIN-1].Name;
    Free_Program_Operate.Name2 = Free_Program_Save[SAVEPROGRAMNUM_MAIN-1].Name2;
    Free_Program_Operate.Name3 = Free_Program_Save[SAVEPROGRAMNUM_MAIN-1].Name3;
    Free_Program_Operate.Num   = Free_Program_Save[SAVEPROGRAMNUM_MAIN-1].Num;	  //当前模组程序条数
    for(i=0; i<Free_Program_Operate.Num; i++)
    {
        Free_Program_Operate.Program[i].Flag   = 1;
        Free_Program_Operate.Program[i].List   = i + 1;
        Free_Program_Operate.Program[i].Order  = OR_BASICORDER;
        Free_Program_Operate.Program[i].Key    = K_PROGRAMSTART + i;
        Free_Program_Operate.Program[i].Value1 = V_BLANK;
        Free_Program_Operate.Program[i].Value2 = V_BLANK;
        Free_Program_Operate.Program[i].Value3 = V_BLANK;
    }
    Free_Program_Operate.Code=Free_Program_Save[SAVEPROGRAMNUM_MAIN-1].Code;
    //发送当前保存的程序到控制板
    g_USART1_SendProgram_Flag=TRUE;
    //    USART1_SendProgram(Free_Program_Operate.Num,&Free_Program_Operate);
    g_USART1_SendProgram_Flag=FALSE;
    g_Current_Program_Debug=TRUE;

    //码垛名称初始化
    for(i=0; i<MD_GOOD_PAGE_PER; i++)
    {
        sMD_Name[i].Name = 0;
        sMD_Name[i].Name1 = 0;
        sMD_Name[i].Name2 = 0;
    }

    //码垛参数初始化
    sMD_Parameter.stackType = 0;
    sMD_Parameter.property = 0;
    sMD_Parameter.revolveMode = 0;
    sMD_Parameter.gasPort = 0;
    sMD_Parameter.topSwitch = 0;
    sMD_Parameter.goodheight = 0;
    sMD_Parameter.stackLayer = 1;
    sMD_Parameter.loopLayer = 1;
    sMD_Parameter.cycleStartLayer = 1;
    for(i=0; i<LOOP_MAX; i++)
    {
        sMD_Parameter.layerNum[i] = 1;
    }
    for(i=0; i<AXIS_NUM; i++)
    {
        sMD_Parameter.goodOffset[i] = 0;
    }
    sMD_Parameter.horNum = 1;
    sMD_Parameter.verNum = 1;
}


//将IO输入输出名字加上0x20
void Global::IOName_To_FreeIO(IONameParameter IOName, IONameParameter *P_IOName)
{
    u16 j = 0;

    P_IOName->Name = IOName.Name;
    P_IOName->Name1 = IOName.Name1;
    P_IOName->Name2 = IOName.Name2;

    /*******处理Name*****/
    if((IOName.Name & 0xFF000000) == 0)
    {//处理第一个字节
        P_IOName->Name = 0x20202020;
        j = 1;
    }
    if(j == 0)
    {//处理第二个字节
        if((IOName.Name & 0x00FF0000) == 0)
        {
            P_IOName->Name = (IOName.Name & 0xFF000000) + 0x00202020;
            j = 1;
        }
    }
    else
    {
        P_IOName->Name1 = 0x20202020;
        P_IOName->Name2 = 0x20202020;
    }
    if(j == 0)
    {//处理第三个字节
        if((IOName.Name & 0x0000FF00) == 0)
        {
            P_IOName->Name = (IOName.Name & 0xFFFF0000) + 0x00002020;
            j = 1;
        }
    }
    else
    {
        P_IOName->Name1 = 0x20202020;
        P_IOName->Name2 = 0x20202020;
    }
    if(j == 0)
    {//处理第四个字节
        if((IOName.Name & 0x000000FF) == 0)
        {
            P_IOName->Name = (IOName.Name & 0xFFFFFF00) + 0x00000020;
            j = 1;
        }
    }
    else
    {
        P_IOName->Name1 = 0x20202020;
        P_IOName->Name2 = 0x20202020;
    }

    /*******处理Name1*****/
    if(j == 0 && (IOName.Name1 & 0xFF000000) == 0)
    {//处理第一个字节
        P_IOName->Name1 = 0x20202020;
        j = 1;
    }
    else if((IOName.Name1 & 0xFF000000) == 0)
    {
        P_IOName->Name1 = 0x20202020;
        j = 1;
    }
    if(j == 0)
    {//处理第二个字节
        if((IOName.Name1 & 0x00FF0000) == 0)
        {
            P_IOName->Name1 = (IOName.Name1 & 0xFF000000) + 0x00202020;
            j = 1;
        }
    }
    else
    {
        P_IOName->Name2 = 0x20202020;
    }
    if(j == 0)
    {//处理第三个字节
        if((IOName.Name1 & 0x0000FF00) == 0)
        {
            P_IOName->Name1 = (IOName.Name1 & 0xFFFF0000) + 0x00002020;
            j = 1;
        }
    }
    else
    {
        P_IOName->Name2 = 0x20202020;
    }
    if(j == 0)
    {//处理第四个字节
        if((IOName.Name1 & 0x000000FF) == 0)
        {
            P_IOName->Name1 = (IOName.Name1 & 0xFFFFFF00) + 0x00000020;
            j = 1;
        }
    }
    else
    {
        P_IOName->Name2 = 0x20202020;
    }

    /*******处理Name2*****/
    if(j == 0 && (IOName.Name2 & 0xFF000000) == 0)
    {//处理第一个字节
        P_IOName->Name2 = 0x20202020;
        j = 1;
    }
    else if((IOName.Name2 & 0xFF000000) == 0)
    {
        P_IOName->Name2 = 0x20202020;
        j = 1;
    }

    if(j == 0)
    {//处理第二个字节
        if((IOName.Name2 & 0x00FF0000) == 0)
        {
            P_IOName->Name2 = (IOName.Name2 & 0xFF000000) + 0x00202020;
            j = 1;
        }
    }
    if(j == 0)
    {//处理第三个字节
        if((IOName.Name2 & 0x0000FF00) == 0)
        {
            P_IOName->Name2 = (IOName.Name2 & 0xFFFF0000) + 0x00002020;
            j = 1;
        }
    }
    if(j == 0)
    {//处理第四个字节
        if((IOName.Name2 & 0x000000FF) == 0)
        {
            P_IOName->Name2 = (IOName.Name2 & 0xFFFFFF00) + 0x00000020;
            j = 1;
        }
    }
}

//保存系统设置参数
void Global::f_SendSystemPara()
{
    QSettings settings(SysConfigPath, QSettings::IniFormat);
    settings.beginGroup("PARAMETER_FUCTION_SET");
    settings.setValue(JXS_Parameter_Axis_Key, JXS_Parameter.Axis);
    settings.setValue(JXS_Parameter_Origin_Key, JXS_Parameter.Origin);
    settings.setValue(JXS_Parameter_SpeedLevel_Key, JXS_Parameter.SpeedLevel);
    settings.setValue(JXS_Parameter_AlarmSignal_Key, JXS_Parameter.AlarmSignal);
    settings.setValue(JXS_Parameter_Outport_Orign_Key, JXS_Parameter.Outport_Orign);
    settings.setValue(JXS_Parameter_Outport_Run_Key, JXS_Parameter.Outport_Run);
    settings.setValue(JXS_Parameter_Outport_Pause_Key, JXS_Parameter.Outport_Pause);
    settings.setValue(JXS_Parameter_Outport_Stop_Key, JXS_Parameter.Outport_Stop);
    settings.setValue(JXS_Parameter_LCcirculation_Key, JXS_Parameter.LCcirculation);

    settings.beginWriteArray("Alarm_Switch_Array");
    for(int i = 0; i < AXIS_NUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(JXS_Parameter_Alarm_Switch_Key, JXS_Parameter.Alarm_Switch[i]);
    }
    settings.endArray();

    settings.setValue(JXS_Parameter_MDgripSwitch_Key, JXS_Parameter.MDgripSwitch);

    settings.beginWriteArray("MDgripPort_Array");
    for(int i = 0; i < MDgrip_Num; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(JXS_Parameter_MDgripPort_Key, JXS_Parameter.MDgripPort[i]);
    }
    settings.endArray();

    settings.beginWriteArray("MDgripPort_Array");
    for(int i = 0; i < OUTPUT_ASSOCIATE_NUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(JXS_Parameter_OutputAssociate_Key, JXS_Parameter.OutputAssociate[i]);
    }
    settings.endArray();

    settings.setValue(JXS_Parameter_ZAxsisAvoidace_Key, JXS_Parameter.ZAxsisAvoidace);
    settings.setValue(JXS_Parameter_ZAxsisLimit_Key, JXS_Parameter.ZAxsisLimit);

    settings.endGroup();
    settings.sync();
    sync();
}

//保存物联网设置
void Global::f_SendInternetPara()
{
    QSettings settings(SysConfigPath, QSettings::IniFormat);
    settings.beginGroup("PARAMETER_FUCTION_SET");

    settings.setValue(Internet_Parameter_Switch_Key, Internet_Parameter.Switch);

    settings.endGroup();
    settings.sync();
    sync();
}

//配方参数下发
void Global::f_Send_PFPara()
{
    QSettings settings(SysConfigPath, QSettings::IniFormat);
    settings.beginGroup("PARAMETER_FUCTION_SET");

    settings.beginWriteArray("PFPara_Array");
    for(int i=0; i < PF_IONUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(PF_Parameter_pfIOnum_Key, PF_Parameter.pfIOnum[i]);
        settings.setValue(PF_Parameter_pfGood_Key, PF_Parameter.pfGood[i]);
        settings.setValue(PF_Parameter_pfSwitch_Key, PF_Parameter.pfSwitch[i]);
    }
    settings.endArray();

    settings.endGroup();
    settings.sync();
    sync();
}

//生产参数下发
void Global::f_Send_SCPara()
{
    QSettings settings(SysConfigPath, QSettings::IniFormat);
    settings.beginGroup("PARAMETER_FUCTION_SET");

    settings.setValue(SC_Parameter_RW_Num_Key, SC_Parameter.RW_Num);
    settings.setValue(SC_Parameter_SC_Num_Key, SC_Parameter.SC_Num);
    settings.setValue(SC_Parameter_CJ_Num_Key, SC_Parameter.CJ_Num);
    settings.setValue(SC_Parameter_JG_Num_Key, SC_Parameter.JG_Num);
    settings.setValue(SC_Parameter_LJ_Num_Key, SC_Parameter.LJ_Num);
    settings.setValue(SC_Parameter_NG_Num_Key, SC_Parameter.NG_Num);
    settings.setValue(sMD_RunPara_mdMethed_Key, sMD_RunPara.mdMethed);
    settings.setValue(sMD_RunPara_totalGood_Key, sMD_RunPara.totalGood);
    settings.setValue(sMD_RunPara_startGood_Key, sMD_RunPara.startGood);
    settings.setValue(sMD_RunPara_curGood_Key, sMD_RunPara.curGood);
    settings.setValue(sMD_RunPara_curLayer_Key, sMD_RunPara.curLayer);
    settings.setValue(sMD_RunPara_curNum_Key, sMD_RunPara.curNum);

    settings.endGroup();
    settings.sync();
    sync();
}

//笛卡尔参数下发
void Global::f_send_Cartesian()
{
    QSettings settings(SysConfigPath, QSettings::IniFormat);
    settings.beginGroup("PARAMETER_FUCTION_SET");

    settings.beginWriteArray("lengthPara_Array");
    for(int i = 0; i < 2; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(sCartesian_Para_length_Key, sCartesian_Para.length[i]);
    }
    settings.endArray();

    settings.setValue(sCartesian_Para_maxSpeed_Key, sCartesian_Para.maxSpeed);
    settings.setValue(sCartesian_Para_accTime_Key, sCartesian_Para.accTime);
    settings.setValue(sCartesian_Para_accAcc_Key, sCartesian_Para.accAcc);

    settings.setValue(sCartesian_Para_carCoordSwitch_Key, sCartesian_Para.carCoordSwitch);
    settings.setValue(sCartesian_Para_MDCoordType_Key, sCartesian_Para.MDCoordType);
    settings.setValue(sCartesian_Para_pitchLength_Key, sCartesian_Para.pitchLength);

    settings.beginWriteArray("axisTypePara_Array");
    for(int i = 0; i < AXIS_NUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(sCartesian_Para_axisType_Key, sCartesian_Para.axisType[i]);
    }
    settings.endArray();

    settings.beginWriteArray("axisPara_Array");
    for(int i = 0; i < AXIS_NUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(sCartesian_Para_axisBackMinDir_Key, sCartesian_Para.axisBackMinDir[i]);
        settings.setValue(sCartesian_Para_axisInterpFlag_Key, sCartesian_Para.axisInterpFlag[i]);
    }
    settings.endArray();

    settings.endGroup();
    settings.sync();
    sync();
}

//码垛参数下发
void Global::f_Send_MDPara(u8 code)
{
    QSettings settings(SysConfigPath, QSettings::IniFormat);
    settings.beginGroup("PARAMETER_MD_PARA");

    settings.setValue(sMD_Parameter_name1_Key, sMD_Parameter.name1);
    settings.setValue(sMD_Parameter_name2_Key, sMD_Parameter.name2);
    settings.setValue(sMD_Parameter_name3_Key, sMD_Parameter.name3);
    settings.setValue(sMD_Parameter_stackType_Key, sMD_Parameter.stackType);
    settings.setValue(sMD_Parameter_property_Key, sMD_Parameter.property);
    settings.setValue(sMD_Parameter_revolveMode_Key, sMD_Parameter.revolveMode);
    settings.setValue(sMD_Parameter_gasPort_Key, sMD_Parameter.gasPort);
    settings.setValue(sMD_Parameter_topSwitch_Key, sMD_Parameter.topSwitch);
    settings.setValue(sMD_Parameter_goodheight_Key, sMD_Parameter.goodheight);
    settings.setValue(sMD_Parameter_stackLayer_Key, sMD_Parameter.stackLayer);
    settings.setValue(sMD_Parameter_loopLayer_Key, sMD_Parameter.loopLayer);

    settings.beginWriteArray("layerNum_Array");
    for(int i = 0; i < LOOP_MAX; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(sMD_Parameter_layerNum_Key, sMD_Parameter.layerNum[i]);
    }
    settings.endArray();

    settings.beginWriteArray("goodOffset_Array");
    for(int i = 0; i < AXIS_NUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(sMD_Parameter_goodOffset_Key, sMD_Parameter.goodOffset[i]);
    }
    settings.endArray();

    settings.setValue(sMD_Parameter_horNum_Key, sMD_Parameter.horNum);
    settings.setValue(sMD_Parameter_verNum_Key, sMD_Parameter.verNum);
    settings.setValue(sMD_Parameter_cycleStartLayer_Key, sMD_Parameter.cycleStartLayer);

    settings.endGroup();
    settings.sync();
    sync();
}

/*************************************************************************
**  函数名：  MD_ParaGet()
**	输入参数：code 物品编号1~60
**	输出参数：无
**	函数功能：获取码垛参数，进入码垛设置界面
**	备注：	  无
**  作者：
**  开发日期：
**************************************************************************/
void Global::MD_ParaGet(u8 code)
{

}

//码垛点下发
void Global::f_Send_MDPoint(u8 code, u8 layer, u8 pcode)
{
    u8 point_code = 0; //本页当前修改的码垛点
    point_code = pcode-1-(m_MD_Point_Page-1)*MD_POINT_PAGE_PER;

    QSettings settings(SysConfigPath, QSettings::IniFormat);
    settings.beginGroup("MDPoint");

    settings.beginWriteArray("sPoint_Array");
    for(int i = 0; i < AXIS_NUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(sMD_Parameter_sPostion_Array_point_Key, sMD_Parameter.sPostion[point_code].point[i]);
        settings.setValue(sMD_Parameter_sPostion_Array_waitPoint_Key, sMD_Parameter.sPostion[point_code].waitPoint[i]);
    }
    settings.endArray();

    settings.endGroup();
    settings.sync();
    sync();
}

/*************************************************************************
**  函数名：  MD_PointGet()
**	输入参数：code 物品编号1~60
**	输出参数：无
**	函数功能：获取码垛参数，进入码垛设置界面
**	备注：	  无
**  作者：
**  开发日期：
**************************************************************************/
void Global::MD_PointGet(u8 code, u8 layer, u8 start_pcode)
{

}

//12字节的名字字符串赋值-大端
void Global::Parameter_StringChang(u8 *string, u16 startIdx, u32 name1, u32 name2, u32 name3)
{
    string[startIdx] = (u8)(name1>>24);
    string[startIdx + 1] = (u8)(name1>>16);
    string[startIdx + 2] = (u8)(name1>>8);
    string[startIdx + 3] = (u8)(name1);
    string[startIdx + 4] = (u8)(name2>>24);
    string[startIdx + 5] = (u8)(name2>>16);
    string[startIdx + 6] = (u8)(name2>>8);
    string[startIdx + 7] = (u8)(name2);
    string[startIdx + 8] = (u8)(name3>>24);
    string[startIdx + 9] = (u8)(name3>>16);
    string[startIdx + 10] = (u8)(name3>>8);
    string[startIdx + 11] = (u8)(name3);
}

//12字节的名字字符串赋值-小端
void Global::Parameter_StringChang_Min(u8 *string, u16 startIdx, u32 name1, u32 name2, u32 name3)
{
    string[startIdx] = (u8)(name1);
    string[startIdx + 1] = (u8)(name1>>8);
    string[startIdx + 2] = (u8)(name1>>16);
    string[startIdx + 3] = (u8)(name1>>24);
    string[startIdx + 4] = (u8)(name2);
    string[startIdx + 5] = (u8)(name2>>8);
    string[startIdx + 6] = (u8)(name2>>16);
    string[startIdx + 7] = (u8)(name2>>24);
    string[startIdx + 8] = (u8)(name3);
    string[startIdx + 9] = (u8)(name3>>8);
    string[startIdx + 10] = (u8)(name3>>16);
    string[startIdx + 11] = (u8)(name3>>24);
}

//用户变量设定功能设置
void Global::USER_PARAMETER(u8 type, u8 num)
{
    if(type == USER_Name)//名称
    {
        Temp_USER_Parameter.USER_Name1[num] = LCD_Var_Data;
        Temp_USER_Parameter.USER_Name2[num] = LCD_Var_Data1;
        Temp_USER_Parameter.USER_Name3[num] = LCD_Var_Data2;
    }
    else if(type == USER_Init)//初始值
    {
        Temp_USER_Parameter.INIT_Num[num] = LCD_Var_Data;
    }
    else if(type == USER_Curr)//当前值
    {
        Temp_USER_Parameter.CURR_Num[num] = LCD_Var_Data;
    }
    else if(type == USER_Elec)//开机置0
    {
        if(Temp_USER_Parameter.ELEC_RESET[num] == FALSE)
        {
            Temp_USER_Parameter.ELEC_RESET[num] = TRUE;
        }
        else
        {
            Temp_USER_Parameter.ELEC_RESET[num] = FALSE;
        }
    }
    else if(type == USER_Start)//启动置0
    {
        if(Temp_USER_Parameter.START_RESET[num] == FALSE)
        {
            Temp_USER_Parameter.START_RESET[num] = TRUE;
        }
        else
        {
            Temp_USER_Parameter.START_RESET[num] = FALSE;
        }
    }
    else
    {
    }

    LCD_Var_Data = 0;       //清除文本数据
    LCD_Var_Data1 = 0;
    LCD_Var_Data2 = 0;
    gs_Reflash_Fuction_USER = TRUE;
}

/*************************************************************************
**  函数名：  JudgLetterDigit(u8)
**	输入参数：程序编号
**	输出参数：无
**	函数功能：判断字符是大写字母3、小写字母2、数字1
**	备注：	  无
**  作者：
**  开发日期：2024/01/12
**************************************************************************/
u8 Global::JudgLetterDigit(u8 data)
{
    if(0x30 <= data && data <= 0x39)
    {
        return 1;
    }
    else if(0x61 <= data && data <= 0x7a)
    {
        return 2;
    }
    else if(0x41 <= data && data <= 0x5a)
    {
        return 3;
    }
    else
    {
        return 0;
    }
}

//机械手参数保存
void Global::JXS_Para_Save()
{
    JXS_Parameter.Axis = Temp_JXS_Parameter.Axis;
    JXS_Parameter.Origin = Temp_JXS_Parameter.Origin;
    JXS_Parameter.SpeedLevel = Temp_JXS_Parameter.SpeedLevel;
    JXS_Parameter.Outport_Pause = Temp_JXS_Parameter.Outport_Pause;
    JXS_Parameter.Outport_Run = Temp_JXS_Parameter.Outport_Run;
    JXS_Parameter.Outport_Stop = Temp_JXS_Parameter.Outport_Stop;
    JXS_Parameter.Outport_Orign = Temp_JXS_Parameter.Outport_Orign;
    JXS_Parameter.LCcirculation = Temp_JXS_Parameter.LCcirculation;
    JXS_Parameter.AlarmSignal = Temp_JXS_Parameter.AlarmSignal;
    JXS_Parameter.ZAxsisAvoidace = Temp_JXS_Parameter.ZAxsisAvoidace;
    JXS_Parameter.ZAxsisLimit = Temp_JXS_Parameter.ZAxsisLimit;
    for(int i=0; i<AXIS_NUM; i++)
    {
        JXS_Parameter.Alarm_Switch[i] = Temp_JXS_Parameter.Alarm_Switch[i];
    }

    JXS_Parameter.MDgripSwitch = Temp_JXS_Parameter.MDgripSwitch;
    for(int i=0; i<MDgrip_Num; i++)
    {
        JXS_Parameter.MDgripPort[i] = Temp_JXS_Parameter.MDgripPort[i];
    }
    for(int i=0; i<OUTPUT_ASSOCIATE_NUM; i++)
    {
        JXS_Parameter.OutputAssociate[i] = Temp_JXS_Parameter.OutputAssociate[i];
    }
}

//机械手参数暂存
void Global::JXS_Temp_Save()
{
    Temp_JXS_Parameter.Axis = JXS_Parameter.Axis;
    Temp_JXS_Parameter.Origin = JXS_Parameter.Origin;
    Temp_JXS_Parameter.SpeedLevel = JXS_Parameter.SpeedLevel;
    Temp_JXS_Parameter.AlarmSignal = JXS_Parameter.AlarmSignal;
    Temp_JXS_Parameter.Outport_Pause  = JXS_Parameter.Outport_Pause;
    Temp_JXS_Parameter.Outport_Run  = JXS_Parameter.Outport_Run;
    Temp_JXS_Parameter.Outport_Stop  = JXS_Parameter.Outport_Stop;
    Temp_JXS_Parameter.Outport_Orign  = JXS_Parameter.Outport_Orign;
    Temp_JXS_Parameter.LCcirculation = JXS_Parameter.LCcirculation;
    Temp_JXS_Parameter.ZAxsisAvoidace = JXS_Parameter.ZAxsisAvoidace;
    Temp_JXS_Parameter.ZAxsisLimit = JXS_Parameter.ZAxsisLimit;
    for(int i=0;i<AXIS_NUM;i++)
    {
        Temp_JXS_Parameter.Alarm_Switch[i] = JXS_Parameter.Alarm_Switch[i];
    }

    Temp_JXS_Parameter.MDgripSwitch = JXS_Parameter.MDgripSwitch;
    for(int i=0; i<MDgrip_Num; i++)
    {
        Temp_JXS_Parameter.MDgripPort[i] = JXS_Parameter.MDgripPort[i];
    }
    for(int i=0;i<OUTPUT_ASSOCIATE_NUM;i++)
    {
        Temp_JXS_Parameter.OutputAssociate[i] = JXS_Parameter.OutputAssociate[i];
    }
}

//绝对值参数保存
void Global::JDZ_Para_Save()
{
    JDZ_Parameter.Switch = Temp_JDZ_Parameter.Switch;
    JDZ_Parameter.Server = Temp_JDZ_Parameter.Server;
    JDZ_Parameter.Resolu = Temp_JDZ_Parameter.Resolu;
    for(int i=0; i<AXIS_NUM; i++)
    {
        JDZ_Parameter.Circle_Pluse[i] = Temp_JDZ_Parameter.Circle_Pluse[i];
        JDZ_Parameter.Motion_Dir[i] = Temp_JDZ_Parameter.Motion_Dir[i];
    }
}

//绝对值参数暂存
void Global::JDZ_Temp_Save()
{
    Temp_JDZ_Parameter.Switch = JDZ_Parameter.Switch;   //功能开关
    Temp_JDZ_Parameter.Server = JDZ_Parameter.Server;   //伺服选择
    Temp_JDZ_Parameter.Resolu = JDZ_Parameter.Resolu;   //编码器分辨率
    for(int i=0;i<AXIS_NUM;i++)
    {
        Temp_JDZ_Parameter.Circle_Pluse[i] = JDZ_Parameter.Circle_Pluse[i]; //单圈脉冲
        Temp_JDZ_Parameter.Motion_Dir[i] = JDZ_Parameter.Motion_Dir[i];     //运动方向
    }
}

//原点参数保存
void Global::OP_Para_Save()
{
    for(int i=0; i<AXIS_NUM; i++)
    {
        JXS_Parameter.OriginPosition[i] = Temp_JXS_Parameter.OriginPosition[i];
        JXS_Parameter.OriginSpeed[i] = Temp_JXS_Parameter.OriginSpeed[i];
        JXS_Parameter.OriginOffset[i] = Temp_JXS_Parameter.OriginOffset[i];
        JXS_Parameter.OriginDiretion[i] = Temp_JXS_Parameter.OriginDiretion[i];
        JXS_Parameter.A_Circle_Pulse[i] = Temp_JXS_Parameter.A_Circle_Pulse[i];
        JXS_Parameter.A_Circle_Distance[i] = Temp_JXS_Parameter.A_Circle_Distance[i];
        JXS_Parameter.Accelerate.Time[i] = Temp_JXS_Parameter.Accelerate.Time[i];
        JXS_Parameter.AccAcc[i] = Temp_JXS_Parameter.AccAcc[i];
        JXS_Parameter.JDZ_AllowError[i] = Temp_JXS_Parameter.JDZ_AllowError[i];
    }
}

//原点参数暂存
void Global::OP_Temp_Save()
{
    for(int i=0; i<AXIS_NUM; i++)
    {
        Temp_JXS_Parameter.OriginPosition[i] = JXS_Parameter.OriginPosition[i];
        Temp_JXS_Parameter.OriginSpeed[i] = JXS_Parameter.OriginSpeed[i];
        Temp_JXS_Parameter.OriginOffset[i] = JXS_Parameter.OriginOffset[i];
        Temp_JXS_Parameter.OriginDiretion[i] = JXS_Parameter.OriginDiretion[i];
        Temp_JXS_Parameter.A_Circle_Pulse[i] = JXS_Parameter.A_Circle_Pulse[i];
        Temp_JXS_Parameter.A_Circle_Distance[i] = JXS_Parameter.A_Circle_Distance[i];
        Temp_JXS_Parameter.Accelerate.Time[i] = JXS_Parameter.Accelerate.Time[i];
        Temp_JXS_Parameter.AccAcc[i] = JXS_Parameter.AccAcc[i];
        Temp_JXS_Parameter.JDZ_AllowError[i] = JXS_Parameter.JDZ_AllowError[i];
    }
}

//用户变量保存
void Global::USER_Para_Save()
{
    for(int i=0; i<USER_NUM; i++)
    {
        USER_Parameter.USER_Name1[i] = Temp_USER_Parameter.USER_Name1[i];
        USER_Parameter.USER_Name2[i] = Temp_USER_Parameter.USER_Name2[i];
        USER_Parameter.USER_Name3[i] = Temp_USER_Parameter.USER_Name3[i];
        USER_Parameter.INIT_Num[i] = Temp_USER_Parameter.INIT_Num[i];
        USER_Parameter.CURR_Num[i] = Temp_USER_Parameter.CURR_Num[i];
        USER_Parameter.ELEC_RESET[i]  = Temp_USER_Parameter.ELEC_RESET[i];
        USER_Parameter.START_RESET[i] = Temp_USER_Parameter.START_RESET[i];

        Parameter_StringChang(Parameter_String[i+V_USER1], 0, USER_Parameter.USER_Name1[i],
                USER_Parameter.USER_Name2[i], USER_Parameter.USER_Name3[i]);
    }
}

//用户变量暂存
void Global::USER_Temp_Save()
{
    for(int i=0; i<USER_NUM; i++)
    {
        Temp_USER_Parameter.USER_Name1[i] = USER_Parameter.USER_Name1[i];
        Temp_USER_Parameter.USER_Name2[i] = USER_Parameter.USER_Name2[i];
        Temp_USER_Parameter.USER_Name3[i] = USER_Parameter.USER_Name3[i];
        Temp_USER_Parameter.INIT_Num[i] = USER_Parameter.INIT_Num[i];
        Temp_USER_Parameter.CURR_Num[i] = USER_Parameter.CURR_Num[i];
        Temp_USER_Parameter.ELEC_RESET[i]  = USER_Parameter.ELEC_RESET[i];
        Temp_USER_Parameter.START_RESET[i] = USER_Parameter.START_RESET[i];
    }
}

//软限位暂存
void Global::LP_Temp_Save()
{
    for(int j=0; j<AXIS_NUM; j++)
    {
        Temp_Soft_Limit[j].Left_Limit  = Robot_SoftLimit[j].Left_Limit;
        Temp_Soft_Limit[j].Right_Limit = Robot_SoftLimit[j].Right_Limit;
        Temp_Soft_Limit[j].Switch_Limit= Robot_SoftLimit[j].Switch_Limit;
    }
}

//软限位参数保存
void Global::LimPos_Para_Save()
{
    for(int j=0; j<AXIS_NUM; j++)
    {
        Robot_SoftLimit[j].Left_Limit  = Temp_Soft_Limit[j].Left_Limit;
        Robot_SoftLimit[j].Right_Limit = Temp_Soft_Limit[j].Right_Limit;
        Robot_SoftLimit[j].Switch_Limit= Temp_Soft_Limit[j].Switch_Limit;
    }
    Robot_SoftDistance.MaxDistance  = Temp_SoftDistance.MaxDistance;
    Robot_SoftDistance.MinDistance  = Temp_SoftDistance.MinDistance;
}

//软限位参数暂存
void Global::LimPos_Temp_Save()
{
    for(int j=0; j<AXIS_NUM; j++)
    {
        Temp_Soft_Limit[j].Left_Limit  = Robot_SoftLimit[j].Left_Limit;
        Temp_Soft_Limit[j].Right_Limit = Robot_SoftLimit[j].Right_Limit;
        Temp_Soft_Limit[j].Switch_Limit= Robot_SoftLimit[j].Switch_Limit;
    }    
    Temp_SoftDistance.MaxDistance = Robot_SoftDistance.MaxDistance;
    Temp_SoftDistance.MinDistance = Robot_SoftDistance.MaxDistance;
}

