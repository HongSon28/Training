#include<bits/stdc++.h>
using namespace std;
int n,m;
int res;
const int N=1e5;
struct dat{
    int u,v,c;
};
dat a[N+5];
bool cmp(dat x,dat y) {
    return x.c<y.c;
}
int par[N+5];
int findset(int x) {
    if(par[x]<0) return x;
    return par[x]=findset(par[x]);
}
void Union(int x,int y) {
    if ((x=findset(x))==(y=findset(y))) return;
    if (par[x]>par[y]) swap(x,y);
    par[x]+=par[y];
    par[y]=x;
}
int main() {
    memset(par,-1,sizeof(par));
    cin>>n>>m;
    for (int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].c;
    sort(a+1,a+1+m,cmp);
    for (int i=1;i<=m;i++) {
        if (findset(a[i].u)!=findset(a[i].v)) {
            res+=a[i].c;
            Union(a[i].u,a[i].v);
        }
    }
    cout<<res;
}
