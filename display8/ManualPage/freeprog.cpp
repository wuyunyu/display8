#include "freeprog.h"
#include "ui_freeprog.h"
#include "mainWidget.h"

FreeProg::FreeProg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FreeProg)
{
    ui->setupUi(this);

    pWidget = static_cast<Widget*>(parent);

    //返回编程界面
    connect(ui->Btn_freeProgBack, &QPushButton::clicked, this, [=](){
        pWidget->backEditTeachPage();
    });
    connect(ui->Btn_freeProgOK, &QPushButton::clicked, this, [=](){
        pWidget->backEditTeachPage();
    });
}

FreeProg::~FreeProg()
{
    delete ui;
}

//刷新码垛夹爪IO
void FreeProg::Refresh_MD_Circulation()
{
    QList<QLabel*> JawList;
    JawList<<ui->label_jaw1<<ui->label_jaw2<<ui->label_jaw3
          <<ui->label_jaw4<<ui->label_jaw5<<ui->label_jaw6;

    if(GP->JXS_Parameter.MDgripSwitch == 1)
    {
        for(int i = 0; i<MDgrip_Num; i++)
        {
            if(GP->JXS_Parameter.MDgripPort[i] == 0)	//夹爪i端口无效
            {
                JawList.at(i)->setText(MD_InvalidGrip2);
            }
            else
            {
                GP->Parameter_StringChang(GP->Temp_Display_Data1, 0,
                        GP->IO_Name_Parameter[GP->JXS_Parameter.MDgripPort[i]-1].Name,
                        GP->IO_Name_Parameter[GP->JXS_Parameter.MDgripPort[i]-1].Name1,
                        GP->IO_Name_Parameter[GP->JXS_Parameter.MDgripPort[i]-1].Name2);
                JawList.at(i)->setText(GP->u8toqstr(GP->Temp_Display_Data1, 12));
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
