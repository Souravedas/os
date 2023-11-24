#include <stdio.h>
#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int available[MAX_RESOURCES];
int maximum[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];

int main() {
    int n, m; // n = number of processes, m = number of resources
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    printf("Enter the available resources: ");
    for (int i = 0; i < m; i++)
        scanf("%d", &available[i]);

    printf("Enter the maximum need:\n");
    for (int i = 0; i < n; i++) {
        printf("For process %d: ", i + 1);
        for (int j = 0; j < m; j++)
            scanf("%d", &maximum[i][j]);
    }

    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("For process %d: ", i + 1);
        for (int j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }

    int work[MAX_RESOURCES];
    int finish[MAX_PROCESSES] = {0}; // Initialize finish array
    int safeSequence[MAX_PROCESSES];
    int count = 0; // Count of processes in the safe sequence

    // Copy available resources to work
    for (int i = 0; i < m; i++)
        work[i] = available[i];

    while (count < n) {
        int found = 0;

        for (int i = 0; i < n; i++) {
            if (finish[i] == 0) {
                // Check if the current process can be satisfied
                int j;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j])
                        break;
                }

                // If all needs are satisfied
                if (j == m) {
                    // Release resources, update work, and mark process as finished
                    for (int k = 0; k < m; k++) {
                        work[k] += allocation[i][k];
                    }
                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        // If no process could be found, the system is not in a safe state
        if (!found) {
            printf("System is not in a safe state\n");
            return 0;
        }
    }

    // If the loop completes, the system is in a safe state
    printf("Safe sequence: ");
    for (int i = 0; i < n-1; i++) {
        printf("P%d--->", safeSequence[i]);
    }
        printf("P%d ", safeSequence[n-1]);

    printf("\n");

    return 1;

    return 0;
}
