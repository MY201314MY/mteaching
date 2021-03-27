#ifndef __FONT_H__
#define __FONT_H__

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;

void LCD_P6x8Str(uint16_t y, uint16_t x, uint8_t ch[]);
void LCD_P8x16Str(uint16_t y, uint16_t x, uint8_t ch[]);
void LCD_test();
#endif

