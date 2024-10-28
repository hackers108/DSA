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

bool is_tree_balance(node *root)
{
    if(root==NULL)
    {
        return true;
    }
    queue<node *>q;
    q.push(root);
    int no_of_nodes=1;
    int pre_node=1;
    int next_level_nodes=0;
    int level=0;
    while(q.empty()==false)
    {
        node *curr=q.front();
        cout<<curr->key<<" ";
        q.pop();
        if(curr->left!=NULL)
        {
            q.push(curr->left);
            next_level_nodes++;
        }
        if(curr->right!=NULL)
        {
            q.push(curr->right);
            next_level_nodes++;
        }
        no_of_nodes--;
        if(no_of_nodes==0)
        {
            no_of_nodes=next_level_nodes;
            if(pre_node!=(1<<level) && next_level_nodes>0)
            {
                return false;
            }
            pre_node=next_level_nodes;
            level+=1;
            next_level_nodes=0;
        }

    }
    return true;
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
    root_1 -> right -> left -> left->right =new node(100);
    cout<<is_tree_balance(root_1);
    return 0;
}