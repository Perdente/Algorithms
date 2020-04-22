#include<bits/stdc++.h>
using namespace std;

#define mx 20010
#define INF 1e9+7
vector<int>edge[mx],cost[mx];

int dijkstra(int source,int destination)
{
	int d[mx];
	memset(d,INF,sizeof(d));
	priority_queue<int,vector<int>,greater<int>>q;
	q.push(source);
	d[source]=0;
	while(!q.empty())
	{
		int u=q.top();
		q.pop();
		for(int i=0;i<edge[u].size();++i)
		{
			int v=edge[u][i];
			if(d[v]>d[u]+cost[u][i])
			{
				d[v]=d[u]+cost[u][i];
				q.push(v);
			}
		}
	}
	return d[destination];
}

int main()
{
	int n,e,src,dist;
	while(scanf("%d%d",&n,&e)==2)
	{
		while(e--)
		{
			int u,v,w;
			cin>>u>>v>>w;
			edge[u].push_back(v);
			edge[v].push_back(u);
			cost[u].push_back(w);
			cost[v].push_back(w);
		}
		cin>>src>>dist;
		int ans=dijkstra(src,dist);
		cout<<ans<<endl;
	}
}
