#ifndef PROGSET_H
#define PROGSET_H

#include <QWidget>
#include <QList>
#include <QLabel>
#include "ParaConfig/parasum.h"

class Widget;   //声明父窗口类
class SetPage;

namespace Ui {
class ProgSet;
}

class ProgSet : public QWidget
{
    Q_OBJECT

    friend class SetPage;

public:
    explicit ProgSet(QWidget *parent = nullptr);
    ~ProgSet();

    void init();
    void showProgSelPage();

public:
    QList<QLabel*> Label_ProgN_List;
    QList<QLabel*> Label_ProgS_List;


public:
    void Program_Display_Refresh(u8 flag);


private:
    Ui::ProgSet *ui;
    GlobalPara *GP;

    Widget *pWidget;    //创建父类窗口指针
};

#endif // PROGSET_H
