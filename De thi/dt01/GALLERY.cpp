#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m;
struct dat{
    long long s,t,c;
};
dat a[N+5];
long long dp[N+5];
long long inf=1e16;
long long res=inf;
bool comp(dat x,dat y) {
    if (x.s==y.s){
        if (x.t==y.t) {
            return x.c<y.c;
        }
        return x.t<y.t;
    }
    return x.s<y.s;
}
long long getmin(long long l,long long r) {
    long long mx=inf;
    for (long long i=l;i<=r;i++) {
        mx=min(mx,dp[i]);
    }
    return mx;
}
int main() {
    cin>>n>>m;
    for (int i=1;i<=m;i++) cin>>a[i].s>>a[i].t>>a[i].c;
    sort(a+1,a+1+m,comp);
    for (int i=1;i<=N;i++) dp[i]=inf;
    for (int i=1;i<=m;i++) {
        long long temp=getmin(a[i].s,a[i].t-1);
        dp[a[i].t]=min(dp[a[i].t],temp+a[i].c);
    }
    for (int i=n;i<=N;i++) {
        res=min(res,dp[i]);
    }
    cout<<res;
}
