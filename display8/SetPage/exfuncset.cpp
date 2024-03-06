#include "exfuncset.h"
#include "ui_exfuncset.h"
#include "mainWidget.h"

ExFuncSet::ExFuncSet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExFuncSet)
{
    ui->setupUi(this);

    pWidget = static_cast<Widget*>(parent);

    ui->stackedWidget->setCurrentIndex(0);

    //返回设置子界面
    connect(ui->Btn_back, &QPushButton::clicked, this, [=](){
        pWidget->backSetPage();
    });

    connect(ui->Btn_IOT, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(0);
        Global::gs_Reflash_Fuction_Internet = TRUE;
        Reflash_Fuction_Internet();
    });

    //物联网功能开关
    connect(ui->Btn_IOTfunc, &QPushButton::clicked, this, [=](){
        if(Global::Internet_Parameter.Switch == 1)
        {
            Global::Internet_Parameter.Switch = 0;
        }
        else
        {
            Global::Internet_Parameter.Switch = 1;
            //物联网功能打开试，关闭绝对值功能
            Global::Temp_JDZ_Parameter.Switch = 0;
            Global::JDZ_Parameter.Switch = Global::Temp_JDZ_Parameter.Switch;
            Global::JDZ_Parameter.Server = Global::Temp_JDZ_Parameter.Server;
            Global::JDZ_Parameter.Resolu = Global::Temp_JDZ_Parameter.Resolu;
            for(int i=0; i<AXIS_NUM; i++)
            {
                Global::JDZ_Parameter.OriginSetting[i] = 0;
                Global::JDZ_Parameter.Circle_Pluse[i] = Global::Temp_JDZ_Parameter.Circle_Pluse[i];
                Global::JDZ_Parameter.Motion_Dir[i] = Global::Temp_JDZ_Parameter.Motion_Dir[i];
            }
        }
        Global::f_SendInternetPara();
        ui->Btn_IOTfunc->setText(Function_switch[Global::Internet_Parameter.Switch]);   //功能开关
    });
}

ExFuncSet::~ExFuncSet()
{
    delete ui;
}

//物联网设定界面刷新
void ExFuncSet::Reflash_Fuction_Internet()
{
    u8 tempChar[20] = {0};
    for(int i=0; i<12; i++)
    {
        if(Global::JudgLetterDigit(Global::Internet_Parameter.Sequence[i]) > 0)
        {
            tempChar[i] = Global::Internet_Parameter.Sequence[i];
        }
        else
        {
            tempChar[i] = '*';
        }
    }
    ui->label_serialNum->setText(Global::u8toqstr(tempChar, 12));   //随机序列
    ui->Btn_IOTfunc->setText(Function_switch[Global::Internet_Parameter.Switch]);   //功能开关
}
