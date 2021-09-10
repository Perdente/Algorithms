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
