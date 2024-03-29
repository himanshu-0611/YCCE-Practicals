/% Lex Program to remove comments from C program
and save it in a file %/
/*Definition Section*/
%{
    #include<stdio.h>
  #include<string.h>
%}

start \/\*
end \*\/

/*Rule Section*/
%%

/*Regular expression for single line comment*/
\/\/(.*) ;
/*Regular expression for multi line comment*/
{start}.*{end} ;

%%

/*Driver function*/
int main(int k,char **argcv)
{
yyin=fopen(argcv[1],"r");
yyout=fopen("out.c","w");
/*call the yylex function.*/
yylex();
return 0;
}
