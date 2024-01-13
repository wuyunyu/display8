#include "memorypoint.h"
#include "ui_memorypoint.h"
#include "mainWidget.h"

MemoryPoint::MemoryPoint(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MemoryPoint)
{
    ui->setupUi(this);

    pWidget = static_cast<Widget*>(parent);

    this->init();

    //返回手动界面
    connect(ui->Btn_back, &QPushButton::clicked, this, [=](){
        pWidget->backManualPage();
    });

    connect(ui->Btn_modify, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_dialog->show();
        if(bName)
            ui->stackedWidget_dialog->setCurrentIndex(NameMod_id);
        else
            ui->stackedWidget_dialog->setCurrentIndex(PosMod_id);
    });

    connect(ui->Btn_delete, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_dialog->show();
        ui->stackedWidget_dialog->setCurrentIndex(Del_id);
    });

    //关闭“修改”和“删除“对话框
    connect(ui->Btn_modposOk, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_dialog->hide();
    });
    connect(ui->Btn_modposCancel, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_dialog->hide();
    });
    connect(ui->Btn_modNameOk, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_dialog->hide();
    });
    connect(ui->Btn_modNameCancel, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_dialog->hide();
    });
    connect(ui->Btn_delOk, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_dialog->hide();
    });
    connect(ui->Btn_delCancel, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_dialog->hide();
    });

//    //切换组号
//    connect(ui->Btn_group1, &QPushButton::clicked, this, [=](){
//        ui->stackedWidget_table->setCurrentIndex(First_id);
//    });
//    connect(ui->Btn_group2, &QPushButton::clicked, this, [=](){
//        ui->stackedWidget_table->setCurrentIndex(Second_id);
//    });
//    connect(ui->Btn_group3, &QPushButton::clicked, this, [=](){
//        ui->stackedWidget_table->setCurrentIndex(Third_id);
//    });
//    connect(ui->Btn_group4, &QPushButton::clicked, this, [=](){
//        ui->stackedWidget_table->setCurrentIndex(Fourth_id);
//    });
//    connect(ui->Btn_group5, &QPushButton::clicked, this, [=](){
//        ui->stackedWidget_table->setCurrentIndex(Fifth_id);
//    });
}

MemoryPoint::~MemoryPoint()
{
    delete ui;
}

void MemoryPoint::init()
{
    bName = false;
    ui->stackedWidget_dialog->hide();

    QStringList header;
    header<<"编号"<<"点名称"<<"X"<<"Y"<<"Z"<<"O"<<"U"<<"V";
    ui->table->setHorizontalHeaderLabels(header);
    ui->table->horizontalHeader()->setMinimumHeight(50);
    ui->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//延伸显示(水平铺满)
    ui->table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);  //延伸显示(垂直铺满)
}
