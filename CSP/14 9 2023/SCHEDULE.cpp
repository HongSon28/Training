#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
struct dat{
    long long a,c,id;
    bool operator < (const dat &other) const {
        return c<other.c;
    }
};
dat a[N+5];
long long b[N+5],c[N+5];
int n;
long long d,res=-1;
bool check(long long dif) {
    long long temp=d-a[1].c;
    long long mx=a[1].c+dif;
    for (int i=2;i<=n;i++) {
        long long t=min(a[i].c,mx);
        if (t<a[i].a) return false;
        temp-=min(a[i].c,mx);
    }
    if (temp<=0) return true;
    return false;
}
int main() {
    freopen("SCHEDULE.INP","r",stdin);
    freopen("SCHEDULE.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>d;
    for (int i=1;i<=n;i++) {
        cin>>a[i].a>>a[i].c;
        a[i].id=i;
    }
    sort(a+1,a+1+n);
    long long lo=0,hi=1e9;
    while (lo<=hi) {
        long long mid=(lo+hi)/2;
        if (check(mid)) {
            res=mid;
            hi=mid-1;
        } else lo=mid+1;
    }
    if (res==-1) {
        cout<<-1;
        return 0;
    }
    long long sum=a[1].c,mx=a[1].c+res;
    b[1]=a[1].c;
    for (int i=2;i<=n;i++) {
        b[i]=min(a[i].c,mx);
        sum+=b[i];
    }
    long long temp=sum-d;
    if (sum>d) {
        for (int i=n;i>=2;i--) {
            long long t=min(temp,b[i]-a[1].c);
            if (b[i]-t<a[i].a) t=b[i]-a[i].a;
            b[i]-=t;
            temp-=t;
            if (temp==0) break;
        }
        if (temp>0) {
            long long delta=temp/n;
            for (int i=1;i<=n;i++) {
                long long t=min(delta,b[i]-a[i].a);
                b[i]-=t;
                temp-=t;
            }
        }
    }
    if (temp>0) {
        cout<<-1;
        return 0;
    }
    for (int i=1;i<=n;i++) c[a[i].id]=b[i];
    for (int i=1;i<=n;i++) cout<<c[i]<<' ';
}

