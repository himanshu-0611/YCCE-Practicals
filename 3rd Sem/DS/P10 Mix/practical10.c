#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 30

typedef struct movies {
	char name[max];
    int n_tickets;
    int price;
    int ID;
    struct movies *next;
}*cc;
                        //Himanshu Agarkar
struct movie {          //A45 20010343
    char c_name[max];
    int seatno;
    int not;
}m[100];

FILE *fp;

cc getnode() {
    cc new1;
    new1=(cc)malloc(sizeof(struct movies));
    new1->next=NULL;
    return new1;
}
cc head=NULL;

int main() {
    cc temp, new1;
    char res, c;
	int x, i, counter=0, ch, id;
    printf("\nCost of 1 Ticket: 350/-\n");
    do {
        printf("\n********************************************************************");
        printf("\n1.Add New Customer\n2.Display Existing Data\n3.Search Using ID\n");
        printf("\n\tEnter your choice: ");
        scanf("%d", &ch);
	  	switch(ch){
            case 1:
                if(head == NULL) {
                    head = getnode();
                    printf("\n");
	                printf("\t\tName: ");
	                scanf("%s",head->name);
	                printf("\t\tID: ");
	                scanf("%d",&head->ID);
	                printf("\t\tNumber of Tickets: ");
	                scanf("%d",&head->n_tickets);
                    printf("\t\tYour Total price: %d\n", head->n_tickets*350);
                    head->price = head->n_tickets*350;
	                temp=head;
	                fp=fopen("records.txt","a");
	                fprintf(fp,"%s\t\t%d\t\t%d\n",head->name,head->ID,head->n_tickets);
	                fclose(fp);
                    counter++;
	                strcpy(m[0].c_name, head->name);
                    m[0].seatno = head->ID;
                    m[0].not = head->n_tickets;
                }
                else {
                    new1 = getnode();
                    printf("\n");
	                printf("\t\tName: ");
	                scanf("%s",new1->name);
	                printf("\t\tID: ");
	                scanf("%d",&new1->ID);
	                printf("\t\tNumber of Tickets: ");
	                scanf("%d",&new1->n_tickets);
                    printf("\t\tYour Total price: %d\n", new1->n_tickets*350);
                    new1->price = new1->n_tickets*350;
	                fp=fopen("records.txt","a");
	                fprintf(fp,"%s\t\t%d\t\t%d\n",new1->name, new1->ID,new1->n_tickets);
	                fclose(fp);
	                temp->next=new1;
	                temp=new1;
                    counter++;
                    strcpy(m[counter].c_name, new1->name);
                    m[counter].seatno = new1->ID;
                    m[counter].not = new1->n_tickets;
                }
            break;                         //Himanshu Agarkar
                                           //A45 20010343
            case 2:
                printf("--------------------------------------------------------------------");
                fp = fopen("records.txt", "r");
                i = 0;
                printf("\n");
                printf("\t\tCustomer Name\tID\tNo. of Tickets\n");
                printf("\n");
                while(fscanf(fp,"%s\t\t%d\t\t%d", m[i].c_name, &m[i].seatno, &m[i].not) != EOF) {
                    printf("\t\t%s\t\t%d\t\t%d\n", m[i].c_name, m[i].seatno , m[i].not);
                    i++;
                }
                fclose(fp);
            break;

            case 3:
                fp = fopen("records.txt", "r");
                i = 0;
                printf("\n\t\tEnter ID of the customer to be searched: ");
                scanf("%d", &id);
                printf("\n");
                printf("\t\t\tCustomer Name\tID\tNo. of Tickets\n");
                while(fscanf(fp,"%s\t\t%d\t\t%d", m[i].c_name, &m[i].seatno, &m[i].not) != EOF) {
                    if(id == m[i].seatno) {
                       printf("\t\t\t%s\t||\t%d\t||\t%d\n", m[i].c_name, m[i].seatno , m[i].not);
                       break;
                    }
                    i++;
                }
                fclose(fp);
            break;
        }
        printf("\n\tDo you want to continue: ");
        scanf(" %c", &res);
    } while(res == 'y');
    return 0;
}
