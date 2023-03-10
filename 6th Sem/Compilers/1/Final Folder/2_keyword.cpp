#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int count_sym[21], nkey = 0;
char sym_tab[21][100] = {"if", "else", "do", "white", "break", "continue", "int", "double", "float", "return", "char", "sizeof", "long", "short", "typedef", "switch", "unsigned", "void", "static", "struct", "goto"};

bool checkDelim(char ch)
{
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
        ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' || ch == '}')
        return (true);
    return (false);
}

bool checkOp(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '>' || ch == '<' ||
        ch == '=')
        return (true);
    return (false);
}

bool checkIden(char *str)
{
    if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
        str[0] == '3' || str[0] == '4' || str[0] == '5' ||
        str[0] == '6' || str[0] == '7' || str[0] == '8' ||
        str[0] == '9' || checkDelim(str[0]) == true)
        return (false);
    return (true);
}

bool checkKeyword(char *str)
{

    for (int i = 0; i < 21; i++)
    {
        if (!strcmp(str, sym_tab[i]))
        {
            count_sym[i]++;
            return true;
        }
    }
    return (false);
}

bool checkInt(char *str)
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

bool checkRealNumber(char *str)
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

void parse(char *str)
{
    int left = 0, right = 0;
    int len = strlen(str);

    while (right <= len && left <= right)
    {
        if (checkDelim(str[right]) == false)
            right++;

        if (checkDelim(str[right]) == true && left == right)
        {
            if (checkOp(str[right]) == true)
                printf("'%c' is not a keyword\n", str[right]);

            right++;
            left = right;
        }
        else if (checkDelim(str[right]) == true && left != right || (right == len && left != right))
        {
            char *subStr = subString(str, left, right - 1);

            if (checkKeyword(subStr) == true)
            {
                printf("'%s' IS A KEYWORD\n", subStr);
                nkey++;
            }

            else if (checkInt(subStr) == true)
                printf("'%s'is not a keyword\n", subStr);

            else if (checkRealNumber(subStr) == true)
                printf("'%s'is not a keyword\n", subStr);

            else if (checkIden(subStr) == true && checkDelim(str[right - 1]) == false)
                printf("'%s' is not a keyword\n", subStr);

            else if (checkIden(subStr) == false && checkDelim(str[right - 1]) == false)
                printf("'%s'is not a keyword\n", subStr);
            left = right;

            printf("\n=====================================\n\n");
        }
    }
    return;
}

int main()
{
    printf("\n=====================================\n\n");

    // char str[100] = "";

    char str[1500];
    ifstream ifs = ifstream("abc.txt", ios_base::in);
    if (ifs.is_open() == true)
    {
        char c;
        int i = 0;
        while (ifs.get(c))
        {
            str[i] = c;
            i++;
        }
        ifs.close();
        str[i] = '\0';
        cout << str << endl;
    }
    else
        cout << "File could not be open!" << endl;

    printf("Symbol Table\n\n");

    for (int i = 0; i < 21; i++)
    {
        printf("%s", sym_tab[i]);
        printf(": %d", count_sym[i]);
        printf("\n");
    }

    // printf("\n\nGive the input string to know the identifiers present:\t");
    // gets(str);
    printf("=====================================\n\n");
    parse(str);

    printf("\n************************************\n\n");
    printf("Number of keyword present:\t%d", nkey);
    printf("\n\n***********************************************\n\n");

    printf("Updated Symbol Table\n\n");
    for (int i = 0; i < 21; i++)
    {
        printf("%s", sym_tab[i]);
        printf(": %d", count_sym[i]);
        printf("\n");
    }

    return (0);
}
