#ifndef IBACKLIGHTER_H
#define IBACKLIGHTER_H

#include "iinterface.h"
#include <functional>

class IBacklighter:public IInterface{
public:
    virtual int light(bool on) = 0;
    virtual bool isLightOn() = 0;
    /**
     * @brief setBrightness set backlightness
     * @param brightness 0~100
     * @note the zero brightness is not real zero
     */
    virtual int setBrightness(int brightness) = 0;
    virtual int getBrightness() = 0;
    virtual int getBacklightTime() = 0;
    virtual int setBacklightTime(uint32_t backlightTime) = 0;
    virtual bool isStartBacklightTimer() = 0;
    virtual void setStartBacklightTimer(bool value) = 0;
    virtual void setLightTimeChangeHandler( std::function<void()> func) = 0;
    virtual void setBacklightTimerTmp(bool turnon) = 0;
};

#endif // IBACKLIGHTER_H
