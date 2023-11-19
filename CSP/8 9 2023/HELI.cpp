#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,res;
vector<vector<int>>adj(N+5);
int num[N+5],low[N+5],d[N+5];
int timer;
bool deleted[N+5];
stack<int>st;
void dfs(int u) {
    timer++;
    num[u]=low[u]=timer;
    st.push(u);
    for (auto v:adj[u]) {
        if (deleted[v]) continue;
        if (!num[v]) {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else low[u]=min(low[u],num[v]);
    }
    if (low[u]==num[u]) {
        int cnt=0;
        int v;
        do {
            v=st.top();
            st.pop();
            deleted[v]=true;
            if (!d[v]) cnt++;
        } while (v!=u);
        res+=(cnt!=0);
    }
}
int main() {
    //freopen("HELI.INP","r",stdin);
    //freopen("HELI.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        d[v]++;
    }
    for (int i=1;i<=n;i++) {
        if (!num[i]) dfs(i);
    }
    cout<<res;
}
