#include<bits/stdc++.h>
using namespace std;
const int N=5e4;
int n,q,k;
struct edge{
	int v,g,c;
};
vector<edge>adj[N+5];
namespace sub1{
	int x,y;
	long long dfs(int u,int par,long long cur) {
		if (u==y) return cur;
		long long res=-1;
		for (auto [v,g,c]:adj[u]) {
			if (v==par) continue;
			long long temp=cur%k,val=0;
			if (temp>g) val=k-temp;
			res=max(res,dfs(v,u,cur+val+c));
		}
		return res;
	}
	void solve() {
		while (q--) {
			cin>>x>>y;
			cout<<dfs(x,0,0)<<'\n';
		}
	}
}
int main() {
	freopen("LIGHT.INP","r",stdin);
	freopen("LIGHT.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>q>>k;
    for (int u=2;u<=n;u++) {
    	int v,g,c;
    	cin>>v>>g>>c;
    	adj[u].push_back({v,g,c});
    	adj[v].push_back({u,g,c});
    }
    sub1::solve();
}