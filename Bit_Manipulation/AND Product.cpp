//https://www.hackerrank.com/challenges/and-product/problem
/*
l=8,r=14
8 =1000
9 =1001
10=1010
11=1011
12=1100
13=1101
14=1110
dif=14-8=6
So <=2^2 atleast one zero.So & would be 0;
Finally if both l and r bits are set then we can add it to the ans
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;cin>>t;
    while(t--){
        int l,r;cin>>l>>r;
        int ans=0;
        int dif=r-l;
        for(int i=0;i<32;++i){
            if(dif>(1LL<<i))continue;
            if(l&(1LL<<i) and r&(1LL<<i))ans+=(1LL<<i);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
