#include<bits/stdc++.h>
#define ll int
using namespace std;
const int N=2e3;
int n;
vector<vector<int>>adj(N+5);
ll c[N+5],t[N+5];
ll inf=1e6+5;
ll dpget[N+5][N+5],dpgive[N+5][N+5];
void dfs(int u,int par) {
    for (auto &v:adj[u]) {
        if (v==par) {
            swap(v,adj[u].back());
            adj[u].pop_back();
            break;
        }
    }
    for (auto v:adj[u]) dfs(v,u);
}
ll get(int u,ll val);
ll give(int u,ll val);
ll cnt=0;
ll give(int u,ll val) {
    //cout<<"give "<<u<<' '<<val<<' '<<++cnt<<endl;
    if (val>n) return 0;
    if (adj[u].empty()) {
        assert(val>=1);
        return 0;
    }
    if (dpgive[u][val]!=-1) return dpgive[u][val];
    dpgive[u][val]=get(u,0);
    ll sum=0;
    for (auto v:adj[u]) {
        if (val==1) sum+=get(v,0);
        else sum+=give(v,val-1);
    }
    dpgive[u][val]=min(dpgive[u][val],min(sum,inf));
    return dpgive[u][val];
}
ll get(int u,ll val) {
    //cout<<"get "<<u<<' '<<val<<endl;
    if (val>n) {
        return inf;
    }
    if (adj[u].empty()) {
        if (t[u]>val) return c[val];
        return inf;
    }
    if (dpget[u][val]!=-1) return dpget[u][val];
    //cout<<"cnf"<<' '<<u<<' '<<val+1<<endl;
    dpget[u][val]=get(u,val+1);
    ll sum=0;
    for (auto v:adj[u]) {
        if (val>=1) sum+=give(v,val);
        else sum+=get(v,0);
    }
    //cout<<"getsum "<<u<<' '<<val<<' '<<sum<<endl;
    if (val<t[u]) dpget[u][val]=min(dpget[u][val],sum+c[val]);
    for (auto v:adj[u]) {
        ll cur=sum+get(v,val+1);
        if (val>=1) cur-=give(v,val);
        else cur-=get(v,0);
        dpget[u][val]=min(dpget[u][val],cur);
    }
    return dpget[u][val];
}
int main() {
    freopen("garden.33.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=0;i<n;i++) cin>>c[i];
    for (int i=1;i<=n;i++) cin>>t[i];
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    memset(dpget,-1,sizeof(dpget));
    memset(dpgive,-1,sizeof(dpgive));
    ll res=get(1,0);
    if (res>=inf) cout<<-1;
    else cout<<res;
}
