#ifndef STACKPARA_H
#define STACKPARA_H

#include <QWidget>
#include "ParaConfig/parasum.h"

class Widget;   //声明父窗口类

namespace Ui {
class StackPara;
}

class StackPara : public QWidget
{
    Q_OBJECT

public:
    explicit StackPara(QWidget *parent = nullptr);
    ~StackPara();

    void init();
    void modStackCoord();

private:
    Ui::StackPara *ui;

    Widget *pWidget;    //创建父类窗口指针
};

#endif // STACKPARA_H
