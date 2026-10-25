#include <stdio.h>

int main() {
    int n, i, j;
    int at[20], bt[20], ct[20], tat[20], wt[20], pid[20];
    int temp;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        pid[i] = i + 1;

        printf("Enter Arrival Time of P%d: ", pid[i]);
        scanf("%d", &at[i]);

        printf("Enter Burst Time of P%d: ", pid[i]);
        scanf("%d", &bt[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    ct[0] = at[0] + bt[0];

    for (i = 1; i < n; i++) {
        if (ct[i - 1] < at[i]) {
            ct[i] = at[i] + bt[i];
        } else {
            ct[i] = ct[i - 1] + bt[i];
        }
    }

    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f ms", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f ms\n", avg_tat / n);

    printf("\nGantt Chart:\n");
    for (i = 0; i < n; i++) {
        printf("|  P%d  ", pid[i]);
    }
    printf("|\n");

    printf("%d", at[0]);
    for (i = 0; i < n; i++) {
        printf("\t%d", ct[i]);
    }
    printf("\n");

    return 0;
}
