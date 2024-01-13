#ifndef STACKING_H
#define STACKING_H

#include <QWidget>
#include <QList>
#include <QPushButton>
#include "ParaConfig/parasum.h"
#include "RunPage/prodpara.h"

class Widget;   //声明父窗口类
class ProdPara;

namespace Ui {
class Stacking;
}

class Stacking : public QWidget
{
    Q_OBJECT


public:
    //码垛管理相关界面id
    enum StackWidget{
        StackMgt_id=0,   //码垛管理界面ID
        CopySel_id,    //拷贝选择界面ID
        CtoU_id,    //控制器拷贝到U盘界面ID
        UtoC_id,    //U盘拷贝到控制器界面ID
    };

    QList<QPushButton*> Btn_MDSel_List;


public:
    explicit Stacking(QWidget *parent = nullptr);
    ~Stacking();

    void stackParaSet();
    void init();

public:
    void Reflash_Name_MD(u8 flag);

public:
    Ui::Stacking *ui;
    GlobalPara *GP;
    ProdPara *ProdPara_ui;
    Widget *pWidget;    //创建父类窗口指针
};

#endif // STACKING_H
