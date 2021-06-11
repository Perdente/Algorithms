//https://cp-algorithms.com/data_structures/sqrt_decomposition.html
//https://www.youtube.com/watch?v=o7278rPg_9I&ab_channel=CodeNCodeCodeNCode
#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){
	int n;cin>>n;
	vector<int>v(n);
	for(auto &i:v)cin>>i;
	int len=(int)sqrt(n+0.0)+1;
	vector<int>sqd(len);
	for(int i=0;i<n;++i){
		sqd[i/len]+=v[i];
	}
	int m;cin>>m;
	while(m--){
		int l,r;cin>>l>>r;l--,r--;
		int sum=0;
		int lb=l/len,rb=r/len;
		if(lb==rb){
			for(int i=l;i<=r;++i)sum+=v[i];
		}else{
			for(int i=l;i<len*(lb+1);++i){
				sum+=v[i];
			}
			for(int i=lb+1;i<rb;++i){
				sum+=sqd[i];
			}
			for(int i=len*rb;i<=r;++i){
				sum+=v[i];
			}
		}
		cout<<sum<<endl;
	}
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
