#include "storage.h"

int storage() {
    FILE *fp;
    char ch, filename[32]="mteaching.txt";
#ifdef DEBUG
    puts("Please input the filename:");
    scanf("%s", filename);
#endif

    if(!(fp=fopen(filename,"w"))){
        printf("error!");
        exit(0);
    }
    printf("input:");
    while ((ch=getchar())!='\n'){
        fputc(ch, fp);
        putchar(ch);
    }

    fputs("\nThis is for everyone!", fp);
    fputs("\nThis is designed by Apple in Cal.", fp);
    fclose(fp);
    puts("\r\nEnd...");

    return 0;
}

int read() {
    FILE *fp;
    char filename[32]="mteaching.txt";

#ifdef DEBUG
    puts("Please input the filename:");
    scanf("%s", filename);
#endif

    if(!(fp=fopen(filename,"r"))){
        printf("error!");
        exit(0);
    }

    while (!(feof(fp))){
#ifdef DEBUG
        printf(" -- ");
#endif
        putchar(fgetc(fp));
    }

    fclose(fp);
    puts("\r\nEnd...");

    return 0;
}