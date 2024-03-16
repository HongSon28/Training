#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m,k,mn,mx;
int s[N+5];
vector<vector<pair<int,long long>>>adj(N+5);
struct dat{
	int u;
	long long d;
	bool operator < (const dat &other) const {
		return d>other.d;
	}
};
priority_queue<dat>pq;
long long d[N+5],inf=1e18;
void dij(int s) {
	for (int i=1;i<=n;i++) d[i]=inf;
	d[s]=0;
	pq.push({s,0});
	while (!pq.empty()) {
		int u=pq.top().u;
		long long du=pq.top().d;
		pq.pop();
		if (du!=d[u]) continue;
		for (auto [v,w]:adj[u]) {
			if (d[v]>d[u]+w) {
				d[v]=d[u]+w;
				pq.push({v,d[v]});
			}
		}
	}
}  
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
    	int u,v,w;
    	cin>>u>>v>>w;
    	adj[u].push_back({v,w});
    	adj[v].push_back({u,w});
    }
    cin>>k;
    for (int i=1;i<=k;i++) cin>>s[i];
    dij(s[k]);
    for (int i=1;i<k;i++) {
    	long long wg,cnt=0;
    	//cout<<s[i]<<endl;
    	for (auto [v,w]:adj[s[i]]) {
    		if (v==s[i+1]) wg=w;
    		if (d[s[i]]==d[v]+w) cnt++;
    		//cout<<d[s[i]]<<' '<<d[v]<<' '<<w<<endl;
    	}
    	if (d[s[i+1]]+wg!=d[s[i]]) {
    		mn++;
    		mx++;
    	} else mx+=(cnt>1);
    }
    cout<<mn<<' '<<mx;
}