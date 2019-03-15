#include <bits/stdc++.h>
using namespace std;
class Graph{
int v;
	list<int> *adj;
	public:
	void addedge(int v,int u);
	Graph(int v);
	void BFS(int s);
};
Graph::Graph(int V){
	adj=new list<int>[V]; 
	v=V;
}
 void Graph::addedge(int v,int u){
	adj[v].push_back(u);
}
void Graph::BFS(int s){
bool visited[v]={false};
	
	list<int> queue;
	visited[s]=true;
	queue.push_back(s);
	while(!queue.empty()){
		int p=queue.front();
		cout<<p<<endl;
		queue.pop_front();
	    list<int>::iterator it;
		for(it=adj[p].begin();it!=adj[p].end();it++){
			if(!visited[*it]){
				visited[*it]=true;
				queue.push_back(*it);
			}
		}
	}
	
}
int main() {
//    std::cout << "hello, world" << std::endl;
	
	 Graph g(4); 
    g.addedge(0, 1); 
    g.addedge(0, 2); 
    g.addedge(1, 2); 
    g.addedge(2, 0); 
    g.addedge(2, 3); 
    g.addedge(3, 3); 
  
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    g.BFS(2); 
  
    return 0;
}
