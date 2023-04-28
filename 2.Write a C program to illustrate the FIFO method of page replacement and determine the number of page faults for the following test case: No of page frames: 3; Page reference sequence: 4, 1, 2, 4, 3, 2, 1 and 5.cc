#include <stdio.h>
#define MAX 50

int main() {
    int i, j, n, f, count, p_fault;
    int ref[MAX], frame[MAX], flag[MAX];
    
    printf("Enter number of page frames: ");
    scanf("%d", &f);
    
    printf("Enter length of page reference sequence: ");
    scanf("%d", &n);
    
    printf("Enter the page reference sequence: ");
    for(i=0; i<n; i++)
        scanf("%d", &ref[i]);
    
    for(i=0; i<f; i++) {
        frame[i] = -1;  // initialize frames to -1
        flag[i] = 0;    // initialize flags to 0
    }
    
    count = 0;  // initialize page count to 0
    p_fault = 0;    // initialize page fault count to 0
    
    printf("\n");
    for(i=0; i<n; i++) {
        printf("%d\t", ref[i]);
        flag[i] = 0;
        for(j=0; j<f; j++) {
            if(frame[j] == ref[i]) {
                flag[i] = 1;
                break;
            }
        }
        if(flag[i] == 0) {
            frame[count] = ref[i];
            count = (count + 1) % f;
            p_fault++;
        }
        for(j=0; j<f; j++)
            printf("%d\t", frame[j]);
        if(flag[i] == 0)
            printf("PF No. %d", p_fault);
        printf("\n");
    }
    printf("\nTotal Page Faults = %d", p_fault);
    
    return 0;
}






