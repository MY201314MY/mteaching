#include "S3C2440.h"
#include "led.h"
#include "uart.h"

extern UART uart0;

void IRQ(){
    unsigned char character;
    unsigned long offset = INTOFFSET;

    INTMASK |= 1<<offset;

    switch (offset){
    case 0:
        puts("\r\nEINT00\r\n");
        GPFDAT |= (7<<4);
        GPFDAT &=~(1<<6);
        break;

    case 2:
        puts("\r\nEINT02\r\n");
        GPFDAT |= (7<<4);
        GPFDAT &=~(1<<5);
        break;
    
    case 5:
        puts("\r\nEINT11\r\n");
        GPFDAT |= (7<<4);
        break;
    case 10:
        GPFDAT = (GPFDAT & (1<<4)^(1<<4)) | (GPFDAT & (~(1<<4)));
        break;
    case 28:
        SUBSRCPND |= 3<<0; 
        if((character = getchar()) != '\r'){
            putchar(character);
            *(uart0.buffer+uart0.length) = character;
            uart0.length++;
        }else{
            *(uart0.buffer+uart0.length) = '\0';
            uart0.update = 1;
            uart0.length = 0;
        }
        
    default:
        break;
    }

    if(offset == 5) 
        EINTPEND |= (1<<11);

    SRCPND |= 1<<offset;
    INTPND |= 1<<offset;  
    INTMASK &= ~(1<<offset);
}
