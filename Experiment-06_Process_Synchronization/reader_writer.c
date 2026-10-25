#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int readcount = 0;
int data = 0;

sem_t mutex;
sem_t wrt;

void *reader(void *arg) {
    int id = *(int *)arg;

    sem_wait(&mutex);
    readcount++;
    if (readcount == 1) {
        sem_wait(&wrt);
    }
    sem_post(&mutex);

    printf("Reader %d is reading data = %d\n", id, data);
    sleep(1);

    sem_wait(&mutex);
    readcount--;
    if (readcount == 0) {
        sem_post(&wrt);
    }
    sem_post(&mutex);

    return NULL;
}

void *writer(void *arg) {
    int id = *(int *)arg;

    sem_wait(&wrt);
    data++;
    printf("Writer %d is writing data = %d\n", id, data);
    sleep(1);
    sem_post(&wrt);

    return NULL;
}

int main() {
    pthread_t r1, r2, w1;
    int reader1 = 1, reader2 = 2, writer1 = 1;

    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    pthread_create(&r1, NULL, reader, &reader1);
    pthread_create(&r2, NULL, reader, &reader2);
    pthread_create(&w1, NULL, writer, &writer1);

    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(w1, NULL);

    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}
