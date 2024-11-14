#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foru(i, l, r) for(int i = l; i <= r; i++)
#define ford(i, r, l) for(int i = r; i >= l; i--)
#define __TIME  (1.0 * clock() / CLOCKS_PER_SEC)

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<ii, ii> iiii;

const int N = 1e5 + 5;

const int oo = 1e18, mod = 1e9 + 7;

int n, m, k, par[N], weights[N], X[N], Y[N], length[N], q, values[N], res[N], maxChild[N], last[N];
vector<int> queriesAt[N];
vector<ii> adj[N];

struct Fenwick {

	int *bit = nullptr;
	int n;

	Fenwick(int _n = 0) {
		resize(_n);
	}

	void reset(void) {
		fill(bit, bit + 1 + n, (int)(0));
	}

	void resize(int _n) {
		if (bit != nullptr) delete[] bit;
		n = _n;
		bit = new int[n + 1];
		reset();
	}

	void update(int i, int val) {
		assert(0 <= i);
		++i;
		for (; i <= n; i += i & -i) bit[i] += val;
	}

	int get(int i) {
		if (i < 0) return (int)(0);
		++i;
		i = min(i, n);
		int res(0);
		for (; i > 0; i -= i & -i)
			res += bit[i];
		return res;
	}

	int upper_bound(int val) {
		int res = 0;
		for (int i = __lg(n); i >= 0; --i) {
			if ((res | (1ll << (i))) <= n && val >= bit[res | (1ll << (i))]) {
				res |= (1ll << (i));
				val -= bit[res];
			}
		}
		return res;
	}

	int lower_bound(int val) {
		int res = 0;
		for (int i = __lg(n); i >= 0; --i) {
			if ((res | (1ll << (i))) <= n && val > bit[res | (1ll << (i))]) {
				res |= (1ll << (i));
				val -= bit[res];
			}
		}
		return res;
	}
};

void init() {
	cin >> n >> q;
	foru(i, 2, n) cin >> par[i];
	foru(i, 2, n) cin >> weights[i];
	foru(i, 1, q) {
		cin >> X[i] >> Y[i];
	}
}

void process() {
	foru(i, 2, n) length[i] = length[par[i]] + weights[i];
	vector<pair <long long, int>> vv;
	vector<int> en(N + 1);
	foru(i, 1, q) queriesAt[Y[i]].push_back(i);
	foru(u, 1, n) {
		maxChild[u] = u;
		values[u] = weights[u];
		for (int p = par[u]; p > 1 && length[maxChild[p]] < length[u]; p = par[p]) {
			int v = maxChild[p];
			values[v] -= weights[p];
			vv.emplace_back(values[v], v);
			maxChild[p] = u;
			values[u] += weights[p];
		}
		vv.emplace_back(values[u], u);
		en[u] = vv.size();
	}
	vector <int> order(vv.size()), pos(vv.size());
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&] (int a, int b) { return vv[a] > vv[b]; });
	foru(i, 0, vv.size()-1) pos[order[i]] = i;
	fill(last + 1, last + 1 + N, -1);
	Fenwick cnt(vv.size());
	Fenwick sum(vv.size());
	foru(y, 1, n) {
		foru(i, en[y - 1], en[y]-1) {
			int val, u;
			tie(val, u)=vv[i];
			if (last[u] != -1) {
				cnt.update(pos[last[u]], -1);
				sum.update(pos[last[u]], -vv[last[u]].fi);
			}
			last[u] = i;
			cnt.update(pos[i], +1);
			sum.update(pos[i], val);
		}
		for (int i: queriesAt[y]) res[i] = sum.get(cnt.lower_bound(X[i]));
	}
	
	foru(i,1,q) cout << res[i] * 2 << '\n';
	return;
}

signed main() {

	init();
	process();
}