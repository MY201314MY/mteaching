#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

void timer_callback()
{
  printf("timer fired.\r\n");
}

void init_sigaction()
{
  struct sigaction act;

  act.sa_handler = timer_callback;
  act.sa_flags = 0;
  sigemptyset(&act.sa_mask);
  sigaction(SIGPROF, &act, NULL);
}

void init_timer()
{
  struct itimerval value;

  value.it_value.tv_sec = 1;
  value.it_value.tv_usec = 0;
  value.it_interval = value.it_value;

  setitimer(ITIMER_PROF, &value, NULL);
}

int main()
{
  init_sigaction();
  init_timer();

  while(1)
  {
    sleep(1);
  }

  return 0;
}
