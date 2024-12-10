#include<bits/stdc++.h>
using namespace std;
const int N=1e5,SQ=316;
int n,q;
int a[N+5],cnt[N+5];
vector<int>adj[N+5];
int p[N+5],h[N+5];
long long d[N+5],c[N+5];
struct query{
	int id,type;
};
vector<query>v1[N+5];
vector<pair<int,int>>v2[N+5];
vector<int>idc[N+5];
int res[N+5];
void dfs1(int u,int par) {
	p[u]=par;
	h[u]=h[par]+1;
	for (auto v:adj[u]) {
		if (v!=par) dfs1(v,u); 
	}
}
void dfs2(int u,int col) {
	d[u]=d[p[u]]+(a[u]==col);
	for (auto [v,id]:v2[u]) {
		long long temp=d[u]-d[v];
		res[id]-=temp*(temp-1);
	}
	for (auto v:adj[u]) {
		if (v!=p[u]) dfs2(v,col);
	}
}
struct Fenwick{
	long long bit[N+5];
	void update(int idx,int val) {
		while (idx<=n) {
			bit[idx]+=val;
			idx+=(idx&(-idx));
		}
	}
	long long get(int idx) {
		long long ans=0;
		while (idx>0) {
			ans+=bit[idx];
			idx-=(idx&(-idx));
		}
		return ans;
	}
} tree;
bool vis[N+5];
void dfs3(int u) {
	for (auto v:idc[a[u]]) {
		if (vis[v]) tree.update(h[v],1);
	}	
	vis[u]=true;
	for (auto [v,id]:v2[u]) res[id]-=2*tree.get(h[u])-2*tree.get(h[v]);
	for (auto v:adj[u]) {
		if (v!=p[u]) dfs3(v);
	}
	vis[u]=false;
	for (auto v:idc[a[u]]) {
		if (vis[v]) tree.update(h[v],-1);
	}	
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	cnt[a[i]]++;
    }
    for (int i=1;i<n;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    dfs1(1,0);
    for (int i=1;i<=q;i++) {
    	int s,t;
    	cin>>s>>t;
    	long long temp=h[s]-h[p[t]];
    	res[i]=temp*(temp-1);
    	v1[s].push_back({i,1});
    	v1[p[t]].push_back({i,-1});
    	v2[s].push_back({p[t],i});
    }
	for (int i=1;i<=n;i++) {
		if (cnt[i]>=SQ) dfs2(1,i);
	}
	memset(d,0,sizeof(d));
	for (int i=1;i<=n;i++) {
		if (cnt[a[i]]<SQ) idc[a[i]].push_back(i);
	}
	dfs3(1);
	for (int i=1;i<=q;i++) cout<<res[i]<<'\n';
}