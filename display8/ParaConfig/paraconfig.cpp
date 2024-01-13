#include "paraconfig.h"

const char* SysConfigPath = "/bin/hal.conf";
//功能设定参数
const char* JXS_Parameter_Axis_Key              = "JXS_Parameter_Axis";
const char* JXS_Parameter_Origin_Key            = "JXS_Parameter_Origin";
const char* JXS_Parameter_Accelerate_Time_Key   = "JXS_Parameter_Accelerate_Time";
const char* JXS_Parameter_SpeedLevel_Key        = "JXS_Parameter_SpeedLevel";
const char* JXS_Parameter_AlarmSignal_Key       = "JXS_Parameter_AlarmSignal";
const char* JXS_Parameter_Outport_Orign_Key     = "JXS_Parameter_Outport_Orign";
const char* JXS_Parameter_Outport_Run_Key       = "JXS_Parameter_Outport_Run";
const char* JXS_Parameter_Outport_Pause_Key     = "JXS_Parameter_Outport_Pause";
const char* JXS_Parameter_Outport_Stop_Key      = "JXS_Parameter_Outport_Stop";
const char* JXS_Parameter_LCcirculation_Key     = "JXS_Parameter_LCcirculation";
const char* JXS_Parameter_OriginOffset_Key      = "JXS_Parameter_LCcirculation";
const char* JXS_Parameter_OriginDiretion_Key    = "JXS_Parameter_LCcirculation";
const char* JXS_Parameter_OriginSpeed_Key       = "JXS_Parameter_LCcirculation";
const char* JXS_Parameter_OriginPosition_Key    = "JXS_Parameter_LCcirculation";
const char* JXS_Parameter_Alarm_Axis_Key        = "JXS_Parameter_LCcirculation";
const char* JXS_Parameter_Alarm_Switch_Key      = "JXS_Parameter_Alarm_Switch";
const char* JXS_Parameter_MDgripSwitch_Key      = "JXS_Parameter_MDgripSwitch";
const char* JXS_Parameter_MDgripNum_Key         = "JXS_Parameter_MDgripNum";
const char* JXS_Parameter_MDgripPort_Key        = "JXS_Parameter_MDgripPort";
const char* JXS_Parameter_A_Circle_Pulse_Key    = "JXS_Parameter_A_Circle_Pulse";
const char* JXS_Parameter_A_Circle_Distance_Key = "JXS_Parameter_A_Circle_Distance";
const char* JXS_Parameter_OutputAssociate_Key   = "JXS_Parameter_OutputAssociate";
const char* JXS_Parameter_ZAxsisAvoidace_Key    = "JXS_Parameter_ZAxsisAvoidace";
const char* JXS_Parameter_ZAxsisLimit_Key       = "JXS_Parameter_ZAxsisLimit";
const char* JXS_Parameter_AccAcc_Key            = "JXS_Parameter_AccAcc";
const char* JXS_Parameter_JDZ_AllowError_Key    = "JXS_Parameter_JDZ_AllowError";

const char* Axis_Step_Coefficient_Step_Coefficient_Key = "Axis_Step_Coefficient_Step_Coefficient";

const char* SC_Parameter_RW_Num_Key = "SC_Parameter_RW_Num";
const char* SC_Parameter_SC_Num_Key = "SC_Parameter_SC_Num";
const char* SC_Parameter_CJ_Num_Key = "SC_Parameter_CJ_Num";
const char* SC_Parameter_JG_Num_Key = "SC_Parameter_JG_Num";
const char* SC_Parameter_LJ_Num_Key = "SC_Parameter_LJ_Num";
const char* SC_Parameter_NG_Num_Key = "SC_Parameter_NG_Num";

const char* sMD_RunPara_mdMethed_Key        = "sMD_RunPara_mdMethed";
const char* sMD_RunPara_totalGood_Key       = "sMD_RunPara_totalGood";
const char* sMD_RunPara_startGood_Key       = "sMD_RunPara_startGood";
const char* sMD_RunPara_curGood_Key         = "sMD_RunPara_curGood";
const char* sMD_RunPara_curLayer_Key        = "sMD_RunPara_curLayer";
const char* sMD_RunPara_curNum_Key          = "sMD_RunPara_curNum";
const char* sMD_RunPara_startName_Name_Key  = "sMD_RunPara_startName_Name";
const char* sMD_RunPara_startName_Name1_Key = "sMD_RunPara_startName_Name1";
const char* sMD_RunPara_startName_Name2_Key = "sMD_RunPara_startName_Name2";
const char* sMD_RunPara_curName_Name_Key    = "sMD_RunPara_curName_Name";
const char* sMD_RunPara_curName_Name1_Key   = "sMD_RunPara_curName_Name1";
const char* sMD_RunPara_curName_Name2_Key   = "sMD_RunPara_curName_Name2";

const char* JDZ_Parameter_Switch_Key        = "JDZ_Parameter_Switch";
const char* JDZ_Parameter_Server_Key        = "JDZ_Parameter_Server";
const char* JDZ_Parameter_PreSwitch_Key     = "JDZ_Parameter_PreSwitch";
const char* JDZ_Parameter_PreServer_Key     = "JDZ_Parameter_PreServer";
const char* JDZ_Parameter_Resolu_Key        = "JDZ_Parameter_Resolu";
const char* JDZ_Parameter_Circle_Pluse_Key  = "JDZ_Parameter_Circle_Pluse";
const char* JDZ_Parameter_Motion_Dir_Key    = "JDZ_Parameter_Motion_Dir";
const char* JDZ_Parameter_OriginSetting_Key = "JDZ_Parameter_OriginSetting";

const char* USER_Parameter_USER_Name1_Key  = "USER_Parameter_USER_Name1";
const char* USER_Parameter_USER_Name2_Key  = "USER_Parameter_USER_Name2";
const char* USER_Parameter_USER_Name3_Key  = "USER_Parameter_USER_Name3";
const char* USER_Parameter_INIT_Num_Key    = "USER_Parameter_INIT_Num";
const char* USER_Parameter_CURR_Num_Key    = "USER_Parameter_CURR_Num";
const char* USER_Parameter_ELEC_RESET_Key  = "USER_Parameter_ELEC_RESET";
const char* USER_Parameter_START_RESET_Key = "USER_Parameter_START_RESET";

const char* sCartesian_Para_carCoordSwitch_Key = "sCartesian_Para_carCoordSwitch";
const char* sCartesian_Para_MDCoordType_Key    = "sCartesian_Para_MDCoordType";
const char* sCartesian_Para_pitchLength_Key    = "sCartesian_Para_pitchLength";
const char* sCartesian_Para_length_Key         = "sCartesian_Para_length";
const char* sCartesian_Para_maxSpeed_Key       = "sCartesian_Para_maxSpeed";
const char* sCartesian_Para_accTime_Key        = "sCartesian_Para_accTime";
const char* sCartesian_Para_accAcc_Key         = "sCartesian_Para_accAcc";
const char* sCartesian_Para_axisType_Key       = "sCartesian_Para_axisType";
const char* sCartesian_Para_axisBackMinDir_Key = "sCartesian_Para_axisBackMinDir";
const char* sCartesian_Para_axisInterpFlag_Key = "sCartesian_Para_axisInterpFlag";

const char* PF_Parameter_pfIOnum_Key  = "PF_Parameter_pfIOnum";
const char* PF_Parameter_pfGood_Key   = "PF_Parameter_pfGood";
const char* PF_Parameter_pfSwitch_Key = "PF_Parameter_pfSwitch";

const char* Internet_Parameter_Switch_Key   = "Internet_Parameter_Switch";
const char* Internet_Parameter_Sequence_Key = "Internet_Parameter_Sequence";


//存储点参数(40个)
const char* Manul_Save_Point_Array_Flag_Key  = "Manul_Save_Point_Array_Flag";
const char* Manul_Save_Point_Array_Name_Key  = "Manul_Save_Point_Array_Name";
const char* Manul_Save_Point_Array_Name2_Key = "Manul_Save_Point_Array_Name2";
const char* Manul_Save_Point_Array_Name3_Key = "Manul_Save_Point_Array_Name3";
const char* Manul_Save_Point_Array_Point_X_ASIS_Key = "Manul_Save_Point_Array_Point_X_ASIS";
const char* Manul_Save_Point_Array_Point_Y_ASIS_Key = "Manul_Save_Point_Array_Point_Y_ASIS";
const char* Manul_Save_Point_Array_Point_Z_ASIS_Key = "Manul_Save_Point_Array_Point_Z_ASIS";
const char* Manul_Save_Point_Array_Point_O_ASIS_Key = "Manul_Save_Point_Array_Point_O_ASIS";


//程序程序信息参数（20个）
const char* Free_Program_Save_Array_Flag_Key    = "Free_Program_Save_Array_Flag";
const char* Free_Program_Save_Array_Code_Key    = "Free_Program_Save_Array_Code";
const char* Free_Program_Save_Array_Name_Key    = "Free_Program_Save_Array_Name";
const char* Free_Program_Save_Array_Name2_Key   = "Free_Program_Save_Array_Name2";
const char* Free_Program_Save_Array_Name3_Key   = "Free_Program_Save_Array_Name3";
const char* Free_Program_Save_Array_Num_Key     = "Free_Program_Save_Array_Num";
const char* Free_Program_Save_Array_Address_Key = "Free_Program_Save_Array_Address";



//存储程序
const char* Free_Program_Operate_Flag_Key  = "Free_Program_Operate_Flag";
const char* Free_Program_Operate_Code_Key  = "Free_Program_Operate_Code";
const char* Free_Program_Operate_Name_Key  = "Free_Program_Operate_Name";
const char* Free_Program_Operate_Name2_Key = "Free_Program_Operate_Name2";
const char* Free_Program_Operate_Name3_Key = "Free_Program_Operate_Name3";
const char* Free_Program_Operate_Num_Key   = "Free_Program_Operate_Num";
const char* Free_Program_Operate_Program_Array_Flag_Key   = "Free_Program_Operate_Program_Array_Flag";
const char* Free_Program_Operate_Program_Array_List_Key   = "Free_Program_Operate_Program_Array_List";
const char* Free_Program_Operate_Program_Array_Order_Key  = "Free_Program_Operate_Program_Array_Order";
const char* Free_Program_Operate_Program_Array_Key_Key    = "Free_Program_Operate_Program_Array_Key";
const char* Free_Program_Operate_Program_Array_Value1_Key = "Free_Program_Operate_Program_Array_Value1";
const char* Free_Program_Operate_Program_Array_Value2_Key = "Free_Program_Operate_Program_Array_Value2";
const char* Free_Program_Operate_Program_Array_Value3_Key = "Free_Program_Operate_Program_Array_Value3";


//软限位参数
const char* Robot_SoftLimit_Array_Left_Limit_Key   = "Robot_SoftLimit_Array_Left_Limit";
const char* Robot_SoftLimit_Array_Right_Limit_Key  = "Robot_SoftLimit_Array_Right_Limit";
const char* Robot_SoftLimit_Array_Switch_Limit_Key = "Robot_SoftLimit_Array_Switch_Limit";

const char* Robot_SoftDistance_MaxDistance_Key = "Robot_SoftDistance_MaxDistance";
const char* Robot_SoftDistance_MinDistance_Key = "Robot_SoftDistance_MinDistance";


//安全区参数
const char* Robot_Safe_Area_Array_X_Left_Key          = "Robot_Safe_Area_Array_X_Left";
const char* Robot_Safe_Area_Array_Z_Left_Key          = "Robot_Safe_Area_Array_Z_Left";
const char* Robot_Safe_Area_Array_X_Right_Key         = "Robot_Safe_Area_Array_X_Right";
const char* Robot_Safe_Area_Array_Z_Right_Key         = "Robot_Safe_Area_Array_Z_Right";
const char* Robot_Safe_Area_Array_SafeArea_Switch_Key = "Robot_Safe_Area_Array_SafeArea_Switch";


//IO检测参数（30个）
const char* IO_Parameter_Array_minTime_Key = "IO_Parameter_Array_minTime";
const char* IO_Parameter_Array_maxTime_Key = "IO_Parameter_Array_maxTime";
const char* IO_Parameter_Array_Switch_Key  = "IO_Parameter_Array_Switch";

const char* IO_Name_Parameter_Input_Array_Name_Key  = "IO_Name_Parameter_Input_Array_Name";
const char* IO_Name_Parameter_Input_Array_Name1_Key = "IO_Name_Parameter_Input_Array_Name1";
const char* IO_Name_Parameter_Input_Array_Name2_Key = "IO_Name_Parameter_Input_Array_Name2";

const char* Temp_IO_Switch_Parameter_Key = "Temp_IO_Switch_Parameter";


//码垛点
const char* sMD_Parameter_sPostion_Array_point_Key     = "sMD_Parameter_sPostion_Array_point";
const char* sMD_Parameter_sPostion_Array_waitPoint_Key = "sMD_Parameter_sPostion_Array_waitPoint";


//码垛参数
const char* sMD_Parameter_name1_Key           = "sMD_Parameter_name1";
const char* sMD_Parameter_name2_Key           = "sMD_Parameter_name2";
const char* sMD_Parameter_name3_Key           = "sMD_Parameter_name3";
const char* sMD_Parameter_stackType_Key       = "sMD_Parameter_stackType";
const char* sMD_Parameter_property_Key        = "sMD_Parameter_property";
const char* sMD_Parameter_revolveMode_Key     = "sMD_Parameter_revolveMode";
const char* sMD_Parameter_gasPort_Key         = "sMD_Parameter_gasPort";
const char* sMD_Parameter_topSwitch_Key       = "sMD_Parameter_topSwitch";
const char* sMD_Parameter_goodheight_Key      = "sMD_Parameter_goodheight";
const char* sMD_Parameter_stackLayer_Key      = "sMD_Parameter_stackLayer";
const char* sMD_Parameter_loopLayer_Key       = "sMD_Parameter_loopLayer";
const char* sMD_Parameter_layerNum_Key        = "sMD_Parameter_layerNum";
const char* sMD_Parameter_goodOffset_Key      = "sMD_Parameter_goodOffset";
const char* sMD_Parameter_horNum_Key          = "sMD_Parameter_horNum";
const char* sMD_Parameter_verNum_Key          = "sMD_Parameter_verNum";
const char* sMD_Parameter_cycleStartLayer_Key = "sMD_Parameter_cycleStartLayer";
const char* sMD_Parameter_teachLayer_Key      = "sMD_Parameter_teachLayer";


//码垛物品名称
const char* sMD_Name_Array_Name1_Key = "sMD_Name_Array_Name1";
const char* sMD_Name_Array_Name2_Key = "sMD_Name_Array_Name2";
const char* sMD_Name_Array_Name3_Key = "sMD_Name_Array_Name3";


//输出复位选择
const char* IO_Reset_Select_Array_BeforeOrigin_Key = "IO_Reset_Select_Array_BeforeOrigin";
const char* IO_Reset_Select_Array_AfterOrigin_Key  = "IO_Reset_Select_Array_AfterOrigin";
const char* IO_Reset_Select_Array_CommonAlarm_Key  = "IO_Reset_Select_Array_CommonAlarm";
const char* IO_Reset_Select_Array_EmergeAlarm_Key  = "IO_Reset_Select_Array_EmergeAlarm";
const char* IO_Reset_Select_Array_Pause_Key        = "IO_Reset_Select_Array_Pause";
const char* IO_Reset_Select_Array_Stop_Key         = "IO_Reset_Select_Array_Stop";

const char* IO_Name_Parameter_Array_Name_Key  = "IO_Name_Parameter_Array_Name";
const char* IO_Name_Parameter_Array_Name1_Key = "IO_Name_Parameter_Array_Name1";
const char* IO_Name_Parameter_Array_Name2_Key = "IO_Name_Parameter_Array_Name2";

const char* Temp_OUT_Switch_Parameter_Key = "Temp_OUT_Switch_Parameter_Name";


//参数拷贝
const char* ParameterCopy_Buffer_Key = "ParameterCopy_Buffer";

const char* ParameterCopyBufferNum_Key = "ParameterCopyBufferNum";


////码垛参数拷贝
//const char* ParameterCopy_Buffer_Key = "MDCopyPara/ParameterCopy_Buffer";

//const char* ParameterCopyBufferNum_Key = "MDCopyPara/ParameterCopyBufferNum";

ParaConfig::ParaConfig()
{  
    InitConfigPara();
}

ParaConfig::~ParaConfig()
{

}

void ParaConfig::InitConfigPara()
{
    QSettings settings(SysConfigPath, QSettings::IniFormat);

    settings.beginGroup("SettingPara");
    settings.setValue(JXS_Parameter_Axis_Key, 0);
    settings.setValue(JXS_Parameter_Origin_Key, 0);
    settings.setValue(JXS_Parameter_SpeedLevel_Key, 80);
    settings.setValue(JXS_Parameter_AlarmSignal_Key, 0);
    settings.setValue(JXS_Parameter_Outport_Orign_Key, 0);
    settings.setValue(JXS_Parameter_Outport_Run_Key, 0);
    settings.setValue(JXS_Parameter_Outport_Pause_Key, 0);
    settings.setValue(JXS_Parameter_Outport_Stop_Key, 0);
    settings.setValue(JXS_Parameter_LCcirculation_Key, 0);

    settings.beginWriteArray("Alarm_Switch_Array");
    for(int i = 0; i < AXIS_NUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(JXS_Parameter_Alarm_Switch_Key, 1);
    }
    settings.endArray();

    settings.setValue(JXS_Parameter_MDgripSwitch_Key, 0);

    settings.beginWriteArray("MDgripPort_Array");
    for(int i = 0; i < MDgrip_Num; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(JXS_Parameter_MDgripPort_Key, 0);
    }
    settings.endArray();

    settings.beginWriteArray("MDgripPort_Array");
    for(int i = 0; i < OUTPUT_ASSOCIATE_NUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(JXS_Parameter_OutputAssociate_Key, 0);
    }
    settings.endArray();

    settings.setValue(JXS_Parameter_ZAxsisAvoidace_Key, 0);

    settings.setValue(JXS_Parameter_ZAxsisLimit_Key, 0);

    settings.beginWriteArray("OriginPara_Array");
    for(int i = 0; i < AXIS_NUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(JXS_Parameter_OriginOffset_Key, 0);
        settings.setValue(JXS_Parameter_OriginDiretion_Key, 0);
        settings.setValue(JXS_Parameter_OriginSpeed_Key, 5);
        settings.setValue(JXS_Parameter_OriginPosition_Key, 0);
        settings.setValue(JXS_Parameter_A_Circle_Pulse_Key, 10000);
        settings.setValue(JXS_Parameter_A_Circle_Distance_Key, 100000);
        settings.setValue(JXS_Parameter_AccAcc_Key, 20);
        settings.setValue(JXS_Parameter_Accelerate_Time_Key, 200);
        settings.setValue(JXS_Parameter_JDZ_AllowError_Key, 1000);
        settings.setValue(JXS_Parameter_OriginOffset_Key, 0);
        settings.setValue(Axis_Step_Coefficient_Step_Coefficient_Key, 0);
    }
    settings.endArray();

    settings.setValue(SC_Parameter_RW_Num_Key, 0);
    settings.setValue(SC_Parameter_SC_Num_Key, 0);
    settings.setValue(SC_Parameter_CJ_Num_Key, 0);
    settings.setValue(SC_Parameter_JG_Num_Key, 0);
    settings.setValue(SC_Parameter_LJ_Num_Key, 0);
    settings.setValue(SC_Parameter_NG_Num_Key, 0);
    settings.setValue(sMD_RunPara_mdMethed_Key,0);
    settings.setValue(sMD_RunPara_totalGood_Key, 1);
    settings.setValue(sMD_RunPara_startGood_Key, 1);
    settings.setValue(sMD_RunPara_curGood_Key, 1);
    settings.setValue(sMD_RunPara_curLayer_Key, 1);
    settings.setValue(sMD_RunPara_curNum_Key, 1);
    settings.setValue(sMD_RunPara_startName_Name_Key, 0x4D443031);
    settings.setValue(sMD_RunPara_startName_Name1_Key, 0);
    settings.setValue(sMD_RunPara_startName_Name2_Key, 0);
    settings.setValue(sMD_RunPara_curName_Name_Key, 0);
    settings.setValue(sMD_RunPara_curName_Name1_Key, 0x4D443031);
    settings.setValue(sMD_RunPara_curName_Name2_Key, 0);

    settings.setValue(JDZ_Parameter_Switch_Key,0);
    settings.setValue(JDZ_Parameter_Server_Key,0);
    settings.setValue(JDZ_Parameter_Resolu_Key,0);

    settings.beginWriteArray("JDZPara_Array");
    for(int i = 0; i < AXIS_NUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(JDZ_Parameter_Circle_Pluse_Key, 10000);
        settings.setValue(JDZ_Parameter_Motion_Dir_Key, 0);
        settings.setValue(JDZ_Parameter_OriginSetting_Key, 0);
    }
    settings.endArray();

    settings.beginWriteArray("USERPara_Array");
    for(int i = 0; i < USER_NUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(USER_Parameter_USER_Name1_Key, 0x75736572);
        settings.setValue(USER_Parameter_USER_Name2_Key, 0x30200000+((u32)(i + 1) << 24));
        settings.setValue(USER_Parameter_USER_Name3_Key, 0);
        settings.setValue(USER_Parameter_INIT_Num_Key, 0);
        settings.setValue(USER_Parameter_CURR_Num_Key, 0);
        settings.setValue(USER_Parameter_ELEC_RESET_Key, 1);
        settings.setValue(USER_Parameter_START_RESET_Key, 1);
    }
    settings.endArray();

    settings.setValue(sCartesian_Para_carCoordSwitch_Key, 0);
    settings.setValue(sCartesian_Para_MDCoordType_Key, 0);
    settings.setValue(sCartesian_Para_pitchLength_Key, 0);

    settings.beginWriteArray("lengthPara_Array");
    for(int i = 0; i < 2; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(sCartesian_Para_length_Key, 0);
    }
    settings.endArray();

    settings.setValue(sCartesian_Para_maxSpeed_Key, 500);
    settings.setValue(sCartesian_Para_accTime_Key, 200);
    settings.setValue(sCartesian_Para_accAcc_Key, 20);

    settings.beginWriteArray("axisTypePara_Array");
    for(int i = 0; i < AXIS_NUM; i++)
    {
        settings.setArrayIndex(i);
        if(i == Z_AXIS)
        {
            settings.setValue(sCartesian_Para_axisType_Key, 0);
        }
        else
        {
            settings.setValue(sCartesian_Para_axisType_Key, 1);
        }
    }
    settings.endArray();

    settings.beginWriteArray("axisPara_Array");
    for(int i = 0; i < AXIS_NUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(sCartesian_Para_axisBackMinDir_Key, 0);
        settings.setValue(sCartesian_Para_axisInterpFlag_Key, 1);
    }
    settings.endArray();

    settings.beginWriteArray("PFPara_Array");
    for(int i=0; i < PF_IONUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(PF_Parameter_pfIOnum_Key, i);
        settings.setValue(PF_Parameter_pfGood_Key, i+1);
        settings.setValue(PF_Parameter_pfSwitch_Key, 0);
    }
    settings.endArray();

    settings.setValue(Internet_Parameter_Switch_Key, 0);

    settings.setValue(JXS_Parameter_Axis_Key,0);
    settings.setValue(JXS_Parameter_Axis_Key,0);
    settings.setValue(JXS_Parameter_Axis_Key,0);
    settings.setValue(JXS_Parameter_Axis_Key,0);
    settings.setValue(JXS_Parameter_Axis_Key,0);

    settings.endGroup();
    settings.beginGroup("SavePointPara");

    settings.beginWriteArray("SavePoint_Array");
    for(int i=0; i < 40; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(Manul_Save_Point_Array_Flag_Key, 0);
        settings.setValue(Manul_Save_Point_Array_Name_Key, 0);
        settings.setValue(Manul_Save_Point_Array_Name2_Key, 0);
        settings.setValue(Manul_Save_Point_Array_Name3_Key, 0);
        settings.setValue(Manul_Save_Point_Array_Point_X_ASIS_Key, 0);
        settings.setValue(Manul_Save_Point_Array_Point_Y_ASIS_Key, 0);
        settings.setValue(Manul_Save_Point_Array_Point_Z_ASIS_Key, 0);
        settings.setValue(Manul_Save_Point_Array_Point_O_ASIS_Key, 0);
    }
    settings.endArray();

    settings.endGroup();

    settings.beginGroup("ProgramInfPara");

    settings.beginWriteArray("ProgramInf_Array");
    for(int i=0; i < SAVEPROGRAMNUM; i++)
    {
        settings.setArrayIndex(i);
        if(i == SAVEPROGRAMNUM_MAIN-1)
        {
            settings.setValue(Free_Program_Save_Array_Flag_Key, 1);
            settings.setValue(Free_Program_Save_Array_Name_Key, 0xB8B4CEBB);
            settings.setValue(Free_Program_Save_Array_Name2_Key, 0xB3CCD0F2);
            settings.setValue(Free_Program_Save_Array_Name3_Key, 0);
            settings.setValue(Free_Program_Save_Array_Num_Key, 2);
        }
        else
        {
            settings.setValue(Free_Program_Save_Array_Flag_Key, 0);
            settings.setValue(Free_Program_Save_Array_Name_Key, 0);
            settings.setValue(Free_Program_Save_Array_Name2_Key, 0);
            settings.setValue(Free_Program_Save_Array_Name3_Key, 0);
            settings.setValue(Free_Program_Save_Array_Num_Key, 0);
        }
    }
    settings.endArray();

    settings.endGroup();

    settings.beginGroup("ProgramPara");

    settings.setValue(Free_Program_Operate_Flag_Key, 0);
    settings.setValue(Free_Program_Operate_Code_Key, 0);
    settings.setValue(Free_Program_Operate_Name_Key, 0);
    settings.setValue(Free_Program_Operate_Name2_Key, 0);
    settings.setValue(Free_Program_Operate_Name3_Key, 0);
    settings.setValue(Free_Program_Operate_Num_Key, 0);

    settings.beginWriteArray("Program_Array");
    for(int i=0; i < LARGESTPROGRAMNUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(Free_Program_Operate_Program_Array_Flag_Key, 0);
        settings.setValue(Free_Program_Operate_Program_Array_Flag_Key, 0);
        settings.setValue(Free_Program_Operate_Program_Array_Order_Key, 0);
        settings.setValue(Free_Program_Operate_Program_Array_Key_Key, 0);
        settings.setValue(Free_Program_Operate_Program_Array_Value1_Key, 0);
        settings.setValue(Free_Program_Operate_Program_Array_Value2_Key, 0);
        settings.setValue(Free_Program_Operate_Program_Array_Value3_Key, 0);
    }
    settings.endGroup();


    settings.beginGroup("SoftLimitPara");

    settings.beginWriteArray("DistPara_Array");
    for(int i=0; i < PF_IONUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(Robot_SoftLimit_Array_Left_Limit_Key, 0);
        settings.setValue(Robot_SoftLimit_Array_Right_Limit_Key, 0);
        settings.setValue(Robot_SoftLimit_Array_Switch_Limit_Key, 0);
    }
    settings.endArray();

    settings.setValue(Robot_SoftDistance_MaxDistance_Key, 0);
    settings.setValue(Robot_SoftDistance_MinDistance_Key, 0);

    settings.endGroup();

    settings.beginGroup("SafeAreaPara");

    settings.beginWriteArray("SafeAreaPara_Array");
    for(int i=0; i < AXIS_NUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(Robot_Safe_Area_Array_X_Left_Key, 0);
        settings.setValue(Robot_Safe_Area_Array_Z_Left_Key, 0);
        settings.setValue(Robot_Safe_Area_Array_X_Right_Key, 0);
        settings.setValue(Robot_Safe_Area_Array_Z_Right_Key, 0);
        settings.setValue(Robot_Safe_Area_Array_SafeArea_Switch_Key, 0);
    }
    settings.endArray();

    settings.endGroup();

    settings.beginGroup("IODetectPara");

    settings.beginWriteArray("IONamePara_Array");
    for(int i=0; i < INPUT_NUM; i++)
    {
        settings.setArrayIndex(i);
        if(i < 10)
        {
            settings.setValue(IO_Name_Parameter_Input_Array_Name_Key, ('X'<<24)|((0x30+i)<<16)|0x0000);
            settings.setValue(IO_Name_Parameter_Input_Array_Name1_Key, 0x0);
            settings.setValue(IO_Name_Parameter_Input_Array_Name2_Key, 0x0);
        }
        else if(i < 18)
        {
            settings.setValue(IO_Name_Parameter_Input_Array_Name_Key, ('X'<<24)|(0x31<<16)|((0x30+(i-10))<<8)|0x00);
            settings.setValue(IO_Name_Parameter_Input_Array_Name1_Key, 0x0);
            settings.setValue(IO_Name_Parameter_Input_Array_Name2_Key, 0x0);
        }
        else if(i == 18)    //X轴最小限位
        {
            settings.setValue(IO_Name_Parameter_Input_Array_Name_Key,  0x5820D6E1);
            settings.setValue(IO_Name_Parameter_Input_Array_Name1_Key, 0xD7EED0A1);
            settings.setValue(IO_Name_Parameter_Input_Array_Name2_Key, 0xCFDECEBB);
        }
        else if(i == 19)    //Y轴最小限位
        {
            settings.setValue(IO_Name_Parameter_Input_Array_Name_Key,  0x5920D6E1);
            settings.setValue(IO_Name_Parameter_Input_Array_Name1_Key, 0xD7EED0A1);
            settings.setValue(IO_Name_Parameter_Input_Array_Name2_Key, 0xCFDECEBB);
        }
        else if(i == 20)    //Z轴最小限位
        {
            settings.setValue(IO_Name_Parameter_Input_Array_Name_Key,  0x5A20D6E1);
            settings.setValue(IO_Name_Parameter_Input_Array_Name1_Key, 0xD7EED0A1);
            settings.setValue(IO_Name_Parameter_Input_Array_Name2_Key, 0xCFDECEBB);
        }
        else if(i == 21)    //O轴最小限位
        {
            settings.setValue(IO_Name_Parameter_Input_Array_Name_Key,  0x4F20D6E1);
            settings.setValue(IO_Name_Parameter_Input_Array_Name1_Key, 0xD7EED0A1);
            settings.setValue(IO_Name_Parameter_Input_Array_Name2_Key, 0xCFDECEBB);
        }
        else if(i == 22)    //X轴最大限位
        {
            settings.setValue(IO_Name_Parameter_Input_Array_Name_Key,  0x5820D6E1);
            settings.setValue(IO_Name_Parameter_Input_Array_Name1_Key, 0xD7EEB4F3);
            settings.setValue(IO_Name_Parameter_Input_Array_Name2_Key, 0xCFDECEBB);
        }
        else if(i == 23)    //Y轴最大限位
        {
            settings.setValue(IO_Name_Parameter_Input_Array_Name_Key,  0x5920D6E1);
            settings.setValue(IO_Name_Parameter_Input_Array_Name1_Key, 0xD7EEB4F3);
            settings.setValue(IO_Name_Parameter_Input_Array_Name2_Key, 0xCFDECEBB);
        }
        else if(i == 24)    //Z轴最大限位
        {
            settings.setValue(IO_Name_Parameter_Input_Array_Name_Key,  0x5A20D6E1);
            settings.setValue(IO_Name_Parameter_Input_Array_Name1_Key, 0xD7EEB4F3);
            settings.setValue(IO_Name_Parameter_Input_Array_Name2_Key, 0xCFDECEBB);
        }
        else if(i == 25)    //O轴最大限位
        {
            settings.setValue(IO_Name_Parameter_Input_Array_Name_Key,  0x4F20D6E1);
            settings.setValue(IO_Name_Parameter_Input_Array_Name1_Key, 0xD7EEB4F3);
            settings.setValue(IO_Name_Parameter_Input_Array_Name2_Key, 0xCFDECEBB);
        }
        else if(i == 26)    //X轴原点
        {
            settings.setValue(IO_Name_Parameter_Input_Array_Name_Key,  0x5820D6E1);
            settings.setValue(IO_Name_Parameter_Input_Array_Name1_Key, 0xD4ADB5E3);
            settings.setValue(IO_Name_Parameter_Input_Array_Name2_Key, 0x0);
        }
        else if(i == 27)    //Y轴原点
        {
            settings.setValue(IO_Name_Parameter_Input_Array_Name_Key,  0x5920D6E1);
            settings.setValue(IO_Name_Parameter_Input_Array_Name1_Key, 0xD4ADB5E3);
            settings.setValue(IO_Name_Parameter_Input_Array_Name2_Key, 0x0);
        }
        else if(i == 28)    //Z轴原点
        {
            settings.setValue(IO_Name_Parameter_Input_Array_Name_Key,  0x5A20D6E1);
            settings.setValue(IO_Name_Parameter_Input_Array_Name1_Key, 0xD4ADB5E3);
            settings.setValue(IO_Name_Parameter_Input_Array_Name2_Key, 0x0);
        }
        else if(i == 29)    //O轴原点
        {
            settings.setValue(IO_Name_Parameter_Input_Array_Name_Key,  0x4F20D6E1);
            settings.setValue(IO_Name_Parameter_Input_Array_Name1_Key, 0xD4ADB5E3);
            settings.setValue(IO_Name_Parameter_Input_Array_Name2_Key, 0x0);
        }

        settings.setValue(IO_Parameter_Array_minTime_Key, 0);
        settings.setValue(IO_Parameter_Array_maxTime_Key, 0);
        settings.setValue(IO_Parameter_Array_Switch_Key , 0);

    }
    settings.endArray();
    //X18-X29当作特殊io参数恢复
    settings.beginWriteArray("TempIOPara_Array");
    for(int i=0; i < INPUT_NUM; i++)
    {
        settings.setArrayIndex(i);
        if(i < Input_Special)
        {
            settings.setValue(Temp_IO_Switch_Parameter_Key, 0);
        }
        else
        {
            settings.setValue(Temp_IO_Switch_Parameter_Key, 1);
        }
    }
    settings.endArray();

    settings.endGroup();

    settings.beginGroup("MDPointPara");
    settings.endGroup();

    settings.beginGroup("MDPara");
    settings.setValue(sMD_Parameter_teachLayer_Key, 1);
    settings.endGroup();


    settings.beginGroup("MDNamePara");
    settings.endGroup();
    settings.beginGroup("OUTResetPara");
    //Y22-Y23当作特殊io参数恢复
    settings.beginWriteArray("TempOUTPara_Array");
    for(int i=0; i < OUTPUT_NUM; i++)
    {
        settings.setArrayIndex(i);
        if(i == 22 || i == 23)
        {
            settings.setValue(Temp_OUT_Switch_Parameter_Key, 1);
        }
        else
        {
            settings.setValue(Temp_OUT_Switch_Parameter_Key, 0);
        }
    }
    settings.endArray();

    settings.beginWriteArray("IONamePara_Array");
    for(int i=0; i < OUTPUT_NUM; i++)
    {
        settings.setArrayIndex(i);
        if(i < 10)
        {
            settings.setValue(IO_Name_Parameter_Array_Name_Key, ('Y'<<24)|((0x30+i)<<16)|0x0000);
            settings.setValue(IO_Name_Parameter_Array_Name1_Key, 0x0);
            settings.setValue(IO_Name_Parameter_Array_Name2_Key, 0x0);
        }
        else if(i < 20)
        {
            settings.setValue(IO_Name_Parameter_Array_Name_Key, ('Y'<<24)|(0x31<<16)|((0x30+(i-10))<<8)|0x00);
            settings.setValue(IO_Name_Parameter_Array_Name1_Key, 0x0);
            settings.setValue(IO_Name_Parameter_Array_Name2_Key, 0x0);
        }
        else if(i < 22)
        {
            settings.setValue(IO_Name_Parameter_Array_Name_Key,  ('Y'<<24)|(0x32<<16)|((0x30+(i-20))<<8)|0x0);
            settings.setValue(IO_Name_Parameter_Array_Name1_Key, 0x0);
            settings.setValue(IO_Name_Parameter_Array_Name2_Key, 0x0);
        }
        else if(i == 22)    //原点状态
        {
            settings.setValue(IO_Name_Parameter_Array_Name_Key,  0xD4ADB5E3);
            settings.setValue(IO_Name_Parameter_Array_Name1_Key, 0xD7B4CCAC);
            settings.setValue(IO_Name_Parameter_Array_Name2_Key, 0x0);
        }
        else if(i == 23)    //复位状态
        {
            settings.setValue(IO_Name_Parameter_Array_Name_Key,  0xB8B4CEBB);
            settings.setValue(IO_Name_Parameter_Array_Name1_Key, 0xD7B4CCAC);
            settings.setValue(IO_Name_Parameter_Array_Name2_Key, 0x0);
        }
        else if(i == 24)    //运行灯
        {
            settings.setValue(IO_Name_Parameter_Array_Name_Key,  0xD4CBD0D0);
            settings.setValue(IO_Name_Parameter_Array_Name1_Key, 0xB5C60000);
            settings.setValue(IO_Name_Parameter_Array_Name2_Key, 0x0);
        }
        else if(i == 25)    //待机灯
        {
            settings.setValue(IO_Name_Parameter_Array_Name_Key,  0xB4FDBBFA);
            settings.setValue(IO_Name_Parameter_Array_Name1_Key, 0xB5C60000);
            settings.setValue(IO_Name_Parameter_Array_Name2_Key, 0x0);
        }
        else if(i == 26)    //报警灯
        {
            settings.setValue(IO_Name_Parameter_Array_Name_Key,  0xB1A8BEAF);
            settings.setValue(IO_Name_Parameter_Array_Name1_Key, 0xB5C60000);
            settings.setValue(IO_Name_Parameter_Array_Name2_Key, 0x0);
        }
        else if(i == 27)    //蜂鸣器
        {
            settings.setValue(IO_Name_Parameter_Array_Name_Key,  0xB7E4C3F9);
            settings.setValue(IO_Name_Parameter_Array_Name1_Key, 0xC6F70000);
            settings.setValue(IO_Name_Parameter_Array_Name2_Key, 0x0);
        }
        else if(i == 28)    //RY0
        {
            settings.setValue(IO_Name_Parameter_Array_Name_Key,  0x52593000);
            settings.setValue(IO_Name_Parameter_Array_Name1_Key, 0x0);
            settings.setValue(IO_Name_Parameter_Array_Name2_Key, 0x0);
        }
        else if(i == 29)    //RY1
        {
            settings.setValue(IO_Name_Parameter_Array_Name_Key,  0x52593100);
            settings.setValue(IO_Name_Parameter_Array_Name1_Key, 0x0);
            settings.setValue(IO_Name_Parameter_Array_Name2_Key, 0x0);
        }

        if((i < 24) || (i > 27))   //输出IO复位选择设定参数恢复
        {// Y0-Y23 RY0 RY1
            settings.setValue(IO_Reset_Select_Array_BeforeOrigin_Key, 0);
            settings.setValue(IO_Reset_Select_Array_AfterOrigin_Key, 0);
            settings.setValue(IO_Reset_Select_Array_CommonAlarm_Key, 0);
            settings.setValue(IO_Reset_Select_Array_EmergeAlarm_Key, 0);
            settings.setValue(IO_Reset_Select_Array_Pause_Key, 0);
            settings.setValue(IO_Reset_Select_Array_Stop_Key, 0);
        }

    }
    settings.endArray();


    settings.endGroup();
    settings.beginGroup("CopyPara");
    settings.endGroup();
}

void ParaConfig::Config_DateSyc()
{

}
