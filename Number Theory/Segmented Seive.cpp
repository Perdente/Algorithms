//Segmented Seive Algorithm(spoj)
//https://www.youtube.com/watch?v=ykZvMA-8S6s
#include<bits/stdc++.h>
using namespace std;
#define mx 32000//(sqrt of right )

vector<long long>primes;
void seive()
{
	vector<bool>isPrime(mx,true);
	isPrime[0]=isPrime[1]=false;
	for(long long i=2;i<=mx;++i)
	{
		if(isPrime[i])
		{
			primes.emplace_back(i);
			for(long long j=i*i;j<=mx;j+=i)isPrime[j]=false;
		}
	}
	
}

void segmentSeive(long long n,long long m)
{
	vector<bool>isPrime(m-n+1,true);
	if(n==1)isPrime[0]=false;
	for(int i=0;primes[i]*primes[i]<=m;++i)
	{
		int currentPrime=primes[i];
		long long base=(n/currentPrime)*currentPrime;
		if(base<n)base+=currentPrime;
		for(long long j=base;j<=m;j+=currentPrime)
		{
			isPrime[j-n]=false;
		}
		if(base==currentPrime)isPrime[base-n]=true;
	}
	for(int i=0;i<m-n+1;++i)
	{
		if(isPrime[i]) cout<<i+n<<endl;
	}
}

int main()
{
	seive();
	long long t,n,m;cin>>t;
	for(int i=0;i<t;++i)
	{
		cin>>n>>m;
		segmentSeive(n,m);
		cout<<"\n";
	}	
	return 0;
}
