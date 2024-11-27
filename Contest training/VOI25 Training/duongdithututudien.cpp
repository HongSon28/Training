#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
int inf=1e9+5;
vector<pair<int,int>>adj[N+5],adj2[N+5];
queue<int>q;
int d[N+5];
pair<int,int>trace[N+5];
bool vis[N+5];
vector<int>q1,q2;
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
    d[n]=0;
    q.push(n);
    while (!q.empty()) {
    	int u=q.front();
    	q.pop();
    	for (auto [v,w]:adj[u]) {
    		if (!d[v]&&v!=n) {
    			d[v]=d[u]+1;
    			q.push(v);
    			adj2[v].push_back({u,w});
    			//cout<<d[v]<<' '<<d[u]<<' '<<v<<' '<<u<<' '<<w<<endl;
    		} else if (d[v]==d[u]+1) {
    			adj2[v].push_back({u,w});
    			//cout<<d[v]<<' '<<d[u]<<' '<<v<<' '<<u<<' '<<w<<endl;
    		}
    	}
    }
    q1.push_back(1);
    while (true) {
    	if (q1.size()==1&&q1[0]==n) break;
    	int mn=inf;
    	for (auto u:q1) {
    		for (auto [v,w]:adj2[u]) {
    			mn=min(mn,w);
    		}
    	}
    	for (auto u:q1) {
    		for (auto [v,w]:adj2[u]) {
    			if (!vis[v]&&w==mn) {
    				vis[v]=true;
    				q2.push_back(v);
    				trace[v]={u,w};
    			}
    		}
    	}
    	swap(q1,q2);
    	q2.clear();
    }
    vector<int>res;
    cout<<d[1]<<'\n';
    int cur=n;
    while (cur!=1) {
    	res.push_back(trace[cur].second);
    	cur=trace[cur].first;
    }
    reverse(res.begin(),res.end());
    for (auto x:res) cout<<x<<' ';
}