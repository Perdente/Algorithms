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

int sumOfDivisors(int n) {
    int res = 1;
    int sqrtn = sqrt(n);
    for ( int i = 0; i < Primes.size() && Primes[i] <= sqrtn; i++ ) {
        if (n%Primes[i]==0) {
            int tempSum = 1; // Contains value of (p^0+p^1+...p^a)
            int p = 1;
            while (n%Primes[i]==0) {
                n /= Primes[i];
                p *= Primes[i];
                tempSum += p;
            }
            sqrtn = sqrt (n);
            res *= tempSum;
        }
    }
    if (n!=1) res *= (n+1); // Need to multiply (p^0+p^1)
        
    return res;
}
int main()
{
	seive();
	int n;cin>>n;
	getFactorization(n);
	//for(auto x:Primes)cout<<x<<" ";
	//cout<<endl;
	cout<<sumOfDivisors(n)<<endl;
	return 0;
}
