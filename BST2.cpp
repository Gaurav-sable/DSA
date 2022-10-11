#include <iostream>
#include "Stack.cpp"
#include "BST.h"
#include "BSTQueue.cpp"
using namespace std;

//Constructor of Bnode class
template <class T>
Bnode<T>::Bnode()
{
    //Initialization of Pointers
    left = NULL;    
    right = NULL;
}

//Constructor of BST
template <class T>
BST<T>::BST()
{
    Root = NULL;
    count = 0;
}

//To insert into the tree
template <class T>
void BST<T>::Insert()
{
    Bnode<T> *temp;
    Bnode<T> *new1 = new Bnode<T>;
    T key;
    cout << "Enter data = ";
    cin >> key;
    new1->info = key;
    new1->left = new1->right = NULL;
    if (Root == NULL)
    {
        Root = new1;
    }
    else
    {
        temp = Root;
        while (temp != NULL)
        {
            if (new1->info < temp->info)
            {
                if (temp->left != NULL)
                {
                    temp = temp->left;
                }
                else
                {
                    temp->left = new1;
                    break;
                }
            }
            else if (new1->info > temp->info)
            {
                if (temp->right != NULL)
                {
                    temp = temp->right;
                }
                else
                {
                    temp->right = new1;
                    break;
                }
            }
            else
            {
                cout << "Duplicate Entries not allowed!!!" << endl;
                delete new1;
                break;
            }
        }
    }
    count++;
}

//To search from a tree
template <class T>
void BST<T>::Search()
{
    T key;
    Bnode<T> *Loc, *Par;
    cout << "Enter data to be searched = ";
    cin >> key;
    if (Root == NULL)
    {
        cout << "Lets Create Tree First!" << endl;
        Loc = NULL;
        Par = NULL;
    }
    Loc = Par = NULL;
    Bnode<T> *ptr = Root;
    while (ptr != NULL)
    {
        if (key == ptr->info)
        {
            Loc = ptr;
            if (key == Root->info)
            {
                cout << "It's a Root = " << Loc->info << endl;
                break;
            }
            cout << "Founded Element and its parent = " << Loc->info << endl
                 << Par->info << endl;
            break;
        }
        else if (key < ptr->info)
        {
            Par = ptr;
            ptr = ptr->left;
        }
        else
        {
            Par = ptr;
            ptr = ptr->right;
        }
    }
    if (Loc == NULL)
    {
        cout << "Key is Not there in Tree,lets Insert it." << endl;
    }
}

//Helping method for deletion of node
template <class T>
Bnode<T> *BST<T>::DelNode(Bnode<T> *t, T x)
{
    Bnode<T> *temp;
    if (t == NULL)
    {
        cout << "Element not found." << endl;
        return t;
    }
    if (x < t->info)
    {
        t->left = DelNode(t->left, x);
        return t;
    }
    else if (x > t->info)
    {
        t->right = DelNode(t->right, x);
        return t;
    }
    else
    {
        if (t->left == NULL && t->right == NULL)
        {
            temp = t;
            delete temp;
            return NULL;
        }
        if (t->left == NULL)
        {
            temp = t;
            t = t->right;
            delete temp;
            return t;
        }
        if (t->right == NULL)
        {
            temp = t;
            t = t->left;
            delete temp;
            return t;
        }
        temp = t->right;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        t->info = temp->info;
        t->right = DelNode(t->right, temp->info);
        return t;
    }
}

//To delete a node from tree
template <class T>
void BST<T>::Delete()
{
    T key;
    cout << "Enter element to be Deleted = ";
    cin >> key;
    Root = DelNode(Root, key);
    count--;
    cout<<"Deleted Successfully!!!"<<endl;
}

//Helping method for Inorder Recursive traversal 
template <class T>
void BST<T>::Rec_Inorder(Bnode<T> *t1)
{
    if (t1 != NULL)
    {
        Rec_Inorder(t1->left);
        cout << t1->info << "  ";
        Rec_Inorder(t1->right);
    }
}

//for Recursive Inorder Traversal
template <class T>
void BST<T>::ReInTrav()
{
    if (Root == NULL)
    {
        cout << "Tree does not exist." << endl;    }
    else
    {
        //calling the Helping method
        Rec_Inorder(Root);
    }
}

//Helping method for Recursive Preorder Traversal
template <class T>
void BST<T>::Rec_Preorder(Bnode<T> *t2)
{
    if (t2 != NULL)
    {
        cout << t2->info << "  ";
        Rec_Preorder(t2->left);
        Rec_Preorder(t2->right);
    }
}

//for Recursive Preorder Traversal
template <class T>
void BST<T>::RePreTrav()
{
    if (Root == NULL)
    {
        cout << "Tree does not exist." << endl;
    }
    else
    {
        //calling the Helping method
        Rec_Preorder(Root);
    }
}

//Helping method for Recursive Postorder Traversal
template <class T>
void BST<T>::Rec_Postorder(Bnode<T> *t3)
{
    if (t3 != NULL)
    {
        Rec_Postorder(t3->left);
        Rec_Postorder(t3->right);
        cout << t3->info << "  ";
    }
}

//for Recursive Postorder Traversal
template <class T>
void BST<T>::RePostTrav()
{
    if (Root == NULL)
    {
        cout << "Tree does not exist." << endl;
    }
    else
    {
        Rec_Postorder(Root);
    }
}

//Non recursive Inorder Traversal
template <class T>
void BST<T>::InTrav()
{
    if (Root == NULL)
    {
        cout << "Tree dies not exist." << endl;
    }
    else
    {
        Bnode<T> *temp = Root;
        Stack<Bnode<T> *> st;
        while (temp != NULL)
        {
            st.Push(temp);
            temp = temp->left;
        }
        while (!st.IsEmpty())
        {
            temp = st.IsTop();
            st.Pop();
            cout << temp->info << "  ";
            temp = temp->right;
            while (temp != NULL)
            {
                st.Push(temp);
                temp = temp->left;
            }
        }
    }
}

//Non-Recursive Preorder Traversal
template <class T>
void BST<T>::PreTrav()
{
    if (Root == NULL)
    {
        cout << "Tree does not exist." << endl;
    }
    else
    {
        Bnode<T> *temp = Root;
        Stack<Bnode<T> *> st;
        while (temp != NULL)
        {
            cout << temp->info << "  ";
            st.Push(temp);
            temp = temp->left;
        }
        while (!st.IsEmpty())
        {
            temp = st.IsTop();
            st.Pop();
            temp = temp->right;
            while (temp != NULL)
            {
                cout << temp->info << "  ";
                st.Push(temp);
                temp = temp->left;
            }
        }
    }
}

//Non-Recursive Postorder Traversal
template <class T>
void BST<T>::PostTrav()
{
    if (Root == NULL)
    {
        cout << "Tree does not exist." << endl;
    }
    else
    {
        Bnode<T> *temp = Root;
        Bnode<T> *prev = NULL;
        Stack<Bnode<T> *> st;
        while (temp != NULL || !st.IsEmpty())
        {
            if (temp != NULL)
            {
                st.Push(temp);
                temp = temp->left;
            }
            else
            {
                temp = st.IsTop();
                if (temp->right == NULL || temp->right == prev)
                {
                    cout << temp->info << "  ";
                    st.Pop();
                    prev = temp;
                    temp = NULL;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
}
template <class T>
void BST <T> :: LevelTrav()
{
    if(Root == NULL)
    {
        cout<<"Tree does not exist."<<endl;
    }
    else{
        Bqueue <Bnode <T> *> q(count);
        Bnode <T> * cur;
        q.Enqueue(Root);
        while(!q.IsEmpty())
        {
            cur = q.Front();
            q.Dequeue();
            cout<<cur -> info<<"  ";
                if(cur -> left)
                {
                    q.Enqueue(cur -> left);
                }
                if(cur -> right)
                {
                    q.Enqueue(cur -> right);
                }
            }
        }
    
}

//Helping method to make a mirror image of a tree
template <class T>
void BST <T> :: MirrorImg(Bnode <T> * t)
{
    Bnode <T> * temp;
    if(t != NULL)
    {
        temp = t -> left;
        t -> left = t -> right;
        t -> right = temp;
        MirrorImg(t -> left);
        MirrorImg(t -> right);
    }
    else{
        return;
    }
}

//Method to find Mirror tree 
template <class T>
void BST <T> :: MirrorTree()
{
    if(Root == NULL)
    {
        cout<<"Tree does not exist."<<endl;
    }
    else{
    cout<<"Mirror image created successfully!!!"<<endl;
    MirrorImg(Root);
    }
}

//Gelping method to find leaf nodes of a tree
template <class T>
void BST <T> :: Leaf(Bnode <T> * L)
{
    if(!L)
    {
        return;
    }
    if(!L -> left && !L -> right)
    {
        cout<<L -> info<<"  ";
        return;
    }
    if(L -> left)
    {
        Leaf(L -> left);
    }
    if(L -> right)
    {
        Leaf(L -> right);
    }
}

//Finding Leaf Nodes of a tree
template <class T>
void BST <T> :: DisplayLeaf()
{
    if(Root == NULL)
    {
        cout<<"Tree does not exist."<<endl;
    }
    else{
        cout<<"Leaf nodes of a tree = "<<endl;
        Leaf(Root);
    }
}

//Helping method to find depth of a tree
template <class T>
int BST <T> :: Depth(Bnode <T> * t)
{
    int Hr, Hl;
    if(t == NULL)
    {
        return 0;
    }
    if(t -> left == NULL && t -> right == NULL)
    {
        return 0;
    }
    Hl = Depth(t -> left);
    Hr = Depth(t -> right);
    if(Hl > Hr)
    {
        return (Hl+1);
    }
    else{
        return(Hr+1);
    }
}

//Finding tree depth
template <class T>
void BST <T> :: TreeDep()
{
    cout<<"Depth of Given Tree = "<<Depth(Root)<<endl;
}

//Helping method to crwate a copy of a tree
template <class T>
Bnode <T> * BST <T> :: copy(Bnode <T> * t)
{
    Bnode <T> *p;
    p = NULL;
    if(t != NULL)
    {
        p = new Bnode<T>;
        p -> info = t -> info;
        p -> left = copy(t -> left);
        p -> right = copy(t -> right);
    }
    return p;
}

//Creating a copy of a tree
template <class T>
void BST <T> :: CreateCopy()
{
    Bnode <T> * t;
    t = copy(Root);
    cout<<"Copied Tree = ";
    Rec_Inorder(Root);
}
//Start of main
int main()
{
    BST<int> b;
    int n;
    while (true)
    {
        cout << "\nPress\n1.To Insert Element\n2.To Search Element\n3.To Delete Element\n4.Recursive Inorder Traversal\n5.Recursive Preorder Traversal\n6.Recursive Postorder Traversal\n7.Non Recursive Inorder Traversal\n8.Non Recursive Preorder Traversal\n9.Non Recursive Postorder Traversal\n10.Level wise Traversal\n11.Mirror Tree.\n12.Display Leaf Nodes.\n13.Find Depth of Tree\n14.Creating vopy of a tree\n0.Exit." << endl;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        switch (n)
        {
        case 1:
            b.Insert();
            break;
        case 2:
            b.Search();
            break;
        case 3:
            b.Delete();
            break;
        case 4:
            b.ReInTrav();
            break;
        case 5:
            b.RePreTrav();
            break;
        case 6:
            b.RePostTrav();
            break;
        case 7:
            b.InTrav();
            break;
        case 8:
            b.PreTrav();
            break;
        case 9:
            b.PostTrav();
            break;
            case 10 :
            b.LevelTrav();
            break;
            case 11 :
            b.MirrorTree();
            break;
            case 12 :
            b.DisplayLeaf();
            break;
            case 13 :
            b.TreeDep();
            break;
            case 14 :
            b.CreateCopy();
            break;
        default:
            cout << "Invalid Choice !!!" << endl;
        }
    }
}