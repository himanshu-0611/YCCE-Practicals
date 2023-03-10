#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int space = 0, tab_space = 0, new_line = 0;
    int c;
    printf("\n\n=====================================\n\n");
    printf("Give input consisting of words and line breaks:\n\n");
    char arr[1500];
    ifstream ifs = ifstream("abc.txt", ios_base::in);
    if (ifs.is_open() == true)
    {
        char c;
        int i = 0;
        while (ifs.get(c))
        {
            arr[i] = c;
            if(c == '\n') ++new_line;
            i++;
        }
        ifs.close();
        arr[i] = '\0';
        cout << arr << endl;
    }
    printf("\n=====================================\n\n");
    printf("Number of newlines:\n\n");
    printf("Line Breaks: \t%d\n", new_line);
    printf("\n=====================================\n\n");
}