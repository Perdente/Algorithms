//https://forthright48.com/number-of-divisors-of-integer
#include<bits/stdc++.h>
using namespace std;

#define mx 1000005
vector<int>isPrime(mx,-1);
vector<int>Primes;
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

void getFactorization(int n)
{
	while(n!=1)
	{
		Primes.push_back(isPrime[n]);
		n/=(isPrime[n]);
	}
}

int numberOfDivisors(int n)
{
	int sq=sqrt(n);
	int res=1;
	for(int i=0;i<Primes.size() and Primes[i]<=sq;++i)
	{
		if(n%Primes[i]==0)
		{
			int cnt=0;
			while(n%Primes[i]==0)
			{
				n/=Primes[i];
				cnt++;
			}
			sq=sqrt(n);
			cnt++;
			res*=cnt;
		}
	}
	if(n!=1)res*=2;
	return res;
}
int main()
{
	seive();
	int n;cin>>n;
	getFactorization(n);
	//for(auto x:Primes)cout<<x<<" ";
	//cout<<endl;
	cout<<numberOfDivisors(n)<<endl;
	return 0;
}
