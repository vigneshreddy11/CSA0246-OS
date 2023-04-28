#include <stdio.h>
#include <stdbool.h>

#define NUM_PROCESSES 4
#define NUM_RESOURCES 3

int main() {
    int claim[NUM_PROCESSES][NUM_RESOURCES] = {{3, 2, 2}, {6, 1, 3}, {3, 1, 4}, {4, 2, 2}};
    int allocation[NUM_PROCESSES][NUM_RESOURCES] = {{1, 0, 0}, {6, 1, 2}, {2, 1, 1}, {0, 0, 2}};
    int available[NUM_RESOURCES] = {9, 3, 6};
    bool finished[NUM_PROCESSES] = {false};

    // Calculate the need matrix
    int need[NUM_PROCESSES][NUM_RESOURCES];
    for (int i = 0; i < NUM_PROCESSES; i++) {
        for (int j = 0; j < NUM_RESOURCES; j++) {
            need[i][j] = claim[i][j] - allocation[i][j];
        }
    }

    // Find a safe sequence
    int work[NUM_RESOURCES];
    for (int i = 0; i < NUM_RESOURCES; i++) {
        work[i] = available[i];
    }
    int safe_sequence[NUM_PROCESSES];
    int num_safe_processes = 0;
    while (num_safe_processes < NUM_PROCESSES) {
        bool found = false;
        for (int i = 0; i < NUM_PROCESSES; i++) {
            if (!finished[i]) {
                bool can_run = true;
                for (int j = 0; j < NUM_RESOURCES; j++) {
                    if (need[i][j] > work[j]) {
                        can_run = false;
                        break;
                    }
                }
                if (can_run) {
                    for (int j = 0; j < NUM_RESOURCES; j++) {
                        work[j] += allocation[i][j];
                    }
                    safe_sequence[num_safe_processes] = i;
                    num_safe_processes++;
                    finished[i] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            printf("The system is in an unsafe state.\n");
            return 0;
        }
    }

    // Print the safe sequence
    printf("The system is in a safe state. The safe sequence is: ");
    for (int i = 0; i < NUM_PROCESSES; i++) {
        printf("%d ", safe_sequence[i]);
    }
    printf("\n");

    return 0;
}
