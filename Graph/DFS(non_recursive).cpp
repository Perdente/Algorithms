//Non recursive approach
#include<bits/stdc++.h>
using namespace std;
#define mx 10005
vector<int>graph[mx],printpath;


void dfs(int snode,int node)
{
	stack<int>stk;
	stk.push(snode);
	int visited[mx]={0};
	while(!stk.empty())
	{
		int u=stk.top();
		printpath.push_back(u);
		visited[u]=1;
		stk.pop();
		for(int i=0;i<graph[u].size();++i)
		{
			int v=graph[u][i];
			if(!visited[v])
			{
				stk.push(v);
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=node;++i)
	{
		cnt=0;
		if(!visited[i])cnt++;//no of unreachable nodes
	}
	cout<<"No of disconnected path "<<cnt<<endl;
	for(auto x:printpath)
	{
		cout<<x<<" ";
	}
	cout<<endl;
	printpath.clear();
}


int main()
{
	int n,e,x,y;
	cout<<"Enter no of nodes: ";
	cin>>n;
	cout<<"Enter no of edges: ";
	cin>>e;
	for(int i=0;i<e;++i)
	{
		cin>>x>>y;
		graph[x].push_back(y);
		//graph[y].push_back(x);
	}
	dfs(3,n);
	
}
