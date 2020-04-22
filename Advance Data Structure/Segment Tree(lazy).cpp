#include<bits/stdc++.h>
using namespace std;
#define mx 10005
int num[mx];
int seg[4*mx];
int lazy[4*mx];
void bld_segtree(int pos,int low,int hi)
{
	if(low==hi)
	{
		seg[pos]=num[low];return ;
	}
	int mid=(low + hi)/2;
	bld_segtree(2*pos+1,low,mid);//recurse on the left child
	bld_segtree(2*pos+2,mid+1,hi);//recurse on the right child
	seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
}
int query(int pos,int L,int R,int low,int hi)
{
	if(lazy[pos]!=0)
	{
		seg[pos]+=lazy[pos];
		if(L!=R)
		{
			lazy[2*pos+1]+=lazy[pos];
			lazy[2*pos+2]+=lazy[pos];
		}
		lazy[pos]=0;
	}
	if(L>hi or R<low)return INT_MAX;
	if(L>=low and R<=hi)return seg[pos];
	int mid=(L+R)/2;
	int x=query(2*pos+1,L,mid,low,hi);
	int y=query(2*pos+2,mid+1,R,low,hi);
	return min(x,y);
}
void update(int at,int L,int R,int l,int r,int value)
{
	if(lazy[at]!=0)//if lazy contains previous value
	{
		seg[at]+=lazy[at];
		if(L!=R)
		{
			lazy[2*at+1]+=lazy[at];
			lazy[2*at+2]+=lazy[at];
		}
	}
	if(L>r or R<l) return ;//no overlap
	if(L>=l and R<=r)//total overlap
	{
		seg[at]+=value;//update the range
		if(L!=R)//if not leaf not then update its children
		{
			lazy[2*at+1]+=value;
			lazy[2*at+2]+=value;
		}
		return ;
	}
	int mid=(L+R)/2;
	update(2*at+1,L,mid,l,r,value);
	update(2*at+2,mid+1,R,l,r,value);
	seg[at]=min(seg[2*at+1],seg[2*at+2]);
}
int main()
{
	int n;cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>num[i];
	}
	memset(lazy,0,sizeof(lazy));
	bld_segtree(0,0,n-1);//from root = 0 we construct from index 0 to index 3 segment tree in arr_min[]
	for(int i=0;i<4*n;++i)
	{
		cout<<seg[i]<<" ";
	}
	cout<<endl;
	cout<<query(0,0,n-1,1,2)<<endl;
	update(0,0,n-1,0,1,2);
	for(int i=0;i<4*n;++i)
	{
		cout<<seg[i]<<" ";
	}
	cout<<endl;
	cout<<query(0,0,n-1,0,n-1)<<endl;
}
