// geeksforgeeks.org/count-divisors-of-factorial/

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
const int mx = 1e6;

vector<bool> isPrime(mx+1,true);
vector<int> primes;

void Sieve(){
    isPrime[0]=isPrime[1]=false;
    int sq=sqrt(mx);
    for(int i=2;i<=mx;++i){
        if(isPrime[i] and (i*i)<=mx){
            primes.push_back(i);
            for(int j=i*i;j<=mx;j+=i) isPrime[j]=false;
        }
    }
    for(int i=sq+1;i<=mx;++i){
        if(isPrime[i])primes.push_back(i);
    }
}

void malena(){
    int n; cin >> n;
    int ans = 1;
    for (auto value : primes) {
        if (value > n) continue;
        int k = 0, m = n;
        while (m) {
            k += m / value;
            m /= value;
        }
        ans *= (k + 1);
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t, c = 0;
    t = 1;
    Sieve();
    // cin >> t;
    while(t--) {
        // cout << "Case " << ++c <<": ";
        malena();
    }
    return 0;
}
