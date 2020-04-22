#include<bits/stdc++.h>
using namespace std;

long long recpow(long long a,long long b)
{
	if(b==0)return 1;
	long long res=recpow(a,b/2);
	if(b%2) return res*res*a;
	else return res*res;
}

long long itrpow(long long a,long long b)
{
	long long res=1;
	while(b>0)
	{
		if(b%2)res*=a;
		a*=a;
		b>>=1;
	}
	return res;
}
int main()
{
	long long n,k;cin>>n>>k;
	cout<<recpow(n,k)<<endl<<itrpow(n,k)<<endl;
	return 0;	
}
