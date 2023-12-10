#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n;
int d[N+5];
vector<vector<pair<int,int>>>adj(N+5);
void dfs(int u) {
	for (auto [v,w]:adj[u]) {
		d[v]=(d[u]^w);
		dfs(v);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<n;i++) {
    	int u,v,w;
    	cin>>u>>v>>w;
    	adj[u].push_back({v,w});
    }	
    dfs(1);
	cout<<d[n];
}