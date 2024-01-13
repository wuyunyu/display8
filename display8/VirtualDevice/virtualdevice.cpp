#include "virtualdevice.h"


VirtualDevice::VirtualDevice()
    :mFd(-1), mDevicePath("/dev/mcgs-hal-virtual-device")
{}

VirtualDevice::~VirtualDevice()
{
    if(mFd > 0){
        ::close(mFd);
    }
}

int VirtualDevice::beep(uint32_t time_ms)
{
    virtual_device_interface_sound_data data;
    data.beep_ms = time_ms;
    int retVal = ioctl(VIRTUAL_DEVICE_CMD_SOUND_SET_BEEP_TIME, &data);
    if(retVal == 0)
    {
        return 0;
    }
    printf("beep :%u failed!\n", time_ms);
    return -errno;
}

int VirtualDevice::light(bool on)
{
    virtual_device_interface_display_data data;
    data.status = on ? virtual_device_interface_display_data::status::BACKLIGHT_OPEN : virtual_device_interface_display_data::status::BACKLIGHT_CLOSE;
    int retVal = ioctl(VIRTUAL_DEVICE_CMD_DISPLAY_SET_BACKLIGHT_STATUS, &data);
    if(retVal == 0)
    {
        return 0;
    }
    printf("light %s failed!\n", on ? "on": "off");
    return -errno;
}

bool VirtualDevice::isLightOn()
{
    struct virtual_device_interface_display_data data;
    int retVal = 0;
    retVal = ioctl(VIRTUAL_DEVICE_CMD_DISPLAY_GET_BACKLIGHT_STATUS, &data);
    if (retVal != 0)
    {
        return -errno;
    }
    return data.status == virtual_device_interface_display_data::status::BACKLIGHT_OPEN;
}

int VirtualDevice::setBrightness(int brightness)
{
    constexpr int BRIGHTNESS_MAX_VALUE = 100;
    constexpr int BRIGHTNESS_MIN_VALUE = 1;
    struct virtual_device_interface_display_data data;
    data.brightness = brightness;
    if(brightness > BRIGHTNESS_MAX_VALUE)
    {
        data.brightness = BRIGHTNESS_MAX_VALUE;
    }
    else if(brightness < BRIGHTNESS_MIN_VALUE)
    {
        data.brightness = BRIGHTNESS_MIN_VALUE;
    }
    int retVal = ioctl(VIRTUAL_DEVICE_CMD_DISPLAY_SET_BACKLIGHT_BRIGHTNESS, &data);
    if(retVal == 0)
    {
        return 0;
    }
    printf("set brightness failed!retVal=%d\n",retVal);
    return -errno;
}

int VirtualDevice::getBrightness()
{
    struct virtual_device_interface_display_data data;
    int retVal = 0;
    retVal = ioctl(VIRTUAL_DEVICE_CMD_DISPLAY_GET_BACKLIGHT_BRIGHTNESS, &data);
    if(retVal == 0)
    {
        return data.brightness;
    }
    printf("get brightness failed!\n");
    return -errno;
}

int VirtualDevice::setRtcTime(tm *time)
{
    struct tm tm;
    if(! time)
    {
        return -EINVAL;
    }
    memcpy(&tm, time, sizeof(struct tm));
    int fd = 0;
    int counter = 10;
    do{
        fd = open("/dev/rtc0", O_WRONLY);
        if(fd < 0)
        {
            if (counter-- && errno == EBUSY)
            {
                usleep(2000);
                continue;
            }
            else
            {
                return fd;
            }
        }
    }while(0);

    int retval = ::ioctl(fd, RTC_SET_TIME, &tm);
    close(fd);
    if(retval != 0)
    {
        printf("set rtc time error:%s\n", strerror(errno));
    }
    return retval;
}

int VirtualDevice::ioctl(unsigned long cmd, void *arg)
{
    if(mFd < 0)
    {
        mFd = ::open(mDevicePath.data(), O_RDWR);
        if(mFd < 0)
        {
            printf("open device:%s failed", mDevicePath.data());
            return mFd;
        }
    }
    return ::ioctl(mFd, cmd, arg);
}

