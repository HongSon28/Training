#include<bits/stdc++.h>
using namespace std;
const int N=14;
int n;
struct dat{
    long long x,y;
    double a;
    bool operator < (const dat &other) const {
        return a<other.a;
    }
} a[N+5];
bool comp(dat a,dat b) {
    return a.x<b.x;
}
double d(dat a,dat b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
namespace sub1{
    bool check(double mn) {
        if (a[1].a>=mn&&a[2].a>=mn) return true;
        if (a[1].a<mn&&a[2].a<mn) return false;
        double t=a[2].a-mn,dist=d(a[1],a[2]);
        return (a[1].a+max(0.0,t-dist)>=mn);
    }
    void solve() {
        double lo=0,hi=1e9,ans=0,eps=1e-6;
        while (hi-lo>eps) {
            double mid=(lo+hi)/2;
            if (check(mid)) {
                ans=mid;
                lo=mid;
            } else hi=mid;
        }
        cout<<fixed<<ans<<'\n';
    }
}
namespace sub2{
    bool check(double mn) {
        if (a[3].a<mn) return false;
        if (a[1].a>=mn) return true;
        if (a[2].a>=mn) {
            double t2=max(a[2].a-mn-d(a[1],a[2]),0.0);
            double t3=max(a[3].a-mn-d(a[1],a[3]),0.0);
            if (a[1].a+t2+t3>=mn) return true;
            if (d(a[1],a[3])<=d(a[1],a[2])) {
                t2=max(a[2].a-mn-d(a[2],a[3]),0.0);
                t3=max(a[3].a+t2-mn-d(a[1],a[3]),0.0);
                return (a[1].a+t3>=mn);
            } else {
                t3=max(a[3].a-mn-d(a[2],a[3]),0.0);
                t2=max(a[2].a+t3-mn-d(a[1],a[2]),0.0);
                return (a[1].a+t2>=mn);
            }
        } else {
            double t1=mn-a[1].a+d(a[1],a[3]);
            double t2=mn-a[2].a+d(a[2],a[3]);
            if (a[3].a-t1-t2>=mn) return true;
            if (d(a[3],a[1])<=d(a[3],a[2])) {
                t1=max(a[3].a-mn-d(a[1],a[3]),0.0);
                if (a[1].a+t1<mn) return false;
                t2=max(a[1].a+t1-mn-d(a[1],a[2]),0.0);
                return (a[2].a+t2>=mn);
            } else {
                t2=max(a[3].a-mn-d(a[2],a[3]),0.0);
                if (a[2].a+t2<mn) return false;
                t1=max(a[2].a+t2-mn-d(a[1],a[2]),0.0);
                return (a[1].a+t1>=mn);
            }
        }
    }
    void solve() {
        double lo=0,hi=1e9,ans=0,eps=1e-6;
        while (hi-lo>eps) {
            double mid=(lo+hi)/2;
            if (check(mid)) {
                ans=mid;
                lo=mid;
            } else hi=mid;
        }
        cout<<fixed<<ans<<'\n';
    }
}
namespace sub3{
    dat b[N+5];
    bool check(double mn) {
        for (int i=1;i<=n;i++) b[i]=a[i];
        for (int i=1;i<n;i++) {
            if (b[i].a>=mn) {
                double t=max(b[i].a-mn-(b[i+1].x-b[i].x),0.0);
                b[i+1].a+=t;
            } else {
                double t=mn-b[i].a+(b[i+1].x-b[i].x);
                b[i+1].a-=t;
            }
        }
        return (b[n].a>=mn);
    }
    void solve() {
        sort(a+1,a+1+n,comp);
        double lo=0,hi=1e9,ans=0,eps=1e-6;
        while (hi-lo>eps) {
            double mid=(lo+hi)/2;
            if (check(mid)) {
                ans=mid;
                lo=mid;
            } else hi=mid;
        }
        cout<<fixed<<ans<<'\n';
    }
}
int main() {
    freopen("DROUGHT.INP","r",stdin);
	freopen("DROUGHT.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].a;
    sort(a+1,a+1+n);
    if (n==1) cout<<a[1].a<<'\n';
    else if (n==2) sub1::solve();
    else if (n==3) sub2::solve();
    else sub3::solve();
}
/*
3
4 0 1
5 0 3
7 0 10
*/
