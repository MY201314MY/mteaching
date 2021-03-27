#include <stdio.h>
#include <unistd.h>


int main()
{
  printf("This is one of the most important concepts in Linux!\r\n");

  pid_t pid = fork();

  if(pid > 0)
  {
    printf("return child process pid:%d\r\n", pid);
    printf("Parent PID:%d\r\n", getpid());

  }
  else if(pid == 0)
  {
    printf("child process.\r\n");
    printf("Child PID:%d\r\n", getpid());
  }
  else
  {
    printf("fork error!");
  }


  return 0;
}