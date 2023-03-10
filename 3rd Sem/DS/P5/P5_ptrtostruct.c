#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct cricket
{
    char p_name[30];
    int t_no;
    int avg;
}*ptr;                      //Himanshu Agarkar
                            //A45 20010343
int main()
{
    int n, ch, y, sch, add;
    printf("No. of players : ");
    scanf("%d", &n);
    ptr = (struct cricket*)malloc(n*sizeof(struct cricket));
    for(int i=0; i<n; i++){
        printf("Enter name, number and average of player %d : ", i+1);
        scanf("%s %d %d", (ptr+i)->p_name, &(ptr+i)->t_no, &(ptr+i)->avg);
    }
    do{
        printf("1.Display\n2.Search\n3.Add\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                for(int i=0; i<n; i++){
                    printf("\nName: %s, Number: %d, Average: %d", (ptr+i)->p_name, (ptr+i)->t_no, (ptr+i)->avg);
                }
            break;
            case 2:
                printf("Enter Player No. to be searched: ");
                scanf("%d", &sch);
                for(int i=0; i<n; i++){
                    if(sch == (ptr+i)->t_no){
                        printf("\nName: %s, Number: %d, Average: %d", (ptr+i)->p_name, (ptr+i)->t_no, (ptr+i)->avg);
                    }
                }
            break;
            case 3:
                printf("Enter number of players to be added: ");
                scanf("%d", &add);
                printf("Enter name, number, average of the players : ");
                for(int i=n; i<=add; i++){
                    printf("\nPlayer %d\n", i+1);
                    scanf("%s %d %d", (ptr+i)->p_name, &(ptr+i)->t_no, &(ptr+i)->avg);
                }
                for(int i=0; i<n+add; i++){
                    printf("\nName: %s, Number: %d, Average: %d", (ptr+i)->p_name, (ptr+i)->t_no, (ptr+i)->avg);
                }
            break;
            default:
                exit(0);
            break;
        }
    printf("\nEnter 1 is you want to continue else 0: ");
    scanf("%d", &y);
    }while(y==1);
    return 0;   
}