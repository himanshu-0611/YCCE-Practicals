#include<bits/stdc++.h>
using namespace std;
int arr[5];
void merge(int a[], int first, int mid, int last)
{
    int b[4];
    int i=first, j=mid+1, k=first;
    while(i<=mid && j<=last){
        if(a[i] <= a[j]){
            b[k] = a[i];
            i++; k++;
        }
        else{
            b[k] = a[j];
            j++; k++;
        }
    }
    while(j<=last){
        b[k] = a[j];
        k++; j++;
    }
    while(i<=mid){
        b[k] = a[i];
        k++; i++;
    }
    for(i=first; i<=last; i++){
        a[i] = b[i];
    }
}

void mergeSort(int a[], int first, int last)
{   
    if(first<last){
        int mid = (first+last)/2;
        mergeSort(a, first, mid);
        mergeSort(a, mid+1, last);
        merge(a, first, mid, last);
    }
}

int main()
{
    int a[] = {4, 3, 6, 1};
    mergeSort(a, 0, 3);
    for(int i=0; i<4; i++){
        cout << a[i] << " ";
    }
    return 0;
}