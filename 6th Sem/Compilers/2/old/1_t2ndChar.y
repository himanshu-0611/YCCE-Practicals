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
  yylex();
  printf("\nNumber of strings with 't' as second character: %d",count);
  return 0;
}