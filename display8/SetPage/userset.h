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

public:
    bool bAdmin;
    u32 backlightTime;

public:
    explicit UserSet(QWidget *parent = nullptr);
    ~UserSet();

    void initTime();
    void init();
    void editClr();
    void clockSetShow();
    void showEvent(QShowEvent *event) override;
    void hideEvent(QHideEvent *event) override;
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    void fixTime(QLineEdit* lineEdit, int max, int min);
    void fixYear();
    void fixMonth();
    void fixDay();
    bool isLeapYear(int year) const;
    bool isBigMonth(int month) const;

private slots:
    void freshTimeUi();

public:
    void Pass_Word_Refresh();


public:
    Ui::UserSet *ui;
//    Global GL;
    Widget *pWidget;    //创建父类窗口指针
    IBeeper *mBeeper;
    IBacklighter *mLighter;
    QTimer* mTimer;
};

#endif // USERSET_H
