#ifndef ALARMPAGE_H
#define ALARMPAGE_H

#include <QWidget>
#include "ParaConfig/parasum.h"

namespace Ui {
class AlarmPage;
}

class AlarmPage : public QWidget
{
    Q_OBJECT

public:
    explicit AlarmPage(QWidget *parent = nullptr);
    ~AlarmPage();

    void init();

private slots:
    void on_Btn_clr_clicked();

private:
    Ui::AlarmPage *ui;
};

#endif // ALARMPAGE_H
