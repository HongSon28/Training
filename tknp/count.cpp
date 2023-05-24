#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[100001],sum[100001];
long long res=0,resx;
void tknp (long long m) {
    long long lo=1,hi=m;
    while (lo<hi) {
        long long mid=(lo+hi)/2;
        if (a[m]*(m-mid+1)-(sum[m]-sum[mid-1])<=k) {
            if (res<m-mid+1) {
                res=m-mid+1;
                resx=a[m];
            }
            hi=mid;
        } else {
            lo=mid+1;
        }
    }
}
int main() {
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++) sum[i]+=sum[i-1]+a[i];
    for (int i=1;i<=n;i++) {
        tknp(i);
    }
    cout<<res<<' '<<resx;
}
