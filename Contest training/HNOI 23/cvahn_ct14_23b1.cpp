#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int par[N+5];
int find_root(int u) {
    if (par[u]<0) return u;
    return par[u]=find_root(par[u]);
}
void Union(int u,int v) {
    if ((u=find_root(u))==(v=find_root(v))) return;
    if (par[v]>par[u]) swap(u,v);
    par[u]+=par[v];
    par[v]=u;
}
int p,x,y,z;
int main() {
    freopen("BIN.INP","r",stdin);
    freopen("BIN.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(par,-1,sizeof(par));
    cin>>p;
    while (p--) {
        cin>>x>>y>>z;
        if (z==1) Union(x,y);
        else cout<<(find_root(x)==find_root(y))<<'\n';
    }
}
