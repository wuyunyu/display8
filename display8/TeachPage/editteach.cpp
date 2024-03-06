#include "editteach.h"
#include "ui_editteach.h"
#include "mainWidget.h"

EditTeach::EditTeach(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditTeach)
{
    ui->setupUi(this);

    pWidget = static_cast<Widget*>(parent);

    //返回编程界面
    connect(ui->Btn_Ok, &QPushButton::clicked, this, [=](){
        pWidget->editTeachEnd();
    });
    connect(ui->Btn_Cancel, &QPushButton::clicked, this, [=](){
        pWidget->editTeachEnd();
    });

    connect(ui->Btn_axisMovePonitSel, &QPushButton::clicked, this, [=](){
        pWidget->FreeProgPage();
    });

    connect(ui->Btn_signalCond, &QPushButton::clicked, this, [=](){
        pWidget->showEditDialog(CondSel_id);
    });

    //自由编程页面-输入输出口选择
    connect(ui->Btn_detectPort, &QPushButton::clicked, this, [=](){
        pWidget->changeSetPage(Signal_id);
    });

    //自由编程页面-脉宽输出端口选择
    connect(ui->Btn_pulseWidthOutputPort, &QPushButton::clicked, this, [=](){
        pWidget->OutputPortSetPage();
        Global::Program_Buffer.Key = K_PULSE_OUTPUT;
        pWidget->SignalSet_ui->IO_Detect_Display_Refresh();
    });

    //自由编程页面-输出检测端口选择
    connect(ui->Btn_OutputDetectPort, &QPushButton::clicked, this, [=](){
        pWidget->OutputPortSetPage();
        Global::Program_Buffer.Key = K_OUTDETECT;
        pWidget->SignalSet_ui->IO_Detect_Display_Refresh();
    });

    AxisMoveSel(ui->Btn_axisMoveX,ui->Btn_axisMoveX->text());
    AxisMoveSel(ui->Btn_axisMoveY,ui->Btn_axisMoveY->text());
    AxisMoveSel(ui->Btn_axisMoveZ,ui->Btn_axisMoveZ->text());
    AxisMoveSel(ui->Btn_axisMoveO,ui->Btn_axisMoveO->text());
    AxisMoveSel(ui->Btn_axisMoveU,ui->Btn_axisMoveU->text());
    AxisMoveSel(ui->Btn_axisMoveV,ui->Btn_axisMoveV->text());
    StackPosSel(ui->Btn_stackPosX,ui->Btn_stackPosX->text());
    StackPosSel(ui->Btn_stackPosY,ui->Btn_stackPosY->text());
    StackPosSel(ui->Btn_stackPosZ,ui->Btn_stackPosZ->text());
    StackPosSel(ui->Btn_stackPosO,ui->Btn_stackPosO->text());
    StackPosSel(ui->Btn_stackPosPointX,ui->Btn_stackPosPointX->text());
    StackPosSel(ui->Btn_stackPosPointY,ui->Btn_stackPosPointY->text());
    StackPosSel(ui->Btn_stackPosPointZ,ui->Btn_stackPosPointZ->text());
    StackPosSel(ui->Btn_stackPosPointO,ui->Btn_stackPosPointO->text());
    SearchMotionSel(ui->Btn_searchMotionX,ui->Btn_searchMotionX->text());
    SearchMotionSel(ui->Btn_searchMotionY,ui->Btn_searchMotionY->text());
    SearchMotionSel(ui->Btn_searchMotionZ,ui->Btn_searchMotionZ->text());
    SearchMotionSel(ui->Btn_searchMotionO,ui->Btn_searchMotionO->text());
    SearchMotionSel(ui->Btn_searchMotionU,ui->Btn_searchMotionU->text());
    SearchMotionSel(ui->Btn_searchMotionV,ui->Btn_searchMotionV->text());
    MachBack0Sel(ui->Btn_machBack0X,ui->Btn_machBack0X->text());
    MachBack0Sel(ui->Btn_machBack0Y,ui->Btn_machBack0Y->text());
    MachBack0Sel(ui->Btn_machBack0Z,ui->Btn_machBack0Z->text());
    MachBack0Sel(ui->Btn_machBack0O,ui->Btn_machBack0O->text());
    MachBack0Sel(ui->Btn_machBack0U,ui->Btn_machBack0U->text());
    MachBack0Sel(ui->Btn_machBack0V,ui->Btn_machBack0V->text());
    CoordRstSel(ui->Btn_coordRstX,ui->Btn_coordRstX->text());
    CoordRstSel(ui->Btn_coordRstY,ui->Btn_coordRstY->text());
    CoordRstSel(ui->Btn_coordRstZ,ui->Btn_coordRstZ->text());
    CoordRstSel(ui->Btn_coordRstO,ui->Btn_coordRstO->text());
    CoordRstSel(ui->Btn_coordRstU,ui->Btn_coordRstU->text());
    CoordRstSel(ui->Btn_coordRstV,ui->Btn_coordRstV->text());
    SlowDownSel(ui->Btn_slowDownX,ui->Btn_slowDownX->text());
    SlowDownSel(ui->Btn_slowDownY,ui->Btn_slowDownY->text());
    SlowDownSel(ui->Btn_slowDownZ,ui->Btn_slowDownZ->text());
    SlowDownSel(ui->Btn_slowDownO,ui->Btn_slowDownO->text());
    SlowDownSel(ui->Btn_slowDownU,ui->Btn_slowDownU->text());
    SlowDownSel(ui->Btn_slowDownV,ui->Btn_slowDownV->text());
    AdvConfirmSel(ui->Btn_advConfirmX,ui->Btn_advConfirmX->text());
    AdvConfirmSel(ui->Btn_advConfirmY,ui->Btn_advConfirmY->text());
    AdvConfirmSel(ui->Btn_advConfirmZ,ui->Btn_advConfirmZ->text());
    AdvConfirmSel(ui->Btn_advConfirmO,ui->Btn_advConfirmO->text());
    AdvConfirmSel(ui->Btn_advConfirmU,ui->Btn_advConfirmU->text());
    AdvConfirmSel(ui->Btn_advConfirmV,ui->Btn_advConfirmV->text());
    TransPointSel(ui->Btn_transPointX,ui->Btn_transPointX->text());
    TransPointSel(ui->Btn_transPointY,ui->Btn_transPointY->text());
    TransPointSel(ui->Btn_transPointZ,ui->Btn_transPointZ->text());
    TransPointSel(ui->Btn_transPointO,ui->Btn_transPointO->text());
    TransPointSel(ui->Btn_transPointU,ui->Btn_transPointU->text());
    TransPointSel(ui->Btn_transPointV,ui->Btn_transPointV->text());
    IncMotionSel(ui->Btn_incMotionX,ui->Btn_incMotionX->text());
    IncMotionSel(ui->Btn_incMotionY,ui->Btn_incMotionY->text());
    IncMotionSel(ui->Btn_incMotionZ,ui->Btn_incMotionZ->text());
    IncMotionSel(ui->Btn_incMotionO,ui->Btn_incMotionO->text());
    IncMotionSel(ui->Btn_incMotionU,ui->Btn_incMotionU->text());
    IncMotionSel(ui->Btn_incMotionV,ui->Btn_incMotionV->text());
}

EditTeach::~EditTeach()
{
    delete ui;
}

void EditTeach::switchDialog(const int dialogID)
{
    ui->stackedWidget_dialog->setCurrentIndex(dialogID);
}

void EditTeach::outputCtlShow(const QString portShow)
{
    ui->Btn_OutputCtlPort->setText(portShow);
}

void EditTeach::inputDetectShow(const QString portShow)
{
    ui->Btn_InputDetectPort->setText(portShow);
}

//自由编程界面，O方式的输入口选择显示
void EditTeach::dispInputPortText(u8 IOPort)
{
    pWidget->backEditTeachPage();   //返回信号条件端口选择页面
    Global::Program_Buffer.Value2 = IOPort | 0xc0000000;
    Global::Parameter_StringChang(Global::Temp_Display_Data,0,
                                  Global::IO_Name_Parameter_Input[Global::Program_Buffer.Value2].Name,
                                  Global::IO_Name_Parameter_Input[Global::Program_Buffer.Value2].Name1,
                                  Global::IO_Name_Parameter_Input[Global::Program_Buffer.Value2].Name2);
    ui->Btn_detectPort->setText(Global::u8toqstr(Global::Temp_Display_Data, 12));
}

//自由编程界面，脉宽输出、输出检测、O方式的输出口选择显示
void EditTeach::dispIOPortText(u8 IOPort)
{
    if(Global::Program_Buffer.Key == K_PULSE_OUTPUT || Global::Program_Buffer.Key == K_OUTDETECT)
    {
        Global::Program_Buffer.Value1 = IOPort | 0xc0000000;
        if(Global::Program_Buffer.Key == K_PULSE_OUTPUT)
        {
            pWidget->backEditTeachPage();   //返回脉宽输出端口选择页面
            Global::Parameter_StringChang(Global::Temp_Display_Data,0,
                                          Global::IO_Name_Parameter[Global::Program_Buffer.Value1].Name,
                                          Global::IO_Name_Parameter[Global::Program_Buffer.Value1].Name1,
                                          Global::IO_Name_Parameter[Global::Program_Buffer.Value1].Name2);
            ui->Btn_pulseWidthOutputPort->setText(Global::u8toqstr(Global::Temp_Display_Data, 12));
        }
        else
        {
            pWidget->backEditTeachPage();   //返回输出检测端口选择页面
            Global::Parameter_StringChang(Global::Temp_Display_Data,0,
                                          Global::IO_Name_Parameter[Global::Program_Buffer.Value1].Name,
                                          Global::IO_Name_Parameter[Global::Program_Buffer.Value1].Name1,
                                          Global::IO_Name_Parameter[Global::Program_Buffer.Value1].Name2);
            ui->Btn_OutputDetectPort->setText(Global::u8toqstr(Global::Temp_Display_Data, 12));
        }
    }
    else if(Global::Program_Buffer.Key == K_IF || Global::Program_Buffer.Key == K_ELSE)
    {
        pWidget->backEditTeachPage();   //返回信号条件端口选择页面
        Global::Program_Buffer.Value2 = IOPort | 0xc0000000;
        Global::Parameter_StringChang(Global::Temp_Display_Data,0,
                                      Global::IO_Name_Parameter[Global::Program_Buffer.Value2].Name,
                                      Global::IO_Name_Parameter[Global::Program_Buffer.Value2].Name1,
                                      Global::IO_Name_Parameter[Global::Program_Buffer.Value2].Name2);
        ui->Btn_detectPort->setText(Global::u8toqstr(Global::Temp_Display_Data, 12));
    }
}

