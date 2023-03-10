#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    int n, x;
    cout << "\n\nEnter the value of n: ";
    cin >> n;

    cout << "\n\nAdditive Inverse Pairs: " << n << ": " << endl;
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j<n; j++) {
            if((i+j)%n == 0)
                cout << "( " << i << " , " << j << " ) " << endl;
        }
    }

    cout << "\n\nMultiplicative Inverse Pairs: " << n << ": " << endl;
    for (int i = 1; i < n; i++)
    {
        if (gcd(i, n) == 1)
        {
            for(int i = 0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if((i*j)%n == 1)
                        cout << "( " << i << " , " << j << " ) " << endl;
                }
            }
        } 
    }
    return 0;
}