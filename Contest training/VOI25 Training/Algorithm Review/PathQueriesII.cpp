#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,q;
int val[N+5];
vector<int>adj[N+5];
int d[N+5],p[N+5],sz[N+5];
int chainHead[N+5],chainID[N+5],curChain,curpos,pos[N+5],a[N+5];
void dfs(int u,int par) {
	sz[u]=1;
	p[u]=par;
	d[u]=d[par]+1;
	for (auto v:adj[u]) {
		if (v==par) continue;
		dfs(v,u);
		sz[u]+=sz[v];
	}
}
void hld(int u) {
	if (!chainHead[curChain]) chainHead[curChain]=u;
	chainID[u]=curChain;
	pos[u]=++curpos;
	a[curpos]=u;
	int nxt=-1;
	for (auto v:adj[u]) {
		if (v==p[u]) continue;
		if (nxt==-1||sz[nxt]<sz[v]) nxt=v; 
	}
	if (nxt!=-1) hld(nxt);
	for (auto v:adj[u]) {
		if (v==p[u]||v==nxt) continue;
		curChain++;
		hld(v);
	}
}
struct SegmentTree{
	int st[N*4+5],inf=1e9;
	void build(int id,int l,int r) {
		if (l==r) {
			st[id]=val[a[l]];
			return;
		}
		int mid=(l+r)/2;
		build(id*2,l,mid);
		build(id*2+1,mid+1,r);
		st[id]=max(st[id*2],st[id*2+1]);
	}
	void update(int id,int l,int r,int pos,int val) {
		if (l>pos||r<pos) return;
		if (l==r) {
			st[id]=val;
			return;
		}
		int mid=(l+r)/2;
		update(id*2,l,mid,pos,val);
		update(id*2+1,mid+1,r,pos,val);
		st[id]=max(st[id*2],st[id*2+1]);
	}
	int get(int id,int l,int r,int u,int v) {
		if (l>v||r<u) return -inf;
		if (u<=l&&r<=v) return st[id];
		int mid=(l+r)/2;
		return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
	}
} tree;
int lca(int u,int v) {
	while (chainID[u]>chainID[v]) u=p[chainHead[chainID[u]]];
	while (chainID[v]>chainID[u]) v=p[chainHead[chainID[v]]];
	if (d[u]<d[v]) return u;
	return v;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>val[i];
    for (int i=1;i<n;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    dfs(1,0);
    hld(1);
    tree.build(1,1,n);
    while (q--) {
    	int type;
    	cin>>type;
    	if (type==1) {
    		int s,x;
    		cin>>s>>x;
    		tree.update(1,1,n,pos[s],x);
    	} else {
    		int u,v;
    		cin>>u>>v;
    		int k=lca(u,v),res=0;
    		while (chainID[u]!=chainID[k]) {
    			res=max(res,tree.get(1,1,n,pos[chainHead[chainID[u]]],pos[u]));
    			u=p[chainHead[chainID[u]]];
    		}
    		while (chainID[v]!=chainID[k]) {
    			res=max(res,tree.get(1,1,n,pos[chainHead[chainID[v]]],pos[v]));
    			v=p[chainHead[chainID[v]]];
    		}
    		if (d[u]<d[v]) res=max(res,tree.get(1,1,n,pos[u],pos[v]));
    		else res=max(res,tree.get(1,1,n,pos[v],pos[u]));
    		cout<<res<<' ';
    	}
    }
}