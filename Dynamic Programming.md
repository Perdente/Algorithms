# Basic

<details>
<summary>Problems</summary>
  
<ul>
  <details>
  <summary>Filling Shapes</summary>
  <ul>
       You have a given integer $n$. Find the number of ways to fill all $3×n$ tiles with the shape described in the picture below. Upon filling, no empty spaces are allowed.          Shapes cannot overlap.
       <a href="https://ibb.co/SVNqwJp"><img src="https://i.ibb.co/ZcdyzNC/b83f3a7f74be29b2f62f8e51f6126ffd20d9757c.png" alt="b83f3a7f74be29b2f62f8e51f6126ffd20d9757c" border="0"></a>
    
    
>Here, the tiles dimentions can be $1×2$ or $2×1$. If we put two tiles of different type only then $3$ row can fully filled with the shaped tiles with $2$ column.So there is no gaps between them. So, our $f[i]$ is dependent upon $f[i-2]$ value, hence dp is used.
    
> State: $f[i] =$ no of ways to fill $ith$ row ,
    
> Base case: $f[0]=1$ (as if row is $0$ there is always a way), 
    $f[1]=0$.
    
> Recurrence: $$   f[n] = 2* f[n-2]  $$
    
```c++
int n;cin>>n;
int f[n+1];
f[0]=1;
f[1]=0;
for(int i=2;i<=n;++i)
{
    f[i]=2*f[i-2];
}
cout<<f[n]<<endl;
```   

</ul>
</details>

<ul>
<details>
<summary>Frog Jump</summary>
<ul>
     There are $N$ stones, numbered $1,2,…,N$. For each $i$ $(1≤i≤N)$, the height of Stone $i$ is $h_i$ .There is a frog who is initially on Stone $1$. He will repeat the following action some number of times to reach Stone $N$:
  
- If the frog is currently on Stone $i$, jump to one of the following: Stone $i+1,i+2,…,i+K$. Here, a cost of $|h_i-h_j|$ is incurred, where $j$ is the stone to land on.

Find the minimum possible total cost incurred before the frog reaches Stone $N$.

Note: similar problem: [ Bouncing Ball](https://codeforces.com/contest/1415/submission/131650801) 
    
```c++
int n,k;cin>>n>>k;
vector<ll>a(n),dp(n,inf);
for(int i=0;i<n;++i)cin>>a[i];
dp[0]=0;
for(int i=0;i<n;++i)
{
  for(int j=i+1;j<=i+k;++j)
  {
    if(j<n) dp[j]=min(dp[j],dp[i]+abs(a[i]-a[j]));
  }
}
cout<<dp[n-1]<<endl;
```   

</ul>
</details>
    

  <ul>
<details>
  <summary>Jump Games</summary>
<ul>
     You are given an integer array $nums$. You are initially positioned at the array's $1$st index, and each element in the array represents your maximum jump length at that position.Return true if you can reach the last index, or false otherwise.Also count the minimum jumps.
  
```
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
```
  
```c++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1){
            return true;
        }
        pair<int,int>interval{0,0}; //here interval{min_distance,max_distance}
        int jumps=0;
        while(true){
            jumps++;
            int can_reach=-1;
            for(int i=interval.first;i<=interval.second;++i){
                can_reach=max(can_reach,i+nums[i]);            
            }
            
            if(can_reach>=n-1){
                cout<<jumps<<endl;
                return true;
            }
            
            interval={interval.second+1,can_reach};
            if(interval.first>interval.second){ //means the jumps can never be enough
                cout<<jumps<<endl;
                return false;
            }
        }
        assert(false); //I don't know why I use it but fear to delete it😂
    }
};
```   

</ul>
</details>  
  
<ul>
<details>
<summary>Vacation </summary>
<ul>
     The vacation consists of $N$ days. For each $i$ $(1≤i≤N)$, Taro will choose one of the following activities and do it on the $i-th$ day:

- A: Swim in the sea. Gain $a_i$ points of happiness.
- B: Catch bugs in the mountains. Gain $b_i$ points of happiness.
- C: Do homework at home. Gain $c_i$ points of happiness.

As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.

Find the maximum possible total points of happiness that Taro gains.
  
Note: similar problem: [ Pokémon Army (easy version)](https://codeforces.com/contest/1420/submission/131606583) , [ Best Time to Buy and Sell Stock II](https://leetcode.com/submissions/detail/569909708/), [ Basketball Exercise](https://codeforces.com/contest/1195/submission/131671341)
    
```c++
int n;cin>>n;
vector<int> a(n),b(n),c(n);
for(int i=0;i<n;++i)cin>>a[i]>>b[i]>>c[i];
vector<int> dp(3);
for(int i=0;i<n;++i){
    vector<int> temp(3);
    temp[0]=a[i]+ max(dp[1],dp[2]);
    temp[1]=b[i]+ max(dp[0],dp[2]);
    temp[2]=c[i]+ max(dp[0],dp[1]);
    dp=temp;
}
cout<<*max_element(dp.begin(), dp.end())<<'\n';
```   

</ul>
</details>
      
  <ul>
<details>
  <summary>Broken keyboard </summary>
<ul>
     Recently, Norge found a string $s=s_1s_2…s_n$ consisting of $n$ lowercase Latin letters. As an exercise to improve his typing speed, he decided to type all substrings of the string $s$.Norge realized that his keyboard was broken, namely, he could use only $k$ Latin letters $c_1,c_2,…,c_k$ out of $26$.
    
  > state: $dp[i]$ = num of substrings ending at index $i$
  
```c++
int n,m;cin>>n>>m;
string s;cin>>s;
vector<int> can(26);
while(m--){
    char ch;cin>>ch;
    can[ch-'a']=1;
}
int sum=0;
vector<int> dp(n+1);
for(int i=0;i<n;++i){
    if(can[s[i]-'a']){
        dp[i+1]=dp[i]+1;
    }
    sum+=dp[i+1];
}
cout<<sum<<endl;
```   

</ul>
</details>
  
  
  <ul>
<details>
  <summary>Boredom </summary>
<ul>
     Given a sequence $a$ consisting of $n$ integers. The player can make several steps. In a single step he can choose an element of the sequence (let's denote it $a_k$) and delete it, at that all elements equal to $a_k + 1$ and $a_k - 1$ also must be deleted from the sequence. That step brings $a_k$ points to the player.
  
  Similar problem:[House Robber](https://leetcode.com/submissions/detail/572701091/),[House Robber 2](https://leetcode.com/problems/house-robber-ii/submissions/)
  
  > State: $dp[i] = $ maximum points gained by the total frequency of $i$ th element
  
  > Recurrence :  $$ dp[i]=max(dp[i+1],dp[i]+dp[i+2]); $$
  
```c++
int n,x,ma=0;cin>>n;
map<int,int>dp;
for(int i=0;i<n;++i){
    cin>>x;
    dp[x]+=x;
    ma=max(ma,x);
}
for(int i=ma+2;i>=1;--i){
    dp[i]=max(dp[i+1],dp[i]+dp[i+2]);
}
cout<<dp[1]<<endl;

```   

</ul>
</details>
   
</ul>
</details>


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
  
# Longest Increasing Subsequence
  
  > You are given an array containing $n$ integers. Your task is to determine the longest increasing subsequence in the array, i.e., the longest subsequence where every element is larger than the previous one. eg. $[7, 3, 5, 3, 6, 2, 9, 8]$  ans is $4$ ; indices ${1,2,4,6}$
  
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

<details>
<summary>Variants</summary>
<ul>
<details>
<summary>Orac and Models </summary>
<ul>
Given an array of $n$ elements. Here we need to find the longest increasing subsequence for the indices which were divisible by each other. $i$ and $j$ index must be divisible 

$[1,4,2 ,3, 6, 4, 9]$
Here the indices ${1,3,6}$ has increasing subsequence hence ans is $3$

<details>
<summary>code</summary>
<ul>
                                    
```c++

const int N=1e5+10;

vector<int> divi[N],dp(N),v(N);

for(int i=1;i<N;++i){
  for(int j=i*2;j<N;j+=i){
      divi[i].push_back(j);
  }
}
int main(){
  int n;cin>>n;
  for(int i=1;i<=n;++i){
    cin>>v[i];
  }
  for(int i=1;i<=n;++i) dp[i]=1;// there is always length 1 subsequences exists 
  for(int i=1;i<=n;++i){
    for(auto j:divi[i]){
        if(v[i]<v[j]) dp[j]=max(dp[j],dp[i]+1);
    }
  }
  cout<<*max_element(dp.begin()+1, dp.begin()+n+1)<<endl;
}
                                                       
                                                       
```
                                                                                           
                                                                                           
</ul>
</details>
  
</ul>
</details>

</ul>
</details>

</ul>
</details>


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

# Grid DP
> Given a $m$ x $n$ grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
  
<a href="https://imgbb.com/"><img src="https://i.ibb.co/kHZXqcz/minpath.jpg" alt="minpath" border="0"></a>
<details>
<summary>Code</summary>
<ul>
  
```c++
int minPathSum(vector<vector<int>>& grid) {
    const int inf=1e9;
    int H=grid.size();
    int W=grid[0].size();
    vector<vector<int>>dp(H,vector<int>(W));
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j){
            if(i==0 and j==0){
                dp[i][j]=grid[i][j];
                continue;
            }
            dp[i][j] = grid[i][j] + min((i==0? inf:dp[i-1][j]) ,(j==0? inf:dp[i][j-1]) );
        }
    }
    return dp[H-1][W-1];
}
```
</ul>
</details>

> Consider an $n$×$m$ grid whose squares may have traps $$#$$.Your task is to calculate the number of paths from the upper-left square to the lower-right square. You can only move right or down.
<details>
<summary>Code</summary>
<ul>
  
```c++
int n,m;cin>>n>>m;
vector<vector<int>> dp(n,vector<int>(m));
vector<string> a(n);
for(int i=0;i<n;++i){
    cin>>a[i];
}
if(a[0][0]=='#')return cout<<0<<endl,0;
dp[0][0]=1;
for(int i=0;i<n;++i){
    for(int j=0;j<m;++j){
        if(a[i][j]=='.'){
            if(i>0 and a[i-1][j]=='.'){
                dp[i][j]+=dp[i-1][j];
            }
            if(j>0 and a[i][j-1]=='.'){
                dp[i][j]+=dp[i][j-1];
            }
            dp[i][j]%=mod;
        }
    }
}
cout<<dp[n-1][m-1]<<endl;
```
</ul>
</details>
  
> Given an $m$ x $n$ integers matrix, return the length of the longest increasing path in matrix.From each cell, you can either move in four directions: left, right, up, or down.You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
  
  <a href="https://imgbb.com/"><img src="https://i.ibb.co/gtB3JRS/grid1.jpg" alt="grid1" border="0"></a>

  <details>
<summary>Code</summary>
<ul>
  
```c++

int longestIncreasingPath(vector<vector<int>>& matrix) {
int r=matrix.size();
int c=matrix[0].size();
vector<vector<int>>mat(r,vector<int>(c,1));
vector<vector<int>>dp(r,vector<int>(c));
auto inside=[&](int x,int y){
    return 0<=x and x<r and 0<=y and y<c;
};

function<int(int,int)>solve=[&](int si,int sj)->int{
    int ans=1;
    if(dp[si][sj]) return dp[si][sj];
    vector<pair<int,int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
    for(pair<int,int>dir:directions){
        int ni=si+dir.first;
        int nj=sj+dir.second;
        if(inside(ni,nj) and matrix[ni][nj]>matrix[si][sj]){
            ans=max(ans,1+solve(ni,nj));
        }
    }
    return dp[si][sj]=ans;
};
int ans=0;
for(int i=0;i<r;++i){
    for(int j=0;j<c;++j){
        ans=max(ans,solve(i,j));
    }
}
return ans;
}
  ```
</ul>
</details>

 
  
  
 # Bitmask DP
  
  > Add, remove and display the bits using bitmasking.
  
  <details>
<summary>Code</summary>
<ul>

```c++
int n;cin>>n;

auto add=[&](int x){
// Here, if the bit is not present then add.
  if(!(n & (1<<x))) n^=(1<<x);
};

auto remove=[&](int x){
  // Here, if the bit is already present then remove.
  if(n & (1<<x)) n^=(1<<x);
};
auto display=[&](){
  for(int mask=0;mask<=31;++mask){ // an integer consists of 32 bits
      if(n & (1<<mask)){                2^31 .... 16 8 4 2 1
          cout<<mask<<" ";   // n ->              0  0 1 1 0    
                           //(2^1)                0  0 0 1 0    //1st bit is SET
                           //(2^3)                0  1 0 0 0    //3rd bit is not SET     
      }
  }
};
remove(2);
add(3);
remove(7);
add(3);
display();
```
  
</ul>
</details>
