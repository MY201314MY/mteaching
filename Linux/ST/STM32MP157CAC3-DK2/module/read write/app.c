#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    printf("Linux DEVICE TREE.\r\n");

    int fd, result;
    char *filename;
    unsigned char buffer[1];

    if(argc != 3){
        printf("Error Usage!");

        return -1;
    }

    filename = argv[1];

    fd = open(filename, O_RDWR);
    if(fd<0){
        printf("file %s openned failed!", filename);

        return -1;
    }

    buffer[0] = atoi(argv[2]);

    result = write(fd, buffer, sizeof buffer);
    if(result<0){
        printf("LED Control Failed!\r\n");
        close(fd);
        return -1;
    }

    result = close(fd);
    if(result<0){
        printf("File %s Close Failed!\r\n", argv[1]);
    }

    return 0;
}