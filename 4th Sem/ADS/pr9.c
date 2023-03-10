#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 100
typedef struct railway
{
    char name[max];
    int no_of_ticket;
    int bill;
    int ID;
    struct railway *next;
}*cc;

struct train {
    char c_name[max];
    int seatno;
    int not;
}m[100];

FILE*fb;
cc getnode()
{
 cc new1;
 new1=(cc)malloc(sizeof(struct railway));
 new1->next=NULL;
 return new1;
}

cc head=NULL;
int main()
{
       cc temp,new1;
       char ch;
       int x, i, counter=0;
       printf("\n\t\tPrice of one train ticket: 3000 Rs.\n");

       do{
            printf("\n1.Add Customer\n2.Search\n3.Display Database\n");
            printf("\nEnter your choice:\t");
            scanf("%d",&x);
                   switch(x){
                    case 1:
                        if (head==NULL)
                                       {
                                        head=getnode();
                                        printf("\n\tName:\t");
                                        scanf("%s",head->name);
                                        printf("\tID:\t");
                                        scanf("%d",&head->ID);
                                        printf("\tNumber of Tickets:\t");
                                        scanf("%d",&head->no_of_ticket);
                                        printf("\tTotal bill: \t%d\n", head->no_of_ticket*3000);
                                        head->bill = head->no_of_ticket*3000;
                                        temp=head;
                                        fb=fopen("data.txt","a");
                                        fprintf(fb,"%s\t\t%d\t\t%d\n",head->name,head->ID,head->no_of_ticket);
                                        fclose(fb);
                                        counter++;
                                        strcpy(m[0].c_name, head->name);
                                        m[0].seatno = head->ID;
                                        m[0].not = head->no_of_ticket;
                                       }
                                     else
                                      {
                                        new1=getnode();
                                        printf("\n\tName:\t");
                                        scanf("%s",new1->name);
                                        printf("\tID:\t");
                                        scanf("%d",&new1->ID);
                                        printf("\tNumber of Tickets:\t");
                                        scanf("%d",&new1->no_of_ticket);
                                        printf("\tTotal bill: \t%d\n", new1->no_of_ticket*3000);
                                        new1->bill = new1->no_of_ticket*3000;
                                        fb=fopen("data.txt","a");
                                        fprintf(fb,"%s\t\t%d\t\t%d\n",new1->name,new1->ID,new1->no_of_ticket);
                                        fclose(fb);
                                        temp->next=new1;
                                        temp=new1;
                                        counter++;
                                        strcpy(m[counter].c_name, new1->name);
                                        m[counter].seatno = new1->ID;
                                        m[counter].not = new1->no_of_ticket;
                                      }

                                     break;

                            case 2:
                                i=0;
                                int id;
                                printf("\n\tEnter ID of Customer to be searched:\t");
                                scanf("%d", &id);
                                 while(temp!=NULL)
							     {
									 if(id == temp->ID) {
                                        printf("\n\tName\t\tSeat No\t\tNumber of Tickets\t\tBilling Amount\n");
							     	    printf("\n\t%s",temp->name);
							     	    printf("\t\t%d",temp->ID);
							     	    printf("\t\t%d",temp->no_of_ticket);
							     	    printf("\t\t%d",&temp->bill);
                                     break;
                                     }
	                  			    temp=temp->next;
								 }
                                 break;

                            case 3:
                                 temp=head;
                                 printf("\n\tName\t\tSeat No\t\tNumber of Tickets\t\t\n");
                                 while(temp!=NULL)
                                 {
                                    printf("\n\t%s",temp->name);
                                    printf("\t\t%d",temp->ID);
                                    printf("\t\t%d",temp->no_of_ticket);
                                    temp=temp->next;
                                 }

                                     break;
                     }
        printf("\n\n*******************************************************************************");
        printf("\n*******************************************************************************");
        printf("\n\nDo you want to continue:\t");
        scanf(" %c",&ch);
        }while(ch=='y');
    return 0;
}