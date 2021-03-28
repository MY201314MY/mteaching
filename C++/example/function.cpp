#include <iosfwd>
#include "function.h"

int max(int a, int b){
    return a>b?a:b;
}

int min(int a, int b){
    return a<b?a:b;
}

int func(){
    int x = 2;
    char *s=NULL;
    fun p = max;
    fun init[2] = {max, min};
    printf("size:%d\r\n", sizeof s);
    printf("size:%d\r\n", sizeof x);
    printf("size:%d\r\n", sizeof init[0]);
    for (int i = 0; i < 2; ++i) {
        printf("Value:%d\r\n", init[i](3,5));
    }
    return p(3, 4);
}
