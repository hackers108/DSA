#include<bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    node *left;
    node *right;
    node(int x)
    {
        key=x;
        left=right=NULL;
    }
};

int level_order_traverse(node *root,int n1,int n2)
{
    if(root==NULL)
    {
        cout<<"NULL";
        return 0;
    }
    queue<node *>q;
    q.push(root);
    int x=0;
    while(q.empty()==false)
    {
        node *curr=q.front();
        if(curr->key==n1)
        {
            x++;
        }
        if(curr->key==n2)
        {
            x++;
        }
        if(x==2)
        {
            return x;
        }
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
    return x; 
}

void lowest_common_ancestor(node *root,int n1,int n2)
{
    node *curr=root;
    int x=level_order_traverse(curr->left,n1,n2);
    if(x==1)
    {
        cout<<curr->key<<" ";
        return;
    }
    while(x!=1)
    {
        if(x==0)
        {
            curr=curr->right;
            lowest_common_ancestor(curr,n1,n2);
        }
        else
        {
            curr=curr->left;
            lowest_common_ancestor(root,n1,n2);
        }
    }

}  

int main()
{
    node *root_1 = new node(10);
    root_1 -> left = new node(20);
    root_1 -> right = new node(30);
    root_1 -> left -> left = new node(40);
    root_1 -> left -> right = new node(50);
    root_1 -> right -> left = new node(60);
    root_1 -> right -> right = new node(70);
    root_1 -> right -> left -> left = new node(80);
    lowest_common_ancestor(root_1,30,50);
    return 0;
}
