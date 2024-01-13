#include "backlighter.h"

static const char* SysConfigPath = "/bin/hal.conf";
static const char* BrightnessConfigKey = "/device/brightness";
static const char* BacklightTimeKey = "/device/backlight_time";
static const char* BacklightCanKey = "/device/is_backlight";

BackLighter::BackLighter(IVirtualDevice *virtualDevice)
    :mVirtualDevice(virtualDevice), mBacklightTime(30000),mIsStartBacklightTimer(true),
    mResetTimerFunc(nullptr)
{
    light(true);
    QSettings settings(SysConfigPath, QSettings::IniFormat);
    int brightness = 100;
    if(settings.contains(BrightnessConfigKey))
    {
        brightness = settings.value(BrightnessConfigKey).toInt();
        brightness = brightness > 100 ? 100 : brightness;
        brightness = brightness < 0 ? 0 : brightness;
    }
    setBrightness(brightness);
    if(settings.contains(BacklightCanKey))
    {
        mIsStartBacklightTimer = settings.value(BacklightCanKey).toBool();
    }
    if(settings.contains(BacklightTimeKey))
    {
        int time = settings.value(BacklightTimeKey).toInt();
        time = time < 30000 ? 30000: time;
        mBacklightTime = time;
    }
}

int BackLighter::light(bool on)
{
//    qDebug() << "turn " << (on ? "on" : "off") << " backlight";
    return mVirtualDevice->light(on);
}

bool BackLighter::isLightOn()
{
    return mVirtualDevice->isLightOn();
}

int BackLighter::setBrightness(int brightness)
{
    QSettings settings(SysConfigPath, QSettings::IniFormat);
    settings.setValue(BrightnessConfigKey, brightness);
    settings.sync();
    sync();
    return mVirtualDevice->setBrightness(brightness);
}

int BackLighter::getBrightness()
{
    return mVirtualDevice->getBrightness();
}

int BackLighter::getBacklightTime()
{
    return mBacklightTime;
}

int BackLighter::setBacklightTime(uint32_t backlightTime)
{
    QSettings settings(SysConfigPath, QSettings::IniFormat);
    settings.setValue(BacklightTimeKey, backlightTime);
    settings.sync();
    sync();
    mBacklightTime = backlightTime;
    if(mResetTimerFunc)
    {
        mResetTimerFunc();
    }
    return 0;
}

bool BackLighter::isStartBacklightTimer()
{
    return mIsStartBacklightTimer;
}

void BackLighter::setStartBacklightTimer(bool value)
{
    QSettings settings(SysConfigPath, QSettings::IniFormat);
    settings.setValue(BacklightCanKey, value);
    settings.sync();
    sync();
    mIsStartBacklightTimer = value;
    if(mResetTimerFunc)
    {
        mResetTimerFunc();
    }
}

void BackLighter::setLightTimeChangeHandler(std::function<void ()> func)
{
    mResetTimerFunc = func;
}

void BackLighter::setBacklightTimerTmp(bool turnOn)
{
    mIsStartBacklightTimer = turnOn;
    if(mResetTimerFunc)
    {
        mResetTimerFunc();
    }
}
