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

void spirel_printing(node *root)
{
    if(root==NULL)
    {
        cout<<"null";
    }
    queue<node *>q;
    q.push(root);
    int no_of_currentlevel_node=1;
    int no_of_node_remaning=1;
    int next_line_node=0;
    int level=0;
    queue<int>qp;
    stack<int>sp;
    while(q.empty()==false)
    {
        node *curr=q.front();
        if(level%2==0)
        {
            qp.push(curr->key);
        }
        else
        {
            sp.push(curr->key);
        }
        q.pop();
        if(curr->left!=NULL)
        {
            q.push(curr->left);
            next_line_node++;
        }
        if(curr->right!=NULL)
        {
            q.push(curr->right);
            next_line_node++;
        }
        no_of_node_remaning--;
        if(no_of_node_remaning==0)
        {
            int x=no_of_currentlevel_node;
            if(level%2==0)
            {
                while(x!=0)
                {
                    cout<<qp.front()<<" ";
                    qp.pop();
                    x--;
                }
                cout<<endl;
            }
            else
            {
                while(x!=0)
                {
                    cout<<sp.top()<<" ";
                    sp.pop();
                    x--;
                }
                cout<<endl;
            }
            no_of_currentlevel_node = next_line_node;
            no_of_node_remaning=next_line_node;
            next_line_node=0;
            level++;

        }
    }
}

void left_view_printing(node *root)
{
    if(root==NULL)
    {
        cout<<"null";
    }
    queue<node *>q;
    q.push(root);
    int current_nodes=1;
    int nodes_remaning=1;
    int nextlevel_nodes=0;
    int level=0;

    while(q.empty()==false)
    {
        node *curr=q.front();
        if(nodes_remaning==current_nodes)
        {
            cout<<curr->key<<" ";
        }
        q.pop();
        if(curr->left!=NULL)
        {
            q.push(curr->left);
            nextlevel_nodes++;
        }
        if(curr->right!=NULL)
        {
            q.push(curr->right);
            nextlevel_nodes++;
        }                                             
        nodes_remaning--;
        if(nodes_remaning==0)
        {
            current_nodes=nextlevel_nodes;
            nodes_remaning=nextlevel_nodes;
            nextlevel_nodes=0;
            level++;
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
    //spirel_printing(root_1);
    left_view_printing(root_1);
    return 0;
}