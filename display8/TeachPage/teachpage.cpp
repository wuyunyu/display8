#include "teachpage.h"
#include "ui_teachpage.h"
#include "mainWidget.h"
#include "ui_mainWidget.h"

QString TeachPage::inputPort = "X";
QString TeachPage::outputPort = "Y";

TeachPage::TeachPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeachPage)
{
    ui->setupUi(this);

    this->init();

    pWidget = static_cast<Widget*>(parent);

    /////////////////////////////编辑对话框开始/////////////////////////////
    connect(ui->Btn_mainProg, &QPushButton::clicked, this, [=](){
        pWidget->showEditTeach(MainProg_id);
    });
    connect(ui->Btn_subProg, &QPushButton::clicked, this, [=](){
        pWidget->showEditTeach(SubProg_id);
    });
    connect(ui->Btn_axisMove, &QPushButton::clicked, this, [=](){
        pWidget->showEditTeach(AxisMove_id);
    });
    connect(ui->Btn_incMotion, &QPushButton::clicked, this, [=](){
        pWidget->showEditTeach(IncMotion_id);
    });
    connect(ui->Btn_stackPos, &QPushButton::clicked, this, [=](){
        pWidget->showEditTeach(StackPos_id);
    });
    connect(ui->Btn_stackCnt, &QPushButton::clicked, this, [=](){
        pWidget->showEditTeach(StackCnt_id);
    });
    connect(ui->Btn_userVar, &QPushButton::clicked, this, [=](){
        pWidget->showEditTeach(UserVar_id);
    });
    connect(ui->Btn_pulseWidthOutput, &QPushButton::clicked, this, [=](){
        pWidget->showEditTeach(PulseWidthOutput_id);
//        GP.Program_Buffer.Value1 = SET::g_IO_Detect_Output | 0xc0000000;
//        GP.Parameter_StringChang(GP.Temp_Display_Data, 0,
//                                 GP.IO_Name_Parameter[GP.Program_Buffer.Value1].Name,
//                                 GP.IO_Name_Parameter[GP.Program_Buffer.Value1].Name1,
//                                 GP.IO_Name_Parameter[GP.Program_Buffer.Value1].Name2);
//        TEACH::teach_dialog_flag = PulseWidthOutput_id;
    });
    connect(ui->Btn_judgeCond, &QPushButton::clicked, this, [=](){
        pWidget->showEditTeach(JudgeCond_id);
//        GP.Program_Buffer.Value2 = SET::g_IO_Detect_Output | 0xc0000000;
//        GP.Parameter_StringChang(GP.Temp_Display_Data, 0,
//                                 GP.IO_Name_Parameter[GP.Program_Buffer.Value2].Name,
//                                 GP.IO_Name_Parameter[GP.Program_Buffer.Value2].Name1,
//                                 GP.IO_Name_Parameter[GP.Program_Buffer.Value2].Name2);
//        TEACH::teach_dialog_flag = JudgeCond_id;
    });
    connect(ui->Btn_loopCond, &QPushButton::clicked, this, [=](){
        pWidget->showEditTeach(LoopCond_id);
    });
    connect(ui->Btn_jump, &QPushButton::clicked, this, [=](){
        pWidget->showEditTeach(Jump_id);
    });
    connect(ui->Btn_delay, &QPushButton::clicked, this, [=](){
        pWidget->showEditTeach(Delay_id);
    });
    connect(ui->Btn_otherwise, &QPushButton::clicked, this, [=](){
        pWidget->showEditTeach(Otherwise_id);
    });
    connect(ui->Btn_specialCmd, &QPushButton::clicked, this, [=](){
        pWidget->showEditTeach(SpecialCmd_id);
    });
    connect(ui->Btn_outputDetect, &QPushButton::clicked, this, [=](){
        pWidget->showEditTeach(OutputDetect_id);
//        GP.Program_Buffer.Value1 = SET::g_IO_Detect_Output | 0xc0000000;
//        GP.Parameter_StringChang(GP.Temp_Display_Data, 0,
//                                 GP.IO_Name_Parameter[GP.Program_Buffer.Value1].Name,
//                                 GP.IO_Name_Parameter[GP.Program_Buffer.Value1].Name1,
//                                 GP.IO_Name_Parameter[GP.Program_Buffer.Value1].Name2);
//        TEACH::teach_dialog_flag = OutputDetect_id;
    });
    connect(ui->Btn_searchMotion, &QPushButton::clicked, this, [=](){
        pWidget->showEditTeach(SearchMotion_id);
    });
    connect(ui->Btn_machBack0, &QPushButton::clicked, this, [=](){
        pWidget->showEditTeach(MachBack0_id);
    });
    connect(ui->Btn_coordRst, &QPushButton::clicked, this, [=](){
        pWidget->showEditTeach(CoordRst_id);
    });
    connect(ui->Btn_slowDownPoint, &QPushButton::clicked, this, [=](){
        pWidget->showEditTeach(SlowDownPoint_id);
    });
    connect(ui->Btn_interpolationStart, &QPushButton::clicked, this, [=](){
        pWidget->showEditTeach(InterpolationStart_id);
    });
    connect(ui->Btn_advConfirm, &QPushButton::clicked, this, [=](){
        pWidget->showEditTeach(AdvConfirm_id);
    });
    connect(ui->Btn_lineInterpolation, &QPushButton::clicked, this, [=](){
        pWidget->showEditTeach(LineInterpolation_id);
    });
    connect(ui->Btn_transPoint, &QPushButton::clicked, this, [=](){
        pWidget->showEditTeach(TransPoint_id);
    });
    ////////////////////////////////////////编辑对话框结束////////////////////////////////////////

    connect(ui->Btn_outputCtl, &QPushButton::clicked, this, [=](){
        pWidget->ui->Btn_progSel->hide();
        ui->stackedWidget_teach->setCurrentIndex(Output_id);
        ui->Btn_loaclOutputPort->setStyleSheet("background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #00BEFA, stop: 1 #0160EA);");
    });
    connect(ui->Btn_OutPageUp, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_output->setCurrentIndex(0);
    });
    connect(ui->Btn_OutPageDown, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_output->setCurrentIndex(1);
    });
    connect(ui->Btn_OutputBack, &QPushButton::clicked, this, [=](){
        pWidget->ui->Btn_progSel->show();
        ui->stackedWidget_teach->setCurrentIndex(Prog_id);
    });
    connect(ui->Btn_inputDetect, &QPushButton::clicked, this, [=](){
        pWidget->ui->Btn_progSel->hide();
        ui->stackedWidget_teach->setCurrentIndex(Input_id);
        ui->Btn_localInputPort->setStyleSheet("background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #00BEFA, stop: 1 #0160EA);");
    });
    connect(ui->Btn_InPageUp, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_input->setCurrentIndex(0);
    });
    connect(ui->Btn_InPageDown, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_input->setCurrentIndex(1);
    });
    connect(ui->Btn_InputBack, &QPushButton::clicked, this, [=](){
        pWidget->ui->Btn_progSel->show();
        ui->stackedWidget_teach->setCurrentIndex(Prog_id);
    });

    ///////////////////////////////输入检测端口按钮跳转对话框开始/////////////////////////////
    Input(ui->Btn_X0 , InputIO_Detect_IO[0]);
    Input(ui->Btn_X1 , InputIO_Detect_IO[1]);
    Input(ui->Btn_X2 , InputIO_Detect_IO[2]);
    Input(ui->Btn_X3 , InputIO_Detect_IO[3]);
    Input(ui->Btn_X4 , InputIO_Detect_IO[4]);
    Input(ui->Btn_X5 , InputIO_Detect_IO[5]);
    Input(ui->Btn_X6 , InputIO_Detect_IO[6]);
    Input(ui->Btn_X7 , InputIO_Detect_IO[7]);
    Input(ui->Btn_X8 , InputIO_Detect_IO[8]);
    Input(ui->Btn_X9 , InputIO_Detect_IO[9]);
    Input(ui->Btn_X10, InputIO_Detect_IO[10]);
    Input(ui->Btn_X11, InputIO_Detect_IO[11]);
    Input(ui->Btn_X12, InputIO_Detect_IO[12]);
    Input(ui->Btn_X13, InputIO_Detect_IO[13]);
    Input(ui->Btn_X14, InputIO_Detect_IO[14]);
    Input(ui->Btn_X15, InputIO_Detect_IO[15]);
    Input(ui->Btn_X16, InputIO_Detect_IO[16]);
    Input(ui->Btn_X17, InputIO_Detect_IO[17]);
    Input(ui->Btn_X18, InputIO_Detect_IO[18]);
    Input(ui->Btn_X19, InputIO_Detect_IO[19]);
    Input(ui->Btn_X20, InputIO_Detect_IO[20]);
    Input(ui->Btn_X21, InputIO_Detect_IO[21]);
    Input(ui->Btn_X22, InputIO_Detect_IO[22]);
    Input(ui->Btn_X23, InputIO_Detect_IO[23]);
    Input(ui->Btn_X24, InputIO_Detect_IO[24]);
    Input(ui->Btn_X25, InputIO_Detect_IO[25]);
    Input(ui->Btn_X26, InputIO_Detect_IO[26]);
    Input(ui->Btn_X27, InputIO_Detect_IO[27]);
    Input(ui->Btn_X28, InputIO_Detect_IO[28]);
    Input(ui->Btn_X29, InputIO_Detect_IO[29]);
    //////////////////////////////////////////输入检测端口按钮跳转对话框结束////////////////////////////////////////

    ///////////////////////////////输出控制端口按钮跳转对话框开始/////////////////////////////
    Output(ui->Btn_Y0 , OutputIO_Detect_IO[0]);
    Output(ui->Btn_Y1 , OutputIO_Detect_IO[1]);
    Output(ui->Btn_Y2 , OutputIO_Detect_IO[2]);
    Output(ui->Btn_Y3 , OutputIO_Detect_IO[3]);
    Output(ui->Btn_Y4 , OutputIO_Detect_IO[4]);
    Output(ui->Btn_Y5 , OutputIO_Detect_IO[5]);
    Output(ui->Btn_Y6 , OutputIO_Detect_IO[6]);
    Output(ui->Btn_Y7 , OutputIO_Detect_IO[7]);
    Output(ui->Btn_Y8 , OutputIO_Detect_IO[8]);
    Output(ui->Btn_Y9 , OutputIO_Detect_IO[9]);
    Output(ui->Btn_Y10, OutputIO_Detect_IO[10]);
    Output(ui->Btn_Y11, OutputIO_Detect_IO[11]);
    Output(ui->Btn_Y12, OutputIO_Detect_IO[12]);
    Output(ui->Btn_Y13, OutputIO_Detect_IO[13]);
    Output(ui->Btn_Y14, OutputIO_Detect_IO[14]);
    Output(ui->Btn_Y15, OutputIO_Detect_IO[15]);
    Output(ui->Btn_Y16, OutputIO_Detect_IO[16]);
    Output(ui->Btn_Y17, OutputIO_Detect_IO[17]);
    Output(ui->Btn_Y18, OutputIO_Detect_IO[18]);
    Output(ui->Btn_Y19, OutputIO_Detect_IO[19]);
    Output(ui->Btn_Y20, OutputIO_Detect_IO[20]);
    Output(ui->Btn_Y21, OutputIO_Detect_IO[21]);
    Output(ui->Btn_Y22, OutputIO_Detect_IO[22]);
    Output(ui->Btn_Y23, OutputIO_Detect_IO[23]);
    Output(ui->Btn_Y24, OutputIO_Detect_IO[24]);
    Output(ui->Btn_Y25, OutputIO_Detect_IO[25]);
    Output(ui->Btn_Y26, OutputIO_Detect_IO[26]);
    Output(ui->Btn_Y27, OutputIO_Detect_IO[27]);
    Output(ui->Btn_RY0, OutputIO_Detect_IO[28]);
    Output(ui->Btn_RY1, OutputIO_Detect_IO[29]);
    //////////////////////////////////////////输出控制端口按钮跳转对话框结束////////////////////////////////////////
}

TeachPage::~TeachPage()
{
    delete ui;
}

void TeachPage::init()
{
    SET::g_IO_Detect_Output = 29;
    ui->stackedWidget_teach->setCurrentIndex(Prog_id);
    ui->stackedWidget_menu->setCurrentIndex(MainMenu_id);
    ui->stackedWidget_input->setCurrentIndex(0);
    ui->stackedWidget_output->setCurrentIndex(0);
    ui->stackedWidget_tip->hide();

    ui->Arm_tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->Arm_tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    bPush0 = bPush1 = false;
}

//基本指令和轴控指令之间的逻辑控制处理
void TeachPage::on_Btn_basicCmd_clicked()
{
    bPush0 = !bPush0;
    if(bPush0)
    {
        ui->stackedWidget_menu->setCurrentIndex(BasicCmd_id);
        ui->Btn_basicCmd->setStyleSheet("background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #00BEFA, stop: 1 #0160EA);");
        ui->Btn_axisCtlCmd->setStyleSheet("background-color:#F2F2F2;");
        bPush1 = false;
    }
    else
    {
        ui->stackedWidget_menu->setCurrentIndex(MainMenu_id);
        ui->Btn_basicCmd->setStyleSheet("background-color:#F2F2F2;");
    }
}

//轴控指令和基本指令之间的逻辑控制处理
void TeachPage::on_Btn_axisCtlCmd_clicked()
{
    bPush1= !bPush1;
    if(bPush1)
    {
        ui->stackedWidget_menu->setCurrentIndex(AxisCtlCmd_id);
        ui->Btn_axisCtlCmd->setStyleSheet("background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #00BEFA, stop: 1 #0160EA);");
        ui->Btn_basicCmd->setStyleSheet("background-color:#F2F2F2;");
        bPush0 = false;
    }
    else
    {
        ui->stackedWidget_menu->setCurrentIndex(MainMenu_id);
        ui->Btn_axisCtlCmd->setStyleSheet("background-color:#F2F2F2;");
    }
}



void TeachPage::on_Btn_moveUp_clicked()
{
    int curRow = ui->Arm_tableWidget->currentRow();
    if(curRow != -1)
    {
        if(curRow != 0)
        {
            if(ui->Arm_tableWidget->item(curRow, 0) == NULL)
            {
                QMessageBox::critical(this, tr("出现错误"), tr("无法移动：选中行中没有指令"));
            }
            else
            {
                QString strTemp = ui->Arm_tableWidget->item(curRow, 0)->text();
                QTableWidgetItem *item = new QTableWidgetItem(strTemp);
                ui->Arm_tableWidget->setItem(curRow, 0, ui->Arm_tableWidget->item(curRow-1, 0));
                ui->Arm_tableWidget->setItem(curRow-1, 0, item);
            }
        }
        else
        {
            QMessageBox::critical(this, tr("出现错误"), tr("无法移动：已经是第一行"));
        }
    }
    else
    {
        if(ui->Arm_tableWidget->rowCount() != 0)
        {
            QMessageBox::critical(this, tr("出现错误"), tr("无法移动：未选中指令"));
        }
        else
            return;
    }
}

void TeachPage::on_Btn_moveDown_clicked()
{
    int curRow = ui->Arm_tableWidget->currentRow();
    if(curRow != -1)
    {
        if(curRow != (ui->Arm_tableWidget->rowCount() - 1))
        {
            if(ui->Arm_tableWidget->item(curRow, 0) == NULL)
            {
                QMessageBox::critical(this, tr("出现错误"), tr("无法移动：选中行中没有指令"));
            }
            else
            {
                QString strTemp = ui->Arm_tableWidget->item(curRow, 0)->text();
                QTableWidgetItem *item = new QTableWidgetItem(strTemp);
                ui->Arm_tableWidget->setItem(curRow, 0, ui->Arm_tableWidget->item(curRow+1, 0));
                ui->Arm_tableWidget->setItem(curRow+1, 0, item);
            }
        }
        else
        {
            QMessageBox::critical(this, tr("出现错误"), tr("无法移动：已经是最后一行"));
        }

    }
    else
    {
        if(ui->Arm_tableWidget->rowCount() != 0)
        {
            QMessageBox::critical(this, tr("出现错误"), tr("无法移动：未选中指令"));
        }
        else
            return;
    }
}

void TeachPage::on_Btn_delete_clicked()
{
    int curRow = ui->Arm_tableWidget->currentRow();
    ui->Arm_tableWidget->removeRow(curRow);
}

