#include <iostream>
using namespace std;
class Convert
{
    string s;

  public:
    void BconG();
    void GconB();
    void BconD();
    void DconB();
};
void Convert ::BconG()
{
    string G;
    bool flag = true;
    cout << "Enter Binary number : ";
    cin >> s;
    G = G + s[0];
    for (int i = 0; i < s.length() - 1; i++)
    {
        if ((s[i] == '0' || s[i] == '1') && (s[i + 1] == '0' || s[i + 1] == '1'))
        {
            if (s[i] == s[i + 1])
            {
                G = G + '0';
            }
            else
            {
                G = G + '1';
            }
        }
        else
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << "Grey Code = " << G << endl;
    }
    else
    {
        cout << "Wrong Input!!!" << endl;
    }
}
void Convert ::GconB()
{
    string B;
    bool flag2 = true;
    cout << "Enter Gray code = ";
    cin >> s;
    B = B + s[0];
    for (int i = 0; i < s.length() - 1; i++)
    {
        if ((s[i] == '0' || s[i] == '1') && (s[i + 1] == '0' || s[i + 1] == '1'))
        {
            if (B[i] == s[i + 1])
            {
                B = B + '0';
            }
            else
            {
                B = B + '1';
            }
        }
        else
        {
            flag2 = false;
            break;
        }
    }
    if (flag2)
    {
        cout << "Binary = " << B << endl;
    }
    else
    {
        cout << "Wrong Input!!!" << endl;
    }
}
void Convert ::BconD()
{
    bool flag3 = true;
    cout << "Enter Binary = ";
    cin >> s;
    int len = s.length();
    int num = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (s[i] == '0' || s[i] == '1')
        {
            int n = s[i] - '0';
            num = num + n * pow(2, len - 1 - i);
        }
        else
        {
            flag3 = false;
            break;
        }
    }
    if (flag3)
    {
        cout << "Decimal = " << num << endl;
    }
    else
    {
        cout << "Wrong Input!!!" << endl;
    }
}
void Convert :: DconB()
{
    string D;
    int temp;
    cout<<"Enter Digit = ";
    cin>>temp;
    do
    {
        D = D + to_string(temp%2);
        temp = temp/2;
    }while(temp>0);
    cout<<"Binary = ";
    for(int i = D.length()-1; i>=0;i--)
    {
        cout<<D[i];
    }
    cout<<endl;
}
int main()
{
    Convert b;
    int ch;
    while (true)
    {
        cout << "Press\n1.To convert from binary to gray\n2.To convert from gray to binary\n3.To convert binary to decimal\n4.To convert Decimal to Binary" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            b.BconG();
            break;
        case 2:
            b.GconB();
            break;
        case 3:
            b.BconD();
            break;
            case 4 :
            b.DconB();
            break;
        }
    }
}