#include <iostream>
using namespace std;

//Heap class
class Heap
{
  private:
    int *arr; //Declaration of a ptr array to store data
    int size;

  public:
    //Declaration of a constructor
    Heap();

    //Declarations of methods required
    void Ins_Heap();
    void Del_Heap();
    void Display();
    void HeapSort();
};

//Constructor of heap to initialize array and its size
Heap ::Heap()
{
    size = 0;
    arr = new int[size];
}

//Method to insert into a heap
void Heap ::Ins_Heap()
{
    cout << "Enter element  : ";
    size++;
    cin >> arr[size - 1];
    int ptr = size - 1;
    while (ptr > 0)
    {
        int par = (ptr - 1) / 2;
        if (arr[ptr] > arr[par])
        {
            int temp = arr[ptr];
            arr[ptr] = arr[par];
            arr[par] = temp;
            ptr = par;
        }
        else
        {
            break;
        }
    }
}

//Method to delete data from heap
void Heap ::Del_Heap()
{
    if (size == 0)
    {
        cout << "Heap is Empty!!!" << endl;
    }
    else
    {
        int ptr = 0, l_child = 1, r_child = 2;
        cout << arr[0] << "  ";
        int last = arr[size - 1];
        size = size - 1;
        while (r_child <= size - 1)
        {
            if (last >= arr[l_child] && last >= arr[r_child])
            {
                arr[ptr] = last;
                break;
            }
            if (arr[l_child] >= arr[r_child])
            {
                arr[ptr] = arr[l_child];
                ptr = l_child;
            }
            else
            {
                arr[ptr] = arr[r_child];
                ptr = r_child;
            }
            l_child = 2 * ptr + 1;
            r_child = l_child + 1;
        }
        if (l_child == size - 1 && last < arr[l_child])
        {
            arr[ptr] = arr[l_child];
            ptr = l_child;
        }
        arr[ptr] = last;
    }
}

//Method to sort heap data
void Heap ::HeapSort()
{
    if (size == 0)
    {
        cout << "There is no element in Heap." << endl;
    }
    else
    {
        cout << "Sorted Heap = " << endl;
        for (int i = size - 1; i >= 0; i--)
        {
            Del_Heap();
        }
    }
}

//Method to display heap
void Heap ::Display()
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
}

//Start of main
int main()
{
    Heap h;
    int n, nh;
    while (true)
    {
        cout << "\nPress\n1.To Insert element in Heap\n2.To Display element of Heap\n3.To sort the Heap\n0.Exit." << endl;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        switch (n)
        {
        case 1:
            cout<<"Enter no of elements to add : ";
            cin>>nh;
            for(int i = 0; i<nh;i++)
            {
            h.Ins_Heap();
            }
            break;
        case 2:
            h.Display();
            break;
        case 3:
            h.HeapSort();
            break;
        default:
            cout << "Invalid  Choice.";
        }
    }
}