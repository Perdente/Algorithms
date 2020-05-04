//dfs traversal
//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/
#include<bits/stdc++.h>
#define INF				    1e9+7
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
#define meem cout<<(flag?"YES":"NO")<<endl;
#define joker(v) for(auto x:v)cout<<x<<" ";cout<<endl;
#define papiya(mp) for(auto x:mp)cout<<x.first<<" "<<x.second<<endl;
///==========DEBUGGING=============///
#define	debug(a) 		cout<<"*"<<a<<endl;
#define	debug2(a,b) 	cout<<"$"<<a<<" "<<b<<endl;
#define	debug3(a,b,c) 	cout<<"$"<<a<<" "<<b<<" "<<c<<endl;
#define check           cout<<"Avenger's Assemble"<<endl;
#define	lol 			cout<<'\n';
       
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
#define mx 1005
vector<int>graph[mx];
int mi=INF;
int visited[mx]={0},dis[mx]={0};

void dfs(int snode)
{
	visited[snode]=1;
	for(int i=0;i<graph[snode].size();++i)
	{
		if(visited[graph[snode][i]]==0)
		{
			dis[graph[snode][i]]=dis[snode]+1;
			dfs(graph[snode][i]);
		}
	}
}
int main()
{
	Loser
	int n,x,y;cin>>n;
	for(int i=0;i<n-1;++i)
	{
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs(1);
	int q;
	cin>>q;
	vector<pair<int,int>>v;
	while(q--)
	{
		cin>>x;
		v.pb(MP(dis[x],x));
	}
	srt(v);
	cout<<v[0].second<<endl;
	return 0;
}

