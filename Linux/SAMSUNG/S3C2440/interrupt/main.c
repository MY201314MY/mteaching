#include "sys.h"
#include "led.h"
#include "rtc.h" 
#include "font.h"
#include "button.h"
#include "uart.h"
#include "timer.h"
#include "lcddrv.h"
#include "framebuffer.h"

UART uart0={0,0,0};

int main(){
	unsigned short i, j, k;

	LED_init();
	Button_init();
	uart_init();
    timer_init();
	
	puts("\r\nSAMSUNG -- S3C2440\r\n");

	Lcd_Port_Init();                     
    Tft_Lcd_Init(MODE_TFT_16BIT_480272); 
    Lcd_PowerEnable(0, 1);             
    Lcd_EnvidOnOff(1);                   
    
    for(i=0;i<272;i++)
        for(j=0;j<480;j++){
            k=128;
            if(j<160)
                PutPixel(j, i, 0xFF0000);  //red
            else if(j<320)
                PutPixel(j, i, 0x00FF00);  //green
            else{
                PutPixel(j, i, 0x0000FF);  //blue
            }
        }

    ClearScr(0xFFFFFF);
    LCD_test();
    puts("The bit picture comes from ACROBOTIC.\r\n");
    LCD_P8x16Str(128, 0, "Cmd:NONE");
    puts("\r\nPlease input:");
	while (1){
        if(uart0.update == 1){
            uart0.update = 0;
            puts("\r\n");
            puts(RTC_Reader());
            puts("  message:");
            puts(uart0.buffer);
            puts("\n\r\nPlease input:");
            LCD_P8x16Str(128, 8*4, "                                "); //once 48, error actived! now 32 
            LCD_P8x16Str(128, 8*4, uart0.buffer);
            //puts("hello");
        }
    }
	
	return 0;
}
/*
;What's is ip? 
;fp is mainly used to allocate a new address for variable.s

*/

