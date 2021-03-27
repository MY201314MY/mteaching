#include "S3C2440.h"

void timer_init(){
    TCFG0 &= ~((0xFF<<0));
    TCFG0 |= ((99));
    TCFG1 &= ~((15<<0));
    TCFG1 |= 3;

    TCNTB0 = 31250;

    TCON   |= (1<<1);
    TCON = ((1<<0) | (1<<3));  

    INTMASK &= ~((1<<10));  
}
