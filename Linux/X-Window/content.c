#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <X11/Xlib.h>

int main(){
    Display *display;
    Window window;
    XImage* image;

    int width, height;
    int i=0;

    FILE* fp;

    display = XOpenDisplay(NULL);

    if (display == NULL)
    {
        printf("Can't connect to the server.");
        return 0;
    }
    window = RootWindow(display, 0);
    if (window == 0)
    {
        printf("Can't get the root window.\n");
        return 0;
    }
    width = DisplayWidth(display, 0);
    height = DisplayHeight(display, 0);
    printf("width:%d  height:%d\n", width, height);

    image = XGetImage(display, window, 0, 0, width, height, ~0, ZPixmap);
    
    fp = fopen("image.txt", "wb");
    if(fp == NULL){
        printf("Can't open the file.\n");
    }
    fwrite(image->data, 1, image->width*image->height*image->bits_per_pixel/8, fp);
    fclose(fp);
    printf("bpp:%d  depth:%d\n", image->bits_per_pixel, image->depth);
    XCloseDisplay(display);
    printf("bye-bye\n");
    return 0;
}