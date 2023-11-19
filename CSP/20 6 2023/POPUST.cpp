#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
pair<long long,long long>p[N+5];
long long sum[N+5];
bool comp(pair<long long,long long>a,pair<long long,long long>b) {
    if (a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}
long long dif[N+5];
long long mn[N+5];
int main() {
    freopen("POPUST.INP","r",stdin);
    freopen("POPUST.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>p[i].first>>p[i].second;
    sort(p+1,p+1+n,comp);
    dif[0]=-1e18;
    for (int i=1;i<=n;i++) {
        sum[i]=sum[i-1]+p[i].second;
        dif[i]=max(dif[i-1],p[i].second-p[i].first);
    }
    mn[n+1]=1e18;
    for (int i=n;i>=1;i--) mn[i]=min(mn[i+1],p[i].first);
    for (int i=1;i<=n;i++) cout<<min(sum[i-1]+mn[i],sum[i]-dif[i])<<endl;
}
