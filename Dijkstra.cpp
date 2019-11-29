// Anne Almeida
// dijkstra
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef enum {branco, cinza, preto} cores;
#define INFINITY 2147483647

int vertex; // global
vector <cores> visit;
vector <int> dist;
vector <int> pai;

void add_Aresta (vector < vector< pair <int, int > > > &grafo, int u, int v, int w);
void dijkstra ( vector < vector< pair <int, int > > > &grafo, int s);
void print_MinPath ();
 
int main(int argc, char const *argv[])
{
    vector < vector< pair <int, int > > >grafo;
    int arcos,u, v, w, s, t;
    cin>>vertex>>arcos;
    
    for(int i=0; i<vertex; i++)
    {
        grafo.push_back(vector<pair<int, int> >());
        visit.push_back(branco);
        dist.push_back(INFINITY);
        pai.push_back(i);
    }   
    for (int i = 0; i<arcos; i++)
    {
        cin>>u>>v>>w;
        add_Aresta (grafo, u, v, w);
    }
    cin>>s>>t;
    dijkstra (grafo, s); 
    cout<<"\n*CAMINHO MINIMO: "<<endl;
    if (dist[t]==INFINITY)
    {
        cout<<"de "<<s<<" -> "<<t<<" = INFINITO "<<endl;
    }
    else
    cout<<"de "<<s<<" -> "<<t<<" = "<<dist[t]<<endl;
    
    //print_MinPath ();
    
    return 0;
}

void add_Aresta (vector < vector< pair <int, int > > > &grafo, int u, int v, int w)
{
    grafo[u]. push_back(make_pair(v,w));
}

void dijkstra ( vector < vector< pair <int, int > > > &grafo, int s)
{
    priority_queue < pair<int, int>, vector< pair<int, int> >, greater< pair< int, int > > > fila;
    pai[s] = s;
    dist[s] = 0;
    visit[s] = cinza;
    fila.push (make_pair(dist[s], s));
    int x;

    while (!fila.empty())
    {
        x = fila.top().second;
        
        fila.pop();
        for (int i = 0; i < grafo[x].size(); i++)
        {
            if ((dist[x] + grafo[x][i].second) < dist[grafo[x][i].first] )
            {
                pai[grafo[x][i].first] = x;
                dist[grafo[x][i].first] = dist[x] + grafo[x][i].second;
                visit[grafo[x][i].first] = cinza;
                fila.push (make_pair(dist[grafo[x][i].first], grafo[x][i].first));               
            }                 
        }
        visit[x]=preto;        
    }
}

void print_MinPath ()
{
    priority_queue < pair<int, int>, vector< pair<int, int> >, greater< pair< int, int > > > fila;

    for ( int i=0; i < vertex; i++)
    {
        fila.push (make_pair(dist[i], i));  
    }
     cout<<"\n*CAMINHO MINIMO PARA TODOS OS VERTICES: "<<endl;
    while (!fila.empty())
    {
       
        if (fila.top().first ==INFINITY)
        {
            cout<< fila.top().second << " Dist: INFINITO" <<" Pai: "<<pai[fila.top().second]<<endl;
        }
        else
        cout<< fila.top().second << " Dist: "<< fila.top().first <<" Pai: "<<pai[fila.top().second]<<endl;     
            
        fila.pop();
    }
}