#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n;
int a[N+5];
vector<int>adj[N+5];
int c[3][N+5],res;
void dfs(int u,int par) {
	c[a[u]][u]++;
	for (auto v:adj[u]) {
		if (v==par) continue;
		dfs(v,u);
		c[1][u]+=c[1][v];
		c[2][u]+=c[2][v];
		if ((c[1][v]==c[1][0]&&!c[2][v])||(c[2][v]==c[2][0]&&!c[1][v])) res++;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	c[a[i]][0]++;
    }
    for (int i=1;i<n;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    dfs(1,0);
    cout<<res;
}