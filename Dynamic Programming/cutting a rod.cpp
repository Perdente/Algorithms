//https://www.youtube.com/watch?v=IRwVmTmN6go&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=10
#include<bits/stdc++.h>
using namespace std;
vector<int>length;
int cuttingrod(int arr[],int len,int n)
{
	int T[n+1][len+1];

	for(int i=0;i<=n;++i)	
	{
		T[i][0]=0;
	}
	for(int j=1;j<=len;++j)	
	{
		T[0][j]=j;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=len;++j)
		{
			if(j>=i)
			{
				T[i][j]=max(T[i-1][j],arr[i-1]+T[i][j-i]);
			}
			else
			{
				T[i][j]=T[i-1][j];
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=len;++j)
		{
			cout<<T[i][j]<<" ";
		}
		cout<<endl;
	}
	int temp=len;
	for(int i=n;i>0 and temp>0;--i)
	{
		if(T[i][temp]==T[i-1][temp])
		{
			if(i==1)length.push_back(i);
			continue;
		}
		else
		{
			while(T[i][temp]!=T[i-1][temp])
			{
				length.push_back(i);
				temp-=i;
			}
			
		}
	}
	return T[n][len];
} 


int main()
{
	int prize[]={2,5,7,8};
	int n=sizeof(prize)/sizeof(prize[0]);
	int len=5;
	cout<<cuttingrod(prize,len,n)<<endl;
	reverse(length.begin(),length.end());
	for(int i:length)cout<<i<<" ";
	return 0;
}
