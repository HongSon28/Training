#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,t;
long long k;
long long a[N+5];
struct dsu{
    int l,r,par;
}par[N+5];
int findroot(int u) {
    if (par[u].par==0) return u;
    return par[u].par=findroot(par[u].par);
}
void Union(int u,int v) {
    if ((u=findroot(u))==(v=findroot(v))) return;
    par[u].l=min(par[u].l,par[v].l);
    par[u].r=max(par[u].r,par[v].r);
    par[v].par=u;
}
void solve() {
    for (int i=1;i<=n;i++) {
        if (a[i]==a[i+1]) Union(i,i+1);
    }
}
int main() {
    cin>>t;
    while (t--) {
        cin>>n>>k;
        for (int i=1;i<=n;i++) cin>>a[i];
        //init();
        solve();
    }
}
