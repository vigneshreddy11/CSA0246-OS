#include <stdio.h>
#include <stdlib.h>

typedef struct process {
    int pid;        // process id
    int arrival;    // arrival time
    int burst;      // burst time
    int priority;   // priority
    int waiting;    // waiting time
    int turnaround; // turnaround time
    int remaining;  // remaining time
} Process;

// find the highest priority process at a given time
int highest_priority(Process* processes, int n, int time) {
    int highest_priority = -1;
    int highest_priority_value = 0;
    for (int i = 0; i < n; i++) {
        if (processes[i].arrival <= time && processes[i].remaining > 0) {
            if (processes[i].priority > highest_priority_value) {
                highest_priority_value = processes[i].priority;
                highest_priority = i;
            }
        }
    }
    return highest_priority;
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process* processes = (Process*) malloc(n * sizeof(Process));
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time, burst time and priority for process %d: ", i+1);
        scanf("%d %d %d", &processes[i].arrival, &processes[i].burst, &processes[i].priority);
        processes[i].pid = i+1;
        processes[i].remaining = processes[i].burst;
    }

    int time = 0;
    int completed = 0;
    while (completed < n) {
        int i = highest_priority(processes, n, time);
        if (i == -1) {
            time++;
        } else {
            processes[i].remaining--;
            time++;
            if (processes[i].remaining == 0) {
                completed++;
                processes[i].turnaround = time - processes[i].arrival;
                processes[i].waiting = processes[i].turnaround - processes[i].burst;
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

    printf("\nProcess\tArrival\tBurst\tPriority\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n", processes[i].pid, processes[i].arrival, processes[i].burst, processes[i].priority, processes[i].waiting, processes[i].turnaround);
    }
    printf("Average waiting time: %.2f\n", avg_waiting);
    printf("Average turnaround time: %.2f\n", avg_turnaround);

    free(processes);

    return 0;
}
