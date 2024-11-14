#include<bits/stdc++.h>
using namespace std;
const int N=100,M=11000;
int n,m;
int a[N+5][N+5];
int id[N+5][N+5];
int cur,res;
vector<int>adj[M+5];
int vis[M+5],assigned[M+5];
int t;
bool dfs(int u) {
	if (vis[u]!=t) vis[u]=t;
	else return false;
	for (auto v:adj[u]) {
		if (!assigned[v]||dfs(assigned[v])) {
			assigned[v]=u;
			return true;
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=m;j++) cin>>a[i][j];
    }
    for (int i=0;i<=n;i++) {
    	for (int j=0;j<=m;j++) id[i][j]=++cur;
    }
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=m;j++) {
    		if (a[i][j]==1||a[i][j]==3) {
    			adj[id[i][j]].push_back(id[i-1][j-1]);
    			adj[id[i-1][j-1]].push_back(id[i][j]);
    		}
    		if (a[i][j]==2||a[i][j]==3) {
    			adj[id[i-1][j]].push_back(id[i][j-1]);
    			adj[id[i][j-1]].push_back(id[i-1][j]);
    		}
    	}
    }
    for (int i=0;i<=n;i++) {
    	for (int j=0;j<=m;j++) {
    		t++;
    		res+=dfs(id[i][j]);
    	}
    }
    cout<<res/2;
}