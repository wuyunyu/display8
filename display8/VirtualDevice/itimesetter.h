#ifndef ITIMESETTER_H
#define ITIMESETTER_H

#include "iinterface.h"
#include <time.h>

class ITimeSetter:public IInterface{
public:
    virtual int setTime(const tm& tm) = 0;
};

#endif // ITIMESETTER_H
