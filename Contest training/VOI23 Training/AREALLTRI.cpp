#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
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

bool cmp(const point a, const point b) {
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
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("arealltri.inp","r",stdin);
	freopen("arealltri.out","w",stdout);
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