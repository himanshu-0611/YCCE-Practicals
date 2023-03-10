
%{
#include<stdio.h>
%}

%% 

[/][/][^\n]* 





























[ \t\r\n]+
\/\*[a-zA-Z0-9 \t\n/+-/%]*\*\/		
%% 

int yywrap(){
return 1;
} 
int main()
{ 

yyin=fopen("code.c","r");
yyout=fopen("out.c","w");
yylex();
return 0;
}