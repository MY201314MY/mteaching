#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

char messagebox[128] = {0};
typedef struct {
    sem_t sem;
    char *p;
} mail_t;

mail_t mail;

char *str[] = {
        "quit",
        "ABC",
        "muyuan",
        "embedded",
        "system",
        "come in, please!"
};

void producer()
{
    unsigned char count = 6;

    while(count--){
        strcpy(mail.p, str[count]);
        sem_post(&mail.sem);
        sleep(1);
    }

    puts("bye-bye");
}

void consumer()
{
    while(1){
        sem_wait(&mail.sem);
        printf("recv:len=%d\r\npayload:%s\r\n", strlen(mail.p), mail.p);

        if(!strcmp("quit", mail.p))
        {
            printf("Quit the thread!\r\n");
            break;
        }
    }
}

int main(int argc, char *argv[]) {

    puts("- - - - thread - - - -");
    mail.p = messagebox;

    pthread_t thread1, thread2;

    sem_init(&mail.sem, 0, 0);

    pthread_create(&thread1, NULL, (void *)producer, NULL);
    pthread_create(&thread2, NULL, (void *)consumer, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    sem_destroy(&mail.sem);

    printf("-- End --\r\n");

    return 0;
}