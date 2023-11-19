#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long m,n,k,res=-2;
long long a[N+5];
long long sum[N+5];
int main() {
    cin>>m>>n>>k;
    for (int i=1;i<=m;i++) cin>>a[i];
    sort(a+1,a+1+m,greater<long long>());
    for (int i=1;i<=m;i++) sum[i]=sum[i-1]+a[i];
    for (int i=n;i<=m;i++) {
        if (a[i-n+1]-a[i]<=k) res=max(res,sum[i]-sum[i-n]);
    }
    cout<<res;
}
