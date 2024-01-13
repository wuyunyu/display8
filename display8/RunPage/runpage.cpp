#include "runpage.h"
#include "ui_runpage.h"
#include "mainWidget.h"
#include "ui_mainWidget.h"

RunPage::RunPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RunPage)
{
    ui->setupUi(this);

    pWidget = static_cast<Widget*>(parent);

    this->init();

    connect(ui->Btn_output, &QPushButton::clicked, this, [=](){
        pWidget->prodParaPage();
    });

    connect(ui->Btn_stop, &QPushButton::clicked, this, [=](){
        pWidget->Stop();
    });
    connect(ui->Btn_pause, &QPushButton::clicked, this, [=](){
        pWidget->Stop();
    });
    connect(ui->Btn_start, &QPushButton::clicked, this, [=](){
        pWidget->Auto();
    });
    connect(ui->Btn_oneCycle, &QPushButton::clicked, this, [=](){
        pWidget->cycle();
    });

    //开机界面--设定产量-当前产量-清零
    connect(ui->Btn_clr, &QPushButton::clicked, this, [=](){
        if(GP->Robot_Status == ACTION_STOP)
        {
            GP->SC_Parameter.RW_Num = 0;
            GP->SC_Parameter.SC_Num = 0;
            ui->Edit_setOutput->setText(QString::number(GP->SC_Parameter.RW_Num));
            ui->label_nowOutput->setText(QString::number(GP->SC_Parameter.SC_Num));
            GP->f_Send_SCPara();
        }
    });

    //开机界面--当前物品
    connect(ui->Btn_nowMaterials, &QPushButton::clicked, this, [=](){
        if(GP->Robot_Status == ACTION_STOP)
        {
            GP->m_Choose_Good_Mode = 5;
            GP->m_MD_Good_Page = 1;
//            MD_NameGet(1);
            pWidget->stackingPage();
        }
    });

    //当前物品-当前层数-当前个数 重置
    connect(ui->Btn_reset, &QPushButton::clicked, this, [=](){
        if(GP->Robot_Status == ACTION_STOP)
        {
            GP->sMD_RunPara.curGood = GP->sMD_RunPara.startGood;
//            Order_Temp[0] = MD_CURLAYER_CURNUM;  				//查询机当前物品的当前层和当前个数
//            Order_Temp[1] = sMD_RunPara.curGood;  				//当前物品号
//            USART1_SendData(2, WATCH_COMMAND, &Order_Temp[0]);
            GP->f_Send_SCPara();
            GP->m_Reflash_Run_MD = TRUE;
//            Order_Temp[0] = AUTO_PARAMETER;
//            USART1_SendData(1,WATCH_COMMAND,&Order_Temp[0]);
        }
    });
}

RunPage::~RunPage()
{
    delete ui;
}

void RunPage::init()
{
    ui->stackedWidget_tip->hide();

    ui->label_speed->setText(QString::number((int)GP->JXS_Parameter.SpeedLevel));
    ui->label_progName->setText(GP->u8toqstr(GP->Temp_Display_Data,12));
}

void RunPage::on_Btn_Cancel_clicked()
{
    ui->stackedWidget_tip->hide();
}

void RunPage::on_Btn_back0OK_clicked()
{
    ui->stackedWidget_tip->hide();
}

void RunPage::on_Btn_back0Cancel_clicked()
{
    ui->stackedWidget_tip->hide();
}

void RunPage::on_Btn_rstOK_clicked()
{
    ui->stackedWidget_tip->hide();
}

void RunPage::on_Btn_rstCancel_clicked()
{
    ui->stackedWidget_tip->hide();
}

