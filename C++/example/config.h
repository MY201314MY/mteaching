#ifndef APPLE_CONFIG_H
#define APPLE_CONFIG_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#define SYSTEM_ENTER
#define mteaching(string, ...) {  \
    printf(string, ##__VA_ARGS__);    \
}

#define max(x, y) ({ \
    typeof(x) _x = x; \
    typeof(y) _y = y; \
    (void)(&_x == &_y); \
    _x>_y?_x:_y;    \
})

#define function(argument) printf("%s:%d\r\n", #argument, argument)
#define square(x) printf("The square of "#x" is %d.\r\n", x*x)
#define combine(param) x_ ## param
#endif
