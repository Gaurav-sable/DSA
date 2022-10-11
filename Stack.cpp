#include "Stack.h"
#include <iostream>
using namespace std;
template <class T>
Node<T>::Node()
{
    nxt = NULL;
}

template <class T>
Stack<T>::Stack()
{
    Top = NULL;
}

template <class T>
bool Stack<T>::IsEmpty()
{
    if(Top == NULL)
    {
        return true;
    }
    else{
        return false;
    }
}

template <class T>
void Stack<T>::Push(T Data)
{
    Node<T> *new1 = new Node<T>;
    new1->info = Data;
    if (Top == NULL)
    {
        Top = new1;
        Top->nxt = NULL;
    }
    else
    {
        new1->nxt = Top;
        Top = new1;
    }
}

template <class T>
void Stack<T>::Pop()
{
    if (Top == NULL)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        Node<T> *temp;
        temp = Top;
        Top = Top->nxt;
        temp->nxt = NULL;
        delete temp;
    }
}

template <class T>
void Stack<T>::Display()
{
    if (Top == NULL)
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        Node<T> *key = Top;
        while (key != NULL)
        {
            cout << key->info << endl;
            key = key->nxt;
        }
    }
}

template <class T>
T Stack<T>::IsTop()
{
    if (!IsEmpty())
    {
        return Top -> info;
    }
    else
    {
        return NULL;
    }
}
