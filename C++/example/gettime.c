#include <iostream>
#include <stdio.h>
#include <ctime>

using namespace std;
int main() {
    time_t m = time(0);
    char *time = ctime(&m);

    printf("time:%s\r\n", time);
    return 0;
}