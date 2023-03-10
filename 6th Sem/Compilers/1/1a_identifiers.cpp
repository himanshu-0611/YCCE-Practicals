
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int count_iden;

bool isDelimiter(char ch)
{
	if (ch == ' ' || ch == '\n' || ch == '+' || ch == '-' || ch == '*' ||
		ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
		ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
		ch == '[' || ch == ']' || ch == '{' || ch == '}')
		return (true);
	return (false);
}

bool isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' ||
		ch == '/' || ch == '>' || ch == '<' ||
		ch == '=')
		return (true);
	return (false);
}

bool validIdentifier(char *str)
{
	if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
		str[0] == '3' || str[0] == '4' || str[0] == '5' ||
		str[0] == '6' || str[0] == '7' || str[0] == '8' ||
		str[0] == '9' || isDelimiter(str[0]) == true)
		return (false);
	return (true);
}

bool isKeyword(char *str)
{
	if (!strcmp(str, "if") || !strcmp(str, "else") ||
		!strcmp(str, "while") || !strcmp(str, "do") ||
		!strcmp(str, "break") ||
		!strcmp(str, "continue") || !strcmp(str, "main") || !strcmp(str, "stdio.h") || !strcmp(str, "cout") || !strcmp(str, "cin") || !strcmp(str, "int") || !strcmp(str, "double") || !strcmp(str, "float") || !strcmp(str, "return") || !strcmp(str, "char") || !strcmp(str, "case") || !strcmp(str, "char") || !strcmp(str, "sizeof") || !strcmp(str, "long") || !strcmp(str, "short") || !strcmp(str, "typedef") || !strcmp(str, "switch") || !strcmp(str, "unsigned") || !strcmp(str, "void") || !strcmp(str, "static") || !strcmp(str, "struct") || !strcmp(str, "goto"))
		return (true);
	return (false);
}

bool isInteger(char *str)
{
	int i, len = strlen(str);

	if (len == 0)
		return (false);
	for (i = 0; i < len; i++)
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' || (str[i] == '-' && i > 0))
			return (false);
	}
	return (true);
}

bool isRealNumber(char *str)
{
	int i, len = strlen(str);
	bool hasDecimal = false;

	if (len == 0)
		return (false);
	for (i = 0; i < len; i++)
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i] != '.' ||
			(str[i] == '-' && i > 0))
			return (false);
		if (str[i] == '.')
			hasDecimal = true;
	}
	return (hasDecimal);
}

char *subString(char *str, int left, int right)
{
	int i;
	char *subStr = (char *)malloc(
		sizeof(char) * (right - left + 2));

	for (i = left; i <= right; i++)
		subStr[i - left] = str[i];
	subStr[right - left + 1] = '\0';
	return (subStr);
}

int dfa;

void start(char c)
{
	if (isalpha(c))
		dfa = 1;
	else

		dfa = -1;
}

void state1(char c)
{
	if (isalnum(c))
		dfa = 1;
	else
		dfa = -1;
}

bool DFA_for_ID(string token)
{
	dfa = 0;
	int i, len = token.length();
	for (i = 0; i < len; i++)
	{
		if (dfa == 0)
			start(token[i]);
		else if (dfa == 1)
			state1(token[i]);
		else
			return 0;
	}
	if (dfa == 1)
		return 1;
	else
		return 0;
}

// driver code
bool isIden(char *str)
{
	stringstream ss(str);
	string token;
	while (ss >> token)
	{
		bool isValid = DFA_for_ID(token);
		if (isValid)
			return true;
		else
			return false;
	}
	return false;
}

void parse(char *str)
{
	int left = 0, right = 0;
	int len = strlen(str);

	while (right <= len && left <= right)
	{
		if (isDelimiter(str[right]) == false)
		{
			right++;
		}
		if (isDelimiter(str[right]) == true && left == right)
		{
			if (isOperator(str[right]) == true)
				printf("'%c'  is not an identifier\n\n", str[right]);

			right++;
			left = right;
		}
		else if (isDelimiter(str[right]) == true && left != right || (right == len && left != right))
		{
			char *subStr = subString(str, left, right - 1);

			if (isKeyword(subStr) == true)
				printf("'%s' is not an identifier\n\n", subStr);

			else if (isInteger(subStr) == true)
				printf("'%s'  is not an identifier\n\n", subStr);

			else if (isRealNumber(subStr) == true)
				printf("'%s' is not an identifier\n\n", subStr);

			else if (isIden(subStr) == true && isDelimiter(str[right - 1]) == false)
			{
				printf("'%s'  IS AN IDENTIFIER\n\n", subStr);
				count_iden++;
			}

			else if (validIdentifier(subStr) == false && isDelimiter(str[right - 1]) == false)
				printf("'%s'  is not a valid identifier\n\n", subStr);
			left = right;
			printf("=====================================\n\n");
		}
	}
	return;
}
// DRIVER FUNCTION
int main()
{
	printf("\n=====================================\n\n");

	char arr[1500];
	ifstream ifs = ifstream("abc.txt", ios_base::in);
	if (ifs.is_open() == true)
	{
		char c;
		int i = 0;
		while (ifs.get(c))
		{
			arr[i] = c;
			i++;
		}
		ifs.close();
		arr[i] = '\0';
		cout << arr << endl;
	}
	else
		cout << "File could not be open!" << endl;

	printf("=====================================\n\n");
	parse(arr);

	printf("**************************************************\n\n");
	printf("Number of valid identifiers: %d\n\n", count_iden);
	printf("**************************************************\n\n");

	return (0);
}
