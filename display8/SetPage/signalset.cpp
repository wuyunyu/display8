#include "signalset.h"
#include "ui_signalset.h"
#include "mainWidget.h"

SignalSet::SignalSet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignalSet)
{
    ui->setupUi(this);

    pWidget = static_cast<Widget*>(parent);

    init();

    //返回设置子界面
    connect(ui->Btn_back, &QPushButton::clicked, this, [=](){
        pWidget->backSetPage();
    });

    connect(ui->Btn_InputSet, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(InputSet_id);
        ui->stackedWidget_dialog->setCurrentIndex(InputSetDialog_id);
    });
    connect(ui->Btn_inputPageUp, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_input->setCurrentIndex(0);
    });
    connect(ui->Btn_inputPageDown, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_input->setCurrentIndex(1);
    });

    ////输入IO设置界面信号和槽的链接
    for(int i = 0; i < INPUT_NUM; i++)
    {
        connect(Btn_X_List.at(i), &QPushButton::clicked, this, [=](){
            if(Global::LCD_Main_Page == FREE_PROGRAMME)
            {//自由编程页面-输入口选择
                SET::g_IO_Detect_Input = i;
                pWidget->EditTeach_ui->dispInputPortText(SET::g_IO_Detect_Input);
            }
            else if(Global::LCD_Main_Page == START_UP)
            {//配方页面-输入口选择
                SET::g_IO_Detect_Input = i;
                pWidget->Formula_ui->dispIOPortText(SET::g_IO_Detect_Input);
            }
            else
            {
                Global::Temp_IO_Detect_Parameter = i;
                ui->stackedWidget_dialog->show();
                InputPort_DialogShow(Global::Temp_IO_Detect_Parameter);
            }
        });
    }

    connect(ui->Btn_InputSetOk, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_dialog->hide();
    });
    connect(ui->Btn_InputSetCancel, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_dialog->hide();
    });
    connect(ui->Btn_inputBack, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_dialog->hide();
        ui->stackedWidget->setCurrentIndex(IOSetSel_id);
    });

    connect(ui->Btn_OutputSet, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(OutputSet_id);
        ui->stackedWidget_dialog->setCurrentIndex(OutputSetDialog_id);
    });
    connect(ui->Btn_outputPageUp, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_output->setCurrentIndex(0);
    });
    connect(ui->Btn_outputPageDown, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_output->setCurrentIndex(1);
    });

    ////输出IO设置界面信号和槽的链接
    for(int i = 0; i < OUTPUT_NUM; i++)
    {
        connect(Btn_Y_List.at(i), &QPushButton::clicked, this, [=](){
            if(Global::LCD_Main_Page == FREE_PROGRAMME)
            {//自由编程界面，脉宽输出、输出检测、O方式的输出口选择
                SET::g_IO_Detect_Output = i;
                pWidget->EditTeach_ui->dispIOPortText(SET::g_IO_Detect_Output);
            }
            else if(Global::gs_MDgripSetFlag == TRUE)
            {//机械手设置页面端口选择
                if(Global::Temp_JXS_Parameter.MDgripSwitch == 1)
                {
                    u8 OutputPort = i;
                    pWidget->SysSet_ui->JXS_Set_dispPort(OutputPort);
                }
            }
            else if(Global::m_MD_GasPort_Flag == TRUE)
            {//码垛参数设置页面气缸端口选择
                Global::sMD_Parameter.gasPort = i;
                pWidget->StackPara_ui->dispIOPortText(Global::sMD_Parameter.gasPort);
            }
            else
            {
                Global::Temp_IO_Detect_Parameter = i;
                ui->stackedWidget_dialog->show();
                OutputPort_DialogShow(Global::Temp_IO_Detect_Parameter);
            }
        });
    }

    connect(ui->Btn_OutputSetOk, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_dialog->hide();
    });
    connect(ui->Btn_OutputSetCancel, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_dialog->hide();
    });
    connect(ui->Btn_outputBack, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_dialog->hide();
        ui->stackedWidget->setCurrentIndex(IOSetSel_id);
    });
}

SignalSet::~SignalSet()
{
    delete ui;
}

void SignalSet::init()
{
    Btn_X_List<<ui->Btn_X0<<ui->Btn_X1<<ui->Btn_X2<<ui->Btn_X3<<ui->Btn_X4<<ui->Btn_X5
              <<ui->Btn_X6<<ui->Btn_X7<<ui->Btn_X8<<ui->Btn_X9<<ui->Btn_X10<<ui->Btn_X11
              <<ui->Btn_X12<<ui->Btn_X13<<ui->Btn_X14<<ui->Btn_X15<<ui->Btn_X16<<ui->Btn_X17
              <<ui->Btn_X18<<ui->Btn_X19<<ui->Btn_X20<<ui->Btn_X21<<ui->Btn_X22<<ui->Btn_X23
              <<ui->Btn_X24<<ui->Btn_X25<<ui->Btn_X26<<ui->Btn_X27<<ui->Btn_X28<<ui->Btn_X29;

    Btn_Y_List<<ui->Btn_Y0<<ui->Btn_Y1<<ui->Btn_Y2<<ui->Btn_Y3<<ui->Btn_Y4<<ui->Btn_Y5
              <<ui->Btn_Y6<<ui->Btn_Y7<<ui->Btn_Y8<<ui->Btn_Y9<<ui->Btn_Y10<<ui->Btn_Y11
              <<ui->Btn_Y12<<ui->Btn_Y13<<ui->Btn_Y14<<ui->Btn_Y15<<ui->Btn_Y16<<ui->Btn_Y17
              <<ui->Btn_Y18<<ui->Btn_Y19<<ui->Btn_Y20<<ui->Btn_Y21<<ui->Btn_Y22<<ui->Btn_Y23
             <<ui->Btn_Y24<<ui->Btn_Y25<<ui->Btn_Y26<<ui->Btn_Y27<<ui->Btn_RY0<<ui->Btn_RY1;

    Label_RstSel_List<<ui->label_RstSel1<<ui->label_RstSel2<<ui->label_RstSel3<<ui->label_RstSel4<<ui->label_RstSel5<<ui->label_RstSel6;
    CheckBox_RstSel_List<<ui->checkBox_RstSel1<<ui->checkBox_RstSel2<<ui->checkBox_RstSel3<<ui->checkBox_RstSel4<<ui->checkBox_RstSel5<<ui->checkBox_RstSel6;

    ui->stackedWidget->setCurrentIndex(IOSetSel_id);
    ui->stackedWidget_input->setCurrentIndex(0);
    ui->stackedWidget_output->setCurrentIndex(0);
    ui->stackedWidget_dialog->hide();
}

//进入输入设置界面首页
void SignalSet::InputSetPage()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->stackedWidget_input->setCurrentIndex(0);
}

//进入输出设置界面首页
void SignalSet::OutputSetPage()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->stackedWidget_output->setCurrentIndex(0);
}

//输入设置界面端口修改窗口显示
void SignalSet::InputPort_DialogShow(u8 IOProt)
{
    ui->label_inputPort->setText(InputIO_Detect_IO[IOProt]);    //IO设置--设置窗口的输入设置的端口号刷新
    Global::Temp_IO_Name_Parameter_Input[IOProt].Name  = Global::IO_Name_Parameter_Input[IOProt].Name;
    Global::Temp_IO_Name_Parameter_Input[IOProt].Name1 = Global::IO_Name_Parameter_Input[IOProt].Name1;
    Global::Temp_IO_Name_Parameter_Input[IOProt].Name2 = Global::IO_Name_Parameter_Input[IOProt].Name2;
    Global::Parameter_StringChang(Global::Temp_Display_Data1, 0,
                                  Global::Temp_IO_Name_Parameter_Input[IOProt].Name,
                                  Global::Temp_IO_Name_Parameter_Input[IOProt].Name1,
                                  Global::Temp_IO_Name_Parameter_Input[IOProt].Name2);
    ui->Edit_Input->setText(Global::u8toqstr(Global::Temp_Display_Data1, 12));  //输入IO设置-》点击文本-》显示的文本
    ui->Btn_OnOff->setText(IO_Detect_Switch[Global::Temp_IO_Parameter[IOProt].Switch]);  //IO设置--输入设置窗口的常开/常闭刷新
    //IO设置--输入设置窗口的保持时间刷新
    ui->Edit_TimeStart->setText(QString::number(Global::Temp_IO_Parameter[IOProt].minTime));
    ui->Edit_TimeEnd->setText(QString::number(Global::Temp_IO_Parameter[IOProt].maxTime));
}

//输出设置界面端口修改窗口显示
void SignalSet::OutputPort_DialogShow(u8 IOProt)
{
    ui->label_outputPort->setText(OutputIO_Detect_IO[IOProt]);   //IO设置--设置窗口的输出设置的端口号刷新
    Global::Parameter_StringChang(Global::Temp_Display_Data1, 0,
                                  Global::Temp_IO_Name_Parameter[IOProt].Name,
                                  Global::Temp_IO_Name_Parameter[IOProt].Name1,
                                  Global::Temp_IO_Name_Parameter[IOProt].Name2);
    ui->Edit_Output->setText(Global::u8toqstr(Global::Temp_Display_Data1, 12)); //输出IO设置-》点击文本-》显示的文本
    for(int j = 0; j < 6; j++)
    {
        CheckBox_RstSel_List.at(j)->setChecked(false);  //未选中
        Label_RstSel_List.at(j)->setText(Output_Reset_Select_String[j]);
    }
    if((IOProt <= 23)||(IOProt >= 28))
    {
        if(Global::IO_Reset_Select[IOProt].BeforeOrigin == Before_Origin)
        {
            ui->checkBox_RstSel1->setChecked(true);
            ui->label_RstSel1->setText(Output_Reset_Select_String[Global::IO_Reset_Select[IOProt].BeforeOrigin-1]);
        }
        if(Global::IO_Reset_Select[IOProt].AfterOrigin == After_Origin)
        {
            ui->checkBox_RstSel2->setChecked(true);
            ui->label_RstSel2->setText(Output_Reset_Select_String[Global::IO_Reset_Select[IOProt].AfterOrigin-1]);
        }
        if(Global::IO_Reset_Select[IOProt].CommonAlarm == Common_Alarm)
        {
            ui->checkBox_RstSel3->setChecked(true);
            ui->label_RstSel3->setText(Output_Reset_Select_String[Global::IO_Reset_Select[IOProt].CommonAlarm-1]);
        }
        if(Global::IO_Reset_Select[IOProt].EmergeAlarm == Emerge_Alarm)
        {
            ui->checkBox_RstSel4->setChecked(true);
            ui->label_RstSel4->setText(Output_Reset_Select_String[Global::IO_Reset_Select[IOProt].EmergeAlarm-1]);
        }
        if(Global::IO_Reset_Select[IOProt].Pause == PAUSE)
        {
            ui->checkBox_RstSel5->setChecked(true);
            ui->label_RstSel5->setText(Output_Reset_Select_String[Global::IO_Reset_Select[IOProt].Pause-1]);
        }
        if(Global::IO_Reset_Select[IOProt].Stop == STOP)
        {
            ui->checkBox_RstSel6->setChecked(true);
            ui->label_RstSel6->setText(Output_Reset_Select_String[Global::IO_Reset_Select[IOProt].Stop-1]);
        }
    }
}

//输入设置--输入名刷新
void SignalSet::IO_Detect_Display_Refresh_Input()
{
    QList<QLabel*> IO_InputList;
    IO_InputList<<ui->label_X0<<ui->label_X1<<ui->label_X2<<ui->label_X3<<ui->label_X4<<ui->label_X5
                <<ui->label_X6<<ui->label_X7<<ui->label_X8<<ui->label_X9<<ui->label_X10<<ui->label_X11
                <<ui->label_X12<<ui->label_X13<<ui->label_X14<<ui->label_X15<<ui->label_X16<<ui->label_X17
                <<ui->label_X18<<ui->label_X19<<ui->label_X20<<ui->label_X21<<ui->label_X22<<ui->label_X23
                <<ui->label_X24<<ui->label_X25<<ui->label_X26<<ui->label_X27<<ui->label_X28<<ui->label_X29;
    for(int i=0; i<INPUT_NUM; i++)
    {
        Global::Parameter_StringChang(Global::Temp_Display_Data1, 0, Global::IO_Name_Parameter_Input[i].Name,
                                  Global::IO_Name_Parameter_Input[i].Name1, Global::IO_Name_Parameter_Input[i].Name2);
        if(Global::Temp_IO_Switch_Parameter[i]==1 && i>=Input_Special)
        {
            IO_InputList.at(18+(i-Input_Special))->setText(Global::u8toqstr(Global::Temp_Display_Data1, 12));  //红色
            IO_InputList.at(i)->setText(Global::u8toqstr(Global::BlankChar, 12));
        }
        else
        {
            IO_InputList.at(i)->setText(Global::u8toqstr(Global::BlankChar, 12));
            IO_InputList.at(18+(i-Input_Special))->setText(Global::u8toqstr(Global::Temp_Display_Data1, 12));
        }
    }
}

//输出设置--输出名刷新
void SignalSet::IO_Detect_Display_Refresh()
{
    QList<QLabel*> IO_OutputList;
    IO_OutputList<<ui->label_Y0<<ui->label_Y1<<ui->label_Y2<<ui->label_Y3<<ui->label_Y4<<ui->label_Y5
                 <<ui->label_Y6<<ui->label_Y7<<ui->label_Y8<<ui->label_Y9<<ui->label_Y10<<ui->label_Y11
                 <<ui->label_Y12<<ui->label_Y13<<ui->label_Y14<<ui->label_Y15<<ui->label_Y16<<ui->label_Y17
                 <<ui->label_Y18<<ui->label_Y19<<ui->label_Y20<<ui->label_Y21<<ui->label_Y22<<ui->label_Y23
                 <<ui->label_Y24<<ui->label_Y25<<ui->label_Y26<<ui->label_Y27<<ui->label_RY0<<ui->label_RY1;
    for(int i=0; i<OUTPUT_NUM; i++)
    {
        Global::Parameter_StringChang(Global::Temp_Display_Data1, 0, Global::IO_Name_Parameter[i].Name,
                                  Global::IO_Name_Parameter[i].Name1, Global::IO_Name_Parameter[i].Name2);
        if(Global::Temp_OUT_Switch_Parameter[i]==1)
        {
            IO_OutputList.at(22+(i-22))->setText(Global::u8toqstr(Global::Temp_Display_Data1, 12)); //红色
            IO_OutputList.at(i)->setText(Global::u8toqstr(Global::BlankChar, 12));
        }
        else
        {
            IO_OutputList.at(i)->setText(Global::u8toqstr(Global::BlankChar, 12));
            IO_OutputList.at(22+(i-22))->setText(Global::u8toqstr(Global::Temp_Display_Data1, 12));
        }
    }
}



