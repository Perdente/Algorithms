//https://www.youtube.com/watch?v=ru7mWZJlRQg
//https://www.geeksforgeeks.org/chinese-remainder-theorem-set-2-implementation/
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

int modInverse(int a,int m)
{
	int g=gcdExtended(a,m,&x,&y);
	int res=(x%m+m)%m;
	return res;
}

int findMinX(int num[],int rem[],int k)
{
	int pro=1;
	for(int i=0;i<k;++i)pro*=num[i];
	int result=0;
	for(int i=0;i<k;++i)
	{
		int pp=pro/num[i];
		result+=(rem[i]*modInverse(pp,num[i])*pp);
	}
	return result%pro;
}

int main()
{
	int num[3]={3,4,5},rem[3]={2,3,1};
	int k=3;
	cout<<findMinX(num,rem,k);
	return 0;
}
