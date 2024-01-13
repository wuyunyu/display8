#include "mainWidget.h"

#include <QApplication>
#include "VirtualDevice/globaleventfilter.h"

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("tgtsml"));
    QApplication a(argc, argv);

    GlobalEventFilter* globalFilter = new GlobalEventFilter();
    a.installEventFilter(globalFilter);

    Widget w;
    w.show();

    return a.exec();
}
