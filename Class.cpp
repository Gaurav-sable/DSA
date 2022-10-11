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
{Students s1,s2,s3;
    s1.getstudent();
    s2.getstudent();
    s3.getstudent();
    s1.showstudent();
    s2.showstudent();
    s3.showstudent(); }