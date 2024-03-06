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
    void Refresh_Speed_Para();
    void Refresh_MD_Circulation();

public:
    Ui::ManualPage *ui;
//    Global GL;
    Widget *pWidget;    //创建父类窗口指针
};

#endif // MANUALPAGE_H
