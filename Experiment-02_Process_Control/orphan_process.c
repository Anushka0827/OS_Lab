#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }
    else if (pid == 0) {
        printf("Child Process ID: %d, Parent Process ID: %d\n", getpid(), getppid());
        sleep(5);
        printf("\nAfter parent exits -> Child Process ID: %d, New Parent ID: %d\n", getpid(), getppid());
    }
    else {
        printf("Parent Process ID: %d exiting...\n", getpid());
        exit(0);
    }

    return 0;
}
