#include<bits/stdc++.h>
using namespace std;
const int N=1e5,msk=12;
int n,m,k;
int inf=1e8;
int p[msk],doc[N+5],f[N+5];
int c[N+5],d[N+5],mincost[(1<<msk)],dp[(1<<msk)];
vector<vector<int>>adj(N+5),adj2(N+5);
int low[N+5],num[N+5],label[N+5],in[N+5];
bool del[N+5];
int scc,timer;
stack<int>st;
vector<pair<int,int>>vc;
void dfs_scc(int u) {
    num[u]=low[u]=++timer;
    st.push(u);
    for (auto v:adj[u]) {
        if (del[v]) continue;
        if (!num[v]) {
            dfs_scc(v);
            low[u]=min(low[u],low[v]);
        } else low[u]=min(low[u],num[v]);
    }
    if (low[u]==num[u]) {
        scc++;
        d[scc]=inf;
        int v;
        do {
            v=st.top();
            st.pop();
            del[v]=true;
            label[v]=scc;
            d[scc]=min(d[scc],c[v]);
            f[scc]|=doc[v];
        } while (v!=u);
    }
}
bool vis[N+5];
void dfs(int u) {
	vis[u]=true;
	for (auto v:adj2[u]) {
		if (!vis[v]) dfs(v);
		f[u]|=f[v];
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>k>>m;
	for (int i=0;i<k;i++) {
		cin>>p[i];
		doc[p[i]]|=(1<<i);
	}
	for (int i=1;i<=n;i++) cin>>c[i];
	for (int i=1;i<=m;i++) {
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	for (int i=1;i<=n;i++) {
		if (!num[i]) dfs_scc(i);
	}
	for (int i=1;i<=n;i++) {
		if (!label[i]) {
			label[i]=++scc;
			d[scc]=c[i];
			f[scc]=doc[i];
		}
	}
	for (int u=1;u<=n;u++) {
		for (auto v:adj[u]) {
			if (label[u]!=label[v]) {
				adj2[label[u]].push_back(label[v]);
				in[label[v]]++;
			}
		}
	}
	for (int i=1;i<=scc;i++) {
		if (in[i]==0) dfs(i);
	}
	for (int i=0;i<(1<<k);i++) mincost[i]=dp[i]=inf;
	for (int i=1;i<=scc;i++) {
		mincost[f[i]]=min(mincost[f[i]],d[i]);
	}
	dp[0]=0;
	for (int i=0;i<(1<<k);i++) {
		if (mincost[i]==inf) continue;
		for (int bit=0;bit<(1<<k);bit++) {
			dp[bit|i]=min(dp[bit|i],dp[bit]+mincost[i]);
		}
	}
	cout<<dp[(1<<k)-1];
}