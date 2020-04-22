#include<bits/stdc++.h>
using namespace std;
#define mx 1005
int parent[mx],Rank[mx];
pair<int,pair<int,int>>graph[mx];
int n,e,x,y,w;
void make_set(int v) {
    for(int i=0;i<v;++i)
    {
    	parent[i] = i;
    	Rank[i] = 0;
	}
}

int find_set(int v) {//determines the parent
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    
    if (a != b) {
        if (Rank[a] < Rank[b])
            swap(a, b);
        parent[b] = a;
        if (Rank[a] == Rank[b])
            Rank[a]++;
    }
}


int Kruskal(pair<int, pair<int, int> > graph[])
{
	int c,mc=0;
	for(int i=0;i<e;++i)
	{
		int p=graph[i].second.first;
		int q=graph[i].second.second;
		c=graph[i].first;
		if(find_set(p)!=find_set(q))
		{
			mc+=c;
			union_sets(p,q);
		}
	}
	return mc;
}
int main()
{
	cin>>n>>e;
	for(int i=0;i<e;++i)
	{
		cin>>x>>y>>w;
		graph[i]=make_pair(w,make_pair(x,y));
	}
	make_set(e);
	sort(graph,graph+e);
	int mincost=Kruskal(graph);
	cout<<mincost<<endl;
	return 0;
}
