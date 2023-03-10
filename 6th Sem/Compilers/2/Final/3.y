%{
#include <stdio.h>
int count = 0;
#undef yywrap
#define yywrap() 1
%}

DIGIT [0-9]+
FLOAT (([0-9]+[\.][0-9]+)|([\.][0-9]+)|([0-9]+[\.]))

%%

{DIGIT}    { count++; } 
{FLOAT}     {}
. {};

%%

int main() {
    extern FILE *yyin;
    yyin = fopen("code.c","r");
    yylex();
    printf("Number of integers: %d\n", count);
    return 0;
}
