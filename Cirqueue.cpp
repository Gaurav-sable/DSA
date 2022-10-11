#include <iostream>
using namespace std;

struct Student
{
    string name;
    int rollno;
    float sgpa;
};
class CircularQueue
{
    Student s[10];
    int n;
    int front, rear;

  public:
    CircularQueue();
    void Elements();
    bool IsEmpty();
    void Enqueue();
    void Dequeue();
    void Display();
};

CircularQueue ::CircularQueue()
{
    front = -1;
    rear = -1;
}


//To Read no. of Elements
void CircularQueue ::Elements()
{
    cout << "Enter no.of records : ";
    cin >> n;
}

//Queue is empty or not
bool CircularQueue ::IsEmpty()
{
    if (front == -1 && rear == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}


//To Insert Element
void CircularQueue ::Enqueue()
{
    if ((rear + 1) % n == front)
    {
        cout << "Queue is Full." << endl;
    }

    else
    {
        if (front == -1)
        {
            front = 0;
        }

        rear = (rear + 1) % n;
        cout << "Enter Details in format : \nName\nRollno\nSgpa\n_______" << endl;
        cin >> s[rear].name >> s[rear].rollno >> s[rear].sgpa;
    }
}


//To Delete Element
void CircularQueue ::Dequeue()
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue Underflow." << endl;
    }
    else if (front == rear)
    {
        cout << "Deleted record is : \n"
             << "Name : " << s[front].name << "  --> "
             << "Rollno : " << s[front].rollno << " --> " << s[front].sgpa << endl;
        front = rear = -1;
    }
    else
    {
        cout << "Deleted record is : \n"
             << "Name : " << s[front].name << "  --> "
             << "Rollno : " << s[front].rollno << " --> " << s[front].sgpa << endl;
        front = (front + 1) % n;
    }
}


//To Display Queue
void CircularQueue ::Display()
{
    int i;
    if (IsEmpty())
    {
        cout << "Queue is Empty." << endl;
    }
    else
    {
        for (i = front; i != rear; i = (i + 1) % n)
        {
            cout << "Name : " << s[i].name << " -->  Rollno : " << s[i].rollno << "  -->   SGPA : " << s[i].sgpa << endl;
        }
        cout << "Name : " << s[i].name << " -->  Rollno : " << s[i].rollno << "  -->   SGPA : " << s[i].sgpa << endl;
    }
};


//Start of main
int main()
{
    CircularQueue p;
    int ch;
    do
    {
        cout << "Press\n1.No.of Elements\n2.Enqueue\n3.Dequeue\n4.Display\n5.Exit" << endl;
        cout << "•••••••••••••••••••••••••••••••••••••" << endl;

        cout << "Enter your Choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            p.Elements();
            cout << "\n•••••••••••••••••••••••••••••••••••" << endl;
            break;
        case 2:
            p.Enqueue();
            cout << "\n•••••••••••••••••••••••••••••••••••" << endl;
            break;
        case 3:
            p.Dequeue();
            cout << "\n•••••••••••••••••••••••••••••••••••" << endl;
            break;
        case 4:
            p.Display();
            cout << "\n•••••••••••••••••••••••••••••••••••" << endl;
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
