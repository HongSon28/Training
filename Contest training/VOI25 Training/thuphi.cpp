#include<bits/stdc++.h>
using namespace std;
const int N=4000;
int n;
long long a[N+5],inf=1e18;
vector<int>adj[N+5];
long long f[N+5];
vector<pair<long long,int>>vc;
long long dfs(int u,int par,int root) {
	if ((adj[u].size()==1)||(f[u]!=inf&&a[root]!=a[u])) {
		return f[u];
	}
	long long ans=inf;
	for (auto v:adj[u]) {
		if (v==par) continue;
		long long temp=dfs(v,u,root)+a[root];
		ans=min(ans,temp);
		//cout<<u<<' '<<v<<' '<<temp<<endl;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<n;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }	
    for (int i=1;i<=n;i++) {
    	if (adj[i].size()==1) f[i]=-a[i];
    	else {
    		f[i]=inf;
    		vc.push_back({a[i],i});
    	}
    }
    sort(vc.begin(),vc.end());
    for (auto [w,u]:vc) {
    	f[u]=dfs(u,0,u)+1;
    }
    for (int i=1;i<=n;i++) 
    	cout<<f[i]<<' ';
}