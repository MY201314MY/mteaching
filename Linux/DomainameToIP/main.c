
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_ADDR "baidu.com"

int main()
{
    char **p;
    char txt[64];
    struct hostent *host;

    printf("= = = Network = = =\r\n");

    if((host=gethostbyname(SERVER_ADDR)) == NULL)
    {
        printf("DNS ERROR");
    }

    struct in_addr addr = *((struct in_addr *)host->h_addr);

    for(p=host->h_addr_list; *p!=NULL;p++)
    {
        if(NULL != inet_ntop(host->h_addrtype, *p, txt, sizeof(txt)))
        {
            printf("IP:%s\r\n", txt);
        }
    }

    return 0;
}