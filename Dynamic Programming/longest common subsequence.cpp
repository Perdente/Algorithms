//https://www.techiedelight.com/longest-common-subsequence/
//https://www.youtube.com/watch?v=NnD96abizww&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=2
#include<bits/stdc++.h>
using namespace std;
#define mx 20
int lookup[mx][mx];

int LCS_len(string m,string n,int M,int N)
{
	for(int i=1;i<=M;++i)
	{
		for(int j=1;j<=N;++j)
		{
			if(m[i-1]==n[j-1])
			{
				lookup[i][j]=lookup[i-1][j-1]+1;
			}
			else
			{
				lookup[i][j]=max(lookup[i-1][j],lookup[i][j-1]);
			}
		}
	}
	return lookup[M][N];
}

string LCS(string m,string n,int M,int N)
{
	if(M==0 ||N==0)
	{
		return string("");
	}
	if(m[M-1]==n[N-1])
	{
		return LCS(m,n,M-1,N-1)+m[M-1];
	}
	if(lookup[M-1][N]>lookup[M][N-1])return LCS(m,n,M-1,N);
	else return LCS(m,n,M,N-1);
}
int main()
{
	string s1="abcdaf",s2="acbcf";
	int M=s1.size(),N=s2.size();
	cout<<"Longest Common Subsequence length is :"<<LCS_len(s1,s2,M,N)<<endl;
	cout<<"Longest Common Subsequence is :"<<LCS(s1,s2,M,N)<<endl;
}
