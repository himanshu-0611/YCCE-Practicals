#include<stdio.h>
#include<stdlib.h>
#define MAX 4
                                //Himanshu Agarkar
int main() {                    //A45 200101343
    char stk1[MAX], stk2[MAX];
    int top1 = -1, top2 = -1, ch, i=0;
    char val, res;
    do {
        printf("\n1. Creation\n2. Deletion\n3.Display");
	    printf("\nEnter your choice:\t");
	    scanf("%d", &ch);
        switch(ch) {
            case 1:
                if(top1 == MAX-1) {
                    printf("\nQueue is Full\n");
                }
                else {
                    printf("\nEnter values to be inserted in queue : ");
                    scanf(" %c", &val);
                    top1++;
                    stk1[top1] = val;
                }                
            break;
            case 2:
                if(top1 == -1) {
                    printf("\nQueue is empty!\n");
                }
                else {
                    while(top1 >= 0) {
                        top2++;
                        stk2[top2] = stk1[top1];
                        top1--;
                    }
                    printf("%c is deleted from queue", stk2[top2]);
                    top2--;
                    while(top2 >= 0) {
                        top1++;
                        stk1[top1] = stk2[top2];
                        top2--;
                    }
                }
            break;         //Himanshu Agarkar
            case 3:        //A45 20010343
                i=0;
                while(i <= top1) {
                    printf("%c\t", stk1[i]);
                    i++;
                }
            break;
            default:
                exit(0);
            
        }printf("\nDo you want to continue : ");
            scanf(" %c", &res);
    }while(res == 'y');
    return 0;
}