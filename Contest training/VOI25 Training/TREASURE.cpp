#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,q;
vector<int>adj[N+5];
int t[N+5],c[N+5];
namespace sub1{
	int cnt[N+5],b[N+5];
	long long res=0;
	void dfs(int u,int par,int tax) {
		for (auto v:adj[u]) {
			if (v==par) continue;
			dfs(v,u,tax);
			cnt[u]+=cnt[v];
		}
		if (t[u]==tax) res=max(res,1ll*cnt[u]*c[u]);
	}
	void solve() {
		while (q--) {
			int type;
			cin>>type;
			if (type==1) {
				int u;
				cin>>u;
				cin>>t[u];
			} else {
				int tax,k;
				cin>>tax>>k;
				memset(cnt,0,sizeof(cnt)); 
				for (int i=1;i<=k;i++) {
					cin>>b[i];
					cnt[b[i]]=1;
				}
				res=0;
				dfs(1,0,tax);
				cout<<res<<'\n';
				for (int i=1;i<=k;i++) cnt[b[i]]=0;
			}
		}
	}
}
int main() {
	freopen("treasure.inp","r",stdin);
	freopen("treasure.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>q;
    for (int i=2;i<=n;i++) {
    	int p;
    	cin>>p;
    	adj[p].push_back(i);
    	adj[i].push_back(p);
    }	
    for (int i=1;i<=n;i++) cin>>t[i];
    for (int i=1;i<=n;i++) cin>>c[i];
    sub1::solve();
}