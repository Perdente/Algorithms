#include<iostream>
#include<queue>
using namespace std;
int main()
{
	priority_queue<int>pq;
	priority_queue<int,vector<int>,greater<int>>p;
	int n,x;cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>x;
		pq.push(x);
		p.push(x);
	}
	cout<<"Max heap elements are ->"<<endl;
	while(!pq.empty())
	{
		int i=pq.top();
		pq.pop();
		cout<<i<<" ";
	}
	cout<<endl;
	cout<<"Min heap elements are->"<<endl;
	while(!p.empty())
	{
		int i=p.top();
		p.pop();
		cout<<i<<" ";
	}
	cout<<endl;
}
