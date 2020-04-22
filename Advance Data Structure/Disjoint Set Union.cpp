//https://cp-algorithms.com/data_structures/disjoint_set_union.html#toc-tgt-3
#include<bits/stdc++.h>
using namespace std;
#define mx 1005
int parent[mx],Rank[mx];

void make_set(int v) {
    for(int i=0;i<v;++i)
    {
    	parent[i] = i;
    	Rank[i] = 0;
	}
}
int find_set(int v) {//determines the parent
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    
    if (a != b) {
        if (Rank[a] < Rank[b])
            swap(a, b);
        parent[b] = a;
        if (Rank[a] == Rank[b])
            Rank[a]++;
    }
    printf("%d->%d\n",a,b);
}
bool check(int a, int b){ return find_set(a) == find_set(b); }

int main()
{
	int x;scanf("%d",&x);
	make_set(x);
	union_sets(1,2);
	union_sets(2,3);
	union_sets(4,5);
	union_sets(6,7);
	union_sets(5,6);
	union_sets(3,7);
	for(int i=1;i<=x;++i)
	{
		printf("%d\n",find_set(i));
	}
}
