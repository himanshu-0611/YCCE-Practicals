#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 15
FILE *fp, *c;
struct Employee
{
	int Id;
	char name[MAX];
	char city[MAX];
	int salary;                //Himanshu Agarkar
}Em[MAX];					   //A45 20010343

int main()
{
	int i=0,n,ch,ID,found=0;
	char res;
	do
	{
		printf("1.Display\n2.Append\n3.Search\n4.Coping salary of employee with salary more than 20000 into another file\n5.Display People Staying in Mumbai");
		
		printf("\n\n\tEnter your choice :\t");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1://Reading
			//FILE *fp,*c;
			fp=fopen("Employee.txt","r");
			printf("\n*************\n");
			printf("ID\tNAME\tCITY\tSALARY\n");
			printf("\n*************\n");
			while(fscanf(fp,"%d\t%s\t%s\t%d",&Em[i].Id,&Em[i].name,&Em[i].city,&Em[i].salary)!=EOF)
			{
				printf("\n%d\t%s\t%s\t%d\n",Em[i].Id,Em[i].name,Em[i].city,Em[i].salary);
				i++;
			}
			fclose(fp);
			break;
			case 2://Append
			printf("\n\t\tEnter the number of Employees :\t");
			scanf("%d",&n);
			fp = fopen("Employee.txt","a");
			for(i=0;i<n;i++)
			{
    			printf("\nEnter Id: ");
    			scanf("%d",&Em[i].Id);
    			printf("Enter name: ");
    			scanf("%s",&Em[i].name);
    			printf("Enter city: ");
    			scanf("%s",&Em[i].city);
    			printf("Enter salary: ");
    			scanf("%d",&Em[i].salary);
    			fprintf(fp,"\n%d\t%s\t%s\t%d",Em[i].Id,Em[i].name,Em[i].city,Em[i].salary);
			}	
    		fclose(fp);
    		break;
    		case 3://Search Record
    		found=0;
    		printf("\n********Enter the ID to be searched******\n");
    		scanf("%d",&ID);
			fp=fopen("Employee.txt","r");
    		while(fscanf(fp,"%d\t%s\t%s\t%d",&Em[i].Id,&Em[i].name,&Em[i].city,&Em[i].salary)!=EOF)
			{
				if(Em[i].Id==ID)
				{
					found=1;
					printf("\nThe id of employee is %d and his name is %s and belongs to %s city and has a monthly salary of %d\n",Em[i].Id,Em[i].name,Em[i].city,Em[i].salary);      
			 	}
				i++;
			}
			if(found==0)
			{
				printf("\n\t\tRecord Not Found.");	
			}
			fclose(fp);
			break;
			case 4: //Copying people having Salary more 20000 into salary.txt
			found=0;
			fp = fopen("Employee.txt","r");
			c = fopen("Salary.txt","w");
			fprintf(c,"ID\tNAME\tCITY\tSALARY\n");
    		while(fscanf(fp,"%d\t%s\t%s\t%d",&Em[i].Id,&Em[i].name,&Em[i].city,&Em[i].salary)!=EOF)
			{
				if(Em[i].salary > 20000)
				{
					found=1;
					fprintf(c,"\n%d\t%s\t%s\t%d\n",Em[i].Id,Em[i].name,Em[i].city,Em[i].salary);
			 	}
				i++;                  //Himanshu Agarkar
			}						  //A45 20010343
			if(found==0)
			{
				printf("\n\t\tNo one has salary more than 20k.");	
			}
			fclose(fp);
			fclose(c);
			break;		
			case 5:// Display people staying in mumbai
			found=0;
			fp=fopen("Employee.txt","r");
			printf("\n************\n");
			printf("ID\tNAME\tCITY\tSALARY\n");
			printf("\n************\n");
    		while(fscanf(fp,"%d\t%s\t%s\t%d",&Em[i].Id,&Em[i].name,&Em[i].city,&Em[i].salary)!=EOF)//End of file
			{
				if(strcmp(Em[i].city,"Mumbai")==0)
				{
					found=1;
				
					printf("\n%d\t%s\t%s\t%d\n",Em[i].Id,Em[i].name,Em[i].city,Em[i].salary);
						
			 	}
				i++;
			}
			if(found==0)
			{
				printf("\n\t\tNO one staying in Mumbai.");	
			}
			fclose(fp);
			break;	
			default:
			exit(0);
		}
		printf("\nDo you want to continue, then press y :");
		scanf("%s",&res);
	}while(res=='y');
	return 0;
}