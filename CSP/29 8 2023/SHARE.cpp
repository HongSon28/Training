#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
pair<long long, long long>a[N+5];
long long b[N+5],d[N+5];
int n;
long long m,res=-1;
bool check(long long dif) {
    long long temp=m-a[1].first;
    long long mx=a[1].first+dif;
    for (int i=2;i<=n;i++) {
        temp-=min(a[i].first,mx);
    }
    if (temp<=0) return true;
    return false;
}
int main() {
    freopen("SHARE.INP","r",stdin);
    freopen("SHARE.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i].first;
        a[i].second=i;
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
    long long sum=a[1].first,mx=a[1].first+res;
    b[1]=a[1].first;
    for (int i=2;i<=n;i++) {
        b[i]=min(a[i].first,mx);
        sum+=b[i];
    }
    if (sum>m) {
        long long temp=sum-m;
        for (int i=n;i>=2;i--) {
            long long t=min(temp,b[i]-a[1].first);
            b[i]-=t;
            temp-=t;
            if (temp==0) break;
        }
    }
    for (int i=1;i<=n;i++)
        d[a[i].second]=b[i];
    for (int i=1;i<=n;i++) cout<<d[i]<<' ';
}
