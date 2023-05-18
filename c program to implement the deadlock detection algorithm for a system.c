#include <stdio.h>

#define MAX_PROCESSES 3
#define MAX_RESOURCES 3

int is_safe_state(int allocation[MAX_PROCESSES][MAX_RESOURCES], int max[MAX_PROCESSES][MAX_RESOURCES], int available[MAX_RESOURCES]) {
    int i, j, k;
    int work[MAX_RESOURCES];
    int finish[MAX_PROCESSES] = { 0 };
    int need[MAX_PROCESSES][MAX_RESOURCES];

    // Initialize the work and need matrices
    for (i = 0; i < MAX_RESOURCES; i++) {
        work[i] = available[i];
        for (j = 0; j < MAX_PROCESSES; j++) {
            need[j][i] = max[j][i] - allocation[j][i];
        }
    }

    // Find an unallocated process with need <= work
    int found;
    do {
        found = 0;
        for (i = 0; i < MAX_PROCESSES; i++) {
            if (!finish[i]) {
                int can_allocate = 1;
                for (j = 0; j < MAX_RESOURCES; j++) {
                    if (need[i][j] > work[j]) {
                        can_allocate = 0;
                        break;
                    }
                }
                if (can_allocate) {
                    found = 1;
                    // Allocate resources
                    for (k = 0; k < MAX_RESOURCES; k++) {
                        work[k] += allocation[i][k];
                    }
                    finish[i] = 1;
                }
            }
        }
    } while (found);

    // Check if all processes are finished
    for (i = 0; i < MAX_PROCESSES; i++) {
        if (!finish[i]) {
            return 0; // Not a safe state
        }
    }

    return 1; // Safe state
}

int main() {
    int allocation[MAX_PROCESSES][MAX_RESOURCES] = {
        {3, 3, 3},
        {2, 0, 3},
        {1, 2, 4}
    };

    int max[MAX_PROCESSES][MAX_RESOURCES] = {
        {3, 6, 8},
        {4, 3, 3},
        {3, 4, 4}
    };

    int available[MAX_RESOURCES] = {1, 2, 0};

    if (is_safe_state(allocation, max, available)) {
        printf("The system is in a safe state.\n");
    } else {
        printf("The system is in a deadlock state.\n");

        printf("Deadlocked processes: ");
        int i;
        for (i = 0; i < MAX_PROCESSES; i++) {
            if (!is_safe_state(allocation, max, available)) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }

    return 0;
}
