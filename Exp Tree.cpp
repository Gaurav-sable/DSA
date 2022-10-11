#include "Tree.h"
#include <iostream>
using namespace std;

//Constructor for Tnode class
Tnode ::Tnode()
{
    left = NULL; //Initializing the Pointers
    right = NULL;
}

//Creating Expression Tree
void Tree ::ExpTree()
{
    Stack<Tnode *> st;
    cout << "Enter Postfix Expression(No digits allowed) : ";
    cin.ignore();
    cin.getline(E, 100);
    for (int i = 0; i < strlen(E); i++)
    {
        //Creating new Node
        Tnode *new1 = new Tnode();
        if (isalpha(E[i]))
        {
            new1->info = E[i];
            st.Push(new1);
        }
        else if (E[i] == '^' || E[i] == '*' || E[i] == '/' || E[i] == '+' || E[i] == '-')
        {
            new1->info = E[i];
            if (!st.IsEmpty())
            {
                new1->right = st.IsTop();
                st.Pop();
                new1->left = st.IsTop();
                st.Pop();
            }
            st.Push(new1);
        }
        else
        {
            cout << "Wrong Input!!! Please Enter Correctly." << endl;
        }
        Root = st.IsTop();
    }
    st.Pop();
}

//Helping method for Recursive Inorder Traversal
void Tree ::Rec_Inorder(Tnode *t1)
{
    if (t1 != NULL)
    {
        Rec_Inorder(t1->left);
        cout << t1->info << "  ";
        Rec_Inorder(t1->right);
    }
}

//for Recursive Inorder Traversal
void Tree ::ReInTrav()
{
    cout<<"Obtained Infix Expression = ";
    //calling the Helping method
    Rec_Inorder(Root);
}

//Helping method for Recursive Preorder Traversal
void Tree ::Rec_Preorder(Tnode *t2)
{
    if (t2 != NULL)
    {
        cout << t2->info << "  ";
        Rec_Preorder(t2->left);
        Rec_Preorder(t2->right);
    }
}

//for Recursive Preorder Traversal
void Tree ::RePreTrav()
{
    cout<<"Obtained Prefix Expression = ";
    //calling the Helping method
    Rec_Preorder(Root);
}

//Helping method for Recursive Postorder Traversal
void Tree ::Rec_Postorder(Tnode *t3)
{
    if (t3 != NULL)
    {
        Rec_Postorder(t3->left);
        Rec_Postorder(t3->right);
        cout << t3->info << "  ";
    }
}

//for Recursive Postorder Traversal
void Tree ::RePostTrav()
{
    cout<<"Obtained Postfix Expression = ";
    //calling the helping method
    Rec_Postorder(Root);
}

//Non-Recursive Inorder Traversal
void Tree ::InTrav()
{
    Tnode *temp = Root;
    Stack<Tnode *> st;
    cout<<"Obtained Infix Expression = ";
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

//Non-Recursive Preorder Traversal
void Tree ::PreTrav()
{
    Tnode *temp = Root;
    Stack<Tnode *> st;
    cout<<"Obtained Prefix Expression = ";
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

//Non-Recursive Postorder Traversal
void Tree ::PostTrav()
{
    Tnode *temp = Root;
    Tnode *prev = NULL;
    Stack<Tnode *> st;
    cout<<"Obtained Postfix Expression = ";
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

//Start of Main
int main()
{
    Tree T;
    int n;
    while (true)
    {
        cout << "\nPress\n1.To take Input and Create Expression Tree.\n2.Recursive Inorder Traversal\n3.Recursive Preorder Traversal\n4.Recursive Postorder Traversal\n5.In order Traversal without Recursion\n6.Pre order Traversal without Recursion\n7.Post Order Traversal without Recursion.\n0.Exit." << endl;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        switch (n)
        {
        case 1:
            T.ExpTree();
            break;
        case 2:
            T.ReInTrav();
            break;
        case 3:
            T.RePreTrav();
            break;
        case 4:
            T.RePostTrav();
            break;
        case 5:
            T.InTrav();
            break;
        case 6:
            T.PreTrav();
            break;
        case 7:
            T.PostTrav();
            break;
        default:
            cout << "Enter correct choice." << endl;
        }
    }
}