//https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/mathematically-beautiful-numbers-174a158e/
#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t;cin>>t;
	while(t--){
		int n,k;cin>>n>>k;
		int cnt=0;
		vector<int>freq(100);
		while(n){
			cnt++;
			freq[n%k]++;
			n/=k;
		}
		if(freq[0]+freq[1]==cnt)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
