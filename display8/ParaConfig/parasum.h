#ifndef PARASUM_H
#define PARASUM_H

#include "paradef.h"
#include <iostream>
#include <QSettings>
#include <unistd.h>
#include "paraconfig.h"

using namespace std;

namespace RUN {
    static u32 Program_RunTime_LastTime = 0;	//上次运行时间
    static u8 gs_Robot_Enable_Flag = 0;	           	//使能
    static u8 gs_Emergency_Stop_Flag = 0;	        //急停
    static u32 gs_SC_Parameter_SC_Num = 0;		    //加工参数
    static u32 gs_MDRun_Parameter[3] = {0};		    //码垛加工参数：0：当前物品，1：当前层，2：当前个
    static u8 gs_Cycle_Run_Flag = 0;	 		    //0:循环  1：单次
    volatile static u8 gs_Auto_Status = AUTO_ERROR;
    static u8 gs_Program_Refresh_Flag = FALSE;	   	//显示程序刷新
    static u8 gs_Run_Program_List[10]= {0};	                    //当前显示的8条指令
    static u8 gs_Run_Program_Color = 0;				            //当前背景色
    static u8 gs_Run_Program_Code[10] ={0};	                    //当前显示的8个编码
    static u32 gs_Run_Program_Parameter_Display[10][3]= {0};	//编码命令对应的两位参数及显示
    static u8 gs_Run_Program_Operater_List = 0;		            //当前选择运行程序正在运行的指令条：由主控板返回
}

namespace TEACH {
    static u16 Parameter_Unset_Line = 0;			//参数未设置的行数
    static u8 gs_Start_End_Error = FALSE;			//程序开始结束不对
    static u8 gs_Save_Program_Num = 0;	 			//当前保存程序的编号
    static u8 gs_Current_Program_Debug = TRUE;	 	//调试-显示剪切图标
    static u8 gs_Current_Program_Modify = TRUE;	 	//调试
    static u8 gs_Refresh_Speed_Input = FALSE;	 	//参数-速度刷新显示
    static u8 gs_Refresh_Delay_Input = FALSE;	 	//参数-时间刷新显示
    static u8 gs_Refresh_Distance_Input = FALSE;	//参数-距离刷新显示
    static u8 gs_Refresh_User_Input = FALSE;	 	//参数-用户变量刷新显示
    static u8 g_UserSelect_Display_Refresh = FALSE; //用户变量选择标志
    static u8 gs_Refresh_SubProgramNumber = FALSE;  //子程序号显示
    static u8 gs_Refresh_JUMP = FALSE; 				//跳转
    static u8 gs_Refresh_IO_Input = FALSE; 			//行号/IO刷新显示
    static u8 gs_Refresh_While_Num = FALSE; 		//循环次数

    static int teach_dialog_flag;                   //编程界面对话框标志
}

namespace DEBUG {
    static u16 gs_Input1_Status = 0;    //gs_Input1_Status[0]=[0~7];gs_Input1_Status[1]=[0~6]--8+7=15
    static u16 gs_Input2_Status = 0;
    static u16 gs_Output1_Status = 0;
    static u16 gs_Output2_Status = 0;
}

namespace MANUAL {
    static u8 gs_LinkMove_Speed = 10;	         	//X轴连动速度
    static u8 gs_Carte_LinkMove_Speed = 10;	     	//笛卡尔坐标系下的连动速度
    static u16 gs_StepMove_Distance = 50;        	//寸动距离
}

namespace SET {
    static u8 gs_Pre_Choose_Program = 0;	            	//先选择程序
    static u8 gs_Current_Choose_Program = 0;	        	//当前选择程序
    static u8 g_IO_Detect_Input = 0;						//自由编程界面，I方式的输入口选择标志
    static u8 g_IO_Detect_Output = 0;						//自由变成界面，O方式、脉宽输出、输出检测的输出口选择标志
    static u8 gs_Refresh_IO_Detect_IO = FALSE;
    static u8 gs_Refresh_IO_Detect_Name = FALSE;  				//IO名字刷新
    static u8 gs_Refresh_IO_Detect_Switch = FALSE;				//IO常开常闭刷新
    static u8 gs_Refresh_IO_Detect_Time = FALSE;  				//IO检测时间刷新
    static u8 gs_Refresh_IO_Detect_Name_Input = FALSE;  		//IO检测名字刷新
    static u8 gs_Pre_Buzzer_switch = FALSE;       //蜂鸣器之前状态
    static u8 gs_BackLight_Refresh = 1;
    static u8 gs_Pass_Word_Refresh = FALSE;	    //显示刷新
    static u32 gs_Pass_Word_Temp[3] = {0};	       	//原密码、新密码、确认密码缓存
    static u8 gs_Refresh_StartUp_Password = TRUE;	//开机密码刷新显示
    static u8 gs_Reflash_SoftLimit = FALSE;
    static u8 gs_Refresh_SoftLimit_Temp = FALSE; 			//点软限位开关时
    static u8 gs_Refresh_SafeArea_Temp = TRUE;	  			//点安全区域开关时
    static u8 gs_Reflash_Save_JDZ = FALSE;	             	//机械手绝对值参数保存显示刷新
    static u8 gs_Refresh_JDZ_Axis = FALSE ;					//设置机械手回零、原点重置、原点设置时确认具体轴更新显示
    static u8 gs_Refresh_Axis_Num = FALSE;          	//机械手轴个数no
    static u8 gs_Refresh_Axis_Select = FALSE;          //机械手轴个数选择no
    static u8 gs_Refresh_Origin_Method = FALSE;     	//回原点方式
    static u8 gs_Refresh_Accelerate_Level = FALSE;  	//加速度等级
    static u8 gs_Refresh_Outport = FALSE; 	 			//外部端口显示
    static u8 gs_Refresh_AlarmSignal = FALSE;    		//伺服报警信号
    static u8 gs_Refresh_OrignParameter = FALSE;  		//原点参数刷新显示
    static u8 gs_Refresh_OrignPara_Text = FALSE;		//原点参数text显示
    static u8 gs_Refresh_Associate = FALSE;    		//关联输出刷新显示
    static u8 gs_Refresh_Avoidace = FALSE;
    static u8 gs_USBH_Copy_Status = USBHSTATUS_NOUDISK;
    static u8 gs_Refresh_Admin_Pass_Word = FALSE;
}

namespace ALARM {
    static DateTable AlarmDate = {};
    static u8 gs_Alarm_History_Refresh = 0;
    static u8 gs_Current_Alarm = 0xFF;
    static u8 gs_Alarm_Blink = 0;
    static u8 gs_Auto_Status_Error = 0xff;				//用于状态栏刷新显示
}

namespace MAINW {
    static s32 gs_StartUp_Axis_Position[AXIS_NUM] = {0};  //轴位置
}

//全局参数和函数汇总
class Global
{
public:
    Global();
    ~Global();

public://RunPage
    static u32 Program_RunTime;				//程序单次运行时间
    static u8  Landing_Success;		 //密码登陆标识位
    static u8  PassWord_Input_Done;
    static u32 Pass_Word_Temp;		         //输入的密码缓存
    static u8  Package_Adj;
    static u8  Package_Point;
    static u8  Restore_setting;
    static u8  Change_User_Start;
    static u8  Change_User_Password;	//修改用户权限密码，=0时修改普通权限密码，=1时修改管理员权限密码
    static u8  gs_Run_Program_Num;				                   	//当前选择运行程序的编号
    static u8  g_Auto_Status;
    static s32 gs_Run_PosValue[11];								//暂存当前坐标值
    static u8  m_PF_Refresh;									//配方参数刷新
    static u8  ProgramSelect_PointNum[11];                        //轴移动指令中选择的点位编号 用于开机界面指令显示点位名称
    static u8  g_Run_ProFirstLineNum;          		            //开机页程序显示第一行行数


public://TeachPage
    static u8  gs_Current_Dispaly_Code[11];	    //当前显示的8个编码 !
    static u8  gs_Current_Dispaly_Point[11];	    //当前显示的轴命令的点编号
    static u32 gs_Code_Parameter_Display[11][3]; //编码命令对应的两位参数及显示 !
    static u8 gs_IO_Instructions_Display_Refresh;
    static u8 SubProgram_Sequence;//当前保存的子程序序号 !
    static u8 BlankChar[12];
    static u8 BlankChar48[48];     // !
    static u8 gs_Current_Dispaly_List[11]; 						//当前显示的8条指令
    static u8 gs_Current_Operate_List;	         					//当前蓝色背景所在的指令编号
    static u8 gs_Current_Program_Firstline;                        //显示框第一条指令的行数
    static u8 g_Refresh_Dispaly_List_Flag;	 					//刷新程序显示列表
    static u8 gs_Parameter_Unset;			 					//程序参数未设置 !
    static FreeProgram Program_Buffer;                           //用于缓存修改 添加是的程序指令参数
    static u8 Program_StringSplic[16];
    static u8 Parameter_Value[10];
    static s8 Parameter_ValueS[10]; //有符号 !
    static u8 g_Current_Program_Debug;			 				//当前程序是否可以调试
    static u8 g_Program_Is_Debuging;			     			//程序调试中,所有按键失效
    static u8 g_Link_Debug;
    static u8 g_USART1_SendProgram_Flag;			 			//标志开始发送程序
    static u8 g_Current_Program_Modify; 			 			//修改
    static u8 g_SubPro_Value_Flag;						//子程序选择标志位 !
    static u8 Number_SubProgram;									//子程序序号 1-20 !
    static u8 Number_JUMP;										//跳转行号 !
    static u8 Number_While;										//循环次数 !
    static u8 gs_Free_Point_Display_Refresh; 					//坐标修改


public://DebugPage
    static u8 gs_IO_Name_Display_Refresh;

public://ManualPage
    static u32 gs_Manul_Axis_Position[AXIS_NUM];     //轴位置
    static u8 gs_Point_Display_Refresh_Step;
    static u8 gs_Save_Point_Num;	           			//当前保存点的编号,比实际编号小1,可做数组下标 !
    static u8 gs_Refresh_Speed_Para;	     		//速度-步进刷新
    static u8 g_Manul_Move_count;	                    //左右移连动计数
    static u8 g_Manul_Move_Flag;                	//手动移动标志位，用于是否协议握手
    static u8 g_Manul_Link_Flag;                	//连动操作，主要标志蜂鸣器
    static u8 Temp_Display_Data[12];
    static u8 Temp_Display_Data1[12];
    static u8 SavePoint_Group_Choose;  	  //选中第一组---该变量是第40页的组界面切换时显示的下标索引 !
    static u8 g_Current_Choose_Group;	      //当前选择存储点的组别
    static u8 g_Current_Choose_Point;	      //当前选择点--存储点管理界面
    static u8 g_Current_Choose_Axsis;        //选中的是这个点的那个轴坐标
    static u8 g_Pre_Choose_Group;	      	  //当前选择存储点的组别
    static u8 g_Pre_Choose_Point;	          //先前选择点

public://SetPage
    static u8 gs_MDgripSetFlag;                     //码垛夹爪端口选择标志
    static SoftLimit  Temp_Soft_Limit[AXIS_NUM];   // !
    static SoftLimit  Robot_SoftLimit[AXIS_NUM];		//XZL软限位参数
    static SoftDistance  Robot_SoftDistance;
    static SoftDistance  Temp_SoftDistance;
    static u8 gs_Pre_Choose_Area;             		//先前选择区域
    static u8 g_Current_Choose_Area;          		//当前选择区域
    static u8 gs_Reflash_Fuction_JXS;	             	 			//机械手功能显示刷新
    static u8 gs_Reflash_Fuction_SC;	              				//生产功能显示刷新
    static u8 gs_Reflash_Fuction_USER;                             //生产功能显示刷新
    static u8 gs_Reflash_Save_USER;	              				//生产功能显示刷新
    static u8 gs_Reflash_Fuction_JDZ;	             	 	//机械手绝对值参数显示刷新  兼容绝对值
    static u8 gs_Refresh_JDZOriginSetting_Text;				//JDZ原点设置显示
    static u8 JDZ_Machine_Ori_Axis_Num;							//机械手回零：1-X 2-Z 3-Y 4-O
    static u8 JDZ_Origin_Resetting_Axis_Num;						//重置原点： 1-X 2-Z 3-Y 4-O
    static u8 JDZ_Origin_Setting_Axis_Num;							//原点设置： 1-X 2-Z 3-Y 4-O
    static u8 Get_JDZ_Information;	//区分获得那个JDZ信息	0X15:获取原点设置信息	0X16:获取原点重置信息	0X17:获取机械回零信息
    static u8 gs_Refresh_MD_Circulation;    	//码垛循环方式
    static u8 Axis_Parameter_Select;  				//原点参数轴选择刷新显示
    static JXSParameter JXS_Parameter;
    static JXSParameter Temp_JXS_Parameter;    // !
    static u8 Temp_ACC_Axis;   // !
    static SCParameter SC_Parameter;		               		//生产参数
    static USERParameter USER_Parameter;		               	//用户变量
    static USERParameter Temp_USER_Parameter;  // !
    static u8 g_USART1_DeletePoint_Flag;			 		//标志开始删除
    static u32  Admin_Pass_Word;
    static JDZParameter JDZ_Parameter;	//绝对值参数设定
    static JDZParameter Temp_JDZ_Parameter;					//绝对值参数设定
    static u8 gs_Reflash_Fuction_Internet;                  //物联网设定界面刷新
    static u8 gs_Reflash_Internet_Switch;                   //物联网功能开关刷新
    static InternetParameter Internet_Parameter;              //物联网功能设置
    static IONameParameter sMD_Name[MD_GOOD_PAGE_PER];        //码垛选择页面-名称显示   
    static u8 m_MD_Methed;					//码垛方式：0：连续，1：分拣
    static u8 m_MD_Good_Page;				//物品选择当前页
    static u8 m_MD_Point_Page;				//示教点选则当前页
    static u8 m_MD_Point_Code;				//当前选择示教点编号：1，2，3，...
    static u8 m_Choose_Good_Mode;	   		//选取码垛物品标志：0：读参数，1：选取起始物品，2：选取当前物品，3：选取拷出物品参数
    static ST_MDParameter sMD_Parameter;  //码垛参数
    static ST_MDRunPara sMD_RunPara;		//码垛运行参数
    static u8 m_Reflash_Name_MD;		//码垛名称刷新
    static u8 m_Reflash_Point_MD;       //码垛点刷新
    static u8 m_Reflash_Para_MD;		//码垛参数刷新
    static u8 m_Reflash_Run_MD;         //码垛运行参数刷新
    static u8 m_MD_TeachPoint_Flag;     //码垛示教点标志
    static u8 m_MD_GasPort_Flag;		//气缸端口选择标志
    static u8 m_GoodOffset_Refresh;     //物料偏移刷新
    static PFParameter PF_Parameter;		//配方参数
    static u8 Temp_PF_Ionum;   // !
    static u8 m_MD_Copy_Code;               //当前选择要拷贝的物品编号：1,2,3,...
    //笛卡尔坐标系相关参数
    static ST_Cartesian sCartesian_Para;
    static u8 m_Refresh_Cartesian;      //坐标系参数刷新no

    static IONameParameter IO_Name_Parameter_Temp[OUTPUT_NUM];
    static IONameParameter IO_Name_Parameter[OUTPUT_NUM];
    static IONameParameter Temp_IO_Name_Parameter[OUTPUT_NUM];
    static IOResetSelect IO_Reset_Select[OUTPUT_NUM];
    static IOResetSelect Temp_IO_Reset_Select[OUTPUT_NUM];
    static IONameParameter IO_Name_Parameter_Input[INPUT_NUM];
    static IONameParameter Temp_IO_Name_Parameter_Input[INPUT_NUM];
    static u8 Temp_IO_Switch_Parameter[INPUT_NUM];
    static u8 Temp_OUT_Switch_Parameter[OUTPUT_NUM];
    static u8 gs_IO_Detect_Display_Refresh;										//IO输入名刷新
    static u8 gs_IO_Detect_Display_Refresh_Input;

    static PointCodeParameter Point_CodeParameter;
    static char Temp_CopyFileName[17];
    static NamePara Copy_FileName;          //文件名称
    static u8 Current_Point_List;

    static u32 RealTimeCount;
    static u8 Set_LCPosition;
    static SafeArea Robot_Safe_Area[7];
    static u8  gs_Program_Display_Refresh;
    static u8  gs_Point_Display_Refresh;
    static u8  g_FucSet_Axis_Num;
    static u8 gs_Temp_Point_Display_Refresh;
    static u8 Temp_IO_Detect_Parameter;                     //当前选择的IO口号
    static InputIOParameter IO_Parameter[INPUT_NUM];        //输入口参数保存
    static InputIOParameter Temp_IO_Parameter[INPUT_NUM];   //修改的输入口参数
    static s32 Modify_Point_Temp;    						//修改存储点时输入的坐标值
    static s32 Modify_MD_Point_Temp[AXIS_NUM];    		//修改存储点时输入的坐标值
    static u8 gs_Point_Modify_Refresh;    	//存储点修改弹框中的显示内容刷新


public://AlarmPage
    static AlarmHistory Alarm_History_Time[20];
    static AlarmHistoryDisplay Alarm_History_Display[21];
    static u8 Cur_Alarm_Page;      //报警页    !
    static u8 gs_Robot_Error_Flag; // !
    static u8 g_Alarm_Buzzer;
    static u8 g_Alarm_Buzzer_Timer;
    static u8 g_Alarm_Buzzer_Count;
    static u8 g_Current_Alarm;


public://DGUS
    static u8  LCD_Main_Page;                     //LCD当前主目录1~6
    static s32 LCD_Var_Data;				   //变量数据
    static s32 LCD_Var_Data1;
    static s32 LCD_Var_Data2;
    static u32 Pass_Word[2];
    static u8  Refresh_Admin_Flag;
    static u8  Admin_Authority;					   		//0:普通权限 1:管理员权限
    static u8  Robot_Admin_Authority;
    /*----------------Start_Up--界面1操作标志位----------------*/
    static u8 g_Robot_Enable_Flag ;	         	//使能
    static u8 g_Emergency_Stop_Flag ;	     		//急停
    static u8 g_Cycle_Run_Flag ;	 		 				//0:循环  1：单次
    static u8 g_Robot_Restart_Flag ;
    static u8 g_Run_Program_Num;
    static u8 g_Run_Program_Operater_List;	 	//当前选择运行程序正在运行的指令条：由主控板返回
    static u8 g_RunProgram_Refresh;	 					//运行页面当前运行程序刷新
    static u8 g_Run_Program_List_Num;
    static u8 g_Reflash_Progress_Num ;
    static u8 g_Reflash_Speed ;
    static u8 g_Robot_Auto_Reset;
    static u8 g_Robot_Auto_Reset_Scan;
    static u8 Axis_Position_Scan ;
    /*----------------Free_Program--界面2操作标志位--------------*/
    static u8 g_Background_Color;			  			//编辑背景色
    static u8 g_Background_Color_Blink ;      //背光闪烁标志位
    static u8 g_Background_Blink_Delay ;      //背景闪烁延时标志位
    static u8 g_Background_Blink_Count;
    static u8 g_Event_Done_Flag  ;
    static u8 g_SaveProgram_Flag ;            //程序保存
    static u32 Axis_Parameter_Speed;          //轴速度值百分比
    static u32 Delay_Parameter_Time ;				  //延时时间参数
    static s32 Distance_Parameter;            //位移参数
    static s32 User_Parameter;                //用户参数
    static s32 Coorinate_Parameter;           //坐标设置

    static u32 Number_IOstatus_Input; 				//R数量/IO状态参数 //XDS 2019.6
    static u32 Number_IO_Input;       				//行号/IO参数 //XDS 2019.6

    static u8 g_Current_Paramter_Value;		    //设置参数1/2/3
    static u8 g_Current_Paramter_Num ;		  	//参数设置行
    static u8 g_Current_Paramter_Key ;		  	//参数设置指令编号
    static u8 g_FreeProgram_Setting_XZ;
    static u8 gs_FreeProgram_Setting_XZ;
    static u8 g_SavePoint_Setting;
    static u8 g_FreeProgram_Axismove_Flag;    //轴移动拾取坐标标志位
    /*----------------IO_Control--界面3操作标志位--------------*/
    //static u8  g_Watch_IO_Control;
    static u16 g_Input1_Status  ;	 //输入1状态
    static u16 g_Input2_Status  ;	 //输入2状态
    static u16 g_Input3_Status  ;	 //输入3状态
    static u16 g_Output1_Status ;	 //输出1状态
    static u16 g_Output2_Status ;	 //输出2状态
    static u16 g_Output3_Status ;	 //输出3状态
    static u8  g_Output1Ack_Flag;
    static u8  g_Output2Ack_Flag;
    static u8  g_Output3Ack_Flag;

    /*----------------Manul_Operate--界面4操作标志位------------*/
    static u8  g_Current_Manul_Axis;		 		//手动微调时当前选择轴
    static u8  g_Current_Manul_Axis_Refresh;//手动微调时当前选择轴刷新
    static u16 g_Manule_Pulse ;
    static u16 gs_Manule_Pulse ;
    /*---------------------------------------------------------*/

    /*----------------SystemSetting--界面5操作标志位------------*/
    static u8  g_Buzzer_Switch_Flag;
    static u32 g_BackLight_Time;
    static u32 g_BackLight_Count;
    static u8  g_BackLight_Dark;
    static u8  USBH_Process_Flag;
    static u8  USBH_Direction;
    static u8  USBH_Dispaly_Fresh_Flag;
    static u8  USBH_Copy_Status;
    static u8  USB_Update_Status;
    static u8  USB_Dispaly_Fresh_Flag;

public://Parameter
    static u8  X_Axsis_Origin_Enable ;	 	//X轴回原点标识位
    static u8  Z_Axsis_Origin_Enable ;	 	//Z轴回原点标识位
    static u8  Robot_Origining;
    static u8  X_Axsis_Origned;	   				//X轴已回原点
    static u8  Z_Axsis_Origned;	   				//Z轴已回原点
    static u8  Robot_Origined;	   				//机械手回原点
    static u8  Robot_Enable;
    static u8  Robot_Enable_Switch_On;
    static u8  Robot_Enable_Pre_Switch;
    static u8  Program_Ready;
    static u8  Data_Syc_Ready;
    static u8  ProgramInf_Syc_Ready;
    static u8  Program_Syc_Ready;
    static u8  SoftLimit_Syc_Ready;
    static u8  SafeArea_Syc_Ready;
    static u8  Point_Syc_Ready;
    static u8  Setting_Syc_Ready;
    static u8  IODetect_Syc_Ready;
    static u8  OUTReset_Syc_Ready;
    static u8  ParameterCopy_Ready;
    static u8  MDParaCopy_Ready;
    static u8  DJParameter_Syc_Ready; 			//开机读取导教参数完成 ---2019.8.3
    static u8  Main_Init_Done;		 					//主控板开机完成
    static volatile u8  Robot_Status ;      //机械手状态
    static u8  Robot_Auto_Mode;
    static u8  Robot_Single_Mode;
    static u8  Robot_Single_Mode_Pre;

    static s32 g_Axis_Position[AXIS_NUM] ;			//O轴的位置
    static s32 g_Pre_Axis_Position[AXIS_NUM];		//X轴之前时刻的位置
    static u8 g_AxiseCarteType;			 						//轴坐标-笛卡尔坐标标志
    static u8 gs_AxiseCarteType_Refresh;

    static union Conefficient Axis_Step_Coefficient[AXIS_NUM];

    static u8  g_Servo_Is_Run;
    static u8  g_Axis_Choose ;
    static u8  Robot_Error_Data[10];
    static u8  g_Robot_Error_Flag;
    static u8  MDNameDetect_Syc_Ready;
    static u8  MDPara_Syc_Ready;
    static u8  MDPoint_Syc_Ready;

    static u8 StartUp_Password;
    static u8 StartUp_Password_Dis;

    static SavePoint Manul_Save_Point[40];
    static SaveProgramInf Free_Program_Save[SAVEPROGRAMNUM];
    static SaveProgram Current_Operate_Program;
    static SaveProgram Free_Program_Operate;

    static u8 Percentage_Value[4];
    static u32 DisplayDealTimeCounter;				//防止操作过快引起的问题

    static u8 UnLock_RequestDecrypt;					//请求解密标志
    static u8 CheckBatterySta;								//电池拔出标志，1拔出，0没拔出

    static u8  Axsis_Robot_Origined[AXIS_NUM];//各个轴回零完成标志位				绝对值优化20210304zcx

    static u8  InitDataTimeFlag;														//加密锁初始时间标志开机默认需要初始化
    static u32 InitDataTime;														//加密锁初始时间，单位s
    static u8  UnLock_Forever_flag[UnLock_Jurisd_Num];								//加密锁不同权限的长期有效标志位
    static u32 CurSystemTime;																	//当前读到的系统时间
    static u32 UnLock_EndTime[UnLock_Jurisd_Num];  									//加密锁不同权限的结束时间
    static u32 UnLock_LastSystemTime;  												//上次开机的系统时间

    static u8  MachineNumFlag[UnLock_Jurisd_Num];			//加密锁不同权限的机器编码已设标志
    static u32 MachineNum[UnLock_Jurisd_Num];		//加密锁不同权限的机器编码

    static u32 Unlock_SurplusDays[UnLock_Jurisd_Num];	//加密锁不同权限的剩余天数

    static u8  UnLock_CurJurisType;														//当前权限 0开发者 1代理商 2机器厂商

    static u16 DecryptMachineDays;															//解密后得到的解密天数
    static u32 DecryptMachineQueueNum;													//解密后得到的机器编码
    static u32 DecryptMachinePassword;													//解密用的解密密码
    static u32 MachineQueueNum;

    //解密用的解密编码
    static u32 MachineNumInPut;																//解密用的机器编码

    static u8 Beyond_Black[25];

public:
    static QString u8toqstr(u8* data, int size);
    static u8 ValSwitch(u8 val);

    static void Robot_Init();
    static void Para_Rst();

    static void IOName_To_FreeIO(IONameParameter IOName, IONameParameter* P_IOName);
    static void f_SendSystemPara();
    static void f_SendInternetPara();
    static void f_Send_PFPara();
    static void f_Send_SCPara();
    static void f_send_Cartesian();
    static void f_Send_MDPara(u8 code);
    static void MD_ParaGet(u8 code);
    static void f_Send_MDPoint(u8 code, u8 layer, u8 pcode);
    static void MD_PointGet(u8 code, u8 layer, u8 start_pcode);
    static void Parameter_StringChang(u8 *string, u16 startIdx, u32 name1, u32 name2, u32 name3);
    static void Parameter_StringChang_Min(u8 *string, u16 startIdx, u32 name1, u32 name2, u32 name3);
    static void USER_PARAMETER(u8 type, u8 num);
    static u8 JudgLetterDigit(u8 data);


    static void JXS_Para_Save();
    static void JXS_Temp_Save();
    static void JDZ_Para_Save();
    static void JDZ_Temp_Save();
    static void OP_Para_Save();
    static void OP_Temp_Save();
    static void USER_Para_Save();
    static void USER_Temp_Save();
    static void LP_Temp_Save();

    static void LimPos_Para_Save();
    static void LimPos_Temp_Save();
    static u8 getTemp_IO_Detect_Parameter();
    static void setTemp_IO_Detect_Parameter(const u8 &value);
};

#endif // PARASUM_H
