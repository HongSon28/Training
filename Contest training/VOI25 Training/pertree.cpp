#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
vector<int>adj[N+5];
long long mod=1e9+7;
long long dp[N+5],f[N+5],sz[N+5],szf[N+5],g[N+5],inv[N+5],p[N+5],res;
long long power(long long x,long long y) {
	if (y==0) return 1;
	if (y==1) return x%mod;
	long long ans=power(x,y/2);
	ans=(ans*ans)%mod;
	if (y&1) ans=ans*x%mod;
	return ans;
}
void prep() {
	g[0]=1;
	for (int i=1;i<=N;i++) g[i]=g[i-1]*i%mod;
	inv[N]=power(g[N],mod-2);
	for (int i=N-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
long long C(int k,int n) {
	return g[n]*inv[k]%mod*inv[n-k]%mod;
}
void dfs1(int u,int par) {
	p[u]=par;
	sz[u]=1;
	for (auto v:adj[u]) {
		if (v==par) continue;
		dfs1(v,u);
		sz[u]+=sz[v];
	}
	long long sum=sz[u]-1;
	dp[u]=1;
	for (auto v:adj[u]) {
		if (v==par) continue;
		dp[u]*=dp[v]*C(sz[v],sum)%mod;
		sum-=sz[v];
		dp[u]%=mod;
	}
}
void dfs2(int u,int par) {
	f[u]=1;
	if (par!=0) {
		szf[u]=1;
		vector<pair<long long,long long>>vc;
		for (auto v:adj[par]) {
			if (v==u) continue;
			if (v!=p[par]) {
				vc.push_back({dp[v],sz[v]});
				szf[u]+=sz[v];
			} else {
				vc.push_back({f[par],szf[par]});
				szf[u]+=szf[par];
			}
		}
		long long sum=szf[u]-1;
		for (auto [val,sz]:vc) {
			f[u]*=val*C(sz,sum)%mod;
			f[u]%=mod;
			sum-=sz;
		} 
		//cout<<f[u]<<endl;
	}
	for (auto v:adj[u]) {
		if (v!=par) dfs2(v,u);
	}
}
void dfs3(int u,int par) {
	int sum=n-1;
	long long ans=f[u];
	for (auto v:adj[u]) {
		if (v==par) continue;
		ans*=dp[v]*C(sz[v],sum)%mod;
		ans%=mod;
		sum-=sz[v];
	}
	res+=ans;
	//cout<<u<<' '<<f[u]<<' '<<ans<<endl;
	if (res>=mod) res-=mod;
	for (auto v:adj[u]) {
		if (v!=par) dfs3(v,u);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    prep();	
    cin>>n;
    for (int i=1;i<n;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    dfs1(1,0);
    f[0]=1;
    dfs2(1,0);
    dfs3(1,0);
    cout<<res;
}