
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int count_const = 0;

bool checkDelim(char ch)
{
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
        ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' || ch == '}' || ch == '\n')
        return (true);
    return (false);
}

bool checkConstInt(char *str)
{
    int i, len = strlen(str);

    if (len == 0)
        return (false);
    for (i = 0; i < len; i++)
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' || (str[i] == '-' && i > 0))
            return (false);
    }
    count_const++;
    return (true);
}

bool checkConstRealNum(char *str)
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
    count_const++;

    return (hasDecimal);
}

bool isString(char *str)
{
    int i, len = strlen(str);
    if (len == 0 || str[0] != '\"')
    {
        return (false);
    }
    for (i = 1; i < len - 1; i++)
    {

        if (0 == isalpha(str[i]))
        {
            return (false);
        }
    }
    count_const++;

    return (true);
}
bool isChar(char *str)
{
    int i, len = strlen(str);
    if (len == 0 || str[0] != '\'')
    {
        return (false);
    }
    if (0 == isalpha(str[1]) && len > 3)
        return false;
    count_const++;

    return (true);
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

void checkIdentifier(char *str)
{
    int left = 0, right = 0;
    int len = strlen(str);

    while (right <= len && left <= right)
    {
        if (checkDelim(str[right]) == false)
        {
            right++;
        }
        if (checkDelim(str[right]) == true && left == right)
        {
            right++;
            left = right;
        }
        else if (checkDelim(str[right]) == true && left != right || (right == len && left != right))
        {
            char *subStr = subString(str, left, right - 1);

            if (isString(subStr) == true)
            {
                printf("%s  is a string\n\n", subStr);
                printf("=====================================\n\n");
            }

            if (isChar(subStr) == true)
            {
                printf("%s  is a character\n\n", subStr);
                printf("=====================================\n\n");
            }

            if (checkConstInt(subStr) == true)
            {
                printf("'%s'  is a constant\n\n", subStr);
                printf("=====================================\n\n");
            }

            else if (checkConstRealNum(subStr) == true)
            {
                printf("'%s' is a constant\n\n", subStr);
                printf("=====================================\n\n");
            }

            left = right;
        }
    }
    printf("**********************************************\n");
    printf("**********************************************\n\n");
    printf("Total Number of constants in program: %d\n\n", count_const);
    printf("**********************************************\n");
    printf("**********************************************\n\n");
    return;
}

int main()
{
    printf("\n=====================================\n\n");

    // char str[100] = "";
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
    // printf("Give the input string to know the identifiers present:\n\n");
    // gets(arr);

    printf("\n=====================================\n\n");
    checkIdentifier(arr);

    return (0);
}