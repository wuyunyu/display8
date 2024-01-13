#ifndef BEEPER_H
#define BEEPER_H

#include "ibeeper.h"
#include "ivirtualdevice.h"
#include <QSettings>
#include <unistd.h>
#include <QDebug>

class Beeper : public IBeeper
{
public:
    explicit Beeper(IVirtualDevice* virtualDevice);
    int beep() override;
    int saveBeeTime(uint32_t time_ms) override;
    uint32_t getBeeTime() const override;

private:
    int mBeeTime;
    int mDevFd;
    IVirtualDevice* mVirtualDevice;

};

#endif // BEEPER_H
