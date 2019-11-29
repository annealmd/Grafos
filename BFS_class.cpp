#include <iostream>
#include <list>
#include <queue>
#include <fstream>
#include <algorithm> // find function

using namespace std;

class grafo
{
    private: 
    int v;
    list <int> *adj;
    public:
    grafo(int v);
    void addAresta (int v1, int v2);
    void BFS (int startVertex);
};
int nVertex;

int main(int argc, char** argv) //argv[1] grau minimo do no e argv[2] nome do arquivo
{
    ifstream fileIn(argv[1], ios::in); // entry file read and write
        
    if(!fileIn.is_open())
    {
        cerr<<"\nNão foi prossivel abrir o arquivo de entrada. "<<endl;
        abort();
    }
    int nArch;
    int v1, v2, i, start;
    fileIn>>nVertex>>nArch;
    grafo gr(nVertex); // inicia o graph and adjacent listof vertex
    for(i=0; i<nArch; i++)
    {
        fileIn>>v1>>v2;
        gr.addAresta(v1,v2);
    }
    fileIn>>start;
    
    cout<<"\n Distancia de vertice "<<start<<" para : "<<endl;
    gr.BFS(start);
    
    fileIn.close();
    return 0;
}

grafo::grafo(int v)
{
    this->v = v; // number of vertices
    adj = new list <int>[v]; //each vertex has its own list
}
void grafo::addAresta (int v1, int v2)
{
    adj[v1].push_back(v2);
}

void grafo::BFS (int startVertex)
{

    int *visited = new int[nVertex];//vetores de visited e distances
    int *dist = new int[nVertex];
    
    for(int i = 0; i < nVertex; i++)// sempre start marking all visted
        visited[i] = 0; //all WHITE COLOUR 0
   
    list<int> queue; //BFS queue, DFS stark
    visited[startVertex] = 1; //colour gray
    dist[startVertex]=0;
    queue.push_back(startVertex);
 
    list<int>::iterator i; //iteratior para correr a lista 
 
    while(!queue.empty())
    {
        startVertex = queue.front();
        cout << startVertex <<" "<<"dist: "<<dist[startVertex]<<endl;
        queue.pop_front();
       
        //all the adjacent vertex of the printed one, if not visited, true and enqueue
        for (i = adj[startVertex].begin(); i != adj[startVertex].end(); ++i)
        {
            if (visited[*i]==0)//não visitado ainda
            {
                visited[*i] = 2;// COLOUR GRAY 2
                dist[*i] = dist[startVertex]+1;
                //cout<<"enqueue: "<<*i<<" colour: "<<visited[*i]<<endl;
                queue.push_back(*i);                
            }                        
        }
        
        visited[startVertex] = 3; // colour black
    }
    cout <<endl;    
}
 

