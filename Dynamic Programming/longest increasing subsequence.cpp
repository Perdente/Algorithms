//https://www.youtube.com/watch?v=CE2b_-XfVDk
//https://www.techiedelight.com/longest-increasing-subsequence-using-dynamic-programming/
#include<bits/stdc++.h>
using namespace std;

int LIS_len(int arr[],int n)
{
	int lis[n]={0};	
	lis[0]=1;
	for(int i=1;i<n;++i)
	{
		for(int j=0;j<i;++j)
		{
			if(arr[j]<arr[i] and lis[j]>lis[i])
			{
				lis[i]=lis[j];
			}
		}
		lis[i]++;
	}
	int lis_max=INT_MIN;
	for(int i:lis)
	{
		lis_max=max(lis_max,i);
	}
	return lis_max;
}

void LIS(int arr[],int n)
{
	vector<int>lis[n];
	lis[0].push_back(arr[0]);
	for(int i=1;i<n;++i)
	{
		for(int j=0;j<i;++j)
		{
			if(arr[j]<arr[i] and lis[j].size()>lis[i].size())
			{
				lis[i]=lis[j];
			}
		}
		lis[i].push_back(arr[i]);
	}
	int ind;
	for(int i=0;i<n;++i)
	{
		if(lis[ind].size()<lis[i].size())
		{
			ind=i;
		}
	}
	for(int i:lis[ind])
	{
		cout<<i<<" ";
	}
	cout<<endl;
}

int main()
{
	int num[]={0,4,3,1,55,23,52,5,5,4,66,23,0,9,3,5,2,1,5,66,222,55332,52,11,1,53,66,352,5335};
	int n=sizeof(num)/sizeof(num[0]);
	
	cout<<"Length of longest increasing subsequence is: "<<LIS_len(num,n)<<endl;
	
	cout<<"Longest increasing subsequence :";
	LIS(num,n);
}
