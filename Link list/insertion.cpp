#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};

void begin_insertion(node *&head,int n)
{
    node *temp = new node(n);
    temp -> next = head;
    head = temp;
}

void any_position(node *&head,int k,int pos)
{
    node *temp = new node(k);
    int p=1;
    node *curr = head;
    while(p!= pos)
    {
        curr = curr -> next;
        p++;
    }
    temp -> next = curr -> next;
    curr -> next = temp;
}

void delete_head(node *&head)
{
    node *temp = head;
    head = head ->next;
    delete temp;
    
}

void delete_anyPosition(node *&head,int pos)
{
    int p=1;
    node *curr = head;
    while(p <pos-1)
    {
        curr = curr -> next;
        p++;
    }
    node *temp = curr -> next; 
    curr -> next = curr -> next -> next;
    delete temp;
}

int main()
{
    node *head = new node(10);
    node *temp1 = new node(20);
    node *temp2 = new node(30);
    node *temp3 =new node(40);
    head -> next = temp1;
    temp1 ->next = temp2;
    temp2 -> next = temp3;
    begin_insertion(head,5);
    any_position(head, 25,3);
    delete_head(head);
    delete_anyPosition(head,3);
    node *current = head;
    while(current != NULL)
    {
        cout << current -> data << " ";
        current = current -> next;
    }
    return 0;
}