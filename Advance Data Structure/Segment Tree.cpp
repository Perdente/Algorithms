
/* * A segment tree is a tree data structure for storing intervals, or segments. It allows 
 * for faster querying (e.g sum or min) in these intervals. Lazy propagation is useful
 * when there are high number of updates in the input array.
 * Write a program to support mininmum range query
 * createSegmentTree(int arr[]) - create segment tree
 * query(int segment[], int startRange, int endRange) - returns minimum between startRange and endRange
 * update(int input[], int segment[], int indexToBeUpdated, int newVal) - updates input and segmentTree with newVal at index indexToBeUpdated;
 * updateRange(int input[], int segment[], int lowRange, int highRange, int delta) - updates all the values in given range by
 * adding delta to them
 * queryLazy(int segment[], int startRange, int endRange) - query based off lazy propagation
 *
 * Time complexity to create segment tree is O(n) since new array will be at max 4n size
 * Space complexity to create segment tree is O(n) since new array will be at max 4n size
 * Time complexity to search in segment tree is O(logn) since you would at max travel 4 depths
 * Time complexity to update in segment tree is O(logn)
 * Time complexity to update range in segment tree is O(range)
 * */
 
#include<bits/stdc++.h>
using namespace std;
int num[]={4,1,2,3};
int seg[4*sizeof(num)]={};

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
	if(seg_str>q_end or seg_end<q_str)return INT_MAX;
	if(seg_str>=q_str and seg_end<=q_end)return seg[seg_si];
	int mid=(seg_str+seg_end)/2;
	int x=query(2*seg_si+1,seg_str,mid,q_str,q_end);
	int y=query(2*seg_si+2,mid+1,seg_end,q_str,q_end);
	return min(x,y);
}

void update(int seg_si,int seg_str,int seg_end,int q_ind,int value)
{
	if(seg_str==seg_end)
	{
		seg[seg_si]=num[seg_str];return;
	}
	int mid=(seg_str+seg_end)/2;
	
	if(q_ind<=mid)update(2*seg_si+1,seg_str,mid,q_ind,value);
	else update(2*seg_si+2,mid+1,seg_end,q_ind,value);
	
	seg[seg_si]=min(seg[2*seg_si+1],seg[2*seg_si+2]);
}
int main()
{
	bld_segtree(0,0,3);//from root = 0 we construct from index 0 to index 3 segment tree in arr_min[]
	for(int i=0;i<sizeof(num);++i)
	{
		cout<<seg[i]<<" ";
	}
	cout<<endl;
	cout<<query(0,0,3,1,2)<<endl;
	update(0,0,3,2,-1);
	for(int i=0;i<sizeof(num);++i)
	{
		cout<<seg[i]<<" ";
	}
	cout<<endl;
	cout<<query(0,0,3,0,3)<<endl;
}
