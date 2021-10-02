# Coin Change
### Combination Sum
>Your task is to **count the number of ways** to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and 6.

For example, if n=3, there are 4 ways:
- 1+1+1
- 1+2
- 2+1
- 3
<details>
<summary>Code</summary>
<ul>
  
```c++
int n;cin>>n;
int dp[n+1];
memset(dp,0,sizeof(dp));
dp[0]=1;
for(int i=1;i<=n;++i)
{
  for(int x=1;x<=6;++x)
  {
    if(i-x>=0)dp[i]+=dp[i-x],dp[i]%=mod;
  }
}
cout<<dp[n]<<endl;
```
</ul>
</details>
<br/>

### Minimizing Coin

>Your task is to produce a sum of money x using the available coins in such a way that **the number of coins** is minimal.
>For example, if the coins are {1,5,7} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.

<details>
<summary>Code</summary>
<ul>
  
```c++
int n,sum;
cin>>n>>sum;
vector<int>v(n);
for(int &i:v)cin>>i;
vector<int>dp(sum+1,1e9);
dp[0]=0;
for(int j=1;j<=sum;++j)
{
  for(int i=1;i<=n;++i)
  {
    if(j-v[i-1]>=0)
    {
      dp[j]=min(dp[j],1+dp[j-v[i-1]]);
      dp[j]%=mod;
    }
  }
}
if(dp[sum]==1e9)return cout<<-1<<endl,0;
cout<<dp[sum]<<endl;
```
</ul>
</details>
<br/>
