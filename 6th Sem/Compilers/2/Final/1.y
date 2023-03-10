%{
  #include<stdio.h>
  #include<string.h>
  int count=0;
%}
%%
[ \t\n][a-zA-Z0-9][t] {count++;}
^[a-zA-Z0-9][t] {count++;}
.|\n ;
%%

int main()
{   
  yyin=fopen("code.c","r");
  yylex();
  printf("\n%d strings with 't' as second letter",count);
  return 0;
} 
int yywrap(){
return 1;
}
