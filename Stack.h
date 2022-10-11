#include <iostream>
using namespace std;
template <class T>
class Stack;
template <class T>
class Node
{
    private :
    T info;
    Node <T> *nxt;
    friend class Stack <T> ;

  public:
    Node();
    
};

template <class T>
class Stack
{
    private :
    Node <T> *Top;

  public:
    Stack();
    bool IsEmpty();
    void Push(T Data);
    void Pop();
    void Display();
    T IsTop();
    
};



