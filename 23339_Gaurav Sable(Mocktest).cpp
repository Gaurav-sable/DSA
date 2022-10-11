//Mock Test
//23339_ Gaurav Sable
//Batch :- SE11(F11)

//Including necessary libraries and files
#include <iostream>
#include "Mock.h"
using namespace std;

//Constructor for Bnode class
template <class T>
Bnode<T>::Bnode()
{
    //Initialization of Pointers
    left = NULL;
    right = NULL;
}

//BST Constructor
template <class T>
BST<T>::BST()
{
    Root = NULL;
}

//Insert method
template <class T>
void BST<T>::Insert()
{
    T key;
    cout << "Enter the Data to be Inserted = ";
    cin >> key;
    Bnode<T> *new1 = new Bnode<T>;
    new1->info = key;
    new1->left = NULL;
    new1->right = NULL;
    if (Root == NULL)
    {
        Root = new1;
    }
    else
    {
        Bnode<T> *temp = Root;
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
                cout << "Duplicate Entries not allowed." << endl;
                delete new1;
                break;
            }
        }
    }
    count++;
}

//Helping method for Recursive Inoreder Traversal
template <class T>
void BST<T>::Rec_Inorder(Bnode<T> *t)
{
    if (t != NULL)
    {
        Rec_Inorder(t->left);
        cout << t->info << "  ";
        Rec_Inorder(t->right);
    }
}

//Recirsive Inorder Traversal method
template <class T>
void BST<T>::ReInTrav()
{
    if (Root == NULL)
    {
        cout << "Tree is Empty....." << endl;
    }
    else
    {
        Rec_Inorder(Root);
    }
}

//Helping method for Recursive Preorder Traversal
template <class T>
void BST<T>::Rec_Preorder(Bnode<T> *t)
{
    if (t != NULL)
    {
        cout << t->info << "  ";
        Rec_Preorder(t->left);
        Rec_Preorder(t->right);
    }
}

//Recursive Preorder Traversal method
template <class T>
void BST<T>::RePreTrav()
{
    if (Root == NULL)
    {
        cout << "Tree is Empty...." << endl;
    }
    else
    {
        Rec_Preorder(Root);
    }
}

//Helping method for Recursive Postorder Traversal
template <class T>
void BST<T>::Rec_Postorder(Bnode<T> *t)
{
    if (t != NULL)
    {
        Rec_Postorder(t->left);
        Rec_Postorder(t->right);
        cout << t->info << "  ";
    }
}

//Recursive Postorder Traversal method
template <class T>
void BST<T>::RePostTrav()
{
    if (Root == NULL)
    {
        cout << "Tree is Empty...." << endl;
    }
    else
    {
        Rec_Postorder(Root);
    }
}

//Non Recursive Inorder Traversal
template <class T>
void BST<T>::InTrav()
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

//Non Recursive Preorder Traversal
template <class T>
void BST<T>::PreTrav()
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

//Non Recursive Postorder Traversal
template <class T>
void BST<T>::PostTrav()
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

//Levelwise Traversal of a Tree
template <class T>
void BST<T>::LevelTrav()
{
    if (Root == NULL)
    {
        cout << "Tree does not exist." << endl;
    }
    else
    {
        Bqueue<Bnode<T> *> q(count);
        Bnode<T> *cur;
        q.Enqueue(Root);
        while (!q.IsEmpty())
        {
            cur = q.Front();
            q.Dequeue();
            cout << cur->info << "  ";
            if (cur->left)
            {
                q.Enqueue(cur->left);
            }
            if (cur->right)
            {
                q.Enqueue(cur->right);
            }
        }
    }
}

//Start of Main
int main()
{
    BST<int> b;
    int n;
    while (true)
    {
        cout << "\nPress\n1.To insert Element in tree\n2.Recursive Inorder Traversal\n3.Recursive Preorder Traversal\n4.Recursive Postorder Traversal\n5.Non Recursive Inorder Traversal\n6.Non Recursive Preorder Traversal\n7.Non Recursive Postorder Traversal\n8.Level Traversal of Tree\n0.Exit" << endl;
        cout << "Choose your Opeartion = ";
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
            b.ReInTrav();
            break;
        case 3:
            b.RePreTrav();
            break;
        case 4:
            b.RePostTrav();
            break;
        case 5:
            b.InTrav();
            break;
        case 6:
            b.PreTrav();
            break;
        case 7:
            b.PostTrav();
            break;
        case 8:
            b.LevelTrav();
            break;
        default:
            cout << "Invalid Choice...." << endl;
        }
    }
}
