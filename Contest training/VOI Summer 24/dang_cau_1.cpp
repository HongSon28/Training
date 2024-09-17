#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n;
int base=7;
vector<int>adj1[N+5],adj2[N+5];
long long mod=1e9+7;
long long power(long long x, long long n) {
    long long res=1;
    while (n>0) {
    	if (n&1) res=res*x%mod;
    	n/=2;
    	res=res*res%mod;
    }
    return res;
}
long long dfs1(int u,int par) {
	long long ans=1;
	for (auto v:adj1[u]) {
		if (v==par) continue;
		ans+=power(base,dfs1(v,u));
		if (ans>=mod) ans-=mod;
	}
	return ans;
}
long long dfs2(int u,int par) {
	long long ans=1;
	for (auto v:adj2[u]) {
		if (v==par) continue;
		ans+=power(base,dfs2(v,u));
		if (ans>=mod) ans-=mod;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		cin>>n;
		for (int i=1;i<=n;i++) {
			adj1[i].clear();
			adj2[i].clear();
		}
		for (int i=1;i<n;i++) {
			int u,v;
			cin>>u>>v;
			adj1[u].push_back(v);
			adj1[v].push_back(u);
		}
		for (int i=1;i<n;i++) {
			int u,v;
			cin>>u>>v;
			adj2[u].push_back(v);
			adj2[v].push_back(u);
		}
		if (dfs1(1,0)!=dfs2(1,0)) cout<<"NO"<<'\n';
		else cout<<"YES"<<'\n';
	}
}