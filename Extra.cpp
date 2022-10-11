#include <iostream>
using namespace std;
class set;
class Node
{
    int info;
    Node *nxt;

  public:
    Node()
    {
        nxt = NULL;
    }
    friend class set;
};
class set
{
  public:
    void Add_St(Node **start, int Roll)
    {
        Node *last;
        Node *ptr = new Node();
        ptr->info = Roll;
        ptr->nxt = NULL;
        if (*start == NULL)
        {
            *start = ptr;
        }
        else
        {
            last = *start;
            while (last->nxt != NULL)
            {
                last = last->nxt;
            }
            last->nxt = ptr;
        }
    }
    void Display(Node *root)
    {
        Node *temp = root;
        while (temp != NULL)
        {
            cout << temp->info << "   ";
            temp = temp->nxt;
        }
        cout << endl;
    }
    void Intersect(Node *root1, Node *root2)
    {
        Node *ptr1 = root1, *ptr2 = root2;
        while (ptr1 != NULL)
        {
            while (ptr2 != NULL)
            {
                if (ptr2->info == ptr1->info)
                {
                    cout << ptr2->info << "   ";
                    break;
                }
                else
                {
                    ptr2 = ptr2->nxt;
                }
            }
            ptr1 = ptr1->nxt;
        }
    }
};
int main()
{
    set s;
    int num, Anum, Bnum;
    Node *Total = NULL, *SetA = NULL, *SetB = NULL;
    cout << "Enter Total no. of Students : ";
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int Rollno;
        cout << "Enter Rollno - ";
        cin >> Rollno;
        s.Add_St(&Total, Rollno);
    }
    s.Display(Total);
    cout << "Enter no. of vanilla Stu : ";
    cin >> Anum;
    for (int i = 0; i < Anum; i++)
    {
        int ARoll;
        cout << "Enter Rollno : ";
        cin >> ARoll;
        s.Add_St(&SetA, ARoll);
    }
    s.Display(SetA);
    cout << "Enter no. of Butter Stu : ";
    cin >> Bnum;
    for (int i = 0; i < Bnum; i++)
    {
        int BRoll;
        cout << "Enter Rollno : ";
        cin >> BRoll;
        s.Add_St(&SetB, BRoll);
    }
    cout << "Both : ";
    s.Intersect(SetA, SetB);
}