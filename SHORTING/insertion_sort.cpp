#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int arry[],int n)
{
    for(int i=0;i<n;i++)
    {
        int key=arry[i];
        int j;
        for(j=i-1;(j>=0 && key<arry[j]);j--)
        {
            arry[j+1]=arry[j];
        }

        arry[j+1]=key;

    }
}

int main()
{
    int n;
    cin >> n;
    int arry[n];
    for(int i=0;i<n;i++)
    {
        cin >> arry[i];
    }
    insertion_sort(arry,n);
    for(int i=0;i<n;i++)
    {
        cout << arry[i] << " ";
    }
    return 0;
}