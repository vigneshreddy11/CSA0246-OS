#include<stdio.h>
#include<stdlib.h>

// Process structure
struct process {
    char name[5];  // Process name
    int arrival_time;  // Arrival time of the process
    int burst_time;  // Burst time of the process
    int remaining_time;  // Remaining time of the process
    int start_time;  // Start time of the process
    int completion_time;  // Completion time of the process
    int waiting_time;  // Waiting time of the process
    int turnaround_time;  // Turnaround time of the process
};

int main() {
    int n, i, j, time, smallest;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    struct process p[10], temp;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input process details
    for(i=0; i<n; i++) {
        printf("Enter the details of process %d\n", i+1);
        printf("Name: ");
        scanf("%s", &p[i].name);
        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &p[i].burst_time);
        p[i].remaining_time = p[i].burst_time;
    }

    // Sort the processes in ascending order of arrival time
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(p[j].arrival_time > p[j+1].arrival_time) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    int completed = 0, prev = 0;
    printf("\nGantt Chart\n");
    printf("-----------\n");
    printf("0");
    for(time=0; completed!=n; time++) {
        smallest = -1;
        for(i=0; i<n; i++) {
            if(p[i].arrival_time <= time && p[i].remaining_time > 0) {
                if(smallest == -1 || p[i].remaining_time < p[smallest].remaining_time) {
                    smallest = i;
                }
            }
        }
        if(smallest != -1) {
            if(prev != smallest) {
                p[smallest].start_time = time;
                printf("|%s", p[smallest].name);
            }
            p[smallest].remaining_time--;
            prev = smallest;
            if(p[smallest].remaining_time == 0) {
                completed++;
                p[smallest].completion_time = time+1;
                p[smallest].turnaround_time = p[smallest].completion_time - p[smallest].arrival_time;
                p[smallest].waiting_time = p[smallest].turnaround_time - p[smallest].burst_time;
                avg_waiting_time += p[smallest].waiting_time;
                avg_turnaround_time += p[smallest].turnaround_time;
            }
        }
        printf("%d", time+1);
    }

    // Print the process table
    printf("\n\nProcess Table\n");
    printf("-------------\n");
    printf("Process\tArrival Time\tBurst Time\tStart Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for(i=0; i<n;
