#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/ipc.h>

typedef struct {
    long type;
    char message[512];
}Communication;

int main()
{
    int ID = 0;
    Communication xyz;
    key_t key = ftok("temporary", 66);
    ID = msgget(key, IPC_CREAT);

    printf("Queue Key:0x%X - ID:0x%X\r\n", key, ID);
    
    if(ID == -1){
        printf("Create Queue Failed!\r\n");

        return 1;
    }

    while(1)
    {
        if(msgrcv(ID, &xyz, 512, -1, 0) < 0)
        {
            printf("Recv Queue Failed!\r\n");

            return 1;
        }
        printf("recv:%s\r\n", xyz.message);
        if(strncmp(xyz.message, "quit", 4) == 0)
            break;
    }

    return 0;

}