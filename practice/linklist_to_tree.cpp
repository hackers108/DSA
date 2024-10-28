#include<bits/stdc++.h>
using namespace std;

struct node_linklist
{
    int key;
    node_linklist *next;
    node_linklist(int x)
    {
        key=x;
        next=NULL;
    }
};

struct node_tree
{
    int key;
    node_tree *left;
    node_tree *right;
    node_tree(int x)
    {
        key=x;
        left=right=NULL;
    }
};
void itrative_level_order(node_tree *root)
{
    if(root==NULL)
    {
        return;
    }
    queue<node_tree *>q;
    node_tree *curr=root;
    q.push(curr);
    while(q.empty()==false)
    {
        curr=q.front();
        cout<<curr->key<<" ";
        q.pop();
        if(curr->left!=NULL)
        {
            q.push(curr->left);
        }
        if(curr->right!=NULL)
        {
            q.push(curr->right);
        }
    }
    return;
}
void preorder(node_tree *root)//root,l,r;
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right);
}



void linklist_to_tree(node_linklist *head)
{
    node_linklist *curr=head;
    vector<node_tree *>v;
    while(curr!=NULL)
    {
        v.push_back(new node_tree(curr->key));
        curr=curr->next;
    }
    v.shrink_to_fit();
    int size=v.size();
    for(int i=0;i<size && (2*i+2)<=size;i++)
    {
        v[i]->left=v[(2*i)+1];
        v[i]->right=v[(2*i)+2];
    }
    itrative_level_order(v[0]);
    cout<<endl;
    preorder(v[0]);
    return;
}

int main()
{
    node_linklist *head=new node_linklist(10);
    head->next=new node_linklist(20);
    head->next->next=new node_linklist(30);
    head->next->next->next=new node_linklist(40);
    head->next->next->next->next=new node_linklist(50);
    head->next->next->next->next->next=new node_linklist(60);
    head->next->next->next->next->next->next=new node_linklist(70);
    head->next->next->next->next->next->next->next=new node_linklist(80);
    linklist_to_tree(head);
    return 0;
}