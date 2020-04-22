//https://www.youtube.com/watch?v=We3YDTzNXEk&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=6
#include<bits/stdc++.h>
using namespace std;
int min(int a,int b,int c) 
{
	return min(a,min(b,c));
}
int editDistance(string s1,string s2,int a,int b)
{
	int T[a+1][b+1];
	for(int i=0;i<=a;++i)T[i][0]=i;
	for(int i=0;i<=b;++i)T[0][i]=i;
	for(int i=1;i<=a;++i)
	{
		for(int j=1;j<=b;++j)
		{
			if(s1[i-1]==s2[j-1])
			{
				T[i][j]=T[i-1][j-1];
			}
			else
			{
				T[i][j]=1+min(T[i][j-1],T[i-1][j],T[i-1][j-1]);
			}
		}
	}
	for(int i=1;i<=a;++i)
	{
		for(int j=1;j<=b;++j)
		{
			//cout<<T[i][j]<<" ";
		}
		//cout<<endl;
	}
	int i=a,j=b;
	while(true)
	{
		if(i==0 || j==0) break;
		if(s1[i-1]==s2[j-1])
		{
			i--,j--;
		}
		else if(T[i][j]==T[i-1][j-1]+1)
		{
			cout<<"Replace "<<s2[j-1]<<" (string2) into "<<s1[i-1]<<" (string1)\n";
			i--,j--;
		}
		else if(T[i][j]==T[i][j-1]+1)
		{
			cout<<"Delete "<<s2[j-1]<<" in string2 \n";
			j--;
		}
		else if(T[i][j]==T[i-1][j]+1)
		{
			cout<<"Delete "<<s1[i-1]<<" in string1 \n";
			i--;
		}
	}
	return T[a][b];
}

int main()
{
	string s1="saturday",s2="sunday";
	int a=s1.size(),b=s2.size();
	cout<<"Minimum no of change is: "<<editDistance(s1,s2,a,b)<<endl;
	return 0;
}
