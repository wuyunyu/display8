#include "mainWidget.h"
#include "ui_mainWidget.h"
#include "ui_sysset.h"
#include "ui_signalset.h"
#include "ui_progset.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    init();

    /////////////////////////////权限登录界面开始/////////////////////////////
    connect(ui->Btn_admin, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_main->setCurrentIndex(Login_id);
    });
    connect(ui->Btn_loginOk, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_main->setCurrentIndex(Main_id);
    });
    connect(ui->Btn_loginCancel, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_main->setCurrentIndex(Main_id);
    });
    ////////////////////////////////////////权限登录界面结束////////////////////////////////////////

    connect(ui->Btn_formula, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_main->setCurrentIndex(SubRun_id);
        ui->stackedWidget_subRun->setCurrentWidget(Formula_ui);
        ui->Btn_formula->hide();
    });

    connect(ui->Btn_progSel, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_main->setCurrentIndex(SubSet_id);
        ui->stackedWidget_selSet->setCurrentWidget(ProgSet_ui);
        ProgSet_ui->showProgSelPage();
        ui->Btn_progSel->hide();
    });

    /////////////////////////////导航主界面开始/////////////////////////////
    connect(ui->Btn_RunHome, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_sub->setCurrentWidget(RunPage_ui);
        ui->stackedWidget_teachDialog->hide();
        ui->Btn_formula->show();
        ui->Btn_progSel->hide();
        ui->Btn_coordSwitch->hide();
        Global::LCD_Main_Page = START_UP;
    });
    connect(ui->Btn_TeachHome, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_sub->setCurrentWidget(TeachPage_ui);
        ui->stackedWidget_teachDialog->hide();
        ui->Btn_formula->hide();
        ui->Btn_progSel->show();
        ui->Btn_coordSwitch->hide();
        Global::LCD_Main_Page = FREE_PROGRAMME;
    });
    connect(ui->Btn_DebugHome, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_sub->setCurrentWidget(DebugPage_ui);
        ui->stackedWidget_teachDialog->hide();
        ui->Btn_formula->hide();
        ui->Btn_progSel->hide();
        ui->Btn_coordSwitch->hide();
        Global::LCD_Main_Page = IO_CONTROL;
    });
    connect(ui->Btn_ManualHome, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_sub->setCurrentWidget(ManualPage_ui);
        ui->stackedWidget_teachDialog->hide();
        ui->Btn_formula->hide();
        ui->Btn_progSel->hide();
        ui->Btn_coordSwitch->show();
        Global::LCD_Main_Page = MANUL_DEBUG;
        Manual();
    });
    connect(ui->Btn_SetHome, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_sub->setCurrentWidget(SetPage_ui);
        ui->stackedWidget_teachDialog->hide();
        ui->Btn_formula->hide();
        ui->Btn_progSel->hide();
        ui->Btn_coordSwitch->hide();
        Global::LCD_Main_Page = SYSTEM_SETTING;     //标志为从设置界面进入个设置子界面
    });
    connect(ui->Btn_AlarmHome, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_sub->setCurrentWidget(AlarmPage_ui);
        ui->stackedWidget_teachDialog->hide();
        ui->Btn_formula->hide();
        ui->Btn_progSel->hide();
        ui->Btn_coordSwitch->hide();
        Global::LCD_Main_Page = ALARM_HISTORY;
    });
    ////////////////////////////////////////导航主界面结束////////////////////////////////////////
}


Widget::~Widget()
{
    delete ui;
}

void Widget::init()
{
    setFixedSize(QSize(1024,768));
    Label_Axis_Pos<<ui->label_X<<ui->label_Y<<ui->label_Z<<ui->label_O;

    //开辟需要调用的子窗体空间
    RunPage_ui = new RunPage(this); //把父类窗口的指针传给子窗口
    TeachPage_ui = new TeachPage(this);
    DebugPage_ui = new DebugPage(this);
    ManualPage_ui = new ManualPage(this);
    SetPage_ui = new SetPage(this);
    AlarmPage_ui = new AlarmPage(this);
    //开辟设置功能子窗体空间
    UserSet_ui = new UserSet(this);
    SignalSet_ui = new SignalSet(this);
    SafeSet_ui = new SafeSet(this);
    SysSet_ui = new SysSet(this);
    ProgSet_ui = new ProgSet(this);
    ExFuncSet_ui = new ExFuncSet(this);
    //开辟手动界面下功能子窗体空间
    Stacking_ui = new Stacking(this);
    MemoryPoint_ui = new MemoryPoint(this);
    StackPara_ui = new StackPara(this);
    StackSet_ui = new StackSet(this);
    FreeProg_ui = new FreeProg(this);
    //开辟运行界面下功能子窗体空间
    Formula_ui = new Formula(this);
    ProdPara_ui = new ProdPara(this);
    //开辟编程界面编辑对话框功能子窗体空间
    EditTeach_ui = new EditTeach(this);
    EditDialog_ui = new EditDialog(this);

    //将各个子窗口加入到主窗口stackedWidget_sub框架上
    ui->stackedWidget_sub->addWidget(RunPage_ui);
    ui->stackedWidget_sub->addWidget(TeachPage_ui);
    ui->stackedWidget_sub->addWidget(DebugPage_ui);
    ui->stackedWidget_sub->addWidget(ManualPage_ui);
    ui->stackedWidget_sub->addWidget(SetPage_ui);
    ui->stackedWidget_sub->addWidget(AlarmPage_ui);
    //将各个设置子窗口加入到窗口stackedWidget_selSet框架上
    ui->stackedWidget_selSet->insertWidget(User_id, UserSet_ui);
    ui->stackedWidget_selSet->insertWidget(Signal_id, SignalSet_ui);
    ui->stackedWidget_selSet->insertWidget(Safe_id, SafeSet_ui);
    ui->stackedWidget_selSet->insertWidget(System_id, SysSet_ui);
    ui->stackedWidget_selSet->insertWidget(Program_id, ProgSet_ui);
    ui->stackedWidget_selSet->insertWidget(ExFunction_id, ExFuncSet_ui);
    //将码垛管理窗口和存储点窗口加入到主窗口stackedWidget_main框架上
    ui->stackedWidget_subManual->addWidget(Stacking_ui);
    ui->stackedWidget_subManual->addWidget(MemoryPoint_ui);
    ui->stackedWidget_subManual->addWidget(StackPara_ui);
    ui->stackedWidget_subManual->addWidget(StackSet_ui);
    ui->stackedWidget_subManual->addWidget(FreeProg_ui);

    ui->stackedWidget_subRun->addWidget(Formula_ui);
    ui->stackedWidget_subRun->addWidget(ProdPara_ui);
    //将编辑对话框子窗口加入到主窗口stackedWidget_teachDialog框架上
    ui->stackedWidget_teachDialog->addWidget(EditTeach_ui);
    ui->stackedWidget_teachDialog->addWidget(EditDialog_ui);

    isAdmin = false;
    ui->stackedWidget->setCurrentIndex(1);

    Global::Robot_Init();
    if(Global::StartUp_Password_Dis)
    {//有开机密码
        ui->Btn_admin->setText(Admin_Authority_Dis[Global::Admin_Authority]);
        ui->Btn_user->setText(Admin_Authority_Dis[Global::Admin_Authority]);
        ui->Edit_code->clear(); //清除登录密码显示
        ui->stackedWidget->setCurrentIndex(0);
        ui->stackedWidget_main->setCurrentIndex(Login_id);
        ui->stackedWidget_login->setCurrentIndex(0);
        Global::StartUp_Password = TRUE;
        Global::gs_Reflash_Fuction_JXS = TRUE;
    }
    else
    {//无开机密码
        ui->stackedWidget->setCurrentIndex(0);
        ui->stackedWidget_main->setCurrentIndex(Main_id);
        ui->stackedWidget_sub->setCurrentWidget(RunPage_ui);
        Global::gs_Reflash_Fuction_JXS = TRUE;
    }

    //初始界面（运行子界面）
    ui->stackedWidget_main->setCurrentIndex(Main_id);
    ui->stackedWidget_sub->setCurrentWidget(RunPage_ui);
    ui->stackedWidget_login->setCurrentIndex(0);
    ui->Btn_progSel->hide();
    ui->Btn_coordSwitch->hide();
    //隐藏编程界面编辑对话框
    ui->stackedWidget_teachDialog->hide();

    //将图片嵌入到登入界面的用户输入框和密码输入框上，
    QAction *actionCode = new QAction(this);
    actionCode->setIcon(QIcon(":/main_images/code.png"));
    //嵌入位置为最左侧
    ui->Edit_code->addAction(actionCode, QLineEdit::LeadingPosition);
}

//进入配方参数界面
void Widget::formulaPage()
{
    ui->stackedWidget_main->setCurrentIndex(SubRun_id);
    ui->stackedWidget_subRun->setCurrentWidget(Formula_ui);
    ui->Btn_formula->hide();
}

//进入生产参数界面
void Widget::prodParaPage()
{
    ui->stackedWidget_main->setCurrentIndex(SubRun_id);
    ui->stackedWidget_subRun->setCurrentWidget(ProdPara_ui);
    ui->Btn_formula->hide();
}

//返回运行界面
void Widget::backRunPage()
{
    ui->stackedWidget_main->setCurrentIndex(Main_id);
    ui->stackedWidget_sub->setCurrentWidget(RunPage_ui);
    ui->Btn_formula->show();
}

//进入设置界面的具体子设置界面
void Widget::changeSetPage(const int selSetPage)
{
    ui->stackedWidget_main->setCurrentIndex(SubSet_id);
    ui->stackedWidget_selSet->setCurrentIndex(selSetPage);
}

//返回设置界面
void Widget::backSetPage()
{
    ui->stackedWidget_main->setCurrentIndex(Main_id);
    ui->stackedWidget_sub->setCurrentWidget(SetPage_ui);
}

//返回编程界面
void Widget::backTeachPage()
{
    ui->stackedWidget_main->setCurrentIndex(Main_id);
    ui->stackedWidget_sub->setCurrentWidget(TeachPage_ui);
    ui->Btn_progSel->show();
}

//进入码垛管理界面
void Widget::stackingPage()
{
    ui->stackedWidget_main->setCurrentIndex(SubManual_id);
    ui->stackedWidget_subManual->setCurrentWidget(Stacking_ui);
    Global::m_Reflash_Name_MD = TRUE;
    Stacking_ui->Reflash_Name_MD();
}

//进入码垛参数界面
void Widget::stackParaPage()
{
    ui->stackedWidget_main->setCurrentIndex(SubManual_id);
    ui->stackedWidget_subManual->setCurrentWidget(StackPara_ui);
}

//进入码垛坐标设置界面
void Widget::stackSetPage()
{
    ui->stackedWidget_main->setCurrentIndex(SubManual_id);
    ui->stackedWidget_subManual->setCurrentWidget(StackSet_ui);
}

//进入存储点界面
void Widget::memoryPointPage()
{
    ui->stackedWidget_main->setCurrentIndex(SubManual_id);
    ui->stackedWidget_subManual->setCurrentWidget(MemoryPoint_ui);
}

//返回手动界面
void Widget::backManualPage()
{
    ui->stackedWidget_main->setCurrentIndex(Main_id);
    ui->stackedWidget_sub->setCurrentWidget(ManualPage_ui);
}

//为编程界面提供进入自由编程界面的函数(EditTeach类调用)
void Widget::FreeProgPage()
{
    ui->stackedWidget_main->setCurrentIndex(SubManual_id);
    ui->stackedWidget_subManual->setCurrentWidget(FreeProg_ui);
    ui->stackedWidget_teachDialog->hide();
    ui->Btn_progSel->hide();
}

//为手动界面的自由编程界面提供返回编程界面的函数(FreeProg类调用)
void Widget::backEditTeachPage()
{
    ui->stackedWidget_main->setCurrentIndex(Main_id);
    ui->stackedWidget_sub->setCurrentWidget(TeachPage_ui);
    ui->stackedWidget_teachDialog->setCurrentWidget(EditTeach_ui);
    ui->stackedWidget_teachDialog->show();
    ui->Btn_progSel->show();
}

//直接进入设置下的输入信号设置界面
void Widget::InputPortSetPage()
{
    ui->stackedWidget_main->setCurrentIndex(SubSet_id);
    ui->stackedWidget_selSet->setCurrentWidget(SignalSet_ui);
    SignalSet_ui->InputSetPage();
}

//直接进入设置下的输出信号设置界面
void Widget::OutputPortSetPage()
{
    ui->stackedWidget_main->setCurrentIndex(SubSet_id);
    ui->stackedWidget_selSet->setCurrentWidget(SignalSet_ui);
    SignalSet_ui->OutputSetPage();
}

//跳转至程序管理设置界面的拷贝选择页面
void Widget::progCopySelPage()
{
    ui->stackedWidget_main->setCurrentIndex(SubSet_id);
    ui->stackedWidget_selSet->setCurrentWidget(ProgSet_ui);
    ProgSet_ui->ui->stackedWidget->setCurrentIndex(CopySel_id);
}

//跳转至程序管理设置界面的拷贝提示弹窗页面
void Widget::progCopyTipPage()
{
    ui->stackedWidget_main->setCurrentIndex(SubSet_id);
    ui->stackedWidget_selSet->setCurrentWidget(ProgSet_ui);
    ProgSet_ui->ui->stackedWidget->setCurrentIndex(5);
    ProgSet_ui->ui->stackedWidget_tip->setCurrentIndex(0);
}

//为编程界面提供弹出对话框的函数
void Widget::showEditTeach(const int DialogID)
{
    EditTeach_ui->switchDialog(DialogID);   //根据编程界面按钮对应的ID切换对话框的内容页面
    ui->stackedWidget_teachDialog->show();
    ui->stackedWidget_teachDialog->setCurrentWidget(EditTeach_ui);
    if(DialogID == OutputCtl_id)
    {
        EditTeach_ui->outputCtlShow(TeachPage::outputPort);
    }
    if(DialogID == InputDetect_id)
    {
        EditTeach_ui->inputDetectShow(TeachPage::inputPort);
    }
}

//为编程界面提供弹出编辑对话框的函数(EditTeach类调用)
void Widget::showEditDialog(const int EidtDialogID)
{
    EditDialog_ui->switchEditDialog(EidtDialogID);  //根据对话框中对应的按钮ID切换编辑对话框的内容页面
    ui->stackedWidget_teachDialog->setCurrentWidget(EditDialog_ui);
}

//为编程界面提供关闭对话框的函数(EditTeach类调用)
void Widget::editTeachEnd()
{
    ui->stackedWidget_teachDialog->hide();
}

//为编程界面提供关闭编辑对话框(回到对话框界面)的函数(EditDialog类调用)
void Widget::editTeachDialogEnd()
{
    ui->stackedWidget_teachDialog->setCurrentWidget(EditTeach_ui);
}

//系统设定界面绝对值保存后跳转权限登入界面函数
void Widget::JDZParaSaveAuthority()
{
    ui->stackedWidget_main->setCurrentIndex(Login_id);
    ui->stackedWidget_login->setCurrentIndex(1);
    ui->Edit_absValParacode->clear();//清除登录密码显示
}

void Widget::Auto()
{
    ui->label_auto_stop->setText("AUTO");
    ui->label_auto_stop->setStyleSheet("color:green;border-radius:34px;background-color:#00C0F9;");
    QPixmap PixIcon(":/main_images/manual0.png");
    ui->label_manual->setPixmap(PixIcon);
}

void Widget::Manual()
{
    QPixmap PixIcon(":/main_images/manual1.png");
    ui->label_manual->setPixmap(PixIcon);
}

void Widget::cycle()
{
    QPixmap PixIcon1(":/main_images/cycle1.png");
    ui->label_cycle_singleStep->setPixmap(PixIcon1);
    QPixmap PixIcon2(":/main_images/manual0.png");
    ui->label_manual->setPixmap(PixIcon2);
}

void Widget::singleStep()
{
    QPixmap PixIcon1(":/main_images/cycle0.png");
    ui->label_cycle_singleStep->setPixmap(PixIcon1);
    QPixmap PixIcon2(":/main_images/manual0.png");
    ui->label_manual->setPixmap(PixIcon2);
}

void Widget::showScreenSaver()
{
    ui->stackedWidget->setCurrentIndex(1);
}

/*************************************************************************
**  函数名： f_Axis_Position_Refresh()
** 输入参数：
** 输出参数：无
** 函数功能：轴位置刷新
** 备注：   无
**  作者：
**  开发日期：
**************************************************************************/
void Widget::f_Axis_Position_Refresh(u8 flag)
{
    u16 i = 0;
    u8 posChangeFlag = 0;
    s32 point[AXIS_NUM] = {0};
    s32 tarPoint[AXIS_NUM] = {0};

    if(flag == 1)
    {//必须重新刷新
        for(i=0; i<AXIS_NUM; i++)
        {
            MAINW::gs_StartUp_Axis_Position[i] = Global::g_Axis_Position[i] + 1;
        }
    }

    if(Global::Robot_Origined == 1 && Global::g_AxiseCarteType == 1)
    {
        for(i=0; i<AXIS_NUM; i++)
        {
            if(MAINW::gs_StartUp_Axis_Position[i] != Global::g_Axis_Position[i])
            {//轴位置刷新，需要刷新坐标显示
                posChangeFlag = 1;
                break;
            }
        }

        if(posChangeFlag == 1)
        {
            for(i=0; i<AXIS_NUM; i++)
            {//将脉冲坐标转换成距离，单位0.01mm
                MAINW::gs_StartUp_Axis_Position[i] = Global::g_Axis_Position[i];
                point[i] = MAINW::gs_StartUp_Axis_Position[i] * 100 / Global::Axis_Step_Coefficient[i].Step_Coefficient;
            }

            mMD.MD_PosSolCal(point, tarPoint);
            for(i=0; i<AXIS_NUM; i++)
            {
                Label_Axis_Pos.at(i)->setText(QString::number(tarPoint[i]));
            }
        }
    }
    else
    {
        for(i=0; i<AXIS_NUM; i++)
        {
            if(MAINW::gs_StartUp_Axis_Position[i] != Global::g_Axis_Position[i])
            {//轴位置刷新
                MAINW::gs_StartUp_Axis_Position[i] = Global::g_Axis_Position[i];
                Label_Axis_Pos.at(i)->setText(QString::number(MAINW::gs_StartUp_Axis_Position[i] * 100 / Global::Axis_Step_Coefficient[i].Step_Coefficient - Global::JXS_Parameter.OriginOffset[i]));
            }
        }
    }
}

//刷新坐标系类型
void Widget::AxiseCarteType_Refresh(u8 flag)
{
    if(flag == TRUE)
    {
        ui->Btn_coordSwitch->setText(g_AxiseCarteTypeString[Global::g_AxiseCarteType]);
        Global::gs_AxiseCarteType_Refresh = FALSE;
        f_Axis_Position_Refresh(1);
    }
}

void Widget::Stop()
{
    ui->label_auto_stop->setText("STOP");
    ui->label_auto_stop->setStyleSheet("color:red;border-radius:34px;background-color:#00C0F9;");
    QPixmap PixIcon1(":/main_images/manual0.png");
    ui->label_manual->setPixmap(PixIcon1);
    QPixmap PixIcon2(":/main_images/cycle0.png");
    ui->label_cycle_singleStep->setPixmap(PixIcon2);
}

void Widget::on_Btn_user_clicked()
{
    isAdmin = !isAdmin;
    if(isAdmin){
        ui->Btn_user->setText("管理员权限");
        ui->Btn_admin->setText("管理员");
    }
    else{
        ui->Btn_user->setText("普通权限");
        ui->Btn_admin->setText("普通用户");
    }
}

void Widget::on_Btn_exitScreenSaver_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//绝对值保存密码确定
void Widget::on_Btn_absValParaOk_clicked()
{
    if((Global::Admin_Authority == 1) && (Global::PassWord_Input_Done == TRUE) && (Global::Pass_Word[1] == Global::Pass_Word_Temp))
    {//“管理员权限”登录密码正确
        ui->stackedWidget_main->setCurrentIndex(SubSet_id);
        ui->stackedWidget_selSet->setCurrentWidget(SysSet_ui);

        Global::PassWord_Input_Done = FALSE;
        Global::Pass_Word_Temp = 0;
        SysSet_ui->JDZ_Tips1();    //绝对值参数保存中

        if(Global::Temp_JDZ_Parameter.Switch == 1)
        {
            Global::Internet_Parameter.Switch = 0;
            Global::f_SendInternetPara();
        }

        if(Global::JDZ_Parameter.Switch != Global::Temp_JDZ_Parameter.Switch || Global::JDZ_Parameter.Server != Global::Temp_JDZ_Parameter.Server )
        {//绝对值开关或者伺服电机发生改变是需要提示重启系统
            for(int i=0; i<AXIS_NUM; i++)
            {
                Global::JDZ_Parameter.OriginSetting[i] = 0;
            }
            Global::JDZ_Para_Save();
            SysSet_ui->JDZ_Tips2();																//重新启动界面
        }
        else
        {
            Global::JDZ_Para_Save();
            SysSet_ui->JDZ_ModBack();												//绝对值参数设置界面
        }
        SET::gs_Reflash_Save_JDZ = TRUE;
        SysSet_ui->Reflash_Fuction_JDZ(1);
    }
    else
    {//弹出提示框-密码错误
        ui->stackedWidget_login->setCurrentIndex(2);
        ui->Edit_absValParacode->clear();											//清除登录密码显示
    }
}

//绝对值保存密码取消,返回绝对值设置界面
void Widget::on_Btn_absValParaCancel_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(SubSet_id);
    ui->stackedWidget_selSet->setCurrentWidget(SysSet_ui);
    SysSet_ui->JDZ_ModBack();
    Global::gs_Reflash_Fuction_JDZ = TRUE;
    SysSet_ui->Reflash_Fuction_JDZ(0);
}

//弹出提示框-密码错误后返回密码输入界面
void Widget::on_Btn_errorCancel_clicked()
{
    ui->stackedWidget_login->setCurrentIndex(1);
}
