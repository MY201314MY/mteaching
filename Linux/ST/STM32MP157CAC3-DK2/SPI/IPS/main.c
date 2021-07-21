#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdint.h>
#include <linux/gpio.h>
#include "SPI.h"

struct gpiohandle_request req[2];

void GPIO_OUTPUT(int fd, u_int8_t value)
{
    struct gpiohandle_data data;

    data.values[0] = value;
    ioctl(fd, GPIOHANDLE_SET_LINE_VALUES_IOCTL, &data);
}



#define	LCD_WR_RS(n)	(n?\
						GPIO_OUTPUT(req[0].fd, 1):\
						GPIO_OUTPUT(req[0].fd, 0))
#define	LCD_RST(n)		(n?\
						GPIO_OUTPUT(req[1].fd, 1):\
						GPIO_OUTPUT(req[1].fd, 0))

#define LCD_Width   240
#define LCD_Height  240

#define WHITE   0xFFFF	
#define YELLOW  0xFFE0	
#define BRRED   0XFC07  
#define PINK    0XF81F	
#define RED     0xF800	
#define BROWN   0XBC40 
#define GRAY    0X8430  
#define GBLUE   0X07FF	
#define GREEN   0x07E0	
#define BLUE    0x001F  
#define BLACK   0x0000	
#define COUNT 11
static uint16_t color[] = {WHITE, YELLOW, BRRED, PINK, RED, BROWN, GRAY, GBLUE, GREEN, BLUE, BLACK};

uint8_t SPI_WriteByte(uint8_t *TxData,uint16_t size)
{
	/*move*/
	transfer(TxData, default_rx, size);
}
static void LCD_Write_Cmd(uint8_t cmd)
{
    LCD_WR_RS(0);
    SPI_WriteByte(&cmd, 1);
}
static void LCD_Write_Data(uint8_t dat)
{
    LCD_WR_RS(1);
    SPI_WriteByte(&dat, 1);
}
void LCD_Address_Set(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
    LCD_Write_Cmd(0x2a);
    LCD_Write_Data(x1 >> 8);
    LCD_Write_Data(x1);
    LCD_Write_Data(x2 >> 8);
    LCD_Write_Data(x2);

    LCD_Write_Cmd(0x2b);
    LCD_Write_Data(y1 >> 8);
    LCD_Write_Data(y1);
    LCD_Write_Data(y2 >> 8);
    LCD_Write_Data(y2);

    LCD_Write_Cmd(0x2C);
}
#define LCD_TOTAL_BUF_SIZE	(240*240*2)
#define LCD_Buf_Size 1152
static uint8_t lcd_buf[LCD_Buf_Size];
void LCD_Clear(uint16_t color)
{
    uint16_t i, j;
    uint8_t data[2] = {0}; 

    data[0] = color >> 8;
    data[1] = color;
    
    for(j = 0; j < LCD_Buf_Size / 2; j++)
    {
        lcd_buf[j * 2] =  data[0];
        lcd_buf[j * 2 + 1] =  data[1];
    }
    LCD_Address_Set(0, 0, LCD_Width - 1, LCD_Height - 1);
    LCD_WR_RS(1);
    for(i = 0; i < (LCD_TOTAL_BUF_SIZE / LCD_Buf_Size); i++)
    {
        SPI_WriteByte(lcd_buf, (uint16_t)LCD_Buf_Size);
    }
}
void LCD_Init(void)
{
    
    LCD_RST(0);
    usleep(200*1000);
    LCD_RST(1);
	
    usleep(200*1000);
	
    
    LCD_Write_Cmd(0x11);
    usleep(200*1000);

    
    LCD_Write_Cmd(0x36);
    LCD_Write_Data(0x00);
    
    LCD_Write_Cmd(0x3A);
    LCD_Write_Data(0x65);
    
    LCD_Write_Cmd(0xB2);
    LCD_Write_Data(0x0C);
    LCD_Write_Data(0x0C);
    LCD_Write_Data(0x00);
    LCD_Write_Data(0x33);
    LCD_Write_Data(0x33);
    
    LCD_Write_Cmd(0xB7);
    LCD_Write_Data(0x72);
    
    LCD_Write_Cmd(0xBB);
    LCD_Write_Data(0x3D);
    
    LCD_Write_Cmd(0xC0);
    LCD_Write_Data(0x2C);
    
    LCD_Write_Cmd(0xC2);
    LCD_Write_Data(0x01);
    
    LCD_Write_Cmd(0xC3);
    LCD_Write_Data(0x19);
    
    LCD_Write_Cmd(0xC4);
    LCD_Write_Data(0x20);
    
    LCD_Write_Cmd(0xC6);
    LCD_Write_Data(0x0F);
    
    LCD_Write_Cmd(0xD0);
    LCD_Write_Data(0xA4);
    LCD_Write_Data(0xA1);
    
    LCD_Write_Cmd(0xE0);
    LCD_Write_Data(0xD0);
    LCD_Write_Data(0x04);
    LCD_Write_Data(0x0D);
    LCD_Write_Data(0x11);
    LCD_Write_Data(0x13);
    LCD_Write_Data(0x2B);
    LCD_Write_Data(0x3F);
    LCD_Write_Data(0x54);
    LCD_Write_Data(0x4C);
    LCD_Write_Data(0x18);
    LCD_Write_Data(0x0D);
    LCD_Write_Data(0x0B);
    LCD_Write_Data(0x1F);
    LCD_Write_Data(0x23);
    
    LCD_Write_Cmd(0xE1);
    LCD_Write_Data(0xD0);
    LCD_Write_Data(0x04);
    LCD_Write_Data(0x0C);
    LCD_Write_Data(0x11);
    LCD_Write_Data(0x13);
    LCD_Write_Data(0x2C);
    LCD_Write_Data(0x3F);
    LCD_Write_Data(0x44);
    LCD_Write_Data(0x51);
    LCD_Write_Data(0x2F);
    LCD_Write_Data(0x1F);
    LCD_Write_Data(0x1F);
    LCD_Write_Data(0x20);
    LCD_Write_Data(0x23);
    
    LCD_Write_Cmd(0x21);
    LCD_Write_Cmd(0x29);
    
  
    LCD_Clear(WHITE);
}

int main(int argc, char **argv)
{
	char chrdev_name[20];
	int fd, ret;

	SPI_Init();

	strcpy(chrdev_name, "/dev/gpiochip0");

	/*  Open device: gpiochip0 for GPIO bank A */
	fd = open(chrdev_name, 0);
	if (fd == -1) {
		ret = -errno;
		fprintf(stderr, "Failed to open %s\n", chrdev_name);

		return ret;
	}

	/* request GPIO line: GPIO_A_11 */
	req[0].lineoffsets[0] = 11;
	req[0].flags = GPIOHANDLE_REQUEST_OUTPUT;
	strcpy(req[0].consumer_label, "led_gpio_A_11");
	req[0].lines  = 1;

	ret = ioctl(fd, GPIO_GET_LINEHANDLE_IOCTL, &req[0]);
	if (ret == -1) {
		ret = -errno;
		fprintf(stderr, "Failed to issue GET LINEHANDLE IOCTL (%d)\n", ret);
	}

    /* request GPIO line: GPIO_A_12 */
	req[1].lineoffsets[0] = 12;
	req[1].flags = GPIOHANDLE_REQUEST_OUTPUT;
	strcpy(req[1].consumer_label, "led_gpio_A_12");
	req[1].lines  = 1;

	ret = ioctl(fd, GPIO_GET_LINEHANDLE_IOCTL, &req[1]);
	if (ret == -1) {
		ret = -errno;
		fprintf(stderr, "Failed to issue GET LINEHANDLE IOCTL (%d)\n", ret);
	}

	if (close(fd) == -1)
		perror("Failed to close GPIO character device file");

	unsigned char i = 0;
	/*  Start led blinking */
	while(i++ < 11) {
		usleep(500*1000);
		LCD_Clear(color[i++]);
		if(i==COUNT) i=0;

		fprintf(stderr, ".");
	}
	fprintf(stdout, "\nend...\n");
	/*  release line */
	SPI_Exit();
	ret = close(req[0].fd);
	if (ret == -1) {
		perror("Failed to close GPIO LINEHANDLE device file");
		ret = -errno;
	}
    ret = close(req[1].fd);
	if (ret == -1) {
		perror("Failed to close GPIO LINEHANDLE device file");
		ret = -errno;
	}

	return ret;
}