//https://marcodiiga.github.io/optimal-binary-search-tree
#include<bits/stdc++.h>
using namespace std;

int sum(int fre[],int a,int b)
{
	int s=0;
	for(int i=a;i<=b;++i)s+=fre[i];
	return s;
}
int minCostBST(int keys[],int fre[],int n)
{
	int cost[n][n];
	for(int i=0;i<n;++i)
	{
		cost[i][i]=fre[i];
	}
	for(int len=2;len<=n;++len)
	{
		for(int i=0;i<=n-len+1;++i)
		{
			int j=i+len-1;
			cost[i][j]=INT_MAX;
			for(int k=i;k<=j;++k)
			{
				int c=sum(fre,i,j)+((k>i)?cost[i][k-1]:0)+((k<j)?cost[k+1][j]:0);
				if(c<cost[i][j])cost[i][j]=c;
			}
		}
	}
	return cost[0][n-1];
}
int main()
{
	int keys[]={10,12,16,21};
	int fre[]={4,2,6,3};
	int n=sizeof(keys)/sizeof(keys[0]);
	cout<<minCostBST(keys,fre,n)<<endl;
}
