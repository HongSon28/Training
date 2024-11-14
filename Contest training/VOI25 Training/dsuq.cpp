#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
const int N=1e7;
int n,q,x,y,z,mod;
int par[N+5],mx[N+5],top,res;
pair<int,int>st[N+5];
pair<int,int>query[N+5];
int find_root(int u) {
	if (par[u]<0) return u;
	return par[u]=find_root(par[u]);
}
void Union(int u,int v) {
	if ((u=find_root(u))==(v=find_root(v))) return;
	if (par[u]>par[v]) swap(u,v);
	par[u]+=par[v];
	par[v]=u;
	mx[u]=max(mx[u],mx[v]);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>q>>x>>y>>z>>mod;
    for (int i=1;i<=n;i++) par[i]=-1;
    for (long long i=1;i<=q;i++) {
    	query[i].second=min(i%n+1,i*i%n+1);
    	query[i].first=max(i%n+1,i*i%n+1);
    }
    sort(query+1,query+1+q);
    int pos=1;
    long long cur=x;
    for (int i=1;i<=n;i++) {
    	if (i>=2) cur=(cur*y+z)%mod;
    	mx[i]=cur;
		while (top>0&&st[top].first<=cur) {
			Union(st[top].second,i);
			top--;
		}
		top++;
		st[top]={cur,i};
		while (pos<=q&&query[pos].first==i) {
			res+=mx[find_root(query[pos].second)];
			if (res>=mod) res-=mod;
			pos++;
		}
    }
    cout<<res;
}