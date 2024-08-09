#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
struct PST{
	int left,right;
	long long val;
} st[300*N+5];
int n,q;
long long a[N+5];
int r[N+5];
int nnode,ntree=1;
int build(int l,int r) {
	if (l==r) {
		st[++nnode].val=a[l];
		return nnode;
	}
	int mid=(l+r)/2;
	int cur=++nnode;
	st[cur].left=build(l,mid);
	st[cur].right=build(mid+1,r);
	st[cur].val=st[st[cur].left].val+st[st[cur].right].val;
	return cur;
}
int update(int root,int l,int r,int u,long long val) {
	if (l==r) {
		st[++nnode].val=val;
		return nnode;
	}
	int mid=(l+r)/2;
	int cur=++nnode;
	if (u<=mid) {
		st[cur].left=update(st[root].left,l,mid,u,val);
		st[cur].right=st[root].right;
	} else {
		st[cur].left=st[root].left;
		st[cur].right=update(st[root].right,mid+1,r,u,val);
	}
	st[cur].val=st[st[cur].left].val+st[st[cur].right].val;
	return cur;
}
long long get(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return 0ll;
	if (u<=l&&r<=v) return st[id].val;
	int mid=(l+r)/2;
	return get(st[id].left,l,mid,u,v)+get(st[id].right,mid+1,r,u,v);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    r[1]=build(1,n);
    while (q--) {
    	int type;
    	cin>>type;
    	if (type==1) {
    		int k,u;
    		long long x;
    		cin>>k>>u>>x;
    		r[k]=update(r[k],1,n,u,x);
    	} else if (type==2) {
    		int k,u,v;
    		cin>>k>>u>>v;
    		cout<<get(r[k],1,n,u,v)<<'\n';
    	} else {
    		int k;
    		cin>>k;
    		r[++ntree]=r[k];
    	}
    }
}
