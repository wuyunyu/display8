#include "debugpage.h"
#include "ui_debugpage.h"

DebugPage::DebugPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DebugPage)
{
    ui->setupUi(this);

    this->init();

    connect(ui->Btn_localInput, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(InputPort_id);
        ui->Btn_localInput->setStyleSheet("background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #00BEFA, stop: 1 #0160EA);");
        ui->Btn_localOutput->setStyleSheet("background-color:#F1F5FE; ");
    });
    connect(ui->Btn_pageUpInput, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_input->setCurrentIndex(0);
    });
    connect(ui->Btn_pageDownInput, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_input->setCurrentIndex(1);
    });
    connect(ui->Btn_localOutput, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(OutputPort_id);
        ui->Btn_localInput->setStyleSheet("background-color:#F1F5FE; ");
        ui->Btn_localOutput->setStyleSheet("background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #00BEFA, stop: 1 #0160EA);");
    });
    connect(ui->Btn_pageUpOutput, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_output->setCurrentIndex(0);
    });
    connect(ui->Btn_pageDownOutput, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_output->setCurrentIndex(1);
    });
}

DebugPage::~DebugPage()
{
    delete ui;
}

void DebugPage::init()
{
    ui->stackedWidget->setCurrentIndex(InputPort_id);
    ui->stackedWidget_input->setCurrentIndex(0);
    ui->stackedWidget_output->setCurrentIndex(0);
    ui->Btn_localInput->setStyleSheet("background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #00BEFA, stop: 1 #0160EA);");
}
