#ifndef IBEEPER_H
#define IBEEPER_H

#include "iinterface.h"

class IBeeper:public IInterface{
public:
    virtual int beep() = 0;
    virtual int saveBeeTime(uint32_t time_ms) = 0;
    virtual uint32_t getBeeTime() const = 0;
};

#endif // IBEEPER_H
