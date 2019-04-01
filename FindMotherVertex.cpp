/**
 * 
 * A mother vertex in a graph G = (V,E) is a vertex v such that all other vertices in G can be reached by a path from v.
 * */
#include <bits/stdc++.h>
using namespace std;
class Graph{
    int V;
	list<int> *adj;
   void DFSutil(int v,bool visited[]);
    int vertex;
public:
	void addEdge(int u,int v);
	Graph(int v);
	int findMotherVer();
	
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

   
        list<int>::iterator it;
        for(it=adj[v].begin();it!=adj[v].end();it++){
            if(visited[*it]==false) 
            DFSutil(*it,visited);
        }
}
int Graph::findMotherVer(){
    bool *visited=new bool[V];
for(int i=0;i<V;i++){
    visited[i]=false;
}
 for (int i = 0; i < V; i++) 
    { 
        if (visited[i] == false) 
        { 
               this->vertex=i;   
            DFSutil(i, visited); 
        
        } 
    }
   
for(int i=0;i<V;i++){
    visited[i]=false;
}
DFSutil(this->vertex,visited);
for(int i=0;i<V;i++){
    if(visited[i]==false)
    return -1;
}
return this->vertex;
}
int main() {
   Graph g(7); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(4, 1); 
    g.addEdge(6, 4); 
    g.addEdge(5, 6); 
    g.addEdge(5, 2); 
    g.addEdge(6, 0); 
  
    cout << "A mother vertex is " << g.findMotherVer()<<endl; 
    return 0;
}
