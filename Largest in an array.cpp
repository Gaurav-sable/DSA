#include<iostream>
using namespace std;
int main()
{int arr[10]={1090,10,6,8,45,26,99,243,67,42},i;
    for(i=0;i<=10;i++)
    {if(arr[0]<arr[i])
        arr[0]=arr[i];
        }
    cout<<"largest no. is : "<<arr[0]<<endl;
    return 0;}