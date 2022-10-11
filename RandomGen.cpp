#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void myFunc(int * x)
{
    * x = 100;
}
int main()
{
    int var = 20;
    myFunc(&var);
    cout<<var;
    /*srand(time(0));
    for (int i = 1; i <=10; i++)
    {
        cout << 1+rand()%6 << endl;
    }
    cout<<rand()<<endl;*/
    
}
