#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
long long a[N+5],res;
int b[N+5],c[N+5];
vector<int>adj[N+5];
int dfs(int u,int par) {
	a[u]=min(a[u],a[par]);
	long long c0=0,c1=0;
	for (auto v:adj[u]) {
		if (v==par) continue;
		int t=dfs(v,u);
		if (t>0) c1+=t;
		else c0-=t;
	}
	if (b[u]==1&&c[u]==0) c1++;
	else if (b[u]==0&&c[u]==1) c0++;
	long long t=min(c0,c1);
	res+=t*2*a[u];
	return c1-c0;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
    a[0]=(int)1e9+7;
    for (int i=1;i<n;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }	
    if (dfs(1,0)!=0) cout<<-1;
    else cout<<res;
}