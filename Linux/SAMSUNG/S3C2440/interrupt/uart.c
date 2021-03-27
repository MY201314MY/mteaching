#include "S3C2440.h"

void uart_init() {
    

    GPHCON &=~((3<<4) | (3<<6));
    GPHCON |= ((2<<4) | (2<<6)); 
    GPHUP  &=~((1<<2) | (1<<3));
    GPHUP  |= ((1<<2) | (1<<3));
    
    ULCON0  = 0x00000003;
    UCON0   = 0x00000005;
    UBRDIV0 = 0x0000001A;
    INTMASK &= ~(1<<28);
    INTSUBMSK &= ~(1<<0);
    INTSUBMSK |= 1<<1;
}

void putchar(unsigned char character){
    while (!(UTRSTAT0 & (1<<2)));
    UTXH0 = character;

}

void puts(char *p){
    while (*p) {
        putchar(*p);
        p++;
    }
}

unsigned char getchar(){
    while(!(UTRSTAT0 & 1));

    return URXH0;
}

unsigned char *gets(){
    unsigned char *p, *buffer=0;
    unsigned char character;

    p = buffer;

    while((character = getchar()) != '\r'){
        putchar(character);
        *buffer++ = character;
    }
    *buffer = '\0';

    return p;
}
