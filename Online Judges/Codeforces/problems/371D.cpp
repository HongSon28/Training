#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,q;
long long a[N+5];
struct DSU{
	int p[N+5],mx[N+5];
	long long cap[N+5],cur[N+5];
	void init() {
		for (int i=1;i<=n;i++) {
			p[i]=-1;
			cap[i]=a[i];
			cur[i]=0;
			mx[i]=i;
		}
	}
	int find_root(int u) {
		if (p[u]<0) return u;
		return p[u]=find_root(p[u]);
	}
	void Union(int u,int v) {
		if ((u=find_root(u))==(v=find_root(v))) return;
		if (p[u]>p[v]) swap(u,v);
		cap[u]+=cap[v];
		cur[u]+=cur[v];
		mx[u]=max(mx[u],mx[v]);
		p[u]+=p[v];
		p[v]=u;
	}
} dsu;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    dsu.init();
    cin>>q;
    while (q--) {
    	int type;
    	cin>>type;
    	if (type==1) {
    		int p;
    		long long x;
    		cin>>p>>x;
    		while (x>0) {
    			int u=dsu.find_root(p);
    			long long t=min(x,dsu.cap[u]-dsu.cur[u]);
    			dsu.cur[u]+=t;
    			x-=t;
    			if (x>0) {
    				int nxt=dsu.mx[u]+1;
    				if (nxt==n+1) break;
    				dsu.Union(u,nxt);
    			}
    		}
    	} else {
    		int k;
    		cin>>k;
    		int u=dsu.find_root(k);
    		if (dsu.mx[u]!=k) cout<<a[k]<<'\n';
    		else cout<<a[k]-(dsu.cap[u]-dsu.cur[u])<<'\n';
    	}
    }
}