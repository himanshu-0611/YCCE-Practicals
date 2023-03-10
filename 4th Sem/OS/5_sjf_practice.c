#include<stdio.h>

int main() {

    int n, btime[20], atime[20], temp, pid[20], wt[20], total, tat[20];
    float avg_wt, avg_tat;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        printf("\nProcess %d\n", i+1);
        printf("Burst Time: \t");
        scanf("%d", &btime[i]);
        pid[i] = i+1;
    }

    for(int i=0; i<n; i++) {
        int pos = i;
        for(int j=i+1; j<n; j++) {
            if(btime[j] < btime[pos]) {
                pos = j;
            }
        }

        temp = btime[i];
        btime[i] = btime[pos];
        btime[pos] = temp;

        temp = pid[i];
        pid[i] = pid[pos];
        pid[pos] = temp;
    }

    wt[0] = 0;
    for(int i=1; i<n; i++) {
        wt[i] = 0;
        for(int j=0; j<i; j++) {
            wt[i] += btime[j];
        }
        total += wt[i];
    }
    printf("\n\ntotal of wt %d", total);
    avg_wt = (float)total/n;
    printf("\n\navg wt %f", avg_wt);
    total = 0;

    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(int i=0;i<n;i++)
    {
        tat[i]=btime[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",pid[i],btime[i],wt[i],tat[i]);
    }

    avg_tat=(float)total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);

}