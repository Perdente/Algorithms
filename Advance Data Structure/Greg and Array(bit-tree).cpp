//https://codeforces.com/contest/295/problem/A
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int mx=1e5+5;
int arr[mx],l[mx],r[mx],tree[mx],tree2[mx],va[mx];
void update(int idx,int val,int n)
{
    while(idx<=n){
        tree[idx]+=val;
        idx+=(idx & -idx);
    }
}
 
int read(int idx)
{
    int sum=0;
    while(idx>0){
        sum+=tree[idx];
        idx-=(idx & -idx);
    }
    return sum;
}
 
void update2(int idx,int val,int n)
{
    while(idx<=n){
        tree2[idx]+=val;
        idx+=(idx & -idx);
    }
}
 
int read2(int idx)
{
    int sum=0;
    while(idx>0){
        sum+=tree2[idx];
        idx-=(idx & -idx);
    }
    return sum;
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n,m,k,val,x,y;cin>>n>>m>>k;
	for(int i=1;i<=n;++i)
		cin>>arr[i];
	for(int i=1;i<=m;++i)
		cin>>l[i]>>r[i]>>va[i];
	for(int i=1;i<=k;++i){
		cin>>x>>y;
		update2(x,1,m);
		update2(y+1,-1,m);
	}
	for(int i=1;i<=m;++i){
		int temp=(va[i]*read2(i));
		update(l[i],temp,n);
		update(r[i]+1,-temp,n);
	}
	for(int i=1;i<=n;++i){
		cout<<read(i)+arr[i]<<" ";
	}
	cout<<'\n';

	return 0;
	
}
