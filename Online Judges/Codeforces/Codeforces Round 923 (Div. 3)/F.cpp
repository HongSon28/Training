#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n,m;
vector<vector<pair<int,int>>>adj;
bool vis[N+5];
int b,k,str,en,h[N+5],st[N*4+5],p[N+5];
vector<int>res;
void update(int id,int l,int r,int pos,int val) {
	if (l>pos||r<pos) return;
	if (l==r) {
		st[id]=val;
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos,val);
	update(id*2+1,mid+1,r,pos,val);
	st[id]=min(st[id*2],st[id*2+1]);
}
int get(int id,int l,int r,int u,int v) {
	if (u>r||v<l) return 1e9;
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
void dfs(int u,int par) {
	vis[u]=true;
	for (auto [v,w]:adj[u]) {
		if (v==par) continue;
		if (vis[v]) {
			int cur=min(w,get(1,1,n,h[v],h[u]-1));
			if (cur<b) {
				b=cur;
				str=v,en=u;
				res.clear();
				res.push_back(en);
				while (en!=str) {
					en=p[en];
					res.push_back(en);
				}
			}
		} else {
			h[v]=h[u]+1;
			update(1,1,n,h[u],w);
			p[v]=u;
			dfs(v,u);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n>>m;
    	b=1e9;
    	adj.clear();
    	adj.resize(n+1);
    	for (int i=1;i<=n;i++) vis[i]=false;
    	for (int i=1;i<=m;i++) {
    		int u,v,w;
    		cin>>u>>v>>w;
    		adj[u].push_back({v,w});
    		adj[v].push_back({u,w});
    	}
    	for (int i=1;i<=n;i++) {
    		if (!vis[i]) {
    			h[i]=1;
    			dfs(i,0);
    		}
    	}
    	cout<<b<<' '<<res.size()<<'\n';
    	for (auto i:res) cout<<i<<' ';
    	cout<<'\n';
    }
}