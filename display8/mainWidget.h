#ifndef WIDGET_H
#define WIDGET_H

#include <QPixmap>
#include <QAction>
#include <QWidget>
#include <QList>
#include <QLabel>
#include "./VirtualDevice/syscfgfactory.h"
#include "./RunPage/runpage.h"
#include "./RunPage/formula.h"
#include "./RunPage/prodpara.h"
#include "./TeachPage/teachpage.h"
#include "./DebugPage/debugpage.h"
#include "./ManualPage/manualpage.h"
#include "./SetPage/setpage.h"
#include "./AlarmPage/alarmpage.h"
#include "./SetPage/userset.h"
#include "./SetPage/signalset.h"
#include "./SetPage/safeset.h"
#include "./SetPage/sysset.h"
#include "./SetPage/progset.h"
#include "./SetPage/exfuncset.h"
#include "./ManualPage/stacking.h"
#include "./ManualPage/memorypoint.h"
#include "./ManualPage/stackpara.h"
#include "./ManualPage/stackset.h"
#include "./ManualPage/freeprog.h"
#include "./TeachPage/editteach.h"
#include "./TeachPage/editdialog.h"
#include "./ParaConfig/parasum.h"
#include "./ParaConfig/paraconfig.h"
#include "./MidLevel/md.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

//class GlobalPara;

//class RunPage;
//class Formula;
//class ProdPara;

//class TeachPage;
//class EditTeach;
//class EditDialog;

//class DebugPage;

//class ManualPage;
//class MemoryPoint;
//class Stacking;
//class StackPara;
//class StackSet;
//class FreeProg;

//class SetPage;
//class UserSet;
//class SignalSet;
//class SafeSet;
//class SysSet;
//class ProgSet;
//class ExFuncSet;

//class AlarmPage;

class Widget : public QWidget
{
    Q_OBJECT

public:
    bool isAdmin;
    QList<QLabel*> Label_Axis_Pos;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void init();

    void formulaPage();
    void prodParaPage();
    void backRunPage();

    void changeSetPage(const int selSetPage);
    void backSetPage();
    void backTeachPage();

    void stackingPage();
    void stackParaPage();
    void stackSetPage();
    void memoryPointPage();
    void backManualPage();

    void FreeProgPage();
    void backEditTeachPage();

    void InputPortSetPage();
    void OutputPortSetPage();

    void progCopySelPage();
    void progCopyTipPage();

    void showEditTeach(const int DialogID);
    void showEditDialog(const int EidtDialogID);
    void editTeachEnd();
    void editTeachDialogEnd();

    void JDZParaSaveAuthority();

    void Auto();
    void Stop();
    void Manual();
    void cycle();
    void singleStep();
    void showScreenSaver();
    void f_Axis_Position_Refresh(u8 flag);
    void AxiseCarteType_Refresh(u8 flag);

private slots:
    void on_Btn_user_clicked();
    void on_Btn_exitScreenSaver_clicked();

    void on_Btn_absValParaOk_clicked();

    void on_Btn_absValParaCancel_clicked();

    void on_Btn_errorCancel_clicked();

public:
    Ui::Widget *ui;
    MD mMD;

    //主界面下的各子界面
    RunPage *RunPage_ui;
    TeachPage *TeachPage_ui;
    DebugPage *DebugPage_ui;
    ManualPage *ManualPage_ui;
    SetPage *SetPage_ui;
    AlarmPage *AlarmPage_ui;
    //设置界面下的各个功能界面
    UserSet *UserSet_ui;
    SignalSet *SignalSet_ui;
    SafeSet *SafeSet_ui;
    SysSet *SysSet_ui;
    ProgSet *ProgSet_ui;
    ExFuncSet *ExFuncSet_ui;
    //手动界面下的其他界面
    Stacking *Stacking_ui;
    MemoryPoint *MemoryPoint_ui;
    StackPara *StackPara_ui;
    StackSet *StackSet_ui;
    FreeProg *FreeProg_ui;

    Formula *Formula_ui;
    ProdPara *ProdPara_ui;

    EditTeach *EditTeach_ui;
    EditDialog *EditDialog_ui;
};
#endif // WIDGET_H
