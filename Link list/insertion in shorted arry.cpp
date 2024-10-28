#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node (int x)
    {
        data = x;
        next = NULL;
    }
};

node *insertion_insorted(node *head,int value)
{
    node *temp= new node(value);
    node *curr = head;
    while(curr -> data <= value && curr -> next -> data < value )
    {
        curr = curr -> next;
    }
    temp -> next = curr -> next;
    curr -> next = temp;
    return head;
}




int main()
{
    node *head = new node(10);
    node *temp1 = new node(20);
    node *temp3 = new node(30);
    node *temp4 = new node(40);
    head -> next = temp1 ;
    temp1 -> next = temp3 ;
    temp3 -> next = temp4 ;
    head = insertion_insorted(head,35);
    node *curr =head;
    while(curr != NULL)
    {
        cout << curr-> data << " ";
        curr = curr -> next;
    }
    return 0;
}