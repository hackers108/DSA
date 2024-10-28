#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data,lh,rh;
    Node *left;
    Node *right;
    Node(int x)
    {
        data=x;
        lh=rh=0;
        left=right=NULL;
    }
};

int height_updater(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }

    root->lh=height_updater(root->left);
    root->rh=height_updater(root->right);

    return (max(root->lh,root->rh)+1);
}

int diameter(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    queue<Node *>q;
    height_updater(root);
    q.push(root);
    int diameter =0;
    while(q.empty()==false)
    {
        Node *curr=q.front();
        q.pop();
        if((curr->lh+curr->rh>diameter))
        {
            diameter=curr->lh+curr->rh;
        }
        if(curr->left!=NULL)
        {
            q.push(curr->left);
        }
        if(curr->right!=NULL)
        {
            q.push(curr->right);
        }

    }
    return (diameter+1);
}


int vertical_breath(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int x=0;
    Node *curr=root;
    while(curr!=NULL)
    {
        curr=curr->left;
        x++;
    }
    curr=root;
    while(curr!=NULL)
    {
        curr=curr->right;
        x++;
    }
    return (x-1);

}

int check_if_subtree_present(Node *T,Node *S)
{
    if(T==NULL&&S==NULL)
    {
        return 1;
    }
    if(S==NULL)
    {
        return 1;
    }
    if(T==NULL)
    {
        return 0;
    }
    queue<Node *>q;
    Node *curr_t=T;
    q.push(curr_t);
    while(q.empty()==false)
    {
        curr_t=q.front();
        if(curr_t->data==S->data)
        {
            break;
        }
        q.pop();
        if(curr_t->left!=NULL)
        {
            q.push(curr_t->left);
        }
        if(curr_t->right!=NULL)
        {
            q.push(curr_t->right);
        }
    }
    if (curr_t->data != S->data) 
    {
        return 0;
    }


    queue<Node *>q_t;
    queue<Node *>q_s;
    q_t.push(curr_t);
    Node *curr_s=S;
    q_s.push(curr_s);
    while(q_s.empty()==false&&q_t.empty()==false)
    {
        curr_t=q_t.front();
        curr_s=q_s.front();
        if(curr_t->data!=curr_s->data)
        {
            return 0;
        }
        q_t.pop();
        q_s.pop();
        if(curr_t->left!=NULL&&curr_s->left!=NULL)
        {
            q_t.push(curr_t->left);
            q_s.push(curr_s->left);
        }
        else if(curr_t->left==NULL&&curr_s->left!=NULL)
        {
            return 0;
        }
        if(curr_t->right!=NULL&&curr_s->right!=NULL)
        {
            q_t.push(curr_t->right);
            q_s.push(curr_s->right);
        }
        else if(curr_t->right==NULL&&curr_s->right!=NULL)
        {
            return 0;
        }

    }
    return 1;
}

void mirror(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    queue<Node *>q;
    q.push(root);
    while (q.empty()==false)
    {
        root=q.front();
        std::cout<<root->data<<" ";
        q.pop();
        
        Node *curr=root->left;
        root->left=root->right;
        root->right=curr;

        if(root->left!=NULL)
        {
            q.push(root->left);
        }
        if (root->right!=NULL)
        {
            q.push(root->right);
        }
    }
   
}

void linklist_to_tree(node *)

int main()
{
    Node *root_1 = new Node(10);
    root_1 -> left = new Node(20);
    root_1 -> right = new Node(30);
    root_1 -> left -> left = new Node(40);
    root_1 -> left -> right = new Node(50);
    root_1 -> right -> left = new Node(60);
    root_1 -> right -> right = new Node(70);
    root_1 -> right -> left -> left = new Node(80);
    root_1 -> right -> left -> left->right =new Node(100);
    Node *root_2 = new Node(30);
    root_2->left= new Node(50);
    root_2->right= new Node(70);
    //cout<<diameter(root_1);
    //cout<<vertical_breath(root_1);
    //itrative_level_order(root_1 -> left -> right);
    //cout<<check_if_subtree_present(root_1,root_2);
    mirror(root_1);
    return 0;
}