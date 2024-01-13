#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QWidget>
#include "ParaConfig/parasum.h"

class Widget;   //声明父窗口类

namespace Ui {
class EditDialog;
}

class EditDialog : public QWidget
{
    Q_OBJECT

public:
    explicit EditDialog(QWidget *parent = nullptr);
    ~EditDialog();

    void switchEditDialog(const int dialogID);

private:
    Ui::EditDialog *ui;

    Widget *pWidget;    //创建父类窗口指针
};

#endif // EDITDIALOG_H
