#include "sys.h"
#include "S3C2440.h"

void LED_init(){
	GPFCON &= ~((3<<8) | (3<<10) | (3<<12));
	GPFCON |=  ((1<<8) | (1<<10) | (1<<12));
}

void LED_test(){
    unsigned char i=0;

    while (i<8){
        GPFDAT |= 7<<4;
        GPFDAT &= ~(i<<4);
        i++;
        delay();
    }
    
}
