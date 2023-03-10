%{
  #include<stdio.h>
  #include<string.h>
  int count=0;
%}
%%
[@!,.?$#^*%&+=_–|/\;:'“()\[\]{}<>+=_–|/\;:'“] {count++;}
%%
int yywrap(void){}
int main()
{   
  yylex();
  printf("\nNumber special symbols: %d",count);
  return 0;
}