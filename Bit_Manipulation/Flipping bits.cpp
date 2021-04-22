//https://www.hackerrank.com/challenges/flipping-bits/problem
#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){
    int n;cin>>n;
    int ans=0;
    for(int mask=31;mask>=0;--mask){
        if(!(n & (1LL<<mask)))ans+=((1LL<<mask));
    }
    cout<<ans<<'\n';
}

signed main()
{
    
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    //t=1;
    cin>>t;
    while(t--){
        Malena();
    }
    return 0;
}
