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
        if(GP->Robot_Status == ACTION_STOP)
        {
            GP->SC_Parameter.RW_Num = ui->Edit_task->text().toUInt();
            GP->f_Send_SCPara();
        }
    });

    //功能设定--生产-抽检产品
    connect(ui->Edit_samplingProd, &QLineEdit::editingFinished, this, [=](){
        if(GP->Robot_Status == ACTION_STOP)
        {
            GP->SC_Parameter.CJ_Num = ui->Edit_samplingProd->text().toUInt();
            GP->f_Send_SCPara();
        }
    });

    //功能设定--生产-抽检间隔
    connect(ui->Edit_samplingInterval, &QLineEdit::editingFinished, this, [=](){
        if(GP->Robot_Status == ACTION_STOP)
        {
            GP->SC_Parameter.JG_Num = ui->Edit_samplingInterval->text().toUInt();
            GP->f_Send_SCPara();
        }
    });

    //功能设定--生产-当前加工数量
    connect(ui->Edit_curProcess, &QLineEdit::editingFinished, this, [=](){
        if(GP->Robot_Status == ACTION_STOP)
        {
            if(ui->Edit_curProcess->text().toUInt() <= GP->SC_Parameter.RW_Num)
            {
                GP->SC_Parameter.SC_Num = ui->Edit_curProcess->text().toUInt();
            }
            else
            {
                GP->SC_Parameter.SC_Num = GP->SC_Parameter.RW_Num;
            }
            GP->f_Send_SCPara();
        }
    });

    //功能设定--生产-累计数量-清除
    connect(ui->Btn_totalProcessClr, &QPushButton::clicked, this, [=](){
        if(GP->Robot_Status == ACTION_STOP)
        {
            GP->SC_Parameter.LJ_Num = 0;
            ui->label_totalProcess->setText(QString::number(GP->SC_Parameter.LJ_Num));
            GP->f_Send_SCPara();
        }
    });

    //功能设定--生产-完成数量-清除
    connect(ui->Btn_curProcessClr, &QPushButton::clicked, this, [=](){
        if(GP->Robot_Status == ACTION_STOP)
        {
            GP->SC_Parameter.SC_Num = 0;
            ui->Edit_curProcess->setText(QString::number(GP->SC_Parameter.SC_Num));
            GP->f_Send_SCPara();
        }
    });

    //功能设定--生产-NG数量-清除
    connect(ui->Btn_NGprodClr, &QPushButton::clicked, this, [=](){
        if(GP->Robot_Status == ACTION_STOP)
        {
            GP->SC_Parameter.NG_Num = 0;
            ui->label_NGprod->setText(QString::number(GP->SC_Parameter.NG_Num));
            GP->f_Send_SCPara();
        }
    });

    //功能设定--生产-总物品数
    connect(ui->Edit_totalNum, &QLineEdit::editingFinished, this, [=](){
        if(GP->Robot_Status == ACTION_STOP)
        {
            GP->sMD_RunPara.totalGood = static_cast<u8>(ui->Edit_samplingInterval->text().toUInt());
            GP->f_Send_SCPara();
        }
    });

    //功能设定--生产-起始物品
    connect(ui->Btn_startItem, &QPushButton::clicked, this, [=](){
        if(GP->Robot_Status == ACTION_STOP)
        {
            pWidget->ui->stackedWidget_main->setCurrentIndex(SubManual_id);
            pWidget->ui->stackedWidget_subManual->setCurrentWidget(pWidget->Stacking_ui);
            GP->m_MD_Good_Page = 1;
//            MD_NameGet(1);
            GP->m_Reflash_Name_MD = TRUE;
            GP->m_Choose_Good_Mode = 1;
        }
    });

    //功能设定--生产-当前物品
    connect(ui->Btn_startItem, &QPushButton::clicked, this, [=](){
        if(GP->Robot_Status == ACTION_STOP)
        {
            GP->m_Choose_Good_Mode = 2;
            GP->m_MD_Good_Page = 1;
//            MD_NameGet(1);
            pWidget->stackingPage();
        }
    });

    //功能设定--生产-当前层数
    connect(ui->Edit_curLayerNum, &QLineEdit::editingFinished, this, [=](){
        if(GP->Robot_Status == ACTION_STOP)
        {
            if(ui->Edit_curLayerNum->text().toInt() > 0)
            {
                GP->sMD_RunPara.curLayer = static_cast<u8>(ui->Edit_curLayerNum->text().toUInt());
            }
            GP->f_Send_SCPara();
        }
    });

    //功能设定--生产-当前个数
    connect(ui->Edit_curNum, &QLineEdit::editingFinished, this, [=](){
        if(GP->Robot_Status == ACTION_STOP)
        {
            if(ui->Edit_curNum->text().toInt() > 0)
            {
                GP->sMD_RunPara.curNum = static_cast<u8>(ui->Edit_curNum->text().toUInt());
            }
            GP->f_Send_SCPara();
        }
    });

    //当前物品--生产--当前物品--重置
    connect(ui->Btn_curItemRst, &QPushButton::clicked, this, [=](){
        if(GP->Robot_Status == ACTION_STOP)
        {
            GP->sMD_RunPara.curGood = GP->sMD_RunPara.startGood;
//            Order_Temp[0] = MD_CURLAYER_CURNUM;  						//查询机当前物品的当前层和当前个数
//            Order_Temp[1] = sMD_RunPara.curGood;  						//当前物品号
//            USART1_SendData(2, WATCH_COMMAND, &Order_Temp[0]);
            GP->f_Send_SCPara();
            GP->m_Reflash_Run_MD = TRUE;
//            Order_Temp[0] = AUTO_PARAMETER;
//            USART1_SendData(1,WATCH_COMMAND,&Order_Temp[0]);

//            f_MDParaGet(sMD_RunPara.curGood);
            if(GP->sMD_Parameter.property == 1)
            {//拆垛
                GP->sMD_RunPara.curLayer = GP->sMD_Parameter.stackLayer;
            }
            else
            {//码垛
                GP->sMD_RunPara.curLayer = 1;
            }
            GP->sMD_RunPara.curLayer = static_cast<u8>(ui->Edit_curLayerNum->text().toUInt());
            GP->f_Send_SCPara();

//            f_MDParaGet(sMD_RunPara.curGood);
            if(GP->sMD_Parameter.property == 1)
            {//拆垛
                if(GP->sMD_Parameter.topSwitch == 1 && GP->sMD_Parameter.loopLayer < LOOP_MAX)
                {//顶层功能开启
                    GP->sMD_RunPara.curNum = GP->sMD_Parameter.layerNum[LOOP_MAX - 1];
                }
                else
                {
                    int i = GP->sMD_Parameter.stackLayer - GP->sMD_Parameter.stackLayer / GP->sMD_Parameter.loopLayer * GP->sMD_Parameter.loopLayer;
                    if(i == 0)
                    {
                        i = GP->sMD_Parameter.loopLayer;
                    }
                    GP->sMD_RunPara.curNum = GP->sMD_Parameter.layerNum[i - 1];
                }
            }
            else
            {//码垛
                GP->sMD_RunPara.curNum = 1;
            }
            GP->sMD_RunPara.curNum = static_cast<u8>(ui->Edit_curNum->text().toUInt());
            GP->f_Send_SCPara();
        }
    });

    //功能设定--生产--当前层数--重置
    connect(ui->Btn_curLayerNumRst, &QPushButton::clicked, this, [=](){
        if(GP->Robot_Status == ACTION_STOP)
        {
//            f_MDParaGet(sMD_RunPara.curGood);
            if(GP->sMD_Parameter.property == 1)
            {//拆垛
                GP->sMD_RunPara.curLayer = GP->sMD_Parameter.stackLayer;
            }
            else
            {//码垛
                GP->sMD_RunPara.curLayer = 1;
            }
            GP->sMD_RunPara.curLayer = static_cast<u8>(ui->Edit_curLayerNum->text().toUInt());
            GP->f_Send_SCPara();
        }
    });

    //功能设定--生产--当前个数--重置
    connect(ui->Btn_curLayerNumRst, &QPushButton::clicked, this, [=](){
        if(GP->Robot_Status == ACTION_STOP)
        {
//            f_MDParaGet(sMD_RunPara.curGood);
            if(GP->sMD_Parameter.property == 1)
            {//拆垛
                if(GP->sMD_Parameter.topSwitch == 1 && GP->sMD_Parameter.loopLayer < LOOP_MAX)
                {//顶层功能开启
                    GP->sMD_RunPara.curNum = GP->sMD_Parameter.layerNum[LOOP_MAX - 1];
                }
                else
                {
                    int i = GP->sMD_Parameter.stackLayer - GP->sMD_Parameter.stackLayer / GP->sMD_Parameter.loopLayer * GP->sMD_Parameter.loopLayer;
                    if(i == 0)
                    {
                        i = GP->sMD_Parameter.loopLayer;
                    }
                    GP->sMD_RunPara.curNum = GP->sMD_Parameter.layerNum[i - 1];
                }
            }
            else
            {//码垛
                GP->sMD_RunPara.curNum = 1;
            }
            GP->sMD_RunPara.curNum = static_cast<u8>(ui->Edit_curNum->text().toUInt());
            GP->f_Send_SCPara();
        }
    });
}

ProdPara::~ProdPara()
{
    delete ui;
}
