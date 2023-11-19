#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
struct dat{
    int u,v,id;
};
vector<dat>white,grey,black;
int n,m,cnt;
bool flag;
vector<int>res;
int par[N+5];
bool used[N+5];
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
    freopen("BWGRAPH.INP","r",stdin);
    freopen("BWGRAPH.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(par,-1,sizeof(par));
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        if (c==1) white.push_back({a,b,i});
        else if (c==2) black.push_back({a,b,i});
        else grey.push_back({a,b,i});
    }

    for (auto i:grey) {
        int s=findroot(i.u),t=findroot(i.v);
        if (s!=t) {
            used[i.id]=true;
            Union(s,t);
        }
    }
    for (auto i:black) {
        int s=findroot(i.u),t=findroot(i.v);
        if (s!=t) {
            used[i.id]=true;
            Union(s,t);
        }
    }
    for (int i=1;i<=n;i++) {
        if (par[i]<0) {
            if (-par[i]==n){
                flag=true;
                break;
            }
        }
    }
    if (!flag) {
        cout<<-1;
        return 0;
    }

    memset(par,-1,sizeof(par));
    flag=false;
    for (auto i:grey) {
        if (used[i.id]) Union(i.u,i.v);
    }
    for (auto i:grey) {
        if (used[i.id]) continue;
        int s=findroot(i.u),t=findroot(i.v);
        if (s!=t) {
            used[i.id]=true;
            Union(s,t);
        }
    }
    for (auto i:white) {
        int s=findroot(i.u),t=findroot(i.v);
        if (s!=t) {
            used[i.id]=true;
            Union(s,t);
        }
    }
    for (int i=1;i<=m;i++) if (!used[i]) {
        cnt++;
        res.push_back(i);
    }
    for (int i=1;i<=n;i++) {
        if (par[i]<0) {
            if (-par[i]==n){
                flag=true;
                break;
            }
        }
    }
    if (!flag) {
        cout<<-1;
        return 0;
    }
    if (cnt==0) {
        cout<<-1;
        return 0;
    }

    cout<<cnt<<endl;
    for(auto i:res) cout<<i<<' ';
}
