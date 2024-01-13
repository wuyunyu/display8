#include "setpage.h"
#include "ui_setpage.h"
#include "mainWidget.h"
#include "ui_userset.h"
#include "ui_sysset.h"
#include "ui_signalset.h"
#include "ui_progset.h"
#include "ui_safeset.h"
#include "ui_exfuncset.h"

SetPage::SetPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetPage)
{
    ui->setupUi(this);

    pWidget = static_cast<Widget*>(parent);

    GP->LCD_Main_Page = SYSTEM_SETTING;     //标志为从设置界面进入个设置子界面

    //进入设置界面的各个子窗口
    connect(ui->Btn_userSet, &QPushButton::clicked, this, [=](){
        pWidget->changeSetPage(User_id);
        SET::gs_Pass_Word_Refresh = TRUE;
        UserSet_ui->Pass_Word_Refresh(SET::gs_Pass_Word_Refresh);
    });
    connect(ui->Btn_signalSet, &QPushButton::clicked, this, [=](){
        pWidget->changeSetPage(Signal_id);
    });
    connect(ui->Btn_safeSet, &QPushButton::clicked, this, [=](){
        pWidget->changeSetPage(Safe_id);
    });
    connect(ui->Btn_sysSet, &QPushButton::clicked, this, [=](){ //功能设定：初始为机械手设定页面
        pWidget->changeSetPage(System_id);
        SysSet_ui->ui->stackedWidget->setCurrentIndex(ArmSet_id);
        GP->JXS_Temp_Save();
        GP->gs_Reflash_Fuction_JXS = TRUE;
        SET::gs_Refresh_Associate = TRUE;
        SET::gs_Refresh_Avoidace = TRUE;
        SysSet_ui->Refresh_Fuction_JXS(GP->gs_Reflash_Fuction_JXS);
        SysSet_ui->Refresh_Associate(SET::gs_Refresh_Associate);
        SysSet_ui->Refresh_Avoidace(SET::gs_Refresh_Avoidace);
    });
    connect(ui->Btn_progSet, &QPushButton::clicked, this, [=](){    //程序管理
        pWidget->changeSetPage(Program_id);
        SET::gs_Current_Choose_Program = 1;
        GP->gs_Program_Display_Refresh = TRUE;
        ProgSet_ui->Program_Display_Refresh(GP->gs_Program_Display_Refresh);
    });
    connect(ui->Btn_exFuncSet, &QPushButton::clicked, this, [=](){
        pWidget->changeSetPage(ExFunction_id);
    });
}

SetPage::~SetPage()
{
    delete ui;
}
