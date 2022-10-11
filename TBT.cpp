#include <iostream>
#include "TBT.h"
using namespace std;

//Implementation of class TBT
template <class T>

//TBT Constructor for initialization of pointers
TBT<T>::TBT()
{
    Root = new Node<T>;
    Root->left = Root;
    Root->right = Root;
    Root->lthread = 0;
    Root->rthread = 1;
}

//Implementing the creation of TBT
template <class T>
void TBT<T>::Create()
{
    T data;
    bool dirleft, dirright;
    int n;
    cout << "Enter no. of Elements to add : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Node<T> *new1 = new Node<T>;
        cout << "Enter data "<<(i+1)<<" : ";
        cin >> data;
        new1->info = data;
        if (Root == Root->left && Root->right == Root)
        {
            new1->left = Root;
            Root->left = new1;
            new1->lthread = Root->lthread;
            Root->lthread = 1;
            new1->right = Root;
        }
        else
        {
            Node<T> *cur = Root->left;
            while (true)
            {
                if (cur->info > new1->info)
                {
                    if (cur->lthread == 0)
                    {
                        dirleft = true;
                        dirright = false;
                        break;
                    }
                    else
                    {
                        cur = cur->left;
                    }
                }
                else
                {
                    if (cur->rthread == 0)
                    {
                        dirleft = false;
                        dirright = true;
                        break;
                    }
                    else
                    {
                        cur = cur->right;
                    }
                }
            }
            if (dirleft)
            {
                new1->left = cur->left;
                cur->left = new1;
                new1->lthread = cur->lthread;
                cur->lthread = 1;
                new1->right = cur;
            }
            else if (dirright)
            {
                new1->right = cur->right;
                cur->right = new1;
                new1->rthread = cur->rthread;
                cur->rthread = 1;
                new1->left = cur;
            }
        }
    }
}

//Finding Inorder Succesor
template <class T>
Node<T> *TBT<T>::FindInSuc(Node<T> *I)
{
    if (I->rthread == 0)
    {
        return I->right;
    }
    else
    {
        I = I->right;
        while (I->lthread != 0)
        {
            I = I->left;
        }
        return I;
    }
}

//Implementation of Inorder Traversal
template <class T>
void TBT<T>::InTrav()
{
    Node<T> *cur = Root->left;
    while (cur->lthread == 1)
    {
        cur = cur->left;
    }
    while (cur != Root)
    {
        cout << cur->info << "  ";
        cur = FindInSuc(cur);
    }
}

//Implementing Preorder Traversal
template <class T>
void TBT<T>::PreTrav()
{
    Node<T> *cur = Root->left;
    while (cur != Root)
    {
        while(cur -> lthread != 0)
        {
        cout<<cur -> info<<"  ";
        cur = cur -> left;
        }
        cout<<cur -> info<<"  ";
        while(cur -> rthread == 0)
        {
            cur = cur -> right;
            if(cur == Root)
            {
                break;
            }
        }
        cur = cur -> right;
    }
}
        
//Start of Main
int main()
{
    TBT<int> t;
    int n;
    while (true)
    {
        cout << "\nPress\n1.To create TBT\n2.Inorder Traversal\n3.Preorder Traversal.\n0.Exit." << endl;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        switch (n)
        {
        case 1:
            t.Create();
            break;
        case 2:
            t.InTrav();
            break;
        case 3:
            t.PreTrav();
            break;
        default:
            cout << "Invalid  Choice." << endl;
        }
    }
}
