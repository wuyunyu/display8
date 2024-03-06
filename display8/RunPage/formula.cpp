#include "formula.h"
#include "ui_formula.h"
#include "mainWidget.h"

Formula::Formula(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Formula)
{
    ui->setupUi(this);

    pWidget = static_cast<Widget*>(parent);

    init();

    //返回运行界面
    connect(ui->Btn_back, &QPushButton::clicked, this, [=](){
        pWidget->backRunPage();
    });

    //配方端口
    for(int i = 0; i < 4; i++)
    {
        connect(Btn_Port_List.at(i), &QPushButton::clicked, this, [=](){
            if(Global::Robot_Status == ACTION_STOP)
            {
                Global::Temp_PF_Ionum = i;
                pWidget->InputPortSetPage();
            }
        });
    }

    //配方物品
    for(int i = 0; i < 4; i++)
    {
        connect(Btn_Item_List.at(i), &QPushButton::clicked, this, [=](){
            if(Global::Robot_Status == ACTION_STOP)
            {
                Global::Temp_PF_Ionum = i;
                Global::m_MD_Good_Page = 1;
//                MD_NameGet(1);
                pWidget->stackingPage();
                Global::m_Choose_Good_Mode = 4;
            }
        });
    }

    //配方开关
    for(int i = 0; i < 4; i++)
    {
        connect(Btn_Switch_List.at(i), &QPushButton::clicked, this, [=](){
            if(Global::Robot_Status == ACTION_STOP)
            {
                if(Global::PF_Parameter.pfSwitch[i] == 0)
                {
                    Global::PF_Parameter.pfSwitch[i] = 1;
                }
                else
                {
                    Global::PF_Parameter.pfSwitch[i] = 0;
                }
                Global::m_PF_Refresh = TRUE;
                PF_Refresh();
                Global::f_Send_PFPara();
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

//配方页面端口显示
void Formula::dispIOPortText(u8 IOPort)
{
    Global::PF_Parameter.pfIOnum[Global::Temp_PF_Ionum] = IOPort;
    pWidget->formulaPage();
    PF_Refresh();
    Global::f_Send_PFPara();
}

//配方设置刷新
void Formula::PF_Refresh()
{
    QString strName[PF_IONUM];
    for(int i=0; i<PF_IONUM; i++)
    {
        Global::Parameter_StringChang(Global::Temp_Display_Data1, 0,
                                  Global::IO_Name_Parameter_Input[Global::PF_Parameter.pfIOnum[i]].Name,
                                  Global::IO_Name_Parameter_Input[Global::PF_Parameter.pfIOnum[i]].Name1,
                                  Global::IO_Name_Parameter_Input[Global::PF_Parameter.pfIOnum[i]].Name2);
        Btn_Port_List.at(i)->setText(Global::u8toqstr(Global::Temp_Display_Data1, 12));
        strName[i] = ProgramCode_String[Global::PF_Parameter.pfGood[i]];
        Btn_Switch_List.at(i)->setText(PF_Switch[Global::PF_Parameter.pfSwitch[i]]);    //功能开关
    }

    for(int j=1; j<=MD_GOOD_PAGE_NUM; j++)
    {
//        MD_NameGet((j - 1) * MD_GOOD_PAGE_PER + 1);
        for(int i=0; i<PF_IONUM; i++)
        {
            if(Global::PF_Parameter.pfGood[i] <= MD_GOOD_PAGE_PER * j && Global::PF_Parameter.pfGood[i] > MD_GOOD_PAGE_PER * (j - 1))
            {
                Global::Parameter_StringChang(Global::Temp_Display_Data1, 0,
                                              Global::sMD_Name[(Global::PF_Parameter.pfGood[i] - 1) % MD_GOOD_PAGE_PER].Name,
                                              Global::sMD_Name[(Global::PF_Parameter.pfGood[i] - 1) % MD_GOOD_PAGE_PER].Name1,
                                              Global::sMD_Name[(Global::PF_Parameter.pfGood[i] - 1) % MD_GOOD_PAGE_PER].Name2);
                strName[i] += Global::u8toqstr(Global::Temp_Display_Data1, 12);
                Btn_Item_List.at(i)->setText(strName[i]);
            }
        }
    }
}
