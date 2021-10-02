# Coin Change
### Combination Sum
>Your task is to **count the number of ways** to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and 6.
>For example, if n=3, there are 4 ways: (1+1+1) , (1+2) , (2+1) , 3 .
<details>
<summary>Code</summary>
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
<br/>

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
