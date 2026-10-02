#include <stdio.h>

int main()
{
    int n, i, time = 0, completed = 0;
    int at[20], bt[20], rt[20];
    int ct[20], tat[20], wt[20];
    int min, shortest;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input
    for (i = 0; i < n; i++)
    {
        printf("\nEnter Arrival Time of P%d: ", i + 1);
        scanf("%d", &at[i]);

        printf("Enter Burst Time of P%d: ", i + 1);
        scanf("%d", &bt[i]);

        rt[i] = bt[i];   // Remaining Time
    }

    // SJF Preemptive / SRTF
    while (completed != n)
    {
        min = 9999;
        shortest = -1;

        // Find process with shortest remaining time
        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && rt[i] > 0)
            {
                if (rt[i] < min)
                {
                    min = rt[i];
                    shortest = i;
                }
            }
        }

        // If no process has arrived
        if (shortest == -1)
        {
            time++;
            continue;
        }

        // Execute selected process for 1 unit
        rt[shortest]--;
        time++;

        // If process completes
        if (rt[shortest] == 0)
        {
            completed++;

            ct[shortest] = time;

            tat[shortest] = ct[shortest] - at[shortest];

            wt[shortest] = tat[shortest] - bt[shortest];

            avg_tat += tat[shortest];
            avg_wt += wt[shortest];
        }
    }

    // Display results
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1,
               at[i],
               bt[i],
               ct[i],
               tat[i],
               wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f ms",
           avg_wt / n);

    printf("\nAverage Turnaround Time = %.2f ms",
           avg_tat / n);

    return 0;
}
