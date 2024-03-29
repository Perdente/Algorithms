# Miscellaneous

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

Note: similar problem: [ Bouncing Ball](https://codeforces.com/contest/1415/submission/131650801), [Long jump](https://codeforces.com/contest/1472/submission/132667659) 
    
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
```c++
const int N = 1e6 + 5, oo = 1e9;
int dp[N][3];
int activ[N][3];

int fun(int n, int prev) {
    if(n == 0) return 0;
    if (dp[n][prev] != -1) return dp[n][prev];
    int total = 0;
    if (prev != 0) {
        total = max (total, activ[n][0] + fun(n - 1, 0));
    }
    if (prev != 1) {
        total = max (total, activ[n][1] + fun(n - 1, 1));
    }
    if (prev != 2) {
        total = max (total, activ[n][2] + fun(n - 1, 2));
    }
    return dp[n][prev] = total;
}

void malena() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> activ[i][0] >> activ[i][1] >> activ[i][2];
    }
    memset(dp, -1, sizeof dp);
    cout << fun(n, 3) << '\n';
}
```	

</ul>
</details>

  <ul>
<details>
<summary>Allocate Mailboxes </summary>
<ul>
     Given the array houses and an integer $k$. where $houses[i]$ is the location of the $i$th house along a street, your task is to allocate $k$ mailboxes in the street.

Return the minimum total distance between each house and its nearest mailbox.
  
  <a href="https://imgbb.com/"><img src="https://i.ibb.co/DM5frMR/sample-11-1816.png" alt="sample-11-1816" border="0"></a>
  ```
Input: houses = [1,4,8,10,20], k = 3
Output: 5
Explanation: Allocate mailboxes in position 3, 9 and 20.
Minimum total distance from each houses to nearest mailboxes is |3-1| + |4-3| + |9-8| + |10-9| + |20-20| = 5 

  ```
  
    
```c++
const static int N=101;
int cost[N][N],dp[N][N];

int ok(vector<int>& houses , int k , int i){
    int n=houses.size();
    if(k==0 and i==n) return 0;
    if(k==0 or i==n) return 1e9;
    if(dp[k][i]!=-1) return dp[k][i];
    int ans=1e9;
    for(int j=i;j<n;j++){
        ans=min(ans,cost[i][j]+ok(houses,k-1,j+1));
    }
    return dp[k][i]=ans;
}

int minDistance(vector<int>& houses, int k) {
    sort(houses.begin(),houses.end());
    int n=houses.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int x=i;x<=j;x++){
                cost[i][j]+=abs(houses[(i+j)/2]-houses[x]);// min dist would be total abs dist from median house to all other houses in the branch
            }
        }
    }
    memset(dp,-1,sizeof(dp));
    return ok(houses,k,0);
}
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
     Given a sequence $a$ consisting of $n$ integers. The player can make several steps. In a single step he can choose an element of the sequence (let's denote it $a_k$) and delete it, at that all elements equal to $a_k + 1$ and $a_k - 1$ also must be deleted from the sequence. That step brings $a_k$ points to the player. Print a single integer — the maximum number of points that Alex can earn.
  
  Similar problem:[House Robber](https://leetcode.com/submissions/detail/572701091/),[House Robber 2](https://leetcode.com/problems/house-robber-ii/submissions/), [House Robber 3 (trees)](https://leetcode.com/problems/house-robber-iii/)
  
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


<ul>
<details>
  <summary>Unique Binary Search Trees </summary>
<ul>
     Given an integer $n$, return the number of structurally unique _BST_ (binary search trees) which has exactly $n$ nodes of unique values from $1$ to $n$.
	
![](https://assets.leetcode.com/uploads/2021/01/18/uniquebstn3.jpg)

> Explanation: Here, for each $i$ th root we compute how many children it has in _left_ subtree and _right_ subtree. if $n = 4$ and $i = 3$ then it has $3 - 1$ children in left and $4-i$ in right subtree and multiply them And we sum them up untill $n$.

  > State: $dp[i] = $ total unique binary trees for root $i$
  
  > Recurrence :  $$ dp[i] = \sum dp[j-1] * dp[i - j] $$
  
```c++
class Solution {
public:
    int numTrees(int n) {
        
        /*
         numTrees(4) = numTrees(0) * numTrees(3) + numTrees(1) * numTrees(2) + numTrees(2) * numTrees(1) + numTrees(3) * numTrees(0). 
        */
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
```   

</ul>
</details>

</ul>
</details>

# Fibonacy Numbers 
> The Fibonacci sequence is a series of numbers in which each number is the sum of the two that precede it. Starting at $0$ and $1$, the sequence looks like this: $0, 1, 1, 2, 3, 5, 8, 13, 21, 34,$ and so on forever....

<details>
<summary>Recursive</summary>
<ul>
    
```c++
const int N = 1e5 + 5;
int F[N];

int fibonacy(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (F[n] != -1) return F[n];
    F[n] = fibonacy(n - 1) + fibonacy(n - 2);
    return F[n];
}
    
int n; cin >> n;
memset(F, -1, sizeof F);
cout << fibonacy(n) << '\n';    

```

</ul>
</details>

<details>
<summary>Iterative</summary>
<ul>
    
```c++
const int N = 1e5 + 5;
int F[N];
    
int n; cin >> n;
F[0] = 0, F[1] = 1;
for (int i = 2; i <= n; ++i) {
    F[i] = F[i - 1] + F[i - 2];
}
cout << F[n] << '\n';
```

</ul>
</details>	

# Dice Combination (CSES)
> Your task is to count the number of ways to construct sum $n$ by throwing a dice one or more times. Each throw produces an outcome between $1$ and $6$.

<details>
<summary>recursive</summary>
<ul>
  
```c++
const int N = 1e6 + 5, mod = 1e9 + 7;
int dp[N];
 
// dp[i] - how many ways to show i as a sum of {1, 2, 3, 4, 5, 6}
// fun(n) = {1 + fun(n - 1)} + {2 + fun(n - 2)} + {3 + fun(n - 3)} + ....
 
/*
3 -> 1 + fun(2) // 2
  -> 2 + fun(1) // 1
  -> 3 + fun(0) // fun(0) is 1 otherwise this step won't return any value
*/
 
int fun(int n) {
    if (n == 0) return 1;
    if (dp[n] != -1) return dp[n];
    int sum = 0;
    for (int i = 1; i <= 6; ++i) {
        if (n - i >= 0) {
            sum += fun(n - i);
            sum %= mod;
        }
    }
    return dp[n] = sum;
}
 
void malena() {
    int n; cin >> n;
    memset(dp, -1, sizeof dp);
    cout << fun(n) << '\n';
}
```
</ul>
</details>
    
<details>
<summary>iterative</summary>
<ul>
  
```c++
int sum;cin>>sum;
vector<int> dice(6);
iota(dice.begin(), dice.end(),1);
vector<int> dp(sum+1);
dp[0]=1;
for(int i=1;i<=sum;++i){
    for(int j:dice){
        if(i-j>=0){
            dp[i]+=dp[i-j];
            dp[i]%=mod;
        }
    }
}
cout<<dp[sum]<<'\n';
```
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
> recursive (with coin print)

```c++
// https://leetcode.com/problems/combination-sum/
const int N = 1e6 + 5, mod = 1e9 + 7;
int n, ans;
int dp[N];
vector<vector<int>> vec;
vector<int> temp;

void rec(int i, int arr[], int sum) {
    if (sum == 0) {
        vec.push_back(temp);
        return;
    }
    if (i == n or sum < 0) return;
    rec(i + 1, arr, sum);
    temp.push_back(arr[i]);
    rec(i, arr, sum - arr[i]);
    temp.pop_back();
}

void malena() {
    cin >> n;
    int sum; cin >> sum;
    int coins[n];
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; ++i) cin >> coins[i];
    rec(0, coins, sum);
    for (auto it: vec) {
        for (auto v: it) cout << v << " ";
        cout << '\n';
    }
}
/*
Input: 
3 9
2 3 5
Output:
3 3 3 
2 2 5 
2 2 2 3 

*/

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

### Make Sum using Fixed coins

>Your task is to calculate the number of distinct ways you can produce a money sum $x$ using the available coins.
>For example, if the coins are {$1,2,5$} and coin $1$ can be used atmost $3$ times similarly coin $2$ upto $2$ and coin $5$ upto $1$ times and the desired sum is $5$, there are $3$ ways:
> $(1, 1, 1, 2), (1, 2, 2), (5)$

<details>
<summary>Code</summary>
<ul>
  
```c++
// https://lightoj.com/problem/coin-change-i
const int N = 55, K = 1e3 + 5, mod = 100000007;
int dp[N][K], coins[N], vals[N];
int n, sum;

int fun(int n, int sum) {
    if (sum == 0) return 1;
    if (n == 0) return 0;
    if (dp[n][sum] != -1) return dp[n][sum];
    int res = 0;
    for (int j = 0; j <= vals[n]; ++j) {
        if (sum - (coins[n] * j) >= 0) {
            res = (res + fun(n - 1, sum - (coins[n] * j))) % mod;
        }
    }
    return dp[n][sum] = res;
}

void malena() {
    cin >> n >> sum;
    for (int i = 1; i <= n; ++i) cin >> coins[i];

    for (int i = 1; i <= n; ++i) cin >> vals[i];

    memset(dp, -1, sizeof dp);
    cout << fun(n, sum) << '\n';
}
```
</ul>
</details>

# Knapsack
> You are in a book shop which sells $n$ different books. You know the price and number of pages of each book.
> You have decided that the total price of your purchases will be at most $x$. What is the maximum number of pages you can buy? You can buy each book at most once.

<details>
<summary>recursive</summary>
<ul>
  
```c++
// https://atcoder.jp/contests/dp/tasks/dp_d
const int N = 1e2 + 5, mx = 1e5 + 5;
int dp[N][mx];
int weight[N], value[N];

int fun(int n, int W) {
    if (n == 0) return 0;
    if (dp[n][W] != -1) return dp[n][W];
    int sum = fun(n - 1, W);
    if(W - weight[n] >= 0) sum = max(sum, fun(n - 1, W - weight[n]) + value[n]);
    return dp[n][W] = sum;
}
int n, W; cin >> n >> W;
for (int i = 1; i <= n; ++i) {
    cin >> weight[i] >> value[i];
}
memset(dp, -1, sizeof dp);
cout << fun(n, W) << '\n';
```
</ul>
</details>
	
<details>
<summary>iterative</summary>
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
<summary>iterative</summary>
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
<details>
<summary>recursive</summary>
<ul>
  
```c++

const int N = 3e3 + 5;
int dp[N][N];
string a, b;
int lcs_length(int i, int j) {
    int n = a.size(), m = b.size();
    if (i == n or j == m) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (a[i] == b[j]) return lcs_length(i + 1, j + 1) + 1;
    int x = 0, y = 0;
    x = lcs_length(i + 1, j);
    y = lcs_length(i, j + 1);
    return dp[i][j] = max(x, y);
}

void print_lcs(int i, int j) {
    int n = a.size(), m = b.size();
    if (i == n or j == m) return;
    if (a[i] == b[j]) {
        cout << a[i];
        print_lcs(i + 1, j + 1);
        return;
    }
    int x = 0, y = 0;
    x = lcs_length(i + 1, j);
    y = lcs_length(i, j + 1);
    if (x >= y) {
        print_lcs(i + 1, j);
    }else {
        print_lcs(i, j + 1);
    }
}

void malena() {
    cin >> a >> b;
    memset(dp, -1, sizeof dp);
    print_lcs(0, 0);
}
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


# Longest Palindromic Subsequence
> Given a string $s$ return longest palindromic subsequence. If string is $ADAM$ answer is $3$ as $ADA$ and $racemyfuckingcar$ answer is $7$ as $racecar$.

<details>
<summary>Code</summary>
<ul>
    
```c++
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
const int N = 1e3 + 5;
int dp[N][N];
string s;
int n;
int lps_len(int i, int j) {
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (s[i] == s[j]) {
        if (i == j) return lps_len(i + 1, j - 1) + 1;
        return lps_len(i + 1, j - 1) + 2;
    }
    int a = 0, b = 0;
    a = lps_len(i + 1, j);
    b = lps_len(i, j - 1);
    return dp[i][j] = max(a, b);
}

void malena() {
    getline(cin, s);
    n = s.size();
    memset(dp, -1, sizeof dp);
    cout << lps_len(0, n - 1) << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, c = 0;
    t = 1;
    cin >> t;
    cin.ignore();
    while (t--) {
        // cout << "Case " << ++c <<": ";
        malena();
    }
    return 0;
}
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
<summary>iterative</summary>
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

<details>
<summary>recursive</summary>
<ul>
  
```c++
const int N = 5005, oo = 1e9;
string s1, s2;
int dp[N][N];
 
int fun(int i, int j) {
    int n = s1.size(), m = s2.size();
    if (dp[i][j] != -1) return dp[i][j];
    if (i == n and j == m) return 0;
    if (i == n) return dp[i][j] = m - j;
    if (j == m) return dp[i][j] = n - i;
    if (s1[i] == s2[j]) return dp[i][j] = fun(i + 1, j + 1);
    int cost = oo;
    cost = min (cost, fun(i + 1, j + 1));
    cost = min(cost, fun(i + 1, j));
    cost = min(cost, fun(i, j + 1));
    return dp[i][j] = 1 + cost;
}
 
void malena() {
    cin >> s1 >> s2;
    memset(dp, -1, sizeof dp);
    cout << fun(0, 0) << '\n';
}
 ```
  
</ul>
</details>

>We have an integer sequence $A$ of length $N$ and an integer sequence $B$ of length $M$.Takahashi will make a new sequence $A'$ by removing some elements (possibly zero or all) from $A$ and concatenating the remaining elements.Similarly, he will make another new sequence $B'$ by removing some elements (possibly zero or all) from $B$ and concatenating the remaining elements.
  
>Here, he will remove elements so that $|A'|=|B'|$ ($∣s∣$ denotes the length of $s$ for a sequence $s$.)Let $x$ be the total number of elements removed from $A$ and $B$, and $y$ be the number of integers $i$ such that $1≤i≤|A'|$ and $A'_i \neq B'_i$ . Find minimum value of $x+y$
 
```
Input:
4 6
1 3 2 4
1 5 2 6 4 3
Output:
3
```
> If we remove nothing from $A$ and remove $B_4$ and $B_6$ from $B$, we have $x=2,y=1$, and $x+y=3$, which is the minimum possible value.
<details>
<summary>Code </summary>
<ul>
 
```c++
const int oo=1e10;
int n,m;cin>>n>>m;
vector<int> v(n),u(m);
for(int i=0;i<n;++i)cin>>v[i];
for(int i=0;i<m;++i)cin>>u[i];
vector<vector<int>> dp(n+1,vector<int>(m+1,oo));
dp[0][0]=0;
for(int i=0;i<=n;++i)
{
  for(int j=0;j<=m;++j)
  {
    if(i)  dp[i][j]=min(dp[i][j],dp[i-1][j]+1);

    if(j)  dp[i][j]=min(dp[i][j],dp[i][j-1]+1);

    if(i and j)   dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(v[i-1]!=u[j-1]));
  }
}
cout<<dp[n][m]<<'\n';
```

</ul>
</details>

# Grid DP
> 1. Given a $m$ x $n$ grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
  
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

> 2. Consider an $n$×$m$ grid whose squares may have traps _#_ .Your task is to calculate the number of paths from the upper-left square to the lower-right square. You can only move right or down.
<details>
<summary>iterative</summary>
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

<details>
<summary>recursive</summary>
<ul>
  
```c++
const int N = 1e3 + 5, mod = 1e9 + 7;
int n, m;
char arr[N][N];
int dp[N][N];

int fun(int i, int j) {
    if (i > n or j > m) return 0;
    if (i == n and j == m) return (arr[i][j] == '.');
    if (dp[i][j] != -1) return dp[i][j];
    int x = 0, y = 0;
    if(i + 1 <= n and arr[i + 1][j] == '.') x = fun(i + 1, j);
    if(j + 1 <= m and arr[i][j + 1] == '.') y = fun(i, j + 1);
    return dp[i][j] = (x + y) % mod;
}

void malena() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> arr[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    cout << fun(1, 1) << '\n';
}
```
</ul>
</details>

> 3. Given an $m$ x $n$ integers matrix, return the length of the longest increasing path in matrix.From each cell, you can either move in four directions: left, right, up, or down.You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
  
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

> 4. Given a matrix $Mat$ with $n$ rows and $m$ columns. Print maximum sum from $Mat[1,1]$ to $Mat[n][m]$ and main challange is $(-10^5 <= A_i <= 10^5)$
 
[ref](https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/X)

<details>
<summary>Code</summary>
<ul>

```c++
const int oo = 1e12;
int n, m; cin >> n >> m;
int a[n + 1][m + 1], dp[n + 1][m + 1];
memset(dp, 0, sizeof dp);
for (int i = 0; i <= n; ++i) dp[i][0] = -oo;
for (int j = 0; j <= m; ++j) dp[0][j] = -oo;

for (int i = 1; i <= n; ++i) {
	for (int j = 1; j <= m; ++j) {
	    cin >> a[i][j];
	    int temp = max(dp[i - 1][j], dp[i][j - 1]);
	    dp[i][j] = a[i][j] + (temp != -oo ? temp : 0);
	}
}
cout << dp[n][m] << '\n';
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
    
    
>_Job Assignment:_ Let there be $N$ workers and $N$ jobs. Any worker can be assigned to perform any job, incurring some cost that may vary depending on the work-job assignment. It is required to perform all jobs by assigning exactly one worker to each job and exactly one job to each agent in such a way that the total cost of the assignment is minimized.Here,$N\leq20$

[source](https://www.youtube.com/watch?v=685x-rzOIlY&list=PLb3g_Z8nEv1icFNrtZqByO1CrWVHLlO5g&index=3)
    
 <a href="https://imgbb.com/"><img src="https://i.ibb.co/3c4PHrR/jobassignment.png" alt="jobassignment" border="0"></a>
    

<details>
<summary>Code</summary>
<ul>

```c++

// dp[i][mask] =  min cost to assign job i to job n and the people available represented by mask
const int N=21;
int cost[N][N],dp[N][(1<<N)];

int solve(int i,int mask,int &n){
    if(i==n) return 0; //if every person is already assigned the job then cost is 0
    if(dp[i][mask]!=-1) return dp[i][mask];

    int ans=INT_MAX;
    // here i=job, j=people, mask=available people at that moment.
    for(int j=0;j<n;++j){
        if( mask & (1<<j) ){ //if the jth person is available at that moment
            ans=min(ans,cost[j][i] + solve(i+1,(mask^(1<<j)),n)); //we'll toggle the jth bit as jth person has already been assigned
        }
    }
    return dp[i][mask]=ans;
}

int n;cin>>n;
for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
        cin>>cost[i][j];
    }
}
memset(dp,-1,sizeof(dp));
cout<<solve(0,(1<<n)-1,n)<<'\n';
```
  
</ul>
</details>

      
>_Travelling Salesman Problem:_ Given a set of cities and distances between every pair of cities, the problem is to find the shortest possible route that visits every city exactly once and returns to the starting point. 

[source 1](https://www.youtube.com/watch?v=QukpHtZMAtM&list=PLb3g_Z8nEv1icFNrtZqByO1CrWVHLlO5g&index=4),[source 2](https://www.youtube.com/watch?v=XaXsJJh-Q5Y)
      
Related problems:
[1)](https://atcoder.jp/contests/abc180/tasks/abc180_e)-->[submission](https://atcoder.jp/contests/abc180/submissions/26691458)
    
 <a href="https://imgbb.com/"><img src="https://i.ibb.co/nDKjp41/download.jpg" alt="download" border="0"></a> 

```
Input:

4
-1 10 15 20
10 -1 35 25
15 35 -1 30
20 25 30 -1
      
Output:80
1->2->4->3->1
10 + 25 + 30 + 15 := 80
```      
      
<details>
<summary>Code</summary>
<ul>

```c++

// dp[i][mask] =  min dist needed to travel from city i to cities represented by mask 
const int N=21;
int tsp[N][N],dp[N][(1<<N)];

int solve(int i,int mask,int &n){
    if(mask==0) return tsp[i][0]; //when we have no cities left we can travel to our base city
    if(dp[i][mask]!=-1) return dp[i][mask];

    int ans=INT_MAX;
    // here i=current city, mask=available cities at that moment.
    for(int j=0;j<n;++j){
        if( mask & (1<<j) ){ //if the jth city is available at that moment
            ans=min(ans,tsp[i][j] + solve(j,(mask^(1<<j)),n)); //we'll toggle the jth bit as jth city has already been visited
        }
    }
    return dp[i][mask]=ans;
}
int n;cin>>n;
for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
        cin>>tsp[i][j];
    }
}
memset(dp,-1,sizeof(dp));
cout<<solve(0,((1<<n)-1)^1,n)<<'\n';
// here ^1 represents total minimum dist except for city 1
```
  
</ul>
</details>
 


<details>
<summary>Related Problems</summary>
<ul>
  
 - [Vitamins](https://codeforces.com/gym/302977/problem/C) [Submission](https://codeforces.com/gym/302977/submission/98868151)

</ul>
</details>

  


# Probablity DP
  **Expected value:** is the average value of an event/experiment
  $$
  E(X) = \sum_{\omega\in\Omega}P(\omega)*X(\omega)
  $$
  where, $P(\omega)$ = The probablity of $\omega$ event to happen.
         $X(\omega)$ = The result of $\omega$ event

  

<details>
<summary>Problems</summary>
<ul>
 Three bags $A$,$B$ and $C$.Until the bag contains $100$ coins of the same color, we will randomly take out one coin from the bag. (Every coin has an equal probability of being chosen.) Then, put back into the bag two coins of the same kind as the removed coin.
  
  
  **Explanation:** Here, for each step we'll calculate the expected values for each type of coins.From the definition, we can find the expected value for type $x$ is $\dfrac{x}{x+y+z}$ , the probablity of $x$ multipling with $solve(x+1,y,z)$,future expected values. Finally $dp[x][y][z]$ stores each expected values + $1$ for each single step.

<details>
<summary>Code</summary>
<ul>

```c++
const int N=101;
double dp[N][N][N];

double solve(int x,int y, int z){
    if(x==100 or y==100 or z==100) return 0;
    if(dp[x][y][z]) return dp[x][y][z];
    double X=(1.0*x/(x+y+z))*solve(x+1,y,z);
    double Y=(1.0*y/(x+y+z))*solve(x,y+1,z);
    double Z=(1.0*z/(x+y+z))*solve(x,y,z+1);
    return dp[x][y][z]=X+Y+Z+1;
}
double x,y,z;cin>>x>>y>>z; 
cout<<fixed<<showpoint<<setprecision(20); 
cout<<solve(x,y,z)<<endl;
```

</ul>
</details>
</ul>
</details>

# Dp on Trees
> Given a rooted tree with $n$ nodes. Find the sizes of all substrees in $O(n)$.
<details>
<summary>Code</summary>
<ul>

```c++
const int N = 2e5 + 5;
vector<int> tree[N];
int subtree[N];

void dfs(int u, int par) {
    subtree[u] = 1;
    for (auto v: tree[u]) {
        if (v != par) {
            dfs(v, u);
            subtree[u] += subtree[v];
        }
    }
}

void malena() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) {
        cout << subtree[i] << " ";
    }cout << '\n';
}
	  
	     
```

</ul>
</details>












    

