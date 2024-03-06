#include "sysset.h"
#include "ui_sysset.h"
#include "mainWidget.h"

SysSet::SysSet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SysSet)
{
    ui->setupUi(this);

    pWidget = static_cast<Widget*>(parent);

    init();

    //返回设置子界面
    connect(ui->Btn_back, &QPushButton::clicked, this, [=](){
        if(ui->stackedWidget->currentIndex() == ValParaSet_id)  //绝对值参数暂存
        {
            Global::JDZ_Temp_Save();
        }
        else if(ui->stackedWidget->currentIndex() == ArmSet_id) //机械手设置暂存
        {
            Global::JXS_Temp_Save();
        }
        else if(ui->stackedWidget->currentIndex() == AxisParaSet_id) //原点参数暂存
        {
            Global::OP_Temp_Save();
        }
        else if(ui->stackedWidget->currentIndex() == User_id) //用户变量暂存
        {
            Global::USER_Temp_Save();
        }

        pWidget->backSetPage();       
    });

    //参数保存
    connect(ui->Btn_save, &QPushButton::clicked, this, [=](){
        if(ui->stackedWidget->currentIndex() == ValParaSet_id)  //绝对值参数保存
        {
            pWidget->JDZParaSaveAuthority();
        }
        else if(ui->stackedWidget->currentIndex() == ArmSet_id) //机械手设置保存
        {
            ui->stackedWidget_tip->setCurrentIndex(0);
            ui->stackedWidget_tip->show();

            Global::JXS_Para_Save();

            Global::f_SendSystemPara();
            Global::gs_Reflash_Fuction_JXS = TRUE;
            Refresh_Fuction_JXS();
            ui->stackedWidget_tip->hide();
        }
        else if(ui->stackedWidget->currentIndex() == AxisParaSet_id) //原点参数保存
        {
            ui->stackedWidget_tip->setCurrentIndex(0);
            ui->stackedWidget_tip->show();

            Global::OP_Para_Save();

            Global::f_SendSystemPara();         //原点参数下发(需更改其对应函数！！！！！！)
            for(int i=0; i<AXIS_NUM; i++)
            {
                Global::Axis_Step_Coefficient[i].Step_Coefficient = (float)Global::JXS_Parameter.A_Circle_Pulse[i]/((float)Global::JXS_Parameter.A_Circle_Distance[i]/1000);
            }
            SET::gs_Refresh_OrignParameter = TRUE;
            Refresh_OrignParameter();

            ui->stackedWidget_tip->hide();
        }
        else if(ui->stackedWidget->currentIndex() == User_id) //用户变量保存
        {
            ui->stackedWidget_tip->setCurrentIndex(0);
            ui->stackedWidget_tip->show();

            Global::USER_Para_Save();

            Global::f_SendSystemPara();         //用户变量参数下发(需更改其对应函数！！！！！！)
            Global::gs_Reflash_Save_USER = TRUE;
            Reflash_Save_USER();
            ui->stackedWidget_tip->hide();
        }

    });

    //功能设定--机械手设置
    connect(ui->Btn_armSet, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(ArmSet_id);
        ui->Btn_save->show();

        Global::JXS_Temp_Save();

        Global::gs_Reflash_Fuction_JXS = TRUE;
        SET::gs_Refresh_Associate = TRUE;
        SET::gs_Refresh_Avoidace = TRUE;

        Refresh_Fuction_JXS();
        Refresh_Associate();
        Refresh_Avoidace();
        ui->Btn_stackIO->setText(MD_gripSwitch[Global::Temp_JXS_Parameter.MDgripSwitch]);
    });

    //功能设定--机械手设置--外部回零端口
    connect(ui->Btn_externalReturn0, &QPushButton::clicked, this, [=](){
        if(Global::Temp_JXS_Parameter.Outport_Orign == 1)
        {
            Global::Temp_JXS_Parameter.Outport_Orign = 0;
        }
        else
        {
            Global::Temp_JXS_Parameter.Outport_Orign = 1;
        }
        SET::gs_Refresh_Outport = TRUE;
        Refresh_Outport();
    });

    //功能设定--机械手设置--外部启动端口
    connect(ui->Btn_externalStart, &QPushButton::clicked, this, [=](){
        if(Global::Temp_JXS_Parameter.Outport_Run == 2)
        {
            Global::Temp_JXS_Parameter.Outport_Run = 0;
        }
        else
        {
            Global::Temp_JXS_Parameter.Outport_Run = 2;
        }
        SET::gs_Refresh_Outport = TRUE;
        Refresh_Outport();
    });

    //功能设定--机械手设置--外部暂停端口
    connect(ui->Btn_externalPause, &QPushButton::clicked, this, [=](){
        if(Global::Temp_JXS_Parameter.Outport_Pause == 3)
        {
            Global::Temp_JXS_Parameter.Outport_Pause = 0;
        }
        else
        {
            Global::Temp_JXS_Parameter.Outport_Pause = 3;
        }
        SET::gs_Refresh_Outport = TRUE;
        Refresh_Outport();
    });

    //功能设定--机械手设置--外部停止端口
    connect(ui->Btn_externalStop, &QPushButton::clicked, this, [=](){
        if(Global::Temp_JXS_Parameter.Outport_Stop == 4)
        {
            Global::Temp_JXS_Parameter.Outport_Stop = 0;
        }
        else
        {
            Global::Temp_JXS_Parameter.Outport_Stop = 4;
        }
        SET::gs_Refresh_Outport = TRUE;
        Refresh_Outport();
    });

    //功能设定--机械手设置--伺服报警信号高低电平
    connect(ui->Btn_servoAlarm, &QPushButton::clicked, this, [=](){
        Global::Temp_JXS_Parameter.AlarmSignal = Global::ValSwitch(Global::Temp_JXS_Parameter.AlarmSignal);
        SET::gs_Refresh_AlarmSignal = TRUE;
        Refresh_AlarmSignal();
    });

    //功能设定--机械手设置--X/Y/Z/O伺服报警开关
    for(int i = 0; i < AXIS_NUM; i++)
    {
        connect(Btn_Axis_Servo.at(i), &QPushButton::clicked, this, [=](){
            Global::Temp_JXS_Parameter.Alarm_Switch[i] = Global::ValSwitch(Global::Temp_JXS_Parameter.Alarm_Switch[i]);
            SET::gs_Refresh_AlarmSignal = TRUE;
            Refresh_AlarmSignal();
        });
    }

    //功能设定--机械手设置--码垛IO开关
    connect(ui->Btn_stackIO, &QPushButton::clicked, this, [=](){
        if(Global::Temp_JXS_Parameter.MDgripSwitch == 1)
        {
            Global::Temp_JXS_Parameter.MDgripSwitch = 0;
            for(int i=0; i<MDgrip_Num; i++)
            {
                Global::Temp_JXS_Parameter.MDgripPort[i]=0;	//关闭功能则恢复默认，无效
                //对应夹爪点颜色变化
            }
        }
        else
        {
            Global::Temp_JXS_Parameter.MDgripSwitch = 1;
        }
        Global::gs_Refresh_MD_Circulation = TRUE;
        Refresh_MD_Circulation();
    });

    //功能设定--机械手设置--码垛IO序号
    connect(ui->Btn_num, &QPushButton::clicked, this, [=](){
        if(Global::Temp_JXS_Parameter.MDgripSwitch == 1)
        {
            Global::Temp_JXS_Parameter.MDgripNum = 1 + Global::Temp_JXS_Parameter.MDgripNum;
            if((Global::Temp_JXS_Parameter.MDgripNum & 0x0f) == MDgrip_Num)
            {
                Global::Temp_JXS_Parameter.MDgripNum = 0;
            }
        }
        Global::gs_Refresh_MD_Circulation = TRUE;
        Refresh_MD_Circulation();
    });

    //功能设定--机械手设置--码垛IO端口
    connect(ui->Btn_port, &QPushButton::clicked, this, [=](){
        if(Global::Temp_JXS_Parameter.MDgripSwitch == 1)
        {
            Global::gs_MDgripSetFlag = TRUE;	//标志设置码垛端口
        }
        Global::gs_IO_Detect_Display_Refresh = TRUE;
        Global::gs_Refresh_MD_Circulation = TRUE;
        pWidget->SignalSet_ui->IO_Detect_Display_Refresh();
        Refresh_MD_Circulation();
    });

    //功能设定--机械手设置--Y0Y1关联输出
    connect(ui->Btn_Y0Y1, &QPushButton::clicked, this, [=](){
        Global::Temp_JXS_Parameter.OutputAssociate[0] = Global::ValSwitch(Global::Temp_JXS_Parameter.OutputAssociate[0]);
        SET::gs_Refresh_Associate = TRUE;
        Refresh_Associate();
    });

    //功能设定--机械手设置--Y2Y3关联输出
    connect(ui->Btn_Y2Y3, &QPushButton::clicked, this, [=](){
        Global::Temp_JXS_Parameter.OutputAssociate[0] = Global::ValSwitch(Global::Temp_JXS_Parameter.OutputAssociate[1]);
        SET::gs_Refresh_Associate = TRUE;
        Refresh_Associate();
    });

    //功能设定--机械手设置--Z轴防撞
    connect(ui->Btn_ZavoidHit, &QPushButton::clicked, this, [=](){
        if(Global::Temp_JXS_Parameter.ZAxsisAvoidace==1)
        {
            Global::Temp_JXS_Parameter.ZAxsisAvoidace = 0;
            Global::Temp_JXS_Parameter.ZAxsisLimit =  0;
        }
        else
        {
            Global::Temp_JXS_Parameter.ZAxsisAvoidace = 1;
        }
        SET::gs_Refresh_Avoidace = TRUE;
        Refresh_Avoidace();
    });

    //功能设定--机械手设置--Z轴下限
    connect(ui->Edit_ZavoidHitLength, &QLineEdit::editingFinished, this, [=](){
        if(Global::Temp_JXS_Parameter.ZAxsisAvoidace==1)
        {
            Global::Temp_JXS_Parameter.ZAxsisLimit = ui->Edit_ZavoidHitLength->text().toUInt();
        }
        else
        {
            Global::Temp_JXS_Parameter.ZAxsisLimit = 0;
        }
        SET::gs_Refresh_Avoidace = TRUE;
        Refresh_Avoidace();
    });


    //功能设定--原点参数设置
    connect(ui->Btn_axisParaSet, &QPushButton::clicked, this ,[=](){
        ui->stackedWidget->setCurrentIndex(AxisParaSet_id);
        ui->Btn_save->show();

        Global::Axis_Parameter_Select = X_AXIS;
        Global::Temp_JXS_Parameter.OriginPosition[X_AXIS] = Global::JXS_Parameter.OriginPosition[X_AXIS];
        Global::Temp_JXS_Parameter.OriginSpeed[X_AXIS] = Global::JXS_Parameter.OriginSpeed[X_AXIS];
        Global::Temp_JXS_Parameter.OriginOffset[X_AXIS] = Global::JXS_Parameter.OriginOffset[X_AXIS];
        Global::Temp_JXS_Parameter.OriginDiretion[X_AXIS] = Global::JXS_Parameter.OriginDiretion[X_AXIS];
        Global::Temp_JXS_Parameter.A_Circle_Pulse[X_AXIS] = Global::JXS_Parameter.A_Circle_Pulse[X_AXIS];
        Global::Temp_JXS_Parameter.A_Circle_Distance[X_AXIS] = Global::JXS_Parameter.A_Circle_Distance[X_AXIS];
        SET::gs_Refresh_OrignParameter = TRUE;
        Refresh_OrignParameter();
    });

    //功能设定--原点参数设置 X轴\Y轴\Z轴\O轴
    for(int i = 0; i < AXIS_NUM; i++)
    {
        connect(Btn_Axis_Sel.at(i), &QPushButton::clicked, this ,[=](){
            Global::Axis_Parameter_Select = i;
            Global::Temp_JXS_Parameter.OriginPosition[i] = Global::JXS_Parameter.OriginPosition[i];
            Global::Temp_JXS_Parameter.OriginSpeed[i] = Global::JXS_Parameter.OriginSpeed[i];
            Global::Temp_JXS_Parameter.OriginOffset[i] = Global::JXS_Parameter.OriginOffset[i];
            Global::Temp_JXS_Parameter.OriginDiretion[i] = Global::JXS_Parameter.OriginDiretion[i];
            Global::Temp_JXS_Parameter.A_Circle_Pulse[i] = Global::JXS_Parameter.A_Circle_Pulse[i];
            Global::Temp_JXS_Parameter.A_Circle_Distance[i] = Global::JXS_Parameter.A_Circle_Distance[i];
            Global::Temp_JXS_Parameter.Accelerate.Time[i] = Global::JXS_Parameter.Accelerate.Time[i];
            Global::Temp_JXS_Parameter.AccAcc[i] = Global::JXS_Parameter.AccAcc[i];
            Global::Temp_JXS_Parameter.JDZ_AllowError[i] = Global::JXS_Parameter.JDZ_AllowError[i];
            SET::gs_Refresh_OrignParameter = TRUE;
            Refresh_OrignParameter();
        });
    }

    //功能设定--原点参数设置--回零方向
    connect(ui->Btn_back0Diret, &QPushButton::clicked, this, [=](){
        Global::Temp_JXS_Parameter.OriginDiretion[Global::Axis_Parameter_Select] = Global::ValSwitch(Global::Temp_JXS_Parameter.OriginDiretion[Global::Axis_Parameter_Select]);
        ui->Btn_back0Diret->setText(Origin_Direction[Global::Temp_JXS_Parameter.OriginDiretion[Global::Axis_Parameter_Select]]);
    });

    //功能设定--原点参数设置--回零速度
    connect(ui->Edit_back0Speed, &QLineEdit::editingFinished, this, [=](){
        Global::Temp_JXS_Parameter.OriginSpeed[Global::Axis_Parameter_Select] = static_cast<u8>(ui->Edit_back0Speed->text().toUInt());
    });

    //功能设定--原点参数设置--原点位置
    connect(ui->Btn_originPos, &QPushButton::clicked, this, [=](){
        Global::Temp_JXS_Parameter.OriginPosition[Global::Axis_Parameter_Select] = Global::ValSwitch(Global::Temp_JXS_Parameter.OriginPosition[Global::Axis_Parameter_Select]);
        ui->Btn_originPos->setText(Origin_Position[Global::Temp_JXS_Parameter.OriginPosition[Global::Axis_Parameter_Select]]);
    });

    //功能设定--原点参数设置--原点偏移
    connect(ui->Edit_originOffest, &QLineEdit::editingFinished, this, [=](){
        Global::Temp_JXS_Parameter.OriginOffset[Global::Axis_Parameter_Select] = ui->Edit_originOffest->text().toUInt();
    });

    //功能设定--原点参数设置--单圈脉冲
    connect(ui->Edit_loopPulse, &QLineEdit::editingFinished, this, [=](){
        Global::Temp_JXS_Parameter.A_Circle_Pulse[Global::Axis_Parameter_Select] = ui->Edit_loopPulse->text().toUInt();
    });

    //功能设定--原点参数设置--单圈距离
    connect(ui->Edit_lapDistance, &QLineEdit::editingFinished, this, [=](){
        Global::Temp_JXS_Parameter.A_Circle_Distance[Global::Axis_Parameter_Select] = ui->Edit_lapDistance->text().toUInt();
    });

    //功能设定--原点参数设置--加速度时间
    connect(ui->Edit_speedUpTime, &QLineEdit::editingFinished, this, [=](){
        Global::Temp_JXS_Parameter.Accelerate.Time[Global::Axis_Parameter_Select] = ui->Edit_speedUp->text().toUShort();
    });

    //功能设定--原点参数设置--加加速
    connect(ui->Edit_speedUp, &QLineEdit::editingFinished, this, [=](){
        Global::Temp_JXS_Parameter.AccAcc[Global::Axis_Parameter_Select] = static_cast<u8>(ui->Edit_speedUp->text().toUInt());
    });

    //功能设定--原点参数设置--动作确认
    connect(ui->Edit_actionConfirm, &QLineEdit::editingFinished, this, [=](){
        Global::Temp_JXS_Parameter.JDZ_AllowError[Global::Axis_Parameter_Select] = ui->Edit_actionConfirm->text().toUShort();
    });

    //功能设定--绝对值参数设定
    connect(ui->Btn_valueParaSet, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(ValParaSet_id);
        ui->Btn_save->show();

        Global::JDZ_Temp_Save();

        Global::gs_Refresh_JDZOriginSetting_Text = TRUE;
        Global::gs_Reflash_Fuction_JDZ = TRUE;

        Refresh_JDZOriginSetting_Text();
        Reflash_Fuction_JDZ(0);
    });

    //绝对值参数设定--功能开关
    connect(ui->Btn_On_Off, &QPushButton::clicked, this, [=](){
        Global::Temp_JDZ_Parameter.Switch = Global::ValSwitch(Global::Temp_JDZ_Parameter.Switch);
        Global::gs_Reflash_Fuction_JDZ = TRUE;
        Reflash_Fuction_JDZ(0);
    });

    //绝对值参数设定--编码器分辨率
    connect(ui->Btn_encoder, &QPushButton::clicked, this, [=](){
        Global::Temp_JDZ_Parameter.Resolu++;
        if(Global::Temp_JDZ_Parameter.Resolu > 3)
        {
            Global::Temp_JDZ_Parameter.Resolu = 0;
        }
        Global::gs_Reflash_Fuction_JDZ = TRUE;
        Reflash_Fuction_JDZ(0);
    });

    for(int i = 0; i < AXIS_NUM; i++)
    {
        //i轴运动方向
        connect(Btn_Axis_Dirt.at(i), &QPushButton::clicked, this, [=](){
            if(Global::JDZ_Parameter.Switch == 1)
            {
                Global::Temp_JDZ_Parameter.Motion_Dir[i] = Global::ValSwitch(Global::Temp_JDZ_Parameter.Motion_Dir[i]);
                Global::gs_Reflash_Fuction_JDZ = TRUE;
                Reflash_Fuction_JDZ(0);
            }
        });
        //i轴机械回零
        connect(Btn_Axis_Return0.at(i), &QPushButton::clicked, this, [=](){
            if(Global::JDZ_Parameter.Switch == 1)
            {
                Global::JDZ_Machine_Ori_Axis_Num = i;
                SET::gs_Refresh_JDZ_Axis = TRUE;
                Refresh_JDZ_Axis(4);
            }
        });
        //i轴原点设置
        connect(Btn_Axis_OriginSet.at(i), &QPushButton::clicked, this, [=](){
            if(Global::JDZ_Parameter.Switch == 1)
            {
                Global::JDZ_Origin_Setting_Axis_Num = i;
                SET::gs_Refresh_JDZ_Axis = TRUE;
                Refresh_JDZ_Axis(5);
            }
        });
        //i轴重置原点
        connect(Btn_Axis_OriginRst.at(i), &QPushButton::clicked, this, [=](){
            if(Global::JDZ_Parameter.Switch == 1)
            {
                Global::JDZ_Origin_Resetting_Axis_Num = i;
                SET::gs_Refresh_JDZ_Axis = TRUE;
                Refresh_JDZ_Axis(6);
            }
        });
    }

    connect(ui->Btn_machback0OK, &QPushButton::clicked, this, [=](){ //机械回零确认
        if(Global::Robot_Status == ACTION_STOP && Global::g_Robot_Error_Flag == 0)
        {//如果机械手状态为停止
//            Order_Temp[0]=MACHINEORIGIN;              					//机械回零
//            Order_Temp[1]=JDZ_Machine_Ori_Axis_Num;              		//机械回零轴 1-4
//            USART1_SendData(2,ROBOT_ENABLE_A_ORIGIN,&Order_Temp[0]);
            Global::Robot_Origined = FALSE;                  					//机械手回原点
            ui->stackedWidget_tip->setCurrentIndex(2);
            Global::Get_JDZ_Information = MACHINE_ORIGIN_STATUS;
        }
        else
        {
//            LCD_Popup_Windows = PW_1_STOPROBOT;							//弹出提示框-请先停止机器
        }
        ui->stackedWidget_tip->hide();
    });

    connect(ui->Btn_machback0Cancel, &QPushButton::clicked, this, [=](){ //机械回零取消
        Global::gs_Reflash_Fuction_JDZ = TRUE;
        Reflash_Fuction_JDZ(0);
        ui->stackedWidget_tip->hide();
    });

    connect(ui->Btn_originSetOK, &QPushButton::clicked, this, [=](){ //设置原点确认
        if(Global::Robot_Status == ACTION_STOP && Global::g_Robot_Error_Flag == 0)
        {//如果机械手状态为停止
//            Order_Temp[0]=ORIGNSETTING;              					//设置原点
//            Order_Temp[1]=JDZ_Origin_Setting_Axis_Num;              	//设置原点轴 1-4
//            USART1_SendData(2,ROBOT_ENABLE_A_ORIGIN,&Order_Temp[0]);
            Global::Get_JDZ_Information = ORIGIN_SETTING_STATUS;
        }
        ui->stackedWidget_tip->hide();
    });
    connect(ui->Btn_originSetCancel, &QPushButton::clicked, this, [=](){ //设置原点取消
        Global::gs_Reflash_Fuction_JDZ = TRUE;
        Reflash_Fuction_JDZ(0);
        ui->stackedWidget_tip->hide();
    });

    connect(ui->Btn_originRstOK, &QPushButton::clicked, this, [=](){ //重置原点确认
        if(Global::Robot_Status == ACTION_STOP && Global::g_Robot_Error_Flag == 0)
        {//如果机械手状态为停止
//            Order_Temp[0]=ORIGNRESETTING;              					//重置原点
//            Order_Temp[1]=JDZ_Origin_Resetting_Axis_Num;              	//重置原点轴 1-4
//            USART1_SendData(2,ROBOT_ENABLE_A_ORIGIN,&Order_Temp[0]);
            Global::Get_JDZ_Information = ORIGIN_RESETTING_STATUS;
        }
        ui->stackedWidget_tip->hide();
    });

    connect(ui->Btn_originRstCancel, &QPushButton::clicked, this, [=](){ //重置原点取消
        Global::gs_Reflash_Fuction_JDZ = TRUE;
        Reflash_Fuction_JDZ(0);
        ui->stackedWidget_tip->hide();
    });

    //功能设定--用户变量设定
    connect(ui->Btn_userVarSet, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(UserVarSet_id);
        ui->Btn_save->show();

//        Order_Temp[0] = USER_CURNUM;
//        USART1_SendData(1,WATCH_COMMAND,&Order_Temp[0]);
        Global::USER_Temp_Save();

        Global::gs_Reflash_Fuction_USER = TRUE;
        Reflash_Fuction_USER();
    });

    for(int i = 0; i < USER_NUM; i++)
    {
        //USER--名称
        connect(Eidt_USER_Name.at(i), &QLineEdit::editingFinished, this, [=](){
            Global::USER_PARAMETER(USER_Name, i);
            Reflash_Fuction_USER();
        });
        //USER--初始值
        connect(Eidt_USER_InitVal.at(i), &QLineEdit::editingFinished, this, [=](){
            Global::USER_PARAMETER(USER_Init, i);
            Reflash_Fuction_USER();
        });
        //USER--当前值
        connect(Eidt_USER_CurVal.at(i), &QLineEdit::editingFinished, this, [=](){
            Global::USER_PARAMETER(USER_Curr, i);
            Reflash_Fuction_USER();
        });
        //USER--开机置0
        connect(Btn_USER_BootRst.at(i), &QPushButton::clicked, this, [=](){
            Global::USER_PARAMETER(USER_Elec, i);
            Reflash_Fuction_USER();
        });
        //USER--启动置0
        connect(Btn_USER_StartRst.at(i), &QPushButton::clicked, this, [=](){
            Global::USER_PARAMETER(USER_Start, i);
            Reflash_Fuction_USER();
        });
    }

    //功能设定--笛卡尔坐标系设定
    connect(ui->Btn_coordSet, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(CoordSet_id);
        ui->Btn_save->hide();
        Global::m_Refresh_Cartesian = TRUE;
        Refresh_Cartesian();
    });

    //笛卡尔坐标系设定--笛卡尔坐标系开关
    connect(ui->Btn_crood, &QPushButton::clicked, this, [=](){
        Global::sCartesian_Para.carCoordSwitch = Global::ValSwitch(Global::sCartesian_Para.carCoordSwitch);
        ui->Btn_crood->setText(CarCoord_Switch[Global::sCartesian_Para.carCoordSwitch]);
        Global::f_send_Cartesian();
    });

    //功能设定--笛卡尔坐标系设定--机械臂1
    connect(ui->Edit_armL1, &QLineEdit::editingFinished, this, [=](){
        Global::sCartesian_Para.length[0] = ui->Edit_armL1->text().toUInt();
        Global::f_send_Cartesian();
    });

    //功能设定--笛卡尔坐标系设定--机械臂2
    connect(ui->Edit_armL2, &QLineEdit::editingFinished, this, [=](){
        Global::sCartesian_Para.length[1] = ui->Edit_armL2->text().toUInt();
        Global::f_send_Cartesian();
    });

    //功能设定--笛卡尔坐标系设定--丝杆螺距
    connect(ui->Edit_pitch, &QLineEdit::editingFinished, this, [=](){
        Global::sCartesian_Para.pitchLength = ui->Edit_pitch->text().toUInt();
        Global::f_send_Cartesian();
    });

    //功能设定--笛卡尔坐标系设定--笛卡尔最大速度
    connect(ui->Edit_maxSpeed, &QLineEdit::editingFinished, this, [=](){
        Global::sCartesian_Para.maxSpeed = ui->Edit_maxSpeed->text().toUShort();
        Global::f_send_Cartesian();
    });

    //功能设定--笛卡尔坐标系设定--笛卡尔加速时间
    connect(ui->Edit_SpeedUpTime, &QLineEdit::editingFinished, this, [=](){
        Global::sCartesian_Para.accTime = ui->Edit_SpeedUpTime->text().toUShort();
        Global::f_send_Cartesian();
    });

    //功能设定--笛卡尔坐标系设定--笛卡尔加加速
    connect(ui->Edit_pSpeedUp, &QLineEdit::editingFinished, this, [=](){
        Global::sCartesian_Para.accAcc = ui->Edit_pSpeedUp->text().toUShort();
        Global::f_send_Cartesian();
    });

    for(int i = 0; i < AXIS_NUM; i++)
    {
        //笛卡尔坐标系设定--轴类型
        connect(Btn_Axis_Type.at(i), &QPushButton::clicked, this, [=](){
            Global::sCartesian_Para.axisType[i] = Global::ValSwitch(Global::sCartesian_Para.axisType[i]);
            Btn_Axis_Type.at(i)->setText(AXISType_Switch[Global::sCartesian_Para.axisType[i]]);
            Global::f_send_Cartesian();
        });

        //笛卡尔坐标系设定--轴联动开关
        connect(Btn_Axis_Link.at(i), &QPushButton::clicked, this, [=](){
            Global::sCartesian_Para.axisInterpFlag[i] = Global::ValSwitch(Global::sCartesian_Para.axisInterpFlag[i]);
            Btn_Axis_Link.at(i)->setText(PF_Switch[Global::sCartesian_Para.axisInterpFlag[i]]);
            Global::f_send_Cartesian();
        });

        //笛卡尔坐标系设定--轴回最小坐标方向
        connect(Btn_Axis_Back.at(i), &QPushButton::clicked, this, [=](){
            Global::sCartesian_Para.axisBackMinDir[i]= Global::ValSwitch(Global::sCartesian_Para.axisBackMinDir[i]);
            Btn_Axis_Back.at(i)->setText(MD_axisBackMinDir[Global::sCartesian_Para.axisBackMinDir[i]]);
            Global::f_send_Cartesian();
        });
    }
}

SysSet::~SysSet()
{
    delete ui;
}

void SysSet::init()
{
    Btn_Axis_Servo<<ui->Btn_armSetX<<ui->Btn_armSetY<<ui->Btn_armSetZ<<ui->Btn_armSetO;
    Btn_Axis_Type<<ui->Btn_Xtype<<ui->Btn_Ytype<<ui->Btn_Ztype<<ui->Btn_Otype;
    Btn_Axis_Link<<ui->Btn_Xlink<<ui->Btn_Ylink<<ui->Btn_Zlink<<ui->Btn_Olink;
    Btn_Axis_Back<<ui->Btn_Xback<<ui->Btn_Yback<<ui->Btn_Zback<<ui->Btn_Oback;
    Btn_Axis_Sel<<ui->Btn_axisSetX<<ui->Btn_axisSetY<<ui->Btn_axisSetZ<<ui->Btn_axisSetO;
    Btn_Axis_Dirt<<ui->Btn_Xdirection<<ui->Btn_Ydirection<<ui->Btn_Zdirection<<ui->Btn_Odirection;
    Btn_Axis_Return0<<ui->Btn_XmechReturn0<<ui->Btn_YmechReturn0<<ui->Btn_ZmechReturn0<<ui->Btn_OmechReturn0;
    Btn_Axis_OriginSet<<ui->Btn_XoriginSet<<ui->Btn_YoriginSet<<ui->Btn_ZoriginSet<<ui->Btn_OoriginSet;
    Btn_Axis_OriginRst<<ui->Btn_XoriginRst<<ui->Btn_YoriginRst<<ui->Btn_ZoriginRst<<ui->Btn_OoriginRst;

    Eidt_USER_Name<<ui->Edit_name1<<ui->Edit_name2<<ui->Edit_name3<<ui->Edit_name4
                  <<ui->Edit_name5<<ui->Edit_name6<<ui->Edit_name7<<ui->Edit_name8;
    Eidt_USER_InitVal<<ui->Edit_initVal1<<ui->Edit_initVal2<<ui->Edit_initVal3<<ui->Edit_initVal4
                     <<ui->Edit_initVal5<<ui->Edit_initVal6<<ui->Edit_initVal7<<ui->Edit_initVal8;
    Eidt_USER_CurVal<<ui->Edit_curVal1<<ui->Edit_curVal2<<ui->Edit_curVal3<<ui->Edit_curVal4
                    <<ui->Edit_curVal5<<ui->Edit_curVal6<<ui->Edit_curVal7<<ui->Edit_curVal8;
    Btn_USER_BootRst<<ui->Btn_bootRst1<<ui->Btn_bootRst2<<ui->Btn_bootRst3<<ui->Btn_bootRst4
                    <<ui->Btn_bootRst5<<ui->Btn_bootRst6<<ui->Btn_bootRst7<<ui->Btn_bootRst8;
    Btn_USER_StartRst<<ui->Btn_startRst1<<ui->Btn_startRst2<<ui->Btn_startRst3<<ui->Btn_startRst4
                     <<ui->Btn_startRst5<<ui->Btn_startRst6<<ui->Btn_startRst7<<ui->Btn_startRst8;

    QStringList strList1;
    QStringList strList2;
    QStringList strList3;
    strList1<<MD_CoordType[0]<<MD_CoordType[1]<<MD_CoordType[2]<<MD_CoordType[3];
    ui->comboBox_machType->addItems(strList1);

    strList2<<FucSet_Axis[0]<<FucSet_Axis[1]<<FucSet_Axis[2]<<FucSet_Axis[3]<<FucSet_Axis[4]
            <<FucSet_Axis[5]<<FucSet_Axis[6]<<FucSet_Axis[7]<<FucSet_Axis[8];
    ui->comboBox_mechAxisNum->addItems(strList2);

    strList3<<Servo_selection[0]<<Servo_selection[1]<<Servo_selection[2]<<Servo_selection[3]
            <<Servo_selection[4]<<Servo_selection[5]<<Servo_selection[6]<<Servo_selection[7];
    ui->comboBox_servoSel->addItems(strList3);


    ui->stackedWidget->setCurrentIndex(ArmSet_id);
    ui->stackedWidget_tip->hide();
}

//绝对值参数保存中
void SysSet::JDZ_Tips1()
{
    ui->stackedWidget_tip->setCurrentIndex(0);
    ui->stackedWidget_tip->show();
}

//重新启动界面
void SysSet::JDZ_Tips2()
{
    ui->stackedWidget_tip->setCurrentIndex(1);
    ui->stackedWidget_tip->show();
}

//绝对值参数修改取消
void SysSet::JDZ_ModBack()
{
    ui->stackedWidget->setCurrentIndex(ValParaSet_id);
    ui->stackedWidget_tip->hide();
}

//机械手设置页面端口选择显示
void SysSet::JXS_Set_dispPort(u8 IOPort)
{
    pWidget->changeSetPage(System_id);
    ui->stackedWidget->setCurrentIndex(ArmSet_id);
    Global::Temp_JXS_Parameter.MDgripPort[Global::Temp_JXS_Parameter.MDgripNum] = IOPort+1;
    Global::gs_MDgripSetFlag = FALSE;
    Refresh_MD_Circulation();
}

//功能设定--机械手设定刷新
void SysSet::Refresh_Fuction_JXS()
{
    //显示轴个数和回原点方式
    ui->comboBox_mechAxisNum->setCurrentIndex(static_cast<int>(Global::JXS_Parameter.Axis));
    ui->Btn_returnOriginWay->setText(FucSet_Origin[Global::JXS_Parameter.Origin]);
    //显示外部端口的设置
    ui->Btn_externalPause->setText(Outport_Switch[Global::JXS_Parameter.Outport_Pause]);
    ui->Btn_externalReturn0->setText(Outport_Switch[Global::JXS_Parameter.Outport_Orign]);
    ui->Btn_externalStart->setText(Outport_Switch[Global::JXS_Parameter.Outport_Run]);
    ui->Btn_externalStop->setText(Outport_Switch[Global::JXS_Parameter.Outport_Stop]);

    ui->Btn_servoAlarm->setText(Alarm_Signal_Dis[Global::JXS_Parameter.AlarmSignal]);   //显示伺服报警电平
    //显示伺服报警开关
    ui->Btn_armSetX->setText(Alarm_Switch_Dis[Global::JXS_Parameter.Alarm_Switch[0]]);
    ui->Btn_armSetY->setText(Alarm_Switch_Dis[Global::JXS_Parameter.Alarm_Switch[1]]);
    ui->Btn_armSetZ->setText(Alarm_Switch_Dis[Global::JXS_Parameter.Alarm_Switch[2]]);
    ui->Btn_armSetO->setText(Alarm_Switch_Dis[Global::JXS_Parameter.Alarm_Switch[3]]);
}

//功能设定--关联输出刷新
void SysSet::Refresh_Associate()
{
    ui->Btn_Y0Y1->setText(Function_switch[(Global::Temp_JXS_Parameter.OutputAssociate[0] & 0x0f)]);
    ui->Btn_Y2Y3->setText(Function_switch[(Global::Temp_JXS_Parameter.OutputAssociate[1] & 0x0f)]);
}

//功能设定--Z轴防撞刷新
void SysSet::Refresh_Avoidace()
{
    ui->Btn_ZavoidHit->setText(ZAxis_Avoidance[(Global::Temp_JXS_Parameter.ZAxsisAvoidace & 0x0f)]);
    ui->Edit_ZavoidHitLength->setText(QString::number(Global::Temp_JXS_Parameter.ZAxsisLimit));

}

//功能设定--机械手设定--回零方式刷新
void SysSet::Refresh_Origin_Method()
{
    ui->Btn_returnOriginWay->setText(FucSet_Origin[Global::Temp_JXS_Parameter.Origin]);
}

//功能设定--机械手设定--外部端口设定刷新
void SysSet::Refresh_Outport()
{
    ui->Btn_externalPause->setText(Outport_Switch[Global::Temp_JXS_Parameter.Outport_Pause]);
    ui->Btn_externalReturn0->setText(Outport_Switch[Global::Temp_JXS_Parameter.Outport_Orign]);
    ui->Btn_externalStart->setText(Outport_Switch[Global::Temp_JXS_Parameter.Outport_Run]);
    ui->Btn_externalStop->setText(Outport_Switch[Global::Temp_JXS_Parameter.Outport_Stop]);
}

//功能设定--机械手设定--伺服报警电平及开关刷新
void SysSet::Refresh_AlarmSignal()
{
    ui->Btn_servoAlarm->setText(Alarm_Signal_Dis[Global::Temp_JXS_Parameter.AlarmSignal]);
    ui->Btn_armSetX->setText(Alarm_Signal_Dis[Global::Temp_JXS_Parameter.Alarm_Switch[0]]);
    ui->Btn_armSetY->setText(Alarm_Signal_Dis[Global::Temp_JXS_Parameter.Alarm_Switch[1]]);
    ui->Btn_armSetZ->setText(Alarm_Signal_Dis[Global::Temp_JXS_Parameter.Alarm_Switch[2]]);
    ui->Btn_armSetO->setText(Alarm_Signal_Dis[Global::Temp_JXS_Parameter.Alarm_Switch[3]]);
}

//刷新码垛夹爪IO
void SysSet::Refresh_MD_Circulation()
{
    ui->Btn_stackIO->setText(MD_gripSwitch[Global::Temp_JXS_Parameter.MDgripSwitch]);
    if(Global::Temp_JXS_Parameter.MDgripSwitch ==0)	//功能关闭
    {
        ui->Btn_num->setText(MD_InvalidGrip);	//无效
        ui->Btn_port->setText(MD_InvalidGrip);
    }
    else
    {
        ui->Btn_num->setText(MD_gripNum[Global::Temp_JXS_Parameter.MDgripNum & 0x0f]);
        if(Global::Temp_JXS_Parameter.MDgripPort[Global::Temp_JXS_Parameter.MDgripNum] == 0)	//端口无效
        {
            ui->Btn_port->setText(MD_InvalidGrip);
        }
        else
        {
            ui->Btn_port->setText(OutputIO_Detect_IO[Global::Temp_JXS_Parameter.MDgripPort[Global::Temp_JXS_Parameter.MDgripNum]-1]);
        }
    }
    pWidget->StackSet_ui->Refresh_MD_Circulation();
    pWidget->ManualPage_ui->Refresh_MD_Circulation();
    pWidget->FreeProg_ui->Refresh_MD_Circulation();
}

//功能设定--原点参数设定刷新
void SysSet::Refresh_OrignParameter()
{
    ui->Btn_back0Diret->setText(Origin_Direction[Global::JXS_Parameter.OriginDiretion[Global::Axis_Parameter_Select]]); //回零方向
    ui->Edit_originOffest->setText(QString::number(Global::JXS_Parameter.OriginOffset[Global::Axis_Parameter_Select]));  //原点偏移
    ui->Edit_back0Speed->setText(QString::number(Global::JXS_Parameter.OriginSpeed[Global::Axis_Parameter_Select]));    //回零速度
    ui->Edit_loopPulse->setText(QString::number(Global::JXS_Parameter.A_Circle_Pulse[Global::Axis_Parameter_Select]));     //单圈脉冲
    ui->Edit_lapDistance->setText(QString::number(Global::JXS_Parameter.A_Circle_Distance[Global::Axis_Parameter_Select]));   //单圈距离
    ui->Btn_originPos->setText(Origin_Position[Global::JXS_Parameter.OriginPosition[Global::Axis_Parameter_Select]]);  //原点位置

    ui->Edit_speedUpTime->setText(QString::number(Global::JXS_Parameter.Accelerate.Time[Global::Axis_Parameter_Select]));   //加速度时间
    ui->Edit_speedUp->setText(QString::number(Global::JXS_Parameter.AccAcc[Global::Axis_Parameter_Select]));       //加加速
    ui->Edit_actionConfirm->setText(QString::number(Global::JXS_Parameter.JDZ_AllowError[Global::Axis_Parameter_Select])); //动作确认
}

//原点设置
void SysSet::Refresh_JDZOriginSetting_Text()
{
    for(int i = 0; i < AXIS_NUM; i++)
    {
        Btn_Axis_OriginSet.at(i)->setText(JDZ_OriginSetting_Dis[Global::JDZ_Parameter.OriginSetting[i]]);
    }
}

//功能设定--绝对值参数刷新
void SysSet::Reflash_Fuction_JDZ(int flag)
{
    if(flag == 1)   //绝对值参数保存刷新
    {
        ui->Btn_On_Off->setText(Function_switch[Global::JDZ_Parameter.Switch]);    //功能开关
        ui->comboBox_servoSel->setCurrentIndex(static_cast<int>(Global::JDZ_Parameter.Server));      //伺服选择
        ui->Btn_encoder->setText(Encoder_resolution[Global::JDZ_Parameter.Resolu]);       //编码器分辨率
    }
    else if(flag == 0)  //绝对值参数设定刷新
    {
        ui->Btn_On_Off->setText(Function_switch[Global::Temp_JDZ_Parameter.Switch]);    //功能开关
        ui->comboBox_servoSel->setCurrentIndex(static_cast<int>(Global::Temp_JDZ_Parameter.Server));      //伺服选择
        ui->Btn_encoder->setText(Encoder_resolution[Global::Temp_JDZ_Parameter.Resolu]);       //编码器分辨率
    }
    //运动方向
    for(int i = 0; i < AXIS_NUM; i++)
    {
        Btn_Axis_Dirt.at(i)->setText(Move_Direction[Global::Temp_JDZ_Parameter.Motion_Dir[i]]);
    }
}

//功能设定--绝对值参数保存刷新
void SysSet::Reflash_Save_JDZ()
{
//    ui->Btn_On_Off->setText(Function_switch[Global::JDZ_Parameter.Switch]);    //功能开关
//    ui->comboBox_servoSel->setCurrentIndex(static_cast<int>(Global::JDZ_Parameter.Server));      //伺服选择
//    ui->comboBox_encoder->setCurrentIndex(static_cast<int>(Global::JDZ_Parameter.Resolu));       //编码器分辨率
//    //运动方向
//    for(int i = 0; i < AXIS_NUM; i++)
//    {
//        Btn_Axis_Dirt.at(i)->setText(Move_Direction[Global::Temp_JDZ_Parameter.Motion_Dir[i]]);
//    }
}

void SysSet::Refresh_JDZ_Axis(int dialog_page)
{  
    if(dialog_page == 4)
    {
        ui->stackedWidget_tip->setCurrentIndex(dialog_page);
        ui->label_axisMachback0->setText(JDZ_Axis[Global::JDZ_Machine_Ori_Axis_Num]);   //机械原点回零轴显示
        ui->stackedWidget_tip->show();
    }
    else if(dialog_page == 5)
    {
        ui->stackedWidget_tip->setCurrentIndex(dialog_page);
        ui->label_axisOriginRst->setText(JDZ_Axis[Global::JDZ_Origin_Setting_Axis_Num]);    //原点设置
        ui->stackedWidget_tip->show();
    }
    else if(dialog_page == 6)
    {
        ui->stackedWidget_tip->setCurrentIndex(dialog_page);
        ui->label_axisOriginSet->setText(JDZ_Axis[Global::JDZ_Origin_Resetting_Axis_Num]);  //原点重置回零轴显示
        ui->stackedWidget_tip->show();
    }
}

//功能设定--用户变量设定刷新
void SysSet::Reflash_Fuction_USER()
{
    for(int i=0; i<USER_NUM; i++)
    {
        Global::Parameter_StringChang(Global::Temp_Display_Data, 0, Global::Temp_USER_Parameter.USER_Name1[i],
                                  Global::Temp_USER_Parameter.USER_Name2[i], Global::Temp_USER_Parameter.USER_Name3[i]);
        Eidt_USER_Name.at(i)->setText(Global::u8toqstr(Global::Temp_Display_Data, 10));
        Eidt_USER_InitVal.at(i)->setText(QString::number(Global::Temp_USER_Parameter.INIT_Num[i]));
        Eidt_USER_CurVal.at(i)->setText(QString::number(Global::Temp_USER_Parameter.CURR_Num[i]));
        Btn_USER_BootRst.at(i)->setText(ELECRESET_Switch[Global::Temp_USER_Parameter.ELEC_RESET[i]]);
        Btn_USER_StartRst.at(i)->setText(STARTRESET_Switch[Global::Temp_USER_Parameter.START_RESET[i]]);
    }
}

//功能设定--用户变量设定刷新 保存后刷新
void SysSet::Reflash_Save_USER()
{
    for(int i=0; i<USER_NUM; i++)
    {
        Global::Parameter_StringChang(Global::Temp_Display_Data, 0, Global::USER_Parameter.USER_Name1[i],
                                  Global::USER_Parameter.USER_Name2[i], Global::USER_Parameter.USER_Name3[i]);
        Eidt_USER_Name.at(i)->setText(Global::u8toqstr(Global::Temp_Display_Data, 10));
        Eidt_USER_InitVal.at(i)->setText(QString::number(Global::USER_Parameter.INIT_Num[i]));
        Eidt_USER_CurVal.at(i)->setText(QString::number(Global::USER_Parameter.CURR_Num[i]));
        Btn_USER_BootRst.at(i)->setText(ELECRESET_Switch[Global::USER_Parameter.ELEC_RESET[i]]);
        Btn_USER_StartRst.at(i)->setText(STARTRESET_Switch[Global::USER_Parameter.START_RESET[i]]);
    }
}

//功能设定--坐标系参数刷新
void SysSet::Refresh_Cartesian()
{
    ui->Btn_crood->setText(CarCoord_Switch[Global::sCartesian_Para.carCoordSwitch]);
    ui->Edit_armL1->setText(QString::number(Global::sCartesian_Para.length[0]));
    ui->Edit_armL2->setText(QString::number(Global::sCartesian_Para.length[1]));
    ui->Edit_pitch->setText(QString::number(Global::sCartesian_Para.pitchLength));
    ui->Edit_maxSpeed->setText(QString::number(Global::sCartesian_Para.maxSpeed));
    ui->Edit_SpeedUpTime->setText(QString::number(Global::sCartesian_Para.accTime));
    ui->Edit_pSpeedUp->setText(QString::number(Global::sCartesian_Para.accAcc));

    ui->Btn_Xtype->setText(AXISType_Switch[Global::sCartesian_Para.axisType[0]]);
    ui->Btn_Ytype->setText(AXISType_Switch[Global::sCartesian_Para.axisType[1]]);
    ui->Btn_Ztype->setText(AXISType_Switch[Global::sCartesian_Para.axisType[2]]);
    ui->Btn_Otype->setText(AXISType_Switch[Global::sCartesian_Para.axisType[3]]);

    ui->Btn_Xlink->setText(PF_Switch[Global::sCartesian_Para.axisInterpFlag[0]]);
    ui->Btn_Ylink->setText(PF_Switch[Global::sCartesian_Para.axisInterpFlag[1]]);
    ui->Btn_Zlink->setText(PF_Switch[Global::sCartesian_Para.axisInterpFlag[2]]);
    ui->Btn_Olink->setText(PF_Switch[Global::sCartesian_Para.axisInterpFlag[3]]);

    ui->Btn_Xback->setText(MD_axisBackMinDir[Global::sCartesian_Para.axisBackMinDir[0]]);
    ui->Btn_Yback->setText(MD_axisBackMinDir[Global::sCartesian_Para.axisBackMinDir[1]]);
    ui->Btn_Zback->setText(MD_axisBackMinDir[Global::sCartesian_Para.axisBackMinDir[2]]);
    ui->Btn_Oback->setText(MD_axisBackMinDir[Global::sCartesian_Para.axisBackMinDir[3]]);
}

//笛卡尔坐标系设定--当前机器类型改变
void SysSet::on_comboBox_machType_currentIndexChanged(int index)
{
    Global::sCartesian_Para.MDCoordType = index;
    Global::g_AxiseCarteType = 0;
    Global::gs_AxiseCarteType_Refresh = TRUE;
    Global::gs_Refresh_Speed_Para = TRUE;
    Global::gs_Point_Display_Refresh = TRUE;

    pWidget->AxiseCarteType_Refresh(Global::gs_AxiseCarteType_Refresh);
    pWidget->f_Axis_Position_Refresh(1);
    Global::f_send_Cartesian();
}

//机械手设置--轴个数
void SysSet::on_comboBox_mechAxisNum_currentIndexChanged(int index)
{
    //根据新的轴个数，设置新的回原点方式
    switch (index) {
    case 0://FAN_X
        Global::Temp_JXS_Parameter.Axis = FAN_X;
        Global::Temp_JXS_Parameter.Origin = FOM_X;
        break;
    case 1://FAN_Z
        Global::Temp_JXS_Parameter.Axis = FAN_Z;
        Global::Temp_JXS_Parameter.Origin = FOM_Z;
        break;
    case 2://FAN_Y
        Global::Temp_JXS_Parameter.Axis = FAN_Y;
        Global::Temp_JXS_Parameter.Origin = FOM_Y;
        break;
    case 3://FAN_O
        Global::Temp_JXS_Parameter.Axis = FAN_O;
        Global::Temp_JXS_Parameter.Origin = FOM_O;
        break;
    case 4://FAN_X_Y
        Global::Temp_JXS_Parameter.Axis = FAN_X_Y;
        Global::Temp_JXS_Parameter.Origin = FOM_Y_X;
        break;
    case 5://FAN_X_Z
        Global::Temp_JXS_Parameter.Axis = FAN_X_Z;
        Global::Temp_JXS_Parameter.Origin = FOM_Z_X;
        break;
    case 6://FAN_X_O
        Global::Temp_JXS_Parameter.Axis = FAN_X_O;
        Global::Temp_JXS_Parameter.Origin = FOM_O_X;
        break;
    case 7://FAN_X_Z_L
        Global::Temp_JXS_Parameter.Axis = FAN_X_Z_L;
        Global::Temp_JXS_Parameter.Origin = FOM_Z_X_L;
        break;
    case 8://FAN_X_Z_L_O
        Global::Temp_JXS_Parameter.Axis = FAN_X_Z_L_O;
        Global::Temp_JXS_Parameter.Origin = FOM_Z_L_X_O;
        break;
    default:
        break;
    }
    SET::gs_Refresh_Origin_Method = TRUE;
    Refresh_Origin_Method();
}

//机械手设置--回原点方式设置
void SysSet::on_Btn_returnOriginWay_clicked()
{
    if(Global::Temp_JXS_Parameter.Origin == FOM_Y_X)
    {
        Global::Temp_JXS_Parameter.Origin = FOM_X_Y;
    }
    else if(Global::Temp_JXS_Parameter.Origin == FOM_X_Y)
    {
        Global::Temp_JXS_Parameter.Origin = FOM_Y_X;
    }

    else if(Global::Temp_JXS_Parameter.Origin == FOM_Z_X)
    {
        Global::Temp_JXS_Parameter.Origin = FOM_X_Z;
    }
    else if(Global::Temp_JXS_Parameter.Origin == FOM_X_Z)
    {
        Global::Temp_JXS_Parameter.Origin = FOM_Z_X;
    }

    else if(Global::Temp_JXS_Parameter.Origin == FOM_O_X)
    {
    }

    else if(Global::Temp_JXS_Parameter.Origin == FOM_Z_X_L)
    {
        Global::Temp_JXS_Parameter.Origin = FOM_Z_L_X;
    }
    else if(Global::Temp_JXS_Parameter.Origin == FOM_Z_L_X)
    {
        Global::Temp_JXS_Parameter.Origin = FOM_Z_X_L;
    }

    else if(Global::Temp_JXS_Parameter.Origin == FOM_Z_L_X_O)
    {
        Global::Temp_JXS_Parameter.Origin = FOM_Z_X_L_O;
    }
    else if(Global::Temp_JXS_Parameter.Origin == FOM_Z_X_L_O)
    {
        Global::Temp_JXS_Parameter.Origin = FOM_L_O_Z_X;
    }
    else if(Global::Temp_JXS_Parameter.Origin == FOM_L_O_Z_X)
    {
        Global::Temp_JXS_Parameter.Origin = FOM_Z_O_X_L;
    }
    else if(Global::Temp_JXS_Parameter.Origin == FOM_Z_O_X_L)
    {
        Global::Temp_JXS_Parameter.Origin = FOM_O_Z_X_L;
    }
    else if(Global::Temp_JXS_Parameter.Origin == FOM_O_Z_X_L)
    {
        Global::Temp_JXS_Parameter.Origin = FOM_X_Z_L_O;
    }
    else if(Global::Temp_JXS_Parameter.Origin == FOM_X_Z_L_O)
    {
        Global::Temp_JXS_Parameter.Origin = FOM_Z_L_X_O;
    }
    SET::gs_Refresh_Origin_Method = TRUE;
    Refresh_Origin_Method();
}

//绝对值参数设定--伺服选择
void SysSet::on_comboBox_servoSel_currentIndexChanged(int index)
{
    switch (index) {
    case 0: //禾川
        Global::Temp_JDZ_Parameter.Server = 0;
        break;
    case 1: //汇川
        Global::Temp_JDZ_Parameter.Server = 1;
        break;
    case 2: //迈信
        Global::Temp_JDZ_Parameter.Server = 2;
        break;
    case 3: //德宝
        Global::Temp_JDZ_Parameter.Server = 3;
        break;
    case 4: //星普
        Global::Temp_JDZ_Parameter.Server = 4;
        break;
    case 5: //禾川Y7
        Global::Temp_JDZ_Parameter.Server = 5;
        break;
    case 6: //红森
        Global::Temp_JDZ_Parameter.Server = 6;
        break;
    case 7: //英科
        Global::Temp_JDZ_Parameter.Server = 7;
        break;
    default:
        break;
    }
    Global::gs_Reflash_Fuction_JDZ = TRUE;
    Reflash_Fuction_JDZ(0);
}
