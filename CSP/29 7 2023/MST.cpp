#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
struct Edge{
    long long u,v,w;
    bool operator < (const Edge &others) const {
        return w<others.w;
    }
};
Edge edge[N+5];
long long par[N+5];
long long res;
long long findroot(int x) {
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
    freopen("MST.INP","r",stdin);
    freopen("MST.OUT","w",stdout);
    memset(par,-1,sizeof(par));
    cin>>n>>m;
    for (int i=1;i<=m;i++) cin>>edge[i].u>>edge[i].v>>edge[i].w;
    sort(edge+1,edge+1+m);
    for (int i=1;i<=m;i++) {
        if (findroot(edge[i].u)!=findroot(edge[i].v)) {
            Union(edge[i].u,edge[i].v);
            res+=edge[i].w;
        }
    }
    cout<<res;
}
