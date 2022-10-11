#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    if(n>0)
    {
        cout<<n<<" is a positive number."<<endl;
    }
    else if(n==0)
    {
        cout<<n<<" is a neutral number."<<endl;
    }
    else{
        cout<<n<<" is a negative number."<<endl;
    }
    if(n%2==0)
    {
        cout<<n<<" is an even number.";
    }
    else{
        cout<<n<<" is an odd number.";
    }
    return 0;

}