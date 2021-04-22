//https://www.codechef.com/problems/IRSTXOR
#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		bool flag=true,flag1=false;
		int a=0,b=0;
		for(int mask=31;mask>=0;--mask){
			if(n & (1<<mask)){
				flag1=true;
				if(flag){
					a+=(1<<mask);
					flag=false;
				}else{
					b+=(1<<mask);
				}
			}else{ 
				if(flag1){
					a+=(1<<mask);
					b+=(1<<mask);
				}
			}
		}
		cout<<a*b<<'\n';
	}

	return 0;
}
