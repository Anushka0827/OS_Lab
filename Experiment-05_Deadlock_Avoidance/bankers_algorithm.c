#include <stdio.h>

int main() {
    int n, m;
    int allocation[10][10], max[10][10], need[10][10];
    int available[10], work[10];
    int finish[10] = {0};
    int safeSequence[10];
    int count = 0;

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
        work[j] = available[j];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    while (count < n) {
        int found = 0;

        for (int i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int possible = 1;

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
        printf("\nSystem is in SAFE state.\n");
        printf("Safe Sequence: ");
        for (int i = 0; i < n; i++) {
            printf("P%d", safeSequence[i]);
            if (i != n - 1)
                printf(" -> ");
        }
        printf("\n");
    } else {
        printf("\nSystem is NOT in a safe state.\n");
    }

    return 0;
}
