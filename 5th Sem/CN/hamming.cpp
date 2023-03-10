#include<iostream>
using namespace std;
int main()
{
    int a[10],b[10],r1,r2,r3;

    cout<<"\nEnter Sender's Data(4 bits):\t";
    cin>>a[7];
    cin>>a[6];
    cin>>a[5];
    cin>>a[3];

    a[1]=a[3]^a[5]^a[7];
    a[2]=a[3]^a[6]^a[7];
    a[4]=a[5]^a[6]^a[7];
    
    cout<<"Sender (Encoded):\t";
    for (int i = 7; i >=1; i--)
    {
        cout<<" "<<a[i];
    }

    cout<<"\nEnter Recievers:\t";
    for (int i = 7; i >=1; i--)
    {
        cin>>b[i];
    }
    r1=b[1]^b[3]^b[5]^b[7];
    r2=b[2]^b[3]^b[6]^b[7];
    r3=b[4]^b[5]^b[6]^b[7];

    int p=r1*1+r2*2+r3*4;
    if(p==0)
    {
        cout<<"No Error"<<endl;
    }
    else
    {
        cout<<"Error found at position: "<<p<<endl;
        cout<<"Recieved:\t";
        for (int i = 7; i >=1; i--)
        {
            cout<<" "<<b[i];
        }
        cout<<""<<endl;
        if (b[p]==0)
        {
            b[p]=1;
        }
        else
        {
            b[p]=0;
        }
        cout<<"After Correction (Sender's):\t";
        for (int i = 1; i < 8; i++)
        {
            cout<<" "<<b[i];
        }   
    }  
    return 0;
}