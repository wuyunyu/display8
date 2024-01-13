#ifndef IVIRTUALDEVICE_H
#define IVIRTUALDEVICE_H

#include "iinterface.h"
#include <time.h>

class IVirtualDevice{
public:
    virtual int beep(uint32_t time_ms) = 0;
    virtual int light(bool on) = 0;
    virtual int setBrightness(int brightness) = 0;
    virtual int getBrightness() = 0;
    virtual bool isLightOn() = 0;
    virtual int setRtcTime(tm* time) = 0;
    virtual ~IVirtualDevice(){}

};

#endif // IVIRTUALDEVICE_H
