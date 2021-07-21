#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <X11/Xlib.h>

int main(){
    Display *display;
    Window window, m, n, *menu, item;
    XImage* image;
    int width, height;
    unsigned int i=0, number=0;
    char **name=(char**)malloc(sizeof (char *));
    XWindowAttributes attrs;

    FILE* fp = NULL;

    printf("- - - - X.Org - - - -\r\n");
    
    display = XOpenDisplay(NULL);


    if (display == NULL){
        printf("Can't connect to the server.");
        return 0;
    }
    window = RootWindow(display, 0);
    
    if (window == 0){
        printf("Can't get the root window.\n");
        return 0;
    }

    printf("Root window ID:%ld\n", window);

    width = DisplayWidth(display, 0);
    height = DisplayHeight(display, 0);
    
    printf("width:%d  height:%d\n", width, height);

    XQueryTree(display, window, &m, &n, &menu, &number);
    printf("searching");
    for (; i < number; i++){
        item = menu[i];
        XFetchName(display, item, name);
        if(*name != NULL){
            /*
            m@ubuntu: ~
            */
            putchar('.');
            printf("\r\n Find window: %s ID:0x%08lX\n", *name, item);
            if(strstr(*name, "XXXXXX") != NULL){
                printf("\r\nwindow name: %s\n", *name);
                printf("Find the terminal window!\r\n");
                XGetWindowAttributes(display, item, &attrs);
                printf("x:%-4d  y:%-4d  w:%-4d  h:%-4d border:%-4d\n",
                        attrs.x, attrs.y, attrs.width, attrs.height, attrs.border_width);

                image = XGetImage(display, item, 0, 0, attrs.width, attrs.height, ~0, ZPixmap);
                printf("bpp:%d  depth:%d\n", image->bits_per_pixel, image->depth);

                fp = fopen("image.bin", "wb");
                if(fp == NULL){
                    printf("Can't open the file.\n");
                }
                printf("byte length:%d\r\n", image->width*image->height*image->bits_per_pixel/8);
                fwrite(image->data, sizeof(char), image->width*image->height*image->bits_per_pixel/8, fp);

                fclose(fp);
        
                break;
            }
        }
        else continue;
    }
    free(name);
    XFree(menu);
    XCloseDisplay(display);
    printf("\r\n- - - End - - -\r\n");
    return 0;
}

/*
    for(unsigned int l=0;l<image->width*image->bits_per_pixel/8;l++)
        printf("%03d - %03d - %03d - %03d\r\n", image->data[4*l], image->data[4*l+1], image->data[4*l+2], image->data[4*l+3]);
*/