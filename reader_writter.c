#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int readcount = 0;
int data = 0;

sem_t mutex;
sem_t wrt;

/* READER */
void *reader(void *arg)
{
    int id = *(int *)arg;

    // wait(mutex)
    sem_wait(&mutex);

    // readcount++
    readcount++;

    // if(readcount == 1)
    if (readcount == 1)
    {
        // wait(wrt)
        sem_wait(&wrt);
    }

    // signal(mutex)
    sem_post(&mutex);

    // Reading is performed
    printf("Reader %d is reading data = %d\n", id, data);

    sleep(1);

    // wait(mutex)
    sem_wait(&mutex);

    // readcount--
    readcount--;

    // if(readcount == 0)
    if (readcount == 0)
    {
        // signal(wrt)
        sem_post(&wrt);
    }

    // signal(mutex)
    sem_post(&mutex);

    return NULL;
}


/* WRITER */
void *writer(void *arg)
{
    int id = *(int *)arg;

    // wait(wrt)
    sem_wait(&wrt);

    // Writing is performed
    data++;

    printf("Writer %d is writing data = %d\n", id, data);

    sleep(1);

    // signal(wrt)
    sem_post(&wrt);

    return NULL;
}


int main()
{
    pthread_t r1, r2, w1;

    int reader1 = 1;
    int reader2 = 2;
    int writer1 = 1;

    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    // Create threads
    pthread_create(&r1, NULL, reader, &reader1);
    pthread_create(&r2, NULL, reader, &reader2);
    pthread_create(&w1, NULL, writer, &writer1);

    // Wait for threads
    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(w1, NULL);

    return 0;
}
