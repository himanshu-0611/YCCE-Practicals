%{
#include <stdio.h>
int count=0;
%}
digit[0-9]
letter[a-zA-Z_]

%% 
{letter}({letter}|{digit})* {
 count++;
}
%%

int main()
{
yyin=fopen("code.txt","r");
yylex();
printf("\nNo of identifiers : %d\n",count);
return 0;
}

int yywrap(){
return 1;
}