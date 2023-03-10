#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

int isempty( int top)
{
    if(top==MAX-1)
    return 0;
}
int isopr(char c) 
{
    if(c=='+' || c=='-' || c=='^' || c=='*' || c=='/' || c=='%')
        return 1;
    else
        return 0;      //Himanshu Agarkar
}                      //A45 20010343
int pri(char c)
{
    if(c=='^')
        return 3;
    else if(c=='*' || c=='/' || c=='%')
        return 2;
    else 
        return 1;
}
int main()
{
    char stk[MAX];
    int top=-1;
    char post[MAX],infix[MAX];
    int i,j=0;
    char alpha;
    printf("\nEnter infix expression:");
    scanf("%s",infix);
    printf("\nInfix Form : %s",infix);
    for(i=0; infix[i] != '\0' ; i++)
    {
        alpha=infix[i];
        if(isempty(top)!=0 && alpha == '(')//opening (
        {
            top++;
            stk[top]=alpha;
        }
        else if (alpha == ')')             // closing )
        {
            while(top>=0 && stk[top] != '(')
            {
                post[j]=stk[top];
                top--;
                j++;
            }
            top --;
        }
        else if(isempty(top)!=0 && isopr(alpha)==0)//operand
        {
            post[j]=alpha;
            j++;
        }
        else                        //operator
        {
            while( top>=0 && stk[top] != '(' && pri(stk[top]) >= pri(alpha))
            {
                post[j]=stk[top];
                top--;
                j++;
            }
            top++;
            stk[top]=alpha;
        }
    }
    while(top>=0)             //Himanshu Agarkar
    {                         //A45 20010343
        if(stk[top] != '(')
        {
            post[j]=stk[top];
            j++;
        }
        top--;
    }
    post[j]='\0';
    printf("\nPostfix Form : %s",post);
    return 0;
}