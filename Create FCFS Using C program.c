#include <stdio.h>

#define MAX_PROCESSES 100

int main() {
    int num_processes, burst_time[MAX_PROCESSES], waiting_time[MAX_PROCESSES], turnaround_time[MAX_PROCESSES];
    float avg_waiting_time = 0.0, avg_turnaround_time = 0.0;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter the burst time for each process: ");
    for (int i = 0; i < num_processes; i++) {
        scanf("%d", &burst_time[i]);
    }

    // calculate waiting time for each process
    waiting_time[0] = 0;
    for (int i = 1; i < num_processes; i++) {
        waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
    }

    // calculate turnaround time for each process
    for (int i = 0; i < num_processes; i++) {
        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }

    // calculate average waiting time and turnaround time
    for (int i = 0; i < num_processes; i++) {
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_waiting_time /= num_processes;
    avg_turnaround_time /= num_processes;

    // print results
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}
