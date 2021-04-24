//https://codeforces.com/problemset/problem/467/B
#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){
	int n,m,k;cin>>n>>m>>k;
	vector<int>v(m+1);
	for(int i=0;i<=m;++i)cin>>v[i];
	int ans=0;
	for(int i=0;i<m;++i){
		int cnt=0;
		for(int mask=0;mask<32;++mask){
			if((v[i] & (1<<mask)) != (v[m] & (1<<mask)))cnt++;
		}
		if(cnt<=k)ans++;
	}
	cout<<ans;
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
	//cin>>t;
	while(t--){
		Malena();
	}
	return 0;
}
