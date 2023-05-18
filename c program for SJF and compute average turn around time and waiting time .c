#include <stdio.h>

void sjf_scheduling(int processes[], int bursts[], int n, int waiting_time[], int turnaround_time[]) {
    int i, j, min, temp;
    double total_waiting_time = 0, total_turnaround_time = 0;

    // Sort the processes based on their burst time using the selection sort algorithm
    for (i = 0; i < n; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (bursts[j] < bursts[min]) {
                min = j;
            }
        }

        // Swap the processes and bursts
        temp = bursts[i];
        bursts[i] = bursts[min];
        bursts[min] = temp;

        temp = processes[i];
        processes[i] = processes[min];
        processes[min] = temp;
    }

    // Calculate the waiting time and turnaround time for each process
    waiting_time[0] = 0;
    turnaround_time[0] = bursts[0];

    for (i = 1; i < n; i++) {
        waiting_time[i] = bursts[i - 1] + waiting_time[i - 1];
        turnaround_time[i] = bursts[i] + waiting_time[i];
    }

    // Calculate the total waiting time and total turnaround time
    for (i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    // Calculate the average waiting time and average turnaround time
    double avg_waiting_time = total_waiting_time / n;
    double avg_turnaround_time = total_turnaround_time / n;

    printf("Average Waiting Time: %.2lf\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2lf\n", avg_turnaround_time);
}

int main() {
    int n, i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], bursts[n], waiting_time[n], turnaround_time[n];

    printf("Enter the arrival time and burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d:\n", i);
        printf("Arrival Time: ");
        scanf("%d", &processes[i]);
        printf("Burst Time: ");
        scanf("%d", &bursts[i]);
    }

    sjf_scheduling(processes, bursts, n, waiting_time, turnaround_time);

    return 0;
}
