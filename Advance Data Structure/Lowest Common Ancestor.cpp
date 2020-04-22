//https://cp-algorithms.com/graph/lca.html
//LCA using segment tree
#include<bits/stdc++.h>
using namespace std;
      
#define mx 10005
vector<int>graph[mx],height,euler,first,segtree;
vector<bool>visited;

void dfs(int node,int h)
{
	visited[node]=true;
	height[node]=h;
	first[node]=euler.size();
	euler.push_back(node);
	for(auto to:graph[node])
	{
		if(!visited[to])
		{
			dfs(to,h+1);
			euler.push_back(node);
		}
	}
}

void build(int node,int low,int hi)
{
	if(low==hi)
	{
		segtree[node]=euler[low];return;
	}
	int mid=(low+hi)/2;
	build(2*node+1,low,mid);
	build(2*node+2,mid+1,hi);
	int l=segtree[2*node+1],r=segtree[2*node+2];
	segtree[node]=(height[l]<height[r]?l:r);
}

int query(int node,int L,int R,int low,int hi)
{
	if(L>hi or R<low)return -1;
	if(L>=low and R<=hi)return segtree[node];
	int mid=(L+R)/2;
	int left=query(2*node+1,L,mid,low,hi);
	int right=query(2*node+2,mid+1,R,low,hi);
	if(left==-1)return right;
	if(right==-1)return left;
	return height[left]<height[right]?left:right;
}

int LCA(int u,int v)
{
	int left=first[u],right=first[v];
	if(left>right)swap(left,right);
	return query(0,0,euler.size()-1,left,right);
}

int main()
{
	int n,e,x,y;cin>>n>>e;
	for(int i=0;i<e;++i)
	{
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	height.resize(n);
	first.resize(n);
	euler.reserve(2*n);
	visited.assign(n,false);
	dfs(0,0);
	int m=euler.size();
	for(auto x:height)cout<<x<<" ";
	cout<<endl;
	segtree.resize(4*m);
	build(0,0,m-1);
	cout<<LCA(6,3)<<endl;
	cout<<LCA(4,0)<<endl;
	cout<<LCA(5,4)<<endl;
	cout<<LCA(3,2)<<endl;
	return 0;
}
/*11 10
0 1
0 2
0 5
1 8
1 9
9 10
2 3
3 4
5 6
6 7*/
