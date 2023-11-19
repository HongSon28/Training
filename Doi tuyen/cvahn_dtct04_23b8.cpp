#include<bits/stdc++.h>
using namespace std;
const int N=5e3,maxN=1e6;
int n;
long long p,q;
pair<long long,long long>a[N+5];
long long dp[maxN+5];
long long inf=1e18,res=inf;
long long getmin(long long l,long long r) {
    long long mn=inf;
    for (long long i=l;i<=r;i++) {
        mn=min(mn,dp[i]);
    }
    return mn;
}
int main() {
    freopen("PHU.INP","r",stdin);
    freopen("PHU.OUT","w",stdout);
    cin>>n>>p>>q;
    for (int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    if (p<1) {
        long long temp=1-p;
        p+=temp,q+=temp;
        for (int i=1;i<=n;i++) {
            a[i].first+=temp;
            a[i].second+=temp;
        }
    }
    if (p>1) {
        long long temp=p-1;
        p-=temp,q-=temp;
        for (int i=1;i<=n;i++) {
            a[i].first-=temp;
            a[i].second-=temp;
        }
    }
    for (int i=1;i<=n;i++) {
        if (a[i].first>q||a[i].second<p) {
            a[i].first=a[i].second=0;
            continue;
        }
        if (a[i].first<p) a[i].first=p;
        if (a[i].second>q) a[i].second=q;
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=maxN;i++) dp[i]=inf;
    for (int i=1;i<=n;i++) {
        long long temp=getmin(a[i].first-1,a[i].second-1);
        dp[a[i].second]=min(dp[a[i].second],temp+1);
    }
    res=dp[q];
    if (res==inf) cout<<0;
    else cout<<res;
}
/*
5 0 5
-1 3
2 4
3 6
2 4
4 6
*/
