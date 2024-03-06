#ifndef SAFESET_H
#define SAFESET_H

#include <QWidget>
#include <QList>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QIntValidator>
#include "ParaConfig/parasum.h"

class Widget;   //声明父窗口类
class SetPage;

namespace Ui {
class SafeSet;
}

class SafeSet : public QWidget
{
    Q_OBJECT

public:
    explicit SafeSet(QWidget *parent = nullptr);
    ~SafeSet();

public:
    QList<QLabel*> Label_CurPos_List;
    QList<QLineEdit*> Edit_LimPos_Minus;
    QList<QLineEdit*> Edit_LimPos_Add;
    QList<QPushButton*> Btn_AXIS_Enable;

public:
    void init();

public:
    void Refresh_SoftLimit_Temp();
    void Reflash_SoftLimit();

private slots:
    void on_Edit_XPos1_editingFinished();

    void on_Edit_ZPos1_editingFinished();

    void on_Edit_XPos2_editingFinished();

    void on_Edit_ZPos2_editingFinished();

public:
    Ui::SafeSet *ui;
//    Global GL;
    Widget *pWidget;    //创建父类窗口指针
};

#endif // SAFESET_H
