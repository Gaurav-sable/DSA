#include <iostream>
using namespace std;

struct Student
{
    string name;
    int rollno;
    float sgpa;
};
class Queue
{
    Student s[10];
    int n;
    int front, rear;

  public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    void Elements()
    {
        cout << "Enter no.of records : ";
        cin >> n;
    }
    
    void Enqueue()
    {
        if (rear == n - 1)
        {
            cout << "Queue Overflow." << endl;
        }

        else
        {
            if (front == -1)
            {
                front = 0;
            }

            rear++;
            cout << "Enter Details in format : \nName\nRollno\nSgpa\n_______" << endl;
            cin >> s[rear].name >> s[rear].rollno >> s[rear].sgpa;
        }
    }
    void Dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow." << endl;
            return;
        }
        else
        {
            front++;
            cout << "Deleted record is : \n"
                 << "Name : " << s[front - 1].name << "  --> "
                 << "Rollno : " << s[front - 1].rollno << " --> " << s[front - 1].sgpa << endl;
        }
    }
    void Display()
    {
        if (front == -1 || front == rear + 1)
        {
            cout << "Queue is Empty." << endl;
        }
        if (front < rear)
        {
            cout << "Students are : " << endl;
            for (int i = front; i <= rear; i++)
            {
                cout << "Name is : " << s[i].name << " --> "
                     << "Rollno : " << s[i].rollno << " --> "
                     << "SGPA : " << s[i].sgpa << endl;
            }
        }
        if (front == 0 && rear == n - 1)
        {
            cout << "Queue is Full." << endl;
        }
    }
};
int main()
{
    Queue p;
    int ch;
    cout << "Press\n1.No.of Elements\n2.Enqueue\n3.Dequeue\n4.Display\n5.Exit" << endl;

    do
    {
        cout << "Enter your Choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            p.Elements();
            break;
        case 2:
            p.Enqueue();
            break;
        case 3:
            p.Dequeue();
            break;
        case 4:
            p.Display();
            break;
        case 5:
            cout << "Exit." << endl;
            break;
        default:
            cout << "Invalid Input." << endl;
        }
    } while (ch != 5);
    return 0;
}
