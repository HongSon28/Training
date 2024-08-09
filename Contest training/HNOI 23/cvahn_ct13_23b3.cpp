#include<bits/stdc++.h>
using namespace std;
const long long N=1e6,SQ=450;
int n,t;
long long res[N+5];
long long a[N+5],c[N+5],cur;
struct Query{
    long long l,r,id;
};
Query q[N+5];
bool comp(Query x,Query y) {
    if (x.l/SQ!=y.l/SQ) return x.l/SQ<y.l/SQ;
    return x.r<y.r;
}
int main() {
    freopen("GTDAYSO.INP","r",stdin);
    freopen("GTDAYSO.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>t;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=t;i++) {
        cin>>q[i].l>>q[i].r;
        q[i].id=i;
    }
    sort(q+1,q+1+t,comp);
    int l=1,r=1;
    c[a[1]]++;
    cur=a[1];
    for (int i=1;i<=t;i++) {
        while (r<q[i].r) {
            r++;
            cur-=c[a[r]]*c[a[r]]*a[r];
            c[a[r]]++;
            cur+=c[a[r]]*c[a[r]]*a[r];
        }
        while (l<q[i].l) {
            cur-=c[a[l]]*c[a[l]]*a[l];
            c[a[l]]--;
            cur+=c[a[l]]*c[a[l]]*a[l];
            l++;
        }
        while (r>q[i].r) {
            cur-=c[a[r]]*c[a[r]]*a[r];
            c[a[r]]--;
            cur+=c[a[r]]*c[a[r]]*a[r];
            r--;
        }
        while (l>q[i].l) {
            l--;
            cur-=c[a[l]]*c[a[l]]*a[l];
            c[a[l]]++;
            cur+=c[a[l]]*c[a[l]]*a[l];
        }
        res[q[i].id]=cur;
    }
    for (int i=1;i<=t;i++) cout<<res[i]<<'\n';
}
