#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m;
pair<int,int>edge[N+5];
int par[N+5];
vector<string>res;
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
    freopen("RME.INP","r",stdin);
    freopen("RME.OUT","w",stdout);
    memset(par,-1,sizeof(par));
    cin>>n>>m;
    for (int i=1;i<=m;i++) cin>>edge[i].first>>edge[i].second;
    for (int i=m;i>=1;i--) {
        if (findroot(edge[i].first)==findroot(edge[i].second)) res.push_back("YES");
        else {
            res.push_back("NO");
            Union(edge[i].first,edge[i].second);
        }
    }
    for (int i=res.size()-1;i>=0;i--) cout<<res[i]<<endl;
}
