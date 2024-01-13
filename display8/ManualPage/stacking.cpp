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
        pWidget->backManualPage();
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
    ui->stackedWidget->setCurrentIndex(StackMgt_id);
    ui->stackedWidget_tip->hide();

    Btn_MDSel_List<<ui->Btn_selStacking1<<ui->Btn_selStacking2<<ui->Btn_selStacking3
                  <<ui->Btn_selStacking4<<ui->Btn_selStacking5<<ui->Btn_selStacking6
                  <<ui->Btn_selStacking7<<ui->Btn_selStacking8<<ui->Btn_selStacking9
                  <<ui->Btn_selStacking10<<ui->Btn_selStacking11<<ui->Btn_selStacking12
                  <<ui->Btn_selStacking13<<ui->Btn_selStacking14<<ui->Btn_selStacking15;

}

void Stacking::Reflash_Name_MD(u8 flag)
{
    if(flag == TRUE)
    {
        QString str_MD_Name;
        ProdPara_ui->ui->label_stackMode->setText(MD_Methed_String[GP->sMD_RunPara.mdMethed]);  //码垛方式
        for(int i=0; i<MD_GOOD_PAGE_PER; i++)
        {
            GP->Parameter_StringChang(GP->Temp_Display_Data1, 0, GP->sMD_Name[i].Name,
                                      GP->sMD_Name[i].Name1, GP->sMD_Name[i].Name2);
            str_MD_Name = ProgramCode_String[(GP->m_MD_Good_Page-1)*MD_GOOD_PAGE_PER+i+1];  //序号
            str_MD_Name += GP->u8toqstr(GP->Temp_Display_Data1, 12);    //+名称
            Btn_MDSel_List.at(i)->setText(str_MD_Name);
            str_MD_Name.clear();
        }

        GP->Temp_Display_Data1[0] = 0x30 + GP->m_MD_Good_Page;
        GP->Temp_Display_Data1[1] = 0x20;  // " "
        GP->Temp_Display_Data1[2] = 0x2F;  // "/"
        GP->Temp_Display_Data1[3] = 0x20;  // " "
        GP->Temp_Display_Data1[4] = 0x30 + MD_GOOD_PAGE_NUM;
        GP->Temp_Display_Data1[5] = 0x20;  // " "
        ui->label_stackModePage->setText(GP->u8toqstr(GP->Temp_Display_Data1, 6)); //显示页码
        flag = FALSE;
    }
}
