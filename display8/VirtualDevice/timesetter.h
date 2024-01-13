#ifndef TIMESETTER_H
#define TIMESETTER_H

#include "itimesetter.h"
#include <time.h>
#include <sys/time.h>
#include "virtualdevice.h"
#include <errno.h>
#include <string.h>

class IVirtualDevice;

class TimeSetter : public ITimeSetter
{
public:
    explicit TimeSetter(IVirtualDevice* virtualDevice);
public:
    int setTime(const tm& t) override;

private:
    IVirtualDevice* mVirtualDevice;
};

#endif // TIMESETTER_H
