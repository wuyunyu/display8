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

    friend class Stacking;

public:
    explicit ProdPara(QWidget *parent = nullptr);
    ~ProdPara();



private:
    Ui::ProdPara *ui;
    GlobalPara *GP;

    Widget *pWidget;    //创建父类窗口指针
};

#endif // PRODPARA_H
