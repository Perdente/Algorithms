# Number Theory

### Primality Test $\mathcal{O}(sqrt(n))$
```C++
bool isPrime(int n){
	if(n==1) return false;
	for(int i=2;i*i<=n;++i)
		if(n%i==0)return false;
	return true;
}
```

### Sieve of Eratosthenes $\mathcal{O}(mx log(log (mx)))$
```C++
vector<bool> isPrime(mx+1,true);
vector<int> primes;
void Sieve(){
	isPrime[0]=isPrime[1]=false;
	int sq=sqrt(mx);
	for(int i=2;i<=mx;++i){
		if(isPrime[i] and (i*i)<=mx){
			primes.push_back(i);
			for(int j=i*i;j<=mx;j+=i) isPrime[j]=false;
		}
	}
	for(int i=sq+1;i<=mx;++i){
		if(isPrime[i])primes.push_back(i);
	}
}
```
### Prime Factorization $\mathcal{O}(sqrt(n))$
```C++
vector<int> prime_factors;
void PrimeFactorization(int n){
	while(n%2==0)prime_factors.push_back(2),n/=2;
	for(int i=3;i*i<=n;i+=2){
		while(n%i==0){
			prime_factors.push_back(i),n/=i;
		}
	}
	if(n>1)prime_factors.push_back(n);
}
```
### Number of Divisors
> using sieve $\mathcal{O}(mx log(log mx))$
```C++
vector<bool> isPrime(mx,true);
vector<int> primes;
void Seive(){
  isPrime[0]=isPrime[1]=false;
  for(int i=2;i<=mx;++i){
    if(isPrime[i] and (int)(i*i)<=mx){
      for(int j=i*i;j<=mx;j+=i){
        isPrime[j]=false;
      }
    }
  }
  for(int i=1;i<=mx;++i){
    if(isPrime[i])primes.push_back(i);
  }
}

int num_div(int n){
  int ans = 1;
  int sq = sqrt(n);
  for(int i = 0;i<primes.size() && primes[i]<=sq; i++)
  {
    if(n%primes[i] == 0)
    {
      int cnt = 0;
      while(n%primes[i] == 0)
      {
        
        n/=primes[i];cnt++;
      }
      sq = sqrt(n);
      cnt++;
      ans*=cnt;
    }
  }
  if(n!=1LL)
    ans *= 2;
  return ans;
}
```
> Fast calculation $\mathcal{O}(sqrt(n))$
```C++
int num_div(int n){
	int cnt=0;
	for(int i=1;i*i<=n;++i){
		if(n%i==0){
			if(n/i==i)cnt++;
			else cnt+=2;
		}
	}	
	return cnt;
}
```
### Sum of Divisors 
> using Sieve $\mathcal{O}(mx log(log mx))$
```C++
vector<bool> isPrime(mx,true);
vector<int> primes;
void Seive(){
  isPrime[0]=isPrime[1]=false;
  for(int i=2;i<=mx;++i){
    if(isPrime[i] and (int)(i*i)<=mx){
      for(int j=i*i;j<=mx;j+=i){
        isPrime[j]=false;
      }
    }
  }
  for(int i=1;i<=mx;++i){
    if(isPrime[i])primes.push_back(i);
  }
}
int sum_div(int n){
  int res=1,sqrtn=sqrt(n);
  for(int i=0;i<primes.size() and primes[i]<=sqrtn;++i){
    if(n%primes[i]==0){
      int tempSum=1,P=1;
      while(n%primes[i]==0){
        n/=primes[i],P*=primes[i],tempSum+=P;
      }
      sqrtn=sqrt(n),res*=tempSum;
    }
  }
  if(n!=1LL) res*=(n+1);
  return res;
}
```
> (from StackOverflow)
```C++
int sumDivisorsOfDivisors(int n) 
{ 
    // Calculating powers of prime factors and 
    // storing them in a map mp[]. 
    map<int, int> mp; 
    for (int j=2; j<=sqrt(n); j++) 
    { 
        int count = 0; 
        while (n%j == 0) 
        { 
            n /= j; 
            count++; 
        } 

        if (count) 
            mp[j] = count; 
    } 

    // If n is a prime number 
    if (n != 1) 
        mp[n] = 1; 

    // For each prime factor, calculating (p^(a+1)-1)/(p-1) 
    // and adding it to answer. 
    int ans = 1; 
    for (auto it : mp) 
    { 
        int pw = 1; 
        int sum = 0; 

        for (int i=it.second+1; i>=1; i--) 
        { 
            sum += (i*pw); 
            pw *= it.first; 
        } 
        ans *= sum; 
    } 
    return ans; 
} 
```
### Print all Divisors $\mathcal{O}(sqrt(n))$
```C++
void Print_div(int n){
  set<int> st;
  for(int i=1;i*i<=n;++i){
    if(n%i==0)st.insert(i),st.insert(n/i);
  }
  for(auto it:st)cout<<it<<" ";
}
```
### Euler Totient Function/Phi Function $\mathcal{O}(sqrt(n))$
> Counts the number of integers $1$ to $n$ which are **coprime** to $n$.
> Two numbers are **coprime** if their _gcd_ equals $1$
```C++
int Phi(int n){
	int result=n;
	if(n%2==0){
		while(n%2==0)n/=2;
		result-=result/2;
	}
	for(int i=3;i*i<=n;i+=2){
		if(n%i==0){
			while(n%i==0)n/=i;
			result-=result/i;
		}
	}
	if(n>1)result-=result/n;
	return result;
}
```
### Binary Exponentiation
> without **mod**
```C++
int binpow(int a,int b)
{
	int res=1;
	while(b>0)
	{
		if(b%2)res*=a;
		a*=a;
		b>>=1LL;
	}
	return res;
}
```
> with **mod**$(1e^9+7)$
```C++
int binpow(int a,int b,int m)
{
	int res=1;a%=m;
	while(b)
	{
		if(b%2)res=(res*a)%m;
		a=(a*a)%m;
		b>>=1LL;
	}
	return (res%m);
}
```
### ncr 
> without **mod**
```C++
int ncr(int n,int k) {
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}
```

> with **mod**$(1e^9+7)$
```C++
const int mx=1e6,MOD=1e9+7;
int fact[mx];

int binpow(int a,int b)
{
	int res=1;
	while(b>0)
	{
		if(b%2)res=(res*1LL*a)%MOD;
		a=(a*1LL*a)%MOD;
		b>>=1LL;
	}
	return (res%MOD);
}

int ncr(int n,int k){
	if(k>n) return 0;
	int res=fact[n];
	res=(res*1LL*binpow(fact[k],MOD-2))%MOD;
	res=(res*1LL*binpow(fact[n-k],MOD-2))%MOD;
	return res;
}

fact[0]=fact[1]=1;
for(int i=2;i<mx;++i)fact[i]=(fact[i-1]*1LL*i)%MOD;

```











