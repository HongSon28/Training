#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
struct dat{
    int u,v,w;
};
bool comp(dat x, dat y) {
    if (x.w==y.w)
        if (x.u==y.u) return x.v<y.v;
        else return x.u<y.u;
    return x.w<y.w;
}
int n,m,sum;
int par[N+5];
dat edge[N+5];
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
    freopen("SAVE.INP","r",stdin);
    freopen("SAVE.OUT","w",stdout);
    memset(par,-1,sizeof(par));
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        int u,v1,w;
        cin>>u>>v1>>w;
        edge[i]={u,v1,w};
        sum+=w;
    }
    sort(edge+1,edge+m,comp);
    for (int i=1;i<=m;i++) {
        int r=findroot(edge[i].u);
        int s=findroot(edge[i].v);
        if (r!=s) {
            sum-=edge[i].w;
            Union(r,s);
        }
    }
    cout<<sum;
}
