#include "stackpara.h"
#include "ui_stackpara.h"
#include "mainWidget.h"

StackPara::StackPara(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StackPara)
{
    ui->setupUi(this);

    pWidget = static_cast<Widget*>(parent);

    this->init();

    //返回码垛管理界面
    connect(ui->Btn_back, &QPushButton::clicked, this, [=](){   
        pWidget->backStackingPage();
    });

    connect(ui->Btn_offset, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_dialog->show();
    });
    connect(ui->Btn_Ok, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_dialog->hide();
    });
    connect(ui->Btn_pageUp, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->Btn_pageDown, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    this->modStackCoord();
}

StackPara::~StackPara()
{
    delete ui;
}

void StackPara::init()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_dialog->hide();
}

void StackPara::modStackCoord()
{
    connect(ui->Btn_pointNum1, &QPushButton::clicked, this, [=](){
        pWidget->stackSetPage();
    });
    connect(ui->Btn_pointNum2, &QPushButton::clicked, this, [=](){
        pWidget->stackSetPage();
    });
    connect(ui->Btn_pointNum3, &QPushButton::clicked, this, [=](){
        pWidget->stackSetPage();
    });
    connect(ui->Btn_pointNum4, &QPushButton::clicked, this, [=](){
        pWidget->stackSetPage();
    });
    connect(ui->Btn_pointNum5, &QPushButton::clicked, this, [=](){
        pWidget->stackSetPage();
    });
    connect(ui->Btn_pointNum6, &QPushButton::clicked, this, [=](){
        pWidget->stackSetPage();
    });
    connect(ui->Btn_pointNum7, &QPushButton::clicked, this, [=](){
        pWidget->stackSetPage();
    });
    connect(ui->Btn_pointNum8, &QPushButton::clicked, this, [=](){
        pWidget->stackSetPage();
    });
    connect(ui->Btn_pointNum1_2, &QPushButton::clicked, this, [=](){
        pWidget->stackSetPage();
    });
    connect(ui->Btn_pointNum2_2, &QPushButton::clicked, this, [=](){
        pWidget->stackSetPage();
    });
    connect(ui->Btn_pointNum3_2, &QPushButton::clicked, this, [=](){
        pWidget->stackSetPage();
    });
    connect(ui->Btn_pointNum4_2, &QPushButton::clicked, this, [=](){
        pWidget->stackSetPage();
    });
    connect(ui->Btn_pointNum5_2, &QPushButton::clicked, this, [=](){
        pWidget->stackSetPage();
    });
    connect(ui->Btn_pointNum6_2, &QPushButton::clicked, this, [=](){
        pWidget->stackSetPage();
    });
    connect(ui->Btn_pointNum7_2, &QPushButton::clicked, this, [=](){
        pWidget->stackSetPage();
    });
    connect(ui->Btn_pointNum8_2, &QPushButton::clicked, this, [=](){
        pWidget->stackSetPage();
    });
}
