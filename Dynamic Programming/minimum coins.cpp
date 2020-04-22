//https://www.youtube.com/watch?v=Y0ZqKpToTic&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=5
#include<bits/stdc++.h>
using namespace std;
vector<int>micoins;
int mincoins(int arr[],int sum,int n)
{
	int T[n+1][sum+1];
	for(int j=1;j<=sum;++j)	
	{
		T[0][j]=j;
	}
	for(int i=0;i<=n;++i)	
	{
		T[i][0]=0;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=sum;++j)
		{
			if(j>=arr[i-1])
			{
				T[i][j]=min(T[i-1][j],1+T[i-1][j-arr[i-1]]);
			}
			else
			{
				T[i][j]=T[i-1][j];
			}
		}
	}
	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<=sum;++j)
		{
			cout<<T[i][j]<<" ";
		}
		cout<<endl;
	}
	int temp=sum;
	for(int i=n;i>0 and temp>0;--i)
	{
		if(T[i][temp]==T[i-1][temp])
		{
			if(i==1)micoins.push_back(arr[i-1]);
			continue;
		}
		else
		{
			micoins.push_back(arr[i-1]);
			temp-=arr[i-1];
		}
	}
	return T[n][sum];
} 


int main()
{
	int coins[]={1,5,6,8};
	int n=sizeof(coins)/sizeof(coins[0]);
	int sum=9;
	cout<<mincoins(coins,sum,n)<<endl;
	reverse(micoins.begin(),micoins.end());
	for(int i:micoins)cout<<i<<" ";
	return 0;
}
