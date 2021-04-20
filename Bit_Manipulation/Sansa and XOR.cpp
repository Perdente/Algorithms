//https://www.hackerrank.com/challenges/sansa-and-xor/problem
/*
https://math.stackexchange.com/a/1941272
Suppose that our array is: [1,2,3…,n]. How many contiguous subarrays contain k? Look at the following drawing:

|1|2|3|4|…|k−1|k|k+1|…|n|.

Every subarray containing k can be obtained by selecting a "barrier" to the left of k and a barrier to the right of k. There are k barriers to the left of k and n−k+1 barriers to the right of k.

Therefore there are k(n−k+1) contiguous subarrays containing k in the array [1,2,3…n]
*/

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
		int x,ans=0;
		for(int i=1;i<=n;++i){
			cin>>x;
			if(i*(n-i+1)&1)ans^=x;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
