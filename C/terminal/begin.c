#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <Windows.h>

static void SetPos(int x, int y)
{
	COORD point = {x, y};
	
	HANDLE HOutput = GetStdHandle(STD_OUTPUT_HANDLE); 
	SetConsoleCursorPosition(HOutput, point);
}

int main(int argc, char *argv[]) {
	int i=0;
	int j=0;
	int k=0;
	char buffer[6]={'@', '#', '$', '%', '&', 'M'};
	
	printf("- - - OLED 128*64 - - -\r\n\r\n");
	for(i=0;i<sizeof buffer;i++)
	{
		for(j=0;j<64;j++)
		{
			printf("\r");
			for(k=0;k<256;k++)
				printf("%c", buffer[i]);
			printf("\r\n");
		}
		if(i<(sizeof buffer)-1)
			SetPos(0, 2);	
	}
	
	return 0;
}