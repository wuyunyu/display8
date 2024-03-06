#include "setpage.h"
#include "ui_setpage.h"
#include "mainWidget.h"
#include "ui_sysset.h"

SetPage::SetPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetPage)
{
    ui->setupUi(this);

    pWidget = static_cast<Widget*>(parent);

    //进入设置界面的各个子窗口
    connect(ui->Btn_userSet, &QPushButton::clicked, this, [=](){
        pWidget->changeSetPage(User_id);
        SET::gs_Pass_Word_Refresh = TRUE;
        pWidget->UserSet_ui->Pass_Word_Refresh();
    });

    //IO设置
    connect(ui->Btn_signalSet, &QPushButton::clicked, this, [=](){
        pWidget->changeSetPage(Signal_id);
    });

    //软限位设定、安全区域设定,初始为软限位设定页面
    connect(ui->Btn_safeSet, &QPushButton::clicked, this, [=](){
        pWidget->changeSetPage(Safe_id);
        Global::LP_Temp_Save();
        pWidget->SafeSet_ui->Reflash_SoftLimit();
    });

    //功能设定：初始为机械手设定页面
    connect(ui->Btn_sysSet, &QPushButton::clicked, this, [=](){
        pWidget->SysSet_ui->ui->stackedWidget->setCurrentIndex(ArmSet_id);
        pWidget->changeSetPage(System_id);
        Global::JXS_Temp_Save();
        Global::gs_Reflash_Fuction_JXS = TRUE;
        SET::gs_Refresh_Associate = TRUE;
        SET::gs_Refresh_Avoidace = TRUE;
        pWidget->SysSet_ui->Refresh_Fuction_JXS();
        pWidget->SysSet_ui->Refresh_Associate();
        pWidget->SysSet_ui->Refresh_Avoidace();
        pWidget->SysSet_ui->ui->Btn_stackIO->setText(MD_gripSwitch[Global::Temp_JXS_Parameter.MDgripSwitch]);
    });

    //程序管理
    connect(ui->Btn_progSet, &QPushButton::clicked, this, [=](){
        pWidget->changeSetPage(Program_id);
        SET::gs_Current_Choose_Program = 1;
        Global::gs_Program_Display_Refresh = TRUE;
        pWidget->ProgSet_ui->Program_Display_Refresh();
    });

    //物联网
    connect(ui->Btn_exFuncSet, &QPushButton::clicked, this, [=](){
        pWidget->changeSetPage(ExFunction_id);
        pWidget->ExFuncSet_ui->Reflash_Fuction_Internet();
    });
}

SetPage::~SetPage()
{
    delete ui;
}
