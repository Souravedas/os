#include <stdio.h>

// Function to perform Shortest Job First scheduling
void sjf(int n);

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    sjf(n);

    return 0;
}

// Function to perform Shortest Job First scheduling
void sjf(int n) {
    int processes[n]; // Array to store burst time for each process
    int arrival_time[n]; // Array to store arrival time for each process
    int completion_time[n]; // Array to store completion time for each process
    int turnaround_time[n]; // Array to store turnaround time for each process
    int waiting_time[n]; // Array to store waiting time for each process

    // Input burst time and arrival time for each process
    for (int i = 0; i < n; i++) {
        printf("Process P%d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &arrival_time[i]);
        printf("Burst Time: ");
        scanf("%d", &processes[i]);
    }

    int time = 0; // Current time
    int total_ct = 0; // Total completion time
    int total_tat = 0; // Total turnaround time
    int total_wt = 0; // Total waiting time

    int executed[n]; // Array to track if a process has been executed

    for (int i = 0; i < n; i++) {
        executed[i] = 0;
    }

    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    int completed_processes = 0; // Track the number of completed processes

    while (completed_processes < n) {
        int min_bt = __INT_MAX__;
        int min_burst_index = -1;

        for (int i = 0; i < n; i++) {
            if (!executed[i] && arrival_time[i] <= time && processes[i] < min_bt) {
                min_bt = processes[i];
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
            time += processes[i];
            completion_time[i] = time;
            turnaround_time[i] = completion_time[i] - arrival_time[i];
            waiting_time[i] = turnaround_time[i] - processes[i];

            total_ct++;
            total_tat += turnaround_time[i];
            total_wt += waiting_time[i];
            completed_processes++;

            printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrival_time[i],
                   processes[i], completion_time[i],
                   turnaround_time[i], waiting_time[i]);
        }
    }

    float avg_tat = (float)total_tat / n;
    float avg_wt = (float)total_wt / n;

    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);
    printf("Average Waiting Time: %.2f\n", avg_wt);
}
