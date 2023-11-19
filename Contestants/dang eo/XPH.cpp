#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
struct dat{
    int l,r,id;
    bool operator < (const dat &other) const{
        if (l==other.l) return r<other.r;
        return l<other.l;
    }
} a[N+5];
long long res[N+5];
vector<int>cprs;
int n,m;
int st[N*8+5];
int get(int id,int l,int r,int u,int v) {
    if (u>r||v<l) return 0;
    if (u<=l&&r<=v) return st[id];
    int mid=(l+r)/2;
    return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}
void update(int id,int l,int r,int pos) {
    if (l>pos||r<pos) return;
    if (l==r) {
        st[id]++;
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,pos);
    update(id*2+1,mid+1,r,pos);
    st[id]=st[id*2]+st[id*2+1];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("XPH.INP","r",stdin);
    freopen("XPH.OUT","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i].l>>a[i].r;
        a[i].id=i;
        cprs.push_back(a[i].l);
        cprs.push_back(a[i].r);
    }
    sort(cprs.begin(),cprs.end());
    cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
    for (int i=1;i<=n;i++) {
        a[i].l=lower_bound(cprs.begin(),cprs.end(),a[i].l)-cprs.begin()+1;
        a[i].r=lower_bound(cprs.begin(),cprs.end(),a[i].r)-cprs.begin()+1;
    }
    sort(a+1,a+1+n);
    m=2*n;
    for (int i=1;i<=n;i++) {
        res[a[i].id]=get(1,1,m,a[i].l,m);
        int lo=i+1,hi=n,ans=i;
        while (lo<=hi) {
            int mid=(lo+hi)/2;
            if (a[mid].l<=a[i].r) {
                ans=mid;
                lo=mid+1;
            } else hi=mid-1;
        }
        res[a[i].id]+=ans-i;
        update(1,1,m,a[i].r);
    }
    for (int i=1;i<=n;i++) cout<<res[i]<<'\n';
}
