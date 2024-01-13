#ifndef EDITTEACH_H
#define EDITTEACH_H

#include <QWidget>
#include "ParaConfig/parasum.h"

#define  AxisMoveSel(i,j)  connect(i, &QPushButton::clicked, this, [=]()\
                            {ui->label_axisMoveSel->setText(j);})
#define  StackPosSel(i,j)  connect(i, &QPushButton::clicked, this, [=]()\
                            {ui->label_stackPosSel->setText(j);})
#define  SearchMotionSel(i,j)  connect(i, &QPushButton::clicked, this, [=]()\
                            {ui->label_searchMotionSel->setText(j);})
#define  MachBack0Sel(i,j)  connect(i, &QPushButton::clicked, this, [=]()\
                            {ui->label_machBack0Sel->setText(j);})
#define  CoordRstSel(i,j)  connect(i, &QPushButton::clicked, this, [=]()\
                            {ui->label_coordRstSel->setText(j);})
#define  SlowDownSel(i,j)  connect(i, &QPushButton::clicked, this, [=]()\
                            {ui->label_slowDownSel->setText(j);})
#define  AdvConfirmSel(i,j)  connect(i, &QPushButton::clicked, this, [=]()\
                            {ui->label_advConfirmSel->setText(j);})
#define  TransPointSel(i,j)  connect(i, &QPushButton::clicked, this, [=]()\
                            {ui->label_transPointSel->setText(j);})
#define  IncMotionSel(i,j)  connect(i, &QPushButton::clicked, this, [=]()\
                            {ui->label_incMotionSel->setText(j);})

class Widget;   //声明父窗口类

namespace Ui {
class EditTeach;
}

class EditTeach : public QWidget
{
    Q_OBJECT

public:


public:
    explicit EditTeach(QWidget *parent = nullptr);
    ~EditTeach();

    void switchDialog(const int dialogID);
    void outputCtlShow(const QString portShow);
    void inputDetectShow(const QString portShow);

    void displayText();

private slots:


private:
    Ui::EditTeach *ui;

    Widget *pWidget;    //创建父类窗口指针
    GlobalPara *GP;
};

#endif // EDITTEACH_H
