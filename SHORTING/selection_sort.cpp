#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arry[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=arry[i];
        int sudo=0;
        for(int j=i+1;j<n;j++)
        {
            if(arry[j]<min)
            {
                min=arry[j];
                sudo=j;
            }
           
        }
        if(sudo!=i)
        {
            swap(arry[i],arry[sudo]);
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
    selection_sort(arry,n);
    for(int i=0;i<n;i++)
    {
        cout << arry[i] << " ";
    }
    return 0;
}