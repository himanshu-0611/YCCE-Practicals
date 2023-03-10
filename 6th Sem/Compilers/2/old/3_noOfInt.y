/*Write a lex program to count the no. of integers in the code*/

%{
int positive_no = 0, negative_no = 0;
%}

/* Rules for identifying and counting
positive and negative numbers*/
%%
^[-][0-9]+ {negative_no++;
			printf("negative number = %s\n",
				yytext);} // negative number

[0-9]+ {positive_no++;
		printf("positive number = %s\n",
				yytext);} // positive number	
%%

/*** use code section ***/

int yywrap(){}
int main()											
{

yylex();
printf ("number of positive numbers = %d,"
		"number of negative numbers = %d\n",
				positive_no, negative_no);

return 0;
}
