//Dijiktras algorithm
//23339_Gaurav Sable
//Batch SE11(F11)

#include <iostream>

//Including the graph creation file
#include "GraphS.cpp"
using namespace std;

//Spath class
template <class T>
class SPath{
    private :
    int dist[40];    //array to store distance
    int visited[40];     //Array to check loops
    int path[40];      //Array to store path
    
    public :
    
    //Declaration of constructor
    SPath(Graph <T> a);
    
    //Helping method Declaration
    int minvertex(Graph <T> a);
    
    //Method to implement dijiktras algo
    void Dijiktras(Graph <T> a);
};

//Constructor Spath to initialize arrays
template <class T>
SPath <T> :: SPath(Graph <T> a)
{
    for(int i = 0; i<a.vertices; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
        path[i] = 0;
    }
    dist[0] = 0;
}

//Helping method implementation
template <class T>
int SPath <T> :: minvertex(Graph <T> a)
{
    int minver = -1;
    for(int i = 0; i<a.vertices;i++)
    {
        if(!visited[i] && (minver == -1 || dist[i] < dist[minver]))
        {
            minver = i;
        }
    }
    return minver;
}

//Implementation of Dijiktras algo
template <class T>
void SPath <T> :: Dijiktras(Graph <T> a)
{
    for(int i = 0; i<a.vertices -1; i++)
    {
        int min = minvertex(a);
        visited[min] = 1;
        for(int j = 0;j<a.vertices; j++)
        {
            if(!visited[j] && a.adj[min][j] != 0)
            {
                int distance = dist[min] + a.adj[min][j];
                if(distance < dist[j])
                {
                    dist[j] = distance;
                    path[j] = min;
                }
            }
        }
    }
    cout<<"Source  =   "<<a.ver[0]<<endl;
    for(int i = 0; i<a.vertices; i++)
    {
        if(i != 0)
        {
        cout<<a.ver[0]<<" - "<<a.ver[i]<<"\tMinimum Dist =  "<<dist[i]<<"      ";
        cout<<"Path = "<<a.ver[i];
        int j = i;
        do{
            j = path[j];
            cout<<"<-"<<a.ver[j]<<endl;
        }while(j != 0);
        }
    }
}

//Start of main
int main()
{
    int ver, ch;
    cout<<"Enter no. of vertices : ";
    cin>>ver;
    Graph <string> g(ver);
    SPath <string> s(g);
    while(true)
    {
        cout<<"\nPress\n1.To create Graph\n2.To Display Graph.\n3.Shortest Path\n0.Exit\n";
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
            s.Dijiktras(g);
            break;
            default :
            cout<<"Invalid Choice !!!"<<endl;
        }
    }
}
    