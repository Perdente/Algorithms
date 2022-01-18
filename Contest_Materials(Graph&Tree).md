# Graph
```c++
struct graph{
	int n;
	vector<bool> vis;
	vector<int> color;
	vector<vector<int>> edges;
	void init(int size){
		n=size();
		edges.resize(n);
		vis.resize(n);
	}
	void read(int tot_edges,bool isUnDirected){
		for(int i=0;i<tot_edges;++i){
			int u,v;cin>>u>>v;u--,v--;
			edges[u].push_back(v);
			if(isUnDirected) edges[v].push_back(u);
		}
	}
	void bfs(int snode){
		fill(vis.begin(), vis.end(),false);
		queue<int> q;
		q.push(snode);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			if(vis[u])continue;
			vis[u]=true;
			for(auto v:edges[u]){
				if(vis[v])continue;
				q.push(v);
			}
		}
	}
	void dfs(int snode){
		vis[snode]=true;
		for(auto v:edges[snode]){
			if(!vis[v]){
				vis[v]=true;
				dfs(v);
			}
		}
	}
};

```
### DFS
> Directed graph(https://vjudge.net/problem/Aizu-ALDS1_11_B#author=VUPC)
```c++
int n; cin >> n;
vector<int> edges[n + 1], strt(n + 1), end(n + 1);
vector<bool> vis(n + 1);

for (int i = 0; i < n; ++i) {
	int id, m; cin >> id >> m;
	while (m--) {
	    int x; cin >> x;
	    edges[id]. push_back(x);
	}
}
int j = 0;
function<void(int)> dfs = [&](int u) -> void {
	vis[u] = true;
	strt[u] = ++j;
	for(auto v:edges[u]){
		if(vis[v]) continue;
		vis[v]=true;
		dfs(v);
		end[v] = ++j;
	}
};
for (int i = 1; i <= n; ++i) {
	if(!vis[i]) {
	    dfs(i);
	    end[i] = ++j;
	}
	cout << i << " " << strt[i] << " " << end[i] << '\n';
}

```

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
    if(vis[v]) continue;
    vis[v]=true;
    dfs(v);
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
function<bool(int,int)>dfs=[&](int u, int par){
	vis[u]=true;
	for(auto v : adj[u]){
		if(!vis[v]){
			if(dfs(v, u)) return true;
		} else if(v != par){
			return true;
		}
	}
	return false;
};
bool foundcycle = false;
for(int i=1 ;i<=n;++i){
	if(!vis[i]){ // check for each connected components if it has a cycle or not
		if(dfs(i,-1)){
			foundcycle = true;
		}
	}
}
```
### BFS
```c++
const int oo = 1e12;
vector<int>edges[n+1];
while(m--){
	int u,v;cin>>u>>v;
	edges[u].push_back(v);
	edges[v].push_back(u);
}
vector<int>dis(n+1);
vector<bool>vis(n+1);
auto bfs = [&] (int snode) {
        fill(vis.begin(), vis.end(), false);
        fill(dis.begin(), dis.end(), oo);
        queue<int> q;
        q.push(snode); dis[snode] = 0;
        while(! q.empty()){
            int u = q.front();
            q.pop();
            if(vis[u]) continue;
            vis[u] = true;
            for(auto v : edges[u]) {
                if(vis[v]) continue;
                if(dis[u] + 1 < dis[v]){
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
    };
    bfs(1);
```
> BFS on Grid (4 directions)
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
> BFS On Grid (8 directions https://vjudge.net/contest/475737#problem/Q)
```c++

int n, m;
while ( cin >> n >> m and n != 0 and m != 0) {
	string grid[n];
	for (int i = 0; i < n; ++i) {
	    cin >> grid[i];
	}

	int H = n;
	int W = m;
	int ans = 0;

	auto inside = [&](int row,int col) {
	    return 0 <= row and row < H and 0 <= col and col < W;
	};

	vector<pair<int,int>> directions {{1,0}, {0,1}, {-1,0}, {0,-1}, {1,-1}, {-1, 1}, {-1, -1}, {1,1}};
	vector<vector<bool>> vis(H, vector<bool> (W));
	for(int row = 0; row < H; ++row){
	    for(int col = 0; col < W; ++col){
		if(!vis[row][col] and grid[row][col] == '@')
		{
		    ans++;
		    vis[row][col] = true;
		    queue<pair<int,int>> q;
		    q.push({row, col});
		    while(! q.empty()) {
			pair<int,int> p = q.front();
			q.pop();
			for(pair<int,int> dir : directions) {
			    int new_row = p.first + dir.first;
			    int new_col = p.second + dir.second;
			    if(inside(new_row,new_col) and !vis[new_row][new_col] and grid[new_row][new_col] == '@')
			    {
				vis[new_row][new_col] = true;
				q.push({new_row, new_col});
			    }
			}
		    }
		}
	    }
	}
	cout << ans << '\n';
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
### TopSort
```c++
int n,m;cin>>n>>m;
vector<int> adj[n+1],indegree(n+1),outdegree(n+1);
vector<bool> vis(n+1);
for(int i=0;i<m;++i){
	int u,v;cin>>u>>v;
	adj[u].push_back(v);
	outdegree[u]++;
	indegree[v]++;
}
vector<int> tops;
auto top_sort=[&](int u){
	for(int i=1;i<=n;++i){
		if(!indegree[i] and outdegree[i])tops.push_back(i);
	}
	for(int i=0;i<tops.size();++i){
		int u=tops[i];
		for(auto v:adj[u]){
		    indegree[v]--;
		    if(indegree[v]==0)tops.push_back(v);
		}
	}	
};
top_sort(n);
for(auto i:tops){
	cout<<i<<" ";
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

>Lowest Common Ancestor using $binary$ $lifting$
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
### Kruskal's Algorithm $\mathcal{O}(m log n)$
> Minimum Spanning Tree
> Input:
```
4 5
1 2 7
1 4 6
4 2 9
4 3 8
2 3 6
```
>Output:
```
Minumum cost is 19
1 4 6
2 3 6
1 2 7
```
```c++
struct Edge {
    int u, v, w;
    bool operator<(Edge const& other) {
        return w < other.w;
    }
};
 
class DSU{
    vector <int> parent, _rank, minimum, maximum, _size;
    public:
        DSU(int n){
            parent.resize(n + 1);
            minimum.resize(n + 1);
            maximum.resize(n + 1);
            _size.assign(n + 1, 1);
            _rank.assign(n + 1, 0);
            initialize(n);
        }
 
        void initialize(int n){
            for(int i = 1 ; i <= n ; ++i){
                parent[i] = i;
                minimum[i] = i;
                maximum[i] = i;
            }
        }
 
        int find_parent(int element){
            if(parent[element] == element) return element;
            return parent[element] = find_parent(parent[element]);
        }
        
        void union_by__rank(int a, int b){
            int pa = find_parent(a);
            int pb = find_parent(b);
            if(pa == pb) return;
            if(_rank[pa] == _rank[pb]) ++_rank[pa];
            if(_rank[pa] > _rank[pb]){
                parent[pb] = pa;
                _size[pa] += _size[pb];
                minimum[pa] = min(minimum[pa], minimum[pb]);
                maximum[pa] = max(maximum[pa], maximum[pb]);
            } else{
                parent[pa] = pb;
                _size[pb] += _size[pa];
                minimum[pb] = min(minimum[pa], minimum[pb]);
                maximum[pb] = max(maximum[pa], maximum[pb]);
            }
        }
  
        void union_by_size(int a,int b){
            int pa = find_parent(a);
            int pb = find_parent(b);
            if (pa != pb) {
                if (_size[pa] < _size[pb])
                    swap(pa, pb);
                parent[pb] = pa;
                minimum[pa]=min(minimum[pa],minimum[pb]);
                maximum[pa]=max(maximum[pa],maximum[pb]);
                _size[pa] += _size[pb];
            }
        }
 
        int getSize(int v){
            return _size[find_parent(v)];
        }
 
        int getMin(int v){
            return minimum[find_parent(v)];
        }
 
        int getMax(int v){
            return maximum[find_parent(v)];
        }
};
 
int cost;
vector<Edge> Kruskal(vector<Edge> edgelist,int n){
	DSU dsu(n);
	vector<Edge> spanningTree;
	sort(edgelist.begin(), edgelist.end());
	for(Edge e: edgelist){
		if(dsu.find_parent(e.u) != dsu.find_parent(e.v)){
			cost += e.w;
			spanningTree.push_back(e);
			dsu.union_by_size(e.u,e.v);
		}
	}
	return spanningTree;
}

int n,m;cin>>n>>m;
vector<Edge> edgelist;
edgelist.resize(m+1);
for(int i=0;i<m;++i){
	cin>>edgelist[i].u>>edgelist[i].v>>edgelist[i].w;
}
vector<Edge> spanningTree=Kruskal(edgelist,n);
cout<<"Minumum cost is "<<cost<<endl;
for(Edge edge:spanningTree){
	cout<<edge.u<<" "<<edge.v<<" "<<edge.w<<endl;
}
```
















