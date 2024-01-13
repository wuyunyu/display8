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
            GP->JDZ_Temp_Save();
        }
        else if(ui->stackedWidget->currentIndex() == ArmSet_id) //机械手设置暂存
        {
            GP->JXS_Temp_Save();
        }
        else if(ui->stackedWidget->currentIndex() == AxisParaSet_id) //原点参数暂存
        {
            GP->OP_Temp_Save();
        }
        else if(ui->stackedWidget->currentIndex() == User_id) //用户变量暂存
        {
            GP->USER_Temp_Save();
        }

        pWidget->backSetPage();       
    });

    //参数保存
    connect(ui->Btn_save, &QPushButton::clicked, this, [=](){
        if(ui->stackedWidget->currentIndex() == ValParaSet_id)  //绝对值参数保存
        {
            pWidget->JDZ_Para_Save();
        }
        else if(ui->stackedWidget->currentIndex() == ArmSet_id) //机械手设置保存
        {
            ui->stackedWidget_tip->setCurrentIndex(0);
            ui->stackedWidget_tip->show();

            GP->JXS_Para_Save();

            GP->f_SendSystemPara();
            GP->gs_Reflash_Fuction_JXS = TRUE;
            Refresh_Fuction_JXS(GP->gs_Reflash_Fuction_JXS);
            ui->stackedWidget_tip->hide();
        }
        else if(ui->stackedWidget->currentIndex() == AxisParaSet_id) //原点参数保存
        {
            ui->stackedWidget_tip->setCurrentIndex(0);
            ui->stackedWidget_tip->show();

            GP->OP_Para_Save();

            GP->f_SendSystemPara();         //原点参数下发(需更改其对应函数！！！！！！)
            for(int i=0; i<AXIS_NUM; i++)
            {
                GP->Axis_Step_Coefficient[i].Step_Coefficient = (float)GP->JXS_Parameter.A_Circle_Pulse[i]/((float)GP->JXS_Parameter.A_Circle_Distance[i]/1000);
            }
            SET::gs_Refresh_OrignParameter = TRUE;
            Refresh_OrignParameter(GP->gs_Reflash_Fuction_JXS);

            ui->stackedWidget_tip->hide();
        }
        else if(ui->stackedWidget->currentIndex() == User_id) //用户变量保存
        {
            ui->stackedWidget_tip->setCurrentIndex(0);
            ui->stackedWidget_tip->show();

            GP->USER_Para_Save();

            GP->f_SendSystemPara();         //用户变量参数下发(需更改其对应函数！！！！！！)
            GP->gs_Reflash_Save_USER = TRUE;
            Reflash_Save_USER(GP->gs_Reflash_Save_USER);
            ui->stackedWidget_tip->hide();
        }

    });

    //功能设定--机械手设置
    connect(ui->Btn_armSet, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(ArmSet_id);
        ui->Btn_save->show();

        GP->JXS_Temp_Save();

        GP->gs_Reflash_Fuction_JXS = TRUE;
        SET::gs_Refresh_Associate = TRUE;
        SET::gs_Refresh_Avoidace = TRUE;

        Refresh_Fuction_JXS(GP->gs_Reflash_Fuction_JXS);
        Refresh_Associate(SET::gs_Refresh_Associate);
        Refresh_Avoidace(SET::gs_Refresh_Avoidace);
    });

    //功能设定--机械手设置--外部回零端口
    connect(ui->Btn_externalReturn0, &QPushButton::clicked, this, [=](){
        if(GP->Temp_JXS_Parameter.Outport_Orign == 1)
        {
            GP->Temp_JXS_Parameter.Outport_Orign = 0;
        }
        else
        {
            GP->Temp_JXS_Parameter.Outport_Orign = 1;
        }
        SET::gs_Refresh_Outport = TRUE;
        Refresh_Outport(SET::gs_Refresh_Outport);
    });

    //功能设定--机械手设置--外部启动端口
    connect(ui->Btn_externalStart, &QPushButton::clicked, this, [=](){
        if(GP->Temp_JXS_Parameter.Outport_Run == 2)
        {
            GP->Temp_JXS_Parameter.Outport_Run = 0;
        }
        else
        {
            GP->Temp_JXS_Parameter.Outport_Run = 2;
        }
        SET::gs_Refresh_Outport = TRUE;
        Refresh_Outport(SET::gs_Refresh_Outport);
    });

    //功能设定--机械手设置--外部暂停端口
    connect(ui->Btn_externalPause, &QPushButton::clicked, this, [=](){
        if(GP->Temp_JXS_Parameter.Outport_Pause == 3)
        {
            GP->Temp_JXS_Parameter.Outport_Pause = 0;
        }
        else
        {
            GP->Temp_JXS_Parameter.Outport_Pause = 3;
        }
        SET::gs_Refresh_Outport = TRUE;
        Refresh_Outport(SET::gs_Refresh_Outport);
    });

    //功能设定--机械手设置--外部停止端口
    connect(ui->Btn_externalStop, &QPushButton::clicked, this, [=](){
        if(GP->Temp_JXS_Parameter.Outport_Stop == 4)
        {
            GP->Temp_JXS_Parameter.Outport_Stop = 0;
        }
        else
        {
            GP->Temp_JXS_Parameter.Outport_Stop = 4;
        }
        SET::gs_Refresh_Outport = TRUE;
        Refresh_Outport(SET::gs_Refresh_Outport);
    });

    //功能设定--机械手设置--伺服报警信号高低电平
    connect(ui->Btn_servoAlarm, &QPushButton::clicked, this, [=](){
        if(GP->Temp_JXS_Parameter.AlarmSignal == 1)
        {
            GP->Temp_JXS_Parameter.AlarmSignal = 0;
        }
        else
        {
            GP->Temp_JXS_Parameter.AlarmSignal = 1;
        }
        SET::gs_Refresh_AlarmSignal = TRUE;
        Refresh_AlarmSignal(SET::gs_Refresh_AlarmSignal);
    });

    //功能设定--机械手设置--X/Y/Z/O伺服报警开关
    for(int i = 0; i < AXIS_NUM; i++)
    {
        connect(Btn_Axis_Servo.at(i), &QPushButton::clicked, this, [=](){
            if(GP->Temp_JXS_Parameter.Alarm_Switch[i] == 1)
            {
                GP->Temp_JXS_Parameter.Alarm_Switch[i] = 0;
            }
            else
            {
                GP->Temp_JXS_Parameter.Alarm_Switch[i] = 1;
            }
            SET::gs_Refresh_AlarmSignal = TRUE;
            Refresh_AlarmSignal(SET::gs_Refresh_AlarmSignal);
        });
    }

    //功能设定--机械手设置--码垛IO开关
    connect(ui->Btn_stackIO, &QPushButton::clicked, this, [=](){
        if(GP->Temp_JXS_Parameter.MDgripSwitch == 1)
        {
            GP->Temp_JXS_Parameter.MDgripSwitch = 0;
            for(int i=0; i<MDgrip_Num; i++)
            {
                GP->Temp_JXS_Parameter.MDgripPort[i]=0;	//关闭功能则恢复默认，无效
                //对应夹爪点颜色变化
            }
        }
        else
        {
            GP->Temp_JXS_Parameter.MDgripSwitch = 1;
        }
        GP->gs_Refresh_MD_Circulation = TRUE;
        Refresh_MD_Circulation(GP->gs_Refresh_MD_Circulation);
    });

    //功能设定--机械手设置--码垛IO序号
    connect(ui->Btn_num, &QPushButton::clicked, this, [=](){
        if(GP->Temp_JXS_Parameter.MDgripSwitch == 1)
        {
            GP->Temp_JXS_Parameter.MDgripNum = 1 + GP->Temp_JXS_Parameter.MDgripNum;
            if((GP->Temp_JXS_Parameter.MDgripNum & 0x0f) == MDgrip_Num)
            {
                GP->Temp_JXS_Parameter.MDgripNum = 0;
            }
        }
        GP->gs_Refresh_MD_Circulation = TRUE;
        Refresh_MD_Circulation(GP->gs_Refresh_MD_Circulation);
    });

    //功能设定--机械手设置--码垛IO端口
    connect(ui->Btn_port, &QPushButton::clicked, this, [=](){
        if(GP->Temp_JXS_Parameter.MDgripSwitch == 1)
        {
            GP->gs_MDgripSetFlag = TRUE;	//标志设置码垛端口
        }
        GP->gs_IO_Detect_Display_Refresh = TRUE;
        GP->gs_Refresh_MD_Circulation = TRUE;
        SignalSet_ui->IO_Detect_Display_Refresh(GP->gs_IO_Detect_Display_Refresh);
        Refresh_MD_Circulation(GP->gs_Refresh_MD_Circulation);
    });

    //功能设定--机械手设置--Y0Y1关联输出
    connect(ui->Btn_Y0Y1, &QPushButton::clicked, this, [=](){
        if(GP->Temp_JXS_Parameter.OutputAssociate[0]==1)
        {
            GP->Temp_JXS_Parameter.OutputAssociate[0] = 0;
        }
        else
        {
            GP->Temp_JXS_Parameter.OutputAssociate[0] = 1;
        }
        SET::gs_Refresh_Associate = TRUE;
        Refresh_Associate(SET::gs_Refresh_Associate);
    });

    //功能设定--机械手设置--Y2Y3关联输出
    connect(ui->Btn_Y2Y3, &QPushButton::clicked, this, [=](){
        if(GP->Temp_JXS_Parameter.OutputAssociate[1]==1)
        {
            GP->Temp_JXS_Parameter.OutputAssociate[1] = 0;
        }
        else
        {
            GP->Temp_JXS_Parameter.OutputAssociate[1] = 1;
        }
        SET::gs_Refresh_Associate = TRUE;
        Refresh_Associate(SET::gs_Refresh_Associate);
    });

    //功能设定--机械手设置--Z轴防撞
    connect(ui->Btn_ZavoidHit, &QPushButton::clicked, this, [=](){
        if(GP->Temp_JXS_Parameter.ZAxsisAvoidace==1)
        {
            GP->Temp_JXS_Parameter.ZAxsisAvoidace = 0;
            GP->Temp_JXS_Parameter.ZAxsisLimit =  0;
        }
        else
        {
            GP->Temp_JXS_Parameter.ZAxsisAvoidace = 1;
        }
        SET::gs_Refresh_Avoidace = TRUE;
        Refresh_Avoidace(SET::gs_Refresh_Avoidace);
    });

    //功能设定--机械手设置--Z轴下限
    connect(ui->Edit_ZavoidHitLength, &QLineEdit::editingFinished, this, [=](){
        if(GP->Temp_JXS_Parameter.ZAxsisAvoidace==1)
        {
            GP->Temp_JXS_Parameter.ZAxsisLimit = ui->Edit_ZavoidHitLength->text().toUInt();
        }
        else
        {
            GP->Temp_JXS_Parameter.ZAxsisLimit = 0;
        }
        SET::gs_Refresh_Avoidace = TRUE;
        Refresh_Avoidace(SET::gs_Refresh_Avoidace);
    });


    //功能设定--原点参数设置
    connect(ui->Btn_axisParaSet, &QPushButton::clicked, this ,[=](){
        ui->stackedWidget->setCurrentIndex(AxisParaSet_id);
        ui->Btn_save->show();

        GP->Axis_Parameter_Select = X_AXIS;
        GP->Temp_JXS_Parameter.OriginPosition[X_AXIS] = GP->JXS_Parameter.OriginPosition[X_AXIS];
        GP->Temp_JXS_Parameter.OriginSpeed[X_AXIS] = GP->JXS_Parameter.OriginSpeed[X_AXIS];
        GP->Temp_JXS_Parameter.OriginOffset[X_AXIS] = GP->JXS_Parameter.OriginOffset[X_AXIS];
        GP->Temp_JXS_Parameter.OriginDiretion[X_AXIS] = GP->JXS_Parameter.OriginDiretion[X_AXIS];
        GP->Temp_JXS_Parameter.A_Circle_Pulse[X_AXIS] = GP->JXS_Parameter.A_Circle_Pulse[X_AXIS];
        GP->Temp_JXS_Parameter.A_Circle_Distance[X_AXIS] = GP->JXS_Parameter.A_Circle_Distance[X_AXIS];
        SET::gs_Refresh_OrignParameter = TRUE;
        Refresh_OrignParameter(SET::gs_Refresh_OrignParameter);
    });

    //功能设定--原点参数设置 X轴\Y轴\Z轴\O轴
    for(int i = 0; i < AXIS_NUM; i++)
    {
        connect(Btn_Axis_Sel.at(i), &QPushButton::clicked, this ,[=](){
            GP->Axis_Parameter_Select = i;
            GP->Temp_JXS_Parameter.OriginPosition[i] = GP->JXS_Parameter.OriginPosition[i];
            GP->Temp_JXS_Parameter.OriginSpeed[i] = GP->JXS_Parameter.OriginSpeed[i];
            GP->Temp_JXS_Parameter.OriginOffset[i] = GP->JXS_Parameter.OriginOffset[i];
            GP->Temp_JXS_Parameter.OriginDiretion[i] = GP->JXS_Parameter.OriginDiretion[i];
            GP->Temp_JXS_Parameter.A_Circle_Pulse[i] = GP->JXS_Parameter.A_Circle_Pulse[i];
            GP->Temp_JXS_Parameter.A_Circle_Distance[i] = GP->JXS_Parameter.A_Circle_Distance[i];
            GP->Temp_JXS_Parameter.Accelerate.Time[i] = GP->JXS_Parameter.Accelerate.Time[i];
            GP->Temp_JXS_Parameter.AccAcc[i] = GP->JXS_Parameter.AccAcc[i];
            GP->Temp_JXS_Parameter.JDZ_AllowError[i] = GP->JXS_Parameter.JDZ_AllowError[i];
            SET::gs_Refresh_OrignParameter = TRUE;
            Refresh_OrignParameter(SET::gs_Refresh_OrignParameter);
        });
    }

    //功能设定--原点参数设置--回零方向
    connect(ui->Btn_back0Diret, &QPushButton::clicked, this, [=](){
        if(GP->Temp_JXS_Parameter.OriginDiretion[GP->Axis_Parameter_Select] == 1)
        {
            GP->Temp_JXS_Parameter.OriginDiretion[GP->Axis_Parameter_Select] = 0;
        }
        else
        {
            GP->Temp_JXS_Parameter.OriginDiretion[GP->Axis_Parameter_Select] = 1;
        }
        ui->Btn_back0Diret->setText(Origin_Direction[GP->Temp_JXS_Parameter.OriginDiretion[GP->Axis_Parameter_Select]]);
    });

    //功能设定--原点参数设置--回零速度
    connect(ui->Edit_back0Speed, &QLineEdit::editingFinished, this, [=](){
        GP->Temp_JXS_Parameter.OriginSpeed[GP->Axis_Parameter_Select] = static_cast<u8>(ui->Edit_back0Speed->text().toUInt());
    });

    //功能设定--原点参数设置--原点位置
    connect(ui->Btn_originPos, &QPushButton::clicked, this, [=](){
        if(GP->Temp_JXS_Parameter.OriginPosition[GP->Axis_Parameter_Select] == 1)
        {
            GP->Temp_JXS_Parameter.OriginPosition[GP->Axis_Parameter_Select] = 0;
        }
        else
        {
            GP->Temp_JXS_Parameter.OriginPosition[GP->Axis_Parameter_Select] = 1;
        }
        ui->Btn_originPos->setText(Origin_Position[GP->Temp_JXS_Parameter.OriginPosition[GP->Axis_Parameter_Select]]);
    });

    //功能设定--原点参数设置--原点偏移
    connect(ui->Edit_originOffest, &QLineEdit::editingFinished, this, [=](){
        GP->Temp_JXS_Parameter.OriginOffset[GP->Axis_Parameter_Select] = ui->Edit_originOffest->text().toUInt();
    });

    //功能设定--原点参数设置--单圈脉冲
    connect(ui->Edit_loopPulse, &QLineEdit::editingFinished, this, [=](){
        GP->Temp_JXS_Parameter.A_Circle_Pulse[GP->Axis_Parameter_Select] = ui->Edit_loopPulse->text().toUInt();
    });

    //功能设定--原点参数设置--单圈距离
    connect(ui->Edit_lapDistance, &QLineEdit::editingFinished, this, [=](){
        GP->Temp_JXS_Parameter.A_Circle_Distance[GP->Axis_Parameter_Select] = ui->Edit_lapDistance->text().toUInt();
    });

    //功能设定--原点参数设置--加速度时间
    connect(ui->Edit_speedUpTime, &QLineEdit::editingFinished, this, [=](){
        GP->Temp_JXS_Parameter.Accelerate.Time[GP->Axis_Parameter_Select] = ui->Edit_speedUp->text().toUShort();
    });

    //功能设定--原点参数设置--加加速
    connect(ui->Edit_speedUp, &QLineEdit::editingFinished, this, [=](){
        GP->Temp_JXS_Parameter.AccAcc[GP->Axis_Parameter_Select] = static_cast<u8>(ui->Edit_speedUp->text().toUInt());
    });

    //功能设定--原点参数设置--动作确认
    connect(ui->Edit_actionConfirm, &QLineEdit::editingFinished, this, [=](){
        GP->Temp_JXS_Parameter.JDZ_AllowError[GP->Axis_Parameter_Select] = ui->Edit_actionConfirm->text().toUShort();
    });

    //功能设定--绝对值参数设定
    connect(ui->Btn_valueParaSet, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(ValParaSet_id);
        ui->Btn_save->show();

        GP->JDZ_Temp_Save();

        GP->gs_Refresh_JDZOriginSetting_Text = TRUE;
        GP->gs_Reflash_Fuction_JDZ = TRUE;

        Refresh_JDZOriginSetting_Text(GP->gs_Refresh_JDZOriginSetting_Text);
        Reflash_Fuction_JDZ(GP->gs_Reflash_Fuction_JDZ);
    });

    //绝对值参数设定--功能开关
    connect(ui->Btn_On_Off, &QPushButton::clicked, this, [=](){
        if(GP->Temp_JDZ_Parameter.Switch == 1)
        {
            GP->Temp_JDZ_Parameter.Switch = 0;
        }
        else
        {
            GP->Temp_JDZ_Parameter.Switch = 1;
        }
        GP->gs_Reflash_Fuction_JDZ = TRUE;
        Reflash_Fuction_JDZ(GP->gs_Reflash_Fuction_JDZ);
    });

    for(int i = 0; i < AXIS_NUM; i++)
    {
        //i轴运动方向
        connect(Btn_Axis_Dirt.at(i), &QPushButton::clicked, this, [=](){
            if(GP->JDZ_Parameter.Switch == 1)
            {
                if(GP->Temp_JDZ_Parameter.Motion_Dir[i] == 1)
                {
                    GP->Temp_JDZ_Parameter.Motion_Dir[i] = 0;
                }
                else
                {
                    GP->Temp_JDZ_Parameter.Motion_Dir[i] = 1;
                }
                GP->gs_Reflash_Fuction_JDZ = TRUE;
                Reflash_Fuction_JDZ(GP->gs_Reflash_Fuction_JDZ);
            }
        });
        //i轴机械回零
        connect(Btn_Axis_Return0.at(i), &QPushButton::clicked, this, [=](){
            if(GP->JDZ_Parameter.Switch == 1)
            {
                GP->JDZ_Machine_Ori_Axis_Num = i;
                SET::gs_Refresh_JDZ_Axis = TRUE;
                Refresh_JDZ_Axis(SET::gs_Refresh_JDZ_Axis = TRUE, 4);
            }
        });
        //i轴原点设置
        connect(Btn_Axis_OriginSet.at(i), &QPushButton::clicked, this, [=](){
            if(GP->JDZ_Parameter.Switch == 1)
            {
                GP->JDZ_Origin_Setting_Axis_Num = i;
                SET::gs_Refresh_JDZ_Axis = TRUE;
                Refresh_JDZ_Axis(SET::gs_Refresh_JDZ_Axis = TRUE, 5);
            }
        });
        //i轴重置原点
        connect(Btn_Axis_OriginRst.at(i), &QPushButton::clicked, this, [=](){
            if(GP->JDZ_Parameter.Switch == 1)
            {
                GP->JDZ_Origin_Resetting_Axis_Num = i;
                SET::gs_Refresh_JDZ_Axis = TRUE;
                Refresh_JDZ_Axis(SET::gs_Refresh_JDZ_Axis = TRUE, 6);
            }
        });
    }

    connect(ui->Btn_machback0OK, &QPushButton::clicked, this, [=](){ //机械回零确认
        if(GP->Robot_Status == ACTION_STOP && GP->g_Robot_Error_Flag == 0)
        {//如果机械手状态为停止
//            Order_Temp[0]=MACHINEORIGIN;              					//机械回零
//            Order_Temp[1]=JDZ_Machine_Ori_Axis_Num;              		//机械回零轴 1-4
//            USART1_SendData(2,ROBOT_ENABLE_A_ORIGIN,&Order_Temp[0]);
            GP->Robot_Origined = FALSE;                  					//机械手回原点
            ui->stackedWidget_tip->setCurrentIndex(2);
            GP->Get_JDZ_Information = MACHINE_ORIGIN_STATUS;
        }
        else
        {
//            LCD_Popup_Windows = PW_1_STOPROBOT;							//弹出提示框-请先停止机器
        }
        ui->stackedWidget_tip->hide();
    });
    connect(ui->Btn_machback0Cancel, &QPushButton::clicked, this, [=](){ //机械回零取消
        GP->gs_Reflash_Fuction_JDZ = TRUE;
        Reflash_Fuction_JDZ(GP->gs_Reflash_Fuction_JDZ);
        ui->stackedWidget_tip->hide();
    });

    connect(ui->Btn_originSetOK, &QPushButton::clicked, this, [=](){ //设置原点确认
        if(GP->Robot_Status == ACTION_STOP && GP->g_Robot_Error_Flag == 0)
        {//如果机械手状态为停止
//            Order_Temp[0]=ORIGNSETTING;              					//设置原点
//            Order_Temp[1]=JDZ_Origin_Setting_Axis_Num;              	//设置原点轴 1-4
//            USART1_SendData(2,ROBOT_ENABLE_A_ORIGIN,&Order_Temp[0]);
            GP->Get_JDZ_Information = ORIGIN_SETTING_STATUS;
        }
        ui->stackedWidget_tip->hide();
    });
    connect(ui->Btn_originSetCancel, &QPushButton::clicked, this, [=](){ //设置原点取消
        GP->gs_Reflash_Fuction_JDZ = TRUE;
        Reflash_Fuction_JDZ(GP->gs_Reflash_Fuction_JDZ);
        ui->stackedWidget_tip->hide();
    });

    connect(ui->Btn_originRstOK, &QPushButton::clicked, this, [=](){ //重置原点确认
        if(GP->Robot_Status == ACTION_STOP && GP->g_Robot_Error_Flag == 0)
        {//如果机械手状态为停止
//            Order_Temp[0]=ORIGNRESETTING;              					//重置原点
//            Order_Temp[1]=JDZ_Origin_Resetting_Axis_Num;              	//重置原点轴 1-4
//            USART1_SendData(2,ROBOT_ENABLE_A_ORIGIN,&Order_Temp[0]);
            GP->Get_JDZ_Information = ORIGIN_RESETTING_STATUS;
        }
        ui->stackedWidget_tip->hide();
    });
    connect(ui->Btn_originRstCancel, &QPushButton::clicked, this, [=](){ //重置原点取消
        GP->gs_Reflash_Fuction_JDZ = TRUE;
        Reflash_Fuction_JDZ(GP->gs_Reflash_Fuction_JDZ);
        ui->stackedWidget_tip->hide();
    });

    //功能设定--用户变量设定
    connect(ui->Btn_userVarSet, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(UserVarSet_id);
        ui->Btn_save->show();

//        Order_Temp[0] = USER_CURNUM;
//        USART1_SendData(1,WATCH_COMMAND,&Order_Temp[0]);
        GP->USER_Temp_Save();

        GP->gs_Reflash_Fuction_USER = TRUE;
        Reflash_Fuction_USER(GP->gs_Reflash_Fuction_USER);
    });

    for(int i = 0; i < USER_NUM; i++)
    {
        //USER--名称
        connect(Eidt_USER_Name.at(i), &QLineEdit::editingFinished, this, [=](){
            GP->USER_PARAMETER(USER_Name, i);
            Reflash_Fuction_USER(GP->gs_Reflash_Fuction_USER);
        });
        //USER--初始值
        connect(Eidt_USER_InitVal.at(i), &QLineEdit::editingFinished, this, [=](){
            GP->USER_PARAMETER(USER_Init, i);
            Reflash_Fuction_USER(GP->gs_Reflash_Fuction_USER);
        });
        //USER--当前值
        connect(Eidt_USER_CurVal.at(i), &QLineEdit::editingFinished, this, [=](){
            GP->USER_PARAMETER(USER_Curr, i);
            Reflash_Fuction_USER(GP->gs_Reflash_Fuction_USER);
        });
        //USER--开机置0
        connect(Btn_USER_BootRst.at(i), &QPushButton::clicked, this, [=](){
            GP->USER_PARAMETER(USER_Elec, i);
            Reflash_Fuction_USER(GP->gs_Reflash_Fuction_USER);
        });
        //USER--启动置0
        connect(Btn_USER_StartRst.at(i), &QPushButton::clicked, this, [=](){
            GP->USER_PARAMETER(USER_Start, i);
            Reflash_Fuction_USER(GP->gs_Reflash_Fuction_USER);
        });
    }






    //功能设定--笛卡尔坐标系设定
    connect(ui->Btn_coordSet, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(CoordSet_id);
        ui->Btn_save->hide();
        GP->m_Refresh_Cartesian = TRUE;
        Refresh_Cartesian(GP->m_Refresh_Cartesian);
    });

    //笛卡尔坐标系设定--笛卡尔坐标系开关
    connect(ui->Btn_crood, &QPushButton::clicked, this, [=](){
        if(GP->sCartesian_Para.carCoordSwitch == 1)
            GP->sCartesian_Para.carCoordSwitch = 0;
        else
            GP->sCartesian_Para.carCoordSwitch = 1;
        ui->Btn_crood->setText(CarCoord_Switch[GP->sCartesian_Para.carCoordSwitch]);
        GP->f_send_Cartesian();
    });

    //功能设定--笛卡尔坐标系设定--机械臂1
    connect(ui->Edit_armL1, &QLineEdit::editingFinished, this, [=](){
        GP->sCartesian_Para.length[0] = ui->Edit_armL1->text().toUInt();
        GP->f_send_Cartesian();
    });

    //功能设定--笛卡尔坐标系设定--机械臂2
    connect(ui->Edit_armL2, &QLineEdit::editingFinished, this, [=](){
        GP->sCartesian_Para.length[1] = ui->Edit_armL2->text().toUInt();
        GP->f_send_Cartesian();
    });

    //功能设定--笛卡尔坐标系设定--丝杆螺距
    connect(ui->Edit_pitch, &QLineEdit::editingFinished, this, [=](){
        GP->sCartesian_Para.pitchLength = ui->Edit_pitch->text().toUInt();
        GP->f_send_Cartesian();
    });

    //功能设定--笛卡尔坐标系设定--笛卡尔最大速度
    connect(ui->Edit_maxSpeed, &QLineEdit::editingFinished, this, [=](){
        GP->sCartesian_Para.maxSpeed = ui->Edit_maxSpeed->text().toUShort();
        GP->f_send_Cartesian();
    });

    //功能设定--笛卡尔坐标系设定--笛卡尔加速时间
    connect(ui->Edit_SpeedUpTime, &QLineEdit::editingFinished, this, [=](){
        GP->sCartesian_Para.accTime = ui->Edit_SpeedUpTime->text().toUShort();
        GP->f_send_Cartesian();
    });

    //功能设定--笛卡尔坐标系设定--笛卡尔加加速
    connect(ui->Edit_pSpeedUp, &QLineEdit::editingFinished, this, [=](){
        GP->sCartesian_Para.accAcc = ui->Edit_pSpeedUp->text().toUShort();
        GP->f_send_Cartesian();
    });

    for(int i = 0; i < AXIS_NUM; i++)
    {
        //笛卡尔坐标系设定--轴类型
        connect(Btn_Axis_Type.at(i), &QPushButton::clicked, this, [=](){
            if(GP->sCartesian_Para.axisType[i] == 1)
                GP->sCartesian_Para.axisType[i] = 0;
            else
                GP->sCartesian_Para.axisType[i] = 1;
            Btn_Axis_Type.at(i)->setText(AXISType_Switch[GP->sCartesian_Para.axisType[i]]);
            GP->f_send_Cartesian();
        });

        //笛卡尔坐标系设定--轴联动开关
        connect(Btn_Axis_Link.at(i), &QPushButton::clicked, this, [=](){
            if(GP->sCartesian_Para.axisInterpFlag[i] == 1)
                GP->sCartesian_Para.axisInterpFlag[i] = 0;
            else
                GP->sCartesian_Para.axisInterpFlag[i] = 1;
            Btn_Axis_Link.at(i)->setText(PF_Switch[GP->sCartesian_Para.axisInterpFlag[i]]);
            GP->f_send_Cartesian();
        });

        //笛卡尔坐标系设定--轴回最小坐标方向
        connect(Btn_Axis_Back.at(i), &QPushButton::clicked, this, [=](){
            if(GP->sCartesian_Para.axisBackMinDir[i] == 1)
                GP->sCartesian_Para.axisBackMinDir[i] = 0;
            else
                GP->sCartesian_Para.axisBackMinDir[i] = 1;
            Btn_Axis_Back.at(i)->setText(MD_axisBackMinDir[GP->sCartesian_Para.axisBackMinDir[i]]);
            GP->f_send_Cartesian();
        });
    }
}

SysSet::~SysSet()
{
    delete ui;
}

void SysSet::init()
{
    ui->stackedWidget->setCurrentIndex(ArmSet_id);
    ui->stackedWidget_tip->hide();

    QStringList strList1;
    strList1<<MD_CoordType[0]<<MD_CoordType[1]<<MD_CoordType[2]<<MD_CoordType[3];
    ui->comboBox_machType->addItems(strList1);

    QStringList strList2;
    strList2<<FucSet_Axis[0]<<FucSet_Axis[1]<<FucSet_Axis[2]<<FucSet_Axis[3]<<FucSet_Axis[4]
            <<FucSet_Axis[5]<<FucSet_Axis[6]<<FucSet_Axis[7]<<FucSet_Axis[8];
    ui->comboBox_mechAxisNum->addItems(strList2);

    QStringList strList3;
    strList3<<Servo_selection[0]<<Servo_selection[1]<<Servo_selection[2]<<Servo_selection[3]
            <<Servo_selection[4]<<Servo_selection[5]<<Servo_selection[6]<<Servo_selection[7];
    ui->comboBox_servoSel->addItems(strList3);

    QStringList strList4;
    strList4<<Encoder_resolution[0]<<Encoder_resolution[1]<<Encoder_resolution[2]<<Encoder_resolution[3];
    ui->comboBox_encoder->addItems(strList4);

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

//功能设定--机械手设定刷新
void SysSet::Refresh_Fuction_JXS(u8 flag)
{
    if(flag == TRUE)
    {
        //显示轴个数和回原点方式
        ui->comboBox_mechAxisNum->setCurrentIndex(static_cast<int>(GP->JXS_Parameter.Axis));
        ui->Btn_returnOriginWay->setText(FucSet_Origin[GP->JXS_Parameter.Origin]);
        //显示外部端口的设置
        ui->Btn_externalPause->setText(Outport_Switch[GP->JXS_Parameter.Outport_Pause]);
        ui->Btn_externalReturn0->setText(Outport_Switch[GP->JXS_Parameter.Outport_Orign]);
        ui->Btn_externalStart->setText(Outport_Switch[GP->JXS_Parameter.Outport_Run]);
        ui->Btn_externalStop->setText(Outport_Switch[GP->JXS_Parameter.Outport_Stop]);

        ui->Btn_servoAlarm->setText(Alarm_Signal_Dis[GP->JXS_Parameter.AlarmSignal]);   //显示伺服报警电平
        //显示伺服报警开关
        ui->Btn_armSetX->setText(Alarm_Switch_Dis[GP->JXS_Parameter.Alarm_Switch[0]]);
        ui->Btn_armSetY->setText(Alarm_Switch_Dis[GP->JXS_Parameter.Alarm_Switch[1]]);
        ui->Btn_armSetZ->setText(Alarm_Switch_Dis[GP->JXS_Parameter.Alarm_Switch[2]]);
        ui->Btn_armSetO->setText(Alarm_Switch_Dis[GP->JXS_Parameter.Alarm_Switch[3]]);
        flag = FALSE;
    }
}

//功能设定--关联输出刷新
void SysSet::Refresh_Associate(u8 flag)
{
    if(flag == TRUE)
    {
        ui->Btn_Y0Y1->setText(Function_switch[(GP->Temp_JXS_Parameter.OutputAssociate[0] & 0x0f)]);
        ui->Btn_Y2Y3->setText(Function_switch[(GP->Temp_JXS_Parameter.OutputAssociate[1] & 0x0f)]);
        flag = FALSE;
    }
}

//功能设定--Z轴防撞刷新
void SysSet::Refresh_Avoidace(u8 flag)
{
    if(flag == TRUE)
    {
        ui->Btn_ZavoidHit->setText(ZAxis_Avoidance[(GP->Temp_JXS_Parameter.ZAxsisAvoidace & 0x0f)]);
        ui->Edit_ZavoidHitLength->setText(QString::number(GP->Temp_JXS_Parameter.ZAxsisLimit));
        flag = FALSE;
    }
}

//功能设定--机械手设定--回零方式刷新
void SysSet::Refresh_Origin_Method(u8 flag)
{
    if(flag == TRUE)
    {
        ui->Btn_returnOriginWay->setText(FucSet_Origin[GP->Temp_JXS_Parameter.Origin]);
        flag = FALSE;
    }
}

//功能设定--机械手设定--外部端口设定刷新
void SysSet::Refresh_Outport(u8 flag)
{
    if(flag == TRUE)
    {
        ui->Btn_externalPause->setText(Outport_Switch[GP->Temp_JXS_Parameter.Outport_Pause]);
        ui->Btn_externalReturn0->setText(Outport_Switch[GP->Temp_JXS_Parameter.Outport_Orign]);
        ui->Btn_externalStart->setText(Outport_Switch[GP->Temp_JXS_Parameter.Outport_Run]);
        ui->Btn_externalStop->setText(Outport_Switch[GP->Temp_JXS_Parameter.Outport_Stop]);

        flag = FALSE;
    }
}

//功能设定--机械手设定--伺服报警电平及开关刷新
void SysSet::Refresh_AlarmSignal(u8 flag)
{
    if(flag == TRUE)
    {
        ui->Btn_servoAlarm->setText(Alarm_Signal_Dis[GP->Temp_JXS_Parameter.AlarmSignal]);
        ui->Btn_armSetX->setText(Alarm_Signal_Dis[GP->Temp_JXS_Parameter.Alarm_Switch[0]]);
        ui->Btn_armSetY->setText(Alarm_Signal_Dis[GP->Temp_JXS_Parameter.Alarm_Switch[1]]);
        ui->Btn_armSetZ->setText(Alarm_Signal_Dis[GP->Temp_JXS_Parameter.Alarm_Switch[2]]);
        ui->Btn_armSetO->setText(Alarm_Signal_Dis[GP->Temp_JXS_Parameter.Alarm_Switch[3]]);

        flag = FALSE;
    }
}

//刷新码垛夹爪IO
void SysSet::Refresh_MD_Circulation(u8 flag)
{
    if(flag == TRUE)
    {
        ui->Btn_stackIO->setText(MD_gripSwitch[GP->Temp_JXS_Parameter.MDgripSwitch&0x0f]);
        if(GP->Temp_JXS_Parameter.MDgripSwitch ==0)	//功能关闭
        {
            ui->Btn_num->setText(MD_InvalidGrip);	//无效
            ui->Btn_port->setText(MD_InvalidGrip);
        }
        else
        {
            ui->Btn_num->setText(MD_gripNum[GP->Temp_JXS_Parameter.MDgripNum & 0x0f]);
            if(GP->Temp_JXS_Parameter.MDgripPort[GP->Temp_JXS_Parameter.MDgripNum] == 0)	//端口无效
            {
                ui->Btn_port->setText(MD_InvalidGrip);
            }
            else
            {
                ui->Btn_port->setText(OutputIO_Detect_IO[GP->Temp_JXS_Parameter.MDgripPort[GP->Temp_JXS_Parameter.MDgripNum]-1]);
            }
        }
        StackSet_ui->Refresh_MD_Circulation();
        flag = FALSE;
    }
}

//功能设定--原点参数设定刷新
void SysSet::Refresh_OrignParameter(u8 flag)
{
    if(flag == TRUE)
    {
        ui->Btn_back0Diret->setText(Origin_Direction[GP->JXS_Parameter.OriginDiretion[GP->Axis_Parameter_Select]]); //回零方向
        ui->Edit_originOffest->setText(QString::number(GP->JXS_Parameter.OriginOffset[GP->Axis_Parameter_Select]));  //原点偏移
        ui->Edit_back0Speed->setText(QString::number(GP->JXS_Parameter.OriginSpeed[GP->Axis_Parameter_Select]));    //回零速度
        ui->Edit_loopPulse->setText(QString::number(GP->JXS_Parameter.A_Circle_Pulse[GP->Axis_Parameter_Select]));     //单圈脉冲
        ui->Edit_lapDistance->setText(QString::number(GP->JXS_Parameter.A_Circle_Distance[GP->Axis_Parameter_Select]));   //单圈距离
        ui->Btn_originPos->setText(Origin_Direction[GP->JXS_Parameter.OriginPosition[GP->Axis_Parameter_Select]]);  //原点位置

        ui->Edit_speedUpTime->setText(QString::number(GP->JXS_Parameter.Accelerate.Time[GP->Axis_Parameter_Select]));   //加速度时间
        ui->Edit_speedUp->setText(QString::number(GP->JXS_Parameter.AccAcc[GP->Axis_Parameter_Select]));       //加加速
        ui->Edit_actionConfirm->setText(QString::number(GP->JXS_Parameter.JDZ_AllowError[GP->Axis_Parameter_Select])); //动作确认
        flag = FALSE;
    }
}

//原点设置
void SysSet::Refresh_JDZOriginSetting_Text(u8 flag)
{
    if(flag == TRUE)
    {
        ui->Btn_XoriginSet->setText(JDZ_OriginSetting_Dis[GP->JDZ_Parameter.OriginSetting[0]]);
        ui->Btn_YoriginSet->setText(JDZ_OriginSetting_Dis[GP->JDZ_Parameter.OriginSetting[1]]);
        ui->Btn_ZoriginSet->setText(JDZ_OriginSetting_Dis[GP->JDZ_Parameter.OriginSetting[2]]);
        ui->Btn_OoriginSet->setText(JDZ_OriginSetting_Dis[GP->JDZ_Parameter.OriginSetting[3]]);

        flag = FALSE;
    }
}

//功能设定--绝对值参数设定刷新
void SysSet::Reflash_Fuction_JDZ(u8 flag)
{
    if(flag == TRUE)
    {
        ui->Btn_On_Off->setText(Function_switch[GP->Temp_JDZ_Parameter.Switch]);    //功能开关
        ui->comboBox_servoSel->setCurrentIndex(static_cast<int>(GP->Temp_JDZ_Parameter.Server));      //伺服选择
        ui->comboBox_encoder->setCurrentIndex(static_cast<int>(GP->Temp_JDZ_Parameter.Resolu));       //编码器分辨率
        //运动方向
        ui->Btn_Xdirection->setText(Move_Direction[GP->Temp_JDZ_Parameter.Motion_Dir[0]]);
        ui->Btn_Ydirection->setText(Move_Direction[GP->Temp_JDZ_Parameter.Motion_Dir[1]]);
        ui->Btn_Zdirection->setText(Move_Direction[GP->Temp_JDZ_Parameter.Motion_Dir[2]]);
        ui->Btn_Odirection->setText(Move_Direction[GP->Temp_JDZ_Parameter.Motion_Dir[3]]);

        flag = FALSE;
    }
}

//功能设定--绝对值参数保存刷新
void SysSet::Reflash_Save_JDZ(u8 flag)
{
    if(flag == TRUE)
    {
        ui->Btn_On_Off->setText(Function_switch[GP->JDZ_Parameter.Switch]);    //功能开关
        ui->comboBox_servoSel->setCurrentIndex(static_cast<int>(GP->JDZ_Parameter.Server));      //伺服选择
        ui->comboBox_encoder->setCurrentIndex(static_cast<int>(GP->JDZ_Parameter.Resolu));       //编码器分辨率
        //运动方向
        ui->Btn_Xdirection->setText(Move_Direction[GP->Temp_JDZ_Parameter.Motion_Dir[0]]);
        ui->Btn_Ydirection->setText(Move_Direction[GP->Temp_JDZ_Parameter.Motion_Dir[1]]);
        ui->Btn_Zdirection->setText(Move_Direction[GP->Temp_JDZ_Parameter.Motion_Dir[2]]);
        ui->Btn_Odirection->setText(Move_Direction[GP->Temp_JDZ_Parameter.Motion_Dir[3]]);

        flag = FALSE;
    }
}

void SysSet::Refresh_JDZ_Axis(u8 flag, int dialog_page)
{
    if(flag == TRUE)
    {
        if(dialog_page == 4)
        {
            ui->stackedWidget_tip->setCurrentIndex(dialog_page);
            ui->label_axisMachback0->setText(JDZ_Axis[GP->JDZ_Machine_Ori_Axis_Num]);   //机械原点回零轴显示
            ui->stackedWidget_tip->show();
        }
        else if(dialog_page == 5)
        {
            ui->stackedWidget_tip->setCurrentIndex(dialog_page);
            ui->label_axisOriginRst->setText(JDZ_Axis[GP->JDZ_Origin_Setting_Axis_Num]);    //原点设置
            ui->stackedWidget_tip->show();
        }
        else if(dialog_page == 6)
        {
            ui->stackedWidget_tip->setCurrentIndex(dialog_page);
            ui->label_axisOriginSet->setText(JDZ_Axis[GP->JDZ_Origin_Resetting_Axis_Num]);  //原点重置回零轴显示
            ui->stackedWidget_tip->show();
        }

        flag = FALSE;
    }
}

//功能设定--用户变量设定刷新
void SysSet::Reflash_Fuction_USER(u8 flag)
{
    if(flag == TRUE)
    {
        for(int i=0; i<USER_NUM; i++)
        {
            GP->Parameter_StringChang(GP->Temp_Display_Data, 0, GP->Temp_USER_Parameter.USER_Name1[i],
                                      GP->Temp_USER_Parameter.USER_Name2[i], GP->Temp_USER_Parameter.USER_Name3[i]);
            Eidt_USER_Name.at(i)->setText(GP->u8toqstr(GP->Temp_Display_Data, 10));
            Eidt_USER_InitVal.at(i)->setText(QString::number(GP->Temp_USER_Parameter.INIT_Num[i]));
            Eidt_USER_CurVal.at(i)->setText(QString::number(GP->Temp_USER_Parameter.CURR_Num[i]));
            Btn_USER_BootRst.at(i)->setText(ELECRESET_Switch[GP->Temp_USER_Parameter.ELEC_RESET[i]]);
            Btn_USER_StartRst.at(i)->setText(STARTRESET_Switch[GP->Temp_USER_Parameter.START_RESET[i]]);
        }
        flag = FALSE;
    }
}

//功能设定--用户变量设定刷新 保存后刷新
void SysSet::Reflash_Save_USER(u8 flag)
{
    if(flag == TRUE)
    {
        for(int i=0; i<USER_NUM; i++)
        {
            GP->Parameter_StringChang(GP->Temp_Display_Data, 0, GP->USER_Parameter.USER_Name1[i],
                                      GP->USER_Parameter.USER_Name2[i], GP->USER_Parameter.USER_Name3[i]);
            Eidt_USER_Name.at(i)->setText(GP->u8toqstr(GP->Temp_Display_Data, 10));
            Eidt_USER_InitVal.at(i)->setText(QString::number(GP->USER_Parameter.INIT_Num[i]));
            Eidt_USER_CurVal.at(i)->setText(QString::number(GP->USER_Parameter.CURR_Num[i]));
            Btn_USER_BootRst.at(i)->setText(ELECRESET_Switch[GP->USER_Parameter.ELEC_RESET[i]]);
            Btn_USER_StartRst.at(i)->setText(STARTRESET_Switch[GP->USER_Parameter.START_RESET[i]]);
        }
        flag = FALSE;
    }
}

//功能设定--坐标系参数刷新
void SysSet::Refresh_Cartesian(u8 flag)
{
    if(flag == TRUE)
    {
        ui->Btn_crood->setText(CarCoord_Switch[GP->sCartesian_Para.carCoordSwitch]);
        ui->Edit_armL1->setText(QString::number(GP->sCartesian_Para.length[0]));
        ui->Edit_armL2->setText(QString::number(GP->sCartesian_Para.length[1]));
        ui->Edit_pitch->setText(QString::number(GP->sCartesian_Para.pitchLength));
        ui->Edit_maxSpeed->setText(QString::number(GP->sCartesian_Para.maxSpeed));
        ui->Edit_SpeedUpTime->setText(QString::number(GP->sCartesian_Para.accTime));
        ui->Edit_pSpeedUp->setText(QString::number(GP->sCartesian_Para.accAcc));

        ui->Btn_Xtype->setText(AXISType_Switch[GP->sCartesian_Para.axisType[0]]);
        ui->Btn_Ytype->setText(AXISType_Switch[GP->sCartesian_Para.axisType[1]]);
        ui->Btn_Ztype->setText(AXISType_Switch[GP->sCartesian_Para.axisType[2]]);
        ui->Btn_Otype->setText(AXISType_Switch[GP->sCartesian_Para.axisType[3]]);

        ui->Btn_Xlink->setText(PF_Switch[GP->sCartesian_Para.axisInterpFlag[0]]);
        ui->Btn_Ylink->setText(PF_Switch[GP->sCartesian_Para.axisInterpFlag[1]]);
        ui->Btn_Zlink->setText(PF_Switch[GP->sCartesian_Para.axisInterpFlag[2]]);
        ui->Btn_Olink->setText(PF_Switch[GP->sCartesian_Para.axisInterpFlag[3]]);

        ui->Btn_Xback->setText(MD_axisBackMinDir[GP->sCartesian_Para.axisBackMinDir[0]]);
        ui->Btn_Yback->setText(MD_axisBackMinDir[GP->sCartesian_Para.axisBackMinDir[1]]);
        ui->Btn_Zback->setText(MD_axisBackMinDir[GP->sCartesian_Para.axisBackMinDir[2]]);
        ui->Btn_Oback->setText(MD_axisBackMinDir[GP->sCartesian_Para.axisBackMinDir[3]]);
        flag = FALSE;
    }
}

//笛卡尔坐标系设定--当前机器类型改变
void SysSet::on_comboBox_machType_currentIndexChanged(int index)
{
    GP->sCartesian_Para.MDCoordType = index;
    GP->g_AxiseCarteType = 0;
    GP->gs_AxiseCarteType_Refresh = TRUE;
    GP->gs_Refresh_Speed_Para = TRUE;
    GP->gs_Point_Display_Refresh = TRUE;

    pWidget->AxiseCarteType_Refresh(GP->gs_AxiseCarteType_Refresh);
    pWidget->f_Axis_Position_Refresh(1);
    GP->f_send_Cartesian();
}

//机械手设置--轴个数
void SysSet::on_comboBox_mechAxisNum_currentIndexChanged(int index)
{
    //根据新的轴个数，设置新的回原点方式
    switch (index) {
    case 0://FAN_X
        GP->Temp_JXS_Parameter.Axis = FAN_X;
        GP->Temp_JXS_Parameter.Origin = FOM_X;
        break;
    case 1://FAN_Z
        GP->Temp_JXS_Parameter.Axis = FAN_Z;
        GP->Temp_JXS_Parameter.Origin = FOM_Z;
        break;
    case 2://FAN_Y
        GP->Temp_JXS_Parameter.Axis = FAN_Y;
        GP->Temp_JXS_Parameter.Origin = FOM_Y;
        break;
    case 3://FAN_O
        GP->Temp_JXS_Parameter.Axis = FAN_O;
        GP->Temp_JXS_Parameter.Origin = FOM_O;
        break;
    case 4://FAN_X_Y
        GP->Temp_JXS_Parameter.Axis = FAN_X_Y;
        GP->Temp_JXS_Parameter.Origin = FOM_Y_X;
        break;
    case 5://FAN_X_Z
        GP->Temp_JXS_Parameter.Axis = FAN_X_Z;
        GP->Temp_JXS_Parameter.Origin = FOM_Z_X;
        break;
    case 6://FAN_X_O
        GP->Temp_JXS_Parameter.Axis = FAN_X_O;
        GP->Temp_JXS_Parameter.Origin = FOM_O_X;
        break;
    case 7://FAN_X_Z_L
        GP->Temp_JXS_Parameter.Axis = FAN_X_Z_L;
        GP->Temp_JXS_Parameter.Origin = FOM_Z_X_L;
        break;
    case 8://FAN_X_Z_L_O
        GP->Temp_JXS_Parameter.Axis = FAN_X_Z_L_O;
        GP->Temp_JXS_Parameter.Origin = FOM_Z_L_X_O;
        break;
    default:
        break;
    }
    SET::gs_Refresh_Origin_Method = TRUE;
    Refresh_Origin_Method(SET::gs_Refresh_Origin_Method);
}

//机械手设置--回原点方式设置
void SysSet::on_Btn_returnOriginWay_clicked()
{
    if(GP->Temp_JXS_Parameter.Origin == FOM_Y_X)
    {
        GP->Temp_JXS_Parameter.Origin = FOM_X_Y;
    }
    else if(GP->Temp_JXS_Parameter.Origin == FOM_X_Y)
    {
        GP->Temp_JXS_Parameter.Origin = FOM_Y_X;
    }

    else if(GP->Temp_JXS_Parameter.Origin == FOM_Z_X)
    {
        GP->Temp_JXS_Parameter.Origin = FOM_X_Z;
    }
    else if(GP->Temp_JXS_Parameter.Origin == FOM_X_Z)
    {
        GP->Temp_JXS_Parameter.Origin = FOM_Z_X;
    }

    else if(GP->Temp_JXS_Parameter.Origin == FOM_O_X)
    {
    }

    else if(GP->Temp_JXS_Parameter.Origin == FOM_Z_X_L)
    {
        GP->Temp_JXS_Parameter.Origin = FOM_Z_L_X;
    }
    else if(GP->Temp_JXS_Parameter.Origin == FOM_Z_L_X)
    {
        GP->Temp_JXS_Parameter.Origin = FOM_Z_X_L;
    }

    else if(GP->Temp_JXS_Parameter.Origin == FOM_Z_L_X_O)
    {
        GP->Temp_JXS_Parameter.Origin = FOM_Z_X_L_O;
    }
    else if(GP->Temp_JXS_Parameter.Origin == FOM_Z_X_L_O)
    {
        GP->Temp_JXS_Parameter.Origin = FOM_L_O_Z_X;
    }
    else if(GP->Temp_JXS_Parameter.Origin == FOM_L_O_Z_X)
    {
        GP->Temp_JXS_Parameter.Origin = FOM_Z_O_X_L;
    }
    else if(GP->Temp_JXS_Parameter.Origin == FOM_Z_O_X_L)
    {
        GP->Temp_JXS_Parameter.Origin = FOM_O_Z_X_L;
    }
    else if(GP->Temp_JXS_Parameter.Origin == FOM_O_Z_X_L)
    {
        GP->Temp_JXS_Parameter.Origin = FOM_X_Z_L_O;
    }
    else if(GP->Temp_JXS_Parameter.Origin == FOM_X_Z_L_O)
    {
        GP->Temp_JXS_Parameter.Origin = FOM_Z_L_X_O;
    }
    SET::gs_Refresh_Origin_Method = TRUE;
    Refresh_Origin_Method(SET::gs_Refresh_Origin_Method);
}

//绝对值参数设定--伺服选择
void SysSet::on_comboBox_servoSel_currentIndexChanged(int index)
{
    switch (index) {
    case 0: //禾川
        GP->Temp_JDZ_Parameter.Server = 0;
        break;
    case 1: //汇川
        GP->Temp_JDZ_Parameter.Server = 1;
        break;
    case 2: //迈信
        GP->Temp_JDZ_Parameter.Server = 2;
        break;
    case 3: //德宝
        GP->Temp_JDZ_Parameter.Server = 3;
        break;
    case 4: //星普
        GP->Temp_JDZ_Parameter.Server = 4;
        break;
    case 5: //禾川Y7
        GP->Temp_JDZ_Parameter.Server = 5;
        break;
    case 6: //红森
        GP->Temp_JDZ_Parameter.Server = 6;
        break;
    case 7: //英科
        GP->Temp_JDZ_Parameter.Server = 7;
        break;
    default:
        break;
    }
    GP->gs_Reflash_Fuction_JDZ = TRUE;
    Reflash_Fuction_JDZ(GP->gs_Reflash_Fuction_JDZ);
}

//绝对值参数设定--编码器分辨率
void SysSet::on_comboBox_encoder_currentIndexChanged(int index)
{
    GP->Temp_JDZ_Parameter.Resolu++;
    if(GP->Temp_JDZ_Parameter.Resolu > 3)
    {
        GP->Temp_JDZ_Parameter.Resolu = 0;
    }
    GP->gs_Reflash_Fuction_JDZ = TRUE;
    Reflash_Fuction_JDZ(GP->gs_Reflash_Fuction_JDZ);
}
