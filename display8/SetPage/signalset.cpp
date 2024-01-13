#include "signalset.h"
#include "ui_signalset.h"
#include "mainWidget.h"

SignalSet::SignalSet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignalSet)
{
    ui->setupUi(this);

    pWidget = static_cast<Widget*>(parent);

    init();

    //返回设置子界面
    connect(ui->Btn_back, &QPushButton::clicked, this, [=](){
        pWidget->backSetPage();
    });

    connect(ui->Btn_InputSet, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(InputSet_id);
        ui->stackedWidget_dialog->setCurrentIndex(InputSetDialog_id);
    });
    connect(ui->Btn_inputPageUp, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_input->setCurrentIndex(0);
    });
    connect(ui->Btn_inputPageDown, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_input->setCurrentIndex(1);
    });
    ////输入IO设置界面信号和槽的链接
    for(int i = 0; i < INPUT_NUM; i++)
    {
        connect(Btn_X_List.at(i), &QPushButton::clicked, this, [=](){
            ui->stackedWidget_dialog->show();
            ui->label_inputPort->setText(InputIO_Detect_IO[i]);
        });
    }
//    InputSet(ui->Btn_X0 , "X0 ");
//    InputSet(ui->Btn_X1 , "X1 ");
//    InputSet(ui->Btn_X2 , "X2 ");
//    InputSet(ui->Btn_X3 , "X3 ");
//    InputSet(ui->Btn_X4 , "X4 ");
//    InputSet(ui->Btn_X5 , "X5 ");
//    InputSet(ui->Btn_X6 , "X6 ");
//    InputSet(ui->Btn_X7 , "X7 ");
//    InputSet(ui->Btn_X8 , "X8 ");
//    InputSet(ui->Btn_X9 , "X9 ");
//    InputSet(ui->Btn_X10, "X10");
//    InputSet(ui->Btn_X11, "X11");
//    InputSet(ui->Btn_X12, "X12");
//    InputSet(ui->Btn_X13, "X13");
//    InputSet(ui->Btn_X14, "X14");
//    InputSet(ui->Btn_X15, "X15");
//    InputSet(ui->Btn_X16, "X16");
//    InputSet(ui->Btn_X17, "X17");
//    InputSet(ui->Btn_X18, "X18");
//    InputSet(ui->Btn_X19, "X19");
//    InputSet(ui->Btn_X20, "X20");
//    InputSet(ui->Btn_X21, "X21");
//    InputSet(ui->Btn_X22, "X22");
//    InputSet(ui->Btn_X23, "X23");
//    InputSet(ui->Btn_X24, "X24");
//    InputSet(ui->Btn_X25, "X25");
//    InputSet(ui->Btn_X26, "X26");
//    InputSet(ui->Btn_X27, "X27");
//    InputSet(ui->Btn_X28, "X28");
//    InputSet(ui->Btn_X29, "X29");

    connect(ui->Btn_InputSetOk, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_dialog->hide();
    });
    connect(ui->Btn_InputSetCancel, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_dialog->hide();
    });
    connect(ui->Btn_inputBack, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_dialog->hide();
        ui->stackedWidget->setCurrentIndex(IOSetSel_id);
    });

    connect(ui->Btn_OutputSet, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(OutputSet_id);
        ui->stackedWidget_dialog->setCurrentIndex(OutputSetDialog_id);
    });
    connect(ui->Btn_outputPageUp, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_output->setCurrentIndex(0);
    });
    connect(ui->Btn_outputPageDown, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_output->setCurrentIndex(1);
    });

    ////输出IO设置界面信号和槽的链接
    for(int i = 0; i < OUTPUT_NUM; i++)
    {
        connect(Btn_Y_List.at(i), &QPushButton::clicked, this, [=](){
            ui->stackedWidget_dialog->show();
            ui->label_outputPort->setText(OutputIO_Detect_IO[i]);
        });
    }
//    OutputSet(ui->Btn_Y0 , "Y0 ");
//    OutputSet(ui->Btn_Y1 , "Y1 ");
//    OutputSet(ui->Btn_Y2 , "Y2 ");
//    OutputSet(ui->Btn_Y3 , "Y3 ");
//    OutputSet(ui->Btn_Y4 , "Y4 ");
//    OutputSet(ui->Btn_Y5 , "Y5 ");
//    OutputSet(ui->Btn_Y6 , "Y6 ");
//    OutputSet(ui->Btn_Y7 , "Y7 ");
//    OutputSet(ui->Btn_Y8 , "Y8 ");
//    OutputSet(ui->Btn_Y9 , "Y9 ");
//    OutputSet(ui->Btn_Y10, "Y10");
//    OutputSet(ui->Btn_Y11, "Y11");
//    OutputSet(ui->Btn_Y12, "Y12");
//    OutputSet(ui->Btn_Y13, "Y13");
//    OutputSet(ui->Btn_Y14, "Y14");
//    OutputSet(ui->Btn_Y15, "Y15");
//    OutputSet(ui->Btn_Y16, "Y16");
//    OutputSet(ui->Btn_Y17, "Y17");
//    OutputSet(ui->Btn_Y18, "Y18");
//    OutputSet(ui->Btn_Y19, "Y19");
//    OutputSet(ui->Btn_Y20, "Y20");
//    OutputSet(ui->Btn_Y21, "Y21");
//    OutputSet(ui->Btn_Y22, "Y22");
//    OutputSet(ui->Btn_Y23, "Y23");
//    OutputSet(ui->Btn_Y24, "Y24");
//    OutputSet(ui->Btn_Y25, "Y25");
//    OutputSet(ui->Btn_Y26, "Y26");
//    OutputSet(ui->Btn_Y27, "Y27");
//    OutputSet(ui->Btn_RY0, "RY0");
//    OutputSet(ui->Btn_RY1, "RY1");

    connect(ui->Btn_OutputSetOk, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_dialog->hide();
    });
    connect(ui->Btn_OutputSetCancel, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_dialog->hide();
    });
    connect(ui->Btn_outputBack, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_dialog->hide();
        ui->stackedWidget->setCurrentIndex(IOSetSel_id);
    });
}

SignalSet::~SignalSet()
{
    delete ui;
}

void SignalSet::init()
{
    ui->stackedWidget->setCurrentIndex(IOSetSel_id);
    ui->stackedWidget_input->setCurrentIndex(0);
    ui->stackedWidget_output->setCurrentIndex(0);
    ui->stackedWidget_dialog->hide();

    Btn_X_List<<ui->Btn_X0<<ui->Btn_X1<<ui->Btn_X2<<ui->Btn_X3<<ui->Btn_X4<<ui->Btn_X5
              <<ui->Btn_X6<<ui->Btn_X7<<ui->Btn_X8<<ui->Btn_X9<<ui->Btn_X10<<ui->Btn_X11
              <<ui->Btn_X12<<ui->Btn_X13<<ui->Btn_X14<<ui->Btn_X15<<ui->Btn_X16<<ui->Btn_X17
              <<ui->Btn_X18<<ui->Btn_X19<<ui->Btn_X20<<ui->Btn_X21<<ui->Btn_X22<<ui->Btn_X23
              <<ui->Btn_X24<<ui->Btn_X25<<ui->Btn_X26<<ui->Btn_X27<<ui->Btn_X28<<ui->Btn_X29;

    Btn_Y_List<<ui->Btn_Y0<<ui->Btn_Y1<<ui->Btn_Y2<<ui->Btn_Y3<<ui->Btn_Y4<<ui->Btn_Y5
              <<ui->Btn_Y6<<ui->Btn_Y7<<ui->Btn_Y8<<ui->Btn_Y9<<ui->Btn_Y10<<ui->Btn_Y11
              <<ui->Btn_Y12<<ui->Btn_Y13<<ui->Btn_Y14<<ui->Btn_Y15<<ui->Btn_Y16<<ui->Btn_Y17
              <<ui->Btn_Y18<<ui->Btn_Y19<<ui->Btn_Y20<<ui->Btn_Y21<<ui->Btn_Y22<<ui->Btn_Y23
             <<ui->Btn_Y24<<ui->Btn_Y25<<ui->Btn_Y26<<ui->Btn_Y27<<ui->Btn_RY0<<ui->Btn_RY1;
}

//进入输入设置界面首页
void SignalSet::InputSetPage()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->stackedWidget_input->setCurrentIndex(0);
}

//进入输出设置界面首页
void SignalSet::OutputSetPage()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->stackedWidget_output->setCurrentIndex(0);
}

//输入设置--输入名刷新
void SignalSet::IO_Detect_Display_Refresh_Input(u8 flag)
{
    if(flag == TRUE)
    {
        QList<QLabel*> IO_InputList;
        IO_InputList<<ui->label_X0<<ui->label_X1<<ui->label_X2<<ui->label_X3<<ui->label_X4<<ui->label_X5
                    <<ui->label_X6<<ui->label_X7<<ui->label_X8<<ui->label_X9<<ui->label_X10<<ui->label_X11
                    <<ui->label_X12<<ui->label_X13<<ui->label_X14<<ui->label_X15<<ui->label_X16<<ui->label_X17
                    <<ui->label_X18<<ui->label_X19<<ui->label_X20<<ui->label_X21<<ui->label_X22<<ui->label_X23
                    <<ui->label_X24<<ui->label_X25<<ui->label_X26<<ui->label_X27<<ui->label_X28<<ui->label_X29;
        for(int i=0; i<INPUT_NUM; i++)
        {
            GP->Parameter_StringChang(GP->Temp_Display_Data1, 0, GP->IO_Name_Parameter_Input[i].Name,
                                      GP->IO_Name_Parameter_Input[i].Name1, GP->IO_Name_Parameter_Input[i].Name2);
            if(GP->Temp_IO_Switch_Parameter[i]==1 && i>=Input_Special)
            {
                IO_InputList.at(18+(i-Input_Special))->setText(GP->u8toqstr(GP->Temp_Display_Data1, 12));  //红色
                IO_InputList.at(i)->setText(GP->u8toqstr(GP->BlankChar, 12));
            }
            else
            {
                IO_InputList.at(i)->setText(GP->u8toqstr(GP->BlankChar, 12));
                IO_InputList.at(18+(i-Input_Special))->setText(GP->u8toqstr(GP->Temp_Display_Data1, 12));
            }
        }

        flag = FALSE;
    }
}

//输出设置--输出名刷新
void SignalSet::IO_Detect_Display_Refresh(u8 flag)
{
    if(flag == TRUE)
    {
        QList<QLabel*> IO_OutputList;
        IO_OutputList<<ui->label_Y0<<ui->label_Y1<<ui->label_Y2<<ui->label_Y3<<ui->label_Y4<<ui->label_Y5
                     <<ui->label_Y6<<ui->label_Y7<<ui->label_Y8<<ui->label_Y9<<ui->label_Y10<<ui->label_Y11
                     <<ui->label_Y12<<ui->label_Y13<<ui->label_Y14<<ui->label_Y15<<ui->label_Y16<<ui->label_Y17
                     <<ui->label_Y18<<ui->label_Y19<<ui->label_Y20<<ui->label_Y21<<ui->label_Y22<<ui->label_Y23
                     <<ui->label_Y24<<ui->label_Y25<<ui->label_Y26<<ui->label_Y27<<ui->label_RY0<<ui->label_RY1;
        for(int i=0; i<OUTPUT_NUM; i++)
        {
            GP->Parameter_StringChang(GP->Temp_Display_Data1, 0, GP->IO_Name_Parameter[i].Name,
                                      GP->IO_Name_Parameter[i].Name1, GP->IO_Name_Parameter[i].Name2);
            if(GP->Temp_OUT_Switch_Parameter[i]==1)
            {
                IO_OutputList.at(22+(i-22))->setText(GP->u8toqstr(GP->Temp_Display_Data1, 12)); //红色
                IO_OutputList.at(i)->setText(GP->u8toqstr(GP->BlankChar, 12));
            }
            else
            {
                IO_OutputList.at(i)->setText(GP->u8toqstr(GP->BlankChar, 12));
                IO_OutputList.at(22+(i-22))->setText(GP->u8toqstr(GP->Temp_Display_Data1, 12));
            }
        }

        flag = FALSE;
    }
}



