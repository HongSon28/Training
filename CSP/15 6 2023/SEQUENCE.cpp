#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long k;
long long a[N+5],sum[N+5];
long long idx[N+5];
long long res;
long long mx;
bool check(long long m) {
    long long s[N+5]={},ms[N+5];
    ms[0]=1e18;
    for (int i=1;i<=n;i++) {
        s[i]=s[i-1]+a[i]-m;
        ms[i]=min(ms[i-1],s[i]);
        //cout<<i<<' '<<s[i]<<' '<<idx[i]<<' '<<ms[idx[i]-1]<<endl;
        if (idx[i]!=-1&&s[i]-ms[idx[i]-1]>=0) return true;
    }
    return false;
}
int main() {
    freopen("SEQUENCE.INP","r",stdin);
    freopen("SEQUENCE.OUT","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
        idx[i]=-1;
        mx=max(mx,a[i]);
    }
    for (int i=1;i<=n;i++) {
        if (sum[i]<k) continue;
        idx[i]=(upper_bound(sum+1,sum+1+i,sum[i]-k)-sum);
    }
    long long lo=0,hi=mx;
    while (lo<=hi) {
        long long mid=(lo+hi)/2;
        if (check(mid)) {
            res=mid;
            lo=mid+1;
        } else hi=mid-1;
    }
    cout<<res;
}
