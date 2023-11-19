#include <bits/stdc++.h>
#define value first
#define root second
using namespace std;
const int N=1e5;
int n,m,q,res;
int p[N+4],d[N+4];
double val[N+4],lst[N+4];
pair<double,double>dau[N+4],cnt[N+4];

int findroot(int u){
    if(p[u]<0) return u;
    return p[u]=findroot(p[u]);
}
void Union(int x,int y){
    int u=findroot(x),v=findroot(y);
    if(u!=y){
        if(p[u]>p[v]) swap(u,v);
        p[u]+=p[v];
        p[v]=u;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>q;
    memset(p,-1,sizeof(p));
    for(int i=1;i<=m;i++) cin>>val[i];
    while(q--){
        int t; cin>>t;
        if(t==1){
            int x,k; cin>>x>>k;
            d[k]++;
            dau[x].value=val[k];
        }
        else{
            int u,v; cin>>u>>v;
            Union(u,v);
        }
    }
    for(int i=1;i<=N;i++) if(d[i]!=0) res++;
    cout<<res<<'\n';
    for(int i=1;i<=n;i++){
        dau[i].root=findroot(i);
        cnt[findroot(i)].value+=1;
    }
    for(int i=1;i<=n;i++)
        if(dau[i].value!=0)
            cnt[findroot(i)].root=dau[i].value/cnt[findroot(i)].value;
    for(int i=1;i<=n;i++) lst[i]=cnt[findroot(i)].root;
    for(int i=1;i<=n;i++) cout<<fixed<<setprecision(8)<<lst[i]<<'\n';
}

