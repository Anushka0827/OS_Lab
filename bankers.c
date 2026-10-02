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

    // Allocation Matrix
    printf("\nEnter Allocation Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Maximum Matrix
    printf("\nEnter Maximum Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Available Resources
    printf("\nEnter Available Resources:\n");
    for (int j = 0; j < m; j++) {
        scanf("%d", &available[j]);
        work[j] = available[j];
    }

    // Calculate Need Matrix
    // Need = Max - Allocation
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Banker's Algorithm
    while (count < n) {
        int found = 0;

        for (int i = 0; i < n; i++) {

            if (finish[i] == 0) {
                int possible = 1;

                // Check if Need <= Available
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        possible = 0;
                        break;
                    }
                }

                // If process can execute
                if (possible) {

                    // Release its allocated resources
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

        // No process could execute
        if (found == 0) {
            break;
        }
    }

    // Check whether system is safe
    if (count == n) {
        printf("\nSystem is in SAFE state.\n");

        printf("Safe Sequence: ");

        for (int i = 0; i < n; i++) {
            printf("P%d", safeSequence[i]);

            if (i != n - 1)
                printf(" -> ");
        }

        printf("\n");
    }
    else {
        printf("\nSystem is NOT in a safe state.\n");
    }

    return 0;
}
