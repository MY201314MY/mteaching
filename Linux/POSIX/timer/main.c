#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

void handler(union sigval v)
{
  time_t t;

  char p[32];
  time(&t);
  strftime(p, sizeof p, "%T", localtime(&t));
  printf("%s thread %lu, val = %d, signal captured.\n", p, pthread_self(), v.sival_int);
}

int main()
{
  struct sigevent evp;
  struct itimerspec ts;
  timer_t timer;

  int ret;
  memset(&evp, 0, sizeof evp);
  evp.sigev_value.sival_ptr = &timer;
  evp.sigev_notify = SIGEV_THREAD;
  evp.sigev_notify_function = handler;
  evp.sigev_value.sival_int = 3;

  ret = timer_create(CLOCK_REALTIME, &evp, &timer);
  if(ret)
    perror("timer created!");

  ts.it_interval.tv_sec = 1;
  ts.it_interval.tv_nsec = 0;
  ts.it_value.tv_sec = 3;
  ts.it_value.tv_nsec = 0;

  ret = timer_settime(timer, TIMER_ABSTIME, &ts, NULL);
  if(ret)
    perror("timer settime.");

  while(1){
    sleep(5);
    puts("- - - Clock 5 second - - -");
  }
}