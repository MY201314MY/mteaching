#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    printf("--- LED FILE CONTROL ---\r\n");

    int fd, result;

    fd = open("/sys/class/leds/mteaching/brightness", O_WRONLY);
    if(fd<0){
        printf("file %s openned failed!", "mteaching");

        return -1;
    }
    unsigned char count = 10;
    char buffer[8] = {0};

    while(count--)
    {
        fprintf(stdout, "ADB\r\n");
        sprintf(buffer, "%d", count%2);

        result = write(fd, buffer, strlen(buffer));
        if(result<0){
            printf("data write Failed!\r\n");
            close(fd);
            return -1;
        }
        sleep(1);
    }

    result = close(fd);
    if(result<0){
        printf("File %s Close Failed!\r\n", argv[1]);
    }
    putchar('\n');

    return 0;
}