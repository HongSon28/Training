#include<bits/stdc++.h>
using namespace std;
const int N=5e4;
int n,m,s,d,t,q;
vector<vector<int>>adj(N+5);
bitset<N+5>level[N+5],p[N+5],temp;
bool vis[N+5];
int dist[N+5];
void bfs() {
	queue<int>q;
	q.push(s);
	vis[s]=true;
	level[0].set(s);
	p[s].set(s);
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		for (auto v:adj[u]) {
			if (vis[v]) {
				if (dist[u]+1==dist[v]) p[v]|=p[u];
				continue;
			}
			dist[v]=dist[u]+1;
			level[dist[v]].set(v);
			vis[v]=true;
			p[v]|=p[u];
			p[v].set(v);
			q.push(v);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m>>s;
    for (int i=1;i<=m;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    bfs();
    cin>>q;
    while (q--) {
    	cin>>t>>d;
    	temp=(level[d]&p[t]);
    	if (temp.count()==0) cout<<0<<'\n';
    	else if (temp.count()>1) cout<<-1<<'\n';
    	else cout<<temp._Find_first()<<'\n'; 
    }
}