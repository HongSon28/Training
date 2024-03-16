#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
long long n,m,k;
vector<vector<pair<long long,long long>>>adj(N+5);
struct dat{
	long long u,w;
	bool operator < (const dat &other) const {
		return w>other.w;
	}
};
priority_queue<dat>pq;
long long res;
long long cnt;
long long vis[N+5];
void solve() {
	pq.push({1,0});
    while (!pq.empty()) {
    	long long u=pq.top().u,w=pq.top().w;
    	pq.pop(); 	
    	if (u==n) {
    		cnt++;
    		res+=w;
    		if (cnt==k) return;
    		continue;
    	}	
    	vis[u]++;
    	if (vis[u]>k+1) continue;
    	for (auto [v,wg]:adj[u]) {
    		pq.push({v,w+wg});
    	}
    }
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>k>>n>>m;
    for (int i=1;i<=m;i++) {
    	long long u,v,w;
    	cin>>u>>v>>w;
    	adj[u].push_back({v,w});
    	adj[v].push_back({u,w});
    }
    solve();
    cout<<res;
}