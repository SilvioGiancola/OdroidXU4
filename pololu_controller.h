#ifndef POLOLU_CONTROLLER_H
#define POLOLU_CONTROLLER_H
/******************/
/*** POLOLU DRIVERS ***/
/******************/

#define SUCCESS 0
#define ERROR 1

#include <QWidget>
#include <QDebug>
#include <libusb.h>
#include "pololu_protocol.h"
#include <unistd.h>  // uslpeep

class PololuController : public QWidget
{
    Q_OBJECT
public:

    // Constructor
    explicit PololuController(QWidget *parent = 0) : QWidget(parent)
    {
        _ctx = 0;
        _device_list = 0;
        _open = false;
        for (int i = 0; i < 6; i++)
            _value[i] = 1500;
    }

    ~PololuController()
    {
        if (isopen())
            close();
    }

    // Open libusb connection
    int open()
    {

        if (isopen())
            return SUCCESS;
        const unsigned short vendorId = 0x1ffb;
        unsigned short productIDArray[]={0x0089, 0x008a, 0x008b, 0x008c};

        libusb_init(&_ctx);
        int count=libusb_get_device_list(_ctx, &_device_list);
        for (int i = 0; i < count; i++)
        {
            libusb_device *device = _device_list[i];
            {
                for (int Id = 0; Id < 4; Id++)
                {                    
                    libusb_device_descriptor desc;
                    libusb_get_device_descriptor(device, &desc);
                    if (vendorId == desc.idVendor && productIDArray[Id] == desc.idProduct)
                    {
                        _device = device;
                        libusb_open(_device, &_device_handle);
                        _open = true;
                        return SUCCESS;

                        qDebug () << " Pololu successfully opened";
                    }
                }
            }
        }
        return ERROR;
    }

    // Close libusb connection
    void close()
    {
        if (isopen())
        {
            libusb_close(_device_handle);
            libusb_free_device_list(_device_list, 0);
            libusb_exit(_ctx);
            _open = false;
            qDebug () << " Pololu closed";
        }
    }

    // Return true if libusb is opened
    bool isopen()
    {
        return _open;
    }

    void setPWM(int channel, int value)
    {
        _value[channel] = value;
        if (isopen())
            libusb_control_transfer(_device_handle, 0x40, REQUEST_SET_TARGET, value*4, channel, 0, 0, (ushort)5000);
    }

    int getPWM(int channel)
    {
        return _value[channel];
    }

    void impulse(int channel)
    {
        int tmp = getPWM(channel);
        setPWM(channel,2000);
        usleep(100*1000);
        setPWM(channel, tmp);
    }






private:
    bool _open;
    libusb_context *_ctx;
    libusb_device **_device_list;
    libusb_device *_device;
    libusb_device_handle *_device_handle;

    int _value[6];
};

#endif // POLOLU_CONTROLLER_H
