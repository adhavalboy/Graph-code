#include<bits/stdc++.h>
using namespace std;
class Graph{
int V;
list<int> *adj;
void DFSutil(int v,bool visited[]);
public:
Graph(int V);
void addEdge(int u, int v);
void DFS(int v);
};

Graph::Graph(int v){
    this->V=v;
    adj=new list<int>[v];    
}
void Graph::addEdge(int v,int u){
    adj[v].push_back(u);
}
void Graph::DFSutil(int v,bool visited[]){
        visited[v]=true;
        cout<<v<<" ";   
        list<int>::iterator it;
        for(it=adj[v].begin();it!=adj[v].end();it++){
	
            if(visited[*it]==false)
            DFSutil(*it,visited);
        }
}
void Graph::DFS(int v){
bool *visited=new bool[V];
for(int i=0;i<V;i++){
    visited[i]=false;
}
DFSutil(v,visited);
}
int main(){
Graph g(4);
  g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
    g.DFS(2);
    return 0;
}
