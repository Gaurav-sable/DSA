#include <iostream>
using namespace std;
struct Student{
    string name;
    int rollno;
};
class SE11{
    private :
    Student * S;
    int size;
    int count;
    
    public :
    SE11(int c)
    {
        size = c;
        count = 0;
        S = new Student;
    }
    void Insert(){
        cout<<"Enter name of student : ";
        cin>>S[count].name;
        cout<<"Enter Rollno = ";
        cin>>S[count].rollno;
        count++;
    }
    void Display(){
        for(int i = 0;i<count;i++)
        {
            cout<<"Name : "<<S[i].name<<"\nRollno = "<<S[i].rollno<<endl;
        }
    }
};
 int main()
 {
        int stu;
        cout<<"Enter total no. of Student = ";
        cin>>stu;
        SE11 S(stu);
        int n;
        while(true)
        {
            cout<<"\nPress\n1.Insert\n2.Display";
            cin>>n;
            if(n == 0)
            {
                break;
            }
            switch(n)
            {
                case 1 :
                S.Insert();
                break;
                case 2 :
                S.Display();
                break;
            }
        }
 }
        