#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int p[N+5],d[N+5];
long long w[N+5];
vector<int>adj[N+5];
long long dp[N+5][2];
void dfs1(int u) {
	vector<pair<long long,int>>c0,c1;
	for (auto v:adj[u]) {
		dfs1(v);
		c0.push_back({dp[v][1]-dp[v][0],v});
		c1.push_back({dp[v][0]-dp[v][1],v});
	} 
	sort(c0.rbegin(),c0.rend());
	sort(c1.rbegin(),c1.rend());
	dp[u][0]=-w[u];
	dp[u][1]=w[u];
	for (int i=0;i<d[u];i++) {
		dp[u][0]+=dp[c0[i].second][1];
		dp[u][1]+=dp[c1[i].second][0];
	}
	for (int i=d[u];i<(int)c0.size();i++) {
		dp[u][0]+=dp[c0[i].second][0];
		dp[u][1]+=dp[c1[i].second][1];
	}
}
void dfs2(int u) {
	vector<pair<long long,int>>c0,c1;
	for (auto v:adj[u]) {
		dfs2(v);
		c0.push_back({dp[v][1]-dp[v][0],v});
		c1.push_back({dp[v][0]-dp[v][1],v});
	} 
	sort(c0.begin(),c0.end());
	sort(c1.begin(),c1.end());
	dp[u][0]=w[u];
	dp[u][1]=-w[u];
	for (int i=0;i<d[u];i++) {
		dp[u][0]+=dp[c0[i].second][1];
		dp[u][1]+=dp[c1[i].second][0];
	}
	for (int i=d[u];i<(int)c0.size();i++) {
		dp[u][0]+=dp[c0[i].second][0];
		dp[u][1]+=dp[c1[i].second][1];
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=2;i<=n;i++) {
    	cin>>p[i];
    	adj[p[i]].push_back(i);
    }	
    for (int i=1;i<=n;i++) cin>>w[i];
    for (int i=1;i<=n;i++) cin>>d[i];
    dfs1(1);
    long long res=max(dp[1][0],dp[1][1]);
    res=max(res,abs(min(dp[1][0],dp[1][1])));
    cout<<res;
}