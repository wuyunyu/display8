#ifndef MEMORYPOINT_H
#define MEMORYPOINT_H

#include <QWidget>
#include "ParaConfig/parasum.h"

class Widget;   //声明父窗口类

namespace Ui {
class MemoryPoint;
}

class MemoryPoint : public QWidget
{
    Q_OBJECT

public:

    bool bName;

public:
    explicit MemoryPoint(QWidget *parent = nullptr);
    ~MemoryPoint();

    void init();

public:
    Ui::MemoryPoint *ui;
//    Global GL;
    Widget *pWidget;    //创建父类窗口指针
};

#endif // MEMORYPOINT_H
