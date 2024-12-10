#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n,m;
vector<int>adj[N+5];
int res;
int low[N+5],num[N+5],tim;
bool del[N+5];
stack<int>st;
void dfs(int u) {
	low[u]=num[u]=++tim;
	st.push(u);
	for (auto v:adj[u]) {
		if (del[v]) continue;
		if (!num[v]) {
			dfs(v);
			low[u]=min(low[u],low[v]);
		} else low[u]=min(low[u],num[v]);
	}
	if (low[u]==num[u]) {
		res++;
		int v;
		do {
			v=st.top();
			st.pop();
			del[v]=true;
		} while (v!=u);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    }
    for (int i=1;i<=n;i++) {
    	if (!num[i]) dfs(i);
    }
    cout<<res;
}