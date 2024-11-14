#include<bits/stdc++.h>
using namespace std;
const int N=100;
int m,n,p,c;
int q[N+5],t[N+5];
bool a[N+5][N+5];
vector<int>adj[(N+5)*(N+5)];
int vis[(N+5)*(N+5)],assigned[(N+5)*(N+5)],cur;
bool dfs(int u) {
	if (vis[u]==cur) return false;
	vis[u]=cur;
	for (auto v:adj[u]) {
		if (!assigned[v]||dfs(assigned[v])) {
			assigned[v]=u;
			return true;
		}
	}
	return false;
}
bool check(long long lim) {
	cur=0;
	for (int i=1;i<=n*(m+1);i++) {
		adj[i].clear();
		assigned[i]=0;
		vis[i]=0;
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			if (a[j][i]) continue;
			long long tm=(p+q[j]-1)/q[j];
			for (int k=1;k<=n;k++) {
				if ((long long)t[i]+tm*k-1<=lim) {
					adj[i].push_back(j*n+k);
					adj[j*n+k].push_back(i);
					//cout<<i<<' '<<j<<' '<<k<<endl;
				}
			}
		}
	}
	for (int i=1;i<=n;i++) {
		cur++;
		if (!dfs(i)) return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>m>>n>>p>>c;
    for (int i=1;i<=m;i++) cin>>q[i];
    for (int i=1;i<=n;i++) cin>>t[i];
    for (int i=1;i<=c;i++) {
    	int u,v;
    	cin>>u>>v;
    	a[u][v]=true;
    }	
    long long lo=1,hi=1e11,res=-1;
    while (lo<=hi) {
    	long long mid=(lo+hi)/2;
    	if (check(mid)) {
    		hi=mid-1;
    		res=mid;
    	} else lo=mid+1;
    }
    cout<<res;
}