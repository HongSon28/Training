#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m,q;
int s[N+5],t[N+5],w[N+5];
vector<int>adj[N+5];
bool vis[N+5];
void bfs() {
	for (int i=1;i<=n;i++) w[i]=n+1;
	w[n]=0;
	queue<int>q;
	q.push(n);
	vis[n]=true;
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		for (auto v:adj[u]) {
			if (vis[v]) continue;
			vis[v]=true;
			w[v]=w[u]+1;
			q.push(v);
		}
	}
}
multiset<int>st;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m>>q;
	for (int i=1;i<=m;i++) {
		int u,v;
		cin>>u>>v;
		adj[v].push_back(u);
	}
	bfs();
	for (int i=1;i<=n;i++) {
		cin>>s[i];
		t[s[i]]=i-1;
	}
	for (int i=1;i<=n;i++) st.insert(t[i]+w[i]);
	while (q--) {
		int u,v;
		cin>>u>>v;
		st.erase(st.lower_bound(t[s[u]]+w[s[u]]));
		st.erase(st.lower_bound(t[s[v]]+w[s[v]]));
		swap(s[u],s[v]);
		t[s[u]]=u-1;
		t[s[v]]=v-1;
		st.insert(t[s[u]]+w[s[u]]);
		st.insert(t[s[v]]+w[s[v]]);
		int res=*st.begin();
		cout<<res<<'\n';
	}
}