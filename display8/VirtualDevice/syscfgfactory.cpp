#include "syscfgfactory.h"

ISysCfgFactory *SysCfgFactory::instance()
{
    static SysCfgFactory factory;
    return &factory;
}

SysCfgFactory::~SysCfgFactory()
{
    delete mBeeper;
    delete mBacklighter;
    delete mTimeSetter;
    delete mVirtualDevice;
}

SysCfgFactory::SysCfgFactory()
{
    mVirtualDevice = new VirtualDevice();
    mBeeper = new Beeper(mVirtualDevice);
    mBacklighter = new BackLighter(mVirtualDevice);
    mTimeSetter = new TimeSetter(mVirtualDevice);
}

IBeeper *SysCfgFactory::getBeeper()
{
    return mBeeper;
}

IBacklighter *SysCfgFactory::getBacklighter()
{
    return mBacklighter;
}

ITimeSetter *SysCfgFactory::getTimeSetter()
{
    return mTimeSetter;
}

