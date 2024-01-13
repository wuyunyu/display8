#ifndef RUNPAGE_H
#define RUNPAGE_H

#include <QWidget>
#include "ParaConfig/parasum.h"

class Widget;   //声明父窗口类

namespace Ui {
class RunPage;
}

class RunPage : public QWidget
{
    Q_OBJECT

public:
    explicit RunPage(QWidget *parent = nullptr);
    ~RunPage();

    void init();

private slots:
    void on_Btn_Cancel_clicked();
    void on_Btn_back0OK_clicked();
    void on_Btn_back0Cancel_clicked();
    void on_Btn_rstOK_clicked();
    void on_Btn_rstCancel_clicked();

private:
    Ui::RunPage *ui;
    GlobalPara *GP;

    Widget *pWidget;    //创建父类窗口指针
};

#endif // RUNPAGE_H
