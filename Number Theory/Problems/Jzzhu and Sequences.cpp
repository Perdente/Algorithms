//https://codeforces.com/problemset/problem/450/B
//Finding nth recurrance relation using matrix exponentiation .
//O(log(n))
//Transition matrix->
//|0 -1|
//|1  1|
//Equation -> f(n)=f(n-1)-f(n-2);
//f(n) = f(n-1)*T[0][0]+f(n-2)*T[1][0]
#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
const long long mx  = 1e5+5;

#define inf 			INT_MAX
#define zero 			INT_MIN
#define PI   			acos(-1.0)  // 3.1415926535897932
#define Case(J) 		printf("Case %lld: %lld\n",++count,J); ///print case
#define Loser 			ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define max3(a,b,c) 	max(a,max(b,c))
#define min3(a,b,c) 	min(a,min(b,c))
#define GCD(a,b) 		__gcd(a,b)
#define LCM(a,b) 		(a*(b/__gcd(a,b) ))
#define MP 				make_pair
#define pb 				push_back
#define ppb 			pop_back
#define pf 				push_front
#define ppf 			pop_front
#define rev(v) 			reverse(v.begin(),v.end());
#define srt(v) 			sort(v.begin(),v.end());
#define grtsrt(v) 		sort(v.begin(),v.end(),greater<ll>());
#define hellyeah 		exit(0);
#define file 			freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define vmax(v) 		*max_element(v.begin(),v.end());
#define vmin(v) 		*min_element(v.begin(),v.end());
#define	debug(a) 		cout<<"*"<<a<<endl;
#define	debug2(a,b) 	cout<<"$"<<a<<" "<<b<<endl;
#define	debug3(a,b,c) 	cout<<"$"<<a<<" "<<b<<" "<<c<<endl;
#define SET(X,D_type)	memset(X, D_type, sizeof(X))
#define SET2d(x,m,n) 	memset(x, 0, sizeof(x[0][0]) * m * n)
#define groot(A)		return cout<<A<<endl,0
#define vins(V)			srt(V)V.resize(unique(V.begin(),V.end())-V.begin());
#define check           cout<<"Avenger's Assemble"<<endl;
#define	lol 			cout<<'\n';
#define meem(x) 		cout<<(x?"YES":"NO")<<endl;
#define joker(v) 		for(auto x:v)cout<<x<<" ";cout<<endl;
#define papiya(mp) 		for(auto x:mp)cout<<x.first<<" "<<x.second<<endl;
#define each(it,S) 		for(auto it = S.begin(); it != S.end(); ++it)
#define lp(i,a) 		for(int i=0; i<a;i++)
#define lp1(i,a,b) 		for(int i=(a);i<=(b);++i)
#define rlp(i,b,a) 		for(int i=(b);i>=(a);--i) 

typedef long long ll;
typedef vector<ll> vl;
typedef pair <ll, ll> pl;
typedef pair <ll, pl> plp;
typedef vector < pl > vpl;
typedef vector <pair<ll, pl >>vlpl;
typedef vector < string > vs;
typedef map <string, ll> msl;
typedef map <ll,string> mls;
typedef map <ll, ll> ml;
typedef map <pl, ll> mpl;
typedef map <ll, pl> mlp;
typedef deque <ll, ll> dq;

long long middle(ll a, ll b, ll c) { if ((a <= b && b <= c) || (c <= b && b <= a)) return b;else if ((b <= a && a <= c) || (c <= a && a <= b))return a;else return c; } 
bool ispalindrom(string s) {transform(s.begin(),s.end(),s.begin(),::tolower);return (s[0]==s[s.size()-1]?1:0);}
//sort(v.begin(),v.end(),as_second);
bool as_second(const pair<ll,ll> &a, const pair<ll,ll> &b) {return (a.second < b.second); }//sort the vector pair in assending order according to second element
bool ds_first(const pair<ll,ll> &a, const pair<ll,ll> &b){ return (a.first > b.first);}//sort the vector pair in decending order according to first element
bool ds_second(const pair<ll,ll> &a, const pair<ll,ll> &b) {return a.second>b.second;}//sort the vector pair in decending order according to second element

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

string str,str1,str2,str3,str4,str5,str6,str7;
char ch,ch1,ch2,ch3;
bool flag=true,flag1=true,flag2=true;
long long a,b,c,d,e,f,g,h,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,a1,b1,a2,b2,a3,b3,a4,b4,a5,b5,f1=0,f2=0,cnt=0,cnt1=0,cnt2=0,cnt3=0,cnt4=0,sum=0,sum1=0,sum2=0,sum3=0,ma=0,ma1=0,mi=inf,mi1=inf;

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

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
				res[i][j]=(res[i][j]+a[i][k]*b[k][j])%mod;
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

void nthrec(ll x,ll y,ll z)
{
	I[0][0]=I[1][1]=1;I[0][1]=I[1][0]=0;
	T[0][0]=0,T[0][1]=-1,T[1][1]=T[1][0]=1;
	while(z)
	{
		if(z&1)matmul(I,T,2);
		matmul(T,T,2);
		z>>=1;
	}
	fib[2]=(x*I[0][0]+y*I[1][0])%mod;
	cout<<(fib[2]+mod)%mod<<endl;
}
int main()
{
	Loser
	
	cin>>fib[0]>>fib[1]>>n;
	if(n-1<2) cout<<(fib[n-1]+mod)%mod<<endl;
	else nthrec(fib[0],fib[1],n-1);

	return 0;
}
