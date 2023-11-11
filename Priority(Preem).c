#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int highest_priority, lowest_priority;
    printf("Enter the highest priority: ");
    scanf("%d", &highest_priority);
    printf("Enter the lowest priority: ");
    scanf("%d", &lowest_priority);

    int id[n];
    int at[n];
    int bt[n];
    int priority[n];
    int ct[n];
    int tat[n];
    int wt[n];
    int rt[n];

    for (int i = 0; i < n; i++) {
        id[i] = i + 1;
        printf("Process P%d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &priority[i]);
        rt[i] = bt[i];
    }

    int current_time = 0;
    int completed = 0;
    printf("Gantt Chart:\n");

    while (completed < n) {
        int index = -1;
        int selected_priority = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (at[i] <= current_time && rt[i] > 0 && priority[i] >= highest_priority && priority[i] <= lowest_priority) {
                if (priority[i] < selected_priority) {
                    selected_priority = priority[i];
                    index = i;
                }
            }
        }

        if (index != -1) {
            printf("| P%d |", id[index]);
            rt[index]--;

            if (rt[index] == 0) {
                completed++;
                ct[index] = current_time + 1;
				tat[index] = ct[index] - at[index];
                wt[index] = tat[index] - bt[index];
            }

            current_time++;
        } else {
            // If no process can be scheduled, increment the current_time
            current_time++;
        }
    }

    printf("\n");
    printf("Process\t\tPriority\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t\t  %d\t\t  %d\t\t  %d\t\t  %d\t\t  %d\t\t  %d\n", id[i], priority[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    float total_tat = 0;
    float total_wt = 0;

    for (int i = 0; i < n; i++) {
        total_tat += tat[i];
        total_wt += wt[i];
    }

    float avg_tat = total_tat / n;
    float avg_wt = total_wt / n;

    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);
    printf("Average Waiting Time: %.2f\n", avg_wt);

    return 0;
}
