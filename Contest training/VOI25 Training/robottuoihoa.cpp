#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,q,a,b;
int x[N+5];
struct SegmentTree{
	long long f[N*4+5],g[N*4+5],h[N*4+5],lazy[N*4+5],inf=1e18;
	void merge(int id) {
		f[id]=min(f[id*2],f[id*2+1]);
		g[id]=min(g[id*2],g[id*2+1]);
		h[id]=min(h[id*2],h[id*2+1]);
	}
	void build(int id,int l,int r) {
		if (l==r) {
			f[id]=min(abs(a-x[1])+abs(b-l),abs(b-x[1])+abs(a-l));
			lazy[id]=0;
			g[id]=f[id]+l;
			h[id]=f[id]+n-l;
			return;
		}
		int mid=(l+r)/2;
		build(id*2,l,mid);
		build(id*2+1,mid+1,r);
		merge(id);
	}
	void down(int id) {
		long long t=lazy[id];
		lazy[id]=0;
		lazy[id*2]+=t,lazy[id*2+1]+=t;
		f[id*2]+=t,f[id*2+1]+=t;
		g[id*2]+=t,g[id*2+1]+=t;
		h[id*2]+=t,h[id*2+1]+=t;
	}
	void update(int id,int l,int r,int u,int v,long long val) {
		if (l>v||r<u||u>v) return;
		if (u<=l&&r<=v) {
			f[id]+=val;
			g[id]+=val;
			h[id]+=val;
			lazy[id]+=val;
			return;
		}
		down(id);
		int mid=(l+r)/2;
		update(id*2,l,mid,u,v,val);
		update(id*2+1,mid+1,r,u,v,val);
		merge(id);
	}
	long long get_f(int id,int l,int r,int u,int v) {
		if (l>v||r<u||u>v) return inf;
		if (u<=l&&r<=v) return f[id];
		int mid=(l+r)/2;
		down(id);
		return min(get_f(id*2,l,mid,u,v),get_f(id*2+1,mid+1,r,u,v));
	}
	long long get_g(int id,int l,int r,int u,int v) {
		if (l>v||r<u||u>v) return inf;
		if (u<=l&&r<=v) return g[id];
		int mid=(l+r)/2;
		down(id);
		return min(get_g(id*2,l,mid,u,v),get_g(id*2+1,mid+1,r,u,v));
	}
	long long get_h(int id,int l,int r,int u,int v) {
		if (l>v||r<u||u>v) return inf;
		if (u<=l&&r<=v) return h[id];
		int mid=(l+r)/2;
		down(id);
		return min(get_h(id*2,l,mid,u,v),get_h(id*2+1,mid+1,r,u,v));
	}
} tree;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>q>>a>>b;
	for (int i=1;i<=q;i++) cin>>x[i];
	tree.build(1,1,n);
	for (int i=1;i<q;i++) {
		long long dist=abs(x[i+1]-x[i]);
		long long t=tree.get_f(1,1,n,x[i],x[i]);
		long long mn=min({dist,tree.get_g(1,1,n,x[i+1]+1,n)-x[i+1]-t,tree.get_h(1,1,n,1,x[i+1]-1)-(n-x[i+1])-t,tree.get_f(1,1,n,x[i+1],x[i+1])-t});
		//cout<<x[i]<<' '<<dist<<' '<<mn<<endl;
		tree.update(1,1,n,x[i],x[i],mn);
		tree.update(1,1,n,1,x[i]-1,dist);
		tree.update(1,1,n,x[i]+1,n,dist);
	}
	cout<<tree.f[1];
}