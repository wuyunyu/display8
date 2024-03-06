#ifndef STACKSET_H
#define STACKSET_H

#include <QWidget>
#include "ParaConfig/parasum.h"

class Widget;   //声明父窗口类

namespace Ui {
class StackSet;
}

class StackSet : public QWidget
{
    Q_OBJECT

public:
    explicit StackSet(QWidget *parent = nullptr);
    ~StackSet();

public:
    void Refresh_MD_Circulation();

public:
    Ui::StackSet *ui;
//    Global GL;
    Widget *pWidget;    //创建父类窗口指针
};

#endif // STACKSET_H
