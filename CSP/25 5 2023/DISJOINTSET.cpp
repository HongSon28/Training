#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int par[N+5];
int findset(int x) {
    if (par[x]<0) return x;
    return par[x]=findset(par[x]);
}
void mer(int x,int y) {
    if ((x=findset(x))==(y=findset(y))) return;
    if (par[y]<par[x]) swap(x,y);
    par[x]+=par[y];
    par[y]=x;
}
int main() {
    freopen("DISJOINTSET.INP","r",stdin);
    freopen("DISJOINTSET.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(par,-1,sizeof(par));
    int n,m,q;
    cin>>n>>m>>q;
    while (m--) {
        int x,y;
        cin>>x>>y;
        mer(x,y);
    }
    while (q--) {
        int x,y;
        cin>>x>>y;
        if (findset(x)==findset(y)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

