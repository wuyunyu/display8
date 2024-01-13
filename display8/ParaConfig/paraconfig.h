#ifndef PARACONFIG_H
#define PARACONFIG_H

#include <QSettings>
#include <unistd.h>
#include "paradef.h"
#include "parasum.h"

extern const char* SysConfigPath;
//功能设定参数
extern const char* JXS_Parameter_Axis_Key;
extern const char* JXS_Parameter_Origin_Key;
extern const char* JXS_Parameter_Accelerate_Time_Key;
extern const char* JXS_Parameter_SpeedLevel_Key;
extern const char* JXS_Parameter_AlarmSignal_Key;
extern const char* JXS_Parameter_Outport_Orign_Key;
extern const char* JXS_Parameter_Outport_Run_Key;
extern const char* JXS_Parameter_Outport_Pause_Key;
extern const char* JXS_Parameter_Outport_Stop_Key;
extern const char* JXS_Parameter_LCcirculation_Key;
extern const char* JXS_Parameter_OriginOffset_Key;
extern const char* JXS_Parameter_OriginDiretion_Key;
extern const char* JXS_Parameter_OriginSpeed_Key;
extern const char* JXS_Parameter_OriginPosition_Key;
extern const char* JXS_Parameter_Alarm_Axis_Key;
extern const char* JXS_Parameter_Alarm_Switch_Key;
extern const char* JXS_Parameter_MDgripSwitch_Key;
extern const char* JXS_Parameter_MDgripNum_Key;
extern const char* JXS_Parameter_MDgripPort_Key;
extern const char* JXS_Parameter_A_Circle_Pulse_Key;
extern const char* JXS_Parameter_A_Circle_Distance_Key;
extern const char* JXS_Parameter_OutputAssociate_Key;
extern const char* JXS_Parameter_ZAxsisAvoidace_Key;
extern const char* JXS_Parameter_ZAxsisLimit_Key;
extern const char* JXS_Parameter_AccAcc_Key;
extern const char* JXS_Parameter_JDZ_AllowError_Key;

extern const char* Axis_Step_Coefficient_Step_Coefficient_Key;

extern const char* SC_Parameter_RW_Num_Key;
extern const char* SC_Parameter_SC_Num_Key;
extern const char* SC_Parameter_CJ_Num_Key;
extern const char* SC_Parameter_JG_Num_Key;
extern const char* SC_Parameter_LJ_Num_Key;
extern const char* SC_Parameter_NG_Num_Key;

extern const char* sMD_RunPara_mdMethed_Key;
extern const char* sMD_RunPara_totalGood_Key;
extern const char* sMD_RunPara_startGood_Key;
extern const char* sMD_RunPara_curGood_Key;
extern const char* sMD_RunPara_curLayer_Key;
extern const char* sMD_RunPara_curNum_Key;
extern const char* sMD_RunPara_startName_Name_Key;
extern const char* sMD_RunPara_startName_Name1_Key;
extern const char* sMD_RunPara_startName_Name2_Key;
extern const char* sMD_RunPara_curName_Name_Key;
extern const char* sMD_RunPara_curName_Name1_Key;
extern const char* sMD_RunPara_curName_Name2_Key;

extern const char* JDZ_Parameter_Switch_Key;
extern const char* JDZ_Parameter_Server_Key;
extern const char* JDZ_Parameter_PreSwitch_Key;
extern const char* JDZ_Parameter_PreServer_Key;
extern const char* JDZ_Parameter_Resolu_Key;
extern const char* JDZ_Parameter_Circle_Pluse_Key;
extern const char* JDZ_Parameter_Motion_Dir_Key;
extern const char* JDZ_Parameter_OriginSetting_Key;

extern const char* USER_Parameter_USER_Name1_Key;
extern const char* USER_Parameter_USER_Name2_Key;
extern const char* USER_Parameter_USER_Name3_Key;
extern const char* USER_Parameter_INIT_Num_Key;
extern const char* USER_Parameter_CURR_Num_Key;
extern const char* USER_Parameter_ELEC_RESET_Key;
extern const char* USER_Parameter_START_RESET_Key;

extern const char* sCartesian_Para_carCoordSwitch_Key;
extern const char* sCartesian_Para_MDCoordType_Key;
extern const char* sCartesian_Para_pitchLength_Key;
extern const char* sCartesian_Para_length_Key;
extern const char* sCartesian_Para_maxSpeed_Key;
extern const char* sCartesian_Para_accTime_Key;
extern const char* sCartesian_Para_accAcc_Key;
extern const char* sCartesian_Para_axisType_Key;
extern const char* sCartesian_Para_axisBackMinDir_Key;
extern const char* sCartesian_Para_axisInterpFlag_Key;

extern const char* PF_Parameter_pfIOnum_Key;
extern const char* PF_Parameter_pfGood_Key;
extern const char* PF_Parameter_pfSwitch_Key;

extern const char* Internet_Parameter_Switch_Key;
extern const char* Internet_Parameter_Sequence_Key;


//存储点参数(40个)
extern const char* Manul_Save_Point_Array_Flag_Key;
extern const char* Manul_Save_Point_Array_Name_Key;
extern const char* Manul_Save_Point_Array_Name2_Key;
extern const char* Manul_Save_Point_Array_Name3_Key;
extern const char* Manul_Save_Point_Array_Point_X_ASIS_Key;
extern const char* Manul_Save_Point_Array_Point_Y_ASIS_Key;
extern const char* Manul_Save_Point_Array_Point_Z_ASIS_Key;
extern const char* Manul_Save_Point_Array_Point_O_ASIS_Key;


//程序程序信息参数（20个）
extern const char* Free_Program_Save_Array_Flag_Key;
extern const char* Free_Program_Save_Array_Code_Key;
extern const char* Free_Program_Save_Array_Name_Key;
extern const char* Free_Program_Save_Array_Name2_Key;
extern const char* Free_Program_Save_Array_Name3_Key;
extern const char* Free_Program_Save_Array_Num_Key;
extern const char* Free_Program_Save_Array_Address_Key;



//存储程序
extern const char* Free_Program_Operate_Flag_Key;
extern const char* Free_Program_Operate_Code_Key;
extern const char* Free_Program_Operate_Name_Key;
extern const char* Free_Program_Operate_Name2_Key;
extern const char* Free_Program_Operate_Name3_Key;
extern const char* Free_Program_Operate_Num_Key;
extern const char* Free_Program_Operate_Program_Array_Flag_Key;
extern const char* Free_Program_Operate_Program_Array_List_Key;
extern const char* Free_Program_Operate_Program_Array_Order_Key;
extern const char* Free_Program_Operate_Program_Array_Key_Key;
extern const char* Free_Program_Operate_Program_Array_Value1_Key;
extern const char* Free_Program_Operate_Program_Array_Value2_Key;
extern const char* Free_Program_Operate_Program_Array_Value3_Key;


//软限位参数
extern const char* Robot_SoftLimit_Array_Left_Limit_Key;
extern const char* Robot_SoftLimit_Array_Right_Limit_Key;
extern const char* Robot_SoftLimit_Array_Switch_Limit_Key;

extern const char* Robot_SoftDistance_MaxDistance_Key;
extern const char* Robot_SoftDistance_MinDistance_Key;


//安全区参数
extern const char* Robot_Safe_Area_Array_X_Left_Key;
extern const char* Robot_Safe_Area_Array_Z_Left_Key;
extern const char* Robot_Safe_Area_Array_X_Right_Key;
extern const char* Robot_Safe_Area_Array_Z_Right_Key;
extern const char* Robot_Safe_Area_Array_SafeArea_Switch_Key;


//IO检测参数（30个）
extern const char* IO_Parameter_Array_minTime_Key;
extern const char* IO_Parameter_Array_maxTime_Key;
extern const char* IO_Parameter_Array_Switch_Key;

extern const char* IO_Name_Parameter_Input_Array_Name_Key;
extern const char* IO_Name_Parameter_Input_Array_Name1_Key;
extern const char* IO_Name_Parameter_Input_Array_Name2_Key;

extern const char* Temp_IO_Switch_Parameter_Key;


//码垛点
extern const char* sMD_Parameter_sPostion_Array_point_Key;
extern const char* sMD_Parameter_sPostion_Array_waitPoint_Key;


//码垛参数
extern const char* sMD_Parameter_name1_Key;
extern const char* sMD_Parameter_name2_Key;
extern const char* sMD_Parameter_name3_Key;
extern const char* sMD_Parameter_stackType_Key;
extern const char* sMD_Parameter_property_Key;
extern const char* sMD_Parameter_revolveMode_Key;
extern const char* sMD_Parameter_gasPort_Key;
extern const char* sMD_Parameter_topSwitch_Key;
extern const char* sMD_Parameter_goodheight_Key;
extern const char* sMD_Parameter_stackLayer_Key;
extern const char* sMD_Parameter_loopLayer_Key;
extern const char* sMD_Parameter_layerNum_Key;
extern const char* sMD_Parameter_goodOffset_Key;
extern const char* sMD_Parameter_horNum_Key;
extern const char* sMD_Parameter_verNum_Key;
extern const char* sMD_Parameter_cycleStartLayer_Key;
extern const char* sMD_Parameter_teachLayer_Key;


//码垛物品名称
extern const char* sMD_Name_Array_Name1_Key;
extern const char* sMD_Name_Array_Name2_Key;
extern const char* sMD_Name_Array_Name3_Key;


//输出复位选择
extern const char* IO_Reset_Select_Array_BeforeOrigin_Key;
extern const char* IO_Reset_Select_Array_AfterOrigin_Key;
extern const char* IO_Reset_Select_Array_CommonAlarm_Key;
extern const char* IO_Reset_Select_Array_EmergeAlarm_Key;
extern const char* IO_Reset_Select_Array_Pause_Key;
extern const char* IO_Reset_Select_Array_Stop_Key;

extern const char* IO_Name_Parameter_Array_Name2_Key;

extern const char* Temp_OUT_Switch_Parameter_Key;


//参数拷贝
extern const char* ParameterCopy_Buffer_Key;

extern const char* ParameterCopyBufferNum_Key;


////码垛参数拷贝
//extern const char* ParameterCopy_Buffer_Key;

//extern const char* ParameterCopyBufferNum_Key;

class ParaConfig
{
public:
    ParaConfig();
    ~ParaConfig();

public:
    void InitConfigPara();
    void Config_DateSyc(void);

private:


private:


};

#endif // PARACONFIG_H
