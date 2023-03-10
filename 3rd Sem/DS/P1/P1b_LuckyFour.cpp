//Lucky Four
#include<bits/stdc++.h>
using namespace std;
int main()
{                   //Himanshu Agarkar
    int t;          //A45 20010343
    cin >> t;
    while(t--){
        int n, rem, c = 0;
        cin >> n;
        while(n != 0){
            rem = n%10;
            if(rem == 4){
                c++;
            }
            n/=10;
        }
        cout << c;
    }
}