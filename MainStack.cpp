#include "Stack.cpp"
#include <iostream>
#include <cstring>
using namespace std;

class Expression
{
    char E[40];
    char I[40];

  public:
    int Prec(char c);
    void IntoPost();
    void IntoPre();
    void CalPost();
    void CalPre();
    void Input();
    void RevExp();
};

//To check precedence
int Expression ::Prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}


//To take Input
void Expression ::Input()
{
    cout << "Enter Expression : ";
    cin.ignore();
    cin.getline(E, 40);
}


//To convert Infix to Postfix
void Expression ::IntoPost()
{
    int i , j = 0;
    Stack<char> st;
    for (i = 0; i < strlen(E); i++)
    {
        char c = E[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == ' ')
        {
            I[j] = c;
            j++;
        }
        else if (c == '(')
        {
            st.Push(c);
        }
        else if (c == ')')
        {
            while (st.IsTop() != '(')
            {
                I[j] = st.IsTop();
                j++;
                st.Pop();
            }
            st.Pop();
        }
        else
        {
            while ((!st.IsEmpty()) && (Prec(c) <= Prec(st.IsTop())))
            {
                if ((c == '^') && (Prec(c) == Prec(st.IsTop())))
                {
                    break;
                }
                I[j] = st.IsTop();
                j++;
                st.Pop();
            }
            st.Push(c);
        }
    }
    while (!st.IsEmpty())
    {
        I[j] = st.IsTop();
        j++;
        st.Pop();
    }
    cout<<"\n------------------------------\nPostfix Expression = "<<endl;
    cout<<I<<endl;
}


//To calculate Postfix Expression
void Expression ::CalPost()
{
    int val;
    Stack<int> st;
    for (int i = 0; i < strlen(I); i++)
    {
        char c = I[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            cout << "Enter value of Operand " << c << " : ";
            cin >> val;
            st.Push(val);
        }
        else
        {
            int op1 = st.IsTop();
            st.Pop();
            int op2 = st.IsTop();
            st.Pop();
            switch (I[i])
            {
            case '^':
                st.Push(pow(op2, op1));
                break;
            case '*':
                st.Push(op2 * op1);
                break;
            case '/':
                st.Push(op2 / op1);
                break;
            case '+':
                st.Push(op2 + op1);
                break;
            case '-':
                st.Push(op2 - op1);
                break;
            }
        }
    }
    cout <<"\n---------------------------\nAnswer = "<< st.IsTop() << endl;
}


//To Reverse Expression
void Expression ::RevExp()
{
    for (int k = 0; k < strlen(I) / 2; k++)
    {
        char temp = I[strlen(I) - 1 - k];
        I[strlen(I) - 1 - k] = I[k];
        I[k] = temp;
    }
    cout << I << endl;
}


//To convert Infix to Prefix
void Expression ::IntoPre()
{
    int i , j = 0;
    Stack<char> st;
    for (i = strlen(E)-1; i >= 0; i--)
    {
        char c = E[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == ' ')
        {
             I[j] = c;
             j++;
        }
        else if (c == ')')
        {
            st.Push(c);
        }
        else if (c == '(')
        {
            while (st.IsTop() != ')')
            {
                I[j] = st.IsTop();
                j++;
                st.Pop();
            }
            st.Pop();
        }
        else
        {
            while ((!st.IsEmpty()) && (Prec(c) < Prec(st.IsTop())))
            {
                I[j] = st.IsTop();
                j++;
                st.Pop();
            }
            if ((c == '^') && (Prec(c) == Prec(st.IsTop())))
            {
                I[j] = st.IsTop();
                j++;
                st.Pop();
            }
            st.Push(c);
        }
    }
    while (!st.IsEmpty())
    {
        I[j] = st.IsTop();
        j++;
        st.Pop();
    }
    cout << "\n------------------------------\nPrefix Expression is = " << endl;
    RevExp();
}


//To calculate Prefix Expression
void Expression :: CalPre()
{
     int j = 0;
     int val[20];
    Stack<int> st;
    for(int i = 0; i<strlen(I);i++)
    {
        if(isalpha(I[i]))
		{
			cout<<"Enter value for operand "<<I[i]<<":- ";
			cin>>val[j];
			j++;
		}
		if(isdigit(I[i]))
		{
			val[j]=((int)I[i]-'0');
			j++;
		}
	}
	j--;
    for (int i = strlen(I)-1; i >= 0; i--)
    {
        char c = I[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c<= '9'))
        {
            st.Push(val[j]);
            j--;
        }
        else
        {
            int op1 = st.IsTop();
            st.Pop();
            int op2 = st.IsTop();
            st.Pop();
            switch (I[i])
            {
            case '^':
                st.Push(pow(op1, op2));
                break;
            case '*':
                st.Push(op1 * op2);
                break;
            case '/':
                st.Push(op1 / op2);
                break;
            case '+':
                st.Push(op1 + op2);
                break;
            case '-':
                st.Push(op1 - op2);
                break;
            }
        }
    }
    cout <<"\n-----------------------------\nAnswer is = "<<st.IsTop() << endl;
}


//Start of main
int main()
{
    Stack<char> S;
    Expression Ex;

    int ch;

    while (true)
    {
        cout << "Press\n1.To input Expression\n2.To Convert from Infix to Postfix\n3.To Evaluate Postfix Expression\n4.To convert Expression from Infix to Prefix\n5.To Evaluate Prefix Expression\n0.Exit"<< endl;
        cout<<"•••••••••••••••••••••••••••••••••••••"<<endl;
        cout << "Choose your Operation : ";
        cin >> ch;
        if (ch == 0)
        {
            break;
        }
        switch (ch)
        {
        case 1:
            Ex.Input();
            cout<<"\n•••••••••••••••••••••••••••••••••••"<<endl;
            break;
        case 2:
            Ex.IntoPost();
            cout<<"\n•••••••••••••••••••••••••••••••••••"<<endl;
            break;
        case 3:
            Ex.CalPost();
            cout<<"\n•••••••••••••••••••••••••••••••••••"<<endl;
            break;
        case 4:
            Ex.IntoPre();
            cout<<"\n•••••••••••••••••••••••••••••••••••"<<endl;
            break;
        case 5:
            Ex.CalPre();
            cout<<"\n•••••••••••••••••••••••••••••••••••"<<endl;
            break;
        default:
            cout << "Choose Correct Option." << endl;
        }
    }
}
