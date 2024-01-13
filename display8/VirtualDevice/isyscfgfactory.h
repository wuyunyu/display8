#ifndef ISYSCFGFACTORY_H
#define ISYSCFGFACTORY_H

#include "ibeeper.h"
#include "ibacklighter.h"
#include "itimesetter.h"

class ISysCfgFactory:public IInterface
{
public:
    virtual IBeeper* getBeeper() = 0;
    virtual IBacklighter* getBacklighter() = 0;
    virtual ITimeSetter* getTimeSetter() = 0;
};

#endif // ISYSCFGFACTORY_H
