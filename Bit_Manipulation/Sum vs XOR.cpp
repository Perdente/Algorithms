//https://www.hackerrank.com/challenges/sum-vs-xor/problem
#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){
    int n;cin>>n;
    if(n==0){
        cout<<1<<'\n';
        return;
    }
    int x=64-(__builtin_popcountll(n)+__builtin_clzll(n));
    cout<<(1LL<<x);

}

signed main()
{
    
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    t=1;
    //cin>>t;
    while(t--){
        Malena();
    }
    return 0;
}
