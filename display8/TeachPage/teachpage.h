#ifndef TEACHPAGE_H
#define TEACHPAGE_H

#include <QWidget>
#include <QList>
#include <QPushButton>
#include <QMessageBox>
#include "ParaConfig/parasum.h"

class Widget;   //声明父窗口类

namespace Ui {
class TeachPage;
}

class TeachPage : public QWidget
{
    Q_OBJECT

public:
    bool bPush0;        //基本指令按钮按下标志；
    bool bPush1;        //轴控指令按钮按下标志；
    static QString outputPort;  //输出端口名称(可提供给主窗口Widget类使用)
    static QString inputPort;   //输入端口名称(可提供给主窗口Widget类使用)
    QList <QPushButton*> Btn_Input_Port;
    QList <QPushButton*> Btn_Output_Port;

public:
    explicit TeachPage(QWidget *parent = nullptr);
    ~TeachPage();

    void init();


private slots:
    void on_Btn_basicCmd_clicked();
    void on_Btn_axisCtlCmd_clicked();
    void on_Btn_moveUp_clicked();
    void on_Btn_moveDown_clicked();
    void on_Btn_delete_clicked();

public:
    Ui::TeachPage *ui;
//    Global GL;
    Widget *pWidget;    //创建父类窗口指针

};

#endif // TEACHPAGE_H
