#include<bits/stdc++.h>
using namespace std;
const int N=300;
int m,n;
vector<vector<int>>lang(N+5),p(N+5);
vector<vector<int>>adj(N+5);
int w[N+5];
bool kn[N+5][N+5];
int d[N+5],a[N+5][N+5];
int inf=1e9;
struct dat{
    int u, cnt;
};
queue<dat>q;
void bfs(int lan) {
    for (int i=1;i<=m;i++) d[i]=inf;
    while (!q.empty()) q.pop();
    for (auto u:p[lan]) {
        q.push({u,0});
        d[u]=0;
    }
    while (!q.empty()) {
        int u=q.front().u,cnt=q.front().cnt;
        q.pop();
        for (auto v:adj[u]) {
            if (d[v]==inf) {
                d[v]=cnt+1;
                q.push({v,cnt+1});
            }
        }
    }
}
int main() {
    freopen("BAI5.INP","r",stdin);
    freopen("BAI5.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>m>>n;
    for (int i=1;i<=m;i++) {
        int k,t;
        cin>>k;
        while (k--) {
            cin>>t;
            lang[i].push_back(t);
            p[t].push_back(i);
            kn[i][t]=true;
        }
    }
    for (int u=1;u<=m;u++) {
        for (int v=1;v<=m;v++) {
            a[u][v]=inf;
            if (u==v) continue;
            for (auto lan:lang[u]) {
                if (kn[v][lan]) {
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                    break;
                }
            }
        }
    }
    for (int lan=1;lan<=n;lan++) {
        bfs(lan);
        for (int u=1;u<=m;u++) {
            for (int v=1;v<=m;v++) {
                if (u==v) {
                    a[u][v]=0;
                    continue;
                }
                if (!kn[u][lan]) continue;
                //cout<<lan<<' '<<u<<' '<<v<<' '<<d[v]<<' '<<p[lan].size()<<endl;
                a[u][v]=min(a[u][v],d[v]+(int)p[lan].size());
            }
        }
    }
    for (int u=1;u<=m;u++) {
        for (int v=1;v<=m;v++) {
            if (a[u][v]==inf) cout<<-1<<' ';
            else cout<<a[u][v]<<' ';
        }
        cout<<'\n';
    }
}
