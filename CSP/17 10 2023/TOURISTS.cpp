#include<bits/stdc++.h>
using namespace std;
const int N=2e5,SQ=sqrt(2e5);
struct query{
    int l,r,id;
    bool operator < (const query &other) const{
        if (l/SQ!=other.l/SQ) return l/SQ<other.l/SQ;
        return r<other.r;
    }
}q[N+5];
int n,m,c[N+5],t[N+5],cur;
int res[N+5];
void add(int i) {
    c[t[i]]++;
    if (c[t[i]]==1) cur++;
}
void del(int i) {
    c[t[i]]--;
    if (c[t[i]]==0) cur--;
}
vector<int>cprs;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("TOURISTS.INP","r",stdin);
    freopen("TOURISTS.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>t[i];
        cprs.push_back(t[i]);
    }
    sort(cprs.begin(),cprs.end());
    cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
    for (int i=1;i<=n;i++) t[i]=lower_bound(cprs.begin(),cprs.end(),t[i])-cprs.begin();
    cin>>m;
    for (int i=1;i<=m;i++) {
        cin>>q[i].l>>q[i].r;
        q[i].id=i;
    }
    sort(q+1,q+1+m);
    int l=1,r=1;
    c[t[1]]++;
    cur++;
    for (int i=1;i<=m;i++) {
        while (r<q[i].r) {
            r++;
            add(r);
        }
        while (r>q[i].r) {
            del(r);
            r--;
        }
        while (l>q[i].l) {
            l--;
            add(l);
        }
        while (l<q[i].l) {
            del(l);
            l++;
        }
        res[q[i].id]=cur;
    }
    for (int i=1;i<=m;i++) cout<<res[i]<<'\n';
}
