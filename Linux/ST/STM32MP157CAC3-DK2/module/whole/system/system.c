#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int8_t *cmd=NULL;

    cmd = argv[1];
    if(!strcmp(cmd, "on")){
        puts("TURN ON");
    }else if(!strcmp(cmd, "off")){
        puts("TURN OFF");
    }else{
        puts("UNKNOWN COMMAND!");
    }

    return 0;
}