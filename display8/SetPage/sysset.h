#ifndef SYSSET_H
#define SYSSET_H

#include <QWidget>
#include <QLineEdit>
#include <QList>
#include <QPushButton>
#include <QLineEdit>
#include "ParaConfig/parasum.h"
#include "ManualPage/stackset.h"
#include "signalset.h"

class Widget;   //声明父窗口类
class SetPage;

namespace Ui {
class SysSet;
}

class SysSet : public QWidget
{
    Q_OBJECT

public:
    explicit SysSet(QWidget *parent = nullptr);
    ~SysSet();

public:
    QList<QPushButton*> Btn_Axis_Servo;
    QList<QPushButton*> Btn_Axis_Type;
    QList<QPushButton*> Btn_Axis_Link;
    QList<QPushButton*> Btn_Axis_Back;
    QList<QPushButton*> Btn_Axis_Sel;
    QList<QPushButton*> Btn_Axis_Dirt;
    QList<QPushButton*> Btn_Axis_Return0;
    QList<QPushButton*> Btn_Axis_OriginSet;
    QList<QPushButton*> Btn_Axis_OriginRst;

    QList<QLineEdit*> Eidt_USER_Name;
    QList<QLineEdit*> Eidt_USER_InitVal;
    QList<QLineEdit*> Eidt_USER_CurVal;
    QList<QPushButton*> Btn_USER_BootRst;
    QList<QPushButton*> Btn_USER_StartRst;



public:
    void init();

    void JDZ_Tips1();
    void JDZ_Tips2();
    void JDZ_ModBack();

    void JXS_Set_dispPort(u8 IOPort);

public:
    void Refresh_Fuction_JXS();
    void Refresh_Associate();
    void Refresh_Avoidace();
    void Refresh_Origin_Method();
    void Refresh_Outport();
    void Refresh_AlarmSignal();
    void Refresh_MD_Circulation();

    void Refresh_OrignParameter();

    void Refresh_JDZOriginSetting_Text();
    void Reflash_Fuction_JDZ(int flag);
    void Reflash_Save_JDZ();
    void Refresh_JDZ_Axis(int dialog_page);

    void Reflash_Fuction_USER();
    void Reflash_Save_USER();

    void Refresh_Cartesian();


private slots:   
    void on_comboBox_machType_currentIndexChanged(int index);

    void on_comboBox_mechAxisNum_currentIndexChanged(int index);

    void on_Btn_returnOriginWay_clicked();

    void on_comboBox_servoSel_currentIndexChanged(int index);

public:
    Ui::SysSet *ui;
//    Global GL;
    Widget *pWidget;    //创建父类窗口指针
};

#endif // SYSSET_H
