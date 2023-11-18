#include <stdio.h>



int main() {
    int n;
    printf("Enter the number of process: ");
    scanf("%d", &n);

    int id[n];
    int bt[n];
    int at[n];
    int time_quantum;
    int rt[n];
    int ct[n];
    int tat[n];
    int wt[n];
    int time = 0;
    int completed = 0;

    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);

     for (int i = 0; i < n; i++) {
        id[i] = i + 1;
        printf("Process P%d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    // Main loop for Round Robin scheduling
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                if (rt[i] <= time_quantum) {
                    time += rt[i];
                    rt[i] = 0;
                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    printf("Process %d completed at time %d\n", i + 1, ct[i]);
                    completed++;
                } else {
                    time += time_quantum;
                    rt[i] -= time_quantum;
                    printf("Process %d executed at time %d\n", i + 1, time);
                }
            }
        }
    }

    // Display the table
    printf("\nProcess\tBurst Time\tArrival Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", id[i], bt[i], at[i], ct[i], tat[i], wt[i]);
    }

    // Calculate and display average turnaround time and waiting time
    float avg_tat = 0, avg_wt = 0;
    for (int i = 0; i < n; i++) {
        avg_tat += tat[i];
        avg_wt += wt[i];
    }
    avg_tat /= n;
    avg_wt /= n;
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);
    printf("Average Waiting Time: %.2f\n", avg_wt);

   

    return 0;
}
