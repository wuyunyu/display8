#include "paraconfig.h"

const char* SysConfigPath = "/bin/mydata.ini";
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
const char* Manul_Save_Point_Array_Point_X_AXIS_Key = "Manul_Save_Point_Array_Point_X_AXIS";
const char* Manul_Save_Point_Array_Point_Y_AXIS_Key = "Manul_Save_Point_Array_Point_Y_AXIS";
const char* Manul_Save_Point_Array_Point_Z_AXIS_Key = "Manul_Save_Point_Array_Point_Z_AXIS";
const char* Manul_Save_Point_Array_Point_O_AXIS_Key = "Manul_Save_Point_Array_Point_O_AXIS";


//存储程序信息参数（20个）
const char* Free_Program_Save_Array_Flag_Key    = "Free_Program_Save_Array_Flag";
const char* Free_Program_Save_Array_Code_Key    = "Free_Program_Save_Array_Code";
const char* Free_Program_Save_Array_Name_Key    = "Free_Program_Save_Array_Name";
const char* Free_Program_Save_Array_Name2_Key   = "Free_Program_Save_Array_Name2";
const char* Free_Program_Save_Array_Name3_Key   = "Free_Program_Save_Array_Name3";
const char* Free_Program_Save_Array_Num_Key     = "Free_Program_Save_Array_Num";
const char* Free_Program_Save_Array_Address_Key = "Free_Program_Save_Array_Address";



//运行程序参数
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
const char* sMD_Name_Array_Name_Key = "sMD_Name_Array_Name";
const char* sMD_Name_Array_Name1_Key = "sMD_Name_Array_Name1";
const char* sMD_Name_Array_Name2_Key = "sMD_Name_Array_Name2";


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

}

ParaConfig::~ParaConfig()
{

}

//恢复原出厂时将参数值同步写入mydata.ini文件中
void ParaConfig::RstConfigPara()
{
    Global::Para_Rst();
    QSettings settings(SysConfigPath, QSettings::IniFormat);
    int i = 0;
    //软限位参数恢复初始值开始
    settings.beginGroup("PARAMETER_SOFT_LIMIT");

    settings.beginWriteArray("LimPosPara_Array");
    for(i=0; i < PF_IONUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(Robot_SoftLimit_Array_Left_Limit_Key, Global::Robot_SoftLimit[i].Left_Limit);
        settings.setValue(Robot_SoftLimit_Array_Right_Limit_Key, Global::Robot_SoftLimit[i].Right_Limit);
        settings.setValue(Robot_SoftLimit_Array_Switch_Limit_Key, Global::Robot_SoftLimit[i].Switch_Limit);
    }
    settings.endArray();

    settings.setValue(Robot_SoftDistance_MaxDistance_Key, Global::Robot_SoftDistance.MaxDistance);
    settings.setValue(Robot_SoftDistance_MinDistance_Key, Global::Robot_SoftDistance.MinDistance);

    settings.endGroup();    //软限位参数恢复初始值结束

    //安全区参数恢复初始值开始
    settings.beginGroup("PARAMETER_SAFE_AREA");

    settings.beginWriteArray("SafeAreaPara_Array");
    for(i=0; i < AXIS_NUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(Robot_Safe_Area_Array_SafeArea_Switch_Key, Global::Robot_Safe_Area[i].SafeArea_Switch);    //启用-关闭
        settings.setValue(Robot_Safe_Area_Array_X_Left_Key, Global::Robot_Safe_Area[i].X_Left);             //左X
        settings.setValue(Robot_Safe_Area_Array_Z_Left_Key, Global::Robot_Safe_Area[i].Z_Left);             //左Z
        settings.setValue(Robot_Safe_Area_Array_X_Right_Key, Global::Robot_Safe_Area[i].X_Right);            //右X
        settings.setValue(Robot_Safe_Area_Array_Z_Right_Key, Global::Robot_Safe_Area[i].Z_Right);            //右Z
    }
    settings.endArray();

    settings.endGroup();    //安全区参数恢复初始值结束

    //功能设定参数恢复初始值开始
    settings.beginGroup("PARAMETER_FUCTION_SET");

    //功能设定--物联网设定参数恢复初始值
    settings.setValue(Internet_Parameter_Switch_Key, Global::Internet_Parameter.Switch);

    //功能设定--机械手设定参数恢复初始值
    settings.setValue(JXS_Parameter_Axis_Key, Global::JXS_Parameter.Axis);
    settings.setValue(JXS_Parameter_Origin_Key, Global::JXS_Parameter.Origin);
    settings.setValue(JXS_Parameter_SpeedLevel_Key, Global::JXS_Parameter.SpeedLevel);    //速度等级默认为80%
    settings.setValue(JXS_Parameter_AlarmSignal_Key, Global::JXS_Parameter.AlarmSignal);
    settings.setValue(JXS_Parameter_Outport_Orign_Key, Global::JXS_Parameter.Outport_Orign);
    settings.setValue(JXS_Parameter_Outport_Run_Key, Global::JXS_Parameter.Outport_Run);
    settings.setValue(JXS_Parameter_Outport_Pause_Key, Global::JXS_Parameter.Outport_Pause);
    settings.setValue(JXS_Parameter_Outport_Stop_Key, Global::JXS_Parameter.Outport_Stop);
    settings.setValue(JXS_Parameter_LCcirculation_Key, Global::JXS_Parameter.LCcirculation);

    settings.beginWriteArray("Alarm_Switch_Array");
    for(i = 0; i < AXIS_NUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(JXS_Parameter_Alarm_Switch_Key, Global::JXS_Parameter.Alarm_Switch[i]);
    }
    settings.endArray();

    settings.setValue(JXS_Parameter_MDgripSwitch_Key, Global::JXS_Parameter.MDgripSwitch);

    settings.beginWriteArray("MDgripPort_Array");
    for(i = 0; i < MDgrip_Num; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(JXS_Parameter_MDgripPort_Key, Global::JXS_Parameter.MDgripPort[i]);
    }
    settings.endArray();

    settings.beginWriteArray("OutputAssociate_Array");
    for(i = 0; i < OUTPUT_ASSOCIATE_NUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(JXS_Parameter_OutputAssociate_Key, Global::JXS_Parameter.OutputAssociate[i]);
    }
    settings.endArray();

    settings.setValue(JXS_Parameter_ZAxsisAvoidace_Key, Global::JXS_Parameter.ZAxsisAvoidace);

    settings.setValue(JXS_Parameter_ZAxsisLimit_Key, Global::JXS_Parameter.ZAxsisLimit);

    settings.beginWriteArray("OriginPara_Array");
    for(i = 0; i < AXIS_NUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(JXS_Parameter_OriginOffset_Key, Global::JXS_Parameter.OriginOffset[i]);
        settings.setValue(JXS_Parameter_OriginDiretion_Key, Global::JXS_Parameter.OriginDiretion[i]);
        settings.setValue(JXS_Parameter_OriginSpeed_Key, Global::JXS_Parameter.OriginSpeed[i]);
        settings.setValue(JXS_Parameter_OriginPosition_Key, Global::JXS_Parameter.OriginPosition[i]);
        settings.setValue(JXS_Parameter_A_Circle_Pulse_Key, Global::JXS_Parameter.A_Circle_Pulse[i]);
        settings.setValue(JXS_Parameter_A_Circle_Distance_Key, Global::JXS_Parameter.A_Circle_Distance[i]);
        settings.setValue(JXS_Parameter_AccAcc_Key, Global::JXS_Parameter.AccAcc[i]);
        settings.setValue(JXS_Parameter_Accelerate_Time_Key, Global::JXS_Parameter.Accelerate.Time[i]);
        settings.setValue(JXS_Parameter_JDZ_AllowError_Key, Global::JXS_Parameter.JDZ_AllowError[i]);
//        settings.setValue(Axis_Step_Coefficient_Step_Coefficient_Key, 0);
    }
    settings.endArray();

    //功能设定--笛卡尔坐标系参数恢复初始值
    settings.beginWriteArray("lengthPara_Array");
    for(i = 0; i < 2; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(sCartesian_Para_length_Key, Global::sCartesian_Para.length[i]);
    }
    settings.endArray();

    settings.setValue(sCartesian_Para_maxSpeed_Key, Global::sCartesian_Para.maxSpeed);
    settings.setValue(sCartesian_Para_accTime_Key, Global::sCartesian_Para.accTime);
    settings.setValue(sCartesian_Para_accAcc_Key, Global::sCartesian_Para.accAcc);

    settings.setValue(sCartesian_Para_carCoordSwitch_Key, Global::sCartesian_Para.carCoordSwitch);
    settings.setValue(sCartesian_Para_MDCoordType_Key, Global::sCartesian_Para.MDCoordType);

    settings.beginWriteArray("axisTypePara_Array");
    for(i = 0; i < AXIS_NUM; i++)
    {//默认旋转轴
        settings.setArrayIndex(i);
        settings.setValue(sCartesian_Para_axisType_Key, Global::sCartesian_Para.axisType[i]);
    }
    settings.endArray();

    settings.setValue(sCartesian_Para_pitchLength_Key, Global::sCartesian_Para.pitchLength);

    settings.beginWriteArray("axisPara_Array");
    for(i = 0; i < AXIS_NUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(sCartesian_Para_axisBackMinDir_Key, Global::sCartesian_Para.axisBackMinDir[i]);
        settings.setValue(sCartesian_Para_axisInterpFlag_Key, Global::sCartesian_Para.axisInterpFlag[i]);   //默认支持插补
    }
    settings.endArray();

    //功能设定--生产参数设定参数恢复初始值
    settings.setValue(SC_Parameter_RW_Num_Key, Global::SC_Parameter.RW_Num);
    settings.setValue(SC_Parameter_SC_Num_Key, Global::SC_Parameter.CJ_Num);
    settings.setValue(SC_Parameter_CJ_Num_Key, Global::SC_Parameter.JG_Num);
    settings.setValue(SC_Parameter_JG_Num_Key, Global::SC_Parameter.SC_Num);
    settings.setValue(SC_Parameter_LJ_Num_Key, Global::SC_Parameter.LJ_Num);
    settings.setValue(SC_Parameter_NG_Num_Key, Global::SC_Parameter.NG_Num);
    settings.setValue(sMD_RunPara_mdMethed_Key, Global::sMD_RunPara.mdMethed);
    settings.setValue(sMD_RunPara_totalGood_Key, Global::sMD_RunPara.totalGood);
    settings.setValue(sMD_RunPara_startGood_Key, Global::sMD_RunPara.startGood);
    settings.setValue(sMD_RunPara_curGood_Key, Global::sMD_RunPara.curGood);
    settings.setValue(sMD_RunPara_curLayer_Key, Global::sMD_RunPara.curLayer);
    settings.setValue(sMD_RunPara_curNum_Key, Global::sMD_RunPara.curNum);
    settings.setValue(sMD_RunPara_startName_Name_Key, Global::sMD_RunPara.startName.Name);
    settings.setValue(sMD_RunPara_startName_Name1_Key, Global::sMD_RunPara.startName.Name1);
    settings.setValue(sMD_RunPara_startName_Name2_Key, Global::sMD_RunPara.startName.Name2);
    settings.setValue(sMD_RunPara_curName_Name_Key, Global::sMD_RunPara.curName.Name);
    settings.setValue(sMD_RunPara_curName_Name1_Key, Global::sMD_RunPara.curName.Name1);
    settings.setValue(sMD_RunPara_curName_Name2_Key, Global::sMD_RunPara.curName.Name2);

    //功能设定--配方参数恢复初始值
    settings.beginWriteArray("PFPara_Array");
    for(i=0; i < PF_IONUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(PF_Parameter_pfIOnum_Key, Global::PF_Parameter.pfIOnum[i]);
        settings.setValue(PF_Parameter_pfGood_Key, Global::PF_Parameter.pfGood[i]);
        settings.setValue(PF_Parameter_pfSwitch_Key, Global::PF_Parameter.pfSwitch[i]);
    }
    settings.endArray();

    //功能设定--用户变量恢复初始值
    settings.beginWriteArray("USERPara_Array");
    for(i = 0; i < USER_NUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(USER_Parameter_USER_Name1_Key, Global::USER_Parameter.USER_Name1[i]);
        settings.setValue(USER_Parameter_USER_Name2_Key, Global::USER_Parameter.USER_Name2[i]);
        settings.setValue(USER_Parameter_USER_Name3_Key, Global::USER_Parameter.USER_Name3[i]);
        settings.setValue(USER_Parameter_INIT_Num_Key, Global::USER_Parameter.INIT_Num[i]);
        settings.setValue(USER_Parameter_CURR_Num_Key, Global::USER_Parameter.CURR_Num[i]);
        settings.setValue(USER_Parameter_ELEC_RESET_Key, Global::USER_Parameter.ELEC_RESET[i]);
        settings.setValue(USER_Parameter_START_RESET_Key, Global::USER_Parameter.START_RESET[i]);
    }
    settings.endArray();

    //功能设定--绝对值参数恢复初始值
    settings.setValue(JDZ_Parameter_Switch_Key, Global::JDZ_Parameter.Switch);
    settings.setValue(JDZ_Parameter_Server_Key, Global::JDZ_Parameter.Server);
    settings.setValue(JDZ_Parameter_Resolu_Key, Global::JDZ_Parameter.Resolu);

    settings.beginWriteArray("JDZPara_Array");
    for(i = 0; i < AXIS_NUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(JDZ_Parameter_Circle_Pluse_Key, Global::JDZ_Parameter.Circle_Pluse[i]);
        settings.setValue(JDZ_Parameter_Motion_Dir_Key, Global::JDZ_Parameter.Motion_Dir[i]);
        settings.setValue(JDZ_Parameter_OriginSetting_Key, Global::JDZ_Parameter.OriginSetting[i]);
    }
    settings.endArray();

    settings.endGroup();    //功能设定参数恢复初始值结束

    //输入复用开关恢复初始值开始
    settings.beginGroup("PARAMETER_INPUT_SWITCH_SET");

    //X18-X29当作特殊IO参数恢复初始值
    settings.beginWriteArray("TempIOPara_Array");
    for(i=0; i < INPUT_NUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(Temp_IO_Switch_Parameter_Key, Global::Temp_IO_Switch_Parameter[i]);
    }
    settings.endArray();

    //输入IO设定参数恢复初始值
    settings.beginWriteArray("IONamePara_Array");
    for(i=0; i < INPUT_NUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(IO_Name_Parameter_Input_Array_Name_Key,  Global::IO_Name_Parameter_Input[i].Name );
        settings.setValue(IO_Name_Parameter_Input_Array_Name1_Key, Global::IO_Name_Parameter_Input[i].Name1);
        settings.setValue(IO_Name_Parameter_Input_Array_Name2_Key, Global::IO_Name_Parameter_Input[i].Name2);
    }
    settings.endArray();

    settings.endGroup();    //输入复用开关恢复初始值结束

    //输入IO检测恢复初始值开始
    settings.beginGroup("PARAMETER_IO_DETECT_SET");
    settings.beginWriteArray("InputDetect_Array");
    for(i=0; i < INPUT_NUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(IO_Parameter_Array_minTime_Key, Global::IO_Parameter[i].minTime);
        settings.setValue(IO_Parameter_Array_maxTime_Key, Global::IO_Parameter[i].maxTime);
        settings.setValue(IO_Parameter_Array_Switch_Key , Global::IO_Parameter[i].Switch );
    }
    settings.endArray();

    settings.endGroup();    //输入IO检测恢复初始值结束


    //输出复用开关恢复初始值开始
    settings.beginGroup("PARAMETER_OUTPUT_SWITCH_SET");

    //Y22-Y23当作特殊io参数恢复初始值
    settings.beginWriteArray("TempOUTPara_Array");
    for(i=0; i < OUTPUT_NUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(Temp_OUT_Switch_Parameter_Key, Global::Temp_OUT_Switch_Parameter[i]);
    }
    settings.endArray();

    //输出IO设定参数恢复初始值
    settings.beginWriteArray("IONamePara_Array");
    for(i=0; i < OUTPUT_NUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(IO_Name_Parameter_Array_Name_Key,  Global::IO_Name_Parameter[i].Name );
        settings.setValue(IO_Name_Parameter_Array_Name1_Key, Global::IO_Name_Parameter[i].Name1);
        settings.setValue(IO_Name_Parameter_Array_Name2_Key, Global::IO_Name_Parameter[i].Name2);
    }
    settings.endArray();

    settings.endGroup();    //输出复用开关恢复初始值结束

    //输出IO复位选择设定参数恢复初始值开始
    settings.beginGroup("PARAMETER_OUTPUT_SET");

    settings.beginWriteArray("IOResetSel_Array");
    for(i=0; i < OUTPUT_NUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(IO_Reset_Select_Array_BeforeOrigin_Key, Global::IO_Reset_Select[i].BeforeOrigin);
        settings.setValue(IO_Reset_Select_Array_AfterOrigin_Key, Global::IO_Reset_Select[i].AfterOrigin);
        settings.setValue(IO_Reset_Select_Array_CommonAlarm_Key, Global::IO_Reset_Select[i].CommonAlarm);
        settings.setValue(IO_Reset_Select_Array_EmergeAlarm_Key, Global::IO_Reset_Select[i].EmergeAlarm);
        settings.setValue(IO_Reset_Select_Array_Pause_Key, Global::IO_Reset_Select[i].Pause);
        settings.setValue(IO_Reset_Select_Array_Stop_Key, Global::IO_Reset_Select[i].Stop);
    }
    settings.endArray();

    settings.endGroup();    //输出IO复位选择设定参数恢复初始值结束

    //点恢复出厂设置开始
    settings.beginGroup("PARAMETER_SAVEPOINT");

    settings.beginWriteArray("ManulSavePoint_Array");
    for(i=0; i<40; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(Manul_Save_Point_Array_Flag_Key, Global::Manul_Save_Point[i].Flag);
        settings.setValue(Manul_Save_Point_Array_Name_Key, Global::Manul_Save_Point[i].Name);
        settings.setValue(Manul_Save_Point_Array_Name2_Key, Global::Manul_Save_Point[i].Name2);
        settings.setValue(Manul_Save_Point_Array_Name3_Key, Global::Manul_Save_Point[i].Name3);
        settings.setValue(Manul_Save_Point_Array_Point_X_AXIS_Key, Global::Manul_Save_Point[i].Point[X_AXIS]);
        settings.setValue(Manul_Save_Point_Array_Point_Y_AXIS_Key, Global::Manul_Save_Point[i].Point[L_AXIS]);
        settings.setValue(Manul_Save_Point_Array_Point_Z_AXIS_Key, Global::Manul_Save_Point[i].Point[Z_AXIS]);
        settings.setValue(Manul_Save_Point_Array_Point_O_AXIS_Key, Global::Manul_Save_Point[i].Point[O_AXIS]);
    }
    settings.endArray();

    settings.endGroup();    //点恢复出厂设置结束

    //程序恢复出厂设置开始
    settings.beginGroup("PARAMETER_PROGRAM");

    settings.beginWriteArray("ProgramInf_Array");
    for(i=0; i < SAVEPROGRAMNUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(Free_Program_Save_Array_Flag_Key, Global::Free_Program_Save[i].Flag);
        settings.setValue(Free_Program_Save_Array_Name_Key, Global::Free_Program_Save[i].Name);
        settings.setValue(Free_Program_Save_Array_Name2_Key, Global::Free_Program_Save[i].Name2);
        settings.setValue(Free_Program_Save_Array_Name3_Key, Global::Free_Program_Save[i].Name3);
        settings.setValue(Free_Program_Save_Array_Num_Key, Global::Free_Program_Save[i].Num);
    }
    settings.endArray();

    settings.endGroup();    //程序恢复出厂设置结束

    //运行程序恢复出厂设置开始
    settings.beginGroup("PARAMETER_PROGRAM_OPERATE");

    settings.setValue(Free_Program_Operate_Flag_Key, Global::Free_Program_Operate.Flag);
    settings.setValue(Free_Program_Operate_Code_Key, Global::Free_Program_Operate.Code);
    settings.setValue(Free_Program_Operate_Name_Key, Global::Free_Program_Operate.Name);
    settings.setValue(Free_Program_Operate_Name2_Key, Global::Free_Program_Operate.Name2);
    settings.setValue(Free_Program_Operate_Name3_Key, Global::Free_Program_Operate.Name3);
    settings.setValue(Free_Program_Operate_Num_Key, Global::Free_Program_Operate.Num);

    settings.beginWriteArray("ProgOperate_Array");
    for(i=0; i < LARGESTPROGRAMNUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(Free_Program_Operate_Program_Array_Flag_Key, Global::Free_Program_Operate.Program[i].Flag);
        settings.setValue(Free_Program_Operate_Program_Array_List_Key, Global::Free_Program_Operate.Program[i].List);
        settings.setValue(Free_Program_Operate_Program_Array_Order_Key, Global::Free_Program_Operate.Program[i].Order);
        settings.setValue(Free_Program_Operate_Program_Array_Key_Key, Global::Free_Program_Operate.Program[i].Key);
        settings.setValue(Free_Program_Operate_Program_Array_Value1_Key, Global::Free_Program_Operate.Program[i].Value1);
        settings.setValue(Free_Program_Operate_Program_Array_Value2_Key, Global::Free_Program_Operate.Program[i].Value2);
        settings.setValue(Free_Program_Operate_Program_Array_Value3_Key, Global::Free_Program_Operate.Program[i].Value3);
    }
    settings.endArray();

    settings.endGroup();    //运行程序恢复出厂设置结束

    //码垛名称恢复初始值开始
    settings.beginGroup("PARAMETER_MD_NAME");

    settings.beginWriteArray("MDName_Array");
    for(i=0; i < MD_GOOD_PAGE_PER; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(sMD_Name_Array_Name_Key,  Global::sMD_Name[i].Name );
        settings.setValue(sMD_Name_Array_Name1_Key, Global::sMD_Name[i].Name1);
        settings.setValue(sMD_Name_Array_Name2_Key, Global::sMD_Name[i].Name2);
    }
    settings.endArray();

    settings.endGroup();    //码垛名称恢复初始值结束

    //码垛参数恢复初始值开始
    settings.beginGroup("PARAMETER_MD_PARA");

    settings.setValue(sMD_Parameter_stackType_Key, Global::sMD_Parameter.stackType);
    settings.setValue(sMD_Parameter_property_Key, Global::sMD_Parameter.property);
    settings.setValue(sMD_Parameter_revolveMode_Key, Global::sMD_Parameter.revolveMode);
    settings.setValue(sMD_Parameter_gasPort_Key, Global::sMD_Parameter.gasPort);
    settings.setValue(sMD_Parameter_topSwitch_Key, Global::sMD_Parameter.topSwitch);
    settings.setValue(sMD_Parameter_goodheight_Key, Global::sMD_Parameter.goodheight);
    settings.setValue(sMD_Parameter_stackLayer_Key, Global::sMD_Parameter.stackLayer);
    settings.setValue(sMD_Parameter_loopLayer_Key, Global::sMD_Parameter.loopLayer);
    settings.setValue(sMD_Parameter_cycleStartLayer_Key, Global::sMD_Parameter.cycleStartLayer);

    settings.beginWriteArray("layerNum_Array");
    for(i=0; i < LOOP_MAX; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(sMD_Parameter_layerNum_Key, Global::sMD_Parameter.layerNum[i]);
    }
    settings.endArray();

    settings.beginWriteArray("goodOffset_Array");
    for(i=0; i < AXIS_NUM; i++)
    {
        settings.setArrayIndex(i);
        settings.setValue(sMD_Parameter_goodOffset_Key, Global::sMD_Parameter.goodOffset[i]);
    }
    settings.endArray();

    settings.setValue(sMD_Parameter_horNum_Key, Global::sMD_Parameter.horNum);
    settings.setValue(sMD_Parameter_verNum_Key, Global::sMD_Parameter.verNum);

    settings.endGroup();    //码垛参数恢复初始值结束
    settings.sync();
    sync();
}


//同步数据，读取配置文件mydata.ini的参数值，并写入对应结构体参数中
void ParaConfig::Config_DateSyc()
{
    QSettings settings(SysConfigPath, QSettings::IniFormat);
    int size = 0;
    int i = 0;
    //软限位参数读取开始
    settings.beginGroup("PARAMETER_SOFT_LIMIT");

    size = settings.beginReadArray("LimPosPara_Array");
    for(i = 0; i < size; i++)
    {
        settings.setArrayIndex(i);
        Global::Robot_SoftLimit[i].Left_Limit = settings.value(Robot_SoftLimit_Array_Left_Limit_Key).toUInt();
        Global::Robot_SoftLimit[i].Right_Limit = settings.value(Robot_SoftLimit_Array_Right_Limit_Key).toUInt();
        Global::Robot_SoftLimit[i].Switch_Limit = settings.value(Robot_SoftLimit_Array_Switch_Limit_Key).toUInt();
    }
    settings.endArray();

    Global::Robot_SoftDistance.MaxDistance = settings.value(Robot_SoftDistance_MaxDistance_Key).toUInt();
    Global::Robot_SoftDistance.MinDistance = settings.value(Robot_SoftDistance_MinDistance_Key).toUInt();

    settings.endGroup();    //软限位参数读取结束

    //安全区参数读取开始
    settings.beginGroup("PARAMETER_SAFE_AREA");

    size = settings.beginReadArray("SafeAreaPara_Array");
    for(i=0; i < size; i++)
    {
        settings.setArrayIndex(i);
        Global::Robot_Safe_Area[i].SafeArea_Switch = settings.value(Robot_Safe_Area_Array_SafeArea_Switch_Key).toUInt();    //启用-关闭
        Global::Robot_Safe_Area[i].X_Left = settings.value(Robot_Safe_Area_Array_X_Left_Key).toUInt();             //左X
        Global::Robot_Safe_Area[i].Z_Left = settings.value(Robot_Safe_Area_Array_Z_Left_Key).toUInt();             //左Z
        Global::Robot_Safe_Area[i].X_Right = settings.value(Robot_Safe_Area_Array_X_Right_Key).toUInt();            //右X
        Global::Robot_Safe_Area[i].Z_Right = settings.value(Robot_Safe_Area_Array_Z_Right_Key).toUInt();            //右Z
    }
    settings.endArray();

    settings.endGroup();    //安全区参数读取结束

    //功能设定参数读取开始
    settings.beginGroup("PARAMETER_FUCTION_SET");

    //功能设定--物联网设定参数读取
    Global::Internet_Parameter.Switch = settings.value( Internet_Parameter_Switch_Key).toUInt();

    //功能设定--机械手设定参数读取
    Global::JXS_Parameter.Axis = settings.value(JXS_Parameter_Axis_Key).toUInt();
    Global::JXS_Parameter.Origin = settings.value(JXS_Parameter_Origin_Key).toUInt();
    Global::JXS_Parameter.SpeedLevel = settings.value(JXS_Parameter_SpeedLevel_Key).toUInt();
    Global::JXS_Parameter.AlarmSignal = settings.value(JXS_Parameter_AlarmSignal_Key).toUInt();
    Global::JXS_Parameter.Outport_Orign = settings.value(JXS_Parameter_Outport_Orign_Key).toUInt();
    Global::JXS_Parameter.Outport_Run = settings.value(JXS_Parameter_Outport_Run_Key).toUInt();
    Global::JXS_Parameter.Outport_Pause = settings.value(JXS_Parameter_Outport_Pause_Key).toUInt();
    Global::JXS_Parameter.Outport_Stop = settings.value(JXS_Parameter_Outport_Stop_Key).toUInt();
    Global::JXS_Parameter.LCcirculation = settings.value(JXS_Parameter_LCcirculation_Key).toUInt();

    size = settings.beginReadArray("Alarm_Switch_Array");
    for(i=0; i < size; i++)
    {
        settings.setArrayIndex(i);
        Global::JXS_Parameter.Alarm_Switch[i] = settings.value(JXS_Parameter_Alarm_Switch_Key).toUInt();
    }
    settings.endArray();

    Global::JXS_Parameter.MDgripSwitch = settings.value(JXS_Parameter_MDgripSwitch_Key).toUInt();

    size = settings.beginReadArray("MDgripPort_Array");
    for(i=0; i < size; i++)
    {
        settings.setArrayIndex(i);
        Global::JXS_Parameter.MDgripPort[i] = settings.value(JXS_Parameter_MDgripPort_Key).toUInt();
    }
    settings.endArray();

    size = settings.beginReadArray("OutputAssociate_Array");
    for(i=0; i < size; i++)
    {
        settings.setArrayIndex(i);
        Global::JXS_Parameter.OutputAssociate[i] = settings.value(JXS_Parameter_OutputAssociate_Key).toUInt();
    }
    settings.endArray();

    Global::JXS_Parameter.ZAxsisAvoidace = settings.value(JXS_Parameter_ZAxsisAvoidace_Key).toUInt();
    Global::JXS_Parameter.ZAxsisLimit = settings.value(JXS_Parameter_ZAxsisLimit_Key).toUInt();

    size = settings.beginReadArray("OriginPara_Array");
    for(i=0; i < size; i++)
    {
        settings.setArrayIndex(i);
        Global::JXS_Parameter.OriginOffset[i] = settings.value(JXS_Parameter_OriginOffset_Key).toUInt();
        Global::JXS_Parameter.OriginDiretion[i] = settings.value(JXS_Parameter_OriginDiretion_Key).toUInt();
        Global::JXS_Parameter.OriginSpeed[i] = settings.value(JXS_Parameter_OriginSpeed_Key).toUInt();
        Global::JXS_Parameter.OriginPosition[i] = settings.value(JXS_Parameter_OriginPosition_Key).toUInt();
        Global::JXS_Parameter.A_Circle_Pulse[i] = settings.value(JXS_Parameter_A_Circle_Pulse_Key).toUInt();
        Global::JXS_Parameter.A_Circle_Distance[i] = settings.value(JXS_Parameter_A_Circle_Distance_Key).toUInt();
        Global::JXS_Parameter.AccAcc[i] = settings.value(JXS_Parameter_AccAcc_Key).toUInt();
        Global::JXS_Parameter.Accelerate.Time[i] = settings.value(JXS_Parameter_Accelerate_Time_Key).toUInt();
        Global::JXS_Parameter.JDZ_AllowError[i] = settings.value(JXS_Parameter_JDZ_AllowError_Key).toUInt();
    }
    settings.endArray();

    //功能设定--笛卡尔坐标系参数读取
    size = settings.beginReadArray("lengthPara_Array");
    for(i=0; i < size; i++)
    {
        settings.setArrayIndex(i);
        Global::sCartesian_Para.length[i] = settings.value(sCartesian_Para_length_Key).toUInt();
    }
    settings.endArray();

    Global::sCartesian_Para.maxSpeed = settings.value(sCartesian_Para_maxSpeed_Key).toUInt();
    Global::sCartesian_Para.accTime = settings.value(sCartesian_Para_accTime_Key).toUInt();
    Global::sCartesian_Para.accAcc = settings.value(sCartesian_Para_accAcc_Key).toUInt();
    Global::sCartesian_Para.carCoordSwitch = settings.value(sCartesian_Para_carCoordSwitch_Key).toUInt();
    Global::sCartesian_Para.MDCoordType = settings.value(sCartesian_Para_MDCoordType_Key).toUInt();

    size = settings.beginReadArray("axisTypePara_Array");
    for(i=0; i < size; i++)
    {
        settings.setArrayIndex(i);
        Global::sCartesian_Para.axisType[i] = settings.value(sCartesian_Para_axisType_Key).toUInt();
    }
    settings.endArray();

    Global::sCartesian_Para.pitchLength = settings.value(sCartesian_Para_pitchLength_Key).toUInt();

    size = settings.beginReadArray("axisPara_Array");
    for(i=0; i < size; i++)
    {
        settings.setArrayIndex(i);
        Global::sCartesian_Para.axisBackMinDir[i] = settings.value(sCartesian_Para_axisBackMinDir_Key).toUInt();
        Global::sCartesian_Para.axisInterpFlag[i] = settings.value(sCartesian_Para_axisInterpFlag_Key).toUInt();
    }
    settings.endArray();

    //功能设定--生产参数设定参数读取
    Global::SC_Parameter.RW_Num = settings.value(SC_Parameter_RW_Num_Key).toUInt();
    Global::SC_Parameter.SC_Num = settings.value(SC_Parameter_SC_Num_Key).toUInt();
    Global::SC_Parameter.CJ_Num = settings.value(SC_Parameter_CJ_Num_Key).toUInt();
    Global::SC_Parameter.JG_Num = settings.value(SC_Parameter_JG_Num_Key).toUInt();
    Global::SC_Parameter.LJ_Num = settings.value(SC_Parameter_LJ_Num_Key).toUInt();
    Global::SC_Parameter.NG_Num = settings.value(SC_Parameter_NG_Num_Key).toUInt();
    Global::sMD_RunPara.mdMethed = settings.value(sMD_RunPara_mdMethed_Key).toUInt();
    Global::sMD_RunPara.totalGood = settings.value(sMD_RunPara_totalGood_Key).toUInt();
    Global::sMD_RunPara.startGood = settings.value(sMD_RunPara_startGood_Key).toUInt();
    Global::sMD_RunPara.curGood = settings.value(sMD_RunPara_curGood_Key).toUInt();
    Global::sMD_RunPara.curLayer = settings.value(sMD_RunPara_curLayer_Key).toUInt();
    Global::sMD_RunPara.curNum = settings.value(sMD_RunPara_curNum_Key).toUInt();
    Global::sMD_RunPara.startName.Name = settings.value(sMD_RunPara_startName_Name_Key).toUInt();
    Global::sMD_RunPara.startName.Name1 = settings.value(sMD_RunPara_startName_Name1_Key).toUInt();
    Global::sMD_RunPara.startName.Name2 = settings.value(sMD_RunPara_startName_Name2_Key).toUInt();
    Global::sMD_RunPara.curName.Name = settings.value(sMD_RunPara_curName_Name_Key).toUInt();
    Global::sMD_RunPara.curName.Name1 = settings.value(sMD_RunPara_curName_Name1_Key).toUInt();
    Global::sMD_RunPara.curName.Name2 = settings.value(sMD_RunPara_curName_Name2_Key).toUInt();

    //功能设定--配方参数读取
    size = settings.beginReadArray("PFPara_Array");
    for(i=0; i < size; i++)
    {
        settings.setArrayIndex(i);
        Global::PF_Parameter.pfIOnum[i] = settings.value(PF_Parameter_pfIOnum_Key).toUInt();
        Global::PF_Parameter.pfGood[i] = settings.value(PF_Parameter_pfGood_Key).toUInt();
        Global::PF_Parameter.pfSwitch[i] = settings.value(PF_Parameter_pfSwitch_Key).toUInt();
    }
    settings.endArray();

    //功能设定--用户变量读取
    size = settings.beginReadArray("USERPara_Array");
    for(i=0; i < size; i++)
    {
        settings.setArrayIndex(i);
        Global::USER_Parameter.USER_Name1[i] = settings.value(USER_Parameter_USER_Name1_Key).toUInt();
        Global::USER_Parameter.USER_Name2[i] = settings.value(USER_Parameter_USER_Name2_Key).toUInt();
        Global::USER_Parameter.USER_Name3[i] = settings.value(USER_Parameter_USER_Name3_Key).toUInt();
        Global::USER_Parameter.INIT_Num[i] = settings.value(USER_Parameter_INIT_Num_Key).toUInt();
        Global::USER_Parameter.CURR_Num[i] = settings.value(USER_Parameter_CURR_Num_Key).toUInt();
        Global::USER_Parameter.ELEC_RESET[i] = settings.value(USER_Parameter_ELEC_RESET_Key).toUInt();
        Global::USER_Parameter.START_RESET[i] = settings.value(USER_Parameter_START_RESET_Key).toUInt();
    }
    settings.endArray();

    //功能设定--绝对值参数读取
    Global::JDZ_Parameter.Switch = settings.value(JDZ_Parameter_Switch_Key).toUInt();
    Global::JDZ_Parameter.Server = settings.value(JDZ_Parameter_Server_Key).toUInt();
    Global::JDZ_Parameter.Resolu = settings.value(JDZ_Parameter_Resolu_Key).toUInt();

    size = settings.beginReadArray("JDZPara_Array");
    for(i=0; i < size; i++)
    {
        settings.setArrayIndex(i);
        Global::JDZ_Parameter.Circle_Pluse[i] = settings.value(JDZ_Parameter_Circle_Pluse_Key).toUInt();
        Global::JDZ_Parameter.Motion_Dir[i] = settings.value(JDZ_Parameter_Motion_Dir_Key).toUInt();
        Global::JDZ_Parameter.OriginSetting[i] = settings.value(JDZ_Parameter_OriginSetting_Key).toUInt();
    }
    settings.endArray();

    settings.endGroup();    //功能设定参数读取结束

    //输入复用开关参数读取开始
    settings.beginGroup("PARAMETER_INPUT_SWITCH_SET");

    //X18-X29特殊IO参数读取
    size = settings.beginReadArray("TempIOPara_Array");
    for(i=0; i < size; i++)
    {
        settings.setArrayIndex(i);
        Global::Temp_IO_Switch_Parameter[i] = settings.value(Temp_IO_Switch_Parameter_Key).toUInt();
    }
    settings.endArray();

    //输入IO设定参数读取
    size = settings.beginReadArray("IONamePara_Array");
    for(i=0; i < size; i++)
    {
        settings.setArrayIndex(i);
        Global::IO_Name_Parameter_Input[i].Name = settings.value(IO_Name_Parameter_Input_Array_Name_Key).toUInt();
        Global::IO_Name_Parameter_Input[i].Name1 = settings.value(IO_Name_Parameter_Input_Array_Name1_Key).toUInt();
        Global::IO_Name_Parameter_Input[i].Name2 = settings.value(IO_Name_Parameter_Input_Array_Name2_Key).toUInt();
    }
    settings.endArray();

    settings.endGroup();    //输入复用开关参数读取结束

    //输入IO检测参数读取开始
    settings.beginGroup("PARAMETER_IO_DETECT_SET");

    size = settings.beginReadArray("InputDetect_Array");
    for(i=0; i < size; i++)
    {
        settings.setArrayIndex(i);
        Global::IO_Parameter[i].minTime = settings.value(IO_Parameter_Array_minTime_Key).toUInt();
        Global::IO_Parameter[i].maxTime = settings.value(IO_Parameter_Array_maxTime_Key).toUInt();
        Global::IO_Parameter[i].Switch = settings.value(IO_Parameter_Array_Switch_Key).toUInt();
    }
    settings.endArray();

    settings.endGroup();    //输入IO检测参数读取结束

    //输出复用开关参数读取开始
    settings.beginGroup("PARAMETER_OUTPUT_SWITCH_SET");

    //Y22-Y23特殊IO参数读取
    size = settings.beginReadArray("TempOUTPara_Array");
    for(i=0; i < size; i++)
    {
        settings.setArrayIndex(i);
        Global::Temp_OUT_Switch_Parameter[i] = settings.value(Temp_OUT_Switch_Parameter_Key).toUInt();
    }
    settings.endArray();

    //输出IO设定参数读取
    size = settings.beginReadArray("IONamePara_Array");
    for(i=0; i < size; i++)
    {
        settings.setArrayIndex(i);
        Global::IO_Name_Parameter[i].Name = settings.value(IO_Name_Parameter_Array_Name_Key).toUInt();
        Global::IO_Name_Parameter[i].Name1 = settings.value(IO_Name_Parameter_Array_Name1_Key).toUInt();
        Global::IO_Name_Parameter[i].Name2 = settings.value(IO_Name_Parameter_Array_Name2_Key).toUInt();
    }
    settings.endArray();

    settings.endGroup();    //输出复用开关读取结束

    //输出复位选择参数读取开始
    settings.beginGroup("PARAMETER_OUTPUT_SET");

    //输出IO复位选择设定参数读取
    size = settings.beginReadArray("IOResetSel_Array");
    for(i=0; i < size; i++)
    {
        settings.setArrayIndex(i);
        if((i<24)||(i>27))
        {
            Global::IO_Reset_Select[i].BeforeOrigin = settings.value(IO_Reset_Select_Array_BeforeOrigin_Key).toUInt();
            Global::IO_Reset_Select[i].AfterOrigin = settings.value(IO_Reset_Select_Array_AfterOrigin_Key).toUInt();
            Global::IO_Reset_Select[i].CommonAlarm = settings.value(IO_Reset_Select_Array_CommonAlarm_Key).toUInt();
            Global::IO_Reset_Select[i].EmergeAlarm = settings.value(IO_Reset_Select_Array_EmergeAlarm_Key).toUInt();
            Global::IO_Reset_Select[i].Pause = settings.value(IO_Reset_Select_Array_Pause_Key).toUInt();
            Global::IO_Reset_Select[i].Stop = settings.value(IO_Reset_Select_Array_Stop_Key).toUInt();
        }
    }
    settings.endArray();

    settings.endGroup();    //输出IO复位选择参数读取结束

    //存储点参数读取开始
    settings.beginGroup("PARAMETER_SAVEPOINT");

    size = settings.beginReadArray("ManulSavePoint_Array");
    for(i=0; i < size; i++)
    {
        settings.setArrayIndex(i);
        Global::Manul_Save_Point[i].Flag = settings.value(Manul_Save_Point_Array_Flag_Key).toUInt();
        Global::Manul_Save_Point[i].Name = settings.value(Manul_Save_Point_Array_Name_Key).toUInt();
        Global::Manul_Save_Point[i].Name2= settings.value(Manul_Save_Point_Array_Name2_Key).toUInt();
        Global::Manul_Save_Point[i].Name3 = settings.value(Manul_Save_Point_Array_Name3_Key).toUInt();
        Global::Manul_Save_Point[i].Point[X_AXIS] = settings.value(Manul_Save_Point_Array_Point_X_AXIS_Key).toUInt();
        Global::Manul_Save_Point[i].Point[L_AXIS] = settings.value(Manul_Save_Point_Array_Point_Y_AXIS_Key).toUInt();
        Global::Manul_Save_Point[i].Point[Z_AXIS] = settings.value(Manul_Save_Point_Array_Point_Z_AXIS_Key).toUInt();
        Global::Manul_Save_Point[i].Point[O_AXIS] = settings.value(Manul_Save_Point_Array_Point_O_AXIS_Key).toUInt();
    }
    settings.endArray();

    settings.endGroup();    //存储点参数读取结束

    //存储程序参数读取开始
    settings.beginGroup("PARAMETER_PROGRAM");

    size = settings.beginReadArray("ProgramInf_Array");
    for(i=0; i < size; i++)
    {
        settings.setArrayIndex(i);
        Global::Free_Program_Save[i].Flag = settings.value(Free_Program_Save_Array_Flag_Key).toUInt();
        Global::Free_Program_Save[i].Name = settings.value(Free_Program_Save_Array_Name_Key).toUInt();
        Global::Free_Program_Save[i].Name2 = settings.value(Free_Program_Save_Array_Name2_Key).toUInt();
        Global::Free_Program_Save[i].Name3 = settings.value(Free_Program_Save_Array_Name3_Key).toUInt();
        Global::Free_Program_Save[i].Num = settings.value(Free_Program_Save_Array_Num_Key).toUInt();
    }
    settings.endArray();

    settings.endGroup();    //存储程序参数读取结束

    //运行程序参数读取开始
    settings.beginGroup("PARAMETER_PROGRAM_OPERATE");

    Global::Free_Program_Operate.Flag = settings.value(Free_Program_Operate_Flag_Key).toUInt();
    Global::Free_Program_Operate.Code = settings.value(Free_Program_Operate_Code_Key).toUInt();
    Global::Free_Program_Operate.Name = settings.value(Free_Program_Operate_Name_Key).toUInt();
    Global::Free_Program_Operate.Name2 = settings.value(Free_Program_Operate_Name2_Key).toUInt();
    Global::Free_Program_Operate.Name3 = settings.value(Free_Program_Operate_Name3_Key).toUInt();
    Global::Free_Program_Operate.Num = settings.value(Free_Program_Operate_Num_Key).toUInt();

    size = settings.beginReadArray("ProgOperate_Array");
    for(i=0; i < size; i++)
    {
        settings.setArrayIndex(i);
        Global::Free_Program_Operate.Program[i].Flag = settings.value(Free_Program_Operate_Program_Array_Flag_Key).toUInt();
        Global::Free_Program_Operate.Program[i].List = settings.value(Free_Program_Operate_Program_Array_List_Key).toUInt();
        Global::Free_Program_Operate.Program[i].Order = settings.value(Free_Program_Operate_Program_Array_Order_Key).toUInt();
        Global::Free_Program_Operate.Program[i].Key= settings.value(Free_Program_Operate_Program_Array_Key_Key).toUInt();
        Global::Free_Program_Operate.Program[i].Value1 = settings.value(Free_Program_Operate_Program_Array_Value1_Key).toUInt();
        Global::Free_Program_Operate.Program[i].Value2 = settings.value(Free_Program_Operate_Program_Array_Value2_Key).toUInt();
        Global::Free_Program_Operate.Program[i].Value3 = settings.value(Free_Program_Operate_Program_Array_Value3_Key).toUInt();
    }
    settings.endArray();

    settings.endGroup();    //运行程序参数读取结束

    //码垛名称参数读取开始
    settings.beginGroup("PARAMETER_MD_NAME");

    size = settings.beginReadArray("MDName_Array");
    for(i=0; i < size; i++)
    {
        settings.setArrayIndex(i);
        Global::sMD_Name[i].Name = settings.value(sMD_Name_Array_Name_Key).toUInt();
        Global::sMD_Name[i].Name1 = settings.value(sMD_Name_Array_Name1_Key).toUInt();
        Global::sMD_Name[i].Name2 = settings.value(sMD_Name_Array_Name2_Key).toUInt();
    }
    settings.endArray();

    settings.endGroup();    //码垛名称参数读取结束

    //码垛参数读取开始
    settings.beginGroup("PARAMETER_MD_PARA");

    Global::sMD_Parameter.stackType = settings.value(sMD_Parameter_stackType_Key).toUInt();
    Global::sMD_Parameter.property = settings.value(sMD_Parameter_property_Key).toUInt();
    Global::sMD_Parameter.revolveMode = settings.value(sMD_Parameter_revolveMode_Key).toUInt();
    Global::sMD_Parameter.gasPort = settings.value(sMD_Parameter_gasPort_Key).toUInt();
    Global::sMD_Parameter.topSwitch = settings.value(sMD_Parameter_topSwitch_Key).toUInt();
    Global::sMD_Parameter.goodheight = settings.value(sMD_Parameter_goodheight_Key).toUInt();
    Global::sMD_Parameter.stackLayer = settings.value(sMD_Parameter_stackLayer_Key).toUInt();
    Global::sMD_Parameter.loopLayer = settings.value(sMD_Parameter_loopLayer_Key).toUInt();
    Global::sMD_Parameter.cycleStartLayer = settings.value(sMD_Parameter_cycleStartLayer_Key).toUInt();

    size = settings.beginReadArray("layerNum_Array");
    for(i=0; i < size; i++)
    {
        settings.setArrayIndex(i);
        Global::sMD_Parameter.layerNum[i] = settings.value(sMD_Parameter_layerNum_Key).toUInt();
    }
    settings.endArray();

    size = settings.beginReadArray("goodOffset_Array");
    for(i=0; i < size; i++)
    {
        settings.setArrayIndex(i);
        Global::sMD_Parameter.goodOffset[i] = settings.value(sMD_Parameter_goodOffset_Key).toUInt();
    }
    settings.endArray();

    Global::sMD_Parameter.horNum = settings.value(sMD_Parameter_horNum_Key).toUInt();
    Global::sMD_Parameter.verNum = settings.value(sMD_Parameter_verNum_Key).toUInt();

    settings.endGroup();    //码垛参数读取结束
}
