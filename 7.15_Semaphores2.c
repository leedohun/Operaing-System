#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int sum = 0;

sem_t sem;

void *counter(void *param) {
    int k;
    for (k = 0; k < 10000; k++) {
        sem_wait(&sem);
        sum++;
        sem_post(&sem);
    }
    pthread_exit(0);
}

int main() {
    pthread_t tid[5]; int i;
    sem_init(&sem, 0, 5);

    for (i = 0; i < 5; i++)
        pthread_create(&tid[i], NULL, counter, NULL);

    for (i = 0; i < 5; i++)
        pthread_join(tid[i], NULL);
    
    printf("sum = %d\n", sum);
}