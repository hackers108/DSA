#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x) /*constructor*/
    {
        data = x;
        next = NULL;
    }
};

int main()
{
    node *head =  new node(10); /*new dynamically memory allocation*/
    node *temp1 = new node(20); 
    head -> next = temp1;
    node *current= head;
    while(current != NULL)
    {
        cout << current -> data << endl;
        cout << current -> next << endl;
        current = current -> next;
    }
    return 0;
}