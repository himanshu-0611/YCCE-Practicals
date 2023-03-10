%{
#include<stdio.h>
#include<string.h>
int len=0, counter=0;
%}
	
%%
[a-zA-Z]+ { len=strlen(yytext);
			if(len==2)
			{counter++;} }
%%

int yywrap (void )
{
	return 1;
}
	
int main()
{
yyin=fopen("code.c","r");
yylex();
printf("\n %d", counter);
return 0;
}