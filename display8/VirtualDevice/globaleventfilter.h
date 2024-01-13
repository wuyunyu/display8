#ifndef GLOBALEVENTFILTER_H
#define GLOBALEVENTFILTER_H

#include <QObject>
#include <QTimer>
#include <functional>
#include <QEvent>
#include <QDebug>
#include "syscfgfactory.h"
#include <unistd.h>
#include <QProcess>

class IBeeper;
class IBacklighter;

class GlobalEventFilter : public QObject
{
    Q_OBJECT
public:
    explicit GlobalEventFilter(QObject *parent = nullptr);
    bool eventFilter(QObject *watched, QEvent *event) override;
public:
    void registerCalibrateFunc(std::function<void()> func);
    void registerFullExitFunc(std::function<void()> func);
private slots:
    void timeToLightOff();
    void timeToCalibrate();
    void timeToExitFullScreen();
private:
    bool turnOnBacklight();
    long long getTickCount();
    void doCalibrate();
private:
    IBeeper* mBeeper;
    IBacklighter* mLighter;
    bool mIsMouseReleased;
    QTimer* mBacklightTimer;
    bool mIsMouseFristEntry;
    QTimer* mCalibrateTimer;
    long long mTickcount;
    bool mEntryCalibrate;
    std::function<void()> mFuncCalibrate;
    std::function<void()> mFuncFullExit;
    QTimer* mExitFullScreenTimer;
};

#endif // GLOBALEVENTFILTER_H
