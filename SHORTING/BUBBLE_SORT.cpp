#include<bits/stdc++.h>
using namespace std;

void bubble_short(int arry[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(arry[j]>arry[j+1])
            {
                swap(arry[j],arry[j+1]);
            }
        }
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
    bubble_short(arry,n);
    for(int i=0;i<n;i++)
    {
        cout << arry[i] << " ";
    }
    return 0;
}