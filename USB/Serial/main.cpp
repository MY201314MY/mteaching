#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "libusb.h" 

#define bInterfaceNumber 0

int main(){
    puts("  --- Universal serial bus ---\r\n");
    libusb_context *ctx;
    int rc = libusb_init(&ctx);
	if (rc < 0)
		return EXIT_FAILURE;

    libusb_device_handle *device_handle = NULL;
    device_handle = libusb_open_device_with_vid_pid(ctx, 0x0FFE, 0x0001);
    
    if(device_handle == NULL){
        printf("STMicroelectronics USB Transmit ERROR!\r\n");
        return EXIT_FAILURE;
    }

    if(libusb_release_interface(device_handle, bInterfaceNumber) == 0){
        puts("Interface released...\r\n");
    }
    
    int interface = libusb_claim_interface(device_handle, bInterfaceNumber);
    if(interface == 0)
		printf("claim interface successfully.\r\n");
    else
        perror("interface open failed");
        
    unsigned char cmd;   
    int length;
    uint8_t buffer[8]={0};

    while(1){
        char c = getchar();
        getchar();
        if(c=='q'){
            break;
        }
        switch(c){
            case 'n':
                cmd = 0x01;
                libusb_bulk_transfer(device_handle, 0x01, &cmd, 1, &length, 100);
                puts("turn on.");
                break;
            
            case 'f':
                cmd = 0x02;
                libusb_bulk_transfer(device_handle, 0x01, &cmd, 1, &length, 100);
                puts("turn off.");
                break;

            case 'r':
                libusb_bulk_transfer(device_handle, 0x81, buffer, sizeof buffer, &length, 100);
                printf("Read length:%d bytes:0x%02X - 0x%02X\r\n", length, buffer[0], buffer[1]);   
                break;

            default:
                puts("error!");
                break;
        }
    }
    
    puts("QUIT...\r\nbye-bye");
    if(device_handle != NULL){
        libusb_release_interface(device_handle, bInterfaceNumber);
        libusb_close(device_handle);
        libusb_exit(ctx);
    }
    
    return EXIT_SUCCESS;
}
