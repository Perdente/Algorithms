//regular bracket sequence and bit manipulation cross-over
//https://codeforces.com/problemset/problem/1494/A
#include<bits/stdc++.h>
using namespace std;
#define int long long int
bool ok(string s){
	int cnt=0;
	for(auto ch:s){
		if(ch=='(')cnt++;
		else cnt--;
		if(cnt<0)return false;
	}
	if(cnt!=0)return false;
	return true;
}

void Malena(){
	string s;cin>>s;
	for(int mask=0;mask<8;++mask){
		string s1;
		for(auto ch:s){
			if(mask & (1<<(ch-'A')))
				s1+='(';
			else
				s1+=')';
		}
		if(ok(s1)){cout<<"YES\n";return;}
	}
	cout<<"NO\n";
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
