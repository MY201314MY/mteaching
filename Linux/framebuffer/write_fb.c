#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/kd.h>
#include <sys/ioctl.h>
#include <time.h>
#include <linux/fb.h>
#include <sys/mman.h>

int main(){
    int fp=0;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    unsigned long screensize=0;

    char *fbp=0;
    int x=0,y=0;
    long i=0, j=0;


    printf("Hello,world.\n");
    fp = open ("/dev/fb0",O_RDWR);    
    if(!fp){
        printf("error");
        exit(1);
    }

    printf("The frame was opened successfully.\n");

    if(ioctl(fp, FBIOGET_VSCREENINFO, &vinfo)){
        printf("error reading variable information\n");
        exit(1);
    }

    if(ioctl(fp, FBIOGET_FSCREENINFO, &finfo)){
        printf("error");
        exit(1);
    }
    
    printf("Basic: %dx%d, %dbpp\n", vinfo.xres, vinfo.yres, vinfo.bits_per_pixel);
    printf("The memory is:%d (1920*1080*4)\nline length:%d(1920*4)\n", finfo.smem_len, finfo.line_length);
    if(vinfo.bits_per_pixel != 32){
        printf("not support!\n");
        exit(1);
    }
    screensize = vinfo.xres*vinfo.yres*vinfo.bits_per_pixel/8;
    fbp = (char*)mmap(0, screensize, PROT_READ|PROT_WRITE, MAP_SHARED, fp, 0);
    if((int)fbp == -1){
        printf("failed to map.\n");
        exit(4);
    }
    printf("frame was mapped.\n");

    for(i=0;i<100;i++){
        for(j=640;j<740;j++){
            *((unsigned int *)fbp+i*1920+j) = 0x000000FF;
        }
        usleep(5000);
    }

    for(i=100;i<200;i++){
        for(j=740;j<840;j++){
            *((unsigned int *)fbp+i*1920+j) = 0x0000FF00;
        }
        usleep(5000);
    }
    
    for(i=200;i<300;i++){
        for(j=840;j<940;j++){
            *((unsigned int *)fbp+i*1920+j) = 0x00FF0000;
        }
        usleep(5000);
    }
  
    munmap(fbp, screensize);
    close(fp);
    printf("bye-bye");
    
    return 0;
}