#include <bits/stdc++.h>
using namespace std;

int extEucAlgo(int a, int b, int &x, int &y)
{
    if (b == 0)
    {   x = 1;
        y = 0;
        return a;
    }
    else
    {
        int x1, y1;
        int gcd = extEucAlgo(b, a % b, x1, y1);

        x = y1;
        y = x1 - floor(a / b) * y1;

        return gcd;
    }
}

void checkSingleVarLinCong(int A, int B, int N)
{
    A = A % N;
    B = B % N;

    int u = 0, v = 0;

    int d = extEucAlgo(A, N, u, v);

    if (B % d != 0)
    {

        cout << "\nSolution doesnt exist\n" << endl;
        return;
    }

    int x0 = (u * (B / d)) % N;
    if (x0 < 0)
        x0 += N;

    cout << "\n\nNumber of existing solutions: " << d << endl;

    cout << "Solution: " << endl;
    for (int i = 0; i <= d - 1; i++)
        cout << (x0 + i * (N / d)) % N << " ";
}

int main()
{
    int A, B, N;

    cout << "\n\nGive values of A, B, N: " << endl;
    cin >> A >> B >> N;

    checkSingleVarLinCong(A, B, N);

    return 0;
}
