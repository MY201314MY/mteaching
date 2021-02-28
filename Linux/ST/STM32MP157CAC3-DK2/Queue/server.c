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
    ID = msgget(key, IPC_CREAT | 666);

    printf("Queue Key:0x%X - ID:0x%X\r\n", key, ID);

    if(ID == -1){
        printf("Create Queue Failed!\r\n");

        return 1;
    }

    while(1)
    {
        char message[512];
        memset(message, 0, 512);
        xyz.type = 1;
        scanf("%s", message);
        strcpy(xyz.message, message);

        if(msgsnd(ID, &xyz, 512, 0)<0)
        {
            printf("Send Queue Failed!\r\n");

            return 1;
        }

        if(strncmp(message, "quit", 4) == 0)
            break;
    }
    if(msgctl(ID, IPC_RMID, NULL))
    {
        printf("Delete Queue Failed!\r\n");

        return 1;
    }

    return 0;

}