/*Write a lex program to count no. of strings, having 't' as the second
character*/
%{
  #include<stdio.h>
  #include<string.h>
  int count=0;
%}
%%
^.t {count++;}
%%
int yywrap(void){}
int main()
{   
  yyin=fopen("code.txt","r");
  yylex();
  printf("\n%d strings with 't' as second letter",count);
  return 0;
} 