%{
  #include<stdio.h>
  #include<string.h>
  int count=0;
%}
%%

d[ \t\n] {count++;}
.|\n ;
%%

int main()
{   
  yyin=fopen("code.c","r");
  yylex();
  printf("\n%d strings with 'd' as last letter",count);
  return 0;
} 
int yywrap(){
return 1;
}
