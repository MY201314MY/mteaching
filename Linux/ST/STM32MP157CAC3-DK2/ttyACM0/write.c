#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    printf("Linux USB Transmit.\r\n");

    int fd, result;

    fd = open("/dev/ttyACM0", O_RDWR);
    if(fd<0){
        printf("file %s openned failed!", "Transmit");

        return -1;
    }

    char buffer[] = {"hello, ST.\n"};

    result = write(fd, buffer, sizeof buffer);
    if(result<0){
        printf("data transmit Failed!\r\n");
        close(fd);
        return -1;
    }

    result = close(fd);
    if(result<0){
        printf("File %s Close Failed!\r\n", argv[1]);
    }

    return 0;
}