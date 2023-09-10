#include <stdio.h>
#include <limits.h>

// Function to perform Preemptive Shortest Remaining Time First scheduling
void srtf(int n);

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    srtf(n);

    return 0;
}

// Function to perform Preemptive Shortest Remaining Time First scheduling
void srtf(int n) {
    int at[n]; // Array to store arrival time for each process
    int bt[n]; // Array to store burst time for each process
    int rt[n]; // Array to store remaining time for each process
    int ct[n]; // Array to store completion time for each process
    int tat[n]; // Array to store turnaround time for each process
    int wt[n]; // Array to store waiting time for each process

    // Input arrival time and burst time for each process
    for (int i = 0; i < n; i++) {
        printf("Process P%d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; // Initialize remaining time to burst time
    }

    int current_time = 0; // Current time
    int completed = 0; // Counter for completed processes
    int min_rt_index; // Index of the process with the minimum remaining time

    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    while (completed < n) {
        int min_rt = INT_MAX;

        // Find the process with the minimum remaining time
        for (int i = 0; i < n; i++) {
            if (at[i] <= current_time && rt[i] < min_rt && rt[i] > 0) {
                min_rt = rt[i];
                min_rt_index = i;
            }
        }

        // No process found to execute
        if (min_rt == INT_MAX) {
            current_time++;
            continue;
        }

        // Execute the process with the minimum remaining time for one time unit
        rt[min_rt_index]--;

        if (rt[min_rt_index] == 0) {
            completed++;
            ct[min_rt_index] = current_time + 1;
            tat[min_rt_index] = ct[min_rt_index] - at[min_rt_index];
            wt[min_rt_index] = tat[min_rt_index] - bt[min_rt_index];

            // Update total turnaround and waiting times
            current_time = ct[min_rt_index];
        } else {
            current_time++;
        }
    }

    // Print process details
    float total_tat = 0;
    float total_wt = 0;
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
        total_tat += tat[i];
        total_wt += wt[i];
    }

    // Calculate and print average turnaround and waiting times
    float avg_tat = total_tat / n;
    float avg_wt = total_wt / n;
    printf("\nAverage Turnaround Time: %.2f", avg_tat);
    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
}
