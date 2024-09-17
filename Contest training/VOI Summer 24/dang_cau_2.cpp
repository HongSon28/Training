#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n;
int base=7;
vector<int>adj1[N+5],adj2[N+5];
int sz1[N+5],sz2[N+5];
vector<int>cen1,cen2;
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
void count1(int u,int par) {
	sz1[u]=1;
	for (auto v:adj1[u]) {
		if (v==par) continue;
		count1(v,u);
		sz1[u]+=sz1[v];
	}
}
void count2(int u,int par) {
	sz2[u]=1;
	for (auto v:adj2[u]) {
		if (v==par) continue;
		count2(v,u);
		sz2[u]+=sz2[v];
	}
}  
void findcen1(int u,int par) {
	bool iscen=true;
	for (auto v:adj1[u]) {
		if (v==par) continue;
		findcen1(v,u);
		if (sz1[v]>n/2) iscen=false;
	}
	if (n-sz1[u]>n/2) iscen=false;
	if (iscen) cen1.push_back(u);
}
void findcen2(int u,int par) {
	bool iscen=true;
	for (auto v:adj2[u]) {
		if (v==par) continue;
		findcen2(v,u);
		if (sz2[v]>n/2) iscen=false;
	}
	if (n-sz2[u]>n/2) iscen=false;
	if (iscen) cen2.push_back(u);
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
			sz1[i]=sz2[i]=0;
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
		cen1.clear(),cen2.clear();
		count1(1,0);
		count2(1,0);
		findcen1(1,0);
		findcen2(1,0);
		bool flag=false;
		for (auto i:cen1) {
			for (auto j:cen2) {
				if (dfs1(i,0)==dfs2(j,0)) {
					flag=true;
					break;
				}
			}
		}
		if (flag) cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
	}
}