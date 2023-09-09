#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

// Structure to represent a process
struct Process {
    int id;             // Process ID
    int at;   // Arrival Time
    int bt;     // Burst Time
    int ct; // Completion Time
    int tat; // Turnaround Time
    int wt;    // Waiting Time
};

// Function to swap two processes
void swap(struct Process* a, struct Process* b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform Shortest Job First scheduling
void sjf(struct Process processes[], int n) {
    // Sort processes by arrival time and burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].at > processes[j + 1].at ||
                (processes[j].at == processes[j + 1].at &&
                 processes[j].bt > processes[j + 1].bt)) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }

    int time = 0;                 // Current time
    int total_ct = 0; // Total completion time
    int total_tat = 0; // Total turnaround time
    int total_wt = 0;    // Total waiting time
    bool executed[n];             // Array to track if a process has been executed

    for (int i = 0; i < n; i++) {
        executed[i] = false;
    }

    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    while (true) {
        int min_bt = INT_MAX;
        int min_burst_index = -1;

        for (int i = 0; i < n; i++) {
            if (!executed[i] && processes[i].at <= time &&
                processes[i].bt < min_bt) {
                min_bt = processes[i].bt;
                min_burst_index = i;
            }
        }

        if (min_burst_index == -1) {
            // No process can be executed at this time
            time++;
        } else {
            // Execute the process
            int i = min_burst_index;
            executed[i] = true;
            time += processes[i].bt;
            processes[i].ct = time;
            processes[i].tat = processes[i].ct - processes[i].at;
            processes[i].wt = processes[i].tat - processes[i].bt;

            total_ct += processes[i].ct;
            total_tat += processes[i].tat;
            total_wt += processes[i].wt;

            printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].at,
                   processes[i].bt, processes[i].ct,
                   processes[i].tat, processes[i].wt);
        }

        if (total_ct == n) {
            break; // All processes have completed
        }
    }

    float avg_tat = (float)total_tat / n;
    float avg_wt = (float)total_wt / n;

    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);
    printf("Average Waiting Time: %.2f\n", avg_wt);
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

    sjf(processes, n);

    return 0;
}
