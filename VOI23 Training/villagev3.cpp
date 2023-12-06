#include<bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int N=2e5;
long long mod=1e9+7,inf=1e18;
int n,q;
vector<vector<int>>adj(N+5);
int sz[N+5],d[N+5],par[N+5];
vector<long long>prime;
bool p[N+5];
void seive() {
	memset(p,true,sizeof(p));
	prime.push_back(0);
	for (long long i=2;i*i<=N;i++) {
		if (p[i]) {
			for (long long j=i*i;j<=N;j+=i) p[j]=false;
		}
	}
	for (int i=2;i<=N;i++) 
		if (p[i]) prime.push_back(i);
}
void dfs(int u,int p) {
	sz[u]=1;
	for (auto v:adj[u]) {
		if (v==p) continue;
		par[v]=u;
		d[v]=d[u]+1;
		dfs(v,u);
		sz[u]+=sz[v];
	}
}
int ChainHead[N+5],ChainID[N+5],pos[N+5],arr[N+5];
int CurChain=1,curpos=1;
void hld(int u,int p) {
	if (!ChainHead[CurChain]) ChainHead[CurChain]=u;
	ChainID[u]=CurChain;
	pos[u]=curpos;
	arr[curpos]=u;
	curpos++;
	int nxt=0;
	for (auto v:adj[u]) {
		if (v==p) continue;
		if (nxt==0||sz[v]>sz[nxt]) nxt=v;
	}
	if (nxt) hld(nxt,u);
	for (auto v:adj[u]) {
		if (v!=p&&v!=nxt) {
			CurChain++;
			hld(v,u);
		}
	}
}
int Lca(int u,int v) {
	while (ChainID[u]!=ChainID[v]) {
		if (ChainID[u]>ChainID[v]) u=par[ChainHead[ChainID[u]]];
		else v=par[ChainHead[ChainID[v]]];
	}
	if (d[u]<d[v]) return u;
	return v;
}
struct node{
	long long mx,mn,lazy;
};
node mer(node x,node y) {
	node ans;
	ans.lazy=1;
	ans.mx=max(x.mx,y.mx);
	ans.mn=min(x.mn,y.mn);
	return ans;
}
struct Segtree {
	node st[N*4+5];
	void build() {
		for (int i=1;i<=N*4;i++) st[i]={1,1,1};
	}
	void down(int id) {
		long long temp=st[id].lazy;
		if (temp==1) return;
		st[id].lazy=1;
		st[id*2].mx=(st[id*2].mx*temp)%mod;
		st[id*2].mn=(st[id*2].mn*temp)%mod;
		if (st[id*2].mx<st[id*2].mn) swap(st[id*2].mx,st[id*2].mn);
		st[id*2].lazy=(st[id*2].lazy*temp)%mod;
		st[id*2+1].mx=(st[id*2+1].mx*temp)%mod;
		st[id*2+1].mn=(st[id*2+1].mn*temp)%mod;
		if (st[id*2+1].mx<st[id*2+1].mn) swap(st[id*2+1].mx,st[id*2+1].mn);
		st[id*2+1].lazy=(st[id*2+1].lazy*temp)%mod;
	}
	void update(int id,int l,int r,int u,int v,int val) {
		//cout<<id<<' '<<l<<' '<<r<<' '<<u<<' '<<v<<' '<<val<<' '<<prime[val]<<endl;
		if (l>v||r<u) return;
		if (u<=l&&r<=v) {
			st[id].mx=(st[id].mx*prime[val])%mod;
			st[id].mn=(st[id].mn*prime[val])%mod;
			if (st[id].mx<st[id].mn) swap(st[id].mx,st[id].mn);
			st[id].lazy=(st[id].lazy*prime[val])%mod;
			//cout<<id<<' '<<l<<' '<<r<<' '<<st[id].mx<<' '<<st[id].mn<<' '<<st[id].lazy<<endl;
			return;
		}
		down(id);
		int mid=(l+r)/2;
		update(id*2,l,mid,u,v,val);
		update(id*2+1,mid+1,r,u,v,val);
		st[id]=mer(st[id*2],st[id*2+1]);
	}
	node get(int id,int l,int r,int u,int v) {
		if (l>v||r<u) return {-inf,inf,1};
		if (u<=l&&r<=v) return st[id];
		down(id);
		int mid=(l+r)/2;
		return mer(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
	}
} st;
void update(int u,int v,int val) {
	int lca=Lca(u,v);
	while (ChainID[u]!=ChainID[lca]) {
		//cout<<"upd: "<<pos[ChainHead[ChainID[u]]]<<' '<<pos[u]<<' '<<val<<' '<<prime[val]<<endl;
		st.update(1,1,q,pos[ChainHead[ChainID[u]]],pos[u],val);
		u=par[ChainHead[ChainID[u]]];
	}
	while (ChainID[v]!=ChainID[lca]) {
		//cout<<"upd: "<<pos[ChainHead[ChainID[v]]]<<' '<<pos[v]<<' '<<val<<' '<<prime[val]<<endl;
		st.update(1,1,q,pos[ChainHead[ChainID[v]]],pos[v],val);
		v=par[ChainHead[ChainID[v]]];
	}
	if (d[u]<d[v]) {
		st.update(1,1,q,pos[u],pos[v],val);
		//cout<<"upd: "<<pos[u]<<' '<<pos[v]<<' '<<val<<' '<<prime[val]<<endl;
	}
	else {
		st.update(1,1,q,pos[v],pos[u],val);
		//cout<<"upd: "<<pos[v]<<' '<<pos[u]<<' '<<val<<' '<<prime[val]<<endl;
	}
}
void query(int u,int v) {
	int lca=Lca(u,v);
	long long mx=-inf,mn=inf;
	while (ChainID[u]!=ChainID[lca]) {
		node temp=st.get(1,1,q,pos[ChainHead[ChainID[u]]],pos[u]);
		//cout<<pos[ChainHead[ChainID[u]]]<<' '<<pos[u]<<' '<<temp.mx<<' '<<temp.mn<<endl;
		mx=max(mx,temp.mx);
		mn=min(mn,temp.mn);
		u=par[ChainHead[ChainID[u]]];
	}
	while (ChainID[v]!=ChainID[lca]) {
		node temp=st.get(1,1,q,pos[ChainHead[ChainID[v]]],pos[v]);
		//cout<<pos[ChainHead[ChainID[u]]]<<' '<<pos[u]<<' '<<temp.mx<<' '<<temp.mn<<endl;
		mx=max(mx,temp.mx);
		mn=min(mn,temp.mn);
		v=par[ChainHead[ChainID[v]]];
	}
	if (d[u]<d[v]) {
		node temp=st.get(1,1,q,pos[u],pos[v]);
		//cout<<pos[u]<<' '<<pos[v]<<' '<<temp.mx<<' '<<temp.mn<<endl;
		mx=max(mx,temp.mx);
		mn=min(mn,temp.mn);
	} else {
		node temp=st.get(1,1,q,pos[v],pos[u]);
		//cout<<pos[v]<<' '<<pos[u]<<' '<<temp.mx<<' '<<temp.mn<<endl;
		mx=max(mx,temp.mx);
		mn=min(mn,temp.mn);
	}
	//cout<<mx<<' '<<mn<<endl;
	if (mx==mn) cout<<1<<'\n';
	else cout<<0<<'\n';
}
int cur;
unordered_map<int,int>exist;
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
    seive();
    dfs(1,0);
    hld(1,0);
    st.build();
    for (int i=1;i<=q;i++) {
    	int type;
    	cin>>type;
    	if (type==1) {
    		int u,v,t;
    		cin>>u>>v>>t;
    		if (!exist.count(t)) exist[t]=++cur;
    		update(u,v,exist[t]);
    	} else {
    		int u,v;
    		cin>>u>>v;
    		query(u,v);
    	}
    }
    return 0;
}
