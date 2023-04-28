#include<stdio.h>

int main()
{
    int n=6, m=5, i, j;
    int partitions[6]={300, 600, 350, 200, 750, 125}; //memory partitions
    int processes[5]={115, 500, 358, 200, 375}; //processes to be allocated
    int allocation[5]={-1, -1, -1, -1, -1}; //allocation status of each process

    for(i=0;i<m;i++) //allocate memory to each process using first-fit algorithm
    {
        for(j=0;j<n;j++)
        {
            if(partitions[j]>=processes[i])
            {
                allocation[i]=j;
                partitions[j]-=processes[i];
                break;
            }
        }
    }

    printf("Process\tSize\tPartition\n");

    for(i=0;i<m;i++) //display the allocation status of each process
    {
        printf("%d\t%d\t", i+1, processes[i]);
        if(allocation[i]!=-1)
            printf("%d\n", allocation[i]+1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
