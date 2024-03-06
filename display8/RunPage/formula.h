#ifndef FORMULA_H
#define FORMULA_H

#include <QWidget>
#include <QPushButton>
#include <QList>
#include "ParaConfig/parasum.h"

class Widget;   //声明父窗口类

namespace Ui {
class Formula;
}

class Formula : public QWidget
{
    Q_OBJECT

public:
    explicit Formula(QWidget *parent = nullptr);
    ~Formula();

    void init();

    void dispIOPortText(u8 IOPort);

public:
    void PF_Refresh();


public:
    QList<QPushButton*> Btn_Port_List;
    QList<QPushButton*> Btn_Item_List;
    QList<QPushButton*> Btn_Switch_List;

public:
    Ui::Formula *ui;
//    Global GL;
    Widget *pWidget;    //创建父类窗口指针
};

#endif // FORMULA_H
