//bit-manipulation & dp
//https://www.codechef.com/problems/XORSUB
#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){
	int n,k;cin>>n>>k;
	int a[n+1];
	int dp[n+1][1024];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	dp[0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=0;j<1024;++j){
			dp[i][j]=dp[i-1][j] | dp[i-1][j^a[i]];
		}
	}
	int ma=0;
	for(int j=0;j<1024;++j){
		if(dp[n][j])ma=max(ma,k^j);
	}
	cout<<ma<<'\n';
}

signed main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	t=1;
	cin>>t;
	while(t--){
		Malena();
	}
	return 0;
}

