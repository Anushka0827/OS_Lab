#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

pid_t num_pid;

int main() {
    num_pid = fork();

    if (num_pid < 0) {
        printf("Error in fork execution\n");
    } 
    else if (num_pid == 0) {
        // Child Process execution
        printf("This is the child process id: %d\n", getpid());
        printf("This is the parent of this child process id: %d\n", getppid());
    } 
    else {
        // Parent Process execution
        printf("This is parent id: %d\n", getpid());
        wait(NULL); // Parent pauses here until child exits!
    }

    return 0;
}
