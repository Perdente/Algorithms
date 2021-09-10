# Segment Tree
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
# DSU
```c++
const int N=3e5+5;
class DSU{
    vector <int> parent, rank, minimum, maximum, total_elements;
    
    public:
        DSU(int n){
            parent.resize(n + 1);
            minimum.resize(n + 1);
            maximum.resize(n + 1);
            total_elements.assign(n + 1, 1);
            rank.assign(n + 1, 0);
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
        
        void union_by_rank(int a, int b){
            int pa = find_parent(a);
            int pb = find_parent(b);
            if(pa == pb) return;
            if(rank[pa] == rank[pb]) ++rank[pa];
            if(rank[pa] > rank[pb]){
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
int n;cin>>n;
DSU dsu(n);
```
# Binary Search
### binary search on answer
> - Search the result between _[l,r]_
> - Initially **l** is bad(most of the cases) and **r** is good.
> - **l** is some value/index which can never be the answer and **r** is some value/index which always gives the answer
> - _good(m)_ function determines which element is good or bad.
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
# Ordered Set _O(log(n))_
> - _order_of_key(k)_ : Number of item strictly smaller than k
> - _find_by_order(k)_ : kth element in a set (counting from 0)
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
