#include<iostream>
using namespace std;
class Students
{ private:
    char name[10];
    int rollno;
    int Marks;
    
    public:
    void getstudent()
    {
        cout<<"Enter your Name :"<<endl;
         cin>>name;
         cout<<"Enter your Rollno : "<<endl;
            cin>>rollno;
          cout<<"Enter your Marks :"<<endl;
            cin>>Marks;
            }
    void showstudent()
    {cout<<"Name : "<<name<<endl;
        cout<<"Rollno : "<<rollno<<endl;
        cout<<"Marks :"<<Marks<<endl;
        cout<<name <<" "<<"Rollno "<<rollno <<" "<<"has got "<<Marks<<" "<<"Marks"<<endl;}
    
    };
int main()
{int i;
    Students s[100];
    for(i=0;i<=100;i++)
    {s[i].getstudent();
        s[i].showstudent();}}