#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n,res;
int a[N+5],dp1[N+5],dp2[N+5];
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    dp1[1]=a[1];
    for (int i=2;i<=n;i++) {
        dp1[i]=a[i];
        for (int j=i-1;j>=1;j--) {
            if (a[i]>a[j]) dp1[i]=max(dp1[i],dp1[j]+a[i]);
        }
    }
    dp2[n]=a[n];
    for (int i=n-1;i>=1;i--) {
        dp2[i]=a[i];
        for (int j=i+1;j<=n;j++) {
            if (a[i]>a[j]) dp2[i]=max(dp2[i],dp2[j]+a[i]);
        }
    }
    for (int i=2;i<n;i++) {
        res=max(res,dp1[i]+dp2[i]-a[i]);

    }
    cout<<res;
}
