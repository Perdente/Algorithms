# Data Structure
### Segment Tree
>Seg-Sum
```c++
const int N=1e5+6,mod=1e9+7;
 
struct segtree{
    int size;
    vector<int>sums;
    void init(int n){
        size=1;
        while(size<n)size*=2;
        sums.assign(2*size,0LL);
    }
    
    void set(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            sums[x]=v;
            return;
        }
        int m=lx+(rx-lx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }else{
            set(i,v,2*x+2,m,rx);
        }
        sums[x]=sums[2*x+1]+sums[2*x+2];
    }
    
    void set(int i,int v){
        set(i,v,0,0,size);
    }
    
    void build(vector<int>&a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<a.size()){
                sums[x]=a[lx];
            }
            return;
        }
        int m=lx+(rx-lx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        sums[x]=sums[2*x+1]+sums[2*x+2];
    }
    void build(vector<int>&a){
        build(a,0,0,size);
    }
    
    int sum(int l,int r,int x,int lx,int rx){
        if(lx>=r or l>=rx) return 0;
        if(lx>=l and rx<=r) return sums[x];
        int m=lx+(rx-lx)/2;
        int ls=sum(l,r,2*x+1,lx,m);
        int rs=sum(l,r,2*x+2,m,rx);
        return ls+rs; 
    }
    
    int sum(int l,int r){
        return sum(l,r,0,0,size);
    }
};
int n,m;cin>>n>>m;
segtree st;
st.init(n);
vector<int>a(n);
for(int i=0;i<n;++i)
    cin>>a[i];
st.build(a);
while(m--){
    int op;cin>>op;
    if(op==1){
        int i,v;cin>>i>>v;
        st.set(i,v);
    }else{
        int l,r;cin>>l>>r;
        cout<<st.sum(l,r)<<"\n";// [l,r-1]
    }
}
```
>Seg-Min
```c++
const int N=1e5+6,mod=1e9+7;
 
struct segtree{
    int size;
    vector<int>Mi;
    void init(int n){
        size=1;
        while(size<n)size*=2;
        Mi.assign(2*size,0LL);
    }
    
    void set(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            Mi[x]=v;
            return;
        }
        int m=lx+(rx-lx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }else{
            set(i,v,2*x+2,m,rx);
        }
        Mi[x]=min(Mi[2*x+1],Mi[2*x+2]);
    }
    
    void set(int i,int v){
        set(i,v,0,0,size);
    }
    
    void build(vector<int>&a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<a.size()){
                Mi[x]=a[lx];
            }
            return;
        }
        int m=lx+(rx-lx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        Mi[x]=min(Mi[2*x+1],Mi[2*x+2]);
    }
    void build(vector<int>&a){
        build(a,0,0,size);
    }
    
    int mini(int l,int r,int x,int lx,int rx){
        if(lx>=r or l>=rx) return 1e10;
        if(lx>=l and rx<=r) return Mi[x];
        int m=lx+(rx-lx)/2;
        int ls=mini(l,r,2*x+1,lx,m);
        int rs=mini(l,r,2*x+2,m,rx);
        return min(ls,rs);
    }
    
    int mini(int l,int r){
        return mini(l,r,0,0,size);
    }
};
 
int n,m;cin>>n>>m;
segtree st;
st.init(n);
vector<int>a(n);
for(int i=0;i<n;++i)
    cin>>a[i];
st.build(a);
while(m--){
    int op;cin>>op;
    if(op==1){
        int i,v;cin>>i>>v;
        st.set(i,v);
    }else{
        int l,r;cin>>l>>r;
        cout<<st.mini(l,r)<<"\n";//[l,r-1]
    }
}
```
### SQRT Decomposition/MO's Algorithm
> find the distinct elements $(l,r)$
```c++

#define N 311111
#define A 1111111


int cnt[A], a[N], ans[N], answer = 0;
int BLOCK;
struct node {
	int L, R, i;
}query[N];

bool cmp(node x, node y) {
	if(x.L/BLOCK != y.L/BLOCK) {
		// different blocks, so sort by block.
		return x.L/BLOCK < y.L/BLOCK;
	}
	// same block, so sort by R value
	return x.R < y.R;
}

void add(int position) {
	cnt[a[position]]++;
	if(cnt[a[position]] == 1) {
		answer++;
	}
}

void remove(int position) {
	cnt[a[position]]--;
	if(cnt[a[position]] == 0) {
		answer--;
	}
}
int main(){
int n;
	cin>>n;
	BLOCK=sqrt(n);
	
	for(int i=0; i<n; i++)
		cin>>a[i];

	int m;
	cin>>m;
	for(int i=0; i<m; i++) {
		cin>>query[i].L>>query[i].R;
		query[i].L--; query[i].R--;
		query[i].i = i;
	}

	sort(query, query + m, cmp);

	int currentL = 0, currentR = 0;
	for(int i=0; i<m; i++) {
		int L = query[i].L, R = query[i].R;
		while(currentL < L) {
			remove(currentL++);
		}
		while(currentL > L) {
			add(currentL-1);currentL--;
		}
		while(currentR <= R) {
			add(currentR++);
		}
		while(currentR > R+1) {
			remove(currentR-1);currentR--;
		}
		ans[query[i].i] = answer;
	}

	for(int i=0; i<m; i++)
		cout<<ans[i]<<"\n";
}
```
### DSU
```c++
class DSU{
    vector <int> parent, _rank, minimum, maximum, total_elements;
    
    public:
        DSU(int n){
            parent.resize(n + 1);
            minimum.resize(n + 1);
            maximum.resize(n + 1);
            total_elements.assign(n + 1, 1);
            _rank.assign(n + 1, 0);
            initialize(n);
        }
 
        void initialize(int n){
            for(int i = 1 ; i <= n ; ++i){
                parent[i] = i;
                minimum[i] = i;
                maximum[i] = i;
            }
        }
 
        int find_parent(int element){
            if(parent[element] == element) return element;
            return parent[element] = find_parent(parent[element]);
        }
        
        void union_by__rank(int a, int b){
            int pa = find_parent(a);
            int pb = find_parent(b);
            if(pa == pb) return;
            if(_rank[pa] == _rank[pb]) ++_rank[pa];
            if(_rank[pa] > _rank[pb]){
                parent[pb] = pa;
                total_elements[pa] += total_elements[pb];
                minimum[pa] = min(minimum[pa], minimum[pb]);
                maximum[pa] = max(maximum[pa], maximum[pb]);
            } else{
                parent[pa] = pb;
                total_elements[pb] += total_elements[pa];
                minimum[pb] = min(minimum[pa], minimum[pb]);
                maximum[pb] = max(maximum[pa], maximum[pb]);
            }
        }
  
        void union_by_size(int a,int b){
            int pa = find_parent(a);
            int pb = find_parent(b);
            if (pa != pb) {
                if (total_elements[pa] < total_elements[pb])
                    swap(pa, pb);
                parent[pb] = pa;
                minimum[pa]=min(minimum[pa],minimum[pb]);
                maximum[pa]=max(maximum[pa],maximum[pb]);
                total_elements[pa] += total_elements[pb];
            }
        }

        int getSize(int v){
            return total_elements[find_parent(v)];
        }
 
        int getMin(int v){
            return minimum[find_parent(v)];
        }
 
        int getMax(int v){
            return maximum[find_parent(v)];
        }
};
//DSU dsu(n);
```
### Binary Search
#### Binary search on answer
> - Search the result between $(l,r)$
> - Initially $l$ is bad(most of the cases) and $r$ is good.
> - $l$ is some value/index which can never be the answer and $r$ is some value/index which always gives the answer
> - $good(m)$ function determines which element is good or bad.
```c++
auto good=[&](int m){

};
int l=0; // l is bad 
int r=1e6;// r is good
while(r>l+1){
 int m=l+(r-l)/2;
    if(good(m)) r=m;
    else l=m;
}
cout<<r<<endl;
```
### Ordered Set $O(log(n))$
> - _order_of_key$(k)$_ : Number of item strictly smaller than $k$
> - _find_by_order$(k)$_ : $k$th element in a set (counting from $0$)
```c++
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

ordered_multiset os;
int x=os.order_of_key(k);
int x=*(os.find_by_order(k));
```
> Upper_bound & Lower_bound
```c++
auto upper_bound=[&](int element)->int{
 int pos=os.order_of_key(element+1);
 if(pos==os.size()) return -1;
 else{
  return *(os.find_by_order(pos));
 }
};
auto lower_bound=[&](int element)->int{
 int pos=os.order_of_key(element);
 if(pos==os.size()) return -1;
 else return *(os.find_by_order(pos));
};
```
# Algorithms
### Kaden's Algorithm
>Given an array of $n$ elements. Find maximum sum of contiguous non-empty subarray.
>[-1,$(3,-2,5,3)$,-5,2,2]=$9$
```c++
int mx_so_far=INT_MIN;// stores max sub-sum so far
int mx_end_here=0;// stores max sub-sum ending at current pos
for(int i=0;i<n;++i){
	mx_end_here+=v[i];
	// update the maximum sum of sub-array "ending" at index `i` (by adding the
	//current element to maximum sum ending at previous index `i-1`)
	mx_end_here=max(mx_end_here,0LL);
	// if the maximum sum is negative, set it to 0 (which represents
	// an empty subarray)
	mx_so_far=max(mx_so_far,mx_end_here);
	// update the result if the current subarray sum is found to be greater
}
cout<<mx_so_far<<endl;
```

### Meet in the middle
> Condition: If the problem can be solved using $n/2$ then we can use _meet in the middle_
> - Split the given set into two sets of approximately equal size.
> - Compute the required answers for one set, and sort it to make it ready for binary search.
> - Iterate over the unsorted result set, and binary search for the required value in the sorted set. 

<details>
<summary>Problem</summary>
<ul>
You are given an array of $n$ numbers. In how many ways can you choose a subset of the numbers with sum $x$?
<details>
<summary>Code</summary>
<ul>
	
```c++
cin>>n>>m;
k=n/2;
V v(k),u(n-k);
lp(i,k){
	cin>>v[i];
}
lp(i,n-k){
	cin>>u[i];
}
M mp;
lp(mask,(1LL<<k)){
	sum=0;
	lp(i,k){
		if(mask & (1LL<<i)){
			sum+=v[i];
			if(sum>m)break;
		}
	}
	mp[sum]++;
}
St st;
cnt=0;
lp(mask,(1LL<<(n-k))){
	sum=0;
	lp(i,(n-k)){
		if(mask & (1LL<<i)){
			sum+=u[i];
			if(sum>m)break;
		}
	}
	if(mp.find(m-sum)!=mp.end()){
		cnt+=mp[m-sum];
	}
}
cout<<cnt<<endl;
```
	
</ul>
</details>

</ul>
</details>

