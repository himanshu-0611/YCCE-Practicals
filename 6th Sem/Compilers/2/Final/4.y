%{ 
#include<stdio.h>
#include<string.h>
int count = 0;
%}

%%
[a-zA-Z0-9]*[^a-zA-Z0-9 \t\n]+[a-zA-Z0-9]*     {count++;}
.|\n
%%
int yywrap(){
	return 1;	
}
int main() {
	extern FILE *yyin,*yyout;
	yyin = fopen("input.txt","r");  
  	yylex();
    	printf("\nThe number of strings with as one of the special characters is %d\n", count);
    	return 0;
}