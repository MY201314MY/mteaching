#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/l2cap.h>

#define ATT_CID 4

int main(int argc, char **argv)
{
    struct sockaddr_l2 srcaddr, dstaddr;
    int sockfd, status;
    unsigned short cid = 4;
    unsigned short psm = 0;
    char src[18] = "43:43:A1:12:1F:AC";
    char dst[18] = "50:02:91:95:A3:9A";
	
    sockfd = socket(AF_BLUETOOTH, SOCK_SEQPACKET, BTPROTO_L2CAP);
    
    memset(&srcaddr, 0, sizeof(srcaddr));
    str2ba( src, &srcaddr.l2_bdaddr );
    srcaddr.l2_family = AF_BLUETOOTH;
    srcaddr.l2_cid = htobs(ATT_CID);
    srcaddr.l2_bdaddr_type = BDADDR_LE_PUBLIC;
    
    status = bind(sockfd, (struct sockaddr *)&srcaddr, sizeof(srcaddr));
    if ( status < 0 ) {
        perror("uh oh src");
        close(sockfd);
        return -1;
    }
    
    memset(&dstaddr, 0, sizeof(dstaddr));
    str2ba( dst, &dstaddr.l2_bdaddr );
    dstaddr.l2_family = AF_BLUETOOTH;
    dstaddr.l2_cid = htobs(ATT_CID);
    dstaddr.l2_bdaddr_type = BDADDR_LE_PUBLIC;

    // connect to server
    printf("Connecting to device\n");
    status = connect(sockfd, (struct sockaddr *)&dstaddr, sizeof(dstaddr));
    if ( status < 0 ) {
        perror("uh oh dst");
        close(sockfd);
        return -1;
    }
    if( status == 0 ) {
        printf("Successfully connected\n");
        unsigned int i;
        // Write request = 0x12
        // Handle value = 0x23e0 (reversed below due to endianness)
        char str[10] = "\x29\x29\x00hello!\n";
        for (i = 0; i < 5; i++) {
            status = write(sockfd, str, 10);
            printf("status:%d\r\n", status);
            sleep(1);
        }
    }
    
    printf("Done, closing socket\n");
    close(sockfd);
    return 0;
}