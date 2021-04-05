//https://www.geeksforgeeks.org/submatrix-sum-queries/
//https://www.youtube.com/watch?v=-d8KbQVx-mM&ab_channel=GeeksforGeeks
#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n,m;cin>>n>>m;
	int mat[n+1][m+1];
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>mat[i][j];
		}
	}
	int dp[n+1][m+1];
	memset(dp,0,sizeof(dp));
	dp[0][0]=mat[0][0];
	for(int i=1;i<n;++i) dp[i][0]=mat[i][0]+dp[i-1][0];
	for(int j=1;j<m;++j) dp[0][j]=mat[0][j]+dp[0][j-1];
	for(int i=1;i<n;++i){
		for(int j=1;j<m;++j){
			dp[i][j]=mat[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
		}
	}
	int q;cin>>q;
	while(q--){
		int c1,r1,c2,r2;cin>>r1>>c1>>r2>>c2;
		c1--,r1--,c2--,r2--;
		int res=dp[r2][c2];
		if(c1>0){
			res-=dp[r2][c1-1];
		}
		if(r1>0){
			res-=dp[r1-1][c2];
		}
		if(c1>0 and r1>0){
			res+=dp[r1-1][c1-1];
		}
		cout<<res<<'\n';
	}
	
	return 0;
}
