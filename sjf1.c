#include <stdio.h>

// Function to perform Shortest Job First scheduling
void sjf(int n) {
    int bt[n]; 
    int at[n];
    int ct[n]; 
    int tat[n]; 
    int wt[n]; 

    // Input burst time and arrival time for each process
    for (int i = 0; i < n; i++) {
        printf("Process P%d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
    }

    int time = 0;
    int total_ct = 0; 
    int total_tat = 0;
    int total_wt = 0; 

    int executed[n]; // Array to track if a process has been executed

    for (int i = 0; i < n; i++) {
        executed[i] = 0;
    }

    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    while (1) {
        int min_bt = __INT_MAX__;
        int min_burst_index = -1;

        for (int i = 0; i < n; i++) {
            if (!executed[i] && at[i] <= time && bt[i] < min_bt) {
                min_bt = bt[i];
                min_burst_index = i;
            }
        }

        if (min_burst_index == -1) {
            // No process can be executed at this time
            time++;
        } else {
            // Execute the process
            int i = min_burst_index;
            executed[i] = 1;
            time += bt[i];
            ct[i] = time;
            tat[i] = ct[i] - at[i];
            wt[i] = tat[i] - bt[i];

            total_ct += ct[i];
            total_tat += tat[i];
            total_wt += wt[i];

            printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, at[i], bt[i], ct[i],
                   tat[i], wt[i]);
        }

        if (total_ct == n) {
            break; // All bt have completed
        }
    }

    float avg_tat = (float)total_tat / n;
    float avg_wt = (float)total_wt / n;

    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);
    printf("Average Waiting Time: %.2f\n", avg_wt);
}

int main() {
    int n;
    printf("Enter the number of process: ");
    scanf("%d", &n);

    sjf(n);

    return 0;
}


