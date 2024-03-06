#include "stacking.h"
#include "ui_stacking.h"
#include "mainWidget.h"
#include "ui_prodpara.h"

Stacking::Stacking(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Stacking)
{
    ui->setupUi(this);

    pWidget = static_cast<Widget*>(parent);

    init();

    //返回手动界面
    connect(ui->Btn_stackModeBack, &QPushButton::clicked, this, [=](){
        if(Global::m_Choose_Good_Mode == 0)
        {
            pWidget->backManualPage();
        }
        else if(Global::m_Choose_Good_Mode == 1 || Global::m_Choose_Good_Mode == 2)
        {
            pWidget->prodParaPage();
            Global::m_Choose_Good_Mode = 0;
        }
        else if(Global::m_Choose_Good_Mode == 3)
        {
            pWidget->progCopySelPage();
            Global::m_Choose_Good_Mode = 0;
        }
        else if(Global::m_Choose_Good_Mode == 4)
        {
            pWidget->formulaPage();
            Global::m_Choose_Good_Mode = 0;
        }
        else if(Global::m_Choose_Good_Mode == 5)
        {
            pWidget->backRunPage();
            Global::m_Choose_Good_Mode = 0;
        }
    });

    this->stackParaSet();

    connect(ui->Btn_copyPageUp, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_page->setCurrentIndex(0);
    });
    connect(ui->Btn_copyPageDown, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_page->setCurrentIndex(1);
    });
    connect(ui->Btn_stackCopy, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(CopySel_id);
    });
    connect(ui->Btn_CtoU, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(CtoU_id);
    });
    connect(ui->Btn_UtoC, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(UtoC_id);
    });
    connect(ui->Btn_selCopyback, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(StackMgt_id);
    });
    connect(ui->Btn_inCopyBack, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(CopySel_id);
    });
    connect(ui->Btn_outCopyBack, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(CopySel_id);
    });
    connect(ui->Btn_inCopyOk, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(CopySel_id);
    });

    //读取码垛参数
    for(u8 i = 0; i < MD_GOOD_PAGE_PER; i++)
    {
        connect(Btn_MDSel_List.at(i), &QPushButton::clicked, this, [=](){
            Global::sMD_Parameter.code = i + 1 + (Global::m_MD_Good_Page-1)*MD_GOOD_PAGE_PER;
            chooseGoodMode();
        });
    }

    //码垛方式
    connect(ui->Btn_stackMode, &QPushButton::clicked, this, [=](){
        if(Global::Robot_Status == ACTION_PAUSE)
        {
            return;
        }
        ui->label_stackMode->setText(MD_Methed_String[Global::ValSwitch(Global::sMD_RunPara.mdMethed)]);
        Global::f_Send_SCPara();
    });

    //码垛参数拷贝-每次仅支持拷贝一个物品参数
    connect(ui->Btn_stackCopy, &QPushButton::clicked, this, [=](){
        if(Global::LCD_Main_Page == MANUL_DEBUG)
        {
//            COPY_PARAMETER_OR_PROGRAM = MDPARA_COPY;
            pWidget->progCopySelPage();
        }
    });

    //物品-上一页
    connect(ui->Btn_stackModePageUp, &QPushButton::clicked, this, [=](){
        if(Global::m_MD_Good_Page > 1)
        {
            Global::m_MD_Good_Page--;
//            MD_NameGet((m_MD_Good_Page-1)*MD_GOOD_PAGE_PER + 1);
            Global::m_Reflash_Name_MD = TRUE;
            Reflash_Name_MD();
        }
    });
}

Stacking::~Stacking()
{
    delete ui;
}

void Stacking::stackParaSet()
{
    connect(ui->Btn_selStacking1, &QPushButton::clicked, this, [=](){
        pWidget->stackParaPage();
    });
    connect(ui->Btn_selStacking2, &QPushButton::clicked, this, [=](){
        pWidget->stackParaPage();
    });
    connect(ui->Btn_selStacking3, &QPushButton::clicked, this, [=](){
        pWidget->stackParaPage();
    });
    connect(ui->Btn_selStacking4, &QPushButton::clicked, this, [=](){
        pWidget->stackParaPage();
    });
    connect(ui->Btn_selStacking5, &QPushButton::clicked, this, [=](){
        pWidget->stackParaPage();
    });
    connect(ui->Btn_selStacking6, &QPushButton::clicked, this, [=](){
        pWidget->stackParaPage();
    });
    connect(ui->Btn_selStacking7, &QPushButton::clicked, this, [=](){
        pWidget->stackParaPage();
    });
    connect(ui->Btn_selStacking8, &QPushButton::clicked, this, [=](){
        pWidget->stackParaPage();
    });
    connect(ui->Btn_selStacking9, &QPushButton::clicked, this, [=](){
        pWidget->stackParaPage();
    });
    connect(ui->Btn_selStacking10, &QPushButton::clicked, this, [=](){
        pWidget->stackParaPage();
    });
    connect(ui->Btn_selStacking11, &QPushButton::clicked, this, [=](){
        pWidget->stackParaPage();
    });
    connect(ui->Btn_selStacking12, &QPushButton::clicked, this, [=](){
        pWidget->stackParaPage();
    });
    connect(ui->Btn_selStacking13, &QPushButton::clicked, this, [=](){
        pWidget->stackParaPage();
    });
    connect(ui->Btn_selStacking14, &QPushButton::clicked, this, [=](){
        pWidget->stackParaPage();
    });
    connect(ui->Btn_selStacking15, &QPushButton::clicked, this, [=](){
        pWidget->stackParaPage();
    });
    connect(ui->Btn_selStacking16, &QPushButton::clicked, this, [=](){
        pWidget->stackParaPage();
    });
    connect(ui->Btn_selStacking17, &QPushButton::clicked, this, [=](){
        pWidget->stackParaPage();
    });
    connect(ui->Btn_selStacking18, &QPushButton::clicked, this, [=](){
        pWidget->stackParaPage();
    });
    connect(ui->Btn_selStacking19, &QPushButton::clicked, this, [=](){
        pWidget->stackParaPage();
    });
    connect(ui->Btn_selStacking20, &QPushButton::clicked, this, [=](){
        pWidget->stackParaPage();
    });
    connect(ui->Btn_selStacking21, &QPushButton::clicked, this, [=](){
        pWidget->stackParaPage();
    });
    connect(ui->Btn_selStacking22, &QPushButton::clicked, this, [=](){
        pWidget->stackParaPage();
    });
    connect(ui->Btn_selStacking23, &QPushButton::clicked, this, [=](){
        pWidget->stackParaPage();
    });
    connect(ui->Btn_selStacking24, &QPushButton::clicked, this, [=](){
        pWidget->stackParaPage();
    });
    connect(ui->Btn_selStacking25, &QPushButton::clicked, this, [=](){
        pWidget->stackParaPage();
    });
    connect(ui->Btn_selStacking26, &QPushButton::clicked, this, [=](){
        pWidget->stackParaPage();
    });
    connect(ui->Btn_selStacking27, &QPushButton::clicked, this, [=](){
        pWidget->stackParaPage();
    });
    connect(ui->Btn_selStacking28, &QPushButton::clicked, this, [=](){
        pWidget->stackParaPage();
    });
    connect(ui->Btn_selStacking29, &QPushButton::clicked, this, [=](){
        pWidget->stackParaPage();
    });
    connect(ui->Btn_selStacking30, &QPushButton::clicked, this, [=](){
        pWidget->stackParaPage();
    });
}

void Stacking::init()
{
    Btn_MDSel_List<<ui->Btn_selStacking1<<ui->Btn_selStacking2<<ui->Btn_selStacking3
                  <<ui->Btn_selStacking4<<ui->Btn_selStacking5<<ui->Btn_selStacking6
                  <<ui->Btn_selStacking7<<ui->Btn_selStacking8<<ui->Btn_selStacking9
                  <<ui->Btn_selStacking10<<ui->Btn_selStacking11<<ui->Btn_selStacking12
                  <<ui->Btn_selStacking13<<ui->Btn_selStacking14<<ui->Btn_selStacking15;

    ui->stackedWidget->setCurrentIndex(StackMgt_id);
    ui->stackedWidget_tip->hide();

}

void Stacking::chooseGoodMode()
{
    u8 temp_filename[9] = {0};
    if(Global::m_Choose_Good_Mode == 0) //读参数
    {
//                MD_ParaGet(sMD_Parameter.code);
    }
    else if(Global::m_Choose_Good_Mode == 1)    //选取起始物品
    {
        Global::sMD_RunPara.startGood = Global::sMD_Parameter.code;
        Global::f_Send_SCPara();
        pWidget->prodParaPage();
        Global::m_Reflash_Run_MD = TRUE;
        pWidget->ProdPara_ui->Reflash_Run_MD();

        Global::m_Choose_Good_Mode = 0;
        Global::sMD_RunPara.startName = Global::sMD_Name[Global::sMD_RunPara.startGood - (Global::m_MD_Good_Page-1)*MD_GOOD_PAGE_PER - 1];
    }
    else if(Global::m_Choose_Good_Mode == 2)    //选取当前物品
    {
        Global::sMD_RunPara.curGood = Global::sMD_Parameter.code;
//                Order_Temp[0] = MD_CURLAYER_CURNUM;  										//查询机当前物品的当前层和当前个数
//                Order_Temp[1] = sMD_RunPara.curGood;  										//当前物品号
//                USART1_SendData(2, WATCH_COMMAND, &Order_Temp[0]);
        Global::f_Send_SCPara();
        pWidget->prodParaPage();
        Global::m_Reflash_Run_MD = TRUE;
        pWidget->ProdPara_ui->Reflash_Run_MD();

        Global::m_Choose_Good_Mode = 0;
        Global::sMD_RunPara.curName = Global::sMD_Name[Global::sMD_RunPara.curGood - (Global::m_MD_Good_Page-1)*MD_GOOD_PAGE_PER - 1];
    }
    else if(Global::m_Choose_Good_Mode == 3)    //选择拷出物品参数
    {
        Global::m_MD_Copy_Code = Global::sMD_Parameter.code;
        Global::m_Choose_Good_Mode = 0;

        Global::Copy_FileName.Name1 = 0x4D443030 + ((u32)(Global::sMD_Parameter.code)/10 << 8) + (Global::sMD_Parameter.code)%10;
        temp_filename[0] = Global::Copy_FileName.Name1>>24;
        temp_filename[1] = Global::Copy_FileName.Name1>>16;
        temp_filename[2] = Global::Copy_FileName.Name1>>8;
        temp_filename[3] = Global::Copy_FileName.Name1;
        strcat((char*)Global::Temp_CopyFileName, "0:/");
        int j=3;
        for(int i=0; i<9; i++)
        {
            if(temp_filename[i]==0x0d || temp_filename[i]==0x0a)break;
            if(temp_filename[i]!=0)
            {
                Global::Temp_CopyFileName[j] = temp_filename[i];
                j++;
            }
        }
        strcat((char*)Global::Temp_CopyFileName, ".TXT");

        pWidget->progCopyTipPage();
        Global::USBH_Process_Flag = TRUE;
        Global::USBH_Copy_Status = USBHSTATUS_NOUDISK;
        Global::USBH_Dispaly_Fresh_Flag = TRUE;
        Global::USBH_Direction = CONTROLERTOUSB;
//                if(USBH_USR_ApplicationState == USH_USR_FS_NULL)
//                {
//                    USBH_USR_ApplicationState = USH_USR_FS_INIT;
//                }
//                USB_Button_Ok = TRUE;
//                USB_Button_Cancle = TRUE;
    }
    else if(Global::m_Choose_Good_Mode == 4)    //配方物品选择
    {
        Global::PF_Parameter.pfGood[Global::Temp_PF_Ionum] = Global::sMD_Parameter.code;
        Global::f_Send_PFPara();
        pWidget->formulaPage();
        Global::m_PF_Refresh = TRUE;
        Global::m_Choose_Good_Mode = 0;
    }
    else if(Global::m_Choose_Good_Mode == 5)
    {
        Global::sMD_RunPara.curGood = Global::sMD_Parameter.code;
//                Order_Temp[0] = MD_CURLAYER_CURNUM;  										//查询机当前物品的当前层和当前个数
//                Order_Temp[1] = sMD_RunPara.curGood;  										//当前物品号
//                USART1_SendData(2, WATCH_COMMAND, &Order_Temp[0]);
        Global::f_Send_SCPara();
        pWidget->backRunPage();
        Global::m_Reflash_Run_MD = TRUE;
        Global::m_Choose_Good_Mode = 0;
        Global::sMD_RunPara.curName = Global::sMD_Name[Global::sMD_RunPara.curGood - (Global::m_MD_Good_Page-1)*MD_GOOD_PAGE_PER - 1];
    }
}

void Stacking::Reflash_Name_MD()
{
    QString str_MD_Name;
    pWidget->ProdPara_ui->ui->label_stackMode->setText(MD_Methed_String[Global::sMD_RunPara.mdMethed]);  //码垛方式
    for(int i=0; i<MD_GOOD_PAGE_PER; i++)
    {
        Global::Parameter_StringChang(Global::Temp_Display_Data1, 0, Global::sMD_Name[i].Name,
                                  Global::sMD_Name[i].Name1, Global::sMD_Name[i].Name2);
        str_MD_Name = ProgramCode_String[(Global::m_MD_Good_Page-1)*MD_GOOD_PAGE_PER+i+1];  //序号
        str_MD_Name += Global::u8toqstr(Global::Temp_Display_Data1, 12);    //+名称
        Btn_MDSel_List.at(i)->setText(str_MD_Name);
        str_MD_Name.clear();
    }

    Global::Temp_Display_Data1[0] = 0x30 + Global::m_MD_Good_Page;
    Global::Temp_Display_Data1[1] = 0x20;  // " "
    Global::Temp_Display_Data1[2] = 0x2F;  // "/"
    Global::Temp_Display_Data1[3] = 0x20;  // " "
    Global::Temp_Display_Data1[4] = 0x30 + MD_GOOD_PAGE_NUM;
    Global::Temp_Display_Data1[5] = 0x20;  // " "
    ui->label_stackModePage->setText(Global::u8toqstr(Global::Temp_Display_Data1, 6)); //显示页码
}
