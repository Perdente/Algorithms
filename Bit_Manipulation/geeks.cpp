//https://www.geeksforgeeks.org/find-two-non-repeating-elements-in-an-array-of-repeating-elements/
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
	vector<int>v(n);
	int x=0;
	for(int i=0;i<n;++i){
		cin>>v[i];
		x^=v[i];
	}
	int rsb=x&~(x-1);
	int a=0,b=0;
	for(int i=0;i<n;++i){
		if(v[i]&rsb)a^=v[i];
		else b^=v[i];
	}
	cout<<a<<" "<<b<<endl;

	return 0;
}
