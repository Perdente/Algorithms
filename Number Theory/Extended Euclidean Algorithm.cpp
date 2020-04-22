/*Finding the Modular Inverse using Extended Euclidean algorithm*/
//https://www.youtube.com/watch?v=O7qFxAOxKuc
//https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
#include<bits/stdc++.h>
using namespace std;
int x,y;

int gcdExtended(int a,int b,int *x,int *y)
{
	if(a==0)
	{
		*x=0,*y=1;
		return b;
	}
	int x1,y1;
	int gcd=gcdExtended(b%a,a,&x1,&y1);
	*x=y1-(b/a)*x1;
	*y=x1;
	return gcd;
}

void modInverse(int a,int m)
{
	int g=gcdExtended(a,m,&x,&y);
	if(g!=1)
	{
		cout<<"Inverse doesn't exist\n";//a and m are not coprimes
	}
	else
	{
		int res=(x%m+m)%m;//m is added to handle negative x
		cout<<"Modular multiplicative inverse is: "<<res<<endl;
	}
}

int main()
{
	int t;cin>>t;
	while(t--)
	{
		int a,m;cin>>a>>m;
		modInverse(a,m);
	}
	return 0;
}
