#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

static sem_t sem;

void producer()
{
	unsigned char count = 6;
	
	while(count--){
		printf("Producer:%d\r\n", count);
        printf("+P:%ld", sem.__align);
		sem_post(&sem);
        printf("-P:%ld", sem.__align);
		sleep(1);	
	}
	puts("bye-bye"); 
}

void consumer()
{
	unsigned char count = 6;
	
	while(count--){
		sem_wait(&sem);
		printf("Consumer:%d\r\n\r\n", count);
	}
}

int main(int argc, char *argv[]) {
	puts("- - - - thread - - - -");
	
	pthread_t thread1, thread2;
	
	sem_init(&sem, 0, 0);
	
	pthread_create(&thread1, NULL, (void *)producer, NULL);
	pthread_create(&thread2, NULL, (void *)consumer, NULL);
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	
	sem_destroy(&sem);
	
	printf("-- End --\r\n\r\n");
		
	return 0;
}