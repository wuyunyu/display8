#ifndef BACKLIGHTER_H
#define BACKLIGHTER_H

#include "ibacklighter.h"
#include "ivirtualdevice.h"
#include <QSettings>
#include <unistd.h>
#include <QDebug>

class BackLighter : public IBacklighter
{
public:
    explicit BackLighter(IVirtualDevice* virtualDevice);
    int light(bool on) override;
    bool isLightOn() override;
    int setBrightness(int brightness) override;
    int getBrightness() override;
    int getBacklightTime() override;
    int setBacklightTime(uint32_t backlightTime) override;
    bool isStartBacklightTimer() override;
    void setStartBacklightTimer(bool value) override;
    void setLightTimeChangeHandler( std::function<void()> func) override;
    void setBacklightTimerTmp(bool turnOn) override;

private:
    IVirtualDevice *mVirtualDevice;
    uint32_t mBacklightTime;
    bool mIsStartBacklightTimer;
    std::function<void()> mResetTimerFunc;
};

#endif // BACKLIGHTER_H
