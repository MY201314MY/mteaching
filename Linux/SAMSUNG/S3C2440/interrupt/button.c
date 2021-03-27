#include "led.h"
#include "S3C2440.h"

void Button_init(){
    GPFCON &= ~((3<<0) | (3<<4));
    GPFCON |=  ((2<<0) | (2<<4));

    GPGCON &= ~((3<<6));
    GPGCON |=  ((2<<6));
    EINTMASK &= ~((1<<11));

	EXTINT0 &= ~((7<<0) | (7<<8));
	EXTINT0 |=  ((3<<0) | (3<<8));
	EXTINT1 &= ~((7<<12));
	EXTINT1 |=  ((3<<12));
    INTMASK &= ~((1<<0) | (1<<2) | (1<<5));
    
}

void Button_test(){
	while (1) {
		if((GPFDAT&(1<<0))){
			LED12_ON;
		}else{
			LED12_OFF;
		}

		if((GPFDAT&(1<<2))){
			LED11_ON;
		}else{
			LED11_OFF;
		}

		if((GPGDAT&(1<<3))){
			LED10_ON;
		}else{
			LED10_OFF;
		}
    }
}

