#include <iostream>
using namespace std;
int main()
{
    int n1,n2,hcf,temp,i;
    cout<<"Enter two no.s : ";
    cin>>n1>>n2;
    if(n1>n2)
    {
        temp = n1;
        n1 = n2;
        n2 = temp;
    }
    for(i = 1;i<n2;i++)
    {
        if(n1%i == 0 && n2%i == 0)
        {
            hcf = i;
        }
    }
    cout<<"HCF = "<<hcf;
    return 0;
}