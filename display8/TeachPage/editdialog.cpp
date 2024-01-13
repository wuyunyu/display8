#include "editdialog.h"
#include "ui_editdialog.h"
#include "mainWidget.h"

EditDialog::EditDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditDialog)
{
    ui->setupUi(this);

    pWidget = static_cast<Widget*>(parent);

    //返回对话框界面
    connect(ui->Btn_Cancel, &QPushButton::clicked, this, [=](){
        pWidget->editTeachDialogEnd();   
    });
}

EditDialog::~EditDialog()
{
    delete ui;
}

void EditDialog::switchEditDialog(const int dialogID)
{
    ui->stackedWidget->setCurrentIndex(dialogID);
}
