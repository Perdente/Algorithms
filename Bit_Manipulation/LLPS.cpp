//creating subsets of all possible substrings
//https://codeforces.com/contest/202/problem/A
#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){
	string s;cin>>s;
	string ans="";
	int n=s.size();
	for(int mask=1;mask<(1<<n);++mask){
		string str="";
		for(int i=0;i<n;++i){
			if(mask & (1<<i)){
				str+=s[i];
			}
		}
		int m=str.size();
		bool flag=true;
		for(int i=0;i<=m/2;++i){
			if(str[i]!=str[m-1-i])flag=false;
		}
		if(flag and str>ans)ans=str;
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
	//cin>>t;
	while(t--){
		Malena();
	}
	return 0;
}
