#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[5], b[5], lead[5], player[5];
    for(int i=0; i<5; i++){
        cout << "p1 " << i+1 << ":";
        cin >> a[i];
        cout << "p2 " << i+1 << ":";
        cin >> b[i];
    }
    int x = 0, y = 0;
    for(int i=0; i<5; i++){
        a[i] += x;
        x = a[i];
        b[i] += y;
        y = b[i];
        lead[i] = abs(a[i] - b[i]);
        player[i] = (a[i] > b[i]) ? 1 : 2;
    }
    int max = lead[0], winner = player[0];
    for(int i=1; i<5; i++){
        if(max < lead[i]){
            max = lead[i];
            winner = player[i];
        }
    }
    cout << winner << " " << max;
    return 0;
}
