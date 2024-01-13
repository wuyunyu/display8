#ifndef VIRTUAL_DEVICE_INTERFACE_H
#define VIRTUAL_DEVICE_INTERFACE_H

enum virtual_device_cmd
{

    /* FIXME: this cmd may be have a error from '0',
     * The 0x8010 refrence socket ioctl <sockios.h>
     * */
    VIRTUAL_DEVICE_CMD_START = 0x8910,

    /* sound device */
    VIRTUAL_DEVICE_CMD_SOUND_SET_BEEP_TIME,             /*! write, unsigend */
    VIRTUAL_DEVICE_CMD_SOUND_GET_BEEP_TIME,             /*! write, unsigend */

    /* display device */
    VIRTUAL_DEVICE_CMD_DISPLAY_GET_BACKLIGHT_STATUS,    /*! read, int */
    VIRTUAL_DEVICE_CMD_DISPLAY_SET_BACKLIGHT_STATUS,    /*! write, NULL */
    VIRTUAL_DEVICE_CMD_DISPLAY_GET_BACKLIGHT_BRIGHTNESS,
    VIRTUAL_DEVICE_CMD_DISPLAY_SET_BACKLIGHT_BRIGHTNESS,
    VIRTUAL_DEVICE_CMD_DISPLAY_GET_BACKLIGHT_BRIGHTNESS_UP_STATUS,    /*! read, int */
    VIRTUAL_DEVICE_CMD_DISPLAY_SET_BACKLIGHT_BRIGHTNESS_UP,
    VIRTUAL_DEVICE_CMD_DISPLAY_RECOVER_BACKLIGHT_BRIGHTNESS_UP,

    /* usb device */
    VIRTUAL_DEVICE_CMD_USB_GET_OTG_MODE,                /*! read, int */
    VIRTUAL_DEVICE_CMD_USB_SET_OTG_MODE,                /*! write, int */

    /* uart device */
    VIRTUAL_DEVICE_CMD_UART_OPEN,
    VIRTUAL_DEVICE_CMD_UART_CLOSE,
    VIRTUAL_DEVICE_CMD_UART_GET_INFO,
};


/* sound beep */
struct virtual_device_interface_sound_data
{
    unsigned int beep_ms;
};

/* display backlight */
struct virtual_device_interface_display_data
{
    enum status{ BACKLIGHT_OPEN, BACKLIGHT_CLOSE } status;
    int brightness;
};

/* usb mode */
struct virtual_device_interface_usb_data
{
    enum mode{ USB_OTG_MASTER, USB_OTG_DEVICE, USB_OTG_NET, USB_OTG_UNKNOWN} mode;
};

/* uart device */
struct virtual_device_interface_uart_data
{
    int tx;		///<发送总数
    int rx;		///<接收总数
    int parity;	///<校验位错误
    int frame;	///<帧错误
    int overrun;	///<buff溢出

    int com; ///uart port number
};

#endif // VIRTUAL_DEVICE_INTERFACE_H
