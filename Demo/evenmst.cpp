#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

const int N = 3e5 + 5;
const int LG = 19;

struct Edge {
    int u, v, w, id;
};

#include <bits/stdc++.h>
using namespace std;

int n, m;
Edge edges[N];
int par[N];
vector<pair<int, int>> adj[N];
bool choose[N];
int up[LG][N], has[2][LG][N];
int h[N];

int find(int u) {
    return !par[u] ? u : par[u] = find(par[u]);
}

bool unite(int u, int v) {
    if ((u = find(u)) == (v = find(v))) return false;
    return par[v] = u, true;
}

void dfs(int u, int p, int pid) {
    up[0][u] = p;
    for (int j = 1; j < LG; j++) up[j][u] = up[j - 1][up[j - 1][u]];

    if (pid) {
        int who = edges[pid].w % 2;
        has[who][0][u] = pid;
    }

    for (int who = 0; who < 2; who++) {
        for (int j = 1; j < LG; j++) {
            has[who][j][u] = max(has[who][j - 1][u], has[who][j - 1][up[j - 1][u]]);
        }
    }

    for (auto [v, id] : adj[u]) {
        if (v == p) continue;
        h[v] = h[u] + 1;
        dfs(v, u, id);
    }
}

int get(int who, int u, int v) {
    int ans = -1;

    if (h[u] != h[v]) {
        if (h[u] < h[v]) swap(u, v);
        int k = h[u] - h[v];
        for (int j = 0; j <= LG; j++) {
            if (k >> j & 1) {
                ans = max(ans, has[who][j][u]);
                u = up[j][u];
            }
        }
    }

    if (u == v) return ans;

    int k = __lg(h[u]);
    for (int j = k; j >= 0; j--) {
        if (up[j][u] != up[j][v]) {
            ans = max(ans, has[who][j][u]);
            ans = max(ans, has[who][j][v]);
            u = up[j][u];
            v = up[j][v];
        }
    }

    ans = max(ans, has[who][0][u]);
    ans = max(ans, has[who][0][v]);

    return ans;
}

void answer() {
    vector<int> ans;
    for (int i = 1; i <= m; i++) {
        if (choose[i]) {
            ans.push_back(i);
        }
    }
    cout << "YES\n";
    for (int i : ans) cout << i << ' ';
    cout << '\n';
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w, i};
    }

    int mst = 0, sz = 0;
    for (int i = 1; i <= m; i++) {
        if (unite(edges[i].u, edges[i].v)) {
            adj[edges[i].u].push_back({edges[i].v, i});
            adj[edges[i].v].push_back({edges[i].u, i});
            mst += edges[i].w;
            sz++;
            choose[i] = 1;
        }
    }

    if (sz != n - 1) {
        cout << "NO\n";
        return;
    }

    if (mst % 2 == 0) {
        answer();
        return;
    }

    memset(has, -1, sizeof has);
    dfs(1, 0, 0);

    for (int i = 1; i <= m; i++) {
        if (!choose[i]) {
            int id = get(!(edges[i].w % 2), edges[i].u, edges[i].v);
            if (id != -1) {
                choose[id] = 0;
                choose[i] = 1;
                answer();
                return;
            }
        }
    }

    cout << "NO\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    #ifdef LOCAL
    auto st = clock();
    #endif

    #ifdef LOCAL
    freopen("D:\\.inp", "r", stdin);
    freopen("D:\\.out", "w", stdout);
    #endif

    int t = 1;
    // cin >> t;
    while (t--) solve();

    #ifdef LOCAL
    cerr << "[Time]: " << clock() - st << " ms\n";
    #endif
}
