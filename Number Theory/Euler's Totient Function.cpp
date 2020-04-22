#include<bits/stdc++.h>
using namespace std;

int Phi(int n)
{
	int result=n;
	if(n%2==0)
	{
		while(n%2==0)
		{
			n/=2;
		}
		result-=result/2;
	}
	for(int i=3;i*i<=n;i+=2)
	{
		if(n%i==0)
		{
			while(n%i==0)
			{
				n/=i;
			}
			result-=result/i;
		}
	}
	if(n>1) result-=result/n;
	return result;
}

int main()
{
	int n;cin>>n;
	cout<<Phi(n)<<endl;
}
