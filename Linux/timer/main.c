#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdint.h>

static uint8_t i = 0;

#define RelyOn

typedef struct {
    unsigned int start_t;
    unsigned int delay_t;
}alarm_t;

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

void get_uptime(double *t)
{
  FILE *fd = fopen("/proc/uptime", "r");
  
  if (fd)
  {
    int n = fscanf(fd, "%64lf", t);
    fclose(fd);
  } else
    printf("Open file '/proc/uptime' failed!");
}

void timer_callback(int signal)
{
    if(signal == SIGALRM)
    {
        #ifdef RelyOn
        printf("\r\ntime alarm arrived!\r\n");
        if(i==0)
        {
            i=1;
            printf("go ahead!\r\n\r\n");
        }
        #endif
    }
}

void alarm_late_set(unsigned int second)
{
    signal(SIGALRM, timer_callback); //register signal
    /*
    alarm()函数的主要功能是设置信号传送闹钟
    即用来设置信号SIGALRM在经过参数seconds秒数后发送给目前的进程
    如果未设置信号SIGALARM的处理函数，那么alarm()默认处理终止进程
    */

    /*
    reference url:
    https://blog.csdn.net/ken_lyy/article/details/51312466?utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-1.control&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-1.control
    */

    /*
    Attention:一个进程内不能设置多个闹钟(回调函数入口相同)!
    */
    alarm(second); //trigger timer
}

int main()
{
    char buffer[32];
    double time = 0;

    get_uptime(&time);

    printf("uptime:%lf\r\n", time);
    struct tm t = {
        .tm_mday=(int)time/(24*60*60),
        .tm_hour=(int)time/(60*60)%24,
        .tm_min=(int)time/(60)%60,
        .tm_sec=(int)time%60,
    };

    printf("uptime day:%02d h:%02d m:%02d s:%02d\r\n",
            t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec);

    alarm_late_set(10);

    timestr(buffer, sizeof buffer);
    printf("Begin:moment:%s\r\n", buffer);
    /*
    suspend the progress until receive a signal.
    */
    pause();
    
    timestr(buffer, sizeof buffer);
    printf("End:moment:%s\r\n", buffer);

    return 0;

}