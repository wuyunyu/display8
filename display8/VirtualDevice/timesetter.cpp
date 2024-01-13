#include "timesetter.h"

TimeSetter::TimeSetter(IVirtualDevice *virtualDevice)
    :mVirtualDevice(virtualDevice)
{}

int TimeSetter::setTime(const tm &t)
{
    struct tm ts = t;
    time_t tt = mktime(&ts);
    printf("time:%ld\n", tt);//use qt
    struct timeval tv;
    tv.tv_sec = tt;
    tv.tv_usec = 0;
    if(0 != settimeofday(&tv, nullptr))
    {
        printf("set time error:%s\n", strerror(errno));
        return errno;
    }
    return mVirtualDevice->setRtcTime(&ts);
}
