#include<bits/stdc++.h>
using namespace std;
const int N=2000;
int n;
pair<long long,long long>p[N+5];
long long sum[N+5];
long long res;
int bs(int i,int j) {
    int lo=1,hi=n,ans;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (p[i].first*p[i].first+p[j].first*p[j].first>p[mid].first*p[mid].first) {
            ans=mid;
            lo=mid+1;
        } else hi=mid-1;
    }
    return ans;
}
int main() {
    freopen("TRIACU.INP","r",stdin);
    freopen("TRIACU.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    sort(p+1,p+1+n);
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+p[i].second;
    for (int i=1;i<=n;i++) {
        for (int j=i+1;j<=n;j++) {
            int k=bs(i,j);
            if (k>j) res+=p[i].second*p[j].second*(sum[k]-sum[j]);
        }
    }
    cout<<res;
}
