#ifndef __FRAMEBUFFER_H__
#define __FRAMEBUFFER_H__

typedef struct
{
    unsigned int color; 
    unsigned int background;
}DISPLAY;

void PutPixel(unsigned int x, unsigned int y, unsigned int color);

void rgb_confirm_pixel(unsigned int x, unsigned int y, unsigned int color);

void ClearScr(unsigned int color);

#endif
