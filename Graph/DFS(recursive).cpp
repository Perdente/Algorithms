
#include <iostream>
#include <vector>
using namespace std;

vector <int> adj[10],d;
bool visited[10];

void dfs(int s) {
    
    
	visited[s] = true;
	d.push_back(s);

    for(int i = 0;i < adj[s].size();++i)    {
     if(visited[adj[s][i]] == false)
     {
     	dfs(adj[s][i]);	
	 }
         
    }
}

void initialize() {
    for(int i = 1;i <= 7;++i)
     visited[i] = false;
}

int main() {
    int nodes, edges, x, y, connectedComponents = 0;
    cin >> nodes;                       //Number of nodes
    cin >> edges;                       //Number of edges
    for(int i = 0;i < edges;++i) {
     cin >> x >> y;     
 //Undirected Graph 
     adj[x].push_back(y);                   //Edge from vertex x to vertex y
     adj[y].push_back(x);                   //Edge from vertex y to vertex x
    }

    initialize();                           //Initialize all nodes as not visited
	dfs(1);
	for(auto x:d)
    {
    	cout<<x<<" ";
	}
	
    for(int i = 1;i <= nodes;++i) {
     if(visited[i] == false)     {
         dfs(i);
         connectedComponents++;
     }
    }
    
    cout << "Number of connected components: " << connectedComponents << endl;
    return 0;
}
