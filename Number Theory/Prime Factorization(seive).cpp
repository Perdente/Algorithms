//youtube.com/watch?v=DQJfvz2Dhss&list=PL2q4fbVm1Ik4liHX78IRslXzUr8z5QxsG&index=10
#include<bits/stdc++.h>
using namespace std;

#define mx 1000005
vector<int>isPrime(mx,-1);
void seive()
{
	for(int i=2;i<=mx;++i)
	{
		if(isPrime[i]==-1)
		{
			for(int j=i;j<=mx;j+=i)
			{
				if(isPrime[j]==-1)
				{
					isPrime[j]=i;
				}
			}
		}
	}
}

vector<int> getFactorization(int n)
{
	vector<int>v;
	while(n!=1)
	{
		v.push_back(isPrime[n]);
		n/=(isPrime[n]);
	}
	return v;
}
int main()
{
	seive();
	int n;cin>>n;
	vector<int>ans=getFactorization(n);
	for(int i:ans)cout<<i<<" ";
	cout<<endl;	
	return 0;
}
