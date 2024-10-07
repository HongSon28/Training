#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t;
int n,m;
long long inf=1e18;
long long t0,t1,t2;
long long res;
struct edge{
	int v;
	long long l1,l2;
};
vector<edge>adj[N+5];
vector<int>v;
long long d[3][N+5];
struct dat{
	int u;
	long long d;
	bool operator < (const dat &other) const{
		return d>other.d;
	}
};
priority_queue<dat>pq;
void dij1(int st,int id) {
	for (int i=1;i<=n;i++) d[id][i]=inf;
	d[id][st]=0;
	pq.push({st,0});
	while (!pq.empty()) {
		int u=pq.top().u;
		long long du=pq.top().d;
		pq.pop();
		if (du!=d[id][u]) continue;
		for (auto [v,l1,l2]:adj[u]) {
			if (d[id][v]>d[id][u]+l1) {
				d[id][v]=d[id][u]+l1;
				pq.push({v,d[id][v]});
			}
		}
	}
}
void dij2() {
	for (int i=1;i<=n;i++) d[0][i]=inf;
	for (auto u:v) {
		d[0][u]=d[2][u];
		pq.push({u,d[0][u]});
	}
	while (!pq.empty()) {
		int u=pq.top().u;
		long long du=pq.top().d;
		pq.pop();
		if (du!=d[0][u]) continue;
		for (auto [v,l1,l2]:adj[u]) {
			if (d[0][v]>d[0][u]+l2) {
				d[0][v]=d[0][u]+l2;
				pq.push({v,d[0][v]});
			}
		}
	}
	for (int i=1;i<=n;i++) {
		if (d[1][i]!=0) {
			d[0][i]=min(t0-d[0][i],t1);
			res=max(res,d[0][i]-d[1][i]);
		//cout<<i<<' '<<d[0][i]<<' '<<d[1][i]<<endl;
		} else res=max(res,t0-d[0][i]);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;  
    while (t--) {
    	cin>>n>>m;
    	cin>>t0>>t1>>t2;
    	res=-1;
    	for (int i=1;i<=n;i++) adj[i].clear();
    	for (int i=1;i<=m;i++) {
    		int u,v,l1,l2;
    		cin>>u>>v>>l1>>l2;
    		adj[u].push_back({v,l1,l2});
    		adj[v].push_back({u,l1,l2});
    	}
    	dij1(1,1);
    	dij1(n,2);
    	v.clear();
    	if (d[2][1]<=t0-t2) res=t0-d[2][1];
    	for (int i=1;i<=n;i++) {
    		if (d[2][i]<=t0-t2) {
    			v.push_back(i);
    			//cout<<i<<' '<<d[2][i]<<endl;
    		}
    	}
    	dij2();
    	cout<<res<<'\n';
    }
}