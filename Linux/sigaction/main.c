#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

void handler(int signum)
{
  switch (signum){
    case SIGUSR1:
      printf("SIGUSR1\r\n");break;
    
    case SIGUSR2:
      printf("SIGUSR2\r\n");break;

    default:
      printf("Signal:%d received", signum);
      break;
  }
}

#define SIZE 512

int main()
{
  printf("--- Linux Signal ---\r\n");

  char buff[SIZE];
  int length = 0;
  struct sigaction user;

  user.sa_flags = 0;
  user.sa_handler = handler;
  sigaction(SIGUSR1, &user, NULL);
  sigaction(SIGUSR2, &user, NULL);

  printf("PID: %d\r\n", getpid());

  while(1) {
    if((length = read(STDIN_FILENO, buff, SIZE-1)) == -1)
    {
      if(errno == EINTR)
      {
        printf("read is interrupted by signal\n");
      }
    }
    else
    {
      buff[length] = '\0';
      printf("%d bytes read: %s\n", length, buff);
    }
  }

  printf("---End---\r\n");

  return 0;
}
