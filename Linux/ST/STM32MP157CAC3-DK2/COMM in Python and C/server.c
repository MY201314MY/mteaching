#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>

#define PORT            18880 
#define BUFFER_SIZE     32
#define QUEUE           20

int main()
{
    int skt = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(skt, (struct sockaddr *)&server_addr, sizeof server_addr) == -1)
    {
        perror("bind error!");
        exit(1);
    }

    if(listen(skt, QUEUE) == -1)
    {
        perror("listen error!");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    struct sockaddr_in client_addr;
    socklen_t length = sizeof client_addr;

    int connect = accept(skt, (struct sockaddr *)&client_addr, &length);
    if(connect<0)
    {
        perror("connect failed");
        exit(1);
    }

    while(1)
    {
        memset(buffer, 0, sizeof buffer);
        int len = recv(connect, buffer, sizeof buffer, 0);
        if(strcmp(buffer, "quit")==0)
            break;

        puts("---- Recv ----");
        printf("length:%d\r\nmessage:%s\r\n", len, buffer);
        send(connect, buffer, len, 0);
    }

    puts("bye-bye");

    close(connect);
    close(skt);

    return 0;

}