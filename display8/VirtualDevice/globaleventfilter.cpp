#include "globaleventfilter.h"

GlobalEventFilter::GlobalEventFilter(QObject *parent) : QObject(parent),
    mIsMouseReleased(true),mIsMouseFristEntry(true),mEntryCalibrate(false)
{
    mBeeper = SysCfgFactory::instance()->getBeeper();
    mLighter = SysCfgFactory::instance()->getBacklighter();
    mBacklightTimer = new QTimer(this);
    mCalibrateTimer = new QTimer(this);
    mExitFullScreenTimer = new QTimer(this);

    mTickcount = getTickCount();
    connect(mBacklightTimer, SIGNAL(timeout()), this, SLOT(timeToLightOff()));
    connect(mCalibrateTimer, SIGNAL(timeout()), this, SLOT(timeToCalibrate()));
    connect(mExitFullScreenTimer, SIGNAL(timeout()), this, SLOT(timeToExitFullScreen()));
//    connect(mBacklightTimer, &QTimer::timeout, this, &GlobalEventFilter::timeToLightOff);
//    connect(mCalibrateTimer, &QTimer::timeout, this, &GlobalEventFilter::timeToCalibrate);
//    connect(mExitFullScreenTimer, &QTimer::timeout, this, &GlobalEventFilter::timeToExitFullScreen);
    if(mLighter->isStartBacklightTimer())
    {
        mBacklightTimer->start(mLighter->getBacklightTime());
    }
    mLighter->setLightTimeChangeHandler([=]()
    {
        if(mLighter->isStartBacklightTimer())
        {
            qDebug() << "restart backlight timer";
            mBacklightTimer->start(mLighter->getBacklightTime());
        }
        else
        {
            qDebug() << "stop backlight timer";
            mBacklightTimer->stop();
        }
    });

}
//press is filter,release must be filter
bool GlobalEventFilter::eventFilter(QObject *watched, QEvent *event)
{
//    qDebug() << "event fileter";
    if(event->type() == QEvent::MouseMove ||
            event->type() == QEvent::MouseButtonPress ||
            event->type() == QEvent::MouseButtonRelease)
    {

        if(event->type() == QEvent::MouseButtonPress)
        {
//            qDebug() << "mouse press";
            if(mIsMouseReleased)
            {
                mIsMouseReleased = false;
                if(turnOnBacklight())
                {
                    return true;
                }
                mBeeper->beep();
            }
            mExitFullScreenTimer->start(5000);
        }
        else if(event->type() == QEvent::MouseButtonRelease)
        {
//            qDebug() << "mouse release";
            mIsMouseReleased = true;
            mExitFullScreenTimer->stop();
        }
        else{
            qDebug() << "============ mouse move.....\n";
            if(turnOnBacklight())
            {
                return true;
            }
        }
        return QObject::eventFilter(watched, event);
    }
    else if(event->type() == QEvent::TouchBegin ||
            event->type() == QEvent::TouchUpdate ||
            event->type() == QEvent::TouchEnd)
    {
        if(event->type() == QEvent::TouchBegin)
        {
//            qDebug() << "Touch Begin";
            if(mIsMouseFristEntry)
            {
                mIsMouseFristEntry = false;
                long long curTickcount = getTickCount();
                if(curTickcount - mTickcount < 2000)
                {
                    qDebug() << "start calibrate timer";
                    mCalibrateTimer->start(3000);
                }
            }
            if(mIsMouseReleased)
            {
                mIsMouseReleased = false;
                if(turnOnBacklight())
                {
                    return true;
                }
                mBeeper->beep();
            }
            mExitFullScreenTimer->start(5000);
        }
        else if(event->type() == QEvent::TouchEnd)
        {
//            qDebug() << "Touch End";
            if(mCalibrateTimer->isActive())
            {
                qDebug() << "end calibrate timer";
                mCalibrateTimer->stop();
            }
            if(mEntryCalibrate)
            {
                doCalibrate();
            }
            mIsMouseReleased = true;
            mExitFullScreenTimer->stop();
        }
        else
        {
//            qDebug() << "Touch update";
            if(turnOnBacklight())
            {
                return true;
            }
        }
        return QObject::eventFilter(watched, event);
    }
    else if(event->type() == QEvent::KeyPress
            || event->type() == QEvent::KeyRelease)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(turnOnBacklight())
            {
                return true;
            }
        }
//        qDebug() << "filter" << (event->type() == QEvent::KeyPress ? "key press": "key release");
    }
    return QObject::eventFilter(watched, event);
}

void GlobalEventFilter::registerCalibrateFunc(std::function<void ()> func)
{
    mFuncCalibrate = func;
}

void GlobalEventFilter::registerFullExitFunc(std::function<void ()> func)
{
    mFuncFullExit = func;
}

void GlobalEventFilter::timeToLightOff()
{
    mBacklightTimer->stop();
    if(mLighter->isStartBacklightTimer())
    {
        mLighter->light(false);
    }
}

void GlobalEventFilter::timeToCalibrate()
{
    qDebug() << "time out to calibrate";
    mEntryCalibrate = true;
    mCalibrateTimer->stop();
    if(mFuncCalibrate)
    {
        mFuncCalibrate();
    }
}

void GlobalEventFilter::timeToExitFullScreen()
{
    qDebug() << "exit full scrren";
    mExitFullScreenTimer->stop();
    if(mFuncFullExit)
    {
        mFuncFullExit();
    }
}

bool GlobalEventFilter::turnOnBacklight()
{
    if(!mLighter->isLightOn())
    {
        mLighter->light(true);
        if(mLighter->isStartBacklightTimer())
        {
            mBacklightTimer->start(mLighter->getBacklightTime());
        }
        return true;
    }
    else
    {
        if(mLighter->isStartBacklightTimer())
        {
            mBacklightTimer->start(mLighter->getBacklightTime());
        }
    }
    return false;
}

long long GlobalEventFilter::getTickCount()
{
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return t.tv_sec * 1000LL + t.tv_nsec/1000000LL;
}

void GlobalEventFilter::doCalibrate()
{
    qDebug() << "do calibrate";
    unlink("/bin/web");
    symlink("/bin/calibrate.sh", "/bin/web");
    sync();
//    pid_t pid = vfork();
//    if(pid == 0){
//        daemon(0, 0);
//        QStringList list;
//        list.append("-x");
//        list.append("/bin/ts_calibrate.sh");
//        QProcess::startDetached("/bin/sh", list);
//    }
//    exit(0);
}
