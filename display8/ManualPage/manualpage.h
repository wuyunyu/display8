#ifndef MANUALPAGE_H
#define MANUALPAGE_H

#include <QWidget>
#include "ParaConfig/parasum.h"

class Widget;   //声明父窗口类

namespace Ui {
class ManualPage;
}

class ManualPage : public QWidget
{
    Q_OBJECT

public:


public:
    explicit ManualPage(QWidget *parent = nullptr);
    ~ManualPage();

    void init();

public:
    void Refresh_Speed_Para(u8 flag);
    void Refresh_MD_Circulation();

private:
    Ui::ManualPage *ui;
    GlobalPara *GP;

    Widget *pWidget;    //创建父类窗口指针
};

#endif // MANUALPAGE_H
