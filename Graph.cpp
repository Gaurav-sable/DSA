#include <iostream>
using namespace std;

//Pre Declaration of MST class
template <class T>
class MST;

//Declaration of Graph class 
template <class T>
class Graph
{
    int adj[20][20];    //2-D array to store graph
    T ver[20];    //array to store vertices of any data type
    int vertices;

  public:
    //Declaration of constructor
    Graph(int n);
    
    //Declaration of methods
    void Create();
    void Display();

    friend class MST<T>;
};

//Constructor to initialize arrays
template <class T>
Graph<T>::Graph(int n)
{
    vertices = n;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            adj[i][j] = 0;
        }
    }
}

//Method to create graph
template <class T>
void Graph<T>::Create()
{
    int wt;
    for (int i = 0; i < vertices; i++)
    {
        cout << "Enter vertex " << i + 1 << " : ";
        cin >> ver[i];
    }
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (adj[i][j] == 0)
            {
                if (i == j)
                {
                    adj[i][j] = 0;
                }
                else
                {
                    cout << "Enter the weight of edge between " << ver[i] << " and " << ver[j] << " : ";
                    cin >> wt;
                    adj[i][j] = adj[j][i] = wt;
                }
            }
            else
            {
                cout << "Weight of edge between " << ver[i] << " and " << ver[j] << " = " << adj[i][j] << endl;
            }
        }
    }
}

//Method to display graph
template <class T>
void Graph<T>::Display()
{
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cout << adj[i][j] << "  ";
        }
        cout << endl;
    }
}