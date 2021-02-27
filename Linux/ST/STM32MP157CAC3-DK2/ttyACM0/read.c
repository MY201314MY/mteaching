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

    unsigned char i = 0;
    int fd, result ,length;

    fd = open("/dev/ttyACM0", O_RDWR, 0);
    if(fd<0){
        printf("file %s openned failed!", "Transmit");

        return -1;
    }

    char buffer[512] = {0};
    while (i<10)
    {
        i++;

        printf("i:%d", i);
        length = read(fd, buffer, sizeof buffer);
        if(length <= 0){
            sleep(1);
            puts(".");
        }else{
            printf(buffer);
            memset(buffer, 0, sizeof buffer);
        }  
    }

    result = close(fd);
    if(result<0){
        printf("File %s Close Failed!\r\n", argv[1]);
    }
    puts("End...");
    return 0;
}