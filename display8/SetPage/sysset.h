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

    friend class SetPage;

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

public:
    void Refresh_Fuction_JXS(u8 flag);
    void Refresh_Associate(u8 flag);
    void Refresh_Avoidace(u8 flag);
    void Refresh_Origin_Method(u8 flag);
    void Refresh_Outport(u8 flag);
    void Refresh_AlarmSignal(u8 flag);
    void Refresh_MD_Circulation(u8 flag);

    void Refresh_OrignParameter(u8 flag);

    void Refresh_JDZOriginSetting_Text(u8 flag);
    void Reflash_Fuction_JDZ(u8 flag);
    void Reflash_Save_JDZ(u8 flag);
    void Refresh_JDZ_Axis(u8 flag,int dialog_page);

    void Reflash_Fuction_USER(u8 flag);
    void Reflash_Save_USER(u8 flag);

    void Refresh_Cartesian(u8 flag);


private slots:   
    void on_comboBox_machType_currentIndexChanged(int index);

    void on_comboBox_mechAxisNum_currentIndexChanged(int index);

    void on_Btn_returnOriginWay_clicked();

    void on_comboBox_servoSel_currentIndexChanged(int index);

    void on_comboBox_encoder_currentIndexChanged(int index);

private:
    Ui::SysSet *ui;
    GlobalPara *GP;
    SignalSet *SignalSet_ui;
    StackSet *StackSet_ui;

    Widget *pWidget;    //创建父类窗口指针
};

#endif // SYSSET_H
