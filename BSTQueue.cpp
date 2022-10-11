#include <iostream>
using namespace std;
template <class T>
class Bqueue{
    T * queue;
    int size;
    int rear, front;
    
    public :
    Bqueue(int c);
    //~Bqueue();
    bool IsFull();
    bool IsEmpty();
    void Enqueue(T ele);
    void Dequeue();
    T Front();
};
template <class T>
Bqueue <T> :: Bqueue(int c)
{
    front = -1;
    rear = -1;
    size = c;
    queue = new T;
}
/*template <class T>
Bqueue <T> :: ~Bqueue()
{
    delete[] queue;
}*/
template <class T> 
bool Bqueue <T> :: IsFull()
{
    if((front == 0) && (rear == size - 1))
    {
    return true;
    }
    else{
        return false;
    }
}
template <class T>
bool Bqueue <T> :: IsEmpty()
{
    if(front == -1 || front > rear)
    {
        return true;
    }
    else{
        return false;
    }
}
template <class T>
void Bqueue <T> :: Enqueue(T ele)
{
    if(IsFull())
    {
        cout<<"Queue Overflow."<<endl;
        return;
    }
    else{
        if(front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = ele;
    }
    return;
}
template <class T>
void Bqueue <T> :: Dequeue()
{
    if(IsEmpty())
    {
        cout<<"Queue underflow."<<endl;
        return;
    }
    else{
        front++;
    }
    return;
}
template <class T>
T Bqueue <T> :: Front()
{
    if(IsEmpty())
    {
        return NULL;
    }
    else{
        return queue[front];
    }
}