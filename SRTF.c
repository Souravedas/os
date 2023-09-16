#include <stdio.h>
#include <limits.h>

void srtf(int n) {
    int at[n]; 
    int bt[n]; 
    int rt[n]; 
    int ct[n]; 
    int tat[n];
    int wt[n]; 

    for (int i = 0; i < n; i++) {
        printf("Process P%d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; 
    }

    int current_time = 0; 
    int completed = 0; 
    int min_rt_index; 

    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    while (completed < n) {
        int min_rt = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (at[i] <= current_time && rt[i] < min_rt && rt[i] > 0) {
                min_rt = rt[i];
                min_rt_index = i;
            }
        }

        rt[min_rt_index]--;

        if (rt[min_rt_index] == 0) {
            completed++;
            ct[min_rt_index] = current_time + 1;
            tat[min_rt_index] = ct[min_rt_index] - at[min_rt_index];
            wt[min_rt_index] = tat[min_rt_index] - bt[min_rt_index];

            current_time = ct[min_rt_index];
        } else {
            current_time++;
        }
    }

    float total_tat = 0;
    float total_wt = 0;
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
        total_tat += tat[i];
        total_wt += wt[i];
    }

    float avg_tat = total_tat / n;
    float avg_wt = total_wt / n;
    printf("\nAverage Turnaround Time: %.2f", avg_tat);
    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    srtf(n);

    return 0;
}



