#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int t,n;
int cur=1;
vector<int>adj[N+5];
int d[N+5],low[N+5];
void dfs(int u,int par) {
	d[u]=d[par]+1;
	low[u]=d[u];
	for (auto v:adj[u]) {
		if (v==par) continue;
		dfs(v,u);
		low[u]=max(low[u],low[v]);
	}
}
struct dat{
	int u,val;
	bool operator < (const dat &other) const {
		return val>other.val;
	}
};
priority_queue<dat>pq;
queue<int>q;
void bfs(int k) {
	//cout<<k<<endl;
	while (!q.empty()&&d[q.front()]!=k) {
		int u=q.front();
		q.pop();
		for (auto v:adj[u]) {
			if (d[v]==k) {
				q.push(v);
				cur++;
				pq.push({v,low[v]});
				//cout<<cur<<' '<<v<<' '<<low[v]<<endl;
			}
		}
	}
	while (!pq.empty()&&pq.top().val<k) {
		//cout<<cur<<' '<<pq.top().u<<' '<<pq.top().val<<endl;
		pq.pop();
		cur--;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		while (!pq.empty()) pq.pop();
		while (!q.empty()) q.pop();
		cin>>n;
		for (int i=1;i<=n;i++) adj[i].clear();
		for (int i=1;i<n;i++) {
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		cur=1;
		int res=1;
		dfs(1,0);
		q.push(1);
		pq.push({1,low[1]});
		for (int i=2;i<=n;i++) {
			bfs(i);
			res=max(res,cur);
		}
		cout<<n-res<<'\n';
	}
}