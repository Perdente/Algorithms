//https://www.youtube.com/watch?v=cETfFsSTGJI
#include<bits/stdc++.h>
using namespace std;
int seq[100];
int mindis(int arr[],int n)
{
	int minjump[n];
	for(int i=0;i<n;++i)
	{
		minjump[i]=INT_MAX,seq[i]=i;
	}
	minjump[0]=0,seq[0]=-1;
	for(int i=1;i<n;++i)
	{
		for(int j=0;j<i;++j)
		{
			if(arr[j]+j>=i)
			{
				minjump[i]=min(minjump[i],minjump[j]+1);
				if(minjump[i]==minjump[j]+1) seq[i]=j;
			}
		}
	}
	return minjump[n-1];
}
int main()
{
	int arr[]={2,3,1,1,2,4,2,0,1,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<mindis(arr,n)<<endl;
	vector<int>ans;
	int k=n-1;
	while(k>=0)
	{
		ans.push_back(arr[k]);
		k=seq[k];
	}
	reverse(ans.begin(),ans.end());
	for(auto i:ans)cout<<i<<" ";
	cout<<endl;
	return 0;
}
