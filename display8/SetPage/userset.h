#ifndef USERSET_H
#define USERSET_H

#include <QWidget>
#include <QDateTime>
#include "VirtualDevice/syscfgfactory.h"
#include <QIntValidator>
#include <QTimer>
#include <QLineEdit>
#include <QDebug>
#include "ParaConfig/parasum.h"

#define UNUSED(x) (void)x

class Widget;   //声明父窗口类
class SetPage;
class IBeeper;
class IBacklighter;

namespace Ui {
class UserSet;
}

class UserSet : public QWidget
{
    Q_OBJECT

    friend class SetPage;

public:
    QString Key;
    bool bAdmin;
    bool bBee;
    uint32_t backlightTime;

public:
    explicit UserSet(QWidget *parent = nullptr);
    ~UserSet();

    void initTime();
    void init();
    void editClr();
    void clockSetShow();
    bool passwordModErrorTip();
    void showEvent(QShowEvent *event) override;
    void hideEvent(QHideEvent *event) override;
    bool eventFilter(QObject *obj, QEvent *event) override;
    void RestoreSetting();

private:
    void fixTime(QLineEdit* lineEdit, int max, int min);
    void fixYear();
    void fixMonth();
    void fixDay();
    bool isLeapYear(int year) const;
    bool isBigMonth(int month) const;

private slots:
    void freshTimeUi();
    void on_Btn_clockSetOk_clicked();
    void on_Btn_buzzer_clicked();   

public:
    void Pass_Word_Refresh(u8 flag);


private:
    Ui::UserSet *ui;

    Widget *pWidget;    //创建父类窗口指针
    IBeeper *mBeeper;
    IBacklighter* mLighter;
    QTimer* mTimer;

    GlobalPara *GP;
};

#endif // USERSET_H
