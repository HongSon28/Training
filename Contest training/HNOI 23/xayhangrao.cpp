#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q,k;
pair<long long,long long>p[N+5];
long long mx[N+5],mn[N+5],suf[N+5];
long long sum[N+5];
bool comp(pair<long long,long long>a,pair<long long,long long>b) {
    return a.first>b.first;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("xayhangrao.inp","r",stdin);
    freopen("xayhangrao.out","w",stdout);
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>p[i].first;
    for (int i=1;i<=n;i++) cin>>p[i].second;
    sort(p+1,p+1+n,comp);
    mx[0]=LLONG_MIN;
    mn[0]=LLONG_MAX;
    for (int i=1;i<=n;i++) {
        sum[i]=sum[i-1]+p[i].first;
        mx[i]=max(mx[i-1],p[i].second-p[i].first);
        mn[i]=min(mn[i-1],p[i].first);
    }
    suf[n+1]=LLONG_MIN;
    for (int i=n;i>=1;i--) suf[i]=max(suf[i+1],p[i].second);
    while (q--) {
        cin>>k;
        long long t1=sum[k]+mx[k];
        long long t2=sum[k]-mn[k]+suf[k+1];
        cout<<max(t1,t2)<<' ';
    }
}
