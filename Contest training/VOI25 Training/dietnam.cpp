#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
int n,mx,res;
int par[N+5];
int pos[N+5];
int find_root(int u) {
	if (par[u]<0) return u;
	return par[u]=find_root(par[u]);
}
int Union(int u,int v) {
	if ((u=find_root(u))==(v=find_root(v))) return 0;
	if (par[u]>par[v]) swap(u,v);
	par[u]+=par[v];
	par[v]=u;
	return 1;
}
void calc(int x,int y) {
	if (x>N||y>N||x==y) return;
	if (!pos[x]||!pos[y]) return;
	res-=Union(pos[x],pos[y]);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    res=n;
    int t;
    for (int i=1;i<=n;i++) {
    	par[i]=-1;
    	cin>>t;
    	mx=max(mx,t);
    	pos[t]=i;
    }
    mx=(mx*3+1)/2;
    int a,b,c;
    for (int x=2;x*x<=mx;x++) {
    	for (int y=1;y<x;y++) {
    		a=x*x-y*y;
    		b=2*x*y;
    		c=x*x+y*y;
    		if (__gcd(a,b)==1&&__gcd(b,c)==1&&__gcd(a,c)==1) {
    			calc(a,b);
    			calc(a,c);
    			calc(b,c);
    		}
    	}
    }
    cout<<res;
}