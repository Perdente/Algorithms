/*
https://www.hackerrank.com/challenges/the-great-xor/editorial
Q-given n ; cnt the many a^n>n (0<a<n)
here-10 [1010]
so we fill every 0's in the number in 2^n different possibilities and keep adding them.
[1010]=[0+2^2+0+2^0]=5
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){
    int n;cin>>n;
    int msb=0;
    for(int mask=63;mask>=0;--mask){
        if((n & (1LL<<mask))){
            msb=mask;break;
        }
    }
    int ans=0;
    for(int mask=msb;mask>=0;--mask){
        if(!(n & (1LL<<mask))){
            ans+=(1LL<<mask);
        }
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
