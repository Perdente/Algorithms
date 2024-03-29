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
## DFS
### Directed graph(https://vjudge.net/problem/Aizu-ALDS1_11_B#author=VUPC)
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

### Connected Components
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
### Bipartite Coloring

> Algorithm
> - use a $color$ vector which stores $0$ or $1$ for every node which denotes oposite colors.
> - call each time $DFS$ from any non-visited node.
> - if the node $u$ has not been visited previously, then assign $col$ to $color[u]$ and call $DFS$ to adjacent node $v$ and change color to $col$ ^ $1$
> - if any point $col[u] = col[v]$ then the node isn't bipartite.
> - modify the $DFS$ function to return $bool$.  

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
### Cycle Detection (undirectedGraph)
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
### Cycle Detection (directedGraph)
```c++
// https://www.youtube.com/watch?v=uzVUw90ZFIg
// https://leetcode.com/problems/course-schedule/
const int N = 1e5 + 5;
vector<int> g[N];
vector<bool> vis(N), dfsVis(N);

bool dfs(int u) {
    vis[u] = true;
    dfsVis[u] = true;
    for (auto v: g[u]) {
        if (!vis[v]) {
            if (dfs(v)) return true;
        } else if (dfsVis[v]) {
            return true;
        }
    }
    dfsVis[u] = false;
    return false;
}
int n, m; cin >> n >> m;
for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
}
bool cycle = false;
for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
       if (dfs(i)) {
          cycle = true;
       }
    }
}
cout << (cycle ? "Yes\n": "No\n");
```

## BFS
### single sourse shortest distance (https://vjudge.net/contest/475737#problem/G)
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
### Single source shortest path (https://cses.fi/problemset/task/1667)
```c++
    int n, m; cin >> n >> m;
    vector<int>edges[n + 1];
    while(m--){
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<int> parent(n + 1, -1);
    vector<bool> vis(n + 1);
    auto bfs = [&] (int snode) {
        fill(vis.begin(), vis.end(), false);
        queue<int> q;
        q.push(snode);
        while(! q.empty()){
            int u = q.front();
            q.pop();
            vis[u] = true;
            for(auto v : edges[u]) {
                if(vis[v]) continue;
                vis[v] = true;
                parent[v] = u;
                q.push(v);
 
            }
        }
    };
    bfs(1);
    if( parent[n] == -1) {
        cout << "IMPOSSIBLE\n"; return;
    }
    int node = n;
    vector<int> path;
    path.push_back(n);
    while(node != 1) {
        path.push_back(parent[node]);
        node = parent[node];
    }
    cout << (int) path.size() << '\n';
    for (int i = path.size() - 1; i >= 0; --i) {
        cout << path[i] << " ";
    }cout << endl;
```
### BFS on Grid (4 directions)
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
### BFS On Grid (8 directions https://vjudge.net/contest/475737#problem/Q)
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
### Multi Source BFS(https://www.codechef.com/problems/SNSOCIAL)
```c++
void malena(){
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int> (m));
    vector<vector<int>> level(n, vector<int> (m));
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            mx = max(mx, grid[i][j]);
        }
    }
    int H = n;
    int W = m;
    int ans = 0;

    auto inside = [&](int row,int col) {
        return 0 <= row and row < H and 0 <= col and col < W;
    };

    vector<pair<int,int>> directions {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, -1}, {-1, 1}, {-1, -1}, {1, 1}};
    vector<vector<bool>> vis(H, vector<bool> (W));
    queue<pair<int, int> > q;
    for(int row = 0; row < H; ++row){
        for(int col = 0; col < W; ++col){
            if(grid[row][col] == mx){
                vis[row][col] = true;
                q.push({row, col});
            }
        }
    }
    while(! q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        for(pair<int,int> dir : directions) {
            int new_row = p.first + dir.first;
            int new_col = p.second + dir.second;
            if(inside(new_row,new_col) and !vis[new_row][new_col]){
                vis[new_row][new_col] = true;
                level[new_row][new_col] = level[p.first][p.second] + 1;
                q.push({new_row, new_col});
                ans = max(ans, level[new_row][new_col]);
            }
        }
    }
    cout << ans << '\n';
}
```
### Labyrinth(https://cses.fi/problemset/task/1193)
> You are given a map of a labyrinth, and your task is to find a path from start to end. You can walk left, right, up and down.

```c++
void malena(){
    int n, m; cin >> n >> m;
    string grid[n];
    queue<pair<int, int>> q;
    vector< vector< pair<int, int>>> path(n);
    vector< vector< bool>> vis(n, vector<bool> (m));
    vector< pair< int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    pair<int, int> end, start;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            path[i].push_back( {-1, -1});
            if (grid[i][j] =='A'){
                start = {i, j};
                q.push({i, j});
                vis[i][j] = true;
            }
            if(grid[i][j] == 'B'){
                end = {i, j};
            }
            if(grid[i][j] == '#'){
                vis[i][j] = true;
            }
        }
    }
 
    auto inside = [&] (int row, int col) {
        return 0 <= row and row < n and 0 <= col and col < m;
    };
 
    while (!q.empty()) {
        int old_row = q.front().first;
        int old_col = q.front().second;
        q.pop();
        for (pair<int,int> dir: directions) {
            int new_row = old_row + dir.first;
            int new_col = old_col + dir.second;
            if (inside(new_row, new_col) and !vis[new_row][new_col]) {
                vis[new_row][new_col] = true;
                path[new_row][new_col] = {dir.first, dir.second};
                q.push({new_row, new_col});
            }
        }
    }
    if(!vis[end.first][end.second]) {cout << "NO\n"; return;}
    cout << "YES" << '\n';
    vector<pair<int, int>> ans;
    while (end.first != start.first or end.second != start.second) {
        ans.push_back ( path[end.first][end.second]);
        end.first -= ans.back().first;
        end.second -= ans.back().second;
    }
    reverse(ans.begin(), ans.end());
    cout << (int) ans.size() << '\n';
    for (auto [x, y]: ans) {
        if (x == 1 and y == 0) cout << 'D';
        else if (x == -1 and y == 0) cout << 'U';
        else if (x == 0 and y == 1) cout << 'R';
        else cout << 'L';
    }
    cout << '\n';
}
```

### Lava Flow(https://cses.fi/problemset/task/1194/)
> You and some monsters are in a labyrinth. When taking a step to some direction in the labyrinth, each monster may simultaneously take one as well. Your goal is to reach one of the boundary squares without ever sharing a square with a monster.

```c++
// https://www.youtube.com/watch?v=hB59dxdDLII
const int oo = 1e9;

void malena(){
    int n, m; cin >> n >> m;
    string grid[n];

    queue< pair< pair< int, int>, int>> monsters, player;
    map< pair< int, int>, pair<int, int>> parent;
    vector< vector< int>> lava_time(n, vector<int> (m));
    vector< pair< int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] =='M'){
                monsters.push({{i, j}, 0});
                lava_time[i][j] = 0;
            } else if (grid[i][j] == '#'){
                lava_time[i][j] = 0;
            } else if (grid[i][j] == 'A'){
                lava_time[i][j] = 0;
                player.push({{i, j}, 0});
                parent[{i, j}] = {-1, -1};
            }else {
                lava_time[i][j] = oo;
            }
        }
    }

    auto isInside = [&] (int row, int col) {
        return 0 <= row and row < n and 0 <= col and col < m;
    };
    // if the grid value is not already consumed by lava then its valid
    auto isValid = [&] (int row, int col, int timer) {
        return lava_time[row][col] > timer;
    };
    // the edge points
    auto isEscapePoint = [&] (int row, int col) {
        return row == 0 or row == n - 1 or col == 0 or col == m - 1;
    };

    // if the player is already on the edge of the grid ??
    if(isEscapePoint(player.front().first.first, player.front().first.second)) {
        cout << "YES\n" << "0\n"; return;
    }

    // for each monsters first we calculate how much space it consumes with certain time
    // using multisource bfs method
    while (!monsters.empty()) {
        int old_row = monsters.front(). first. first;
        int old_col = monsters.front(). first. second;
        int timer = monsters.front(). second; // the time to fill that grid via monster
        timer++;
        monsters.pop();
        for (pair<int,int> dir: directions) {
            int new_row = old_row + dir.first;
            int new_col = old_col + dir.second;
            if (isInside(new_row, new_col) and isValid(new_row, new_col, timer)) {
                lava_time[new_row][new_col] = timer;
                monsters.push({{new_row, new_col}, timer});
            }
        }
    }
    bool found = false;
    pair<int, int> end;
    while (!player.empty() and !found) {
        int old_row = player.front(). first. first;
        int old_col = player.front(). first. second;
        int timer = player.front(). second;
        timer++;
        player.pop();
        for (pair<int,int> dir: directions) {
            int new_row = old_row + dir.first;
            int new_col = old_col + dir.second;
            if (isEscapePoint(new_row, new_col) and isValid(new_row, new_col, timer)) {
                parent[{new_row, new_col}] = {old_row, old_col};
                found = true;
                end = {new_row, new_col}; break;
            }
            if (isValid(new_row, new_col, timer)) {
                parent[{new_row, new_col}] = {old_row, old_col};
                lava_time[new_row][new_col] = timer;
                player.push({{new_row, new_col}, timer});
            }
        }

    }
    if (!found) {
        cout << "NO" << '\n'; return;
    }
    cout << "YES" << '\n';
    pair<int, int> end_parent = parent[end];
    pair<int, int> start = {-1, -1};
    string ans =  "";
    while (end_parent != start) {
        int x1 = end.first,  x2 = end_parent.first;
        int y1 = end.second, y2 = end_parent.second;
        if (x1 - x2 == 0 and y1 - y2 == 1) {
            ans += 'R';
        } else if (x1 - x2 == 1 and y1 - y2 == 0) {
            ans += 'D';
        } else if (x1 - x2 == -1 and y1 - y2 == 0) {
            ans += 'U';
        } else {
            ans += 'L';
        }
        end = parent[end];
        end_parent = parent[end_parent];
    }
    reverse(ans.begin(), ans.end());
    cout << (int) ans.size() << '\n';
    for (auto ch : ans) cout << ch;
    cout << '\n';
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
![](https://i0.wp.com/algorithms.tutorialhorizon.com/files/2018/03/Topological-Sort.png?ssl=1)
[Alien dictionary](https://practice.geeksforgeeks.org/problems/alien-dictionary/1#)
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
















