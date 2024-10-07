#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n,m,h;
bool a[N+5];
vector<pair<int,long long>>adj[N+5];
long long d[3][3][N+5],inf=1e18;
struct dat{
	int u,fac;
	long long d;
	bool operator < (const dat &other) const {
		return d>other.d;
	}
};
priority_queue<dat>pq;
void dij(int st,int id){
	for (int i=1;i<=n;i++)
		d[id][1][i]=d[id][2][i]=inf;
	if (a[st]) {
		d[id][2][st]=0;
		pq.push({st,2,0});
	} else {
		d[id][1][st]=0;
		pq.push({st,1,0});
	}
	while (!pq.empty()) {
		int u=pq.top().u,fac=pq.top().fac;
		long long du=pq.top().d;
		pq.pop();
		if (du!=d[id][fac][u]) continue;
		for (auto [v,w]:adj[u]) {
			if (a[v]) {
				if (d[id][2][v]>du+w/fac) {
					d[id][2][v]=du+w/fac;
					pq.push({v,2,d[id][2][v]});
				}  
			} else {
				if (d[id][fac][v]>du+w/fac) {
					d[id][fac][v]=du+w/fac;
					pq.push({v,fac,d[id][fac][v]});
				} 
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n>>m>>h;
    	for (int i=1;i<=n;i++) {
    		adj[i].clear();
    		a[i]=false;
    	}
    	for (int i=1;i<=h;i++) {
    		int temp;
    		cin>>temp;
    		a[temp]=true;
    	}
    	for (int i=1;i<=m;i++) {
    		int u,v,w;
    		cin>>u>>v>>w;
    		adj[u].push_back({v,w});
    		adj[v].push_back({u,w});
    	}
    	dij(1,1);
    	dij(n,2);
    	long long res=inf;
    	for (int i=1;i<=n;i++) {
    		long long d1=min(d[1][1][i],d[1][2][i]);
    		long long d2=min(d[2][1][i],d[2][2][i]);
    		res=min(res,max(d1,d2));
    	}
    	if (res==inf) cout<<-1<<'\n';
    	else cout<<res<<'\n';
    }
}