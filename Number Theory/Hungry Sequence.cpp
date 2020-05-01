//Simple seive generate the prime numbers
#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
//const long long mx  = 1e5+5;

#define inf INT_MAX
#define zero INT_MIN
#define PI   acos(-1.0)  // 3.1415926535897932
#define Case(J) printf("Case %lld: %lld\n",++count,J); ///print case
#define Loser ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define GCD(a,b) __gcd(a,b)
#define LCM(a,b) (a*(b/__gcd(a,b) ))
#define MP make_pair
#define pb push_back
#define rev(v) reverse(v.begin(),v.end());
#define srt(v) sort(v.begin(),v.end());
#define grtsrt(v) sort(v.begin(),v.end(),greater<ll>());
#define hellyeah exit(0);
#define file freopen("input.txt","r",stdin);
#define vmax(v) *max_element(v.begin(),v.end());
#define vmin(v) *min_element(v.begin(),v.end());

///==========DEBUGGING=============///
#define	debug(a) 		cout<<"*"<<a<<endl;
#define	debug2(a,b) 	cout<<"$"<<a<<" "<<b<<endl;
#define	debug3(a,b,c) 	cout<<"$"<<a<<" "<<b<<" "<<c<<endl;
#define mem(a, n)       memset(a, n, sizeof(a))
#define check           cout<<"Avenger's Assemble"<<endl;
#define	lol 			cout<<'\n';
#define meem cout<<(flag?"YES":"NO")<<endl;
#define joker(v) for(auto x:v)cout<<x<<" ";cout<<endl;
#define papiya(mp) for(auto x:mp)cout<<x.first<<" "<<x.second<<endl;
#define each(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define lp(i,a) for(int i=0; i<a;i++)
#define lp1(i,a,b) for(int i=(a);i<=(b);++i)
#define rlp(i,b,a) for(int i=(b);i>=(a);--i) 


typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair <ll, ll> pll;
typedef pair <ll, pll> plp;
typedef pair <int, int> pii;
typedef pair <int, pii> pip;
typedef vector < pii > vii;
typedef vector < pll > vll;
typedef map <string, ll> mpsl;
typedef map <string, int> mpsi;
typedef map <int, int> mii;
typedef map <pii, int> mpii;
typedef map <ll, ll> mll;
typedef map <pll, ll> mpll;
int middle(int a, int b, int c) { if ((a <= b && b <= c) || (c <= b && b <= a)) return b;else if ((b <= a && a <= c) || (c <= a && a <= b))return a;else return c; } 
bool pal(string s) {transform(s.begin(),s.end(),s.begin(),::tolower);return (s[0]==s[s.size()-1]?1:0);}

/*max element in map*/
template<typename KeyType, typename ValueType> 
std::pair<KeyType,ValueType> get_max( const std::map<KeyType,ValueType>& x ) {
  using pairtype=std::pair<KeyType,ValueType>; 
  return *std::max_element(x.begin(), x.end(), [] (const pairtype & p1, const pairtype & p2) {
        return p1.second < p2.second;//min->p1.second>p2.second
  }); 
//auto max=get_max(x);
//std::cout << max.first << "=>" << max.second << std::endl;  
//set->max:m=*a.rbegin();min:mi=*a.begin();
}
static inline bool isvowel(char ch)
{
        static const std::string vowels("aeiouEAIOU");
        return vowels.end() != std::find(vowels.begin(), vowels.end(), ch);
}
template <typename Map>
bool map_compare (Map const &lhs, Map const &rhs) {
    return lhs.size() == rhs.size()
        && std::equal(lhs.begin(), lhs.end(),
                      rhs.begin());
}
ll nCr(ll n,ll k)
{
    ll ans=1;
    k=k>n-k?n-k:k;
    ll j=1;
    for(;j<=k;j++,n--)
    {
        if(n%j==0)
        {
            ans*=n/j;
        }
		else if(ans%j==0)
        {
            ans=ans/j*n;
        }
		else
        {
            ans=(ans*n)/j;
        }
    }
    return ans;
}
//sort a pair according to its second element.
//sort(v.begin(),v.end(),sort_pair_second);
template <class T1, class T2, class Pred = std::less<T2> >
struct sort_pair_second {
    bool operator()(const std::pair<T1,T2>&left, const std::pair<T1,T2>&right) {
        Pred p;
        return p(left.second, right.second);
    }
};
/*------------------------------------------------------------------------------------------------------------------------------------------------------*/
#define mx 10000005
vector<bool>isPrime(mx,true);


void seive(ll n)
{
	isPrime[0]=isPrime[1]=false;
	for(ll i=2;i<=mx;++i)
	{
		if(isPrime[i] and i*i<=mx)
		{
			for(ll j=i*i;j<=mx;j+=i)
			{
				isPrime[j]=false;
			}
		}
	}
	ll cnt=0;
	for(ll i=1;i<=mx;++i)
	{
		if(isPrime[i])
		{
			cnt++;
			cout<<i<<" ";
		}
		if(cnt==n)break;
	}
	cout<<endl;
}
int main()
{
	Loser
	ll n;cin>>n;
	seive(n);
	return 0;
}
