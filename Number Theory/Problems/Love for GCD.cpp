//https://www.hackerearth.com/problem/algorithm/c-29/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+5;
int fre[N];
void Malena(){
	int n;cin>>n;
	for(int i=0;i<n;++i){
		int x;cin>>x;
		fre[x]++;
	}
	int ans=(n-fre[0])*(n-fre[0]-1)/2;
	for(int i=1;i<N;++i){
		if(fre[i]){
			ans-=fre[i]*(fre[i]-1)/2;
			for(int j=2*i;j<N;j+=i){
				ans-=fre[i]*fre[j];
			}
		}
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
