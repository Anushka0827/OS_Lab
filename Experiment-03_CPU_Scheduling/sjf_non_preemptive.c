#include <stdio.h>

int main() {
    int n, i;
    int at[20], bt[20], ct[20], tat[20], wt[20];
    int completed[20] = {0};
    int time = 0, count = 0;
    int shortest;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter Arrival Time of P%d: ", i + 1);
        scanf("%d", &at[i]);

        printf("Enter Burst Time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    while (count < n) {
        shortest = -1;

        for (i = 0; i < n; i++) {
            if (completed[i] == 0 && at[i] <= time) {
                if (shortest == -1 || bt[i] < bt[shortest]) {
                    shortest = i;
                }
            }
        }

        if (shortest == -1) {
            time++;
            continue;
        }

        time = time + bt[shortest];
        ct[shortest] = time;
        tat[shortest] = ct[shortest] - at[shortest];
        wt[shortest] = tat[shortest] - bt[shortest];

        completed[shortest] = 1;
        count++;

        avg_tat += tat[shortest];
        avg_wt += wt[shortest];
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f ms", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f ms\n", avg_tat / n);

    return 0;
}
