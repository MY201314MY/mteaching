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

void timer_callback(int signal)
{
    char buffer[32];

    timestr(buffer, sizeof buffer);
    switch(signal)
    {
        case SIGALRM:
            printf("moment:%s signal:%s\r\n", buffer, "SIGALRM");
            break;

        case SIGVTALRM:
            printf("moment:%s signal:%s\r\n", buffer, "SIGVTALRM");
            break;

        default:
            break;
    }
}

#define VIRTUAL 0

int main()
{
    struct itimerval tmv1, tmv2;
    time_t timer;
    int ret;

    printf("process id is %d\r\n", getpid());
    signal(SIGALRM, timer_callback);
#if VIRTUAL
    signal(SIGVTALRM, timer_callback);
#endif

    tmv1.it_value.tv_sec = 1;
    tmv1.it_value.tv_usec = 0;
    tmv1.it_interval.tv_sec = 1;
    tmv1.it_interval.tv_usec = 0;
    /*
    每隔一秒发送一次送出SIGALRM信号(以系统真实的时间来计算)
    */
    setitimer(ITIMER_REAL, &tmv1, NULL);
#if VIRTUAL
    tmv2.it_value.tv_sec = 0;
    tmv2.it_value.tv_usec = 200*1000;
    tmv2.it_interval.tv_sec = 0;
    tmv2.it_interval.tv_usec = 200*1000;
    /*
    每隔0.5秒发出一个SIGVTALRM信号
    */
    setitimer(ITIMER_VIRTUAL, &tmv2, NULL);
#endif
    printf("...\r\n");

    while(1);

}