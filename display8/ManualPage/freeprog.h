#ifndef FREEPROG_H
#define FREEPROG_H

#include <QWidget>
#include "ParaConfig/parasum.h"

class Widget;   //声明父窗口类

namespace Ui {
class FreeProg;
}

class FreeProg : public QWidget
{
    Q_OBJECT

public:
    explicit FreeProg(QWidget *parent = nullptr);
    ~FreeProg();

public:
    void Refresh_MD_Circulation();

public:
    Ui::FreeProg *ui;
//    Global GL;
    Widget *pWidget;    //创建父类窗口指针
};

#endif // FREEPROG_H
