#include<bits/stdc++.h>
using namespace std;
int main()
{
	int prime[100000],n;
	prime[0],prime[1]=0;
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		prime[i]=1;
	}
	for(int i=2;i<=n;i++)
	{
		if(prime[i]==1)
		{
			for(int j=2;i*j<=n;j++)
			{
				prime[i*j]=0;
			}
			cout<<i<<" ";
		}
	}
}
