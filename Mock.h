//Mock test
//23339_Gaurav Sable
//Batch :-SE11(F11)

//Including necessary library and files
#include <iostream>
#include "Stack.cpp"
#include "BSTQueue.cpp"
using namespace std;

//Forward Declaration of BST class
template <class T>
class BST;

//Interface to create node
template <class T>
class Bnode{
    private :
    T info;
    Bnode <T> * left, *right;
    
    public :
    Bnode();
    friend class BST<T>;
};

//Interface for BST class
template <class T>
class BST{
    private :
    Bnode <T> * Root;
    int count;
    
    public :
    
    //Constructo for BST
    BST();
    
    //Insertuon method
    void Insert();
    
    //Recursive Inorder Traversal
    void Rec_Inorder(Bnode <T> * t);
    void ReInTrav();
    
    //Recursive Preorder Traversal
    void Rec_Preorder(Bnode <T> * t);
    void RePreTrav();
    
    //Recursive Postorder Traversal
    void Rec_Postorder(Bnode <T> * t);
    void RePostTrav();
    
    //Non Recursive Traversals
    void InTrav();
    void PreTrav();
    void PostTrav();
    
    //Level wise Travesal of the Tree
    void LevelTrav();
};