#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	unsigned int i=0, j=0;
	
	unsigned char addr = 0x38;
	
	printf("   ");
	for(j=0;j<=0x0F;j++)
		printf("%3X", j);
	
	for(;i<8;i++ )
	{
		puts("\r\n");
		printf("%X0:", i);
		for(j=0;j<=0x0F;j++)
		{
			if((i*16+j) == addr)
				printf("%3X", addr);
			else{
				if(((i*16+j)>0x02) && ((i*16+j)<0x78))
					printf("%3s", "--");
				else
					printf("%3s", "  ");
			}
			
		}	
	}  
	
	puts("\r\n\r\nI2C Address has been scaned!");
	
	return 0;
}
