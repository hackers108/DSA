#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
    node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

node *delete_anyPosition(node *head,int pos)
{
    node *curr= head;
    int p=1;
    while(p<pos)
    {
        curr = curr ->next;
        p++;
    }
    curr ->next ->prev = curr ->prev;
    curr ->prev ->next = curr ->next;
    delete curr;
    return head;

}

node *head_insert(node *head )
{
    node *temp= new node(5);
    temp -> next = head -> next;
    head -> next ->prev = temp;
    head -> next = temp ;
    temp -> prev = head;
    int x= temp -> data;
    temp ->data = head->data;
    head-> data = x;
    return head;
}



int main()
{
    node *head = new node(10);
    node *temp1 = new node(20);
    node *temp2 = new node(30);
    node *temp3 = new node(40);
    head -> next = temp1;
    temp1 -> prev = head;
    temp1-> next = temp2;
    temp2 -> prev = temp1;
    temp2 -> next =temp3;
    temp3 -> prev=temp2;
    head_insert(head);
    node *curr = head;
    delete_anyPosition(head,3);
    cout << curr -> data << " ";
    
    while(curr -> next != NULL)
    {
        curr = curr -> next;
        cout << curr -> data << " ";
        
    }
    cout << endl;
    cout << curr -> data << " ";
    curr = curr -> prev;
    while(curr != NULL)
    {
        cout << curr -> data << " ";
        curr = curr -> prev;
    }
    return 0;
}