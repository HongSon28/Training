#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define lwb lower_bound
#define upb upper_bound

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 105;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n, m1, m2;
vector<int> adj1[SZ], adj2[SZ];
bool edge1[SZ][SZ], edge2[SZ][SZ];

namespace sub1
{
    int vis[SZ][SZ];
    void bfs(int s) {
        queue<pair<int,int>>q;
        memset(vis,-1,sizeof(vis));
        vis[s][s]=0;
        q.push({s,s});
        while (!q.empty()) {
            int u=q.front().first;
            int v=q.front().second;
            q.pop();
            for (int k=1;k<=n;k++) {
                if (edge1[u][k]) {
                    if (vis[k][v] == -1) {
                        vis[k][v] = vis[u][v] + 1;
                        q.push({k,v});
                    }
                }
                if (edge2[v][k]) {
                    if (vis[u][k] == -1) {
                        vis[u][k] = vis[u][v] + 1;
                        q.push({u,k});
                    }
                }
                if (edge1[u][k]&&edge2[v][k]) {
                    if (vis[k][k] == -1) {
                        vis[k][k] = vis[u][v] + 1;
                        q.push({k,k});
                    }
                }
            }
        }
    }

    ll solve()
    {
        long long res = 0;
        for(int s = 1; s <= n; s++)
        {
            bfs(s);
            for(int t = 1; t <= n; t++)
            {
                res+=vis[t][t];
            }
        }
        return res;
    }
}

int main()
{
    init();
    cin >> n >> m1;
    for (int i=1;i<=n;i++) edge1[i][i]=edge2[i][i]=true;
    for(int i = 1; i <= m1; i++)
    {
        int u,v;
        cin >> u >> v;
        adj1[u].pb(v);
        adj1[v].pb(u);
        edge1[u][v]=edge1[v][u]=true;
    }
    cin >> m2;
    for(int i = 1; i <= m2; i++)
    {
        int u,v;
        cin >> u >> v;
        adj2[u].pb(v);
        adj2[v].pb(u);
        edge2[u][v]=edge2[v][u]=true;
    }
    cout << sub1::solve();
}

