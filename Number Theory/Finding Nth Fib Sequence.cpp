//https://www.hackerrank.com/challenges/fibonacci-finding-easy/problem
#include<bits/stdc++.h>
///ordered set
//#include <ext/pb_ds/assoc_container.hpp>
/// Constants
#define INF				    1000000007
#define PI                  acos(-1.0)  // 3.1415926535897932
#define Case(J) printf("Case %lld: %lld\n",++cnt,J); ///print case
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
#define check           cout<<"Avenger's Assemble"<<endl;
#define	lol 			cout<<'\n';
#define meem cout<<(flag?"YES":"NO")<<endl;
#define joker(v) for(auto x:v)cout<<x<<" ";cout<<endl;
#define papiya(mp) for(auto x:mp)cout<<x.first<<" "<<x.second<<endl;
       
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int middle(int a, int b, int c) { if ((a <= b && b <= c) || (c <= b && b <= a)) return b;else if ((b <= a && a <= c) || (c <= a && a <= b))return a;else return c; } 

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
}ll nCr(ll n,ll k)
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
/*------------------------------------------------------------------------------------------------------------------------------------------------------*/
ll fib[3],I[3][3],T[3][3];

void matmul(ll a[3][3],ll b[3][3],ll dim)
{
	ll res[dim+1][dim+1];
	for(int i=0;i<dim;++i)
	{
		for(int j=0;j<dim;++j)
		{
			res[i][j]=0;
			for(int k=0;k<dim;++k)
			{
				res[i][j]=(res[i][j]+a[i][k]*b[k][j])%INF;
			}
		}
	}
	for(int i=0;i<dim;++i)
	{
		for(int j=0;j<dim;++j)
		{
			a[i][j]=res[i][j];
		}
	}
}

void nthfib(ll x,ll y,ll z)
{
	I[0][0]=I[1][1]=1;I[0][1]=I[1][0]=0;
	T[0][0]=0;T[0][1]=T[1][0]=T[1][1]=1;
	while(z)
	{
		if(z&1)matmul(I,T,2);
		matmul(T,T,2);
		z>>=1;
	}
	fib[2]=(x*I[0][0]+y*I[0][1])%INF;
	cout<<fib[2]<<endl;
}
int main()
{
	Loser
	ll t,n;cin>>t;
	while(t--)
	{
		cin>>fib[0]>>fib[1]>>n;
		if(n<2) cout<<fib[n]<<endl;
		else nthfib(fib[0],fib[1],n);
	}
	return 0;
}
