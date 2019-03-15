#include <bits/stdc++.h>
using namespace std;
class Graph{
int v;
	list<int> *adj;

	public:
	void addedge(int v,int u);
	Graph(int v);
	bool isBipart(int s);
};
Graph::Graph(int V){
	adj=new list<int>[V]; 
	v=V;
}
 void Graph::addedge(int v,int u){
	adj[v].push_back(u);
}
bool Graph::isBipart(int s){
bool visited[v]={false};
int color[v]={-1};
	list<int> queue;
	visited[s]=true;
	queue.push_back(s);
	color[s]=1;
	while(!queue.empty()){
		int p=queue.front();
		
		queue.pop_front();
	    list<int>::iterator it;
		for(it=adj[p].begin();it!=adj[p].end();it++){
			if(*it==p) //self loop case
				return false; 
			if(!visited[*it]){
                  if(color[*it]==-1&&color[p]==1)
					  color[*it]=0;
				else if(color[*it]==-1&&color[p]==0)
					  color[*it]=1;
				else if(color[p]==color[*it])
					return false;
				visited[*it]=true;
				queue.push_back(*it);
			}
		}
	}
	return true;
}
int main() {
//    std::cout << "hello, world" << std::endl;
	
	 Graph g(4); 
    g.addedge(0, 1); 
    g.addedge(0, 2); 
    g.addedge(2, 2); 
   
  if(g.isBipart(2))
	  cout<<"Biparted"<<endl;
	else
		cout<<"Not Biparted"<<endl;
  
    return 0;
}
