#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int par[N+5];
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
int n,q;
struct edge{
    long long u,v,w;
    bool operator < (const edge &other) const{
        return w>other.w;
    }
};
priority_queue<edge>pq;
long long w[N+5][N+5],res;
int main() {
    freopen("mst.inp","r",stdin);
    freopen("mst2.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(par,-1,sizeof(par));
    cin>>n>>q;
    while (q--) {
        long long u,v,x,y,ww;
        cin>>u>>v>>x>>y>>ww;
        for (int i=u;i<=v;i++)
            for (int j=x;j<=y;j++)
                w[i][j]+=ww;
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            pq.push({i,j,w[i][j]});
    while (!pq.empty()) {
        edge t=pq.top();
        pq.pop();
        if (findroot(t.u)!=findroot(t.v)) {
            Union(t.u,t.v);
            res+=t.w;
        }
    }
    cout<<res;
}
