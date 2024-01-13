#include "formula.h"
#include "ui_formula.h"
#include "mainWidget.h"

Formula::Formula(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Formula)
{
    ui->setupUi(this);

    pWidget = static_cast<Widget*>(parent);

    //返回运行界面
    connect(ui->Btn_back, &QPushButton::clicked, this, [=](){
        pWidget->backRunPage();
    });

    //配方端口
    for(int i = 0; i < 4; i++)
    {
        connect(Btn_Port_List.at(i), &QPushButton::clicked, this, [=](){
            if(GP->Robot_Status == ACTION_STOP)
            {
                GP->Temp_PF_Ionum = i;
                pWidget->IOPortSetPage();
            }
        });
    }

    //配方物品
    for(int i = 0; i < 4; i++)
    {
        connect(Btn_Item_List.at(i), &QPushButton::clicked, this, [=](){
            if(GP->Robot_Status == ACTION_STOP)
            {
                GP->Temp_PF_Ionum = i;
                GP->m_MD_Good_Page = 1;
//                MD_NameGet(1);
                pWidget->stackingPage();
                GP->m_Choose_Good_Mode = 4;
            }
        });
    }

    //配方开关
    for(int i = 0; i < 4; i++)
    {
        connect(Btn_Switch_List.at(i), &QPushButton::clicked, this, [=](){
            if(GP->Robot_Status == ACTION_STOP)
            {
                if(GP->PF_Parameter.pfSwitch[i] == 0)
                {
                    GP->PF_Parameter.pfSwitch[i] = 1;
                }
                else
                {
                    GP->PF_Parameter.pfSwitch[i] = 0;
                }
                GP->m_PF_Refresh = TRUE;
                PF_Refresh(GP->m_PF_Refresh);
                GP->f_Send_PFPara();
            }
        });
    }
}

Formula::~Formula()
{
    delete ui;
}

void Formula::init()
{
    Btn_Port_List<<ui->Btn_port1<<ui->Btn_port2<<ui->Btn_port3<<ui->Btn_port4;
    Btn_Item_List<<ui->Btn_item1<<ui->Btn_item2<<ui->Btn_item3<<ui->Btn_item4;
    Btn_Switch_List<<ui->Btn_OnOff1<<ui->Btn_OnOff2<<ui->Btn_OnOff3<<ui->Btn_OnOff4;
}

//配方设置刷新
void Formula::PF_Refresh(u8 flag)
{
    if(flag == TRUE)
    {
        QString strName[PF_IONUM];
        for(int i=0; i<PF_IONUM; i++)
        {
            GP->Parameter_StringChang(GP->Temp_Display_Data1, 0,
                                      GP->IO_Name_Parameter_Input[GP->PF_Parameter.pfIOnum[i]].Name,
                                      GP->IO_Name_Parameter_Input[GP->PF_Parameter.pfIOnum[i]].Name1,
                                      GP->IO_Name_Parameter_Input[GP->PF_Parameter.pfIOnum[i]].Name2);
            Btn_Port_List.at(i)->setText(GP->u8toqstr(GP->Temp_Display_Data1, 12));
            strName[i] = ProgramCode_String[GP->PF_Parameter.pfGood[i]];
            Btn_Switch_List.at(i)->setText(PF_Switch[GP->PF_Parameter.pfSwitch[i]]);    //功能开关
        }

        for(int j=1; j<=MD_GOOD_PAGE_NUM; j++)
        {
//            MD_NameGet((j - 1) * MD_GOOD_PAGE_PER + 1);
            for(int i=0; i<PF_IONUM; i++)
            {
                if(GP->PF_Parameter.pfGood[i] <= MD_GOOD_PAGE_PER * j && GP->PF_Parameter.pfGood[i] > MD_GOOD_PAGE_PER * (j - 1))
                {
                    GP->Parameter_StringChang(GP->Temp_Display_Data1, 0, GP->sMD_Name[(GP->PF_Parameter.pfGood[i] - 1) % MD_GOOD_PAGE_PER].Name,
                                                                         GP->sMD_Name[(GP->PF_Parameter.pfGood[i] - 1) % MD_GOOD_PAGE_PER].Name1,
                                                                         GP->sMD_Name[(GP->PF_Parameter.pfGood[i] - 1) % MD_GOOD_PAGE_PER].Name2);
                    strName[i] += GP->u8toqstr(GP->Temp_Display_Data1, 12);
                    Btn_Item_List.at(i)->setText(strName[i]);
                }
            }
        }
        flag = FALSE;
    }
}
