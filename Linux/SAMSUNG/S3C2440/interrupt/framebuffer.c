#include "framebuffer.h"

extern unsigned int fb_base_addr;
extern unsigned int xsize;
extern unsigned int ysize;

DISPLAY SAMSUNG = {0xFF0000, 0XFFFFFF};

void PutPixel(unsigned int x, unsigned int y, unsigned int color)
{
    unsigned char red,green,blue;

    unsigned short *addr = (unsigned short *)fb_base_addr + (y * xsize + x);

    red = (color >> 3) & 0x1f;
    green = (color >> 18) & 0x3f;
    blue = (color >>  11) & 0x1f;
    color = (red << 11) | (green << 5) | blue;

    *addr = (unsigned short) color;
}

void rgb_confirm_pixel(unsigned int x, unsigned int y, unsigned int color)
{
    unsigned short *addr = (unsigned short *)fb_base_addr + (y * xsize + x);

    if(color == 0xFF0000){  
        *addr = (unsigned short) 0x03E0;
    }else if(color == 0x00FF00){
        *addr = (unsigned short) 0X001F;
    }else if(color == 0x0000FF){
        *addr = (unsigned short) 0xF800;
    }else{
        *addr = (unsigned short) 0xFFFF;
    }
    
}


void ClearScr(unsigned int color)
{   
    unsigned int x,y;
    
    for (y = 0; y < ysize; y++)
        for (x = 0; x < xsize; x++)
            PutPixel(x, y, color);
}

