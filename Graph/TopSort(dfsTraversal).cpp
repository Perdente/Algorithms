//using dfs traversal
#include<bits/stdc++.h>
using namespace std;
#define mx 10001
vector <int> graph[mx],top;
int visited[mx]={0};
bool cycle;

void topological_sort(int u)
{
	visited[u]=1;
	for(int i=0;i<graph[u].size();++i)
	{
		int v=graph[u][i];
		if(visited[v]==0)
		{
			topological_sort(v);
		}
		else if(visited[v]==1)
		{
			cycle=true;
			return;
		}
	}
	visited[u]=2;
	top.push_back(u);
}

void dfs_top(int n)
{
	for(int i=1;i<=n;++i)
	{
		if(cycle)return ;
		if(visited[i]==0)topological_sort(i);
	}
}
int main()
{
    int n,e,x,y;cin>>n>>e;
    for(int i=0;i<e;++i)
    {
    	cin>>x>>y;
    	graph[x].push_back(y);
	}
	cycle=false;
	dfs_top(n);
	reverse(top.begin(),top.end());
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
