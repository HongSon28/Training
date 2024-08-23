#include<bits/stdc++.h>
using namespace std;
const int N=5e3;
int n;
int a[N+5];
int dp[N+5][N*2+5],mn[N*2+5],inf=1e9;
vector<int>adj[N+5];
vector<int>p;
bool pr[N*2+5];
void seive() {
	memset(pr,true,sizeof(pr));
	for (int i=2;i<=N*2;i++) {
		if (pr[i]) {
			p.push_back(i);
			for (int j=i*i;j<=N*2;j+=i) pr[j]=false;
		}
	}
}
void dfs(int u,int par) {
	for (int i=1;i<=2*N;i++) dp[u][i]=(i!=a[u])*i;
	for (auto v:adj[u]) {
		if (v==par) continue;
		dfs(v,u);
	}
	for (auto x:p) {
		for (int i=x;i<=N*2;i+=x) dp[u][x]=min(dp[u][x],dp[u][i]);
	}
	for (int i=1;i<=2*N;i++) mn[i]=inf;
	for (auto x:p) {
		for (int i=x;i<=N*2;i+=x) mn[i]=min(mn[i],dp[u][x]);
	}
	for (int i=2;i<=2*N;i++) dp[par][i]+=mn[i];
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    seive();
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<n;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }	
    dfs(1,0);
    int res=inf;
    for (int i=2;i<=2*N;i++) res=min(res,dp[1][i]);
    cout<<res;
}