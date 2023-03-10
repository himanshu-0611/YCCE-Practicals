
#include "bits/stdc++.h"
using namespace std;

string digits = "0123456789", sign = "+-";
string dot = ".", ex = "eE";
int dfa[11][5];

void makeDFA()
{
    dfa[0][0] = 1;

    dfa[1][0] = 1;
    dfa[1][2] = 3;
    dfa[1][3] = 2;
    dfa[1][4] = 6;

    dfa[3][0] = 4;

    dfa[4][0] = 4;
    dfa[4][3] = 5;
    dfa[4][4] = 6;

    dfa[6][0] = 8;
    dfa[6][1] = 7;

    dfa[7][0] = 8;

    dfa[8][0] = 8;
    dfa[8][3] = 9;
}

void buildDFA()
{
    for (int i = 0; i < 11; i++)
        for (int j = 0; j < 5; j++)
            dfa[i][j] = 10;

    makeDFA();
}

void checkDFA(string s)
{
    buildDFA();

    int currentstate = 0;

    for (int i = 0; i < s.size(); i++)
    {

        if (digits.find(s[i]) != digits.npos)

            currentstate = dfa[currentstate][0];

        else if (sign.find(s[i]) != sign.npos)
            currentstate = dfa[currentstate][1];

        else if (dot.find(s[i]) != dot.npos)
            currentstate = dfa[currentstate][2];

        else if (ex.find(s[i]) != ex.npos)
            currentstate = dfa[currentstate][4];

        else
            currentstate = dfa[currentstate][3];
    }

    if (currentstate == 1 || currentstate == 4 || currentstate == 8)
    {
        cout << "Unsigned integer";
    }
    else
    {
        cout << "Not an unsigned integer";
    }
}

int main()
{
    string S = "1729";
    checkDFA(S);

    return 0;
}
