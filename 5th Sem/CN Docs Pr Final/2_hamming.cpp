// Hamming code
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int m_size, rbit = 0, msg[50], data[60], i, k, j, count = 0;
    cout << "\nEnter message size: ";
    cin >> m_size;

    while (1)
    {
        if ((m_size + rbit + 1) <= (int)pow(2, rbit))
            break;

        rbit++;
    }
    cout << "Enter message: ";
    for (i = m_size; i >= 1; i--)
    {
        cin >> msg[i];
    }
    k = 0; 
    j = 1; 
    for (i = 1; i <= (m_size + rbit); i++)
    {
        if (i == (int)pow(2, k))
        {
            data[i] = 8;
            k++;
        }
        else
        {
            data[i] = msg[j];
            j++;
        }
    }
    for (i = 1; i <= (m_size + rbit); i++)
    {
        if (data[i] == 8)
        {
            data[i] = 0;
            int count = 0;
            for (j = i; j <= (m_size + rbit); j++)
            {
                for (k = 0; k < i; k++)
                {
                    if (data[j] == 1)
                    {
                        count++;
                    }
                    j++;
                }
                j = j + i - 1;
            }

            if (count % 2 == 0)
                data[i] = 1;
            else
                data[i] = 0;
        }
    }
    cout << "\nSender side code: ";
    for (i = (m_size + rbit); i >= 1; i--)
        cout << data[i] << " ";
    cout << "\n\n-------------------------------------------------------\n"
         << endl;

    cout << "Enter receiver side code: ";
    for (i = (m_size + rbit); i >= 1; i--)
        cin >> data[i];

    int c = 0;

    int parities[m_size] = {0};
    for (i = 1; i <= (m_size + rbit); i++)
    {
        if (i == (int)pow(2, c))
        {
            count = 0;
            for (j = i; j <= (m_size + rbit); j++)
            {
                for (k = 0; k < i; k++)
                {
                    if (data[j] == 1)
                    {
                        count++;
                    }
                    j++;
                }
                j = j + i - 1;
            }
            if (data[i] == 1)
                count--;
            if (count % 2 == data[i])
                parities[c] = 1;
            else if (count % 2 != data[i])
                parities[c] = 0;
            c++;
        }
    }
    c = 0;
    for (int i = 0; i < rbit; i++)
    {
        c += parities[i] * ((int)pow(2, i));
    }
    if (c == 0)
    {
        cout << "NO ERROR FOUND !!!" << endl;
        exit(0);
    }
    cout << "\nError at position: " << c << endl;
    data[c] = data[c] == 0 ? 1 : 0;
    cout << "After error correction: ";
    for (i = (m_size + rbit); i >= 1; i--)
    {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}

