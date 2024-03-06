#include "userset.h"
#include "ui_userset.h"
#include "mainWidget.h"

UserSet::UserSet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserSet)
{
    ui->setupUi(this);

    pWidget = static_cast<Widget*>(parent);

    init();
    Global::Para_Rst();

    connect(mTimer, SIGNAL(timeout()), this, SLOT(freshTimeUi()));
//    connect(mTimer, &QTimer::timeout, this, &UserSet::freshTimeUi);
    //返回设置子界面
    connect(ui->Btn_back, &QPushButton::clicked, this, [=](){
        pWidget->backSetPage();
    });

    //恢复出厂设置
    connect(ui->Btn_RST, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(UserSetDialog_id);
        ui->stackedWidget_dialog->setCurrentIndex(Rst_id);      //切换到恢复出厂设置界面
        Global::Restore_setting = TRUE;
        ui->Edit_code->clear();     //清除登录密码显示
    });
    connect(ui->Btn_RSTOk, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(UserSet_id);
    });
    connect(ui->Btn_RSTCancel, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(UserSet_id);
    });

    //参数拷贝
    connect(ui->Btn_USBcopy, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(5);
    });

    //蜂鸣器开关
    connect(ui->Btn_buzzer, &QPushButton::clicked, this, [=](){
        Global::g_Buzzer_Switch_Flag = Global::ValSwitch(Global::g_Buzzer_Switch_Flag);
        ui->Btn_buzzer->setText(Buzzer_Switch[Global::g_Buzzer_Switch_Flag]);
        mBeeper->saveBeeTime(Global::g_Buzzer_Switch_Flag * 100);
        mBeeper->beep();
    });

    //时钟设置
    connect(ui->Btn_clockSet, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(TimeSet_id);
        editClr();
    });
    connect(ui->Btn_clockSetOk, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(UserSet_id);
        clockSetShow();
    });
    connect(ui->Btn_clockSetBack, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(UserSet_id);
        editClr();
    });

    //背光时间修改
    connect(ui->Edit_backlightTime, &QLineEdit::editingFinished, this, [=](){
        mLighter->setBacklightTime(ui->Edit_backlightTime->text().toInt()*1000);
        mLighter->setStartBacklightTimer(true);
    });

    //修改密码
    connect(ui->Btn_modPassword, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(ModPassword_id);
        SET::gs_Pass_Word_Temp[0] = 0;
        SET::gs_Pass_Word_Temp[1] = 0;
        SET::gs_Pass_Word_Temp[2] = 0;
        SET::gs_Pass_Word_Refresh = TRUE;
        Pass_Word_Refresh();
        editClr();
    });
    //修改密码-确定
    connect(ui->Btn_modPasswordOk, &QPushButton::clicked, this, [=](){
        if(SET::gs_Pass_Word_Temp[2] != SET::gs_Pass_Word_Temp[1])
        {//弹框提示-两次输入新密码不一致
            ui->stackedWidget->setCurrentIndex(UserSetDialog_id);
            ui->label_passwordErrorTip->setText(PasswordError_Tip[2]);
            ui->stackedWidget_dialog->setCurrentIndex(PasswordErrorTip_id);
        }
        else
        {
            if((Global::Change_User_Password == 0) && (SET::gs_Pass_Word_Temp[0] == Global::Pass_Word[0]))
            {//修改普通权限密码
                ui->stackedWidget->setCurrentIndex(UserSet_id);
                Global::Pass_Word[0] = SET::gs_Pass_Word_Temp[1];
                //需将修改密码存到对应文件！！！
            }
            else if((Global::Change_User_Password == 1) && (SET::gs_Pass_Word_Temp[0] == Global::Pass_Word[1]))
            {//修改管理员权限密码
                ui->stackedWidget->setCurrentIndex(UserSet_id);
                Global::Pass_Word[1] = SET::gs_Pass_Word_Temp[1];
                //需将修改密码存到对应文件！！！
            }
            else
            {//弹框提示-原密码错误
                ui->stackedWidget->setCurrentIndex(UserSetDialog_id);
                ui->label_passwordErrorTip->setText(PasswordError_Tip[0]);
                ui->stackedWidget_dialog->setCurrentIndex(PasswordErrorTip_id);
            }
        }
    });
    connect(ui->Btn_modPasswordBack, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(UserSet_id);
        editClr();
    });
    connect(ui->Btn_modPasswordCancel, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(ModPassword_id);
        editClr();
    });
    //修改密码-原密码
    connect(ui->Edit_oldPassword, &QLineEdit::editingFinished, this, [=](){
        SET::gs_Pass_Word_Temp[0] = ui->Edit_oldPassword->text().toUInt();
    });
    //修改密码-新密码
    connect(ui->Edit_newPassword, &QLineEdit::editingFinished, this, [=](){
        if(ui->Edit_newPassword->text().toUInt() < 100000)
        {//弹框提示-请输入有效的六位密码
            ui->stackedWidget->setCurrentIndex(UserSetDialog_id);
            ui->label_passwordErrorTip->setText(PasswordError_Tip[1]);
            ui->stackedWidget_dialog->setCurrentIndex(PasswordErrorTip_id);
        }
        else
        {
            SET::gs_Pass_Word_Temp[1] = ui->Edit_newPassword->text().toUInt();
        }
    });
    //修改密码-确认新密码
    connect(ui->Edit_renewPassword, &QLineEdit::editingFinished, this, [=](){
        if(ui->Edit_renewPassword->text().toUInt() < 100000)
        {//弹框提示-请输入有效的六位密码
            ui->stackedWidget->setCurrentIndex(UserSetDialog_id);
            ui->label_passwordErrorTip->setText(PasswordError_Tip[1]);
            ui->stackedWidget_dialog->setCurrentIndex(PasswordErrorTip_id);
        }
        else
        {
            SET::gs_Pass_Word_Temp[2] = ui->Edit_renewPassword->text().toUInt();
        }
    });

    //修改加密锁
    connect(ui->Btn_encryptionSet, &QPushButton::clicked, this, [=](){
        if(Global::Robot_Admin_Authority == MANAGE_AUTHORITY)
        {
            ui->stackedWidget->setCurrentIndex(EncryptionSet_id);        //切换到加密锁界面
        }
    });
    //修改加密锁--确定
    connect(ui->Btn_encryptionSetOk, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(UserSet_id);
    });
    //修改加密锁--返回
    connect(ui->Btn_encryptionSetBack, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(UserSet_id);
        ui->label_mechCode->setText("0");
    });

    //设置开机密码开关
    connect(ui->Btn_password, &QPushButton::clicked, this, [=](){
        if(Global::StartUp_Password_Dis)
        {
            Global::StartUp_Password_Dis = 0;
        }
        else
        {
            Global::StartUp_Password_Dis = 1;
        }
        SET::gs_Refresh_StartUp_Password = TRUE;
        ui->Btn_password->setText(StartUp_Password_Switch[Global::StartUp_Password_Dis]);   //开机密码开/关刷新
    });
}

UserSet::~UserSet()
{
    delete ui;
}

void UserSet::initTime()
{
    QDateTime dt = QDateTime::currentDateTime();
    QString strTime = dt.toString("yyyy-MM-dd hh:mm:ss");
    ui->Btn_clockSet->setText(strTime);
    QDate date = dt.date();
    QTime t = dt.time();
    ui->Edit_year->setText(QString::number(date.year()));
    QString formatText = QString("%1").arg(date.month(), 2 , 10, QLatin1Char('0'));
    ui->Edit_month->setText(formatText);
    formatText = QString("%1").arg(date.day(), 2 , 10, QLatin1Char('0'));
    ui->Edit_day->setText(formatText);
    formatText = QString("%1").arg(t.hour(), 2 , 10, QLatin1Char('0'));
    ui->Edit_hour->setText(formatText);
    formatText = QString("%1").arg(t.minute(), 2 , 10, QLatin1Char('0'));
    ui->Edit_minute->setText(formatText);
    formatText = QString("%1").arg(t.second(), 2 , 10, QLatin1Char('0'));
    ui->Edit_second->setText(formatText);
}

void UserSet::init()
{
    ui->stackedWidget->setCurrentIndex(UserSet_id);

    backlightTime = 60*1000;
    ui->Edit_backlightTime->setText("60");
    mLighter->setBacklightTime(backlightTime);
    mLighter->setStartBacklightTimer(true);

    mTimer = new QTimer(this);
    ui->Edit_year->installEventFilter(this);
    ui->Edit_month->installEventFilter(this);
    ui->Edit_day->installEventFilter(this);
    ui->Edit_hour->installEventFilter(this);
    ui->Edit_minute->installEventFilter(this);
    ui->Edit_second->installEventFilter(this);
    ui->Edit_backlightTime->installEventFilter(this);
    ui->Edit_backlightTime->setValidator(new QIntValidator(30,3000,this));
    ui->Edit_year->setValidator(new QIntValidator(2000,3000,this));
    ui->Edit_month->setValidator(new QIntValidator(1,12,this));
    ui->Edit_day->setValidator(new QIntValidator(1,31,this));
    ui->Edit_hour->setValidator(new QIntValidator(0,23,this));
    ui->Edit_minute->setValidator(new QIntValidator(0,59,this));
    ui->Edit_second->setValidator(new QIntValidator(0,59,this));   

    bAdmin = false;
    ui->label_switchUser->setText("普通用户");
    ui->label_versionNum->setText(Edition);//显示版本号
    ui->label_passwordErrorTip->setAlignment(Qt::AlignCenter);

    initTime();

    mBeeper = SysCfgFactory::instance()->getBeeper();
    mBeeper->saveBeeTime(0);
    mLighter = SysCfgFactory::instance()->getBacklighter();
}

//清空编辑框内容
void UserSet::editClr()
{
    ui->Edit_code->clear();
    ui->Edit_year->clear();
    ui->Edit_month->clear();
    ui->Edit_day->clear();
    ui->Edit_hour->clear();
    ui->Edit_minute->clear();
    ui->Edit_second->clear();

    ui->Edit_mechCode->clear();
    ui->Edit_unlockPassword->clear();
}

//显示设置的时间
void UserSet::clockSetShow()
{
    int year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0;
    year = ui->Edit_year->text().toInt();
    month = ui->Edit_month->text().toInt();
    day = ui->Edit_day->text().toInt();
    hour = ui->Edit_hour->text().toInt();
    minute = ui->Edit_minute->text().toInt();
    second = ui->Edit_second->text().toInt();
    tm t;
    t.tm_year = year - 1900;
    t.tm_isdst = 0;
    t.tm_mon = month - 1;
    t.tm_mday = day;
    t.tm_hour = hour;
    t.tm_min = minute;
    t.tm_sec = second;
    ITimeSetter* setter = SysCfgFactory::instance()->getTimeSetter();
    if(setter)
    {
        if(setter->setTime(t) == 0)
        {
            return;
        }
        else
        {
            ui->Btn_clockSet->setText("时间设置失败");
        }
    }
}

//用户设置界面打开时定时器开始计数
void UserSet::showEvent(QShowEvent *event)
{
    UNUSED(event);
    mTimer->start(100);
}

//用户设置界面隐藏时定时器停止计数
void UserSet::hideEvent(QHideEvent *event)
{
    UNUSED(event);
    mTimer->stop();
}

bool UserSet::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::FocusOut)
    {
        if(obj == ui->Edit_year){
            fixYear();
        }
        else if(obj == ui->Edit_month){
            fixMonth();
        }
        else if(obj == ui->Edit_day){
            fixDay();
        }
        else if(obj == ui->Edit_hour){
            fixTime(ui->Edit_hour, 23, 0);
        }
        else if(obj == ui->Edit_minute){
            fixTime(ui->Edit_minute, 59, 0);
        }
        else if(obj == ui->Edit_second){
            fixTime(ui->Edit_second, 59, 0);
        }
        else if(obj == ui->Edit_backlightTime){
            fixTime(ui->Edit_backlightTime, 3600, 10);
        }
    }
    return QWidget::eventFilter(obj, event);
}

void UserSet::fixTime(QLineEdit *lineEdit, int max, int min)
{
    int value = lineEdit->text().toInt();
    value = value > max ? max : value;
    value = value < min ? min : value;
    QString formatText = QString("%1").arg(value, 2 , 10, QLatin1Char('0'));
    lineEdit->setText(formatText);
}

void UserSet::fixYear()
{
    int year = ui->Edit_year->text().toInt();
    year = year > 2050 ? 2050 : year;
    year = year < 1970 ? 1970 : year;
    ui->Edit_year->setText(QString::number(year));
    fixDay();
}

void UserSet::fixMonth()
{
    int month = ui->Edit_month->text().toInt();
    month = month > 12 ? 12 : month;
    month = month < 1 ? 1 : month;
    QString formatText = QString("%1").arg(month, 2 , 10, QLatin1Char('0'));
    ui->Edit_month->setText(formatText);
    fixDay();
}

void UserSet::fixDay()
{
    int day = ui->Edit_day->text().toInt();
    day = day < 1 ? 1 : day;
    int month = ui->Edit_month->text().toInt();
    if(month == 2){
        int year = ui->Edit_year->text().toInt();
        if(isLeapYear(year)){
            day = day > 29 ? 29 : day;
        }
        else{
            day = day > 28 ? 28 : day;
        }
    }
    else{
        if(isBigMonth(month)){
            day = day > 31 ? 31 : day;
        }
        else{
            day = day > 30 ? 30 : day;
        }
    }
    QString formatText = QString("%1").arg(day, 2 , 10, QLatin1Char('0'));
    ui->Edit_day->setText(formatText);
}

bool UserSet::isLeapYear(int year) const
{
    return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
}

bool UserSet::isBigMonth(int month) const
{
    month = month > 7 ? month - 7 : month;
    return month % 2 == 1;
}

void UserSet::freshTimeUi()
{
    QWidget* widget = focusWidget();
    if(widget == ui->Edit_year || widget == ui->Edit_month || widget == ui->Edit_day ||
            widget == ui->Edit_hour || widget == ui->Edit_minute || widget == ui->Edit_second)
    {
        return;
    }
    initTime();
}


//用户设置--密码显示刷新
void UserSet::Pass_Word_Refresh()
{
    ui->Btn_modPassword->setText(gs_Pass_Word_String);
    ui->Btn_encryptionSet->setText(gs_Pass_Word_String);
    ui->Btn_adminAuthority->setText(Admin_Authority_Dis[Global::Change_User_Password]);
    ui->Edit_oldPassword->clear();
    ui->Edit_newPassword->clear();
    ui->Edit_renewPassword->clear();
}





