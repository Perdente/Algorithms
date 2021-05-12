/*
https://codeforces.com/contest/797/problem/A
Implementation:Using prime factorization.O(sqrt(n)
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;cin>>n>>m;
    if(m==1)
    {
        cout<<n<<endl;
        return 0;
    }
    vector<int>v;
    while(n%2==0)
    {
        v.push_back(2);
        n/=2;
        if(v.size()==m-1)
        {
            if(n==1)cout<<-1<<endl;
            else
            {
                v.push_back(n);
                for(auto i:v)cout<<i<<" ";
            }
            return 0;
        }
    }
    for(long long i=3;i*i<=n;i+=2)
    {
        while(n%i==0)
        {
            v.push_back(i);
            n/=i;
            if(v.size()==m-1)
            {
                if(n==1)cout<<-1<<endl;
                else
                {
                    v.push_back(n);
                    for(auto i:v)cout<<i<<" ";
                }
                return 0;
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}
