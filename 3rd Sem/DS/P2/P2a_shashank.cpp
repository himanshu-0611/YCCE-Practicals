#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of elements you will enter : ";
    cin >> n;
    int a[n], b[n];
    cout << "Enter elements : " << endl;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        b[i] = 0;           
    }                      
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i != j){
                b[i] = b[i] + a[j];
            }
        }
    }
    cout << "New array" << endl;
    for(int i=0; i<n; i++){
        cout << b[i] << " ";
    }
    return 0;
}
