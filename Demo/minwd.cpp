#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const long long INF = 1ll << 62;

vector <int> useful_pair[N];
vector <pair <int, int>> queries[N];

long long bit[N];

void modify(int p, long long v) {
    for (int i = p; i > 0; i -= i & (-i)) {
        bit[i] = min(bit[i], v);
    }
}

long long query(int p) {
    long long ans = INF;
    for (int i = p; i < N; i += i & (-i)) {
        ans = min(ans, bit[i]);
    }
    return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector <int> x(n), w(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> w[i];
    }
    for (int i = 0, l, r; i < q; ++i) {
        cin >> l >> r, --l;
        queries[r].emplace_back(l, i);
    }
    stack <int> stk;
    for (int i = 0; i < n; ++i) {
        while (!stk.empty() && w[stk.top()] > w[i]) {
            stk.pop();
        }
        if (!stk.empty()) {
            int x = stk.top();
            useful_pair[i].push_back(x);
        }
        stk.push(i);
    }
    while (!stk.empty()) {
        stk.pop();
    }
    for (int i = n - 1; ~i; --i) {
        while (!stk.empty() && w[stk.top()] > w[i]) {
            stk.pop();
        }
        if (!stk.empty()) {
            int x = stk.top();
            useful_pair[x].push_back(i);
        }
        stk.push(i);
    }
    fill(bit, bit + N, INF);
    vector <long long> ans(q);
    for (int r = 1; r <= n; ++r) {
        for (int l : useful_pair[r - 1]) {
            long long val = 1ll * (x[r - 1] - x[l]) * (w[l] + w[r - 1]);
            modify(l + 1, val);
        }
        for (auto [l, id] : queries[r]) {
            ans[id] = query(l + 1);
        }
    }
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << endl;
    }
}
