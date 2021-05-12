//Number of Divisors.
//https://codeforces.com/problemset/problem/236/B
#include<bits/stdc++.h>
using namespace std;
const long long mod = 1073741824;
const long long mx  = 1e5+5;

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
#define ppb pop_back
#define pf push_front
#define ppf pop_front
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
#define groot(A)		return cout<<A<<endl,0
#define vins(V)			srt(V)V.resize(unique(V.begin(),V.end())-V.begin());
#define check           cout<<"Avenger's Assemble"<<endl;
#define	lol 			cout<<'\n';
#define meem cout<<(flag?"YES":"NO")<<endl;
#define joker(v) for(auto x:v)cout<<x<<" ";cout<<endl;
#define papiya(mp) for(auto x:mp)cout<<x.first<<" "<<x.second<<endl;
#define each(it,S) for(auto it = S.begin(); it != S.end(); ++it)
#define lp(i,a) for(int i=0; i<a;i++)
#define lp1(i,a,b) for(int i=(a);i<=(b);++i)
#define rlp(i,b,a) for(int i=(b);i>=(a);--i) 


typedef long long ll;
typedef vector<ll> vl;
typedef pair <ll, ll> pl;
typedef pair <ll, pl> plp;
typedef vector < pl > vpl;
typedef vector <ll, pl > vlpl;
typedef map <string, ll> msl;
typedef map <ll,string> mls;
typedef map <ll, ll> ml;
typedef map <pl, ll> mpl;
typedef map <ll, pl> mlp;
int middle(ll a, ll b, ll c) { if ((a <= b && b <= c) || (c <= b && b <= a)) return b;else if ((b <= a && a <= c) || (c <= a && a <= b))return a;else return c; } 
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

string str,str1,str2,str3,str4,str5,str6,str7;
char ch,ch1,ch2,ch3;
bool flag=true,flag1=true,flag2=true;
long long a,b,c,d,e,f,g,h,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,a1,b1,a2,b2,a3,b3,a4,b4,a5,b5,f1=0,f2=0,cnt=0,cnt1=0,cnt2=0,cnt3=0,cnt4=0,sum=0,sum1=0,sum2=0,sum3=0,ma=0,ma1=0,mi=inf,mi1=inf;

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#define mx 1000005
vector<int>isPrime(mx,-1);
vector<int>Primes;
void seive()
{
	for(int i=2;i<=mx;++i)
	{
		if(isPrime[i]==-1)
		{
			for(int j=i;j<=mx;j+=i)
			{
				if(isPrime[j]==-1)
				{
					isPrime[j]=i;
				}
			}
		}
	}
}

void getFactorization(int n)
{
	while(n!=1)
	{
		Primes.push_back(isPrime[n]);
		n/=(isPrime[n]);
	}
}

int numberOfDivisors(int n)
{
	int sq=sqrt(n);
	int res=1;
	for(int i=0;i<Primes.size() and Primes[i]<=sq;++i)
	{
		if(n%Primes[i]==0)
		{
			int cnt=0;
			while(n%Primes[i]==0)
			{
				n/=Primes[i];
				cnt++;
			}
			sq=sqrt(n);
			cnt++;
			res*=cnt;
		}
	}
	if(n!=1)res*=2;
	return res;
}
int main()
{
	Loser
	seive();
	cin>>a>>b>>c;
	lp1(i,1,a)
	{
		lp1(j,1,b)
		{
			lp1(k,1,c)
			{
				p=((i%mod)*(j%mod)*(k%mod))%mod;
				getFactorization(p);
				sum=((sum%mod)+(numberOfDivisors(p)%mod))%mod;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
