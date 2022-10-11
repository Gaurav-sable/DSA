#include <iostream>
using namespace std;

//Forward Declaration of Generic class TBT
template <class T>
class TBT;

//Using linked list to implement TBT
template <class T>
class Node
{
  private:
    T info;
    Node<T> *left, *right;  //Declaring Pointers
    int lthread, rthread;   //Declaring left and right bit

    friend class TBT<T>;
};

//ADT of Generic TBT class
template <class T>
class TBT
{
  private:
    Node<T> *Root;  //Declaring Root Pointer

  public:
    TBT();
    
    //Creating TBT
    void Create();  
    
    //Finding Inorder Succeser for inorder traversal
    Node<T> *FindInSuc(Node<T> *I);
    void InTrav();
    
    //Preorder traversal
    void PreTrav();
};