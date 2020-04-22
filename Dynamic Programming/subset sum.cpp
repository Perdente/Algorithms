//https://www.techiedelight.com/subset-sum-problem/
//https://www.youtube.com/watch?v=s6FhG--P7z0&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=4
#include<bits/stdc++.h>
using namespace std;
vector<int>subSetSum;
bool subset_sum(int arr[],int sum,int n)
{
	bool T[n+1][sum+1];
	for(int j=1;j<=sum;++j)
	{
		T[0][j]=false;
	}
	for(int i=0;i<=n;++i)
	{
		T[i][0]=true;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=sum;++j)
		{
			if(arr[i-1]>j)
				T[i][j]=T[i-1][j];
			else
				T[i][j]=T[i-1][j]||T[i-1][j-arr[i-1]];
		}
	}
	int temp=sum;
	for(int i=n;i>0 and temp>0;--i)
	{
		if(T[i][temp]==T[i-1][temp])
		{
			continue;
		}
		else {
			subSetSum.push_back(arr[i-1]);
			temp-=arr[i-1];
		}
		
	}

	return T[n][sum];
}

int main()
{
	int arr[]={4,7,2,6,1,5},sum=16;
	int n=sizeof(arr)/sizeof(arr[0]);
	if(subset_sum(arr,sum,n))
	{
		cout<<"YES\n";
		reverse(subSetSum.begin(),subSetSum.end());
		for(int i:subSetSum)cout<<i<<" ";
	}
	else cout<<"NO\n";
	return 0;
}
