#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp = NULL;
    char pixel[4] = {0};

    printf("Get Image Information.\r\n");

    fp = fopen("image.bin", "rb");
    if(fp == NULL){
        printf("Can't open the file.\n");

        return 0;
    }
    fseek(fp, 380*4*48, 0);
    for(unsigned int i=0;i<390*1*1/10;i++){
        char txt[128] = {0};

        fread(&pixel, sizeof(char), 4, fp);
        sprintf(txt, "R:%03d G:%03d B:%03d U:%03d\n", pixel[0], pixel[1], pixel[2], pixel[3]);
        printf("%s", txt);
    }

    fclose(fp);

    return 0;
}