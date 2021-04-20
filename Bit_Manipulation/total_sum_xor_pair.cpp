//Sum of XOR of all pairs in an array
//https://www.geeksforgeeks.org/sum-xor-pairs-array/
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
	int n;cin>>n;
	int a[n];
	int sum=0;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<32;++i){
		int cnt=0,cnt1=0;
		for(int j=0;j<n;++j){
			if(a[j]&(1<<i))cnt1++;
			else cnt++;
		}
		sum+=cnt*cnt1*(1<<i);
	}
	cout<<sum<<'\n';

	
	return 0;
}
