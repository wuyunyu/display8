#ifndef DEBUGPAGE_H
#define DEBUGPAGE_H

#include <QWidget>
#include "ParaConfig/parasum.h"

namespace Ui {
class DebugPage;
}

class DebugPage : public QWidget
{
    Q_OBJECT

public:


public:
    explicit DebugPage(QWidget *parent = nullptr);
    ~DebugPage();

    void init();

private:
    Ui::DebugPage *ui;
};

#endif // DEBUGPAGE_H
