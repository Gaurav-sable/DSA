#include <iostream>
using namespace std;
int main()
{
    int i,j,count = 0;
    cout<<"Prime no.s between 1 to 20 are : "<<endl;
    for(i=1;i<=20;i++)
    {
        count = 0;
        if(i==0||i==1)
        {
            continue;
        }
        
        for(j=2;j<i;j++)
        {
            if(i%j==0)
            {
                count++;
                break;
            }
        }
        if(count==0)
        {
            cout<<i<<"\n";
        }
    }
    return 0;
}