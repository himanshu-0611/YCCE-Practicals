#include <bits/stdc++.h>
using namespace std;

int modInverse(int A, int M)
{
    int q, r1=M, dup = M, r2=A, r, t1 = 0, t2 = 1, count = 0;
    int t;

    while(r1 > 0 && r2 > -1) {
        q = r1 / r2;
        r = r1 % r2;
        r1 = r2;
        r2 = r;

        if(count > 0) {
            t1 = t2;
            t2 = t;
        }
        t = t1 - q*t2;
        count++;

        if(r1 == 1 && r2 == 0) {
            if (count > 0)
            {
                t1 = t2;
                t2 = t;
            }
            t = t1 - q * t2;
            if(t1 < 0) return t1 + dup;
            else return t1;
        }
    }
}

int main()
{
    int A, M;
    cout << "\nEnter values of A and M" << endl;
    cin >> A >> M;
    cout << "\nMultiplicative Inverse is\t" << modInverse(A, M) << "\n\n";
    return 0;
}