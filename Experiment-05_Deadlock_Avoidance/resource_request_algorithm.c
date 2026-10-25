#include <stdio.h>

int main() {
    int n, m;
    int allocation[10][10];
    int max[10][10];
    int need[10][10];
    int available[10];
    int request[10];

    int work[10];
    int finish[10] = {0};
    int safeSequence[10];

    int process, count = 0;
    int possible, found;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("\nEnter Allocation Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("\nEnter Maximum Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");
    for (int j = 0; j < m; j++) {
        scanf("%d", &available[j]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    printf("\nEnter process number making request (0 to %d): ", n - 1);
    scanf("%d", &process);

    printf("Enter Resource Request:\n");
    for (int j = 0; j < m; j++) {
        scanf("%d", &request[j]);
    }

    for (int j = 0; j < m; j++) {
        if (request[j] > need[process][j]) {
            printf("\nError: Process requested more than its Need.\n");
            return 0;
        }
    }

    for (int j = 0; j < m; j++) {
        if (request[j] > available[j]) {
            printf("\nResources are not available right now.\n");
            return 0;
        }
    }

    for (int j = 0; j < m; j++) {
        available[j] -= request[j];
        allocation[process][j] += request[j];
        need[process][j] -= request[j];
    }

    for (int j = 0; j < m; j++) {
        work[j] = available[j];
    }

    count = 0;

    while (count < n) {
        found = 0;

        for (int i = 0; i < n; i++) {
            if (finish[i] == 0) {
                possible = 1;

                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        possible = 0;
                        break;
                    }
                }

                if (possible) {
                    for (int j = 0; j < m; j++) {
                        work[j] += allocation[i][j];
                    }

                    safeSequence[count] = i;
                    finish[i] = 1;
                    count++;
                    found = 1;
                }
            }
        }

        if (found == 0) {
            break;
        }
    }

    if (count == n) {
        printf("\nRequest can be GRANTED.\n");
        printf("System is in SAFE state.\n");
        printf("Safe Sequence: ");
        for (int i = 0; i < n; i++) {
            printf("P%d", safeSequence[i]);
            if (i != n - 1)
                printf(" -> ");
        }
        printf("\n");
    } else {
        printf("\nRequest CANNOT be granted.\n");
        printf("System would become UNSAFE.\n");
    }

    return 0;
}
