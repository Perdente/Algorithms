//using indegree(no of edge coming to a node) method
#include<bits/stdc++.h>
using namespace std;
#define mx 10001
vector <int> graph[mx],top;
int visited[mx]={0},indegree[mx],n;
bool cycle;

void topological_sort(int u)
{
	for(int i=1;i<=n;++i)
	{
		if(indegree[i]==0)top.push_back(i);
	}
	for(int i=0;i<top.size();++i)
	{
		int u=top[i];
		for(int j=0;j<graph[u].size();++j)
		{
			int v=graph[u][j];
			indegree[v]--;
			if(indegree[v]==0)top.push_back(v);
		}
	}
	cycle=false;
	for(int i=1;i<=n;++i)
	{
		if(indegree[i]>0)cycle=true;
	}
}

int main()
{
    int e,x,y;cin>>n>>e;
    for(int i=0;i<e;++i)
    {
    	cin>>x>>y;
    	graph[x].push_back(y);
    	indegree[y]++;
	}
	topological_sort(n);
	if(cycle)
	{
		cout<<"No topological sort is possible\n";
	}
	else
	{
		cout<<"The topological sort is: ";
		for(auto i:top)cout<<i<<" ";
		cout<<endl;
	}
    return 0;
}
