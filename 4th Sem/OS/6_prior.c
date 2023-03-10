#include<stdio.h>
struct process
{
    int id, wait_time, AT, BT, TAT, PR;
};
struct process a[10];

void swap(int *b,int *c)
{
    int tem;
    tem=*c;
    *c=*b;
    *b=tem;
}

int main()
{
    int n,check_ar=0;
    int finish_time=0;
    float Total_wait_time=0,Total_TAT=0,Avg_wait_time,Avg_TAT;
    printf("\nEnter total number of process: \t");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\n*************************************************************************************************\n");
        printf("\nProcess %d:", i);
        printf("\nEnter the Arrival time, Burst time and Priority of the process: ");
        scanf("%d%d%d",&a[i].AT,&a[i].BT,&a[i].PR);
        a[i].id=i+1;

        if(i==0)
         check_ar=a[i].AT;

        if(check_ar!=a[i].AT )
         check_ar=1;

    }
    if(check_ar!=0)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(a[j].AT>a[j+1].AT)
                {
                      swap(&a[j].id,&a[j+1].id);
                      swap(&a[j].AT,&a[j+1].AT);
                      swap(&a[j].BT,&a[j+1].BT);
                      swap(&a[j].PR,&a[j+1].PR);
                }
            }
        }
    }

    if(check_ar!=0)
    {
        a[0].wait_time=a[0].AT;
        a[0].TAT=a[0].BT-a[0].AT;
        finish_time=a[0].TAT;
        Total_wait_time=Total_wait_time+a[0].wait_time;
        Total_TAT=Total_TAT+a[0].TAT;
        for(int i=1;i<n;i++)
        {
            int min=a[i].PR;
            for(int j=i+1;j<n;j++)
            {
                if(min>a[j].PR && a[j].AT<=finish_time)
                {
                      min=a[j].PR;
                      swap(&a[i].id,&a[j].id);
                      swap(&a[i].AT,&a[j].AT);
                      swap(&a[i].BT,&a[j].BT);
                      swap(&a[i].PR,&a[j].PR);

                }

            }
            a[i].wait_time=finish_time-a[i].AT;
            Total_wait_time=Total_wait_time+a[i].wait_time;
            finish_time=finish_time+a[i].BT;

            a[i].TAT=finish_time-a[i].AT;
            Total_TAT=Total_TAT+a[i].TAT;

        }
    }

    else
    {
        for(int i=0;i<n;i++)
        {
            int min=a[i].PR;
            for(int j=i+1;j<n;j++)
            {
                if(min>a[j].PR && a[j].AT<=finish_time)
                {
                    min=a[j].PR;
                      swap(&a[i].id,&a[j].id);
                      swap(&a[i].AT,&a[j].AT);
                      swap(&a[i].BT,&a[j].BT);
                      swap(&a[i].PR,&a[j].PR);
                }

            }
            a[i].wait_time=finish_time-a[i].AT;

            finish_time=finish_time+a[i].BT;

            a[i].TAT=finish_time-a[i].AT;
            Total_wait_time=Total_wait_time+a[i].wait_time;
            Total_TAT=Total_TAT+a[i].TAT;

        }

    }


    Avg_wait_time=Total_wait_time/n;
    Avg_TAT=Total_TAT/n;
    printf("\n*************************************************************************************************\n");
    printf("*************************************************************************************************\n");

    printf("ID\t|\tWT\t|\tTAT\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t|\t%d\t|\t%d\n",a[i].id,a[i].wait_time,a[i].TAT);
    }

    printf("\nAvg waiting time is: %f\n",Avg_wait_time);
    printf("Avg turn around time is: %f\n",Avg_TAT);
    return 0;
}