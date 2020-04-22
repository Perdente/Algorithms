//https://github.com/mazedrupok/Algorithms/blob/master/BFS%20algorithm
#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>


using namespace std;
vector<int> G[100];
void bfs(int n, int src)
{
    queue<int> Q;
    Q.push(src);
    int visited[100] = {0}, level[100];
    int parent[100];
    visited[src] = 1;
    level[src] = 0;
	while(!Q.empty() )
	{
		int u = Q.front();
		for(int i = 0; i < G[u].size(); i++)//G[u].size() determines the no of nodes connected to u
		{
			int v = G[u][i];//G[u][i] determines the nodes which are connected to the u nod
			if(!visited[v] )
			{
				level[v] = level[u] + 1;
				parent[v] = u;
				visited[v] = 1;
				Q.push(v);
			}
		}
		Q.pop();
	}
	for(int i = 1; i <= n; i++)
		printf("%d to %d distance %d\n", src, i, level[i]);
}

int main ()
{
   int x, y, N , E, i;
   cout << "Enter Nodes and Edges number: ";
   cin >> N >> E;
   cout<<"Enter the node pair for edges: \n";
   for (i = 0; i < E; i++) {
      cin >> x >> y;
      G[x].push_back(y);
      G[y].push_back(x);
   }
   cout<<"Printing the graph"<<endl;
   for(int i=1;i<=N;++i)
   {
	   	cout<<i;
	   	for( vector<int>::iterator itr= G[i].begin() ; itr!=G[i].end(); itr++){
	        cout<<" -> "<<*itr;
	    }
	    cout<<endl;
   }
   cout<<"Distance from each node"<<endl;
   for(int i=1;i<=N;++i)
   {
   		bfs(N,i);
   		cout<<endl;
   }
   
}
