#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	puts("- - - - CPU Temperature - - - -");
	
	FILE *file;
	char buffer[32]={0};
	float temperature = 0;

	file = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
	if(file == NULL){
		perror("fopen failed\r\n");
		exit(1);
	}

	fgets(buffer, sizeof buffer, file);
	temperature = atoi(buffer)*1.0/1000;
	fclose(file);

	printf("temp:%.1f℃\r\n", temperature);
		
	return 0;
}