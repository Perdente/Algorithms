#include<bits/stdc++.h>
using namespace std;
#define mx 10005
vector<pair<int,int>>graph[mx];
vector<int>v;
int visited[mx]={0};
int n,e,x,y,w;

int prims(int s)
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	int mc=0;
	pair<int,int>p;
	pq.push(make_pair(0,s));
	while(!pq.empty())
	{
		p=pq.top();pq.pop();
		s=p.second;
		if(visited[s]==1)continue;
		else v.push_back(s);
		mc+=p.first;
		visited[s]=1;
		for(int i=0;i<graph[s].size();++i)
		{
			int t=graph[s][i].second;
			if(visited[t]==0)
			{
				pq.push(graph[s][i]);
			}
		}
	}
	return mc;
}

int main()
{
	cin>>n>>e;
	for(int i=1;i<=e;++i)
	{
		cin>>x>>y>>w;
		graph[x].push_back(make_pair(w,y));
		graph[y].push_back(make_pair(w,x));
	}
	int src;cin>>src;
	int p=prims(src);
	cout<<p<<endl;
	for(auto i:v)cout<<i<<" ";
	
	return 0;
}
