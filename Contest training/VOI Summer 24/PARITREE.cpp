#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n,q,res;
int mod=1e9+7;
vector<pair<int,int>>adj[N+5];
bool vis[N+5];
int col[N+5];
int power(int k){
	int ans=1;
	for (int i=1;i<=k;i++) {
		ans*=2;
		if (ans>=mod) ans-=mod;
	}
	return ans;
}
bool bfs(int x) {
	vis[x]=true;
	queue<int>q;
	q.push(x);
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		for (auto [v,c]:adj[u]) {
			if (!vis[v]) {
				vis[v]=1;
				q.push(v);
				if (c) col[v]=1-col[u];
				else col[v]=col[u];
			} else {
				if (c&&col[v]!=1-col[u]) return false;
				if (!c&&col[v]!=col[u]) return false; 
			}
		}
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		cin>>n>>q;
		res=0;
		for (int i=1;i<=n;i++) {
			adj[i].clear();
			vis[i]=false;
			col[i]=0;
		}
		for (int i=1;i<n;i++) {
			int u,v;
			cin>>u>>v;
		}
		for (int i=1;i<=q;i++) {
			int u,v,c;
			cin>>u>>v>>c;
			adj[u].push_back({v,c});
			adj[v].push_back({u,c});
		}
		for (int i=1;i<=n;i++) {
			if (vis[i]) continue;
			if (!bfs(i)) {
				res=-1;
				break;
			}
			res++;
		}
		if (res==-1) cout<<0<<'\n';
		else cout<<power(res-1)<<'\n';
	}
}