//https://cp-algorithms.com/algebra/factorization.html
//O(sqrt(n))
#include<bits/stdc++.h>
using namespace std;
vector<long long>pf;
void PrimeFactorization(long long n)
{
	while(n%2==0)
	{
		pf.push_back(2);
		n/=2;
	}
	for(long long i=3;i*i<=n;i+=2)
	{
		while(n%i==0)
		{
			pf.push_back(i);
			n/=i;
		}
	}
	if(n>1)pf.push_back(n);
}

int main()
{
	long long k;cin>>k;
	PrimeFactorization(k);
	for(auto i:pf)cout<<i<<" ";
	cout<<endl;
}
