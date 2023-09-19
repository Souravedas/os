#include <stdio.h>
#include <limits.h>

// Function to perform Non-preemptive Priority Scheduling

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n]; // Array to store arrival time for each process
    int bt[n]; // Array to store burst time for each process
    int priority[n]; // Array to store priority for each process
    int ct[n]; // Array to store completion time for each process
    int tat[n]; // Array to store turnaround time for each process
    int wt[n]; // Array to store waiting time for each process
    int rt[n];//Array to store burst time for each process

    // Input arrival time, burst time, and priority for each process
    for (int i = 0; i < n; i++) {
        printf("Process P%d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
        printf("Priority: ");
        scanf("%d", &priority[i]);
    }

    int current_time = 0; // Current time
    int completed = 0; // Counter for completed processes

    printf("Process\t\tPriority\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    while (completed < n) {
        int highest_priority = INT_MAX;
        int index = -1;

        // Find the process with the highest priority that has arrived
        for (int i = 0; i < n; i++) {
            if (at[i] <= current_time && priority[i] < highest_priority && rt[i] > 0) {
               highest_priority = priority[i];
                index = i;
            }
        }

        if (index != -1) {
            // Execute the process with the highest priority
            current_time += bt[index];
            ct[index] = current_time;
            tat[index] = ct[index] - at[index];
            wt[index] = tat[index] - bt[index];
            rt[index] = 0;
            completed++;

            
           
        }
		 else {
          current_time++;
        }
    }

    // Calculate and print average turnaround and waiting times
    float total_tat = 0;
    float total_wt = 0;
    for (int i = 0; i < n; i++) {
    	 printf("P%d\t\t  %d\t\t  %d\t\t  %d\t\t  %d\t\t  %d\t\t  %d\n",i + 1,priority[i], at[i], bt[i],ct[i], tat[i], wt[i]);
        total_tat += tat[i];
        total_wt += wt[i];
    }

    float avg_tat = total_tat / n;
    float avg_wt = total_wt / n;

    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);
    printf("Average Waiting Time: %.2f\n", avg_wt);

    return 0;
}
