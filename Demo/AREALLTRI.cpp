#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define file "arealltri"

#define mp make_pair
// #define fi first
// #define se second
#define all(x) x.begin(), x.end()

#define bit(x) (1LL << (x))
#define getbit(x, i) (((x) >> (i)) & 1)
#define popcount __builtin_popcountll

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) {
    return l + rd() % (r - l + 1);
}

const int N = 1e6 + 5;
const int mod = (int)1e9 + 7; // 998244353;
const int lg = 25; // lg + 1
const int oo = 1e9;
const long long ooo = 1e18;

template<class X, class Y> bool mini(X &a, Y b) {
    return a > b ? (a = b, true) : false;
}
template<class X, class Y> bool maxi(X &a, Y b) {
    return a < b ? (a = b, true) : false;
}
void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
    if (a < 0) a += mod;
}

using point = pair<int, int>;
#define x first
#define y second

int n;
point p[N], tmp[N];
int sumx[N], sumy[N];


int partition(int x, int y) {
    if(x > 0 && y >= 0)return 0;
    if(x <= 0 && y > 0) return 1;
    if(x < 0 && y <= 0) return 2;
    return 3;
}

bool cmp(const point &a, const point &b) {
    int ax = a.x - tmp[0].x, ay = a.y - tmp[0].y;
    int bx = b.x - tmp[0].x, by = b.y - tmp[0].y;
    int ap = partition(ax, ay);
    int bp = partition(bx, by);
    if(ap != bp) return ap < bp;
    return ay * bx < ax * by;
}

int ccw(const point &a, const point &b, const point &c) {
    return (a.x - b.x) * (c.y - b.y) - (a.y - b.y) * (c.x - b.x);
}

void process() {
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;
    long double ans = 0;
    for(int i = 0; i < n; ++i) {
        copy(p, p + n, tmp);
        swap(tmp[0], tmp[i]);
        sort(tmp + i + 1, tmp + n, cmp);
        copy(tmp + i + 1, tmp + n, tmp + n);
        int m = n + (n - i - 2);
        for (int j = 1; j <= m; ++j) {
            sumx[j] = sumx[j - 1] + tmp[j].x;
            sumy[j] = sumy[j - 1] + tmp[j].y;
        }
        for(int j = i + 1, k = j; j < n; ++j) {
            if(k < j) k = j;
            while(k + 1 <= m && ccw(tmp[j], tmp[0], tmp[k + 1]) >= 0) ++k;
            if(j == k) continue;
            int vx = sumx[k] - sumx[j];
            int vy = sumy[k] - sumy[j];
            int cnt = k - j;
            ans = ans + 1ll * tmp[0].x * tmp[j].y * cnt + 1ll * tmp[j].x * vy + 1ll * vx * tmp[0].y - 1ll * tmp[0].x * vy - 1ll * tmp[j].x * tmp[0].y * cnt - 1ll * vx * tmp[j].y;
        }
    }

    cout << setprecision(1) << fixed << ans / 2;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #else
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
    #endif

    int tc = 1;
    // cin >> tc;

    while (tc--) {
        process();
    }

    return 0;
}

/*

*/
