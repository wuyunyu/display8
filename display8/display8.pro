QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -Wno-unused-variable

QMAKE_CXXFLAGS += -Wno-unused-parameter

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AlarmPage/alarmpage.cpp \
    DebugPage/debugpage.cpp \
    ManualPage/freeprog.cpp \
    ManualPage/manualpage.cpp \
    ManualPage/memorypoint.cpp \
    ManualPage/stacking.cpp \
    ManualPage/stackpara.cpp \
    ManualPage/stackset.cpp \
    RunPage/formula.cpp \
    RunPage/prodpara.cpp \
    RunPage/runpage.cpp \
    SetPage/exfuncset.cpp \
    SetPage/progset.cpp \
    SetPage/safeset.cpp \
    SetPage/setpage.cpp \
    SetPage/signalset.cpp \
    SetPage/sysset.cpp \
    SetPage/userset.cpp \
    TeachPage/editdialog.cpp \
    TeachPage/editteach.cpp \
    TeachPage/teachpage.cpp \
    main.cpp \
    mainWidget.cpp \
    VirtualDevice/virtualdevice.cpp \
    VirtualDevice/backlighter.cpp \
    VirtualDevice/timesetter.cpp \
    VirtualDevice/syscfgfactory.cpp \
    VirtualDevice/globaleventfilter.cpp \
    VirtualDevice/beeper.cpp \
    ParaConfig/paraconfig.cpp \
    ParaConfig/parasum.cpp \
    ParaConfig/paradef.cpp \
    MidLevel/md.cpp

HEADERS += \
    AlarmPage/alarmpage.h \
    DebugPage/debugpage.h \
    ManualPage/freeprog.h \
    ManualPage/manualpage.h \
    ManualPage/memorypoint.h \
    ManualPage/stacking.h \
    ManualPage/stackpara.h \
    ManualPage/stackset.h \
    RunPage/formula.h \
    RunPage/prodpara.h \
    RunPage/runpage.h \
    SetPage/exfuncset.h \
    SetPage/progset.h \
    SetPage/safeset.h \
    SetPage/setpage.h \
    SetPage/signalset.h \
    SetPage/sysset.h \
    SetPage/userset.h \
    TeachPage/editdialog.h \
    TeachPage/editteach.h \
    TeachPage/teachpage.h \
    mainWidget.h \
    VirtualDevice/virtualdevice.h \
    VirtualDevice/virtual_device_interface.h \
    VirtualDevice/iinterface.h \
    VirtualDevice/isyscfgfactory.h \
    VirtualDevice/ivirtualdevice.h \
    VirtualDevice/ibeeper.h \
    VirtualDevice/ibacklighter.h \
    VirtualDevice/itimesetter.h \
    VirtualDevice/backlighter.h \
    VirtualDevice/timesetter.h \
    VirtualDevice/syscfgfactory.h \
    VirtualDevice/globaleventfilter.h \
    VirtualDevice/beeper.h \
    ParaConfig/paraconfig.h \
    ParaConfig/parasum.h \
    ParaConfig/paradef.h \
    MidLevel/md.h

FORMS += \
    AlarmPage/alarmpage.ui \
    DebugPage/debugpage.ui \
    ManualPage/freeprog.ui \
    ManualPage/manualpage.ui \
    ManualPage/memorypoint.ui \
    ManualPage/stacking.ui \
    ManualPage/stackpara.ui \
    ManualPage/stackset.ui \
    RunPage/formula.ui \
    RunPage/prodpara.ui \
    RunPage/runpage.ui \
    SetPage/exfuncset.ui \
    SetPage/progset.ui \
    SetPage/safeset.ui \
    SetPage/setpage.ui \
    SetPage/signalset.ui \
    SetPage/sysset.ui \
    SetPage/userset.ui \
    TeachPage/editdialog.ui \
    TeachPage/editteach.ui \
    TeachPage/teachpage.ui \
    mainWidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES +=
