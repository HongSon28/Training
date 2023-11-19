//#pragma GCC optimize("Ofast,unroll-loops")
#include "bits/stdc++.h"
using namespace std;

#ifdef duc_debug
#include "bits/debug.h"
#else
#define debug(...)
#endif

#define int long long

const int maxn = 2e5+5;
int n, a[maxn], q, lst[maxn], nxt[maxn];
int pos[maxn], ans[maxn];

struct Query{
    int l, r, id;
    bool operator<(const Query &o){
        return r < o.r;
    }
} e[maxn];

struct Fenwick{
    #define gb(x) (x) & (-x)
    int n;
    vector<int> bit;
    void init(int sz){
        n = sz;
        bit.resize(n + 2, 0);
    }
    void update(int x, int val){
        for(int i = x; i <= n; i += gb(i))
            bit[i] += val;
    }
    int get(int x){
        int ans = 0;
        for(int i = x; i > 0; i -= gb(i))
            ans += bit[i];
        return ans;
    }
    int get(int l, int r){
        return get(r) - get(l - 1);
    }
} fen;

void solve(){
    cin >> n >> q;
    fen.init(n);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        lst[i] = pos[a[i]];
        nxt[pos[a[i]]] = i;
        pos[a[i]] = i;
    }

    for(int i = 1; i <= q; ++i){
        cin >> e[i].l >> e[i].r;
        e[i].id = i;
    }
    sort(e + 1, e + q + 1);
    int j = 1;

    Fenwick adu;
    adu.init(n);

    for(int i = 1; i <= q; ++i){
        // debug(e[i].l, e[i].r);
        while(j <= e[i].r){
            fen.update(j, -j);
            if(nxt[j] != 0){
                fen.update(j, nxt[j]);
            }

            if(lst[j] != 0) adu.update(lst[j], j - lst[j]);
            adu.update(j, -nxt[j] + j);

            // debug(j, lst[j], nxt[j], fen.get(j));
            ++j;
        }
        int res = fen.get(e[i].l, e[i].r) + adu.get(e[i].l, e[i].r);
        ans[e[i].id] = res;
    }
    for(int i = 1; i <= q; ++i){
        cout << ans[i] << '\n';
    }

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test = 1;
    // cin >> test;
    for(int i = 1; i <= test; i++){
      // cout << "Case " << "#" << i << ": ";
      solve();
    }

    return 0;
}

