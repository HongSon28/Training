#include<bits/stdc++.h>
using namespace std;
int n;
const int N=1e6;
int inf=1e9+5;
int a[N+5];
int st[4*N+5];
void build(int id, int l, int r) {
    if (l == r) {
        st[id] = a[l];
        return;
    }
    int mid = (l + r)/2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    st[id] = max(st[2 * id], st[2 * id + 1]);
}

int get(int id, int l, int r, int u, int v) {
    if (l >  v || r <  u) return -inf;
    if (l >= u && r <= v) return st[id];
    int mid =(l+r)/2;
    int get1 = get(2 * id, l, mid, u, v);
    int get2 = get(2 * id + 1, mid + 1, r, u, v);
    return max(get1, get2);
}
int main() {
    freopen("DMAX.INP","r",stdin);
    freopen("DMAX.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    for (int i=1;i<=n;i++) {
        int d;
        cin>>d;
        int l=max(1,i-d),r=i;
        cout<<get(1,1,n,l,r)<<' ';
    }
}
