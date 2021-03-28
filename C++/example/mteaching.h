#ifndef APPLE_MTEACHING_H
#define APPLE_MTEACHING_H

#include "config.h"
#define LINE "\r\n"
const char PASSWORD[64] = {"123456Zm"};
#define INPUT_MAX 3
typedef struct{
    unsigned char times;
    char variable[64];
    bool enter;
}MY_PASSWORD;

class Apple{
public:
    int w;
    int h;
    int s;
    int square;
public:
    void message();
    Apple(int init);
};

void gohome();
void enter();

extern Apple apple;
#endif
