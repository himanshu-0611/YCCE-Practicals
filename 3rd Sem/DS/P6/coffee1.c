#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct coffee_shop
{
	char cus_name[100];
	char coffee_brand[100];
	int no_coffee;
	float bill_paid;
	struct coffee_shop *next;
}*CS;
CS getnode()                   //Himanshu Agarkar
{                              //A45 20010343
	CS new1;
	new1=malloc(sizeof(struct coffee_shop));
	new1->next=NULL;
	return new1;
}
void alphabetically(CS head)
{
    CS p1,p2;
    char t[20],b[20];
    int s1,s2;
    for(p1=head;p1!=NULL;p1=p1->next)
    {
        for(p2=p1->next;p2!=NULL;p2=p2->next)
        {
            if(strcmp(p1->cus_name,p2->cus_name)>0)
            {
                strcpy(t,p1->cus_name);
                strcpy(p1->cus_name,p2->cus_name);
                strcpy(p2->cus_name,t);


                strcpy(b,p1->coffee_brand);
                strcpy(p1->coffee_brand,p2->coffee_brand);
                strcpy(p2->coffee_brand,b);

                s1 = p1->no_coffee;
                p1->no_coffee = p2->no_coffee;
                p2->no_coffee = s1;

                s2 = p1->bill_paid;
                p1->bill_paid = p2->bill_paid;
                p2->bill_paid = s2;
            }
        }
    }
}
int main()
{
    CS temp,new1,head=NULL,t1,t2,p1,p2,p3,t;
	char res,res1,name[100];
    int ch,n;
	do
	{
	printf("\n1.Create\n2.Display\n3.Search");
    printf("\n4.Deletion \n5.Insersion");
	printf("\nEnter your choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1://create
        do
        {
            if(head==NULL)
            {
                head=getnode();
                printf("Enter customer name:");
                scanf("%s",head->cus_name);
                printf("Enter coffee brand:");
                scanf("%s",head->coffee_brand);
                printf("Enter no of coffee order:");
                scanf("%d",&head->no_coffee);
                printf("Enter total bill paid:");
                scanf("%f",&head->bill_paid);
                temp=head;
            }
            else
            {
                new1=getnode();
            	printf("Enter customer name:");
                scanf("%s",new1->cus_name);
                printf("Enter coffee brand:");
                scanf("%s",new1->coffee_brand);
                printf("Enter no of coffee order:");
                scanf("%d",&new1->no_coffee);
                printf("Enter total bill paid:");
                scanf("%f",&new1->bill_paid);
                temp->next=new1;
                temp=new1;
            }
            printf("\nDo you want to add further?\t");
            scanf("%s",&res1);
        }while(res1=='y');
		break;

		case 2:
        alphabetically(head);
        temp=head;
        while(temp!=NULL)
        {
            printf("%s\t\t%s\t\t%d\t\t%.2f\n",temp->cus_name,temp->coffee_brand,temp->no_coffee,temp->bill_paid);
            temp=temp->next;
        }
		break;

		case 3://search by customer name
        printf("\nEnter the name of customer:");
        scanf("%s",&name);
        temp=head;
        while(temp!=NULL)
        {
            if(strcmp(temp->cus_name,name)==0)
            {
                printf("\nNAME:\t%s\n",temp->cus_name);
                printf("COFFEE BRAND:\t%s\n",temp->coffee_brand);
                printf("NO OF COFFEE ORDER:\t%d\n",temp->no_coffee);
                printf("TOTAL BILL PAID:\t%.2f\n",temp->bill_paid);
                break;
            }
            temp=temp->next;
        }
        if(temp==NULL)
        {
            printf("Invalid Name");
        }
		break;

		case 4://delete 
        temp=head;
        while(temp!=NULL)
        {
            t1=temp;
            while(t1!=NULL )
            { 
                if(t1->next!=NULL && strcmp(temp->cus_name,t1->next->cus_name)==0 && strcmp(temp->coffee_brand,t1->next->coffee_brand)==0 && temp->no_coffee == t1->next->no_coffee && temp->bill_paid == t1->next->bill_paid)
                {
                    t2=t1->next;
                    t1->next=t1->next->next;
                    free(t2);
                }
                t1=t1->next;
            }
            temp=temp->next;
        }
        printf("\nDublicate entries are deleted");
		break;

		case 5:
        new1=getnode();
        printf("\nEnter customer Name:");
        scanf("%s",new1->cus_name);
        printf("Enter Coffee Brand:");
        scanf("%s",new1->coffee_brand);
        printf("Enter No of coffee order:");
        scanf("%d",&new1->no_coffee);
        printf("Enter Total bill paid:");
        scanf("%f",&new1->bill_paid);
        temp=head;
        int count=0;
        while(temp!=NULL)
        {
            if(strcmp(temp->cus_name,new1->cus_name)>0)
                break ;
            count ++;
            temp=temp->next;
        }
        if(count==1)
        {
            new1->next=head;
            head=new1;
            printf("\nData added");
        }
        else
        {
            while(count>2)
            {
                temp=temp->next;
                count--;
                if(temp==NULL)
                 {
                     break;
                 }
            }
            if(temp==NULL)
            {
                printf("\nInvalid position");
            }
            else
            {
                new1->next=temp->next;
                temp->next=new1;
                printf("\nData added");
            }
        }
		break;
		default:
			exit(0);
	}
	printf("\nWant to continue...\t");
	scanf("%s",&res);
	}while(res=='y');
    return 0;
}