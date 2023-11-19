#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n;
long long l,res;
long long a[N+5],b[N+5],c[N+5],d[N+5];
long long cd[N*N+5];
long long bs1(long long val) {
    long long lo=1,hi=n*n,mid,ans=0;
    while (lo<=hi) {
        mid=(lo+hi)/2;
        if (cd[mid]==val) {
            ans=mid;
            hi=mid-1;
        } else if (cd[mid]>val) hi=mid-1;
        else lo=mid+1;
    }
    return ans;
}
long long bs2(long long val) {
    long long lo=1,hi=n*n,mid,ans=-1;
    while (lo<=hi) {
        mid=(lo+hi)/2;
        if (cd[mid]==val) {
            ans=mid;
            lo=mid+1;
        } else if (cd[mid]>val) hi=mid-1;
        else lo=mid+1;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("TERA.INP","r",stdin);
    freopen("TERA.OUT","w",stdout);
    cin>>n>>l;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1;i<=n;i++) cin>>c[i];
    for (int i=1;i<=n;i++) cin>>d[i];
    int t=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cd[++t]=a[i]+b[j];
    sort(cd+1,cd+1+n*n);
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            long long ll=bs1(l-(c[i]+d[j]));
            long long r=bs2(l-(c[i]+d[j]));
            res+=r-ll+1;
        }
    }
    cout<<res;
}
