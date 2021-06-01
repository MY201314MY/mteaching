#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <stdint.h>


/*
reference url:https://blog.csdn.net/chen1415886044/article/details/106980028
*/

void timestr(char *buffer, uint8_t len)
{
    time_t timestamp;
    struct tm *p;

    time(&timestamp);
    p = gmtime(&timestamp);

    sprintf(buffer, "%04d/%02d/%02d %02d:%02d:%02d", 
                        (1900+p->tm_year), (1+p->tm_mon), p->tm_mday,
                        (8+p->tm_hour), p->tm_min, p->tm_sec);
}

void timer_callback(union sigval arg)
{
    char buffer[32];

    timestr(buffer, sizeof buffer);
    printf("Begin:moment:%s\r\n", buffer);

    printf("timer callback!\r\n");
}

int main()
{
    struct sigevent evp;
    struct itimerspec ts;
    time_t timer;
    int ret;

    memset(&evp, 0, sizeof evp);
    evp.sigev_value.sival_ptr = &timer;

    /*定时器到期时将启动新的线程进行需要的处理*/
    evp.sigev_notify = SIGEV_THREAD;

    evp.sigev_notify_function = timer_callback;
    ret = timer_create(CLOCK_REALTIME, &evp, &timer);
    if(ret){
        perror("timer created failed!\r\n");
    }

    ts.it_interval.tv_sec = 1;
    ts.it_interval.tv_nsec = 0;
    ts.it_value.tv_sec = 10;
    ts.it_value.tv_nsec = 0;

    ret = timer_settime(timer, TIMER_ABSTIME, &ts, NULL);
    if(ret){
        perror("timer settime failed!");
    }
    pause();

}