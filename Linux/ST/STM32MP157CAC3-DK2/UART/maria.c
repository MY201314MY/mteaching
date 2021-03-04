#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/signal.h>
#include <errno.h>
#include <termios.h>
#include <pthread.h>

int fd;
struct termios termAttr;
struct sigaction saio;
char tbuff[64];
char rbuff[64];

void sender()
{ 
	int i;
    strcpy(tbuff, "My name is STM32MP157-DK2.\r\n");
    uint8_t length = strlen(tbuff);

    while(1)
    {   
    	int len= write(fd, tbuff ,length);
		printf("TX length:%d\r\n", len);

	    sleep(1);
    }
 } 

void signal_handler_IO (int status)
{
    int n = read(fd, rbuff, 64);
    
	if (n)
     	printf("%.*s", n, rbuff);
}

#define serial "/dev/ttySTM1"

int main(int argc, char *argv[])
{    
	int i;
	pthread_t ntid;
    
	fd = open(serial, O_RDWR| O_NOCTTY);
    if (fd == -1)
    {
        perror("open_port: Unable to open "serial);
        exit(1);
    }
 
    saio.sa_handler = signal_handler_IO;
    saio.sa_flags = 0;
    saio.sa_restorer = NULL; 
    sigaction(SIGIO,&saio,NULL);
 
    fcntl(fd, F_SETFL, FNDELAY);
    fcntl(fd, F_SETOWN, getpid());
    fcntl(fd, F_SETFL, O_NDELAY| O_ASYNC );
 
    tcgetattr(fd,&termAttr);
    cfsetispeed(&termAttr,B115200);
    cfsetospeed(&termAttr,B115200);
    termAttr.c_cflag &= ~PARENB;
    termAttr.c_cflag &= ~CSTOPB;
    termAttr.c_cflag &= ~CSIZE;
    termAttr.c_cflag |= CS8;
    termAttr.c_cflag |= (CLOCAL | CREAD);
    termAttr.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    termAttr.c_iflag &= ~(IXON | IXOFF | IXANY);
    termAttr.c_oflag &= ~OPOST;
    tcsetattr(fd,TCSANOW,&termAttr);
    printf("serial configured....\n");
     
    pthread_create(&ntid,NULL,(void *)sender,NULL);
	pthread_join(ntid, NULL);
/*
	printf("---End---\r\n");
*/

    close(fd);
    exit(0);             
}
