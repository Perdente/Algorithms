#include<bits/stdc++.h>
using namespace std;
#define N 25
int l[N][N];
int lps(string s,int n)
{
	for(int i=0;i<n;++i)l[i][i]=1;
	for(int len=2;len<=n;++len)
	{
		for(int i=0;i<=n-len+1;++i)
		{
			int j=i+len-1;
			if(s[i]==s[j] and len==2)l[i][j]=2;
			else if(s[i]==s[j])l[i][j]=l[i+1][j-1]+2;
			else l[i][j]=max(l[i][j-1],l[i+1][j]);
		}
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			cout<<l[i][j]<<" ";
		}
		cout<<endl;
	}
	int temp=n-1;
	char s1[n-1]={0};
	for(int i=0;i<n and temp>0;++i)
	{
		if(l[i][temp]==l[i+1][temp])continue;
		else 
		{
			s1[i]=s[i],s1[temp]=s[temp];
			temp--;
		}
		
	}
	cout<<"The longest palindrom is: ";
	for(int i=0;i<n;++i)
	{
		if(s1[i]==0)continue;
		cout<<s1[i];
	}
	cout<<endl;
	cout<<"And the size is: ";
	return l[0][n-1];
}

int main()
{
	string s="ABBDCACB";int n=s.size();
	cout<<lps(s,n)<<endl;
	
}
