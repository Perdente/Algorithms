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
