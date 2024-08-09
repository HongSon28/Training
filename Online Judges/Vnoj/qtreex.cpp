#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
vector<vector<pair<int,int>>>adj;
int n,inf=1e9;
pair<int,int>edge[N+5];
int w[N+5],pos[N+5],a[N+5],sz[N+5],ChainID[N+5],ChainHead[N+5],par[N+5],h[N+5],CurChain=1,CurPos=1;
void dfs(int u) {
	sz[u]=1;
	for (auto [v,wg]:adj[u]) {
		if (v==par[u]) continue;
		par[v]=u;
		h[v]=h[u]+1;
		w[v]=wg;
		dfs(v);
		sz[u]+=sz[v];
	}
}
void hld(int u) {
	if (!ChainHead[CurChain]) ChainHead[CurChain]=u;
	int nxt=0;
	ChainID[u]=CurChain;
	pos[u]=CurPos;
	a[CurPos]=u;
	CurPos++;
	for (auto [v,wg]:adj[u]) {
		if (v==par[u]) continue;
		if (nxt==0||sz[nxt]<sz[v]) nxt=v;
	}
	if (nxt) hld(nxt);
	for (auto [v,wg]:adj[u]) {
		if (v!=par[u]&&v!=nxt) {
			CurChain++;
			hld(v);
		}
	}
}
int LCA(int u,int v) {
	while (ChainID[u]!=ChainID[v]) {
		if (ChainID[u]>ChainID[v]) u=par[ChainHead[ChainID[u]]];
		else v=par[ChainHead[ChainID[v]]];
	}
	if (h[u]<h[v]) return u;
	return v;
}
struct Node{
	int mx,mn,lazy;
} st[N*4+5];
Node mer(Node x,Node y) {
	Node ans;
	ans.mx=max(x.mx,y.mx);
	ans.mn=min(x.mn,y.mn);
	ans.lazy=0;
	return ans;
}
void down(int id) {
	int t=st[id].lazy;
	if (t==0) return;
	st[id].lazy=0;
	st[id*2].lazy^=1;
	st[id*2+1].lazy^=1;
	swap(st[id*2].mx,st[id*2].mn);
	st[id*2].mx=-st[id*2].mx;
	st[id*2].mn=-st[id*2].mn;
	swap(st[id*2+1].mx,st[id*2+1].mn);
	st[id*2+1].mx=-st[id*2+1].mx;
	st[id*2+1].mn=-st[id*2+1].mn;
}
void build (int id,int l,int r) {
	if (l==r) {
		st[id].mx=st[id].mn=w[a[l]];
		st[id].lazy=0;
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id]=mer(st[id*2],st[id*2+1]);
}
void update1(int id,int l,int r,int u,int v) {
	if (u>r||v<l||u>v) return;
	if (u<=l&&r<=v) {
		swap(st[id].mn,st[id].mx);
		st[id].lazy^=1;
		return;
	}
	int mid=(l+r)/2;
	down(id);
	update1(id*2,l,mid,u,v);
	update1(id*2+1,mid+1,r,u,v);
	st[id]=mer(st[id*2],st[id*2+1]);
}
void update2(int id,int l,int r,int pos,int val) {
	if(l>pos||r<pos) return;
	if (l==r) {
		st[id].mx=val;
		st[id].mn=val;
		return;
	}
	int mid=(l+r)/2;
	down(id);
	update2(id*2,l,mid,pos,val);
	update2(id*2+1,mid+1,r,pos,val);
	st[id]=mer(st[id*2],st[id*2+1]);
}
int get(int id,int l,int r,int u,int v) {
	if (u>r||l>v||u>v) return -inf;
	if (u<=l&&r<=v) {
		return st[id].mx;
	}
	int mid=(l+r)/2;
	down(id);
	return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
void Update(int u,int v) {
	while (ChainID[u]!=ChainID[v]) {
		update1(1,1,n,pos[ChainHead[ChainID[u]]],pos[u]);
		//cout<<"UPD1 "<<pos[ChainHead[ChainID[u]]]<<' '<<pos[u]<<endl;
		u=par[ChainHead[ChainID[u]]];
	}
	update1(1,1,n,pos[v]+1,pos[u]);
	//cout<<"UPD1 "<<pos[v]+1<<' '<<pos[u]<<endl;
}
int Query(int u,int v) {
	int ans=-inf;
	while (ChainID[u]!=ChainID[v]) {
		ans=max(ans,get(1,1,n,pos[ChainHead[ChainID[u]]],pos[u]));
		//cout<<"QUERY "<<pos[ChainHead[ChainID[u]]]<<' '<<pos[u]<<endl;
		u=par[ChainHead[ChainID[u]]];
	}
	ans=max(ans,get(1,1,n,pos[v]+1,pos[u]));
	//cout<<"QUERY "<<pos[v]+1<<' '<<pos[u]<<endl;
	return ans;
}
void solve() {
	dfs(1);
	hld(1);
	build(1,1,n);
	string s;
	while (cin>>s) {
		if (s=="DONE") return;
		if (s=="CHANGE") {
			int i,val;
			cin>>i>>val;
			int u=edge[i].first,v=edge[i].second;
			if (v==par[u]) update2(1,1,n,pos[u],val);
			else update2(1,1,n,pos[v],val);
		} else if (s=="NEGATE") {
			int a,b;
			cin>>a>>b;
			int lca=LCA(a,b);
			Update(a,lca);
			Update(b,lca);
		} else {
			int a,b;
			cin>>a>>b;
			if (a==b) {
				cout<<0<<'\n';
				continue;
			} 
			int lca=LCA(a,b);
			cout<<max(Query(a,lca),Query(b,lca))<<'\n';
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    int t;
    cin>>t;
    while (t--) {
    	cin>>n;
    	adj.clear();
    	adj.resize(n+1);
    	for (int i=1;i<n;i++) {
    		int u,v,w;
    		cin>>u>>v>>w;
    		edge[i]={u,v};
    		adj[u].push_back({v,w});
    		adj[v].push_back({u,w});
    	}
    	solve();
    }
}