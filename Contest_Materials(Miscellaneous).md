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
      ans += cnt[((it % k) + k) % k];
      cnt[((it % k) + k) % k]++;
  }
  return ans;
}
```
