#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long a[N+10],dp[N+10],res,inf=1e18;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n+5;i++) dp[i]=-inf;
    for (int i=1;i<=n+5;i++) {
        for (int x=1;x<=3;x++) {
            if (i<x*2) continue;
            long long t1=0;
            for (int j=i-x*2+1;j<=i-x;j++) t1+=a[j];
            dp[i]=max(dp[i],dp[i-x*2]+t1);
            res=max(res,dp[i]);
        }
    }
    cout<<res;
}
