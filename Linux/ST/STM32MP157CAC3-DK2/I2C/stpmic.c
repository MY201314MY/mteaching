#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>

int fd;

#define I2C_ADDR 0x33

static void STPMIC_Init()
{
    fd = open("/dev/i2c-2", O_RDWR);
    if(fd < 0)
        printf("Open I2C Failed.\n");
    
    if(ioctl(fd, I2C_SLAVE_FORCE, I2C_ADDR) < 0)
        printf("Set Slave Address Failed!\n");
}

static void STPMIC_write(unsigned char *buffer, int len)
{
    int result = write(fd, buffer, len);
    printf("result:%d -- temp:0x%02X 0x%02X\r\n", result, buffer[0], buffer[1]);
}

static void STPMIC_read(unsigned char reg, int len)
{
    unsigned char buffer[256]={0};

    int result = write(fd, &reg, 1);
    printf("result:%d\r\n", result);

    result = read(fd, buffer, len);
    printf("result:%d\r\n\r\n", result);

    int i=0, j=0;
    for(;i<=0x0F;i++)
    {
        for(j=0;j<=0x0F;j++)
        {
            printf(" %02X", buffer[i*16+j]);
        }
        printf("\r\n");
    }

}

int main(int argc, char *argv[])
{
    STPMIC_Init();

    puts("Sound Card  Init Successfully.");

    unsigned char buffer[2] = {0x18, 0x04};

    STPMIC_read(0x00, 256);

    int result = close(fd);
    if(result<0){
        printf("File %s Close Failed!\r\n", argv[1]);
    }

    return 0;
}
