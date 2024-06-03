#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n;
vector<vector<int>>adj(N+5);
int res=N+5,cnt;
int dfs(int u,int par) {
	int cur=0;
	for (int i=0;i<(int)adj[u].size();i++) {
		int v=adj[u][i];
		if (v==par) continue;
		cur=max(cur,dfs(v,u));
	}
	return cur+1;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<n;i++){
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    for (int i=1;i<=n;i++) {
    	int temp=dfs(i,0);
    	if (temp==res) cnt++;
    	else if (temp<res) {
    		res=temp;
    		cnt=1;
    	}
    }
    cout<<cnt<<' '<<res-1;
}