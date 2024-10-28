#include<bits/stdc++.h>
using namespace std;

struct Mystack
{
    int *arr;
    int cap;
    int top;
    Mystack(int c)
    {
        cap=c;
        arr= new int[cap];
        top=-1;
    }

    void push(int x)
    {
        top++;
        arr[top]=x;
    }

    int pop()
    {
        int result =arr[top];
        top--;
        return result;
    }

    int peek()
    {
        return arr[top];
    }

    int size()
    {
        return (top+1);
    }

    bool isempty()
    {
        return (top == -1);
    }
};

int main()
{
    Mystack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<< s.pop()<< endl;
    s.pop();
    cout << s.peek()<<endl;
    cout << s.size()<< endl;
    cout << s.isempty()<<endl;
    return 0;

}