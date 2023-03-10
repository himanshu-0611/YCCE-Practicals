//Loop
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int l=0, o=0, p=0, c=0;
    string s;
    cin >> s;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'l'){
            l++;
        }
        if(s[i] == 'o'){
            o++;
        }
        if(s[i] == 'p'){
            p++;
        }
    }
    for(int i=0; i<l; i++){
        if(s[i] != 'l'){
            cout << "No";
            c++;
            break;
        }
    }
    for(int i=l; i<o+l; i++){
        if(s[i] != 'o'){
            cout << "No";
            c++;
            break;
        }
    }
    for(int i=o+l; i<s.size(); i++){
        if(s[i] != 'p'){
            cout << "No";
            c++;
            break;
        }
    }
    if(l==p && o == 2*l && o == 2*p){
        cout << "Yes";
        c++;
    }
    if(c == 0){
        cout << "No";
    }
    return 0;
}