#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);

    if (shmid < 0) {
        perror("shmget failed");
        exit(1);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }
    else if (pid > 0) {
        char *str = (char *)shmat(shmid, (void *)0, 0);
        printf("Parent writing to shared memory...\n");
        strncpy(str, "Shared memory IPC communication", SHM_SIZE);
        shmdt(str);

        wait(NULL);

        shmctl(shmid, IPC_RMID, NULL);
    }
    else {
        sleep(1);
        char *str = (char *)shmat(shmid, (void *)0, 0);
        printf("Child read from shared memory: %s\n", str);
        shmdt(str);
        exit(0);
    }

    return 0;
}
