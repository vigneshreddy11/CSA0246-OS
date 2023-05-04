#include <stdio.h>

#define MAX_BLOCKS 100
#define MAX_PROCESSES 100

void bestFit(int blocks[], int m, int processes[], int n) {
    int allocation[MAX_PROCESSES] = {-1};
    for (int i = 0; i < n; i++) {
        int best_index = -1;
        for (int j = 0; j < m; j++) {
            if (blocks[j] >= processes[i]) {
                if (best_index == -1 || blocks[j] < blocks[best_index]) {
                    best_index = j;
                }
            }
        }
        if (best_index != -1) {
            allocation[i] = best_index;
            blocks[best_index] -= processes[i];
        }
    }
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i+1, processes[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i]+1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    int m, n;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    int blocks[MAX_BLOCKS];
    printf("Enter the size of each memory block:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &blocks[i]);
    }
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int processes[MAX_PROCESSES];
    printf("Enter the size of each process:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &processes[i]);
    }
    bestFit(blocks, m, processes, n);
    return 0;
}
