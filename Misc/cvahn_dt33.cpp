#include<bits/stdc++.h>
using namespace std;
const int N=2000;
int n,res,m1,m2;
vector<vector<int>>adj(N+5);
vector<pair<int,int>>edge;
int dfs(int u,int par,int root) {
	vector<int>cur;
	for (auto v:adj[u]) {
		if (v==par) continue;
		cur.push_back(dfs(v,u,root));
	}
	sort(cur.rbegin(),cur.rend());
	if (root==1) {
		if (cur.size()>=2) m1=max(m1,cur[0]+1+cur[1]+1);
		else if (!cur.empty()) m1=max(m1,cur[0]+1);
	} else {
		if (cur.size()>=2) m2=max(m2,cur[0]+1+cur[1]+1);
		else if (!cur.empty()) m2=max(m2,cur[0]+1);
	}
	if (cur.empty()) return 0;
	return cur[0]+1;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<n;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    	edge.push_back({u,v});
    }
    for (auto [u,v]:edge) {
    	m1=m2=0;
    	dfs(u,v,1);
    	dfs(v,u,2);
    	res=max(res,m1*m2);
    }
    cout<<res;
}