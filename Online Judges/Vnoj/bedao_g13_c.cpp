#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n;
int par[N+5],p[N+5];
long long sum[N+5],pre[N+5],suf[N+5],mx[N+5],res[N+5];
long long a[N+5];
bool used[N+5];
int find_root(int u) {
	if (par[u]<0) return u;
	return par[u]=find_root(par[u]);
}
void Union(int u,int v) {
	u=find_root(u);
	v=find_root(v);
	par[u]+=par[v];
	par[v]=u;
	mx[u]=max({mx[u],mx[v],suf[u]+pre[v]});
	pre[u]=max(pre[u],sum[u]+pre[v]);
	suf[u]=max(suf[v],suf[u]+sum[v]);
	sum[u]+=sum[v];
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	par[i]=-1;
    	sum[i]=a[i];
    	pre[i]=suf[i]=mx[i]=a[i];
    }
    for (int i=1;i<=n;i++) cin>>p[i];
    res[n+1]=LLONG_MIN;
    for (int i=n;i>=1;i--) {
    	if (used[p[i]+1]) Union(p[i],p[i]+1);
    	if (used[p[i]-1]) Union(p[i]-1,p[i]);
    	res[i]=max(res[i+1],mx[find_root(p[i])]);
    	used[p[i]]=true;
    }
    for (int i=1;i<=n;i++) cout<<res[i]<<'\n';
}