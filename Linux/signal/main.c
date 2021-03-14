#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler()
{
  printf("Hello, world.");
  alarm(3);
}

int main()
{
  printf("--- Linux Signal ---\r\n");

  signal(SIGALRM, handler);
  alarm(3);

  for(int i=0;i<10;i++){
    printf("t:%d\r\n", i);
    sleep(1);
  }

  return 0;
}
