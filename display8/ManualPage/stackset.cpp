#include "stackset.h"
#include "ui_stackset.h"
#include "mainWidget.h"

StackSet::StackSet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StackSet)
{
    ui->setupUi(this);

    pWidget = static_cast<Widget*>(parent);

    //返回码垛参数界面
    connect(ui->Btn_stackSetBack, &QPushButton::clicked, this, [=](){
        pWidget->backStackParaPage();
    });
}

StackSet::~StackSet()
{
    delete ui;
}

//刷新码垛夹爪IO
void StackSet::Refresh_MD_Circulation()
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



