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
    XFetchName(display, window, name);
    if(*name != NULL){
        printf("root name: %s\n", *name);
    }else
    {
        printf("Nothing\n");
    }
    

    width = DisplayWidth(display, 0);
    height = DisplayHeight(display, 0);
    
    printf("width:%d  height:%d\n", width, height);

    image = XGetImage(display, window, 0, 0, width, height, ~0, ZPixmap);
    
    printf("bpp:%d  depth:%d\n", image->bits_per_pixel, image->depth);
    XQueryTree(display, window, &m, &n, &menu, &number);
    for (; i < number; i++){
        item = menu[i];
        
        XFetchName(display, item, name);
        if(*name != NULL)
            printf("window name: %s\n", *name);
        else
            continue;

        XGetWindowAttributes(display, item, &attrs);
        printf("x:%-4d  y:%-4d  w:%-4d  h:%-4d border:%-4d root:%-4ld depth:%-4d color:0x%-8lX class:%-4d installed:%-4d\n",
        attrs.x, attrs.y, attrs.width, attrs.height, attrs.border_width, attrs.root, attrs.depth, attrs.colormap, attrs.class, attrs.map_installed);
        
    }
    free(name);
    XFree(menu);
    XCloseDisplay(display);
    printf("bye-bye\n");
    return 0;
}

/*
- - - - X.Org - - - -
Root window ID:1245
Nothing
width:1918  height:888
bpp:32  depth:24
window name: mutter guard window
x:0     y:0     w:1918  h:888  border:0    root:1245 depth:0    color:0x0        class:2    installed:0   
window name: gnome-shell
x:10    y:10    w:10    h:10   border:0    root:1245 depth:0    color:0x0        class:2    installed:0   
window name: ibus-x11
x:10    y:10    w:10    h:10   border:0    root:1245 depth:0    color:0x0        class:2    installed:0   
window name: ibus-xim
x:0     y:0     w:1     h:1    border:0    root:1245 depth:24   color:0x800002   class:1    installed:0   
window name: ibus-extension-gtk3
x:10    y:10    w:10    h:10   border:0    root:1245 depth:0    color:0x0        class:2    installed:0   
window name: gsd-keyboard
x:10    y:10    w:10    h:10   border:0    root:1245 depth:0    color:0x0        class:2    installed:0   
window name: gsd-color
x:10    y:10    w:10    h:10   border:0    root:1245 depth:0    color:0x0        class:2    installed:0   
window name: gsd-power
x:10    y:10    w:10    h:10   border:0    root:1245 depth:0    color:0x0        class:2    installed:0   
window name: gsd-media-keys
x:10    y:10    w:10    h:10   border:0    root:1245 depth:0    color:0x0        class:2    installed:0   
window name: gsd-xsettings
x:10    y:10    w:10    h:10   border:0    root:1245 depth:0    color:0x0        class:2    installed:0   
window name: gsd-wacom
x:10    y:10    w:10    h:10   border:0    root:1245 depth:0    color:0x0        class:2    installed:0   
window name: evolution-alarm-notify
x:10    y:10    w:10    h:10   border:0    root:1245 depth:0    color:0x0        class:2    installed:0   
window name: vmware-user
x:10    y:10    w:10    h:10   border:0    root:1245 depth:0    color:0x0        class:2    installed:0   
window name: vmware-user
x:-100  y:-100  w:10    h:10   border:0    root:1245 depth:0    color:0x0        class:2    installed:0   
window name: vmware-user
x:-100  y:-100  w:10    h:10   border:0    root:1245 depth:0    color:0x0        class:2    installed:0   
window name: vmware-user
x:-100  y:-100  w:10    h:10   border:0    root:1245 depth:0    color:0x0        class:2    installed:0   
window name: update-notifier
x:10    y:10    w:10    h:10   border:0    root:1245 depth:0    color:0x0        class:2    installed:0   
window name: vmware-user
x:-100  y:-100  w:10    h:10   border:0    root:1245 depth:0    color:0x0        class:2    installed:0   
window name: vmware-user
x:-100  y:-100  w:10    h:10   border:0    root:1245 depth:0    color:0x0        class:2    installed:0   
window name: vmware-user
x:-100  y:-100  w:10    h:10   border:0    root:1245 depth:0    color:0x0        class:2    installed:0   
window name: org.gnome.Nautilus
x:10    y:10    w:10    h:10   border:0    root:1245 depth:0    color:0x0        class:2    installed:0   
window name: org.gnome.Nautilus
x:-100  y:-100  w:10    h:10   border:0    root:1245 depth:0    color:0x0        class:2    installed:0   
window name: org.gnome.Nautilus
x:791   y:126   w:358   h:481  border:0    root:1245 depth:32   color:0x2400006  class:1    installed:0   
window name: org.gnome.Nautilus
x:651   y:179   w:319   h:176  border:0    root:1245 depth:32   color:0x2400006  class:1    installed:0   
window name: code
x:10    y:10    w:10    h:10   border:0    root:1245 depth:0    color:0x0        class:2    installed:0   
window name: code
x:0     y:0     w:200   h:200  border:0    root:1245 depth:24   color:0x2200002  class:1    installed:0   
window name: Terminal
x:10    y:10    w:10    h:10   border:0    root:1245 depth:0    color:0x0        class:2    installed:0   
window name: Terminal
x:-100  y:-100  w:10    h:10   border:0    root:1245 depth:0    color:0x0        class:2    installed:0   
window name: Desktop
x:72    y:27    w:1846  h:861  border:0    root:1245 depth:32   color:0x2400006  class:1    installed:0   
window name: m@ubuntu: ~
x:72    y:27    w:1846  h:861  border:0    root:1245 depth:32   color:0x2C00009  class:1    installed:0   
window name: gnome-shell
x:-200  y:-200  w:1     h:1    border:0    root:1245 depth:24   color:0x60000A   class:1    installed:0   
window name: Chromium clipboard
x:-100  y:-100  w:10    h:10   border:0    root:1245 depth:0    color:0x0        class:2    installed:0   
window name: vmware-user
x:865   y:872   w:62    h:62   border:0    root:1245 depth:0    color:0x0        class:2    installed:0   
bye-bye
*/