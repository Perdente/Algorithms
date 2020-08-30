/*https://atcoder.jp/contests/abc177/tasks/abc177_d*/

//simple dfs-Count the maximum no of visited node

#include<bits/stdc++.h>
using namespace std;
vector<set<int>>graph;
vector<int>visited;
int cnt;
void dfs(int u)
{
    if(!visited[u])
    {
        visited[u]=1;
        ++cnt;
        //cout<<cnt<<"->"<<u<<endl;
    }
    for(auto v:graph[u])
    {
        if(!visited[v])
        {
            dfs(v);
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;cin>>n>>m;
	graph = vector<set<int> > (n + 1, set<int> ());
	for(int i=0;i<m;++i)
	{
	    int x,y;
	    cin>>x>>y;
	    graph[x].insert(y);
	    graph[y].insert(x);
	}
// 	for(int i=1;i<=n;++i)
// 	{
// 	    cout<<i<<"->";
// 	    for(auto it:graph[i])
// 	    {
// 	        cout<<it<<" ";
// 	    }
// 	    cout<<endl;
// 	}
    visited=vector<int>(n+1);
    int groups=0;
    for(int i=1;i<=n;++i)
    {
        cnt=0;
        if(!visited[i])
        {
            dfs(i);
        }
        groups=max(groups,cnt);
    }
    cout<<groups<<endl;
	return 0;
}
