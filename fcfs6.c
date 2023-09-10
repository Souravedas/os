#include <stdio.h>

// Function to perform FCFS scheduling
void fcfs(int n) {
    int at[n]; // Array to store arrival time for each process
    int bt[n]; // Array to store burst time for each process
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
    }

    int current_time = 0; // Current time
    float total_tat = 0;
    float total_wt = 0;

    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    for (int i = 0; i < n; i++) {
        // Wait for the process to arrive if necessary
        if (current_time < at[i]) {
            current_time = at[i];
        }

        // Update completion time
        ct[i] = current_time + bt[i];

        // Update turnaround time and waiting time
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        // Update total turnaround and waiting times
        total_tat += tat[i];
        total_wt += wt[i];

        // Print process details
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);

        // Update current time
        current_time = ct[i];
    }

    // Calculate and print average turnaround and waiting times
    float avg_tat = total_tat / n;
    float avg_wt = total_wt / n;
    printf("\nAverage Turnaround Time: %.2f", avg_tat);
    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
}


int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    fcfs(n);

    return 0;
}

