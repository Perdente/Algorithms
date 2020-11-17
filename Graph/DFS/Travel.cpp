/*https://atcoder.jp/contests/abc183/tasks/abc183_c*/
#include<iostream>
using namespace std;

int n,k,i,j,a[10][10],cnt;
bool vis[10]={};

void dfs(int x,int d,int s){
	if(d==n){
		if(s+a[x][1]==k)++cnt;
		return;
	}
	vis[x]=1;
	for(int i=1;i<=n;++i){
		if(!vis[i])dfs(i,d+1,s+a[x][i]);
	}
	vis[x]=0;
}
int main()
{
    cin>>n>>k;
    for(i=1;i<=n;++i){
    	for(j=1;j<=n;++j){
    		cin>>a[i][j];
    	}
	}
	dfs(1,1,0);
	cout<<cnt<<endl;
}
