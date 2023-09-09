#include <stdio.h>

// Structure to represent a process
struct Process {
    int id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

// Function to perform FCFS scheduling
void fcfs(struct Process processes[], int n) {
    int current_time = 0; // Current time
    float total_tat = 0;
    float total_wt = 0;

    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    for (int i = 0; i < n; i++) {
        // Wait for the process to arrive if necessary
        if (current_time < processes[i].at) {
            current_time = processes[i].at;
        }

        // Update completion time
        processes[i].ct = current_time + processes[i].bt;

        // Update turnaround time and waiting time
        processes[i].tat = processes[i].ct - processes[i].at;
        processes[i].wt = processes[i].tat - processes[i].bt;

        // Update total turnaround and waiting times
        total_tat += processes[i].tat;
        total_wt += processes[i].wt;

        // Print process details
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].id, processes[i].at, processes[i].bt,
               processes[i].ct, processes[i].tat, processes[i].wt);

        // Update current time
        current_time = processes[i].ct;
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

    struct Process processes[n];

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Process P%d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].at);
        printf("Burst Time: ");
        scanf("%d", &processes[i].bt);
    }

    // Sort processes by arrival time (FCFS)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].at > processes[j + 1].at) {
                // Swap processes
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    fcfs(processes, n);

    return 0;
}
