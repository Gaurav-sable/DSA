#include<iostream>
using namespace std;
int main()
{  
     int i;
     int sum;
     sum=0;
     for(i=0;i<=200;i++)
    {  if(i%3==0){
        cout<<i<<"  ";
            sum=sum+i;
            }
        
       
        
    }
    cout<<"Sum : "<<sum;
    return 0;}