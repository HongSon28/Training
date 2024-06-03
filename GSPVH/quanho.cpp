#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
vector<pair<int,long long>>adj[N+5];
int p[N+5];
long long d[N+5],w[N+5],inf=1e16;
struct dat{
	int u;
	long long d,w;
	bool operator < (const dat &other) const {
		if (d!=other.d) return d>other.d;
		return w<other.w;
	}
};
priority_queue<dat>pq;
int main() {
	freopen("quanho.inp","r",stdin);
	freopen("quanho.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>p[i];
		d[i]=inf;
	}
	cin>>m;
	for (int i=1;i<=m;i++) {
		int u,v,c;
		cin>>u>>v>>c;
		adj[u].push_back({v,c});
		adj[v].push_back({u,c});
	}
	d[1]=0;
	w[1]=p[1];
	pq.push({1,0,p[1]});
	while (!pq.empty()) {
		dat temp=pq.top();
		pq.pop();
		int u=temp.u;
		long long du=temp.d,wu=temp.w;
		if (du!=d[u]||wu!=w[u]) continue;
		for (auto [v,c]:adj[u]) {
			if (d[v]>du+c) {
				d[v]=du+c;
				w[v]=wu+p[v];
				pq.push({v,d[v],w[v]});
			} else if (d[v]==du+c) {
				if (w[v]<wu+p[v]) {
					w[v]=wu+p[v];
					pq.push({v,d[v],w[v]});
				}
			}
		}
	}
	if (d[n]==inf) cout<<"impossible";
	else cout<<d[n]<<' '<<w[n];
}