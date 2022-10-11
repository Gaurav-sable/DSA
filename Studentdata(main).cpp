#include <iostream>
using namespace std;
struct Student
{
    string name;
    int rollno;
    float sgpa;
};
class se11
{
    Student s[20];
    int n;

  public:
    void setdata();
    void showdata();
    void searchdata();
    void sortdata();
    void sort1data();
    int partition(int low, int high);
    void quicksort(int low, int high);
    void sortsgpa();
    void Tentoppers();
    void bsearchsgpa();
    void lsgpasearch();
};


//To take data Input
void se11 ::setdata()
{
    cout << "Enter no. of records u want to add : ";
    cin >> n;
    cout << "Enter Student Details in given format : \n Name\nRollno\nSGPA\n_________ " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter detail of Student " << i + 1 << " : " << endl;
        cin >> s[i].name >> s[i].rollno >> s[i].sgpa;
    }
    cout << "--------------××××××××××××----------" << endl;
}


//To display Entered Data
void se11 ::showdata()
{
    cout << "Student Detail : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Name : " << s[i].name << " "
             << "Rollno: " << s[i].rollno << " "
             << "SGPA : " << s[i].sgpa << endl;
    }
    cout << "-------------××××××××××××-----------" << endl;
}


//Searching Rollno wise using Linear Search
void se11 ::searchdata()
{
    cout << "Enter Rollno of Student : ";
    int srol;
    cin >> srol;
    int flag = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        if (s[i].rollno == srol)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        cout << "Student found at index : " << i << endl
             << "Name : " << s[i].name << endl
             << "Rollno : " << s[i].rollno << endl
             << "SGPA : " << s[i].sgpa << endl;
    }
    else
    {
        cout << "Student not found." << endl;
    }
    cout << "-----------××××××××××××-------------" << endl;
}


//Sorting Rollno wise using Bubble sort
void se11 :: sortdata()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[i].rollno > s[j].rollno)
            {
                swap(s[i], s[j]);
            }
        }
    }
    cout << "Sorting via bubble sort is done." << endl;
    cout << "-------------××××××××××××-----------" << endl;
}


//Sorting Alphabetically using Insertion Sort
void se11 :: sort1data()
{
    for (int i = 1; i < n; i++)
    {
        string temp = s[i].name;
        int key = s[i].rollno;
        float value = s[i].sgpa;

        int j = i - 1;
        while (s[j].name > temp && j >= 0)
        {
            s[j + 1].name = s[j].name;
            s[j + 1].rollno = s[j].rollno;
            s[j + 1].sgpa = s[j].sgpa;

            j = j - 1;
        }
        s[j + 1].name = temp;
        s[j + 1].rollno = key;
        s[j + 1].sgpa = value;
    }
    cout << "Sorting via Insertion sort is done." << endl;
    cout << "----------------×××××××××××---------" << endl;
}


//To implement Quicksort
int se11 :: partition(int low, int high)
{
    int i = low;
    int j = high;
    float pivot = s[low].sgpa;
    while (i <= j)
    {
        while (pivot <= s[i].sgpa && i <= high)
        {
            i++;
        }
        while (pivot > s[j].sgpa && j >= low)
        {
            j--;
        }
        if (i < j)
        {
            swap(s[i], s[j]);
        }
        if (i >= j)
        {
            swap(s[low], s[j]);
        }
        return j;
    }
}


//Sorting SGPA wise using Quicksort
void se11 :: quicksort(int low, int high)
{
    if (low >= high)
    {
        return;
    }
    if (low < high)
    {
        int pi = partition(low, high);
        quicksort(low, pi - 1);
        quicksort(pi + 1, high);
    }
}


//Sorting via Quicksort
void se11 :: sortsgpa()
{
    quicksort(0, n - 1);
    cout << "Sorting via Quicksort is done." << endl;
    cout << "------------×××××××××××××-----------" << endl;
}


//Find 1st 10 Toppers of class
void se11 :: Tentoppers()
{
    cout << "First 10 toppers are : " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "Name : " << s[i].name << " "
             << "Rollno: " << s[i].rollno << " "
             << "SGPA : " << s[i].sgpa << endl;
    }
    cout << "---------------××××××××××××---------" << endl;
}


//Search on SGPA using Binary Search
void se11 :: bsearchsgpa()
{
    cout << "Enter SGPA of the  student : ";
    float data;
    cin >> data;
    int low = 0, high = n - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high)/2;
        if (s[mid].sgpa < data)
        {
            low = mid + 1;
        }
        else if (s[mid].sgpa == data)
        {
            cout << " Index no is " << mid << endl
                 << " Name : " << s[mid].name << endl
                 << " Roll no is : " << s[mid].rollno << endl
                 << " Sgpa is  " << s[mid].sgpa << endl;
            break;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (low > high)
    {
        cout << "Student not found." << endl;
    }
    cout << "---------------××××××××××××---------" << endl;
}


//Searching SGPA using Linear Search
void se11 :: lsgpasearch()
{
    cout << "Enter sgpa of Student : ";
    float data;
    cin >> data;
    int i;
    int flag1 = 0;
    for (i = 0; i < n; i++)
    {
        if (s[i].sgpa == data)
        {
            flag1 = 1;
            break;
        }
    }
    if (flag1 == 1)
    {
        cout << "Student found at index : " << i << endl
             << "Name : " << s[i].name << endl
             << "Rollno : " << s[i].rollno << endl
             << "SGPA : " << s[i].sgpa << endl;
    }
    else
    {
        cout << "Student not found." << endl;
    }
    cout << "--------------××××××××××××----------" << endl;
};


//Start of main
int main()
{
    se11 p;
    while (true)
    {
        cout << "Press \n1.Set Data\n2.Show Data\n3.sortdata\n4.sort1data\n5.Search Data\n6.quicksort\n7.Tentoppers\n8.Binarysearch\n9.lsgpasearch\n10.Exit" << endl;
        int n;
        cin >> n;
        if (n == 10)
        {
            break;
        }
        switch (n)
        {
        case 1:
            p.setdata();
            break;
        case 2:
            p.showdata();
            break;
        case 3:
            p.sortdata();
            break;
        case 4:
            p.sort1data();
            break;
        case 5:
            p.searchdata();
            break;
        case 6:
            p.sortsgpa();
            break;
        case 7:
            p.Tentoppers();
            break;
        case 8:
            p.bsearchsgpa();
            break;
        case 9:
            p.lsgpasearch();
            break;
        default:
            cout << "Thank you!!!";
        }
    }
}
