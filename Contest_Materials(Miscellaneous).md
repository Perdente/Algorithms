# Matrix
### Rotation of matrix
```c++
//inplace rotation of 90 degree anticlockwise
//https://atcoder.jp/contests/abc218/submissions/25796102
  auto rotate_matrix=[&](VV &a){
    for(int i=0;i<n/2;++i){
      for(int j=i;j<n-i-1;++j){
        temp=a[i][j];
         // Move values from right to top
            a[i][j] = a[j][n-i-1];

            // Move values from bottom to right
            a[j][n-i-1] = a[n-i-1][n-j-1];

            // Move values from left to bottom
            a[n-i-1][n-j-1]= a[n-j-1][i];

            // Assign temp to left
            a[n-j-1][i] = temp;
      }
    }
  };
```
# Array
### Shift $left$ and $right$

```c++
int n, k; cin >> n >> k;
vector<int> v(n);
for (auto &it: v) cin >> it;
vector<int> left_shift(n), right_shift(n);
for (int i = 0; i < n; ++i) {
    left_shift[i] = v[(i + k) % n];
    right_shift[(i + k) % n] = v[i];
}
for (auto it: left_shift) cout << it << " ";
    cout << '\n';
for (auto it: right_shift) cout << it << " ";
    cout << '\n';
Input: 
5 21
1 2 3 4 5
Output:
left -> 2 3 4 5 1 
right -> 5 1 2 3 4
```

### Co-ordinate Compression
```c++
int n; cin >> n;
vector<int> v(n);
for (auto &val: v) cin >> val;
vector<int> u = v;
sort(u.begin(), u.end());
u.resize(unique(u.begin(), u.end()) - u.begin());
for (int i = 0; i < n; ++i) {
    v[i] = lower_bound(u.begin(), u.end(), v[i]) - u.begin();
}
for (auto i: v) cout << i << " ";
/*
in-6
109 592 411 51 135 355
ou-1 5 4 0 2 3 
*/
```
### Local Maxima - Minima
```c++
int n; cin >> n;
vector<int> v(n);
for (int i = 0; i < n; ++i) {
    cin >> v[i];
}
vector<int> mi, ma;
if (v[0] < v[1]) mi.push_back(0);
if (v[0] > v[1]) ma.push_back(0);
for (int i = 1; i < n - 1; ++i) {
    if (v[i] < v[i - 1] and v[i] < v[i + 1]) mi.push_back(i);
    else if (v[i] > v[i - 1] and v[i] > v[i + 1]) ma.push_back(i);
}
if (v[n - 1] < v[n - 2]) mi.push_back(n - 1);
if (v[n - 1] > v[n - 2]) ma.push_back(n - 1);
for (auto val: mi) cout << val << " ";
    cout << '\n';
for (auto val: ma) cout << val << " ";
cout << '\n';

/*
9
1 2 3 2 1 2 3 2 1

> 0 4 8 
> 2 6 

*/
```

### Nearest non-zero value in circular array
```c++
//https://www.codechef.com/START11B/problems/POSSPEW
V v(2*n);
lp(i,2*n){
  if(i<n){
    cin>>v[i];	
  }else{
    v[i]=v[i-n];	
  }
}
V ind; // stores the indices of non-zero elements
lp(i,2*n){
  if(v[i])ind.pb(i);
}
lp(i,n){
  int j=upper_bound(all(ind),i)-ind.begin(); 
  int j1=upper_bound(all(ind),i+n)-ind.begin();
  int t;// stores min distance for i+1 to n-1 index
  int t1;// stores min distance for i-1 to 0 index
  if(j==0){
    t=ind[j]-i;// check for righ indices
  }else if(j==sz(ind)){
    t=i-ind[j-1];// check for left indices
  }else{
    t=min(i-ind[j-1],ind[j]-i);
  }
  if(j1==0){
    t1=ind[j1]-(i+n);
  }else if(j1==sz(ind)){
    t1=(i+n)-ind[j1-1];
  }else{
    t1=min(i+n-ind[j1-1],ind[j1]-i-n);
  }

  t=min(t,t1); // nearest distance for each non-zero array element
}
```
### next greater element in an array
```c++
cin>>n;
V v(n);
lp(i,n){
  cin>>v[i];
}
stack<int> st;
st.push(v[0]);
lp1(i,1,n-1){
  if(st.empty()){
    st.push(v[i]);
    continue;
  }
  while(!st.empty() and st.top()>v[i]){
    debug(v[i]);
    st.pop();
  }
  st.push(v[i]);
}
while(!st.empty()){
  cout<<-1<<endl;
  st.pop();
}
```
### Count pairs in array whose sum is divisible by $K$

```c++
int n, k; cin >> n >> k;
vector<int> v(n);
map <int, int> cnt;
for (auto &it: v) cin >> it, it %= k;
int ans = 0;
for (auto it: v) {
    ans += cnt[k - it];
    cnt[it]++;
}
cout << ans + (cnt[0] * (cnt[0] - 1) / 2)<< '\n';
```
### Count Subarray Sums Divisible by K (https://leetcode.com/problems/subarray-sums-divisible-by-k/)
```c++
vector<int> presum;
  int temp = 0;
  for (auto it: nums) {
      temp += it;
      presum.push_back(temp);
  }
  int ans = 0;
  map <int, int> cnt;
  cnt[0] = 1;
  for (auto it: presum) {
      ans += cnt[((it % k) + k) % k]; // for negative numbers
      cnt[((it % k) + k) % k]++;
  }
  return ans;
}
```
### Subset with no pair sum divisible by $K$
```c++
/*
https://www.hackerrank.com/challenges/non-divisible-subset/problem
> if sum of two numbers is divisible by K, then if one of them gives remainder i, other will give remainder (K – i).
> a subset with no pair sum divisible by K must include either elements with remainder f[i] or with remainder f[K – i]
> so we include max (f[i], f[k - i])
> we must include atmost 1 numbers whose remainder is either 0 or K/2 as they can be divisible otherwise
*/
int n, k; cin >> n >> k;
vector<int> v(n);
map <int, int> cnt;
for (auto &it: v) cin >> it, cnt[it % k]++;
int ans = bool(cnt[0]);
if (k % 2 == 0) cnt[k / 2] = 1;
for (int i = 1; i <= k / 2; ++i) {
    ans += max (cnt[i], cnt[k - i]);
}
cout << ans << '\n';
```
