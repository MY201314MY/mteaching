#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
/*
 * : must attach arg
 * : optional arg and no space
 * no arg
 * */
int main(int argc, char *argv[]) {
    printf("[DRAM Embedded Engineer]\r\n");

    int ch;
    opterr = 0;
    while ((ch = getopt(argc, argv, "a:b::cde")) != -1)
    {
        /*
         * optind:Read Position in argv next.
         * */
        printf("optind:%d\r\n", optind);
        printf("optarg:%s\r\n", optarg);
        printf("char:%c\r\n", ch);

        switch (ch) {
            case 'a':
                printf("option a \"%s\"\r\n", optarg);
                break;
            case 'b':
                printf("option b \"%s\"\r\n", optarg);
                break;
            case 'c':
                printf("option c \"%s\"\r\n", optarg);
                break;
            case 'd':
                printf("option d \"%s\"\r\n", optarg);
                break;
            case 'e':
                printf("option e \"%s\"\r\n", optarg);
                break;
            default:
                printf("other option: %c", ch);
                break;
        }
        printf("----\r\n");
    }

    return 0;
}
