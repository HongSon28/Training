#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q;
int h[N+5],par[N+5],sz[N+5],pos[N+5],a[N+5],chainID[N+5],chainHead[N+5],curChain=1,curPos=1;
pair<int,int> st[N*4+5];
int inf=1e9;
int col[N+5];
vector<vector<int>>adj(N+5);
void build (int id,int l,int r) {
	if (l==r) {
		st[id]={inf,a[l]};
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id]={inf,0};
}
void update(int id,int l,int r,int pos,int type,int val) {
	if (l>pos||r<pos) return;
	if (l==r) {
		if (type==1) st[id].first=val;
		else st[id].first=inf;
		return; 
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos,type,val);
	update(id*2+1,mid+1,r,pos,type,val);
	if (st[id*2].first<st[id*2+1].first) st[id]=st[id*2];
	else st[id]=st[id*2+1];
}
pair<int,int> get(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return {inf,0};
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	pair<int,int>p1=get(id*2,l,mid,u,v),p2=get(id*2+1,mid+1,r,u,v);
	if (p1.first<p2.first) return p1;
	return p2;
}
void dfs(int u,int p) {
	sz[u]=1;
	for (auto v:adj[u]) {
		if (v==p) continue;
		par[v]=u;
		h[v]=h[u]+1;
		dfs(v,u);
		sz[u]+=sz[v];
	}
}
void hld(int u,int par) {
	if (!chainHead[curChain]) chainHead[curChain]=u;
	chainID[u]=curChain;
	pos[u]=curPos;
	a[curPos]=u;
	curPos++;
	int nxt=0;
	for (auto v:adj[u]) {
		if (v==par) continue;
		if (nxt==0||sz[v]>sz[nxt]) nxt=v;
	}
	if (nxt) hld(nxt,u);
	for (auto v:adj[u]) {
		if (v==par) continue;
		if (v!=nxt) {
			curChain++;
			hld(v,u);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>q;
    for (int i=1;i<n;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    dfs(1,-1);
    hld(1,-1);
    build(1,1,n);
    while (q--) {
    	int type,u;
    	cin>>type>>u;
    	if (type==0) {
    		if (col[u]==0) {
    			col[u]=1;
    			update(1,1,n,pos[u],1,h[u]+1);
    		} else {
    			col[u]=0;
    			update(1,1,n,pos[u],0,inf);
    		}
    	} else {
    		int res=inf,p;
    		while (chainID[u]!=chainID[1]) {
    			pair<int,int>temp=get(1,1,n,pos[chainHead[chainID[u]]],pos[u]);
    			if (res>temp.first) {
    				res=temp.first;
    				p=temp.second;
    			}
    			u=par[chainHead[chainID[u]]];
    		}
    		pair<int,int>temp=get(1,1,n,pos[1],pos[u]);
    		if (res>temp.first) {
    			res=temp.first;
    			p=temp.second;
    		}
    		if (res==inf) cout<<-1<<'\n';
    		else cout<<p<<'\n';
    	}
    }
}