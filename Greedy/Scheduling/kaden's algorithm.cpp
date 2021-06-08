#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e7+5;

void Malena(){
	int n;cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;++i){
		cin>>v[i];
	}
	int mx_end_here=0,mx_so_far=INT_MIN;
	for(int i=0;i<n;++i){
		mx_end_here+=v[i];
		if(mx_end_here<v[i]){
			mx_end_here=v[i];
		}
		if(mx_so_far<mx_end_here){
			mx_so_far=mx_end_here;
		}
		cout<<mx_end_here<<" "<<mx_so_far<<endl;
	}
	cout<<mx_so_far<<endl;
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
