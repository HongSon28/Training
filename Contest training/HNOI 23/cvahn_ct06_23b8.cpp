#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n,m;
int par[N+5];
vector<int>v;
int findroot(int x) {
    if (par[x]<0) return x;
    return par[x]=findroot(par[x]);
}
void Union(int x,int y) {
    if ((x=findroot(x))==(y=findroot(y))) return;
    if (par[y]<par[x]) swap(x,y);
    par[x]+=par[y];
    par[y]=x;
}
int main() {
    freopen("KINHDOANH.INP","r",stdin);
    freopen("KINHDOANH.OUT","w",stdout);
    memset(par,-1,sizeof(par));
    cin>>n>>m;
    while (m--) {
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }
    for (int i=1;i<=n;i++) {
        if (par[i]<0) v.push_back(-par[i]);
    }
    sort(v.begin(),v.end(),greater<int>());
    if (v.size()==1) cout<<v[0];
    else cout<<v[0]+v[1];
}
