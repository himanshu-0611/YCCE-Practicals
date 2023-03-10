/*Write a lex program to count the no. of strings having 'd' as the last
character*/

%{
  #include<stdio.h>
  #include<string.h>
  int count=0;
%}
%%
d$ {count++;}
%%
int yywrap(void){}
int main()
{   
  yylex();
  printf("\nNumber of strings with 'd' as last character: %d",count);
  return 0;
}