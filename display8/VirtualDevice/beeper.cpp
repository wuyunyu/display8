#include "beeper.h"

static const char* BeepConfigPath = "/bin/hal.conf";
static const char* BeepConfigKey = "/device/beep";

Beeper::Beeper(IVirtualDevice *virtualDevice)
    :mBeeTime(30),mDevFd(-1), mVirtualDevice(virtualDevice)
{
    QSettings settings(BeepConfigPath, QSettings::IniFormat);
    if(settings.contains(BeepConfigKey))
    {
        mBeeTime = settings.value(BeepConfigKey).toInt();
        if(mBeeTime < 0)
        {
            mBeeTime = 30;
        }
    }
}

int Beeper::beep()
{
    uint32_t beepTime = getBeeTime();
//    qDebug() << "beep" << beepTime;
    return mVirtualDevice->beep(beepTime);
}

int Beeper::saveBeeTime(uint32_t time_ms)
{
    QSettings settings(BeepConfigPath, QSettings::IniFormat);
    settings.setValue(BeepConfigKey, time_ms);
    settings.sync();
    sync();
    mBeeTime = time_ms;
    return 0;
}

uint32_t Beeper::getBeeTime() const
{
    return mBeeTime;
}

