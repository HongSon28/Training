#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,q;
int par[N+5];
int a[N+5];
int findroot(int x) {
    if (par[x]<0) return x;
    return par[x]=findroot(par[x]);
}
void Union(int u,int v) {
    if ((u=findroot(u))==(v=findroot(v))) return;
    if (par[v]<par[u]) swap(u,v);
    par[u]+=par[v];
    par[v]=u;
}
int lo[N+5],hi[N+5];
int qu[N+5],qv[N+5];
vector<int>vc[N+5];
vector<int>Que[N+5];
void ans(int c) {
    bool flag=true;
    for (int i=1;i<vc[c].size();i++) {
        if (findroot(vc[c][i-1])!=findroot(vc[c][i])) {
            flag=false;
            break;
        }
    }
    int mid=(lo[c]+hi[c])/2;
    if (flag) hi[c]=mid;
    else lo[c]=mid+1;
}
void reload() {
    for (int i=0;i<=q;i++) Que[i].clear();
    for (int i=1;i<=m;i++) {
        Que[(lo[i]+hi[i])/2].push_back(i);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(par,-1,sizeof(par));
    cin>>n>>m>>q;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        vc[a[i]].push_back(i);
    }
    for (int i=1;i<=q;i++) cin>>qu[i]>>qv[i];
    for (int i=1;i<=m;i++) {
        lo[i]=0;
        hi[i]=q;
    }
    for (int time=1;time<=25;time++) {
        memset(par,-1,sizeof(par));
        reload();
        for (int i=0;i<=q;i++) {
            Union(qu[i],qv[i]);
            for (int j=0;j<Que[i].size();j++) ans(Que[i][j]);
        }
    }
    for (int i=1;i<=m;i++) {
        if (lo[i]>q) cout<<-1<<'\n';
        else cout<<lo[i]<<'\n';
    }
}
