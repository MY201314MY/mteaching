#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("[DRAM Embedded Engineer]\r\n");

    char *string = "2021 A4 -1234 0x6789";
    char *end;
    long int a, b, c, d;

    a = strtol(string, &end, 10);
    b = strtol(end, &end, 16);
    c = strtol(end, &end, 10);
    d = strtol(end, &end, 0);

    printf("a:%d -- b:%d\r\nc:%d -- d:%d", a, b, c, d);

    return 0;
}
/*
[DRAM Embedded Engineer]
a:2021 -- b:164
c:-1234 -- d:26505
*/