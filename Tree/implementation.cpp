#include<bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    node *left;
    node *right;
    node(int value)
    {
        key = value;
        left = NULL;
        right = NULL;
    }
};

void inorder(node *root)/*l,ro,r*/
{
    if(root!= NULL)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
    
}

void preorder(node *root)/*ro,l,r*/
{
    if(root!=NULL)
    {
        cout<< root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root)/*l,r,ro*/
{
    if(root!=NULL)
    {
       postorder(root->left);
       postorder(root->right);
       cout<< root->key<<" "; 
    }

}

int height(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        return max(height(root->left),height(root->right))+1;
    }
}

void print_kth_distance(node *root,int k)
{
    
    if(root==NULL)
    {
        return;
    }
    if(k==0)
    {
        cout <<root->key<<" "; 
    }
    else
    {
        print_kth_distance((root->left), k-1);
        print_kth_distance((root->right),k-1);
    }
}

void level_order_printing(node *root)
{
    int h=height(root);                                 
    for(int i=0;i<=h;i++)
    {
        print_kth_distance(root,i);
        cout<<endl;
    }
   
}

void level_order_printing_on(node *root)
{
    if(root==NULL)
    {
        return;
    }
    queue<node *>q;
    q.push(root);
    while(q.empty()==false)
    {
        node *curr=q.front();
        q.pop();
        cout<<curr->key<<" ";
        if(curr->left!=NULL)
        {
            q.push(curr->left);
        }
        if(curr->right!=NULL)
        {
            q.push(curr->right);
        }
        
    }
}

int getsize(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+getsize(root->left)+getsize(root->right);
}

int max_element(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return max(root->key,max(max_element(root->left),max_element(root->right)));
}

void iteration_inorder(node *root)
{
    stack<node *>s;
    node *curr=root;
    while(curr!=NULL|| s.empty()==false)
    {
        while(curr!=NULL)
        {
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        cout<<curr->key<<" ";
        curr=curr->right;
    }    
}

void iteration_preorder(node *root)//r,l,r
{
    if(root==NULL)
    {
        return;
    }
    stack<node *>s;
    node *curr=root;
    s.push(curr);
    while(s.empty()==false)
    {
        curr=s.top();
        cout<<curr->key<<" ";
        s.pop();
        if(curr->right!=NULL)
        {
           s.push(curr->right);
        }
        if(curr->left!=NULL)
        {
            s.push(curr->left);
        }

    }
}

void space_preorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    stack<node *>s;
    node *curr=root;
    while(curr!=NULL||s.empty()==false)
    {
        while(curr!=NULL)
        {
            cout<<curr->key<<" ";
            if(curr->right!=NULL)
            {
                s.push(curr->right);
            }
            curr=curr->left;
        }    
            if(!s.empty())
            {
                curr=s.top();
                s.pop();
            }
    }
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
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    cout<< height(root);
    cout<<endl;
    print_kth_distance(root,2);
    cout<<endl;
    level_order_printing(root);
    level_order_printing_on(root);
    cout<<endl;
    cout<<getsize(root);
    cout<<endl;
    cout<<max_element(root);
    iteration_inorder(root);
    cout<<endl;
    iteration_preorder(root);
    cout<<endl;
    space_preorder(root);
    return 0;
}



