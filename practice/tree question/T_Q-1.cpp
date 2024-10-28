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

void itrative_preorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    stack<node *>s;
    s.push(root);
    node *curr;
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

void spaceOptimize_preorder(node *root)
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
        if(s.empty()==false)
        {
            curr=s.top();
            s.pop();
        }

    }
}

void itrative_inorder(node *root)//l,root,right
{
    if(root == NULL)
    {
        return;
    }
    stack<node *>s;
    node *curr=root;
    while(curr!=NULL||s.empty()==false)
    {
        while(curr!=NULL)
        {
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        cout<<curr->key<<" ";
        s.pop();
        curr=curr->right;
    }
    
}

int height_tree(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+max(height_tree(root->left),height_tree(root->right));
}

void print_kth_node(node *root,int k)
{
    if(root==NULL)
    {
        return;
    }
    node *curr=root;
    if(k==0)
    {
        cout<<curr->key<<" ";
    }
    print_kth_node(curr->left, k-1);
    print_kth_node(curr->right, k-1);
}

void level_order(node *root)
{
    int h=height_tree(root);
    for(int i=0;i<h;i++)
    {
        print_kth_node(root,i);
        cout<<endl;
    }
}

void itrative_level_order(node *root)
{
    if(root==NULL)
    {
        return;
    }
    queue<node *>q;
    node *curr=root;
    q.push(curr);
    while(curr!=NULL||q.empty()==false)
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
}

bool tree_comparision(node *r1,node *r2)
{
    if(r1==NULL&&r2==NULL)
    {
        return true;
    }
    if(r1==NULL||r2==NULL)
    {
        return false;
    }
    queue<node *>q1,q2;
    q1.push(r1);
    q2.push(r2);
    vector<int>v1,v2;
    while(q1.empty()==false)
    {
        node *curr_1=q1.front();
        q1.pop();
        v1.push_back(curr_1->key);
        if(curr_1->left!=NULL)
        {
            q1.push(curr_1->left);
        }
        if(curr_1->right!=NULL)
        {
            q1.push(curr_1->right);
        }
    }
    while(q2.empty()==false)
    {
        node *curr_2=q2.front();
        q2.pop();
        v2.push_back(curr_2->key);
        if(curr_2->left!=NULL)
        {
            q2.push(curr_2->left);
        }
        if(curr_2->right!=NULL)
        {
            q2.push(curr_2->right);
        }
    }
    int h1=v1.size();
    int h2=v2.size();
    if(h1!=h2)
    {
        return false;
    }
    else
    {
        for(int i=0;i<h1;i++)
        {
            if(v1[i]!=v2[i])
            {
                return false;
            }
            else 
            {
                continue;
            }
        }
        return true;
    }

}

bool sumOf_child(node *root)
{
    if(root==NULL)
    {
        return false;
    }
    queue<node *>q;
    q.push(root);
    while(q.empty()==false)
    {
        node *curr=q.front();
        q.pop();
        if(curr->left!=NULL || curr->right!=NULL)
        {
            node *h1=curr->left;
            q.push(curr->left);
            node *h2=curr->right;
            q.push(curr->right);
            if(curr->key!=(h1->key+h2->key))return false;
        }
        if(curr->left!=NULL && curr->right!=NULL)
        {
            return true;
        }
        
    }
    return false;
}

void iterative_endline_levelorder(node *root)
{
    if(root==NULL)
    {
        cout<<"NULL";
    }
    queue<node *>q;
    q.push(root);
    int no_of_nodes=1;
    int next_level_nodes=0;
    int level=1;
    while(q.empty()==false)
    {
        node *curr=q.front();
        q.pop();
        cout<<curr->key<<" ";
        if(level % 2!=0)
        {
            
        }
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
            level+=1;
            next_level_nodes=0;
            cout<<endl;
        }

    }
}


/*void iterative_endline_levelorder(node *root)
{
    if(root==NULL)
    {
        cout<<"NULL";
    }
    queue<node *>q;
    q.push(root);
    int max_width=root->key;
    int no_of_nodes=1;
    int next_level_nodes=0;
    int level=1;
    while(q.empty()==false)
    {
        node *curr=q.front();
        q.pop();
        cout<<curr->key<<" ";
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
            level+=1;
            if(next_level_nodes>max_width)
            {
                max_width=next_level_nodes;
            }
            next_level_nodes=0;
            cout<<endl;
        }

    }
    cout<<endl;
    cout<<max_width;
}



/*void spiral_line_by_line_printing(node *root)
{
    if(root==NULL)
    {
        cout<<"NULL";
        return;
    }
    vector<node *>v;
    vector<int>leafcount;
    v.push_back(root);
    leafcount.push_back(1);


    int current_level_elementsno=1;
    int next_level_leafcount=0;
    int level=0;
    int no_of_nodes=1;
    int i=0;
    while(v.empty()==false)
    {
        node *curr=v[i];
        if(curr->left!=NULL)
        {
            v.push_back(curr->left);
            next_level_leafcount++;
        }
        if(curr->right!=NULL)
        {
            v.push_back(curr->right);
            next_level_leafcount++;
        }
        current_level_elementsno--;
        if(current_level_elementsno == 0)
        {
            current_level_elementsno=next_level_leafcount;
            leafcount.push_back(next_level_leafcount);
            no_of_nodes+=next_level_leafcount;
            next_level_leafcount=0;
            level++;
        }
        i++;

    }
    v.shrink_to_fit();
    leafcount.shrink_to_fit();
    int j=0;
    while (j < level) 
    {
        if (j % 2 == 0)
        { 
            int start_index = 0; 
            for (int idx = 0; idx < j; idx++) {
                start_index += leafcount[idx]; 
            }
            for (int idx = start_index; idx < start_index + leafcount[j]; idx++) {
                cout << v[idx]->key << " "; 
            }
        } 
        else 
        { 
            int end_index = 0; 
            for (int idx = 0; idx <= j; idx++)
            {
                end_index += leafcount[idx]; 
            }
            for (int idx = end_index - 1; idx >= end_index - leafcount[j]; idx--)
            {
                cout << v[idx]->key << " "; 
            }
        }
        cout << endl; 
        j++; 
    }
}*/

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
    /*node *root_2 = new node(10);
    root_2 -> left = new node(20);
    root_2 -> right = new node(30);
    root_2 -> left -> left = new node(40);
    root_2 -> left -> right = new node(50);
    root_2 -> right -> left = new node(60);
    root_2 -> right -> right = new node(70);
    root_2 -> right -> left -> left = new node(80);
    preorder(root_1);
    cout<<endl;
    itrative_preorder(root_1);
    cout<<endl;
    spaceOptimize_preorder(root_1);
    cout<<endl;
    itrative_inorder(root_1);
    cout<<endl;
    cout<<height_tree(root);
    cout<<endl;
    print_kth_node(root_1, 2);
    cout<<endl;
    level_order(root_1);
    cout<<endl;
    itrative_level_order(root_1);
    cout<<tree_comparision(root_1, root_2);
    cout<<sumOf_child(root_1);*/
    iterative_endline_levelorder(root_1);
    //spiral_line_by_line_printing(root_1);
    return 0;
}