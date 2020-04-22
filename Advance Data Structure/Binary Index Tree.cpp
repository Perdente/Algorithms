
/* * A Fenwick tree or binary indexed tree is a data structure providing efficient methods
 * for calculation and manipulation of the prefix sums of a table of values.
 * 
 * Space complexity for fenwick tree is O(n)
 * Time complexity to create fenwick tree is O(nlogn)
 * Time complexity to update value is O(logn)
 * Time complexity to get prefix sum is O(logn)
 
 src:https://www.youtube.com/watch?v=CWDQJGaN1gY&t=941s
 */
 
#include<bits/stdc++.h>
using namespace std;
#define mx 10005
int fenwick[mx]={0},n;
int arr[mx];
void build(int idx,int x)
{
	while(idx<=n)
	{
		fenwick[idx]+=x;
		idx += (idx & -idx);
	     /**
	     * To get next
	     * 1) 2's complement of get minus of index
	     * 2) AND this with index
	     * 3) Add it to index
	     */
	}
}
int query(int idx)
{
	int sum=0;
	while(idx>0)
	{
		sum+=fenwick[idx];
		idx-=(idx & -idx);
		  /**
	     * To get parent
	     * 1) 2's complement to get minus of index
	     * 2) AND this with index
	     * 3) Subtract that from index
	     */
	}
	return sum;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>arr[i];
		build(i,arr[i]);
	}
	cout<<"The Fenwick tree: ";	
	for(int i=1;i<=n;++i)
	{
		cout<<fenwick[i]<<" ";
	}
	cout<<endl;
	printf("\nsum of first 10 elements is %d\n", query(10));
    printf("\nsum of all elements in range [2, 7] is %d\n", query(7) - query(2-1));
	return 0;
}
