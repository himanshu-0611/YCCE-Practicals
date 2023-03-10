#include<bits/stdc++.h>
using namespace std;

void quickSort(int a[], int first, int last)
{
    int i, j, pivot, temp;
    if(first<last){
        pivot = first;
        i = first;
        j = last;
        while(i<j){
            while(a[i] >= a[pivot] && i<last)
                i++;
            while(a[j]>a[pivot])
                j--;
            if(i>j){
                swap(a[i], a[j]);
            }
        }
        swap(a[j], a[pivot]);
        quickSort(a, 0, j-1);
        quickSort(a, j+1, last);
    }
}

int main()
{
    int a[] = {4, 3, 56, 1};
    quickSort(a, 0, 3);
    for(int i=0; i<4; i++){
        cout << a[i] << " ";
    }
    return 0;
}