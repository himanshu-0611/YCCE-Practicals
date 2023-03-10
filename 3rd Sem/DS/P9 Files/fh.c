#include<string.h>
#define max 30
FILE *fb;
int main()
{
	char name[max],city[max] ,line[256];;
	char c,y,ch;
	int id,s,i=0,j;
	do
      {	
    printf("1. create file\n2. add data in file\n3. display the file\n4. search record based on id\n5. record of employee based on city\n6. store perticular data in another file\n");
    printf("\n");
	printf("enter your choice : ");
	scanf("%d",&j);
    switch(j)
	       {
                case 1:
                              fb=fopen("employee.txt","w");
	                          fprintf(fb,"the list of employee\n");
                              fprintf(fb,"sr.no\t\tname\t\tID\t\tsalary\t\tCity\n");
	                          fprintf(fb,"__________________________________\n");
                              c='y';
                              while(c=='y')
                              {
                                 printf("employee_%d\n",i+1);
                                 printf("name:");
                                 scanf("%s",name);
                                 printf("salary:");
                                 scanf("%d",&s);
                                 printf("id:");
                                 scanf("%d",&id);
                                 printf("city:");
                                 scanf("%s",city);
                                 fprintf(fb,"%d\t\t%s\t\t%d\t\t%d\t\t%s\n",i+1,name,id,s,city);
                                 i++;
                                 printf("do you want to continue...");
                                 scanf("%c",&c);
                                 scanf("%c",&c);
                              }
                              fclose(fb);
                              break;
				case 2 :
								printf("do you want to add more ........");
                            	scanf("%c",&c);
	                            scanf("%c",&c);
                              	if(c=='y')
                                      	{
	                                     fb=fopen("employee.txt","a");
                                       	 while(c=='y')
                                            {
                                               printf("employee_%d\n",i+1);
                                               printf("name :");
                                               scanf("%s",name);
                                               printf("salary:");
                                               scanf("%d",&s);
                                               printf("id:");
                                               scanf("%d",&id);
                                               printf("city:");
                                               scanf("%s",city);
                                               fprintf(fb,"%d\t\t%s\t\t%d\t\t%d\t\t%s\n",i+1,name,id,s,city);
                                               i++;
                                               printf("do you want to continue...");
                                               scanf("%c",&c);
                                               scanf("%c",&c);
                                           	}
                                        	fclose(fb);
                                     	 }
                                break;
                case 3:
                	            fb=fopen("employee.txt","r");
                                if(fb==NULL)
                                      	{
	                                           printf("ERROR: could not open file");	
                                       	}
                                char line[256];

                                while (fgets(line, sizeof(line), fb))
                                        {
                                               printf("%s", line); 
                                        }
                                fclose(fb); 
								break; 
				case 4:
								char yy[200];
	                            printf("enter the id: ");
	                            scanf("%s",yy);
	                            fb=fopen("employee.txt","r");
                                if(fb==NULL)
	                                {
	                                   printf("ERROR: could not open file");	
                                   	}
                                while (fgets(line, sizeof(line), fb))
                                    { 
                                        char *ptr = strstr(line, yy);
	                                	if (ptr != NULL) 
	                                      	{
		                                        printf("%s", line); 
			
		                                    }
                                     }
                                fclose(fb);
                                break;
                case 5:
								char ss[max];
	                            printf("enter the city: ");
	                            scanf("%s",ss);
	                            fb=fopen("employee.txt","r");
                                if(fb==NULL)
	                                {
	                                   printf("ERROR: could not open file");	
                                   	}
                                
							//	char line[256];

                                while (fgets(line, sizeof(line), fb))
                                    { 
                                        char *ptr = strstr(line, ss);
	                                	if (ptr != NULL) 
	                                      	{
		                                        printf("%s", line); 
			
		                                     }
                                     }
                                fclose(fb);
                                break;
                case 6:
								int dd;
	                            printf("enter the range of salary: ");
	                            scanf("%d",dd);
	                            fb=fopen("employee.txt","r");
                                if(fb==NULL)
	                                {
	                                   printf("ERROR: could not open file");	
                                   	}
                                while (fgets(line, sizeof(line), fb))
                                    { 
                                       while(sa=getw(fb)!=EOF)
                                       {
	                                	if (ss > dd) 
	                                      	{
		                                        printf("%s", line); 
			
		                                    }
		                               }
                                     }
                                fclose(fb);
                                break;
	      
            }
       printf("do you want to continue with menu.....");
       scanf(" %c",&ch);
       }
    while(ch=='y');
    /*
    fb=fopen("employee.txt","r");
    if(fb==NULL)
	{
	 printf("ERROR: could not open file");	
	}
    char line[256];

    while (fgets(line, sizeof(line), fb))
    {
        printf("%s", line); 
    }
    fclose(fb);*/
/*	char ss[max];
	 printf("enter the city: ");
	 scanf("%s",ss);
	fb=fopen("employee.txt","r");
    if(fb==NULL)
	{
	 printf("ERROR: could not open file");	
	}
   // char line[256];

    while (fgets(line, sizeof(line), fb))
    { 
        char *ptr = strstr(line, ss);
		if (ptr != NULL) 
		{
		    printf("%s", line); 
			
		}
    }
    fclose(fb);*/
	
}