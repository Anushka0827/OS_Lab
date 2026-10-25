#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t num_pid = fork();

    if (num_pid < 0) {
        printf("Error in fork execution\n");
    } 
    else if (num_pid == 0) {
        printf("Child process id: %d\n", getpid());
        printf("Parent process id: %d\n", getppid());
    } 
    else {
        printf("Parent id: %d\n", getpid());
        wait(NULL);
    }

    return 0;
}
