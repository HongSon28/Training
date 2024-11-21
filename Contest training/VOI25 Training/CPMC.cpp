#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,q;
struct ed{
	int u,v,a,b;
};
vector<ed>vc;
namespace sub123{
	bool check() {
		if (n<=2000&&m<=2000) return true;
		if (q==1) return true;
		return false;
	}
	struct edge{
		int v,a,b;
	};
	vector<edge>adj[N+5];
	struct dat {
		int u;
		long long d;
		bool operator < (const dat &other) const {
			return d<other.d;
		}
	};
	priority_queue<dat>pq;
	long long d[N+5];
	void dij(long long t) {
		for (int i=1;i<n;i++) d[i]=-1;
		d[n]=t;
		pq.push({n,t});
		while (!pq.empty()) {
			int u=pq.top().u;
			long long du=pq.top().d;
			pq.pop();
			if (du!=d[u]) continue;
			for (auto [v,a,b]:adj[u]) {
				if (b>du) continue;
				if (d[v]<a) {
					d[v]=a;
					pq.push({v,d[v]});
				}
			}
		}
		cout<<d[1]<<'\n';
	}
	void solve() {
		for (auto [u,v,a,b]:vc) adj[v].push_back({u,a,b});
		while (q--) {
			long long t;
			cin>>t;
			dij(t);
		}
	}
}
int main() {
	freopen("CPMC.INP","r",stdin);
	freopen("CPMC.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=m;i++){
    	int u,v,a,b;
    	cin>>u>>v>>a>>b;
    	vc.push_back({u,v,a,b});
    }
    cin>>q;
    sub123::solve();
}