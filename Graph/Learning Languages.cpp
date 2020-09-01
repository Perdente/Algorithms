/*https://codeforces.com/contest/277/problem/A*/
//DFS traversal
#include<bits/stdc++.h>
using namespace std;

vector<int>graph[105];
vector<bool>vis(105);

void dfs(int u)
{
    vis[u]=true;
    for(auto i:graph[u])
    {
        if(!vis[i])dfs(i);
        
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>node[105];
    bool flag=true;
    for(int i=1;i<=n;++i)
    {
        int a;
        cin>>a;
        if(a>0)flag=false;
        while(a--)
        {
            int x;
            cin>>x;
            node[x].push_back(i);
        }
    }
    if(flag)
    {
        cout<<n<<endl;exit(0);
    }
    for(int i=1;i<=m;++i)
    {
        for(int j=0;j<node[i].size();++j)
        {
            for(int k=j+1;k<node[i].size();++k)
            {
                int u=node[i][j],v=node[i][k];
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=n;++i)
    {
        if(!vis[i])
        {
            dfs(i);
            cnt++;
        }
    }
    cout<<cnt-1<<endl;
    return 0;
}
