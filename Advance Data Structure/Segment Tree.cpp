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
int arr_min[4*sizeof(num)]={};
void bld_segtree(int pos,int low,int hi)
{
	if(low==hi)
	{
		arr_min[pos]=num[low];return ;
	}
	int mid=(low + hi)/2;
	bld_segtree(2*pos+1,low,mid);//recurse on the left child
	bld_segtree(2*pos+2,mid+1,hi);//recurse on the right child
	arr_min[pos]=min(arr_min[2*pos+1],arr_min[2*pos+2]);
}
int query(int pos,int L,int R,int low,int hi)
{
	if(L>hi or R<low)return INT_MAX;
	if(L>=low and R<=hi)return arr_min[pos];
	int mid=(L+R)/2;
	int x=query(2*pos+1,L,mid,low,hi);
	int y=query(2*pos+2,mid+1,R,low,hi);
	return min(x,y);
}
void update(int at,int L,int R,int pos,int value)
{
	if(L==R)
	{
		arr_min[at]=value;return ;
	}
	int mid=(L+R)/2;
	if(pos<=mid)update(2*at+1,L,mid,pos,value);
	else update(2*at+2,mid+1,R,pos,value);
	arr_min[at]=min(arr_min[2*at+1],arr_min[2*at+2]);
}
int main()
{
	bld_segtree(0,0,3);//from root = 0 we construct from index 0 to index 3 segment tree in arr_min[]
	for(int i=0;i<sizeof(num);++i)
	{
		cout<<arr_min[i]<<" ";
	}
	cout<<endl;
	cout<<query(0,0,3,1,2)<<endl;
	update(0,0,3,2,-1);
	for(int i=0;i<sizeof(num);++i)
	{
		cout<<arr_min[i]<<" ";
	}
	cout<<endl;
	cout<<query(0,0,3,0,3)<<endl;
}
