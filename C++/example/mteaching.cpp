#include "mteaching.h"

Apple apple(3);

Apple::Apple(int init) {
    square = init;
}
void Apple::message() {
        std::cout<<"This is something about apple square: "<<s<<std::endl;
}
void gohome(){
    printf("Hi, media. . .\r\n");
    apple.w = 3;
    apple.h = 2;
    apple.s = apple.w * apple.h;
    printf("square:%d\r\n", apple.s);
    apple.message();
}

void enter(){
    std::cout << "This is designed by Apple in Cal." << std::endl;
#ifdef SYSTEM_ENTER
    MY_PASSWORD password={         \
            .times = 0,            \
            "undefined",           \
            .enter = false,        \
    };
    char i, character;
    while(password.times < INPUT_MAX) {
        i = 0;
        printf("Please input the password:");
        while ((character = getch()) != 13) {
            password.variable[i++] = character;
            putchar('*');
        }
        puts(NULL);
        password.variable[i] = '\0';
        if(strcmp(password.variable, PASSWORD) == 0){
            printf(LINE "Welcome!\r\n");
            password.enter = true;
            break;
        } else{
            if(password.times != INPUT_MAX-1)
                printf(LINE "Try again with %d chance(s). . .\r\n", INPUT_MAX-password.times-1);
        }
        password.times++;
    }
    if(!password.enter){
        printf("Game over!!!");
    }
#endif
}
