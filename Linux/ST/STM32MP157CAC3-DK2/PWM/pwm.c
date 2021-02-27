#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    printf("Linux PWM Control\r\n");

    int fd, result;

    fd = open("/sys/class/pwm/pwmchip0/pwm0/duty_cycle", O_RDWR);
    if(fd<0){
        printf("file %s openned failed!", "PWM");

        return -1;
    }
    unsigned char count=51;
    long duty = 0;
    char buffer[8] = {0};

    while(count--)
    {
        printf("count:%02d -- duty:%.2f%\r\n", 51-count, duty*100/1000000.0);

        sprintf(buffer, "%d", duty);

        result = write(fd, buffer, strlen(buffer));
        if(result<0){
            printf("data write Failed!\r\n");
            close(fd);
            return -1;
        }
        usleep(100*1000);
        duty += 5000;
    }

    result = close(fd);
    if(result<0){
        printf("File %s Close Failed!\r\n", argv[1]);
    }

    return 0;
}