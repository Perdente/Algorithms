# Coin Change

### Minimizing Coin

>Your task is to produce a sum of money $x$ using the available coins in such a way that _the number of coins_ is minimal.
>For example, if the coins are {$1,5,7$} and the desired sum is $11$, an optimal solution is $5+5+1$ which requires $3$ coins.

<details>
<summary>Code</summary>
<ul>
  
```c++
int n,sum;cin>>n>>sum;
vector<int> vec(n);
for(int &i:vec)cin>>i;
vector<int> dp(sum+1,1e9);
dp[0]=0;
for(int i=1;i<=sum;++i){
    for(int j:vec){
        if(i-j>=0){
            dp[i]=min(dp[i],1+dp[i-j]);
        }
    }
}
cout<<(dp[sum]==1e9?-1:dp[sum])<<'\n';
```
</ul>
</details>
<br/>
  
### Ordered Way Sum

>Your task is to calculate the number of _distinct ordered ways_ you can produce a money sum $x$ using the available coins.
>For example, if the coins are {$2,3,5$} and the desired sum is $9$, there are $3$ ways: ($2+2+5$) ,($3+3+3$) ,($2+2+2+3$)

<details>
<summary>Code</summary>
<ul>
  
```c++
int n,sum;cin>>n>>sum;
vector<int> vec(n);
for(int &i:vec)cin>>i;
vector<int> dp(sum+1);
dp[0]=1;
for(auto j:vec){
    for(int i=1;i<=sum;++i){
        if(i-j>=0)dp[i]=(dp[i]+dp[i-j])%mod;
    }
}
cout<<dp[sum]<<'\n';  
```
  
```c++
/*
  dp[i,x]=valid ways to make sum x using vec[0],vec[1],vec[2],...,vec[i]
  Base case:  dp[i][0]=1; 0 <= i < n
  Recurrence: dp[i][x]=dp[i-1][x] + dp[i][x-vec[i]]
*/
int n,sum;cin>>n>>sum;
vector<int> vec(n+1);
for(int i=1;i<=n;++i)cin>>vec[i];
vector<vector<int>> dp(n+1,vector<int>(sum+1));
for(int i=1;i<=n;++i)dp[i][0]=1;
for(int i=1;i<=n;++i){
    for(int x=1;x<=sum;++x){
        dp[i][x]= dp[i-1][x] + (x-vec[i]>=0? dp[i][x-vec[i]] : 0);
        dp[i][x]%=mod;
    }
}
cout<<dp[n][sum]<<'\n';
```  
</ul>
</details>
<br/>

### Ordered & Unordered Way Sum

>Your task is to calculate the number of distinct ways you can produce a money sum $x$ using the available coins.
>For example, if the coins are {$2,3,5$} and the desired sum is $9$, there are $8$ ways:
>($2+2+5$),($2+5+2$),($5+2+2$),($3+3+3$),($2+2+2+3$),($2+2+3+2$),($2+3+2+2$),($3+2+2+2$)

<details>
<summary>Code</summary>
<ul>
  
```c++
int n,sum;cin>>n>>sum;
vector<int> vec(n);
for(int &i:vec)cin>>i;
vector<int> dp(sum+1);
dp[0]=1;
for(int i=1;i<=sum;++i){
    for(auto j:vec){       
        if(i-j>=0)dp[i]=(dp[i]+dp[i-j])%mod;
    }
}
cout<<dp[sum]<<'\n'; 
```
</ul>
</details>
<br/>
  
# Knapsack
> You are in a book shop which sells $n$ different books. You know the price and number of pages of each book.
> You have decided that the total price of your purchases will be at most $x$. What is the maximum number of pages you can buy? You can buy each book at most once.

<details>
<summary>Code</summary>
<ul>
  
```c++
int n,tot;cin>>n>>tot;
for(int i=1;i<=n;++i)cin>>cost[i];
for(int i=1;i<=n;++i)cin>>pg[i];

for(int i=1;i<=n;++i)
{
  for(int j=1;j<=tot;++j)
  {
    dp[i][j]=max(dp[i-1][j],(j-cost[i]>=0)?pg[i]+dp[i-1][j-cost[i]]:0);
  }
}
cout<<dp[n][tot]<<endl;
```
</ul>
</details>
<br/>
  
# Longest Common Subsequence
> Given two string $s$ and $t$. You need to find the longest common subsequence between them
<details>
<summary>Code</summary>
<ul>
  
```c++

int LCS[N][N];
void lcs_len(string s,string t,int n,int m){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(s[i-1]==t[j-1]){
                LCS[i][j]=LCS[i-1][j-1]+1;
            }else{
                LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
            }
        }
    }
}
set<string> print_all(string s,string t,int n,int m){
    set<string> st;
    if(n==0 or m==0){
        st.insert("");
        return st;
    }
    if(s[n-1] == t[m-1]){
        set<string> temp= print_all(s,t,n-1,m-1);
        for(string str:temp) st.insert(str+s[n-1]);
    }else{
        if(LCS[n-1][m]>=LCS[n][m-1]){
            st=print_all(s,t,n-1,m);
        }
        if(LCS[n][m-1]>=LCS[n-1][m]){
            set<string> temp=print_all(s,t,n,m-1);
            st.insert(temp.begin(), temp.end());
        }
    }
    return st;
}
string lcs_str(string s,string t,int n,int m){
    if(n==0 or m==0) return string("");
    if(s[n-1]==t[m-1]) return lcs_str(s,t,n-1,m-1) + s[n-1];
    if(LCS[n-1][m]>LCS[n][m-1]) return lcs_str(s,t,n-1,m);
    return lcs_str(s,t,n,m-1);
}
string s,t;cin>>s>>t;
int n=s.size(),m=t.size();
lcs_len(s,t,n,m);
cout<<lcs_str(s,t,n,m)<<endl;
```
</ul>
</details>
<br/>  
  
# Longest Increasing Subsequence
 $\mathcal{O}(n^2)$
<details>
<summary>Code</summary>
<ul>
  
```c++
int n;cin>>n;
vector<int> v(n);
for(int i=0;i<n;++i){
    cin>>v[i];
}
vector<int> dp(n,1);
for(int i=0;i<n;++i){
    for(int j=0;j<i;++j){
        if(v[j]<v[i]) dp[i] = max(dp[i], dp[j]+1);
    }
}
int ans=INT_MIN;
for(auto i:dp)ans=max(ans,i);
cout<<ans<<'\n';
```
</ul>
</details>
<br/>

 $\mathcal{O}(nlogn)$
<details>
<summary>Code</summary>
<ul>
  
```c++
int n;cin>>n;
vector<int> v(n);
for(int i=0;i<n;++i){
    cin>>v[i];
}
auto LIS=[&](vector<int> v)->int{
    multiset<int> st;
    for(auto i:v){
        st.insert(i);
        auto it=st.upper_bound(i);
        if(it!=st.end()) st.erase(it);
    }
    return (int)st.size();
};
//Strictly longest increasing subsequence
auto Strictly_LIS=[&](vector<int> v)->int{
    multiset<int> st;
    for(auto i:v){
        st.insert(i);
        auto it=st.lower_bound(i);
        it++;
        if(it!=st.end()) st.erase(it);
    }
    return (int)st.size();
};

cout<<Strictly_LIS(v)<<'\n';
```
</ul>
</details>
<br/>

# Edit Distance
>The edit distance between two strings is the minimum number of operations required to transform one string into the other.
>The allowed operations are:
- Add one character to the string.
- Remove one character from the string.
- Replace one character in the string.
>For example, the edit distance between $LOVE$ and $MOVIE$ is $2$, because you can first replace $L$ with $M$, and then add $I$.
<details>
<summary>Code</summary>
<ul>
  
```c++
string s,t;cin>>s>>t;
int n=s.size(),m=t.size();
vector<vector<int>>dp(n+1,vector<int>(m+1,1e9));
dp[0][0]=0;
for(int i=0;i<=n;++i)
{
  for(int j=0;j<=m;++j)
  {
    if(i)  dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
  
    if(j)  dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
  
    if(i and j)   dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(s[i-1]!=t[j-1]));
  }
}
cout<<dp[n][m]<<endl;
```
</ul>
</details>
<br/>


  
  
