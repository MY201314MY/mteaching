#ifndef APPLE_STRUCTURE_H
#define APPLE_STRUCTURE_H

#include <stdio.h>
#include <string.h>

#define _number 3

struct student{
    char name[64];
    float score[2];
    float aver;
};

struct lanuage{
    char message[32];
    lanuage *next;
};


void input();
int input_to_system();
void find_next();

#endif
