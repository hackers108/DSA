#include<bits/stdc++.h>
using namespace std;

struct Queue
{
    int *arr;
    int size;
    int cap;
    Queue(int c)
    {
        cap = c;
        arr = new int [cap];
        size =0;
    }

    void enqueue(int value)
    {
        arr[size]=value;
        size++;
    
    }

    int deQueue()              
    {  
        int f=arr[0];
        for(int i=0;i<size-1;i++)  
        {
            arr[i]=arr[i+1];
        }
        size--;
        return f;

    }

    int getFront()
    {
        return arr[0];
    }
  
    int getRear()
    {
        return arr[size];
    }

    bool isFull()
    {
        return ((size+1) == cap);
    }

    int sizeo()
    {
        return (size);
    }
};

int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.sizeo() << endl;
    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
    cout << q.isFull() << endl;
    return 0;
}