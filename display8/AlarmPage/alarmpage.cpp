#include "alarmpage.h"
#include "ui_alarmpage.h"

AlarmPage::AlarmPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlarmPage)
{
    ui->setupUi(this);

    this->init();
}

AlarmPage::~AlarmPage()
{
    delete ui;
}

void AlarmPage::init()
{
    ui->table_alarm->setColumnWidth(0, 60);
    ui->table_alarm->setColumnWidth(1,120);
    ui->table_alarm->setColumnWidth(2, 120);
}

void AlarmPage::on_Btn_clr_clicked()
{
    ui->table_alarm->clear();
}

