#include<bits/stdc++.h>
using namespace std;
const int N=1e5,M=20;
int n,m;
long long a[N+5];
struct SegmentTree{
	int pos;
	struct{
		int val,lazy;
	} st[N*4+5];
	void down(int id,int l,int r) {
		if (!st[id].lazy) return;
		st[id].lazy=0;
		st[id*2].lazy^=1;
		st[id*2+1].lazy^=1;
		int mid=(l+r)/2;
		st[id*2].val=mid-l+1-st[id*2].val;
		st[id*2+1].val=r-mid-st[id*2+1].val;
	}
	void build(int id,int l,int r) {
		st[id].lazy=0;
		if (l==r) {
			st[id].val=((a[l]>>pos)&1);
			return;
		}
		int mid=(l+r)/2;
		build(id*2,l,mid);
		build(id*2+1,mid+1,r);
		st[id].val=st[id*2].val+st[id*2+1].val;
	}
	void update(int id,int l,int r,int u,int v) {
		if (l>v||r<u) return;
		if (u<=l&&r<=v) {
			st[id].lazy^=1;
			st[id].val=r-l+1-st[id].val;
			return;
		}
		down(id,l,r);
		int mid=(l+r)/2;
		update(id*2,l,mid,u,v);
		update(id*2+1,mid+1,r,u,v);
		st[id].val=st[id*2].val+st[id*2+1].val;
	}
	int get(int id,int l,int r,int u,int v) {
		if (l>v||r<u) return 0;
		if (u<=l&&r<=v) return st[id].val;
		down(id,l,r);
		int mid=(l+r)/2;
		return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
	}
} tree[M+1];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=0;i<=M;i++) {
		tree[i].pos=i;
		tree[i].build(1,1,n);
	}
	cin>>m;
	while (m--) {
		int type;
		cin>>type;
		if (type==1) {
			int l,r;
			cin>>l>>r;
			long long res=0;
			for (int i=0;i<=M;i++) 
				res+=(1ll<<i)*tree[i].get(1,1,n,l,r);
			cout<<res<<'\n';
		} else {
			int l,r;
			long long x;
			cin>>l>>r>>x;
			for (int i=0;i<=M;i++) {
				if (x>>i&1) tree[i].update(1,1,n,l,r);
			}
		}
	}
}