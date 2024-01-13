#ifndef SYSCFGFACTORY_H
#define SYSCFGFACTORY_H

#include "isyscfgfactory.h"
#include "ivirtualdevice.h"
#include "virtualdevice.h"
#include "beeper.h"
#include "backlighter.h"
#include "timesetter.h"

class SysCfgFactory : public ISysCfgFactory
{
public:
    static ISysCfgFactory* instance();
public:
    SysCfgFactory(const SysCfgFactory&) = delete;
    SysCfgFactory* operator=(const SysCfgFactory&) = delete;
    ~SysCfgFactory();
private:
    SysCfgFactory();
public:
    IBeeper* getBeeper() override;
    IBacklighter* getBacklighter() override;
    ITimeSetter * getTimeSetter() override;

private:
    IVirtualDevice* mVirtualDevice;
    IBeeper * mBeeper;
    IBacklighter* mBacklighter;
    ITimeSetter* mTimeSetter;
};

#endif // SYSCFGFACTORY_H
