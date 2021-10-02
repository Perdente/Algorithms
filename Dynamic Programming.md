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
