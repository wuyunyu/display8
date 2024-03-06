#include "manualpage.h"
#include "ui_manualpage.h"
#include "mainWidget.h"

ManualPage::ManualPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManualPage)
{
    ui->setupUi(this);

    pWidget = static_cast<Widget*>(parent);

    this->init();

    connect(ui->Btn_stackding, &QPushButton::clicked, this, [=](){
        pWidget->stackingPage();
    });
    connect(ui->Btn_memoryPoint, &QPushButton::clicked, this, [=](){
        pWidget->memoryPointPage();
    });

    connect(ui->Btn_speedAdd5, &QPushButton::clicked, this, [=](){
        ui->Edit_speed->setText(QString::number(ui->Edit_speed->text().toInt()+5));
    });
    connect(ui->Btn_speedAdd10, &QPushButton::clicked, this, [=](){
        ui->Edit_speed->setText(QString::number(ui->Edit_speed->text().toInt()+10));
    });
    connect(ui->Btn_speedMinus5, &QPushButton::clicked, this, [=](){
        ui->Edit_speed->setText(QString::number(ui->Edit_speed->text().toInt()-5));
    });
    connect(ui->Btn_speedMinus10, &QPushButton::clicked, this, [=](){
        ui->Edit_speed->setText(QString::number(ui->Edit_speed->text().toInt()-10));
    });
    connect(ui->Btn_mulAdd1, &QPushButton::clicked, this, [=](){
        ui->Edit_mul->setText(QString::number(ui->Edit_mul->text().toDouble()+0.1, 'f', 1));
    });
    connect(ui->Btn_mulAdd10, &QPushButton::clicked, this, [=](){
        ui->Edit_mul->setText(QString::number(ui->Edit_mul->text().toDouble()+1, 'f', 1));
    });
    connect(ui->Btn_mulMinus1, &QPushButton::clicked, this, [=](){
        ui->Edit_mul->setText(QString::number(ui->Edit_mul->text().toDouble()-0.1, 'f', 1));
    });
    connect(ui->Btn_mulMinus10, &QPushButton::clicked, this, [=](){
        ui->Edit_mul->setText(QString::number(ui->Edit_mul->text().toDouble()-1, 'f', 1));
    });
}

ManualPage::~ManualPage()
{
    delete ui;
}

void ManualPage::init()
{
    ui->Edit_speed->setText("0");
    ui->Edit_mul->setText("0");
    ui->stackedWidget_dialog->hide();
}

//速度-步进刷新
void ManualPage::Refresh_Speed_Para()
{
    if(Global::g_AxiseCarteType == 0 || Global::g_AxiseCarteType == 2)
    {
        ui->Edit_speed->setText(QString::number(MANUAL::gs_LinkMove_Speed));    //手动调试-连动速度
    }
    else
    {
        ui->Edit_speed->setText(QString::number(MANUAL::gs_Carte_LinkMove_Speed));  //手动调试-连动速度
    }
    ui->Edit_mul->setText(QString::number(MANUAL::gs_StepMove_Distance));       //手动调试-寸动步进
}

//刷新码垛夹爪IO
void ManualPage::Refresh_MD_Circulation()
{
    QList<QLabel*> JawList;
    JawList<<ui->label_jaw1<<ui->label_jaw2<<ui->label_jaw3
          <<ui->label_jaw4<<ui->label_jaw5<<ui->label_jaw6;

    if(Global::JXS_Parameter.MDgripSwitch == 1)
    {
        for(int i = 0; i<MDgrip_Num; i++)
        {
            if(Global::JXS_Parameter.MDgripPort[i] == 0)	//夹爪i端口无效
            {
                JawList.at(i)->setText(MD_InvalidGrip2);
            }
            else
            {
                Global::Parameter_StringChang(Global::Temp_Display_Data1, 0,
                        Global::IO_Name_Parameter[Global::JXS_Parameter.MDgripPort[i]-1].Name,
                        Global::IO_Name_Parameter[Global::JXS_Parameter.MDgripPort[i]-1].Name1,
                        Global::IO_Name_Parameter[Global::JXS_Parameter.MDgripPort[i]-1].Name2);
                JawList.at(i)->setText(Global::u8toqstr(Global::Temp_Display_Data1, 12));
            }
        }
    }
    else
    {
        for(int i = 0; i<MDgrip_Num; i++)
        {
            JawList.at(i)->setText(MD_InvalidGrip2);
        }
    }
}
