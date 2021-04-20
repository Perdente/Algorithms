//XOR of all pair sum in an array
//https://www.youtube.com/watch?v=LyMPfMe7T58&list=PL2q4fbVm1Ik7ip1VkWwe5U_CEb93vw6Iu&index=10

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
	int x=0;
	for(int i=0;i<n;++i)cin>>a[i],x^=2*a[i];
	cout<<x<<'\n';
	
	return 0;
}
