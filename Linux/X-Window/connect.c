#include <stdlib.h>
#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

int main(){
    Display *display;
    Window window = 0x2c0000a;
    XWindowAttributes attrs;
    XClassHint classhint;

    printf("- - - - X.Org - - - -\r\n");
    
    display = XOpenDisplay(NULL);


    if (display == NULL){
        printf("Can't connect to the server.");
        return 0;
    }
    
    if(XGetClassHint(display, window, &classhint)){
        printf("window name:%s - %s\n", classhint.res_name, classhint.res_class);
    }

    XCloseDisplay(display);
    printf("bye-bye\n");
    return 0;
}