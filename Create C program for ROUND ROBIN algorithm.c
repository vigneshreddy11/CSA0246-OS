#include <stdio.h>
#include <stdlib.h>

typedef struct process {
    int pid;        // process id
    int burst;      // burst time
    int remaining;  // remaining burst time
    int waiting;    // waiting time
    int turnaround; // turnaround time
} Process;

int main() {
    int n, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    Process* processes = (Process*) malloc(n * sizeof(Process));
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i+1);
        scanf("%d", &processes[i].burst);
        processes[i].pid = i+1;
        processes[i].remaining = processes[i].burst;
        processes[i].waiting = -1;
        processes[i].turnaround = -1;
    }

    int time = 0;
    int completed = 0;
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining > 0) {
                int execute_time = processes[i].remaining < quantum ? processes[i].remaining : quantum;
                processes[i].remaining -= execute_time;
                time += execute_time;
                if (processes[i].remaining == 0) {
                    completed++;
                    processes[i].turnaround = time;
                    processes[i].waiting = processes[i].turnaround - processes[i].burst;
                }
            }
        }
    }

    float avg_waiting = 0, avg_turnaround = 0;
    for (int i = 0; i < n; i++) {
        avg_waiting += processes[i].waiting;
        avg_turnaround += processes[i].turnaround;
    }
    avg_waiting /= n;
    avg_turnaround /= n;

    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].burst, processes[i].waiting, processes[i].turnaround);
    }
    printf("Average waiting time: %.2f\n", avg_waiting);
    printf("Average turnaround time: %.2f\n", avg_turnaround);

    free(processes);

    return 0;
}
