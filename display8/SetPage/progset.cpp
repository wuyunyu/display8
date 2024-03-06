#include "progset.h"
#include "ui_progset.h"
#include "mainWidget.h"

ProgSet::ProgSet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProgSet)
{
    ui->setupUi(this);

    pWidget = static_cast<Widget*>(parent);

    init();

    //返回设置子界面
    connect(ui->Btn_MprogBack, &QPushButton::clicked, this, [=](){
        pWidget->backSetPage();
    });
    //返回编程子界面
    connect(ui->Btn_selProgBack, &QPushButton::clicked, this, [=](){
        pWidget->backTeachPage();
        ui->stackedWidget->setCurrentIndex(ProgMgt_id); //程序设定子界面回到初始程序管理页面
    });

    connect(ui->Btn_USBcopy, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(CopySel_id);
    });
    connect(ui->Btn_copySelBack, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(ProgMgt_id);
    });
    connect(ui->Btn_inCopyBack, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(CopySel_id);
    });
    connect(ui->Btn_outCopyBack, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(CopySel_id);
    });
    connect(ui->Btn_inCopyOk, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(ProgMgt_id);
    });
    connect(ui->Btn_CtoU, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(CtoU_id);
    });
    connect(ui->Btn_UtoC, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(UtoC_id);
    });
}

ProgSet::~ProgSet()
{
    delete ui;
}

void ProgSet::init()
{
    Label_ProgN_List<<ui->label_MmainProgN1<<ui->label_MmainProgN2<<ui->label_MmainProgN3<<ui->label_MmainProgN4<<ui->label_MmainProgN5
                    <<ui->label_MmainProgN6<<ui->label_MmainProgN7<<ui->label_MmainProgN8<<ui->label_MmainProgN9<<ui->label_MmainProgN10
                    <<ui->label_MsubProgN1<<ui->label_MsubProgN2<<ui->label_MsubProgN3<<ui->label_MsubProgN4<<ui->label_MsubProgN5
                    <<ui->label_MsubProgN6<<ui->label_MsubProgN7<<ui->label_MsubProgN8<<ui->label_MsubProgN9<<ui->label_MsubProgN10;

    Label_ProgS_List<<ui->label_MmainProgS1<<ui->label_MmainProgS2<<ui->label_MmainProgS3<<ui->label_MmainProgS4<<ui->label_MmainProgS5
                    <<ui->label_MmainProgS6<<ui->label_MmainProgS7<<ui->label_MmainProgS8<<ui->label_MmainProgS9<<ui->label_MmainProgS10
                    <<ui->label_MsubProgS1<<ui->label_MsubProgS2<<ui->label_MsubProgS3<<ui->label_MsubProgS4<<ui->label_MsubProgS5
                    <<ui->label_MsubProgS6<<ui->label_MsubProgS7<<ui->label_MsubProgS8<<ui->label_MsubProgS9<<ui->label_MsubProgS10;

    ui->stackedWidget->setCurrentIndex(ProgMgt_id);
}

//提供给编程界面的程序选择按钮来跳转
void ProgSet::showProgSelPage()
{
    ui->stackedWidget->setCurrentIndex(ProgSel);
}

//程序管理--刷新程序名称和行数
void ProgSet::Program_Display_Refresh()
{
    for(int i=0; i<SAVEPROGRAMNUM; i++)
    {
        Global::Parameter_StringChang(Global::Temp_Display_Data, 0, Global::Free_Program_Save[i].Name,
                                  Global::Free_Program_Save[i].Name2, Global::Free_Program_Save[i].Name3);
        Label_ProgN_List.at(i)->setText(Global::u8toqstr(Global::Temp_Display_Data, 12));
        Label_ProgS_List.at(i)->setText(QString::number(static_cast<int>(Global::Free_Program_Save[i].Num)));
    }
}
