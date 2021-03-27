#ifndef __UART_H_
#define __UART_H_

typedef struct
{
    unsigned char update;
    unsigned int length;
    unsigned char buffer[128];
} UART;


void uart_init();
void putchar(unsigned char character);
void puts(const char *p);
unsigned char getchar();
unsigned char *gets();
#endif
