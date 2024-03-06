#include "prodpara.h"
#include "ui_prodpara.h"
#include "mainWidget.h"
#include "ui_mainWidget.h"

ProdPara::ProdPara(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProdPara)
{
    ui->setupUi(this);

    pWidget = static_cast<Widget*>(parent);

    //返回运行界面
    connect(ui->Btn_back, &QPushButton::clicked, this, [=](){
        pWidget->backRunPage();
    });

    //功能设定--生产-加工任务
    connect(ui->Edit_task, &QLineEdit::editingFinished, this, [=](){
        if(Global::Robot_Status == ACTION_STOP)
        {
            Global::SC_Parameter.RW_Num = ui->Edit_task->text().toUInt();
            Global::f_Send_SCPara();
        }
    });

    //功能设定--生产-抽检产品
    connect(ui->Edit_samplingProd, &QLineEdit::editingFinished, this, [=](){
        if(Global::Robot_Status == ACTION_STOP)
        {
            Global::SC_Parameter.CJ_Num = ui->Edit_samplingProd->text().toUInt();
            Global::f_Send_SCPara();
        }
    });

    //功能设定--生产-抽检间隔
    connect(ui->Edit_samplingInterval, &QLineEdit::editingFinished, this, [=](){
        if(Global::Robot_Status == ACTION_STOP)
        {
            Global::SC_Parameter.JG_Num = ui->Edit_samplingInterval->text().toUInt();
            Global::f_Send_SCPara();
        }
    });

    //功能设定--生产-当前加工数量
    connect(ui->Edit_curProcess, &QLineEdit::editingFinished, this, [=](){
        if(Global::Robot_Status == ACTION_STOP)
        {
            if(ui->Edit_curProcess->text().toUInt() <= Global::SC_Parameter.RW_Num)
            {
                Global::SC_Parameter.SC_Num = ui->Edit_curProcess->text().toUInt();
            }
            else
            {
                Global::SC_Parameter.SC_Num = Global::SC_Parameter.RW_Num;
            }
            Global::f_Send_SCPara();
        }
    });

    //功能设定--生产-累计数量-清除
    connect(ui->Btn_totalProcessClr, &QPushButton::clicked, this, [=](){
        if(Global::Robot_Status == ACTION_STOP)
        {
            Global::SC_Parameter.LJ_Num = 0;
            ui->label_totalProcess->setText(QString::number(Global::SC_Parameter.LJ_Num));
            Global::f_Send_SCPara();
        }
    });

    //功能设定--生产-完成数量-清除
    connect(ui->Btn_curProcessClr, &QPushButton::clicked, this, [=](){
        if(Global::Robot_Status == ACTION_STOP)
        {
            Global::SC_Parameter.SC_Num = 0;
            ui->Edit_curProcess->setText(QString::number(Global::SC_Parameter.SC_Num));
            Global::f_Send_SCPara();
        }
    });

    //功能设定--生产-NG数量-清除
    connect(ui->Btn_NGprodClr, &QPushButton::clicked, this, [=](){
        if(Global::Robot_Status == ACTION_STOP)
        {
            Global::SC_Parameter.NG_Num = 0;
            ui->label_NGprod->setText(QString::number(Global::SC_Parameter.NG_Num));
            Global::f_Send_SCPara();
        }
    });

    //功能设定--生产-总物品数
    connect(ui->Edit_totalNum, &QLineEdit::editingFinished, this, [=](){
        if(Global::Robot_Status == ACTION_STOP)
        {
            Global::sMD_RunPara.totalGood = static_cast<u8>(ui->Edit_samplingInterval->text().toUInt());
            Global::f_Send_SCPara();
        }
    });

    //功能设定--生产-起始物品
    connect(ui->Btn_startItem, &QPushButton::clicked, this, [=](){
        if(Global::Robot_Status == ACTION_STOP)
        {
            pWidget->stackingPage();
            Global::m_MD_Good_Page = 1;
//            MD_NameGet(1);
            Global::m_Reflash_Name_MD = TRUE;
            Global::m_Choose_Good_Mode = 1;
        }
    });

    //功能设定--生产-当前物品
    connect(ui->Btn_startItem, &QPushButton::clicked, this, [=](){
        if(Global::Robot_Status == ACTION_STOP)
        {
            Global::m_Choose_Good_Mode = 2;
            Global::m_MD_Good_Page = 1;
//            MD_NameGet(1);
            pWidget->stackingPage();
        }
    });

    //功能设定--生产-当前层数
    connect(ui->Edit_curLayerNum, &QLineEdit::editingFinished, this, [=](){
        if(Global::Robot_Status == ACTION_STOP)
        {
            if(ui->Edit_curLayerNum->text().toInt() > 0)
            {
                Global::sMD_RunPara.curLayer = static_cast<u8>(ui->Edit_curLayerNum->text().toUInt());
            }
            Global::f_Send_SCPara();
        }
    });

    //功能设定--生产-当前个数
    connect(ui->Edit_curNum, &QLineEdit::editingFinished, this, [=](){
        if(Global::Robot_Status == ACTION_STOP)
        {
            if(ui->Edit_curNum->text().toInt() > 0)
            {
                Global::sMD_RunPara.curNum = static_cast<u8>(ui->Edit_curNum->text().toUInt());
            }
            Global::f_Send_SCPara();
        }
    });

    //当前物品--生产--当前物品--重置
    connect(ui->Btn_curItemRst, &QPushButton::clicked, this, [=](){
        if(Global::Robot_Status == ACTION_STOP)
        {
            Global::sMD_RunPara.curGood = Global::sMD_RunPara.startGood;
//            Order_Temp[0] = MD_CURLAYER_CURNUM;  						//查询机当前物品的当前层和当前个数
//            Order_Temp[1] = sMD_RunPara.curGood;  						//当前物品号
//            USART1_SendData(2, WATCH_COMMAND, &Order_Temp[0]);
            Global::f_Send_SCPara();
            Global::m_Reflash_Run_MD = TRUE;
//            Order_Temp[0] = AUTO_PARAMETER;
//            USART1_SendData(1,WATCH_COMMAND,&Order_Temp[0]);

//            f_MDParaGet(sMD_RunPara.curGood);
            if(Global::sMD_Parameter.property == 1)
            {//拆垛
                Global::sMD_RunPara.curLayer = Global::sMD_Parameter.stackLayer;
            }
            else
            {//码垛
                Global::sMD_RunPara.curLayer = 1;
            }
            Global::sMD_RunPara.curLayer = static_cast<u8>(ui->Edit_curLayerNum->text().toUInt());
            Global::f_Send_SCPara();

//            f_MDParaGet(sMD_RunPara.curGood);
            if(Global::sMD_Parameter.property == 1)
            {//拆垛
                if(Global::sMD_Parameter.topSwitch == 1 && Global::sMD_Parameter.loopLayer < LOOP_MAX)
                {//顶层功能开启
                    Global::sMD_RunPara.curNum = Global::sMD_Parameter.layerNum[LOOP_MAX - 1];
                }
                else
                {
                    int i = Global::sMD_Parameter.stackLayer - Global::sMD_Parameter.stackLayer / Global::sMD_Parameter.loopLayer * Global::sMD_Parameter.loopLayer;
                    if(i == 0)
                    {
                        i = Global::sMD_Parameter.loopLayer;
                    }
                    Global::sMD_RunPara.curNum = Global::sMD_Parameter.layerNum[i - 1];
                }
            }
            else
            {//码垛
                Global::sMD_RunPara.curNum = 1;
            }
            Global::sMD_RunPara.curNum = static_cast<u8>(ui->Edit_curNum->text().toUInt());
            Global::f_Send_SCPara();
        }
    });

    //功能设定--生产--当前层数--重置
    connect(ui->Btn_curLayerNumRst, &QPushButton::clicked, this, [=](){
        if(Global::Robot_Status == ACTION_STOP)
        {
//            f_MDParaGet(sMD_RunPara.curGood);
            if(Global::sMD_Parameter.property == 1)
            {//拆垛
                Global::sMD_RunPara.curLayer = Global::sMD_Parameter.stackLayer;
            }
            else
            {//码垛
                Global::sMD_RunPara.curLayer = 1;
            }
            Global::sMD_RunPara.curLayer = static_cast<u8>(ui->Edit_curLayerNum->text().toUInt());
            Global::f_Send_SCPara();
        }
    });

    //功能设定--生产--当前个数--重置
    connect(ui->Btn_curLayerNumRst, &QPushButton::clicked, this, [=](){
        if(Global::Robot_Status == ACTION_STOP)
        {
//            f_MDParaGet(sMD_RunPara.curGood);
            if(Global::sMD_Parameter.property == 1)
            {//拆垛
                if(Global::sMD_Parameter.topSwitch == 1 && Global::sMD_Parameter.loopLayer < LOOP_MAX)
                {//顶层功能开启
                    Global::sMD_RunPara.curNum = Global::sMD_Parameter.layerNum[LOOP_MAX - 1];
                }
                else
                {
                    int i = Global::sMD_Parameter.stackLayer - Global::sMD_Parameter.stackLayer / Global::sMD_Parameter.loopLayer * Global::sMD_Parameter.loopLayer;
                    if(i == 0)
                    {
                        i = Global::sMD_Parameter.loopLayer;
                    }
                    Global::sMD_RunPara.curNum = Global::sMD_Parameter.layerNum[i - 1];
                }
            }
            else
            {//码垛
                Global::sMD_RunPara.curNum = 1;
            }
            Global::sMD_RunPara.curNum = static_cast<u8>(ui->Edit_curNum->text().toUInt());
            Global::f_Send_SCPara();
        }
    });
}

ProdPara::~ProdPara()
{
    delete ui;
}

void ProdPara::Reflash_Run_MD()
{
    ui->Edit_totalNum->setText(QString::number(static_cast<int>(Global::sMD_RunPara.totalGood)));   //总物品数
    ui->Edit_curLayerNum->setText(QString::number(static_cast<int>(Global::sMD_RunPara.curLayer)));  //当前层数
    ui->Edit_curNum->setText(QString::number(static_cast<int>(Global::sMD_RunPara.curNum)));     //当前个数

    //起始物品
    if(Global::sMD_RunPara.startGood == 0)
    {
        ui->Btn_startItem->setText(ProgramCode_String[Global::sMD_RunPara.startGood] + BlankNon);  //序号+无
    }
    else
    {
        Global::Parameter_StringChang(Global::Temp_Display_Data1, 0, Global::sMD_RunPara.startName.Name,
                                  Global::sMD_RunPara.startName.Name1, Global::sMD_RunPara.startName.Name2);
        ui->Btn_startItem->setText(ProgramCode_String[Global::sMD_RunPara.startGood] + Global::u8toqstr(Global::Temp_Display_Data1, 12));//序号+名称
    }
    //当前物品
    if(Global::sMD_RunPara.curGood == 0)
    {
        ui->Btn_curItem->setText(ProgramCode_String[Global::sMD_RunPara.curGood] + BlankNon);
    }
    else
    {
        Global::Parameter_StringChang(Global::Temp_Display_Data1, 0, Global::sMD_RunPara.curName.Name,
                                  Global::sMD_RunPara.curName.Name1, Global::sMD_RunPara.curName.Name2);
        ui->Btn_curItem->setText(ProgramCode_String[Global::sMD_RunPara.curGood] + Global::u8toqstr(Global::Temp_Display_Data1, 12));
    }
}
