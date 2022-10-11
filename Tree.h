#include <iostream>
#include "Stack.cpp"
using namespace std;
class Tree;    // Forward Declaration of                                 class Tree

//class to create linked list
class Tnode{
    private :
    char info;
    Tnode * left;
    Tnode * right;
    
    public :
    Tnode();
    friend class Tree;
};

//ADT for Expression Tree
class Tree
{
  private:
    Tnode *Root;
    char E[40];

  public:
    void ExpTree();  //To create Expression                                     Tree
    //Required methods for Recursive Inorder Traversals
    void ReInTrav();
    void Rec_Inorder(Tnode *);
    
    //Methods for Revursive Preorder Traversal
    void RePreTrav();
    void Rec_Preorder(Tnode *);
    
    //Methods for Recursive Postorder Traversal
    void RePostTrav();
    void Rec_Postorder(Tnode *);
    
    //Non Recursive Traversals
    void InTrav();
    void PreTrav();
    void PostTrav();
};