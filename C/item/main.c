#include <stdio.h>
#include <stdlib.h>
#include "qr_encode.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char *input = "1d001f001047";
unsigned char bitdata[2048];

void displayQRCode(int side, uint8_t *bitdata)
{
	int i=0;
	int j=0;
	int a=0;
	int l=0;
	int n=0;
	int OUT_FILE_PIXEL_PRESCALER=1;
	
	for (i = 0; i < side; i++) {

		for (j = 0; j < side; j++) {
			a = j * side + i;

			if ((bitdata[a / 8] & (1 << (7 - a % 8))))
			{
				for (l = 0; l < OUT_FILE_PIXEL_PRESCALER; l++)
				{
					for (n = 0; n < OUT_FILE_PIXEL_PRESCALER; n++)
					{
						putchar('#');
					}
				}
			}
			else
				putchar(' ');
			}
		putchar('\n');
	}
}

int main(int argc, char *argv[]) {
	
	int side = qr_encode(QR_LEVEL_H, 0, input, 0, bitdata);
	
	printf("side:%d\r\n", side);
	
	displayQRCode(side, bitdata);
	
	return 0;
}
