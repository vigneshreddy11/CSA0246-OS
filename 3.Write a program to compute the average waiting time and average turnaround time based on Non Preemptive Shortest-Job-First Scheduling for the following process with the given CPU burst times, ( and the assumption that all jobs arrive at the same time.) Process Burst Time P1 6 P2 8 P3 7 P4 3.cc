#include<stdio.h>

int main()
{
    int n=4, i, j, temp, total=0, pos;
    float average_waiting_time, average_turnaround_time;
    int burst_time[4]={6, 8, 7, 3}, arrival_time[4]={0, 0, 0, 0}, waiting_time[4]={0, 0, 0, 0}, turnaround_time[4]={0, 0, 0, 0};

    for(i=0;i<n;i++) //sorting based on burst time
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(burst_time[j]<burst_time[pos])
                pos=j;
        }
        temp=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=temp;

        temp=arrival_time[i];
        arrival_time[i]=arrival_time[pos];
        arrival_time[pos]=temp;
    }

    waiting_time[0]=0; //waiting time for the first process is 0

    for(i=1;i<n;i++) //calculating waiting time for each process
    {
        waiting_time[i]=0;
        for(j=0;j<i;j++)
            waiting_time[i]+=burst_time[j];
        total+=waiting_time[i];
    }

    average_waiting_time=(float)total/n; //calculating average waiting time
    total=0;

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(i=0;i<n;i++) //calculating turnaround time for each process and displaying the results
    {
        turnaround_time[i]=burst_time[i]+waiting_time[i];
        total+=turnaround_time[i];
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    average_turnaround_time=(float)total/n; //calculating average turnaround time

    printf("\nAverage Waiting Time = %.2f\n", average_waiting_time);
    printf("Average Turnaround Time = %.2f\n", average_turnaround_time);

    return 0;
}
