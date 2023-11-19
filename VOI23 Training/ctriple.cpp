#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
vector<vector<int>>adj(N+5);
long long mod=1e9+7,res,a[N+5],w[N+5],sum[N+5],d[N+5];
map<long long,long long>s[N+5];
void seive() {
	iota(d,d+N+5,0);
    for (int i=2; i*i<=N;i++) {
        if (d[i]==i)
            for (int j=i*i;j<=N;j+=i)
                if (i<d[j]) d[j]=i;
    }
}
long long C2(long long x) {
	x%=mod;
	return x*(x-1)/2%mod;
}
void dfs(int u,int par) {
	for (auto v:adj[u]) {
		if (v==par) continue;
		dfs(v,u);
		if (s[u].size()>s[v].size()) swap(s[u],s[v]);
		for (auto i=s[v].begin();i!=s[v].end();i++) {
			s[u][i->first]+=i->second;
		}
	}
	long long t=a[u];
	while (t>1) {
		long long div=d[t];
		s[u][div]++;
		while (t%div==0) t/=div;
	}
	for (auto i=s[u].begin();i!=s[u].end();i++) {
		long long p=i->first,temp=i->second;
		w[u]+=C2(temp)*(sum[p]-temp);
		w[u]%=mod;
		w[u]+=temp*C2(sum[p]-temp);
		w[u]%=mod;
		//cout<<u<<' '<<p<<' '<<temp<<' '<<sum[p]<<' '<<w[u]<<endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	seive();
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		long long t=a[i];
		while (t>1) {
			long long div=d[t];
			sum[div]++;
			while (t%div==0) t/=div;
		}
	}
	for (int i=1;i<n;i++) {
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0);
	for (int i=2;i<=n;i++) {
		res+=w[i];
		res%=mod;
	}
	cout<<res;
}
