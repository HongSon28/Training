#include<bits/stdc++.h>
using namespace std;
const int N=1e5,LG=17;
int n,t;
int a[N+5];
int rmq[N+5][LG+5];
int get(int l,int r) {
	if (l==r) return a[l];
	r--;
	int k=__lg(r-l+1);
	return __gcd(rmq[l][k],rmq[r-(1<<k)+1][k]);
}
struct SegmentTree{
	struct Node{
		int mn,cnt;
	} st[N*4+5];
	int inf=1e9;
	Node merge(Node x,Node y) {
		if (x.mn<y.mn) return x;
		if (x.mn>y.mn) return y; 
		return {x.mn,x.cnt+y.cnt};	
	}
	void build(int id,int l,int r) {
		if (l==r) {
			st[id].mn=a[l];
			st[id].cnt=1;
			return;
		}
		int mid=(l+r)/2;
		build(id*2,l,mid);
		build(id*2+1,mid+1,r);
		st[id]=merge(st[id*2],st[id*2+1]);
	}
	Node get(int id,int l,int r,int u,int v) {
		if (l>v||r<u) return {inf,0};
		if (u<=l&&r<=v) return st[id];
		int mid=(l+r)/2;
		return merge(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
	}
	int cnt(int l,int r,int x) {
		Node t=get(1,1,n,l,r);
		if (t.mn!=x) return 0;
		return t.cnt;
	}
} tree;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<n;i++) rmq[i][0]=__gcd(a[i],a[i+1]);
    for (int i=1;(1<<i)<n;i++) {
    	for (int j=1;j+(1<<i)-1<n;j++) rmq[j][i]=__gcd(rmq[j][i-1],rmq[j+(1<<(i-1))][i-1]);
    }	
    tree.build(1,1,n);
    cin>>t;
    while (t--) {
    	int l,r;
    	cin>>l>>r;
    	int g=get(l,r);
    	cout<<r-l+1-tree.cnt(l,r,g)<<'\n';
    }
}