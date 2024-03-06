#ifndef SETPAGE_H
#define SETPAGE_H

#include <QWidget>
#include "ParaConfig/parasum.h"
#include "userset.h"
#include "signalset.h"
#include "safeset.h"
#include "sysset.h"
#include "progset.h"
#include "exfuncset.h"

class Widget;   //声明父窗口类

namespace Ui {
class SetPage;
}

class SetPage : public QWidget
{
    Q_OBJECT

public:



public:
    explicit SetPage(QWidget *parent = nullptr);
    ~SetPage();

public:
    Ui::SetPage *ui;
//    Global GL;
    Widget *pWidget;    //创建父类窗口指针
};

#endif // SETPAGE_H
