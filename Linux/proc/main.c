#include <time.h>
#include <stdio.h>


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

void get_load(double *one, double *five, double *fifteen)
{
  FILE *fd = fopen("/proc/loadavg", "r");
  int active, total, last;
  
  if (fd)
  {
    int n = fscanf(fd, "%32lf %32lf %32lf %32d/%32d %32d", 
                        one, five, fifteen, &active, &total, &last);
    fclose(fd);
  } else
    printf("Open file '/proc/loadavg' failed!");
}

int get_MaxPid()
{
  FILE *fd = fopen("/proc/sys/kernel/pid_max", "r");
  int max;
  
  if (fd)
  {
    int n = fscanf(fd, "%32d",  &max);
    fclose(fd);
    return max;
  } else {
    printf("Open file '/proc/loadavg' failed!");
    return 0;
  }
}

int main()
{
  printf("--- Linux ---\r\n");

  double time = 0;

  get_uptime(&time);

  printf("uptime:%lf\r\n", time);
  struct tm t = {
    .tm_mday=(int)time/(24*60*60),
    .tm_hour=(int)time/(60*60),
    .tm_min=(int)time/(60),
    .tm_sec=(int)time%60,
    };

  printf("uptime day:%02d h:%02d m:%02d s:%02d\r\n",
    t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec);

  return 0;
}