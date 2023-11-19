#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,k;
long long a[N+5];
long long pre[N+5],suf[N+5];
long long sum=0;
long long res=1e18;
int main() {
    freopen("GIFTS.INP","r",stdin);
    freopen("GIFTS.OUT","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=k;i++) sum+=a[i];
    pre[k]=sum;
    for (int i=k+1;i<=n;i++) {
        sum+=a[i];
        sum-=a[i-k];
        pre[i]=max(pre[i-1],sum);
    }
    sum=0;
    for (int i=n;i>=n-k+1;i--) sum+=a[i];
    suf[n-k+1]=sum;
    for (int i=n-k;i>=1;i--) {
        sum+=a[i];
        sum-=a[i+k];
        suf[i]=max(suf[i+1],sum);
    }
    for (int i=k;i<=n;i++) {
        res=min(res,max(pre[i-k],suf[i+1]));
    }
    cout<<res;
}
