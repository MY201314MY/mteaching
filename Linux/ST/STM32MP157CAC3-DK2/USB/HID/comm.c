#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <unistd.h>
#include <libusb-1.0/libusb.h>

#define bInterFaceNumber 0

int main(int argc, char *argv[])
{
    puts("---- Universal Serial BUS ----");

    libusb_context *ctx;
    int rc = libusb_init(&ctx);

    if(rc < 0){
        printf("Failed to initialise libusb: %s\n", libusb_error_name(rc));

        return EXIT_FAILURE;
    }
    
    libusb_device_handle *device_handle;
    device_handle = libusb_open_device_with_vid_pid(ctx, 0x0FFE, 0x0001);
    if(device_handle == NULL){
        printf("STMicroelectronics USB Transmit ERROR!\r\n");

        goto exit;
    }
/*
    if(libusb_release_interface(device_handle, bInterFaceNumber) == 0){
        puts("Interface released...\r\n");
    }

    int interface = libusb_claim_interface(device_handle, bInterFaceNumber);
    if(interface == 0)
		printf("claim interface successfully.\r\n");
    else
        perror("interface open failed");
    unsigned char cmd;   
    int length;
    unsigned char index = 0;
    while(index < 3){
        index++;

        cmd = 0x01;
        libusb_bulk_transfer(device_handle, 0x01, &cmd, 1, &length, 100);
        printf("turn on the led, actual length:%d\r\n", length);
        sleep(1);

        cmd = 0x02;
        libusb_bulk_transfer(device_handle, 0x01, &cmd, 1, &length, 100);
        printf("turn off the led, actual length:%d\r\n", length);
        sleep(1);
    }

    libusb_close(device_handle);
*/
exit:
    puts("---- EXIT ----");
    libusb_exit(NULL);

    return EXIT_SUCCESS;
}

