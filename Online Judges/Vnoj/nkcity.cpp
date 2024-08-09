#include<bits/stdc++.h>
using namespace std;
const int N=1000;
struct Edge{
    int u,v,t;
    bool operator < (const Edge &other) const {
        return t<other.t;
    }
};
vector<Edge>edge;
int par[N+5];
int n,m;
int res;
int findroot(int u) {
    if (par[u]<0) return u;
    return par[u]=findroot(par[u]);
}
void Union(int u,int v) {
    if ((u=findroot(u))==(v=findroot(v))) return;
    if (par[v]>par[u]) swap(u,v);
    par[u]+=par[v];
    par[v]=u;
}
int main() {
    memset(par,-1,sizeof(par));
    cin>>n>>m;
    while (m--) {
        int u,v,t;
        cin>>u>>v>>t;
        edge.push_back({u,v,t});
    }
    sort(edge.begin(),edge.end());
    for (auto e:edge) {
        int u=e.u,v=e.v,t=e.t;
        if (findroot(u)!=findroot(v)) {
            Union(u,v);
            //cout<<u<<' '<<v<<' '<<t<<endl;
            res=t;
        }
    }
    cout<<res;
}
