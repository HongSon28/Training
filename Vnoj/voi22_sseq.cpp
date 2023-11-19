#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
struct dat{
    int l,r;
    long long w;
    bool operator < (const dat &other) const {
        if (l==other.l) return r<other.r;
        return l<other.l;
    }
};
dat a[N+5];
long long cur,res;
int main() {
    //freopen("SSEQ.INP","r",stdin);
    //freopen("SSEQ.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i].l>>a[i].r>>a[i].w;
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++) {
        cur+=a[i].w;
        if (cur<0&&a[i].l!=a[i+1].l) cur=0;
        cout<<cur<<' '<<a[i].w<<'\n';
        res=max(res,cur);
    }
    cout<<res;
}
