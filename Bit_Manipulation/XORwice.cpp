//https://codeforces.com/problemset/problem/1421/A
#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){
	int a,b;cin>>a>>b;
	int ans=0;
	for(int mask=63;mask>=0;--mask){
		if(a & (1LL<<mask) and b & (1LL<<mask))continue;
		if(a & (1LL<<mask) or b & (1LL<<mask)){
			ans+=(1LL<<mask);
		}
	}
	cout<<ans<<'\n';
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
