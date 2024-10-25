#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,q;
long long v[N+5],st[N*4+5];
vector<int>adj[N+5];
int d[N+5],s[N+5],par[N+5];
void dfs(int u) {
	s[u]=1;
	for (auto v:adj[u]) {
		if (v==par[u]) continue;
		par[v]=u;
		d[v]=d[u]+1;
		dfs(v);
		s[u]+=s[v];	
	}
}
int a[N+5],pos[N+5],chainhead[N+5],chainid[N+5];
int curchain=1,curpos;
void hld(int u) {
	if (!chainhead[curchain]) chainhead[curchain]=u;
	chainid[u]=curchain;
	pos[u]=++curpos;
	a[curpos]=u;	
	int nxt=0;
	for (auto v:adj[u]) {
		if (v==par[u]) continue;
		if (nxt==0||s[nxt]<s[v]) nxt=v;
	}
	//cout<<u<<' '<<curpos<<' '<<curchain<<' '<<nxt<<endl;
	if (nxt) hld(nxt);
	for (auto v:adj[u]) {
		if (v==par[u]||v==nxt) continue;
		curchain++;
		hld(v);
	}
}
void build(int id,int l,int r) {
	if (l==r) {
		st[id]=v[a[l]];
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id]=st[id*2]+st[id*2+1];
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
	st[id]=st[id*2]+st[id*2+1];
}
long long get(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return 0;
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}
int main() { 
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>v[i];
    for (int i=1;i<n;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    dfs(1);
    hld(1);
    build(1,1,n);
    while (q--) {
    	int type,s,x;
    	cin>>type>>s;
    	if (type==1) {
    		cin>>x;
    		update(1,1,n,pos[s],x);
    	} else {
    		long long res=0;
    		while (chainid[s]!=chainid[1]) {
    			//cout<<chainid[s]<<' '<<chainhead[chainid[s]]<<' '<<s<<endl;
    			res+=get(1,1,n,pos[chainhead[chainid[s]]],pos[s]);
    			s=par[chainhead[chainid[s]]];
    		}
    		res+=get(1,1,n,pos[1],pos[s]);
			cout<<res<<'\n';
    	}
    }
}