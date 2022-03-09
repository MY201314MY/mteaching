#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>

int main(){
    int fp=0;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;

    printf("Hello,world.\n");
    fp = open ("/dev/fb0",O_RDWR);    
    printf("%d\n", fp);

    ioctl(fp, FBIOGET_FSCREENINFO, &finfo);
    ioctl(fp, FBIOGET_VSCREENINFO, &vinfo);

    printf("The memory is:%d\nline length:%d", finfo.smem_len, finfo.line_length);
    printf("The xres is %d, the yres is%d\n", vinfo.xres, vinfo.yres);
    printf("bits_per_pixel is:%d\n", vinfo.bits_per_pixel);

    close(fp);

    return 0;
}