#include<bits/stdc++.h>
using namespace std;
#define mx 10005

int num[mx];
int seg[4*mx];
int lazy[4*mx];

void bld_segtree(int seg_si,int seg_str,int seg_end)
{
	if(seg_str==seg_end)
	{
		seg[seg_si]=num[seg_str];return ;
	}
	int mid=(seg_str + seg_end)/2;
	bld_segtree(2*seg_si+1,seg_str,mid);//recurse on the left child
	bld_segtree(2*seg_si+2,mid+1,seg_end);//recurse on the right child
	seg[seg_si]=min(seg[2*seg_si+1],seg[2*seg_si+2]);
}

int query(int seg_si,int seg_str,int seg_end,int q_str,int q_end)
{
	if(lazy[seg_si]!=0)
	{
		seg[seg_si]+=lazy[seg_si];
		if(seg_str!=seg_end)
		{
			lazy[2*seg_si+1]+=lazy[seg_si];
			lazy[2*seg_si+2]+=lazy[seg_si];
		}
		lazy[seg_si]=0;
	}
	if(seg_str>q_end or seg_end<q_str)return INT_MAX;
	if(seg_str>=q_str and seg_end<=q_end)return seg[seg_si];
	int mid=(seg_str+seg_end)/2;
	int x=query(2*seg_si+1,seg_str,mid,q_str,q_end);
	int y=query(2*seg_si+2,mid+1,seg_end,q_str,q_end);
	return min(x,y);
}

void update(int seg_si,int seg_str,int seg_end,int q_str,int q_end,int value)
{
	if(lazy[seg_si]!=0)//if lazy contains previous value
	{
		seg[seg_si]+=lazy[seg_si];
		if(seg_str!=seg_end)
		{
			lazy[2*seg_si+1]+=lazy[seg_si];
			lazy[2*seg_si+2]+=lazy[seg_si];
		}
		lazy[seg_si]=0;
	}
	if(seg_str>q_end or seg_end<q_str) return ;//no overlap
	if(seg_str>=q_str and seg_end<=q_end)//total overlap
	{
		seg[seg_si]+=value;//update the range
		if(seg_str!=seg_end)//if not leaf not then update its children
		{
			lazy[2*seg_si+1]+=value;
			lazy[2*seg_si+2]+=value;
		}
		return ;
	}
	int mid=(seg_str+seg_end)/2;
	update(2*seg_si+1,seg_str,mid,q_str,q_end,value);
	update(2*seg_si+2,mid+1,seg_end,q_str,q_end,value);
	seg[seg_si]=min(seg[2*seg_si+1],seg[2*seg_si+2]);
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
//	for(int i=0;i<4*n;++i)
//	{
//		cout<<seg[i]<<" ";
//	}
//	cout<<endl;
	cout<<query(0,0,n-1,1,2)<<endl;
	update(0,0,n-1,0,1,2);
	//for(int i=0;i<4*n;++i)
	//{
	//	cout<<seg[i]<<" ";
	//}
	cout<<endl;
	cout<<query(0,0,n-1,0,n-1)<<endl;
}
