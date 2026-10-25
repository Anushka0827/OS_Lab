#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX 50

int main() {
    int filedes[2], n;
    char string[MAX] = "Hello from parent process!";
    char line[MAX];
    pid_t pid;

    if (pipe(filedes) < 0) {
        printf("Pipe creation error\n");
        exit(1);
    }

    pid = fork();
    if (pid < 0) {
        printf("Fork error\n");
        exit(1);
    } 
    else if (pid > 0) {
        close(filedes[0]);
        write(filedes[1], string, strlen(string) + 1);
        close(filedes[1]);
    } 
    else {
        close(filedes[1]);
        n = read(filedes[0], line, MAX);
        line[n] = '\0';
        printf("Data read by child is: %s\n", line);
        close(filedes[0]);
    }

    return 0;
}
