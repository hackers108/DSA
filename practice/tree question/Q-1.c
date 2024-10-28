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

void preorder(node *root)//root,l,r;
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right);
}


int main()
{
    node *root = new node(10);
    root -> left = new node(20);
    root -> right = new node(30);
    root -> left -> left = new node(40);
    root -> left -> right = new node(50);
    root -> right -> left = new node(60);
    root -> right -> right = new node(70);
    root -> right -> left -> left = new node(80);
    preorder(root);
    return 0;
}