#ifndef SIGNALSET_H
#define SIGNALSET_H

#include <QWidget>
#include <QList>
#include <QPushButton>
#include "ParaConfig/parasum.h"

#define  InputSet(i,j)  connect(i, &QPushButton::clicked, this, [=]()\
                    {ui->stackedWidget_dialog->show(); ui->label_inputPort->setText(j);})
#define  OutputSet(i,j)  connect(i, &QPushButton::clicked, this, [=]()\
                    {ui->stackedWidget_dialog->show(); ui->label_outputPort->setText(j);})

class Widget;   //声明父窗口类
class SetPage;

namespace Ui {
class SignalSet;
}

class SignalSet : public QWidget
{
    Q_OBJECT

    friend class SetPage;

public:
    QList<QPushButton*> Btn_X_List;
    QList<QPushButton*> Btn_Y_List;

public:
    explicit SignalSet(QWidget *parent = nullptr);
    ~SignalSet();

    void init();
    void InputSetPage();
    void OutputSetPage();

public:
    void IO_Detect_Display_Refresh_Input(u8 flag);
    void IO_Detect_Display_Refresh(u8 flag);

private:
    Ui::SignalSet *ui;
    GlobalPara *GP;

    Widget *pWidget;    //创建父类窗口指针
};

#endif // SIGNALSET_H
