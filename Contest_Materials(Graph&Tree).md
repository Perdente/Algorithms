# Graph
### DFS
>Connected Components
```c++
const int N=1e6+1;
vector<int>adj[N],dis(N);
vector<bool>vis(N);
while(k--){
  int a,b;
  cin>>a>>b;
  adj[a].push_back(b);
  adj[b].push_back(a);
}

function<void(int)>dfs=[&](int u)->void{
  vis[u]=true;
  for(auto v:adj[u]){
    if(!vis[v]){
      vis[v]=true;
      dfs(v);
    }
  }
};
int cnt=0;
for(int i=1;i<=n;++i){
  if(!vis[i]){
    cnt++;
    dfs(i);
  }
}
cout<<cnt<<'\n';
```
>Bipartite Coloring
```c++
vector<vector<int>>graph;
vector<int>color;
int n,m;cin>>n>>m;
graph.resize(n+1);
color.resize(n+1);
bool flag=true;
function<void(int,int)>dfs=[&](int u,int col)->void{
  color[u]=col;
  for(auto v:graph[u]){
    if(color[v]==col)flag=false;
    if(color[v]==-1){
      dfs(v,col^1);
    }
  }
};
for(int i=1;i<=n;++i){
  graph[i].clear();
  color[i]=-1;
}
for(int i=0;i<m;++i){
  int u,v;cin>>u>>v;
  graph[u].push_back(v);
  graph[v].push_back(u);
}
for(int i=1;i<=n;++i){
  if(graph[i].size() and color[i]==-1){
    dfs(i,0);
  }
}
```
>Cycle Detection
```c++
vector<int> adj[n+1];
vector<bool> vis(n+1);
for(int i=0;i<m;++i){
  int u,v;cin>>u>>v;
  adj[u].push_back(v);
  adj[v].push_back(u);	
}
bool found_cycle=true;
function<void(int)>dfs=[&](int u){
  vis[u]=true;
  if(adj[u].size()!=2) found_cycle=false;//checks if degree is 2
  for(auto v:adj[u]){
    if(!vis[v]){
      dfs(v);
    }
  }
};
int cnt=0;
for(int node=1;node<=n;++node){
  found_cycle=true;
  if(!vis[node]){// checks for each cc
    dfs(node);
    if(found_cycle)cnt++;
  }
}
cout<<cnt<<"\n";
```
### BFS
```c++
vector<int>adj[n+1];
while(m--){
  int u,v;cin>>u>>v;
  adj[u].push_back(v);
  adj[v].push_back(u);
}
vector<int>dis(n+1);
vector<bool>vis(n+1);
auto bfs=[&](int s){
  queue<int>q;
  q.push(s);
  vis[s]=true;
  dis[s]=0;
  while(!q.empty()){
    int u=q.front();
    q.pop();
    for(auto v:adj[u]){
      if(!vis[v]){
        vis[v]=true;
        dis[v]=1+dis[u];
        q.push(v);
      }
    }
  }
};
bfs(1);
```
> BFS on Grid
```c++
int H=grid.size();
int W=grid[0].size();
int ans=0;
auto inside =[&](int row,int col){
    return 0<=row and row<H and 0<=col and col<W;
};

vector<pair<int,int>>directions{{1,0},{0,1},{-1,0},{0,-1}};
vector<vector<bool>>vis(H,vector<bool>(W));
for(int row=0;row<H;++row){
    for(int col=0;col<W;++col){
        if(!vis[row][col] and grid[row][col]=='1')
        {
            ans++;
            vis[row][col]=true;
            queue<pair<int,int>>q;
            q.push({row,col});
            while(!q.empty()){
                pair<int,int>p=q.front();
                q.pop();
                for(pair<int,int>dir:directions){
                    int new_row=p.first+dir.first;
                    int new_col=p.second+dir.second;
                    if(inside(new_row,new_col) and !vis[new_row][new_col] and grid[new_row][new_col]=='1')
                    {
                        vis[new_row][new_col]=true;
                        q.push({new_row,new_col});
                    }
                }
            }
        }
    }
}
```
### Dijsktra's Algorithm
```c++
#define p pair<int,int>
int n;cin>>n;
vector<p>edge[n+1];
unordered_map<string,int> mp;
for(int u=1;u<=n;++u){
  string s;cin>>s;
  mp[s]=u;
  int m;cin>>m;
  while(m--){
    int v,w;cin>>v>>w;
    edge[u].push_back({w,v});
    edge[v].push_back({w,u});
  }
}	
priority_queue<p,vector<p>,greater<p>> pq;
auto Dijsktra=[&](int snode,int enode)->int{
  pq.push({0,snode});
  vector<int> dist(n+1,inf);
  vector<bool> vis(n+1);
  dist[snode]=0;
  while(!pq.empty()){
    int u=pq.top().second;
    pq.pop();
    if(vis[u])continue;
    vis[u]=true;
    for(auto [w,v]:edge[u]){
      if(dist[u]+w<dist[v]){
        dist[v]=dist[u]+w;
        pq.push({dist[v],v});
      }
    }
  }
  return dist[enode];
};

int q;cin>>q;
while(q--){
  string start,end;
  cin>>start>>end;
  cout<<Dijsktra(mp[start],mp[end])<<'\n';
}
```
# Tree

>Subordinate of nodes
```c++
int n;cin>>n;
vector<vector<int>>tree(n+1);
vector<int>ans(n+1);
for(int i=2;i<=n;++i){
  int x;cin>>x;
  tree[x].push_back(i);
  tree[i].push_back(x);
}
function<void(int,int)>solve=[&](int u,int par)->void{
  int subords=0;
  for(auto v:tree[u]){
    if(v!=par){
      solve(v,u);
      subords+=1+ans[v];
    }
  }
  ans[u]=subords;
};
solve(1,0);
for(int i=1;i<=n;++i)
  cout<<ans[i]<<" ";
cout<<'\n';
```
>Tree Diameter
```c++
vector<vector<int>>adj;
vector<bool>visited;
int n;cin>>n;
if(n==1){
  cout<<0<<'\n';return;
}
adj.resize(n+1);
visited.resize(n+1);
int mx_dis=0,y=-1;
function<void(int,int)>dfs=[&](int u,int dis)->void{
  visited[u]=true;
  if(dis>mx_dis){
    mx_dis=dis;
    y=u;
  }
  for(auto v:adj[u]){
    if(!visited[v]){
      dfs(v,dis+1);
    }
  }
};
for(int i=0;i<n-1;++i){
  int u,v;cin>>u>>v;
  adj[u].push_back(v);
  adj[v].push_back(u);
}
dfs(1,0);
//visited.clear();
for(int i=1;i<=n;++i)visited[i]=false;
dfs(y,0);
cout<<mx_dis<<'\n';
```

>Lowest Common Ancestor using binary lifting
```c++
const int N = 10005;
const int LOG = 14;

vector<int>children[N];
int up[N][LOG]; // up[v][j] is the 2^j th ancestor of v
int depth[N];

void dfs(int a){
	for(int b:children[a]){
		depth[b]=depth[a]+1;
		up[b][0]=a; // a is the parent of b 
		for(int j=1;j<LOG;++j){
			up[b][j]=up[ up[b][j-1] ][j-1];
		}
		dfs(b);
	}
}
//O(log(n))
int get_lca(int a,int b){
	if(depth[a]<depth[b]) swap(a,b);
	int k=depth[a]-depth[b];// To get the same depth
	for(int j=LOG-1;j>=0;--j){
		if(k & (1<<j)){
			a=up[a][j]; // parent of a
		}
	}
	if(a==b)return a;

	for(int j=LOG-1;j>=0;--j){ // move both a & b power of 2 as binary lifting 
		if(up[a][j]!=up[b][j]){
			a=up[a][j];
			b=up[b][j];
		}
	}
	return up[a][0];
}
int main(){
int n;cin>>n;
	for(int v=0;v<n;++v){
		int nodes;cin>>nodes;
		while(nodes--){
			int c;cin>>c;
			children[v].push_back(c);
		}
	}
	dfs(0);
	int q;cin>>q;
	while(q--){
		int x,y;cin>>x>>y;
		cout<<get_lca(x,y)<<'\n';
	}
}
```
