#include <bits/stdc++.h>
#define task "dichchuyen"

using namespace std;

const int N = 1010;
const int du[] = {0, 1, 0, -1};
const int dv[] = {1, 0, -1, 0};

int n, m, x, y, z, t;
int a[N][N];
pair<int, pair<int, int>> b[N * N];
vector<pair<int, int>> adj[N * N];
bool vis[N][N];
int d[N][N];
bool ok[N * N];

bool in(int u, int v) {
    return 1 <= u && u <= n && 1 <= v && v <= m;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    cin >> n >> m >> x >> y >> z >> t;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> b[(i - 1) * m + j].first;
            b[(i - 1) * m + j].second = make_pair(i, j);
            vis[i][j] = 0;
        }
    }
    sort(b + 1, b + n * m + 1);
    int tmp = 0;
    for (int i = 1; i <= n * m; ++i) {
        tmp += (i == 1 || b[i].first != b[i - 1].first) && b[i].first;
        if (b[i].first) {
            a[b[i].second.first][b[i].second.second] = tmp;
            adj[tmp].push_back(b[i].second);
        }
        ok[tmp] = 0;
    }
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    vis[x][y] = 1;
    d[x][y] = 0;
    while (!q.empty()) {
        int u = q.front().first, v = q.front().second;
        q.pop();
        if (u == z && v == t) {
            break;
        }
        for (int i = 0; i < 4; ++i) {
            int nu = u + du[i], nv = v + dv[i];
            if (!vis[nu][nv] && a[nu][nv] && in(nu, nv)) {
                q.push(make_pair(nu, nv));
                vis[nu][nv] = 1;
                d[nu][nv] = d[u][v] + 1;
            }
        }
        if (!ok[a[u][v]]) {
            for (const pair<int, int> &p: adj[a[u][v]]) {
                int nu = p.first, nv = p.second;
                if (!vis[nu][nv] && a[nu][nv]) {
                    q.push(p);
                    vis[nu][nv] = 1;
                    d[nu][nv] = d[u][v] + 1;
                }
            }
            ok[a[u][v]] = 1;
        }
    }
    cout << d[z][t];
}
