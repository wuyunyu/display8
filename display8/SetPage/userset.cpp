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
    RestoreSetting();

    connect(mTimer, SIGNAL(timeout()), this, SLOT(freshTimeUi()));
//    connect(mTimer, &QTimer::timeout, this, &UserSet::freshTimeUi);
    //返回设置子界面
    connect(ui->Btn_back, &QPushButton::clicked, this, [=](){
        pWidget->backSetPage();
    });
    //恢复出厂设置
    connect(ui->Btn_RST, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(UserSetDialog_id);
        ui->stackedWidget_dialog->setCurrentIndex(Rst_id);
    });
    connect(ui->Btn_RSTOk, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(UserSet_id);
    });
    connect(ui->Btn_RSTCancel, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(UserSet_id);
    });
    //时钟设置
    connect(ui->Btn_clockSet, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(TimeSet_id);
        this->editClr();
    });
    connect(ui->Btn_clockSetBack, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(UserSet_id);
        this->editClr();
    });
    //背光时间修改
    connect(ui->Edit_backlightTime, &QLineEdit::editingFinished, this, [=](){
        mLighter->setBacklightTime(ui->Edit_backlightTime->text().toInt()*1000);
        mLighter->setStartBacklightTimer(true);
    });
    //修改密码
    connect(ui->Btn_modPassword, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(ModPassword_id);
        this->editClr();
    });
    connect(ui->Btn_modPasswordOk, &QPushButton::clicked, this, [=](){
        if(this->passwordModErrorTip())
            ui->stackedWidget->setCurrentIndex(UserSet_id);
    });
    connect(ui->Btn_modPasswordBack, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(UserSet_id);
        this->editClr();
    });
    connect(ui->Btn_modPasswordCancel, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(ModPassword_id);
        this->editClr();
    });
    //加密设置
    connect(ui->Btn_encryptionSet, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(EncryptionSet_id);
    });
    connect(ui->Btn_encryptionSetOk, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(UserSet_id);
    });
    connect(ui->Btn_encryptionSetBack, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(UserSet_id);
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

    Key = "123456";
    bAdmin = false;
    bBee = false;
    ui->label_switchUser->setText("普通用户");
    ui->Btn_password->setText(Key);
    ui->label_versionNum->setText(Edition);//显示版本号


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
        if(setter->setTime(t) == 0){
            return;
        }
        else{
            ui->Btn_clockSet->setText("时间设置失败");
        }
    }
}

//密码更改错误提示，设置成功返回1，否则为0
bool UserSet::passwordModErrorTip()
{
    if(ui->Edit_oldPassword->text() != Key)
    {
        ui->stackedWidget->setCurrentIndex(UserSetDialog_id);
        ui->label_passwordErrorTip->setText("原密码错误，请输入正确原密码!");
        ui->label_passwordErrorTip->setAlignment(Qt::AlignCenter);
        ui->stackedWidget_dialog->setCurrentIndex(PasswordErrorTip_id);
        return 0;
    }
    else if(ui->Edit_newPassword->text().length() != 6)
    {
        ui->stackedWidget->setCurrentIndex(UserSetDialog_id);
        ui->label_passwordErrorTip->setText("请输入有效的六位密码!");
        ui->label_passwordErrorTip->setAlignment(Qt::AlignCenter);
        ui->stackedWidget_dialog->setCurrentIndex(PasswordErrorTip_id);
        return 0;
    }
    else if(ui->Edit_newPassword->text() != ui->Edit_renewPassword->text())
    {
        ui->stackedWidget->setCurrentIndex(UserSetDialog_id);
        ui->label_passwordErrorTip->setText("两次输入密码不一致!");
        ui->label_passwordErrorTip->setAlignment(Qt::AlignCenter);
        ui->stackedWidget_dialog->setCurrentIndex(-PasswordErrorTip_id);
        return 0;
    }
    else
    {
        Key = ui->Edit_newPassword->text();
        return 1;
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
            fixTime(ui->Edit_backlightTime, 3000, 30);
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

void UserSet::RestoreSetting()
{   //软限位恢复出厂设置
    u8 data[1] = {0};
    u16 j = 0;
    u16 i = 0;
    IONameParameter Temp_Free_Output_Name;	//用于给自由编程输出指令赋值的临时变量
    IONameParameter Temp_Free_Input_Name;	//用于给自由编程输入指令赋值的临时变量
    u8 Delete_Point_Syc_Ready = 0;
    u8 Delete_Program_Syc_Ready = 0;
    u8 Delete_MD_Syc_Ready = 0;

    //软限位参数恢复
    for(j=0; j<AXIS_NUM; j++)
    {
        GP->Robot_SoftLimit[j].Left_Limit  = 0;
        GP->Robot_SoftLimit[j].Right_Limit = 0;
        GP->Robot_SoftLimit[j].Switch_Limit = 0;
    }
    GP->Robot_SoftDistance.MaxDistance  = 0;
    GP->Robot_SoftDistance.MinDistance  = 0;

    //安全区参数恢复
    for(i=0; i<AXIS_NUM; i++)
    {
        GP->Robot_Safe_Area[i].SafeArea_Switch = 0;
        GP->Robot_Safe_Area[i].X_Left = 0;
        GP->Robot_Safe_Area[i].Z_Left = 0;
        GP->Robot_Safe_Area[i].X_Right = 0;
        GP->Robot_Safe_Area[i].Z_Right = 0;
    }

    //物联网设定参数恢复
    GP->Internet_Parameter.Switch = 0;
    GP->f_SendInternetPara();

    //机械手设定参数恢复
    GP->JXS_Parameter.Axis = 0;
    GP->JXS_Parameter.Origin = 0;
    GP->JXS_Parameter.SpeedLevel = 80;		//速度等级默认为80%
    GP->JXS_Parameter.Outport_Pause = 0;
    GP->JXS_Parameter.Outport_Run = 0;
    GP->JXS_Parameter.Outport_Stop = 0;
    GP->JXS_Parameter.Outport_Orign = 0;
    GP->JXS_Parameter.LCcirculation = 0;
    GP->JXS_Parameter.AlarmSignal = 0;

    for(i=0; i<AXIS_NUM; i++)
    {
        GP->JXS_Parameter.Alarm_Switch[i] = 1;
    }

    GP->JXS_Parameter.MDgripSwitch = 0;
    for(i=0; i<MDgrip_Num; i++)
    {
        GP->JXS_Parameter.MDgripPort[i] = 0;
    }

    GP->JXS_Parameter.OutputAssociate[0] = 0;
    GP->JXS_Parameter.OutputAssociate[1] = 0;

    GP->JXS_Parameter.ZAxsisAvoidace = 0;
    GP->JXS_Parameter.ZAxsisLimit = 0;

    GP->f_SendSystemPara();
    GP->g_Reflash_Speed = TRUE;

    //原点参数设置参数恢复
    for(i=0; i<AXIS_NUM; i++)
    {
        GP->JXS_Parameter.OriginPosition[i] = 0;
        GP->JXS_Parameter.OriginSpeed[i] = 5;
        GP->JXS_Parameter.OriginOffset[i] = 0;
        GP->JXS_Parameter.OriginDiretion[i] = 0;
        GP->JXS_Parameter.A_Circle_Pulse[i] = 10000;
        GP->JXS_Parameter.A_Circle_Distance[i] = 100000;
        GP->JXS_Parameter.Accelerate.Time[i] = 200;
        GP->JXS_Parameter.AccAcc[i] = 20;
        GP->JXS_Parameter.JDZ_AllowError[i] = 1000;
    }

    //笛卡尔坐标系参数恢复
    GP->sCartesian_Para.length[0] = 0;
    GP->sCartesian_Para.length[1] = 0;
    GP->sCartesian_Para.maxSpeed = 500;
    GP->sCartesian_Para.accTime = 200;
    GP->sCartesian_Para.accAcc = 20;
    GP->sCartesian_Para.carCoordSwitch = 0;
    GP->sCartesian_Para.MDCoordType = 0;
    for(i=0; i<AXIS_NUM; i++)
    {//默认旋转轴
        GP->sCartesian_Para.axisType[i] = 1;
    }
    GP->sCartesian_Para.axisType[Z_AXIS] = 0;		//Z轴默认直线轴
    GP->sCartesian_Para.pitchLength = 0;
    for(i=0; i<AXIS_NUM; i++)
    {
        GP->sCartesian_Para.axisBackMinDir[i] = 0;
        GP->sCartesian_Para.axisInterpFlag[i] = 1;		//默认支持插补
    }
    GP->f_send_Cartesian();

    //码垛参数恢复
    GP->sMD_Parameter.teachLayer = 1;

    //生产参数设定参数恢复
    GP->SC_Parameter.RW_Num = 0;
    GP->SC_Parameter.CJ_Num = 0;
    GP->SC_Parameter.JG_Num = 0;
    GP->SC_Parameter.SC_Num = 0;
    GP->SC_Parameter.LJ_Num = 0;
    GP->SC_Parameter.NG_Num = 0;
    GP->sMD_RunPara.mdMethed = 0;
    GP->sMD_RunPara.totalGood = 1;
    GP->sMD_RunPara.startGood = 1;
    GP->sMD_RunPara.curGood = 1;
    GP->sMD_RunPara.curLayer = 1;
    GP->sMD_RunPara.curNum = 1;
    GP->f_Send_SCPara();
    GP->g_Reflash_Progress_Num = TRUE;
    GP->sMD_RunPara.startName.Name = 0x4D443031;
    GP->sMD_RunPara.startName.Name1 = 0;
    GP->sMD_RunPara.startName.Name2 = 0;
    GP->sMD_RunPara.curName.Name = 0x4D443031;
    GP->sMD_RunPara.curName.Name1 = 0;
    GP->sMD_RunPara.curName.Name2 = 0;

    //配方参数恢复
    for(i=0; i<PF_IONUM; i++)
    {
        GP->PF_Parameter.pfIOnum[i]= i;
        GP->PF_Parameter.pfGood[i]= i + 1;
        GP->PF_Parameter.pfSwitch[i]= 0;
    }
    GP->f_Send_PFPara();

    //用户变量恢复
    for(i=0; i<USER_NUM; i++)
    {
        GP->USER_Parameter.USER_Name1[i] = 0x75736572;
        GP->USER_Parameter.USER_Name2[i] = 0x30200000+ ((u32)(i + 1) << 24);
        GP->USER_Parameter.USER_Name3[i] = 0;
        GP->USER_Parameter.INIT_Num[i] = 0;
        GP->USER_Parameter.CURR_Num[i] = GP->USER_Parameter.INIT_Num[i];
        GP->USER_Parameter.ELEC_RESET[i]  = 1;
        GP->USER_Parameter.START_RESET[i] = 1;
    }
    GP->gs_Reflash_Save_USER = TRUE;

    //绝对值参数恢复
    GP->JDZ_Parameter.Switch = 0;
    GP->JDZ_Parameter.Server = 0;
    GP->JDZ_Parameter.Resolu = 0;

    for(i=0; i<AXIS_NUM; i++)
    {
        GP->JDZ_Parameter.Circle_Pluse[i] = 10000;
        GP->JDZ_Parameter.Motion_Dir[i] = 0;
        GP->JDZ_Parameter.OriginSetting[i] = 0;
    }
    GP->gs_Reflash_Fuction_JDZ = TRUE;

    //X18-X29当作特殊io参数恢复
    for(i=0; i<INPUT_NUM; i++)
    {
        if(i < Input_Special)
        {
            GP->Temp_IO_Switch_Parameter[i] = 0;
        }
        else
        {
            GP->Temp_IO_Switch_Parameter[i] = 1;
        }
    }

    //输入输出名字参数恢复//输入IO设定参数恢复
    for(i=0,j=0; i<INPUT_NUM; i++,j=j+12)
    {
        if(i < 10)
        {
            GP->IO_Name_Parameter_Input[i].Name  = ('X'<<24)|((0x30+i)<<16)|0x0000;
            GP->IO_Name_Parameter_Input[i].Name1 = 0x0;
            GP->IO_Name_Parameter_Input[i].Name2 = 0x0;
        }
        else if(i < 18)
        {
            GP->IO_Name_Parameter_Input[i].Name  = ('X'<<24)|(0x31<<16)|((0x30+(i-10))<<8)|0x00;
            GP->IO_Name_Parameter_Input[i].Name1 = 0x0;
            GP->IO_Name_Parameter_Input[i].Name2 = 0x0;
        }
        else if(i == 18)	//X轴最小限位
        {
            GP->IO_Name_Parameter_Input[i].Name  = 0x5820D6E1;
            GP->IO_Name_Parameter_Input[i].Name1 = 0xD7EED0A1;
            GP->IO_Name_Parameter_Input[i].Name2 = 0xCFDECEBB;
        }
        else if(i == 19)	//Y轴最小限位
        {
            GP->IO_Name_Parameter_Input[i].Name  = 0x5920D6E1;
            GP->IO_Name_Parameter_Input[i].Name1 = 0xD7EED0A1;
            GP->IO_Name_Parameter_Input[i].Name2 = 0xCFDECEBB;
        }
        else if(i == 20)	//Z轴最小限位
        {
            GP->IO_Name_Parameter_Input[i].Name  = 0x5A20D6E1;
            GP->IO_Name_Parameter_Input[i].Name1 = 0xD7EED0A1;
            GP->IO_Name_Parameter_Input[i].Name2 = 0xCFDECEBB;
        }
        else if(i == 21)	//O轴最小限位
        {
            GP->IO_Name_Parameter_Input[i].Name  = 0x4F20D6E1;
            GP->IO_Name_Parameter_Input[i].Name1 = 0xD7EED0A1;
            GP->IO_Name_Parameter_Input[i].Name2 = 0xCFDECEBB;
        }
        else if(i == 22)	//X轴最大限位
        {
            GP->IO_Name_Parameter_Input[i].Name  = 0x5820D6E1;
            GP->IO_Name_Parameter_Input[i].Name1 = 0xD7EEB4F3;
            GP->IO_Name_Parameter_Input[i].Name2 = 0xCFDECEBB;
        }
        else if(i == 23)	//Y轴最大限位
        {
            GP->IO_Name_Parameter_Input[i].Name  = 0x5920D6E1;
            GP->IO_Name_Parameter_Input[i].Name1 = 0xD7EEB4F3;
            GP->IO_Name_Parameter_Input[i].Name2 = 0xCFDECEBB;
        }
        else if(i == 24)	//Z轴最大限位
        {
            GP->IO_Name_Parameter_Input[i].Name  = 0x5A20D6E1;
            GP->IO_Name_Parameter_Input[i].Name1 = 0xD7EEB4F3;
            GP->IO_Name_Parameter_Input[i].Name2 = 0xCFDECEBB;
        }
        else if(i == 25)	//O轴最大限位
        {
            GP->IO_Name_Parameter_Input[i].Name  = 0x4F20D6E1;
            GP->IO_Name_Parameter_Input[i].Name1 = 0xD7EEB4F3;
            GP->IO_Name_Parameter_Input[i].Name2 = 0xCFDECEBB;
        }
        else if(i == 26)	//X轴原点
        {
            GP->IO_Name_Parameter_Input[i].Name  = 0x5820D6E1;
            GP->IO_Name_Parameter_Input[i].Name1 = 0xD4ADB5E3;
            GP->IO_Name_Parameter_Input[i].Name2 = 0x0;
        }
        else if(i == 27)	//Y轴原点
        {
            GP->IO_Name_Parameter_Input[i].Name  = 0x5920D6E1;
            GP->IO_Name_Parameter_Input[i].Name1 = 0xD4ADB5E3;
            GP->IO_Name_Parameter_Input[i].Name2 = 0x0;
        }
        else if(i == 28)    //Z轴原点
        {
            GP->IO_Name_Parameter_Input[i].Name  = 0x5A20D6E1;
            GP->IO_Name_Parameter_Input[i].Name1 = 0xD4ADB5E3;
            GP->IO_Name_Parameter_Input[i].Name2 = 0x0;
        }
        else if(i == 29)	//O轴原点
        {
            GP->IO_Name_Parameter_Input[i].Name  = 0x4F20D6E1;
            GP->IO_Name_Parameter_Input[i].Name1 = 0xD4ADB5E3;
            GP->IO_Name_Parameter_Input[i].Name2 = 0x0;
        }

        GP->IOName_To_FreeIO(GP->IO_Name_Parameter_Input[i],&Temp_Free_Input_Name);
        GP->Parameter_StringChang(Program_String[i+PROGRAM_STRING_INPUT_OFFSET], 0,
                Temp_Free_Input_Name.Name, Temp_Free_Input_Name.Name1, Temp_Free_Input_Name.Name2);
        Program_String[i+PROGRAM_STRING_INPUT_OFFSET][12] = 0xBC;
        Program_String[i+PROGRAM_STRING_INPUT_OFFSET][13] = 0xEC;
        Program_String[i+PROGRAM_STRING_INPUT_OFFSET][14] = 0xB2;
        Program_String[i+PROGRAM_STRING_INPUT_OFFSET][15] = 0xE2;

        GP->Parameter_StringChang(Alarm_String[i+ALARM_STRING_INPUT_OFFSET], 0,
                Temp_Free_Input_Name.Name, Temp_Free_Input_Name.Name1, Temp_Free_Input_Name.Name2);
        Alarm_String[i+ALARM_STRING_INPUT_OFFSET][12] = 0xBC;
        Alarm_String[i+ALARM_STRING_INPUT_OFFSET][13] = 0xEC;
        Alarm_String[i+ALARM_STRING_INPUT_OFFSET][14] = 0xB2;
        Alarm_String[i+ALARM_STRING_INPUT_OFFSET][15] = 0xE2;
        Alarm_String[i+ALARM_STRING_INPUT_OFFSET][16] = 0xD2;
        Alarm_String[i+ALARM_STRING_INPUT_OFFSET][17] = 0xEC;
        Alarm_String[i+ALARM_STRING_INPUT_OFFSET][18] = 0xB3;
        Alarm_String[i+ALARM_STRING_INPUT_OFFSET][19] = 0xA3;

        GP->IO_Parameter[i].minTime = 0;
        GP->IO_Parameter[i].maxTime = 0;
        GP->IO_Parameter[i].Switch = 0;
    }

    //Y22-Y23当作特殊io参数恢复
    for(i=0; i<OUTPUT_NUM; i++)
    {
        if(i == 22 || i == 23)
        {
            GP->Temp_OUT_Switch_Parameter[i] = 1;
        }
        else
        {
            GP->Temp_OUT_Switch_Parameter[i] = 0;
        }
    }

    for(i=0,j=0; i<OUTPUT_NUM; i++,j=j+12)
    {
        if(i < 10)
        {
            GP->IO_Name_Parameter[i].Name =('Y'<<24)|((0x30+i)<<16)|0x0000;
            GP->IO_Name_Parameter[i].Name1=0x0;
            GP->IO_Name_Parameter[i].Name2 =0x0;
        }
        else if(i < 20)
        {
            GP->IO_Name_Parameter[i].Name =('Y'<<24)|(0x31<<16)|((0x30+(i-10))<<8)|0x00;
            GP->IO_Name_Parameter[i].Name1=0x0;
            GP->IO_Name_Parameter[i].Name2 =0x0;
        }
        else if(i < 22)
        {
            GP->IO_Name_Parameter[i].Name =('Y'<<24)|(0x32<<16)|((0x30+(i-20))<<8)|0x0;
            GP->IO_Name_Parameter[i].Name1=0x0;
            GP->IO_Name_Parameter[i].Name2 =0x0;
        }
        else if(i == 22)	//原点状态
        {
            GP->IO_Name_Parameter[i].Name  = 0xD4ADB5E3;
            GP->IO_Name_Parameter[i].Name1 = 0xD7B4CCAC;
            GP->IO_Name_Parameter[i].Name2 = 0x0;
        }
        else if(i == 23)	//复位状态
        {
            GP->IO_Name_Parameter[i].Name  = 0xB8B4CEBB;
            GP->IO_Name_Parameter[i].Name1 = 0xD7B4CCAC;
            GP->IO_Name_Parameter[i].Name2 = 0x0;
        }
        else if(i == 24)	//运行灯
        {
            GP->IO_Name_Parameter[i].Name  = 0xD4CBD0D0;
            GP->IO_Name_Parameter[i].Name1 = 0xB5C60000;
            GP->IO_Name_Parameter[i].Name2 = 0x0;
        }
        else if(i == 25)	//待机灯
        {
            GP->IO_Name_Parameter[i].Name  = 0xB4FDBBFA;
            GP->IO_Name_Parameter[i].Name1 = 0xB5C60000;
            GP->IO_Name_Parameter[i].Name2 = 0x0;
        }
        else if(i == 26)	//报警灯
        {
            GP->IO_Name_Parameter[i].Name  = 0xB1A8BEAF;
            GP->IO_Name_Parameter[i].Name1 = 0xB5C60000;
            GP->IO_Name_Parameter[i].Name2 = 0x0;
        }
        else if(i == 27)	//蜂鸣器
        {
            GP->IO_Name_Parameter[i].Name  = 0xB7E4C3F9;
            GP->IO_Name_Parameter[i].Name1 = 0xC6F70000;
            GP->IO_Name_Parameter[i].Name2 = 0x0;
        }
        else if(i == 28)	//RY0
        {
            GP->IO_Name_Parameter[i].Name  = 0x52593000;
            GP->IO_Name_Parameter[i].Name1 = 0x0;
            GP->IO_Name_Parameter[i].Name2 = 0x0;
        }
        else if(i == 29)	//RY1
        {
            GP->IO_Name_Parameter[i].Name  = 0x52593100;
            GP->IO_Name_Parameter[i].Name1 = 0x0;
            GP->IO_Name_Parameter[i].Name2 = 0x0;
        }
        GP->IOName_To_FreeIO(GP->IO_Name_Parameter[i],&Temp_Free_Output_Name);

        if(i < OUTPUT_NUM - 6)
        {//普通输出(不包括三色灯、蜂鸣器、继电器输出)
            GP->Parameter_StringChang(Program_String[i*2+PROGRAM_STRING_OUTPUT_SET_OFFSET], 0,
                    Temp_Free_Output_Name.Name, Temp_Free_Output_Name.Name1, Temp_Free_Output_Name.Name2);
            Program_String[i*2+PROGRAM_STRING_OUTPUT_SET_OFFSET][12] = 0xD6;
            Program_String[i*2+PROGRAM_STRING_OUTPUT_SET_OFFSET][13] = 0xC3;
            Program_String[i*2+PROGRAM_STRING_OUTPUT_SET_OFFSET][14] = 0xCE;
            Program_String[i*2+PROGRAM_STRING_OUTPUT_SET_OFFSET][15] = 0xBB;

            GP->Parameter_StringChang(Program_String[i*2+PROGRAM_STRING_OUTPUT_RESET_OFFSET], 0,
                    Temp_Free_Output_Name.Name, Temp_Free_Output_Name.Name1, Temp_Free_Output_Name.Name2);
            Program_String[i*2+PROGRAM_STRING_OUTPUT_RESET_OFFSET][12] = 0xB8;
            Program_String[i*2+PROGRAM_STRING_OUTPUT_RESET_OFFSET][13] = 0xB4;
            Program_String[i*2+PROGRAM_STRING_OUTPUT_RESET_OFFSET][14] = 0xCE;
            Program_String[i*2+PROGRAM_STRING_OUTPUT_RESET_OFFSET][15] = 0xBB;
        }
        else if(i >= OUTPUT_NUM - 2)
        {//继电器输出
            GP->Parameter_StringChang(Program_String[i*2+PROGRAM_STRING_REGOUTPUT_SET_OFFSET], 0,
                    Temp_Free_Output_Name.Name, Temp_Free_Output_Name.Name1, Temp_Free_Output_Name.Name2);
            Program_String[i*2+PROGRAM_STRING_REGOUTPUT_SET_OFFSET][12] = 0xD6;
            Program_String[i*2+PROGRAM_STRING_REGOUTPUT_SET_OFFSET][13] = 0xC3;
            Program_String[i*2+PROGRAM_STRING_REGOUTPUT_SET_OFFSET][14] = 0xCE;
            Program_String[i*2+PROGRAM_STRING_REGOUTPUT_SET_OFFSET][15] = 0xBB;

            GP->Parameter_StringChang(Program_String[i*2+PROGRAM_STRING_REGOUTPUT_RESET_OFFSET], 0,
                    Temp_Free_Output_Name.Name, Temp_Free_Output_Name.Name1, Temp_Free_Output_Name.Name2);
            Program_String[i*2+PROGRAM_STRING_REGOUTPUT_RESET_OFFSET][12] = 0xB8;
            Program_String[i*2+PROGRAM_STRING_REGOUTPUT_RESET_OFFSET][13] = 0xB4;
            Program_String[i*2+PROGRAM_STRING_REGOUTPUT_RESET_OFFSET][14] = 0xCE;
            Program_String[i*2+PROGRAM_STRING_REGOUTPUT_RESET_OFFSET][15] = 0xBB;
        }

        if((i<24)||(i>27))   //输出IO复位选择设定参数恢复
        {// Y0-Y23 RY0 RY1
            GP->IO_Reset_Select[i].BeforeOrigin = 0;
            GP->IO_Reset_Select[i].AfterOrigin = 0;
            GP->IO_Reset_Select[i].CommonAlarm = 0;
            GP->IO_Reset_Select[i].EmergeAlarm = 0;
            GP->IO_Reset_Select[i].Pause = 0;
            GP->IO_Reset_Select[i].Stop = 0;
        }
    }

    //点恢复出厂设置
    for(i=0; i<40; i++)
    {//保存点删除
        if(GP->Manul_Save_Point[i].Flag)
        {
            GP->Manul_Save_Point[i].Flag  = 0;
            GP->Manul_Save_Point[i].Name  = 0;
            GP->Manul_Save_Point[i].Name2 = 0;
            GP->Manul_Save_Point[i].Name3 = 0;
            GP->Manul_Save_Point[i].Point[X_AXIS] = 0;
            GP->Manul_Save_Point[i].Point[L_AXIS] = 0;
            GP->Manul_Save_Point[i].Point[Z_AXIS] = 0;
            GP->Manul_Save_Point[i].Point[O_AXIS] = 0;
        }
    }

    //程序恢复出厂设置
    for(i=0; i<SAVEPROGRAMNUM; i++)
    {
        if(i == SAVEPROGRAMNUM_MAIN-1)
        {
            GP->Free_Program_Save[i].Flag = 1;
            GP->Free_Program_Save[i].Name = 0xB8B4CEBB;
            GP->Free_Program_Save[i].Name2 = 0xB3CCD0F2;
            GP->Free_Program_Save[i].Name3 = 0;
            GP->Free_Program_Save[i].Num = 2;
        }
        else
        {
            GP->Free_Program_Save[i].Flag = 0;
            GP->Free_Program_Save[i].Name = 0;
            GP->Free_Program_Save[i].Name2 = 0;
            GP->Free_Program_Save[i].Name3 = 0;
            GP->Free_Program_Save[i].Num = 0;
        }

        if(GP->g_Run_Program_Num == i)
        {//删除程序正是在运行的程序
            GP->g_Run_Program_Num = 0;
            GP->g_Current_Program_Debug = FALSE;
            GP->Free_Program_Operate.Flag = 0;
            GP->Free_Program_Operate.Code = 0;
            GP->Free_Program_Operate.Name = 0;
            GP->Free_Program_Operate.Name2 = 0;
            GP->Free_Program_Operate.Name3 = 0;
            GP->Free_Program_Operate.Num  = 0;
            for(j=0; j<LARGESTPROGRAMNUM; j++)
            {
                GP->Free_Program_Operate.Program[j].Flag  = 0;
                GP->Free_Program_Operate.Program[j].List  = 0;
                GP->Free_Program_Operate.Program[j].Order = 0;
                GP->Free_Program_Operate.Program[j].Key   = 0;
                GP->Free_Program_Operate.Program[j].Value1= 0;
                GP->Free_Program_Operate.Program[j].Value2= 0;
                GP->Free_Program_Operate.Program[j].Value3= 0;
            }
        }
    }

    GP->Free_Program_Operate.Flag = 1;
    GP->Free_Program_Operate.Code = SAVEPROGRAMNUM_MAIN;
    GP->Free_Program_Operate.Name  = GP->Free_Program_Save[SAVEPROGRAMNUM_MAIN-1].Name;
    GP->Free_Program_Operate.Name2 = GP->Free_Program_Save[SAVEPROGRAMNUM_MAIN-1].Name2;
    GP->Free_Program_Operate.Name3 = GP->Free_Program_Save[SAVEPROGRAMNUM_MAIN-1].Name3;
    GP->Free_Program_Operate.Num   = GP->Free_Program_Save[SAVEPROGRAMNUM_MAIN-1].Num;	  //当前模组程序条数
    for(i=0; i<GP->Free_Program_Operate.Num; i++)
    {
        GP->Free_Program_Operate.Program[i].Flag   = 1;
        GP->Free_Program_Operate.Program[i].List   = i + 1;
        GP->Free_Program_Operate.Program[i].Order  = OR_BASICORDER;
        GP->Free_Program_Operate.Program[i].Key    = K_PROGRAMSTART + i;
        GP->Free_Program_Operate.Program[i].Value1 = V_BLANK;
        GP->Free_Program_Operate.Program[i].Value2 = V_BLANK;
        GP->Free_Program_Operate.Program[i].Value3 = V_BLANK;
    }
    GP->Free_Program_Operate.Code=GP->Free_Program_Save[SAVEPROGRAMNUM_MAIN-1].Code;
    //发送当前保存的程序到控制板
    GP->g_USART1_SendProgram_Flag=TRUE;
//    USART1_SendProgram(Free_Program_Operate.Num,&Free_Program_Operate);
    GP->g_USART1_SendProgram_Flag=FALSE;
    GP->g_Current_Program_Debug=TRUE;
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

void UserSet::on_Btn_clockSetOk_clicked()
{
    ui->stackedWidget->setCurrentIndex(UserSet_id);
    clockSetShow();
}

void UserSet::on_Btn_buzzer_clicked()
{
    bBee = !bBee;
    if(bBee)
    {
        ui->Btn_buzzer->setText("开");
        mBeeper->beep();
        mBeeper->saveBeeTime(100);
    }
    else
    {
        ui->Btn_buzzer->setText("关");
        mBeeper->beep();
        mBeeper->saveBeeTime(0);
    }
}

//用户设置--密码显示刷新
void UserSet::Pass_Word_Refresh(u8 flag)
{
    if(flag)
    {
        ui->Btn_modPassword->setText(gs_Pass_Word_String);
        ui->Btn_encryptionSet->setText(gs_Pass_Word_String);
        ui->Btn_adminAuthority->setText(Admin_Authority_Dis[GP->Change_User_Password]);
        ui->Edit_oldPassword->clear();
        ui->Edit_newPassword->clear();
        ui->Edit_renewPassword->clear();
        flag = FALSE;
    }
}





