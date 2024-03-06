#ifndef PRODPARA_H
#define PRODPARA_H

#include <QWidget>
#include "ParaConfig/parasum.h"

class Widget;   //声明父窗口类
class Stacking;

namespace Ui {
class ProdPara;
}

class ProdPara : public QWidget
{
    Q_OBJECT

public:
    explicit ProdPara(QWidget *parent = nullptr);
    ~ProdPara();

public:
    void Reflash_Run_MD();

public:
    Ui::ProdPara *ui;
//    Global GL;
    Widget *pWidget;    //创建父类窗口指针
};

#endif // PRODPARA_H
