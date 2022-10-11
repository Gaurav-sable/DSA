#include <iostream>
#include "Graph.cpp"
using namespace std;

//MST class
template <class T>
class MST{
    private :
    int mst[100][100];    //2-D array to store MST
    int par[20];    
    
    public :
    
    //Declaration of Constructor
    MST(Graph <T> a);
    
    //Declaration of methods for prims implmentation
    int findmin(int cost[], bool selected[], Graph <T> a);
    void prims(Graph <T> a);
    
    //Declaratiin of methods for kruskals implementation
    int find(int i);
    void Union(int i, int j);
    void Kruskal(Graph <T> a);
};

//Cinstructor to initialize arrays
template <class T>
MST <T> :: MST(Graph <T> a)
{
    for (int i = 0; i < a.vertices; i++)
    {
        for (int j = 0; j < a.vertices; j++)
        {
            mst[i][j] = 0;
        }
    }
}

//Helping method for prims implementation
template <class T>
int MST <T> :: findmin(int cost[], bool selected[], Graph <T> a)
{
    int min = INT_MAX;
    int vertex = -1;
    for(int i = 0; i<a.vertices; i++)
    {
        if(cost[i]<min && selected[i] == false)
        {
            min = cost[i];
            vertex = i;
        }
    }
    return vertex;
}

//Method to implement prims algorithm
template <class T>
void MST <T> :: prims(Graph <T> a)
{
    int sum = 0;
    int v = a.vertices;
    int cost[v];
    bool selected[v];
    int parent[v];
    for(int i = 0; i<v; i++)
    {
        cost[i] = INT_MAX;
        selected[i] = false;
    }
    cost[0] = 0;
    parent[0] = -1;
    while(v > 1)
    {
        int u = findmin(cost, selected, a);
        selected[u] = true;
        for(int i = 0; i<a.vertices; i++)
        {
            if(a.adj[u][i] && selected[i] == false && a.adj[u][i]<cost[i])
            {
                cost[i] = a.adj[u][i];
                parent[i] = u;
            }
        }
        v--;
    }
    for(int i = 1; i<a.vertices;i++)
    {
        mst[parent[i]][i] = a.adj[i][parent[i]];
        mst[i][parent[i]] = a.adj[i][parent[i]];
    }
    cout<<"The MST obtained by prims algo Successfully !!! "<<endl;  
    for(int i = 0;i<a.vertices;i++)
    {
        for(int j = 0;j<a.vertices;j++)
        {
            cout<<mst[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<"Mincost of MST = ";
    for(int i = 0;i<a.vertices;i++)
    {
        sum = sum + cost[i];
    }
    cout<<sum<<endl;
} 

//Helping method for kruskals
template <class T>
int MST <T> :: find(int i)
{
    while(par[i] != i)
    {
        i = par[i];
    }
    return i;
}

//Helping methods for kruskals
template <class T>
void MST <T> :: Union(int i, int j)
{
    int a = find(i);
    int b = find(j);
    par[a] = b;
}

//Imolementation of kruskals
template <class T>
void MST <T> :: Kruskal(Graph <T> a)
{
    int min_cost = 0, c = 0;
    int v = a.vertices;
    for(int i = 0; i<v;i++)
    {
        par[i] = i;
    }
    while(v>1)
    {
        int cost = INT_MAX;
        int v1 = -1, v2 = -1;
        for(int i = 0;i<a.vertices; i++)
        {
            for(int j = 0; j<a.vertices;j++)
            {
                if(a.adj[i][j] != 0 && find(i) != find(j) && a.adj[i][j] < cost)
                {
                    cost = a.adj[i][j];
                    v1 = i;
                    v2 = j;
                }
            }
        }
        Union(v1 , v2);
        mst[v1][v2] = cost;
        mst[v2][v1] = cost;
        min_cost +=cost;
        v--;
        cout<<"Edge "<<++c<<" : ( "<<a.ver[v1]<<" , "<<a.ver[v2]<<" ) => Cost = "<<cost<<endl;
    }
    cout<<"\n Mincost of MST = "<<min_cost<<endl;
    cout<<"\nMST in the form of Adjacency Matrix : "<<endl;
    for(int i = 0;i<a.vertices;i++)
    {
        for(int j = 0;j<a.vertices;j++)
        {
            cout<<mst[i][j]<<"  ";
        }
        cout<<endl;
    }  
}

//Start of main
int main()
{
    int ver, ch;
    cout<<"Enter no. of vertices : ";
    cin>>ver;
    Graph <string> g(ver);
    MST <string> m(g);
    while(true)
    {
        cout<<"Press\n1.To create Graph\n2.To Display Graph.\n3.MST by prims algo\n4.MST by kruskal algo\n5.Display MST\n0.Exit\n";
        cin>>ch;
        if(ch == 0)
        {
            break;
        }
        switch(ch)
        {
            case 1 :
            g.Create();
            break;
            case 2 :
            g.Display();
            break;
            case 3 :
            m.prims(g);
            break;
            case 4 :
            cout<<"MST obtained by kruskal algo Successfully !!!"<<endl;
            m.Kruskal(g);
            break;
            default :
            cout<<"Invalid Choice !!!"<<endl;
        }
    }
}