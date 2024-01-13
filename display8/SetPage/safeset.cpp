#include "safeset.h"
#include "ui_safeset.h"
#include "mainWidget.h"


SafeSet::SafeSet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SafeSet)
{
    ui->setupUi(this);

    pWidget = static_cast<Widget*>(parent);

    this->init();

    //返回设置子界面或自由编程界面
    connect(ui->Btn_back, &QPushButton::clicked, this, [=](){
        if(ui->stackedWidget->currentIndex() == LimPosSet_id)
        {
            GP->LimPos_Temp_Save();
            pWidget->backSetPage();
        }
        else if(ui->stackedWidget->currentIndex() == SafeAreaSet_id)
        {
            if(GP->LCD_Main_Page == SYSTEM_SETTING)     //从设置主界面进入的
                pWidget->backSetPage();
            else if(GP->LCD_Main_Page == FREE_PROGRAMME)    //从自由编程主界面进入的
                pWidget->backTeachPage();
        }

    });

    connect(ui->Btn_safeAreaSetCancel, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_tip->hide();
    });

    connect(ui->Btn_save, &QPushButton::clicked, this, [=](){
        if(ui->stackedWidget->currentIndex() == LimPosSet_id)    //软限位--保存
        {
            if((GP->Temp_Soft_Limit[X_AXIS].Switch_Limit == 1 && (GP->Temp_Soft_Limit[X_AXIS].Left_Limit >= GP->Temp_Soft_Limit[X_AXIS].Right_Limit || GP->Temp_Soft_Limit[X_AXIS].Right_Limit * GP->Axis_Step_Coefficient[X_AXIS].Step_Coefficient / 100 < GP->g_Axis_Position[X_AXIS]))
            || (GP->Temp_Soft_Limit[L_AXIS].Switch_Limit == 1 && (GP->Temp_Soft_Limit[L_AXIS].Left_Limit >= GP->Temp_Soft_Limit[L_AXIS].Right_Limit || GP->Temp_Soft_Limit[L_AXIS].Right_Limit * GP->Axis_Step_Coefficient[L_AXIS].Step_Coefficient / 100 < GP->g_Axis_Position[L_AXIS]))
            || (GP->Temp_Soft_Limit[Z_AXIS].Switch_Limit == 1 && (GP->Temp_Soft_Limit[Z_AXIS].Left_Limit >= GP->Temp_Soft_Limit[Z_AXIS].Right_Limit || GP->Temp_Soft_Limit[Z_AXIS].Right_Limit * GP->Axis_Step_Coefficient[Z_AXIS].Step_Coefficient / 100 < GP->g_Axis_Position[Z_AXIS]))
            || (GP->Temp_Soft_Limit[O_AXIS].Switch_Limit == 1 && (GP->Temp_Soft_Limit[O_AXIS].Left_Limit >= GP->Temp_Soft_Limit[O_AXIS].Right_Limit || GP->Temp_Soft_Limit[O_AXIS].Right_Limit * GP->Axis_Step_Coefficient[O_AXIS].Step_Coefficient / 100 < GP->g_Axis_Position[O_AXIS])))
            {
                ui->stackedWidget_tip->setCurrentIndex(2);
                ui->stackedWidget_tip->show();
                SET::gs_Refresh_SoftLimit_Temp = TRUE;
                Refresh_SoftLimit_Temp(SET::gs_Refresh_SoftLimit_Temp);
                return;
            }

            if((GP->Temp_SoftDistance.MaxDistance <= GP->Temp_SoftDistance.MinDistance) && GP->Temp_SoftDistance.MaxDistance !=0)
            {
                ui->stackedWidget_tip->setCurrentIndex(2);
                ui->stackedWidget_tip->show();
                SET::gs_Refresh_SoftLimit_Temp = TRUE;
                Refresh_SoftLimit_Temp(SET::gs_Refresh_SoftLimit_Temp);
            }
            else
            {
                ui->stackedWidget_tip->setCurrentIndex(1);
                ui->stackedWidget_tip->show();

                GP->LimPos_Para_Save();

                ui->stackedWidget_tip->hide();
            }
        }
    });

    connect(ui->Btn_limPosSet, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(LimPosSet_id);
    });

    for(int i = 0; i < AXIS_NUM; i++)
    {
        //软限位-
        connect(Edit_LimPos_Minus.at(i), &QLineEdit::editingFinished, this, [=](){
            GP->Temp_Soft_Limit[i].Left_Limit = Edit_LimPos_Minus.at(i)->text().toUInt();
        });
        //软限位+
        connect(Edit_LimPos_Add.at(i), &QLineEdit::editingFinished, this, [=](){
            GP->Temp_Soft_Limit[i].Right_Limit = Edit_LimPos_Add.at(i)->text().toUInt();
        });
        //软限位开关
        connect(Btn_AXIS_Enable.at(i), &QPushButton::clicked, this, [=](){
            if(GP->Temp_Soft_Limit[i].Switch_Limit)
            {
                GP->Temp_Soft_Limit[i].Switch_Limit = FALSE;
            }
            else
            {
                GP->Temp_Soft_Limit[i].Switch_Limit = TRUE;
            }
            SET::gs_Refresh_SoftLimit_Temp = TRUE;
            Refresh_SoftLimit_Temp(SET::gs_Refresh_SoftLimit_Temp);
        });
    }

    connect(ui->Btn_safeAreaSet, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(SafeAreaSet_id);
    });

    connect(ui->Btn_safeAreaSetCancel, &QPushButton::clicked, this, [=](){
        ui->stackedWidget_tip->hide();
    });

    connect(ui->Btn_on_off, &QPushButton::clicked, this, [=](){
        if(GP->Robot_Safe_Area[GP->g_Current_Choose_Area-1].SafeArea_Switch)
        {
            GP->Robot_Safe_Area[GP->g_Current_Choose_Area-1].SafeArea_Switch = FALSE;
            ui->Btn_on_off->setText(X_SafeArea_Off);
        }
        else
        {
            GP->Robot_Safe_Area[GP->g_Current_Choose_Area-1].SafeArea_Switch = TRUE;
            ui->Btn_on_off->setText(X_SafeArea_On);
        }
        //将更改的安全区限位数据同步更改至参数文件中
        QSettings settings(SysConfigPath, QSettings::IniFormat);
        settings.beginGroup("SafeAreaPara");

        settings.beginWriteArray("SafeAreaPara_Array");
        for(int i=0; i < AXIS_NUM; i++)
        {
            if(i == GP->g_Current_Choose_Area-1)
            {
                settings.setValue(Robot_Safe_Area_Array_SafeArea_Switch_Key, GP->Robot_Safe_Area[i].SafeArea_Switch);
            }
        }
        settings.endArray();;

        settings.endGroup();
        settings.sync();
        sync();

        SET::gs_Refresh_SafeArea_Temp = TRUE;
    });

    //安全区1
    connect(ui->Btn_safeArea1, &QPushButton::clicked, this, [=](){
        GP->g_Current_Choose_Area = 1;
        QImage image(QString(":/SetPage/setpage_images/pic1.png"));
        ui->label_pix->setPixmap(QPixmap::fromImage(image));
    });
    //安全区2
    connect(ui->Btn_safeArea2, &QPushButton::clicked, this, [=](){
        GP->g_Current_Choose_Area = 2;
        QImage image(QString(":/SetPage/setpage_images/pic1.png"));
        ui->label_pix->setPixmap(QPixmap::fromImage(image));
    });
    //安全区3
    connect(ui->Btn_stockSafeArea, &QPushButton::clicked, this, [=](){
        GP->g_Current_Choose_Area = 3;
        QImage image(QString(":/SetPage/setpage_images/pic2.png"));
        ui->label_pix->setPixmap(QPixmap::fromImage(image));
    });

}

SafeSet::~SafeSet()
{
    delete ui;
}


void SafeSet::init()
{
    ui->stackedWidget->setCurrentIndex(LimPosSet_id);
    ui->stackedWidget_tip->hide();

    Edit_LimPos_Minus<<ui->Edit_XlimPosMinus<<ui->Edit_YlimPosMinus<<ui->Edit_ZlimPosMinus<<ui->Edit_OlimPosMinus;
    Edit_LimPos_Minus<<ui->Edit_XlimPosAdd<<ui->Edit_YlimPosAdd<<ui->Edit_ZlimPosAdd<<ui->Edit_OlimPosAdd;
    Btn_AXIS_Enable<<ui->Btn_Xenable<<ui->Btn_Yenable<<ui->Btn_Zenable<<ui->Btn_Oenable;
}

//软限位--开/关刷新
void SafeSet::Refresh_SoftLimit_Temp(u8 flag)
{
    if(flag)
    {
        for(int i = 0; i < AXIS_NUM; i++)
        {
            if(GP->Temp_Soft_Limit[i].Switch_Limit)
            {//轴软限位 开-关
                Btn_AXIS_Enable.at(i)->setText(SoftLimit_On);
            }
            else
            {
                Btn_AXIS_Enable.at(i)->setText(SoftLimit_Off);
            }
        }
        flag = FALSE;
    }
}

//X左上
void SafeSet::on_Edit_XPos1_editingFinished()
{
    if(GP->Robot_Safe_Area[GP->g_Current_Choose_Area-1].SafeArea_Switch == FALSE)
    {//只有在安全区开关关闭的情况下，才能修改安全点坐标
        if(static_cast<u32>(ui->Edit_ZPos1->text().toInt()) >= GP->Robot_Safe_Area[GP->g_Current_Choose_Area-1].Z_Right)
        {
            ui->stackedWidget_tip->setCurrentIndex(PW_5_SAFEAREAERROE);
            ui->stackedWidget_tip->show();
            ui->Edit_ZPos1->setText(QString::number(GP->Robot_Safe_Area[GP->g_Current_Choose_Area-1].Z_Left));
        }
        else
        {
            GP->Robot_Safe_Area[GP->g_Current_Choose_Area-1].Z_Left = ui->Edit_ZPos1->text().toInt();
            //将更改的安全区限位数据同步更改至参数文件中
            QSettings settings(SysConfigPath, QSettings::IniFormat);
            settings.beginGroup("SafeAreaPara");

            settings.beginWriteArray("SafeAreaPara_Array");
            for(int i=0; i < AXIS_NUM; i++)
            {
                if(i == GP->g_Current_Choose_Area-1)
                {
                    settings.setValue(Robot_Safe_Area_Array_Z_Left_Key, GP->Robot_Safe_Area[i].Z_Left);
                }
            }
            settings.endArray();;

            settings.endGroup();
            settings.sync();
            sync();
        }
    }
    else if(GP->Robot_Safe_Area[GP->g_Current_Choose_Area-1].SafeArea_Switch == TRUE)
    {
        ui->stackedWidget_tip->setCurrentIndex(PW_5_SAFEAREAERROE);
        ui->stackedWidget_tip->show();
        ui->Edit_ZPos1->setText(QString::number(GP->Robot_Safe_Area[GP->g_Current_Choose_Area-1].Z_Left));
    }
}

//Z左上
void SafeSet::on_Edit_ZPos1_editingFinished()
{
    if(GP->Robot_Safe_Area[GP->g_Current_Choose_Area-1].SafeArea_Switch == FALSE)
    {//只有在安全区开关关闭的情况下，才能修改安全点坐标
        if(static_cast<u32>(ui->Edit_XPos1->text().toInt()) >= GP->Robot_Safe_Area[GP->g_Current_Choose_Area-1].X_Right)
        {
            ui->stackedWidget_tip->setCurrentIndex(PW_5_SAFEAREAERROE);
            ui->stackedWidget_tip->show();
            ui->Edit_XPos1->setText(QString::number(GP->Robot_Safe_Area[GP->g_Current_Choose_Area-1].X_Left));
        }
        else
        {
            GP->Robot_Safe_Area[GP->g_Current_Choose_Area-1].X_Left = ui->Edit_XPos1->text().toInt();
            //将更改的安全区限位数据同步更改至参数文件中
            QSettings settings(SysConfigPath, QSettings::IniFormat);
            settings.beginGroup("SafeAreaPara");

            settings.beginWriteArray("SafeAreaPara_Array");
            for(int i=0; i < AXIS_NUM; i++)
            {
                if(i == GP->g_Current_Choose_Area-1)
                {
                    settings.setValue(Robot_Safe_Area_Array_X_Left_Key, GP->Robot_Safe_Area[i].X_Left);
                }
            }
            settings.endArray();;

            settings.endGroup();
            settings.sync();
            sync();
        }
    }
    else if(GP->Robot_Safe_Area[GP->g_Current_Choose_Area-1].SafeArea_Switch == TRUE)
    {
        ui->stackedWidget_tip->setCurrentIndex(PW_5_SAFEAREAERROE);
        ui->stackedWidget_tip->show();
        ui->Edit_XPos1->setText(QString::number(GP->Robot_Safe_Area[GP->g_Current_Choose_Area-1].X_Left));
    }
}

//X右下
void SafeSet::on_Edit_XPos2_editingFinished()
{
    if(GP->Robot_Safe_Area[GP->g_Current_Choose_Area-1].SafeArea_Switch == FALSE)
    {//只有在安全区开关关闭的情况下，才能修改安全点坐标
        if(static_cast<u32>(ui->Edit_XPos2->text().toInt()) <= GP->Robot_Safe_Area[GP->g_Current_Choose_Area-1].X_Left)
        {
            ui->stackedWidget_tip->setCurrentIndex(PW_5_SAFEAREAERROE);
            ui->stackedWidget_tip->show();
            ui->Edit_XPos2->setText(QString::number(GP->Robot_Safe_Area[GP->g_Current_Choose_Area-1].X_Right));
        }
        else
        {
            GP->Robot_Safe_Area[GP->g_Current_Choose_Area-1].X_Right = ui->Edit_XPos2->text().toInt();
            //将更改的安全区限位数据同步更改至参数文件中
            QSettings settings(SysConfigPath, QSettings::IniFormat);
            settings.beginGroup("SafeAreaPara");

            settings.beginWriteArray("SafeAreaPara_Array");
            for(int i=0; i < AXIS_NUM; i++)
            {
                if(i == GP->g_Current_Choose_Area-1)
                {
                    settings.setValue(Robot_Safe_Area_Array_X_Right_Key, GP->Robot_Safe_Area[i].X_Right);
                }
            }
            settings.endArray();;

            settings.endGroup();
            settings.sync();
            sync();
        }
    }
    else if(GP->Robot_Safe_Area[GP->g_Current_Choose_Area-1].SafeArea_Switch == TRUE)
    {
        ui->stackedWidget_tip->setCurrentIndex(PW_5_SAFEAREAERROE);
        ui->stackedWidget_tip->show();
        ui->Edit_XPos2->setText(QString::number(GP->Robot_Safe_Area[GP->g_Current_Choose_Area-1].X_Right));
    }
}

//Z右下
void SafeSet::on_Edit_ZPos2_editingFinished()
{
    if(GP->Robot_Safe_Area[GP->g_Current_Choose_Area-1].SafeArea_Switch == FALSE)
    {//只有在安全区开关关闭的情况下，才能修改安全点坐标
        if(static_cast<u32>(ui->Edit_ZPos2->text().toInt()) <= GP->Robot_Safe_Area[GP->g_Current_Choose_Area-1].Z_Left)
        {
            ui->stackedWidget_tip->setCurrentIndex(PW_5_SAFEAREAERROE);
            ui->stackedWidget_tip->show();
            ui->Edit_ZPos2->setText(QString::number(GP->Robot_Safe_Area[GP->g_Current_Choose_Area-1].Z_Right));
        }
        else
        {
            GP->Robot_Safe_Area[GP->g_Current_Choose_Area-1].Z_Right = ui->Edit_ZPos2->text().toInt();
            //将更改的安全区限位数据同步更改至参数文件中
            QSettings settings(SysConfigPath, QSettings::IniFormat);
            settings.beginGroup("SafeAreaPara");

            settings.beginWriteArray("SafeAreaPara_Array");
            for(int i=0; i < AXIS_NUM; i++)
            {
                if(i == GP->g_Current_Choose_Area-1)
                {
                    settings.setValue(Robot_Safe_Area_Array_X_Right_Key, GP->Robot_Safe_Area[i].Z_Right);
                }
            }
            settings.endArray();;

            settings.endGroup();
            settings.sync();
            sync();
        }
    }
    else if(GP->Robot_Safe_Area[GP->g_Current_Choose_Area-1].SafeArea_Switch == TRUE)
    {
        ui->stackedWidget_tip->setCurrentIndex(PW_5_SAFEAREAERROE);
        ui->stackedWidget_tip->show();
        ui->Edit_ZPos2->setText(QString::number(GP->Robot_Safe_Area[GP->g_Current_Choose_Area-1].Z_Right));
    }
}
