#ifndef VIRTUALDEVICE_H
#define VIRTUALDEVICE_H

#include "ivirtualdevice.h"
#include "virtual_device_interface.h"
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/rtc.h>
#include <errno.h>
#include <string.h>
#include <string>

class VirtualDevice:public IVirtualDevice
{
    using String = std::string;
public:
    VirtualDevice();
    ~VirtualDevice();
public:
    int beep(uint32_t time_ms) override;
    int light(bool on) override;
    bool isLightOn() override;
    int setBrightness(int brightness) override;
    int getBrightness() override;
    int setRtcTime(tm* time) override;
private:
    int ioctl(unsigned long cmd, void* arg);
private:
    int mFd;
    String mDevicePath;
};

#endif // VIRTUALDEVICE_H
