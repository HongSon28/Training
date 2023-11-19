#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5;
int n,m;
ll par[N+5];
ll sum=0;
ll findroot(ll x) {
    if (par[x]<0) return x;
    return par[x]=findroot(par[x]);
}
void Union(ll x,ll y) {
    if ((x=findroot(x))==(y=findroot(y))) return;
    if (par[y]<par[x]) swap(x,y);
    par[x]+=par[y];
    par[y]=x;
}
int main() {
    freopen("PAIRS.INP","r",stdin);
    freopen("PAIRS.OUT","w",stdout);
    memset(par,-1,sizeof(par));
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        ll u,v;
        cin>>u>>v;
        if (findroot(u)==findroot(v)) {
            cout<<sum<<endl;
            continue;
        }
        sum+=par[findroot(u)]*par[findroot(v)];
        Union(u,v);
        cout<<sum<<endl;
    }
}
