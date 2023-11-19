#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,test,sub;
long long t,w[N+5],b[N+5],c[N+5],g[N+5],par[N+5];
vector<vector<int>>adj(N+5);

//sub3
long long mx,r;
multiset<int>dict[N+5];
void dfs(int u,int par) {
	c[u]=1;
	for (auto v:adj[u]) {
		if (v==par) continue;
		dfs(v,u);
		c[u]+=c[v];
	}
	long long k=min(t/w[u],c[u]);
	//cout<<u<<' '<<k<<' '<<b[u]<<endl;
	if (mx<k*k+b[u]) {
		mx=k*k+b[u];
	}
}
vector<int>cur;
bool better(int u) {
	int i=0;
	for (auto t:dict[u]) {
		if (t!=cur[i]) return t<cur[i];
		i++;
		if (i>=(int)cur.size()) break;
	}
	return false;
}
void dfs_solve(int u,int par) {
	for (auto v:adj[u]) {
		if (v==par) continue;
		dfs_solve(v,u);
		if (dict[u].size()<dict[v].size()) {
			swap(dict[u],dict[v]);	
		}
		for (auto t:dict[v]) dict[u].insert(t);
		dict[v].clear();
	} 
	dict[u].insert(g[u]);
	int k=min(t/w[u],c[u]);
	if (k*k+b[u]==mx) {
		//cout<<u<<' '<<r<<endl;
		if (r==0) {
			r=u;
			int i=0;
			for (auto t:dict[u]) {
				cur.push_back(t);
				i++;
				if (i>=k) break;
			}
		}
		if (better(u)) {
			int i=0;
			for (auto t:dict[u]) {
				cur[i]=t;
				i++;
				if (i>=(int)cur.size()) break;
			}
			r=u;
		}
	}
}
void solve3() {
	mx=0;
	r=0;
	cur.clear();
	for (int i=1;i<=n;i++) dict[i].clear();
	dfs(1,0);
	dfs_solve(1,0);
	cout<<mx<<' '<<sqrt(mx-b[r])<<'\n';
	for (auto t:cur) cout<<t<<' ';
	cout<<'\n';
}

//sub12
int val[N+5];
vector<int>temp;
void dfs2(int u) {
	temp.push_back(w[u]);
	for (auto v:adj[u]) {
		if (v==par[u]) continue;
		dfs2(v);
	}
}
void dfs_solve2(int u,int par) {
	for (auto v:adj[u]) {
		if (v==par) continue;
		dfs_solve2(v,u);
		if (dict[u].size()<dict[v].size()) {
			swap(dict[u],dict[v]);	
		}
		for (auto t:dict[v]) dict[u].insert(t);
		dict[v].clear();
	} 
	dict[u].insert(g[u]);
	if (val[u]==mx) {
		int k=sqrt(mx-b[u]);
		if (r==0) {
			r=u;
			int i=0;
			for (auto t:dict[u]) {
				cur.push_back(t);
				i++;
				if (i>=k) break;
			}
		}
		if (better(u)) {
			int i=0;
			for (auto t:dict[u]) {
				cur[i]=t;
				i++;
				if (i>=(int)cur.size()) break;
			}
			r=u;
		}
	}
}
void solve12() {
	mx=0;
	r=0;
	cur.clear();
	for (int i=1;i<=n;i++) dict[i].clear();
	for (int i=1;i<=n;i++) {
		temp.clear();
		dfs2(i);
		sort(temp.begin(),temp.end());
		long long sum=0,k=0;
		while (sum<=t&&k<(int)temp.size()) {
			sum+=temp[k];
			k++;
		}
		if (sum>t) {
			sum-=temp[k];
			k--;
		}
		mx=max(mx,k*k+b[i]);
		val[i]=k*k+b[i];
	}
	dfs_solve2(1,0);
	cout<<mx<<' '<<sqrt(mx-b[r])<<'\n';
	for (auto t:cur) cout<<t<<' ';
	cout<<'\n';
}
int main() {
	freopen("V.INP","r",stdin);
	freopen("V.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>sub>>test;
	while (test--) {
		cin>>n>>t;
		adj.clear();
		adj.resize(n+1);
		for (int i=2;i<=n;i++) {
			cin>>par[i];
			adj[par[i]].push_back(i);
			adj[i].push_back(par[i]);
		}
		for (int i=1;i<=n;i++) cin>>w[i];
		for (int i=1;i<=n;i++) cin>>b[i];
		for (int i=1;i<=n;i++) cin>>g[i];
		if (sub==3) solve3();
		else solve12();
	}
}