#include<bits/stdc++.h>
using namespace std;
const int N=5e4;
int n,m,res;
int a[N+5];
pair<int,int>p[N+5];
int suf[N+5];
int bs(int k) {
    int lo=1,hi=m,ans=m;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (p[mid].first>=k) {
            ans=mid;
            hi=mid-1;
        } else lo=mid+1;
    }
    return ans;
}
int main() {
    freopen("BAI3.INP","r",stdin);
    freopen("BAI3.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    cin>>m;
    for (int i=1;i<=m;i++) cin>>p[i].first>>p[i].second;
    sort(p+1,p+1+m);
    suf[m+1]=1e9;
    for (int i=m;i>=1;i--) suf[i]=min(suf[i+1],p[i].second);
    for (int i=1;i<=n;i++) {
        int pos=bs(a[i]);
        res+=suf[pos];
    }
    cout<<res;
}
