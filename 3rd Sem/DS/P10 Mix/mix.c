#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 100
typedef struct cinemas
{
	char name[max];
//	char movie[max];
    int no_of_ticket;
    int bill;
    int ID;
    struct cinemas *next;
}*cc;

struct movie {
    char c_name[max];
    int seatno;
    int not;
}m[100];

FILE*fb;
cc getnode()
{
 cc new1;
 new1=(cc)malloc(sizeof(struct cinemas));
 new1->next=NULL;
 return new1;
}

cc head=NULL;
int main()
{
	   cc temp,new1;
	   char ch;
	   int x, i, counter=0;
    	printf("Price of one movie ticket: 200 Rs.\n");
      
	   do{
	   	    printf("\n1.add data\n2.display data\n3.search\n");
            printf("\n enter your choice:");
            scanf("%d",&x);
	  	           switch(x){
	                case 1:
						if (head==NULL)
	                  			       {
	                  			       	head=getnode();
	                  			       	printf("name:");
	                  			       	scanf("%s",head->name);
	                  			       	printf("ID:");
	                  			       	scanf("%d",&head->ID);
	                  			       	printf("no. of tickets:");
	                  			       	scanf("%d",&head->no_of_ticket);
                                        printf("your total bill: %d\n", head->no_of_ticket*200);
                                        head->bill = head->no_of_ticket*200;
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
	                  			       	printf("name:");
	                  			       	scanf("%s",new1->name);
	                  			       	printf("ID:");
	                  			       	scanf("%d",&new1->ID);
	                  			       	printf("no. of tickets:");
	                  			       	scanf("%d",&new1->no_of_ticket);
                                        printf("your total bill: %d\n", new1->no_of_ticket*200);
                                        new1->bill = new1->no_of_ticket*200;
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
							   
                                 while(fscanf(fb,"%s\t\t%d\t\t%d\n", m[i].c_name, m[i].seatno, m[i].not) != EOF) {
                                    printf("%s %d %d\n", m[i].c_name, m[i].seatno , m[i].not);
                                    i++;
                                 }
							   
							case 3: 
								     temp=head;
							     while(temp!=NULL)
							     {
							     	printf("%s\n",temp->name);
							     	printf("%d\n",temp->ID);
							     	printf("%d\n",temp->no_of_ticket);
							     	printf("%d\n",&temp->bill);
	                  			    temp=temp->next;
								 }
	                  			
								     break;
					 }
	    printf("do you want to continue:");
	    scanf(" %c",&ch);			  
	    }while(ch=='y');
	return 0;	   
}