# Coin Change

### Minimizing Coin

>Your task is to produce a sum of money x using the available coins in such a way that **the number of coins** is minimal.
>For example, if the coins are {1,5,7} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.

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

>Your task is to calculate the number of distinct ordered ways you can produce a money sum x using the available coins.
>For example, if the coins are {2,3,5} and the desired sum is 9, there are 3 ways: (2+2+5) ,(3+3+3) ,(2+2+2+3)

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

>Your task is to calculate the number of distinct ways you can produce a money sum x using the available coins.
>For example, if the coins are {2,3,5} and the desired sum is 9, there are 8 ways:
>(2+2+5),(2+5+2),(5+2+2),(3+3+3),(2+2+2+3),(2+2+3+2),(2+3+2+2),(3+2+2+2)

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
> You are in a book shop which sells n different books. You know the price and number of pages of each book.
> You have decided that the total price of your purchases will be at most x. What is the maximum number of pages you can buy? You can buy each book at most once.

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
> Given two string s and t. You need to find the longest common subsequence bt them
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
  
  
