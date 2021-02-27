/*
    90:E2:02:2C:5C:47 Mongoose
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>

#define ADDR "90:E2:02:2C:5C:47"

int main(int argc, char **argv)
{
    bdaddr_t address;
    str2ba(ADDR, &address);

    uint8_t initiator_filter = 0;
    uint8_t peer_bdaddr_type = LE_PUBLIC_ADDRESS;
    uint16_t interval = htobs(0x0004);
    uint16_t window = htobs(0x0004);
    uint8_t own_bdaddr_type = 0x00;
    uint16_t min_interval = htobs(0x000F);
    uint16_t max_interval = htobs(0x000F);
    uint16_t latency = htobs(0x0000);
    uint16_t supervision_timeout = htobs(0x0C80);
    uint16_t min_ce_length = htobs(0x0001);
    uint16_t max_ce_length = htobs(0x0001);

    uint16_t handle = 0;

    int fd = hci_open_dev(0);
    if(fd < 0)
    {
        perror("Can't Open HCI0.\r\n");
        exit(1);
    }else{
        puts("Open HCI0 Successfully.");
    }

    int error = hci_le_create_conn(fd, interval, window, initiator_filter,
        peer_bdaddr_type, address, own_bdaddr_type, min_interval, max_interval,
        latency, supervision_timeout, min_ce_length, max_ce_length, &handle, 25000);

    printf("Connect to HC08 Successfully\r\nhandle:%d\n", handle);

    uint8_t feature[8] = {0};
    if(!(hci_read_local_ext_features(fd, 0, NULL, feature, 1000)<0)){
        puts("Bluetooth Feature:");
        for(int i=0;i<8;i++)
            printf("0x%02X ", feature[i]);
        printf("\r\n");
    }

    struct hci_filter flt;
    hci_filter_clear(&flt);
    hci_filter_set_ptype(HCI_ACLDATA_PKT, &flt);
    if(setsockopt(fd, SOL_HCI, HCI_FILTER, &flt, sizeof flt)<0){
        printf("Failed to set HCI Filter.\r\n");
        close(fd);
        return -1;
    }

    sleep(5);

    error = hci_disconnect(fd, handle, HCI_OE_USER_ENDED_CONNECTION, 10000);

    hci_close_dev(fd);

    return 0;
}
