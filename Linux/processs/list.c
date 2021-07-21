#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#include <sys/types.h>

int main() {
    printf("[Process Information]\n");

    DIR *dp;
    struct dirent *dirp;
    int count=0;
    pid_t pid = getpid();
    printf("This Process Id:%d\r\n", pid);

    if((dp=opendir("/proc")) == NULL)
    {
        fprintf(stderr, "%s file %d line %s\r\n", __FILE__, __LINE__, strerror(errno));
        exit(1);
    }

    while ((dirp=readdir(dp)) != NULL)
    {
        if(dirp->d_type == DT_DIR){
            uint8_t i = 0;
            uint8_t len = strlen(dirp->d_name);
            for (; i < len; i++) {
                if(!isdigit(dirp->d_name[i]))
                {
                    break;
                }
                if(i==(len-1))
                {
                    printf("%06s\t", dirp->d_name);
                    if(((count+1)%20) == 0)
                        printf("\r\n");

                    count++;
                    int temp = atoi(dirp->d_name);
                    if(temp == pid)
                    {
                        printf("\r\nFound Current Process.\r\n");
                    }
                }
            }
        }
    }

    printf("total process count:%d\r\n", count);
    closedir(dp);
/*
    sleep(30*60);
*/
    return 0;
}

/*
 *cat status
Name:	process
Umask:	0002
State:	S (sleeping)
Tgid:	6796
Ngid:	0
Pid:	6796
PPid:	5212
TracerPid:	0
Uid:	1000	1000	1000	1000
Gid:	1000	1000	1000	1000
FDSize:	1024
Groups:	4 24 27 30 46 116 126 1000
NStgid:	6796
NSpid:	6796
NSpgid:	6796
NSsid:	1434
VmPeak:	    4512 kB
VmSize:	    4512 kB
VmLck:	       0 kB
VmPin:	       0 kB
VmHWM:	     796 kB
VmRSS:	     796 kB
RssAnon:	      64 kB
RssFile:	     732 kB
RssShmem:	       0 kB
VmData:	     176 kB
VmStk:	     132 kB
VmExe:	       4 kB
VmLib:	    2116 kB
VmPTE:	      56 kB
VmSwap:	       0 kB
HugetlbPages:	       0 kB
CoreDumping:	0
THP_enabled:	1
Threads:	1
SigQ:	0/15435
SigPnd:	0000000000000000
ShdPnd:	0000000000000000
SigBlk:	0000000000000004
SigIgn:	0000000000000000
SigCgt:	0000000000000000
CapInh:	0000000000000000
CapPrm:	0000000000000000
CapEff:	0000000000000000
CapBnd:	0000003fffffffff
CapAmb:	0000000000000000
NoNewPrivs:	0
Seccomp:	0
Speculation_Store_Bypass:	thread vulnerable
Cpus_allowed:	ffffffff,ffffffff,ffffffff,ffffffff
Cpus_allowed_list:	0-127
Mems_allowed:	00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000001
Mems_allowed_list:	0
voluntary_ctxt_switches:	1
nonvoluntary_ctxt_switches:	13
 */