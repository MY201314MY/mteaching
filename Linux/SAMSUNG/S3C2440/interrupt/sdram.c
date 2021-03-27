#include "uart.h"
#include "S3C2440.h"

#define Anoter_block_memory (64*1024*1024)
/*
    2^10 = 1024      1Kb
    2^20 = 1024*1024 1M 20/4=5 300FFFFF
                               348FFFFF
*/
void sdram_init(){
    BWSCON &=~((15<<24) |(15<<28));
    BWSCON |= (( 2<<24) | (2<<28));

    BANKCON6 &= ~((3<<2) | (3<<0));
    BANKCON6 |= ((0<<2) | (1<<0));
    BANKCON7 &= ~((3<<2) | (3<<0));
    BANKCON7 |= ((0<<2) | (1<<0));

    REFRESH &= ~((3<<20) | (3<<18));
    REFRESH |= ((1<<18) | (0x04F5<<0));

    BANKSIZE &= ~((0xFF<<0));
    BANKSIZE |=  ((11<<4) | (1<<0));

    MRSRB6 &= ~((7<<0));
    MRSRB6 |= (2<<0) ;
    MRSRB7 &= ~((7<<0));
    MRSRB7 |= (2<<0) ;
}
#ifdef DEBUG
void example_64M(){
	volatile unsigned int i = 0;
    volatile unsigned char *p = (volatile unsigned char *)0x30000000;

	for (i=0;i<64*1024*1024;i++){
		p[i] = 0x55;
		if(i%(1024*1024)==0){
			putchar('#');
		}
	}
	puts("\r\nWrite done.\r\n");
	for (i=0;i<64*1024*1024;i++){
		if(p[i] != 0x55){
			puts("error!!!\r\n");
		}
		if(i%(1024*1024)==0){
			puts(".");
		}
	}

	puts("\r\nGame over!\r\n");

}

void example_another_64M(){
	volatile unsigned int i = 0;
    volatile unsigned char *p = (volatile unsigned char *)0x30000000 + Anoter_block_memory-26;


	for (i=0;i<26;i++){
		p[i] = 97+i;
	}
	puts("\r\nWrite done.\r\n");
	for (i=0;i<26;i++){
		putchar(p[i]);
	}

	puts("\r\nGame over!\r\n");

}
#endif
