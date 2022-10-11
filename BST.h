#include <iostream>
using namespace std;

//Forward Declaration of BST class 
template <class T>
class BST;

//To create Node
template <class T>
class Bnode
{
  private:
    Bnode *left, *right;
    T info;

  public:
    Bnode();
    friend class BST<T>;
};

//Interface of a class BST
template <class T>
class BST
{
    Bnode<T> *Root;  //Pointer to Root Node
    int count;

  public:
  
  //Contructor of BST
    BST();
    void Insert();  //To insert new Node
    void Search();  //To search a node
    
    //To delete a node from tree
    Bnode<T> *DelNode(Bnode<T> *t, T x);
    void Delete();
    
    //Helping methods for Recursive traversals
    void Rec_Inorder(Bnode<T> *t1);
    void Rec_Preorder(Bnode<T> *t2);
    void Rec_Postorder(Bnode<T> *t3);
    
    //Recursive Traversal methods
    void ReInTrav();
    void RePreTrav();
    void RePostTrav();
    
    //Non Recursive Traversal methods
    void InTrav();
    void PreTrav();
    void PostTrav();
    
    //Level Traversal method
    void LevelTrav();
    
    //Making a mirror image of Tree
    void MirrorImg(Bnode <T> *t);
    void MirrorTree();
    
    //Finding leaf nodes of a tree
    void Leaf(Bnode <T> * L);
    void DisplayLeaf();
    
    //Finding Depth of tree
    int Depth(Bnode <T> * t);
    void TreeDep();
    
    //To create copy of a tree
    Bnode <T> * copy(Bnode <T> * t);
    void CreateCopy();
};