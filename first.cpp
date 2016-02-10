#include <iostream>
#include <libusb.h>
#include "protocol.h"

using namespace std;

bool deviceMatchesVendorProduct(libusb_device *device, unsigned short idVendor, unsigned short idProduct)
{
    libusb_device_descriptor desc;
    libusb_get_device_descriptor(device, &desc);
    return idVendor == desc.idVendor && idProduct == desc.idProduct;
}

void setTarget(int position, int servo)
{
    const unsigned short vendorId = 0x1ffb;
    unsigned short productIDArray[]={0x0089, 0x008a, 0x008b, 0x008c};
    libusb_context *ctx=0;
    libusb_device **device_list=0;
    libusb_init(&ctx);
    int count=libusb_get_device_list(ctx, &device_list);
    for(int i=0;i<count;i++)
    {
        libusb_device *device=device_list[i];
        {
            for(int Id=0;Id<4;Id++)
            {
                if(deviceMatchesVendorProduct(device, vendorId, productIDArray[Id]))
                {
                    libusb_device_handle *device_handle;
                    libusb_open(device, &device_handle);
                    libusb_control_transfer(device_handle, 0x40, REQUEST_SET_TARGET, position*4, servo, 0, 0, (ushort)5000);
                    libusb_close(device_handle);
                    break;
                }
            }
        }
    }
    libusb_free_device_list(device_list, 0);
    libusb_exit(ctx);
}

int main()
{
    while(1)
    {
        int position;
        int servo=0;
        cout << "Enter position: ";
        cin >> position;
        setTarget(position, servo);
    }
    return 0;
}
