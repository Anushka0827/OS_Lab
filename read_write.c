#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t wrt;
pthread_mutex_t mutex;
int shared_data = 10;
int read_count = 0;

void *writer(void *arg) {
    sem_wait(&wrt);

    shared_data += 5;
    printf("Writer updated shared data to: %d\n", shared_data);
    sleep(1);

    sem_post(&wrt);
    return NULL;
}

void *reader(void *arg) {
    pthread_mutex_lock(&mutex);
    read_count++;
    if (read_count == 1) {
        sem_wait(&wrt);
    }
    pthread_mutex_unlock(&mutex);

    printf("Reader read shared data as: %d\n", shared_data);
    sleep(1);

    pthread_mutex_lock(&mutex);
    read_count--;
    if (read_count == 0) {
        sem_post(&wrt);
    }
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t w1, r1, r2;

    sem_init(&wrt, 0, 1);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&w1, NULL, writer, NULL);
    pthread_create(&r1, NULL, reader, NULL);
    pthread_create(&r2, NULL, reader, NULL);

    pthread_join(w1, NULL);
    pthread_join(r1, NULL);
    pthread_join(r2, NULL);

    sem_destroy(&wrt);
    pthread_mutex_destroy(&mutex);

    return 0;
}
