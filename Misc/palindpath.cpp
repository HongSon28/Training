#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int maxN = 1e2 + 5;
const int mod = 1e9 + 7;
const ll oo = 1e9;
int n, m;
vector<pair<int, int>> adj[maxN];
int f[maxN][maxN];
int match[maxN][maxN];
void ReadInput()
{
    cin >> n >> m;
    for(int i=1; i<=m; i++)
    {
        int u, v;
        char c;
        cin >> u >> v >> c;
        match[u][v] = 1;
        match[v][u] = 1;
        adj[u].pb({v, int(c - 'a')});
        adj[v].pb({u, int(c - 'a')});
    }
}
int vis[maxN];
void bfs()
{
    queue<pair<int, int>> q;
    memset(f, -1, sizeof f);
    q.push({1, 2});
    f[1][2] = 0;
    while(!q.empty())
    {
        pair<int, int> u = q.front();
        q.pop();
        for(auto v1 : adj[u.fi])
            for(auto v2 : adj[u.se])
            {
                if(f[v1.fi][v2.fi] != -1) continue;
                if(v1.se == v2.se)
                {
                    f[v1.fi][v2.fi] = f[u.fi][u.se] + 1;
                    cout<<u.fi<<' '<<u.se<<' '<<v1.fi<<' '<<v2.fi<<' '<<f[v1.fi][v2.fi]<<endl;
                    q.push({v1.fi, v2.fi});
                }
            }
    }
}
void Solve()
{
    bfs();
    int res = oo;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++)
        {
            if(f[i][j] != -1) {
                if(i == j) res = min(res, f[i][j] * 2);
                else if(match[i][j]) res = min(res, f[i][j] * 2 + 1);
            }
            //cout<<f[i][j]<<' ';
        }
        //cout<<endl;
    }
    cout << (res < oo ? res : -1);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ReadInput();
    Solve();
}

