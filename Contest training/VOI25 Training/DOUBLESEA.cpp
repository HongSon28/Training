#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,q;
vector<int>adj[N+5];
int l[N+5],v[N+5];
int f[N+5];
int cur;
int col[N+5];
bool query[N+5];
vector<int>vc[N+5];
bool vis[N+5];
queue<pair<int,int>>qu;
void bfs(int c,int dist) {
	for (int i=1;i<=n;i++) vis[i]=false;
	for (auto x:vc[c]) {
		vis[x]=true;
		qu.push({x,0});
	}
	while (!qu.empty()) {
		int u=qu.front().first,d=qu.front().second;
		qu.pop();
		if (d==dist) continue;
		for (auto v:adj[u]) {
			if ((col[v]!=0&&col[v]!=c)||vis[v]) continue;
			vis[v]=true;
			col[v]=c;
			vc[c].push_back(v);
			cur-=query[v];
			qu.push({v,d+1});
		}
	}
}
void solve() {
	int k,m;
	cin>>k>>m;
	for (int i=1;i<=n;i++) {
		query[i]=false;
		vc[i].clear();
		col[i]=0;
	}
	for (int i=1;i<=k;i++) {
		cin>>l[i]>>v[i];
		col[l[i]]=i;
		vc[i].push_back(l[i]);
	}
	cur=m;
	for (int i=1;i<=m;i++) {
		cin>>f[i];
		query[f[i]]=true;
		if (col[f[i]]>0) cur--;
	}
	int tim=10;
	while (cur>0&& tim-- >0) {
		for (int i=1;i<=k;i++) {
			bfs(i,v[i]);
			if (cur==0) break;
		}
	}
	for (int i=1;i<=m;i++) cout<<col[f[i]]<<' ';
	cout<<'\n';
}
int main() {
	freopen("DOUBLESEA.INP","r",stdin);
	freopen("DOUBLESEA.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<n;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    cin>>q;
    while (q--) solve();
}