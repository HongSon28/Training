#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
struct dat{
    long long t,w;
    bool operator < (const dat &other) const{
        return (double) w/t>(double) other.w/other.t;
    }
    bool operator >= (const dat &other) const{
        return (double) w/t<=(double) other.w/other.t;
    }
} p[N+5];
long long res;
vector<vector<int>>adj(N+5);
multiset<dat>jobs[N+5];
void dfs(int u,int par) {
    for (auto v:adj[u]) {
        if (v==par) continue;
        dfs(v,u);
        if (jobs[u].size()<jobs[v].size()) swap(jobs[u],jobs[v]);
        for (auto x:jobs[v]) jobs[u].insert(x);
    }
    dat cur=p[u];
    while (!jobs[u].empty()&&cur>=(*jobs[u].begin())) {
        dat t={cur.t+(*jobs[u].begin()).t,cur.w+(*jobs[u].begin()).w};
        res+=cur.t*(*jobs[u].begin()).w;
        jobs[u].erase(jobs[u].begin());
        cur=t;
    }
    jobs[u].insert(cur);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
        int p;
        cin>>p;
        p++;
        adj[p].push_back(i);
    }
    for (int i=1;i<=n;i++) cin>>p[i].w;
    for (int i=1;i<=n;i++) cin>>p[i].t;
    dfs(1,0);
    long long d=0;
    for (auto x:jobs[1]) {
        res+=x.w*d;
        d+=x.t;
    }
    for (int i=1;i<=n;i++) res+=p[i].w*p[i].t;
    cout<<res;
}
