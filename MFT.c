#include <stdio.h>
int main() {
    int n;
    printf("Enter the number of processes:\n");
    scanf("%d", &n);
    int id[n];
    int mry[n];
    int temp = 0;
    int waste = 0;
    int partitions[n];
    for (int i = 0; i < n; i++) {
        printf("Enter memory partition size for Partition %d: ", i + 1);
        scanf("%d", &partitions[i]);
    }
    for (int i = 0; i < n; i++) {
        id[i] = -1; 
    }
    for (int i = 0; i < n; i++) {
        printf("Enter memory size for P%d: ", i + 1);
        scanf("%d", &mry[i]);
    }
    printf("\nMemory Allocation Summary:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (id[i] == -1 && partitions[j] >= mry[i]) {
                id[i] = j;
                temp = partitions[j] - mry[i];
                waste += temp;
                printf("P%d allocated to Partition %d, Waste %d\n", i + 1, j + 1, temp);
                break;
            }
        }
        if (id[i] == -1) {
            printf("P%d: Waiting (Not enough memory)\n", i + 1);
        }
    }
    printf("\nTotal waste of memory: %d\n", waste);

    return 0;
}
