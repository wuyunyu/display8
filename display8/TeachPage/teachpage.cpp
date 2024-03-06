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
    for(int i = 0; i < INPUT_NUM; i++)
    {
        connect(Btn_Input_Port.at(i), &QPushButton::clicked, this, [=](){
            inputPort = InputIO_Detect_IO[i];
            ui->stackedWidget_teach->setCurrentIndex(Prog_id);
            pWidget->showEditTeach(InputDetect_id);
        });
    }
    ///////////////////////////////输入检测端口按钮跳转对话框结束/////////////////////////////

    ///////////////////////////////输出控制端口按钮跳转对话框开始/////////////////////////////
    for(int i = 0; i < OUTPUT_NUM; i++)
    {
        connect(Btn_Output_Port.at(i), &QPushButton::clicked, this, [=](){
            outputPort = OutputIO_Detect_IO[i];
            ui->stackedWidget_teach->setCurrentIndex(Prog_id);
            pWidget->showEditTeach(OutputDetect_id);
        });
    }
    ///////////////////////////////输出控制端口按钮跳转对话框结束/////////////////////////////
}

TeachPage::~TeachPage()
{
    delete ui;
}

void TeachPage::init()
{
    Btn_Input_Port<<ui->Btn_X0<<ui->Btn_X1<<ui->Btn_X2<<ui->Btn_X3<<ui->Btn_X4<<ui->Btn_X5<<ui->Btn_X6<<ui->Btn_X7<<ui->Btn_X8<<ui->Btn_X9
                  <<ui->Btn_X10<<ui->Btn_X11<<ui->Btn_X12<<ui->Btn_X13<<ui->Btn_X14<<ui->Btn_X15<<ui->Btn_X16<<ui->Btn_X17<<ui->Btn_X18<<ui->Btn_X19
                  <<ui->Btn_X20<<ui->Btn_X21<<ui->Btn_X22<<ui->Btn_X23<<ui->Btn_X24<<ui->Btn_X25<<ui->Btn_X26<<ui->Btn_X27<<ui->Btn_X28<<ui->Btn_X29;

    Btn_Output_Port<<ui->Btn_Y0<<ui->Btn_Y1<<ui->Btn_Y2<<ui->Btn_Y3<<ui->Btn_Y4<<ui->Btn_Y5<<ui->Btn_Y6<<ui->Btn_Y7<<ui->Btn_Y8<<ui->Btn_Y9
                   <<ui->Btn_Y10<<ui->Btn_Y11<<ui->Btn_Y12<<ui->Btn_Y13<<ui->Btn_Y14<<ui->Btn_Y15<<ui->Btn_Y16<<ui->Btn_Y17<<ui->Btn_Y18<<ui->Btn_Y19
                   <<ui->Btn_Y20<<ui->Btn_Y21<<ui->Btn_Y22<<ui->Btn_Y23<<ui->Btn_Y24<<ui->Btn_Y25<<ui->Btn_Y26<<ui->Btn_Y27<<ui->Btn_RY0<<ui->Btn_RY1;

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

