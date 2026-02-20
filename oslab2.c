#include <stdio.h>
int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int at[n], bt[n], ct[n], tat[n], wt[n];
    int io=2;
    for(i = 0; i < n; i++) {
        printf("Process P%d\n", i+1);
        printf("Arrival Time = ");
        scanf("%d", &at[i]);
        printf("Burst Time =");
        scanf("%d", &bt[i]);
    }
    ct[0] = at[0] + bt[0]+io;   

    for(i = 1; i < n; i++) {
        if(ct[i-1] < at[i])
            ct[i] = at[i] + bt[i]+io;  
        else
            ct[i] = ct[i-1] + bt[i]+io;
    }

    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", 
               i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}