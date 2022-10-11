#include <iostream>
using namespace std;

//Forward Declaration of Template class Spath
template <class T>
class SPath;

//Template class Graph
template <class T>
class Graph
{
    int adj[20][20];   //2-D array to store graph
    T ver[20];       //Array to store vertices of any data type
    int vertices;

  public:
  
    //Constructor Declaration
    Graph(int n);
    
    //Method to create graph
    void Create();
    
    //Method to display graph
    void Display();

    //Declaring Spath class as a friend class
    friend class SPath<T>;
};

//Constructor of class to initialize arrays
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
    int wt, sw;
    for (int i = 0; i < vertices; i++)
    {
        cout << "Enter vertex " << i + 1 << " : ";
        cin >> ver[i];
    }
    cout << "Choose Graph\nPress\n1.Directed Graph \n2.Undirected Graph\nEnter Choice" << endl;
    cin >> sw;
    
    //To switch between directed and undirected graph
    switch (sw)
    {
        
        //case 1 for directed graph
    case 1:
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                if (i == j)
                {
                    adj[i][j] = 0;
                }
                else
                {
                    cout << "Enter the weight of edge between " << ver[i] << " and " << ver[j] << " : ";
                    cin >> wt;
                    adj[i][j] = wt;
                }
            }
        }
        break;
        
        //case 2 for undirected graph
    case 2:
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
        break;
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