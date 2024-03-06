#ifndef EXFUNCSET_H
#define EXFUNCSET_H

#include <QWidget>
#include "ParaConfig/parasum.h"

class Widget;   //声明父窗口类
class SetPage;

namespace Ui {
class ExFuncSet;
}

class ExFuncSet : public QWidget
{
    Q_OBJECT

public:
    explicit ExFuncSet(QWidget *parent = nullptr);
    ~ExFuncSet();

public:
    void Reflash_Fuction_Internet();

public:
    Ui::ExFuncSet *ui;
//    Global GL;
    Widget *pWidget;    //创建父类窗口指针
};

#endif // EXFUNCSET_H
