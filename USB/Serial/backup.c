#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "libusb.h" 

#define bInterfaceNumber 0

int main(){
    puts("  --- Universal serial bus ---\r\n");
    libusb_context *ctx;
    int r = libusb_init(&ctx);
	if (r < 0)
		return r;

    libusb_device_handle *device_handle = NULL;
    device_handle = libusb_open_device_with_vid_pid(ctx, 0x0483, 0x5750);
    if(device_handle == NULL)
        printf("STMicroelectronics USB Transmit ERROR!\r\n");

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
    unsigned char index = 0;
    while(index < 3){
        index++;

        cmd = 0x01;
        libusb_bulk_transfer(device_handle, 0x01, &cmd, 1, &length, 100);
        printf("turn on the led, actual length:%d\r\n", length);
        Sleep(1000);

        cmd = 0x02;
        libusb_bulk_transfer(device_handle, 0x01, &cmd, 1, &length, 100);
        printf("turn off the led, actual length:%d\r\n", length);
        Sleep(1000);
    }
/*
    while(1){
        char c = getchar();
        getchar();
        if(c=='q'){
            break;
        }
        char *p = "Apple";
        int length = 0;
        uint8_t buffer[128]={0};
        switch(c){
            case 'w':libusb_bulk_transfer(device_handle, 0x01, "L", 1, &length, 100);
                printf("actual length:%d\r\n", length);
                break;
            case 'r':
                libusb_bulk_transfer(device_handle, 0x81, buffer, sizeof buffer, &length, 100);
                printf("actual length:%d\r\n", length);   
                break;

            default: break;
        }
        printf("transmit...\r\n");
    }*/
    libusb_close(device_handle);
    libusb_exit(ctx);
    
    return EXIT_SUCCESS;
}



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
    device_handle = libusb_open_device_with_vid_pid(ctx, 0x0483, 0x5750);
    if(device_handle == NULL)
        printf("STMicroelectronics USB Transmit ERROR!\r\n");

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











#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "libusb.h" 

int done = 0;
libusb_device_handle *handle = NULL;

static int LIBUSB_CALL hotplug_callback(libusb_context *ctx, libusb_device *dev, libusb_hotplug_event event, void *user_data)
{
	struct libusb_device_descriptor desc;
	int rc;

	(void)ctx;
	(void)dev;
	(void)event;
	(void)user_data;

	rc = libusb_get_device_descriptor(dev, &desc);
	if (LIBUSB_SUCCESS != rc) {
		fprintf (stderr, "Error getting device descriptor\n");
	}

	printf ("Device attached: %04x:%04x\n", desc.idVendor, desc.idProduct);

	if (handle) {
		libusb_close (handle);
		handle = NULL;
	}

	rc = libusb_open (dev, &handle);
	if (LIBUSB_SUCCESS != rc) {
		fprintf (stderr, "Error opening device\n");
	}

	done++;

	return 0;
}

static int LIBUSB_CALL hotplug_callback_detach(libusb_context *ctx, libusb_device *dev, libusb_hotplug_event event, void *user_data)
{
	(void)ctx;
	(void)dev;
	(void)event;
	(void)user_data;

	printf ("Device detached\n");

	if (handle) {
		libusb_close (handle);
		handle = NULL;
	}

	done++;

	return 0;
}

int main(int argc, char *argv[])
{
	libusb_hotplug_callback_handle hp[2];
	int product_id, vendor_id, class_id;
	int rc;

	vendor_id  = (argc > 1) ? (int)strtol (argv[1], NULL, 0) : 0x0483;
	product_id = (argc > 2) ? (int)strtol (argv[2], NULL, 0) : 0x5750;
	class_id   = (argc > 3) ? (int)strtol (argv[3], NULL, 0) : LIBUSB_HOTPLUG_MATCH_ANY;

	rc = libusb_init (NULL);
	if (rc < 0)
	{
		printf("failed to initialise libusb: %s\n", libusb_error_name(rc));
		return EXIT_FAILURE;
	}

	if (!libusb_has_capability (LIBUSB_CAP_HAS_HOTPLUG)) {
		printf ("Hotplug capabilities are not supported on this platform\n");
		libusb_exit (NULL);
		return EXIT_FAILURE;
	}
	
	rc = libusb_hotplug_register_callback (NULL, LIBUSB_HOTPLUG_EVENT_DEVICE_ARRIVED, LIBUSB_HOTPLUG_NO_FLAGS, vendor_id,
		product_id, class_id, hotplug_callback, NULL, &hp[0]);
	if (LIBUSB_SUCCESS != rc) {
		fprintf (stderr, "Error registering callback 0\n");
		libusb_exit (NULL);
		return EXIT_FAILURE;
	}

	rc = libusb_hotplug_register_callback (NULL, LIBUSB_HOTPLUG_EVENT_DEVICE_LEFT, LIBUSB_HOTPLUG_NO_FLAGS, vendor_id,
		product_id,class_id, hotplug_callback_detach, NULL, &hp[1]);
	if (LIBUSB_SUCCESS != rc) {
		fprintf (stderr, "Error registering callback 1\n");
		libusb_exit (NULL);
		return EXIT_FAILURE;
	}

	while (done < 2) {
		rc = libusb_handle_events (NULL);
		if (rc < 0)
			printf("libusb_handle_events() failed: %s\n", libusb_error_name(rc));
	}

	if (handle) {
		libusb_close (handle);
	}

	libusb_exit (NULL);

	return EXIT_SUCCESS;
}