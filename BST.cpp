#include <iostream>
#include "Stack.cpp"
using namespace std;
template <class T>
class BST;
template <class T>
class Bnode{
    private :
    Bnode * left, * right;
    T info;
    
    public :
    Bnode();
    friend class BST<T>;
};
template <class T>
Bnode <T> :: Bnode()
{
    left = NULL;
    right = NULL;
}
template <class T>
class BST{
    Bnode <T> * Root;
    int count;
    
    public :
    BST();
    void CreateBST();
    void Insert();
    void Search(T key, Bnode <T> * Loc, Bnode <T> * Par);
    void Del1(T key, Bnode <T> * Loc, Bnode <T> * Par);
    void Del2(T key, Bnode <T> * Loc, Bnode <T> * Par);
    void Delete();
};
template <class T>
BST <T> :: BST()
{
    Root = NULL;
    count = 0;
}
template <class T>
void BST <T> :: CreateBST()
{
    Root = Insert();
}
template <class T>
void BST <T> :: Insert()
{
    T ele;
    Bnode <T> * Loc, * Par;
    cout<<"Enter value to be inserted = ";
    cin>>ele;
    Search(ele,Loc,Par);
    if(Loc != NULL)
    {
        cout<<"Node already Exist!!! Duplicate Entries not allowed."<<endl;
    }
    Bnode <T> * new1 = new Bnode<T>;
    new1 -> info = ele;
    new1 -> left = NULL;
    new1 -> right = NULL;
    if(Par == NULL)
    {
        Root = new1;
    }
    else if(new1 -> info < Par -> info)
    {
        Par -> left = new1;
    }
    else{
        Par -> right = new1;
    }
    count++;
    cout<<count<<endl;
}
template <class T>
void BST <T> :: Search(T key, Bnode <T> * Loc, Bnode <T> * Par)
{
    if(Root == NULL)
    {
        cout<<"Lets Create Tree First!"<<endl;
        Loc = NULL;
        Par = NULL;
    }
    Loc = Par = NULL;
    Bnode <T> * ptr = Root;
    while(ptr != NULL)
    {
        if(key == ptr -> info)
        {
            Loc = ptr;
            cout<<Loc -> info<<endl<<Par -> info<<endl;
        }
        else if(key < ptr -> info)
        {
            Par = ptr;
            ptr = ptr -> left;
        }
        else{
            Par = ptr;
            ptr = ptr -> right;
        }
    }
    if(Loc == NULL)
    {
        cout<<"Key is Not there in Tree,lets Insert it."<<endl;
    }
}
template <class T> 
void BST <T> :: Del1(T key, Bnode <T> * Loc, Bnode <T> * Par)
{
    Bnode <T> * Child;
    if(Loc -> left == NULL && Loc -> right == NULL)
    {
        Child = NULL;
    }
    else if(Loc -> left != NULL)
    {
        Child = Loc -> left;
    }
    else{
        Child = Loc -> right;
    }
    if(Par != NULL)
    {
        if(Loc == Par -> left)
        {
            Par -> left = Child;
        }
        else{
            Par -> right = Child;
        }
    }
    else{
        Root = Child;
    }
}
template <class T>
void BST <T> :: Del2(T key, Bnode <T> * Loc, Bnode <T> * Par)
{
    Bnode <T> * ptr1 = Loc;
    Bnode <T> * ptr2 = Loc -> right;
    while(ptr2 -> left != NULL)
    {
        ptr1 = ptr2;
        ptr2 = ptr2 -> left;
    }
    Del1(key, ptr2, ptr1);
    if(Par != NULL)
    {
        if(Loc == Par -> left)
        {
            Par -> left = ptr2;
        }
        else{
            Par -> right = ptr2;
        }
    }
    else{
        Root = ptr2;
    }
    ptr2 -> left = Loc -> left;
    ptr2 -> right = Loc -> right;
}
template <class T>
void BST <T> :: Delete()
{
    T key;
    Bnode <T> * Loc, * Par;
    cout<<"Enter element to be deleted = ";
    cin>>key;
    Search(key, Loc, Par);
    if(Loc == NULL)
    {
        cout<<"Node does not Exist."<<endl;
    }
    if(Loc -> left != NULL && Loc -> right != NULL)
    {
        Del2(key, Loc, Par);
    }
    else{
        Del1(key, Loc, Par);
    }
}
int main()
{
    BST <int> b;
    int n;
    while(true)
    {
        cout<<"Press\n1.To Insert Element\n2.To Delete Element\n0.Exit."<<endl;
        cin>>n;
        if(n == 0)
        {
            break;
        }
        switch(n)
        {
        case 1 :
        b.Insert();
        break;
        case 2 :
        b.Delete();
        break;
        default :
        cout<<"Invalid Choice !!!"<<endl;
        }
    }
}