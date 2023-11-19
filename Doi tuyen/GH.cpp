#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
struct dat{
    long long x,y;
};
struct comp1 {
    bool operator() (const dat& a, const dat& b) const{
        if (a.x==b.x) return a.y<b.y;
        return a.x<b.x;
    }
};
struct comp2 {
    bool operator() (const dat& a, const dat& b) const{
        if (a.y-a.x==b.y-b.x) return a.y<b.y;
        return a.y-a.x<b.y-b.x;
    }
};
struct comp3 {
    bool operator() (const dat& a, const dat& b) const{
        if (a.y==b.y) return a.x<b.x;
        return a.y<b.y;
    }
};
dat a[N+5],b[N+5];
multiset<dat,comp1>a1;
multiset<dat,comp2>a2;
multiset<dat,comp3>c;
long long n,t;
long long res=1e16,cur,inf=1e16;
int main() {
    //freopen("GH.INP","r",stdin);
    //freopen("GH.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>t;
    for (int i=1;i<=n;i++) cin>>a[i].x;
    for (int i=1;i<=n;i++) cin>>a[i].y;
    sort(a+1,a+1+n,comp1());
    for (int i=1;i<=t;i++) cin>>b[i].x;
    for (int i=1;i<=t;i++) cin>>b[i].y;
    for (int i=1;i<=t;i++) {
        a1.insert(a[i]);
        a2.insert(a[i]);
        cur+=a[i].x;
    }
    for (int i=t+1;i<=n;i++) c.insert(a[i]);
    sort(b+1,b+1+t,comp2());
    for (int i=1;i<=t;i++) cur+=b[i].x;
    res=min(res,cur);
    for (int i=1;i<=t;i++) {
        long long p,q;
        q=(*a1.rbegin()).x;
        if (c.empty()) p=inf;
        else p=(*c.begin()).y;
        long long r=(*a2.begin()).y-(*a2.begin()).x;
        if (p-q<r) {
            dat temp=*a1.rbegin();
            a1.erase(a1.find(temp));
            a2.erase(a2.find(temp));
            c.erase(c.begin());
            c.insert(temp);
        } else {
            dat temp=*a2.begin();
            a2.erase(a2.find(temp));
            a1.erase(a1.find(temp));
        }
        cur+=min(p-q,r);
        cur+=b[i].y-b[i].x;
        res=min(res,cur);
    }
    cout<<res;
}
