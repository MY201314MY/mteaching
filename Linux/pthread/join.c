#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void mteaching(char *p)
{
	unsigned char count = 6;
	
	while(count--){
		printf("thread:%s", p);
		
		Sleep(1000);	
	}
}

void var(char *p)
{	
	unsigned char count = 6;
	
	while(count--){
		printf("%s: character:%d\r\n", __TIME__, *p);
		Sleep(500);	
	}
}

int main(int argc, char *argv[]) {
	puts("- - - - thread - - - -");
	
	int ret;
	pthread_t thread1, thread2, thread3, thread4;
	char *p1 = "--- ABC ***\r\n";
	char *p2 = "~~~ LMN !!!\r\n";
	char *p3 = "@@@ OPQ %%%\r\n";
	
	char x = 3;
	
	ret = pthread_create(&thread1, NULL, (void *)mteaching, (void *)p1);
	ret = pthread_create(&thread2, NULL, (void *)mteaching, (void *)p2);
	ret = pthread_create(&thread3, NULL, (void *)mteaching, (void *)p3);
	ret = pthread_create(&thread4, NULL, (void *)var, (void *)&x);
	
	pthread_join(thread1, NULL);
	puts("1");
	pthread_join(thread2, NULL);
	puts("2");
	pthread_join(thread3, NULL);
	puts("3");
	pthread_join(thread4, NULL);
	puts("4");
	printf("-- End --");
		
	return 0;
}