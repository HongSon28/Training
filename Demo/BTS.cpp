#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
struct dat{
    long long x,y,id;
} a[N+5];
int n;
long long res;
int par[N+5];
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
struct edge{
    long long u,v,w;
    bool operator < (const edge &other) const {
        return w<other.w;
    }
};
vector<edge>e;
bool comp1(dat a,dat b) {
    if (a.x!=b.x) return a.x<b.x;
    return a.y<b.y;
}
bool comp2(dat a,dat b) {
    if (a.y!=b.y) return a.y<b.y;
    return a.x<b.x;
}
int main() {
    freopen("BTS.INP","r",stdin);
    freopen("BTS.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(par,-1,sizeof(par));
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i].x>>a[i].y;
        a[i].id=i;
    }
    sort(a+1,a+1+n,comp1);
    for (int i=1;i<n;i++) e.push_back({a[i].id,a[i+1].id,min(abs(a[i].x-a[i+1].x),abs(a[i].y-a[i+1].y))});
    sort(a+1,a+1+n,comp2);
    for (int i=1;i<n;i++) e.push_back({a[i].id,a[i+1].id,min(abs(a[i].x-a[i+1].x),abs(a[i].y-a[i+1].y))});
    sort(e.begin(),e.end());
    for (auto ed:e) {
        long long u=ed.u,v=ed.v,w=ed.w;
        if (findroot(u)!=findroot(v)) {
            Union(u,v);
            res+=w;
        }
    }
    cout<<res;
}
