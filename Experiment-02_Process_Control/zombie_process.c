#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork error\n");
        return 1;
    }
    else if (pid == 0) {
        printf("Child process exiting, PID: %d\n", getpid());
        exit(0);
    }
    else {
        sleep(5);
        printf("Parent process waking up, PID: %d\n", getpid());
        system("ps -l | grep Z || ps -eo pid,ppid,stat,cmd | grep '[Zz]'");
    }

    return 0;
}
