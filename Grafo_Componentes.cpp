// Anne Almeida
// Components Fortemente conexos
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int vertex; // global
vector<int> visit;
vector<int> Tini; // desnecessario, coloquei p tracking
vector<int> Tfim; // desnecessario, coloquei p tracking
int tempo = 0;
stack<int> topo; //ordem topologica

void addAresta(vector<vector<int> > &grafo, int u, int v);
void DFS (vector<vector<int> > &grafo);
void DFS_V (vector<vector<int> > &grafo, int u);
void components (vector<vector<int> > &grafo);
void componetsR (vector<vector<int> > &grafo, vector<vector<int> > &component, int u);
void printComp (vector<vector<int> > &component);

int main()
{
    int arcos, u, v;
    vector<vector<int> > grafo;
    vector<vector<int> > invG;
    
    cin>>vertex>>arcos;
    for(int i=0; i<vertex; i++)
    {
        grafo.push_back(vector<int>());//aloca vecotr int vazio
        invG.push_back(vector<int>());
    }
    
    for(int i=0; i<arcos; i++)
    {
        cin>>u>>v;
        addAresta(grafo, u, v);
        addAresta (invG, v, u);
    }
    
    DFS (grafo);
    components(invG);
    return 0;
}

void addAresta(vector<vector<int> > &grafo, int u, int v)
{
    grafo[u].push_back(v);    
}

void DFS (vector<vector<int> > &grafo)
{  
    for (int i=0; i< vertex; i++)  
    {
        visit.push_back(0); // white
        Tini.push_back(0);
        Tfim.push_back(0);
    }
    
    for (int i=0; i<vertex; i++)
    {
        if (visit[i]==0)
        DFS_V(grafo,i);
    }
}

void DFS_V (vector<vector<int> > &grafo, int u)
{
    tempo++;
    Tini[u]=tempo;
    visit[u]=1; //gray
    for(int i=0; i<grafo[u].size(); i++)
    {
        if (visit.at(grafo[u][i])== 0)
        {
            DFS_V(grafo, grafo[u][i]);
        }       
    }
    visit[u]=2; //black
    tempo++;
    Tfim[u]= tempo;
    topo.push(u);    
}
void componentsR (vector<vector<int> > &grafo, vector<int> &vec, int u)
{
    visit[u]=1; //gray
    for(int i=0; i<grafo[u].size(); i++)
    {
        if (visit[grafo[u][i]]== 0)
        {
            vec.push_back(grafo[u][i]);
            componentsR(grafo, vec, grafo[u][i]);
        }       
    }
    visit[u]=2; //black     
}

void components (vector<vector<int> > &grafo)
{
    vector<vector<int> > component;
    vector<int> vec;
    visit.clear();
    for (int i=0; i<vertex; i++)  
    {
        visit.push_back(0); // white
    }
    while(!topo.empty())
    {
        if (visit[topo.top()]== 0)
        {
            vec.push_back(topo.top());
            visit[topo.top()]=1;
            componentsR (grafo, vec,topo.top());                
            sort(vec.begin(),vec.end());
            component.push_back(vec);
            visit[topo.top()]=2; //black
            topo.pop();
            vec.clear();
        }
        else topo.pop();        
    }
    printComp ( component);    
}

void printComp (vector<vector<int> > &component)
{
    sort(component.begin(),component.end());  
    for(int i=0; i<component.size(); i++)
    {
        cout<<"component: "<<endl;
        for(int j=0; j<component[i].size(); j++)
        {
            cout<<component[i][j]<<" ";
        }
        cout<<endl;
    }

}
