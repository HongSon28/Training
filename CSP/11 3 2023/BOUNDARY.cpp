#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("BOUNDARY.INP","r",stdin);
    freopen("BOUNDARY.OUT","w",stdout);
    long long n;
    cin>>n;
    pair<long long,long long>a[n];
    for (int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
    long long dp1[n],dp2[n];
    dp1[0]=a[0].second;
    dp2[0]=a[0].first;
    for (int i=1;i<n;i++) {
            dp1[i]=dp1[i-1]+abs(a[i-1].first-a[i].first)+a[i].second;
            dp2[i]=dp1[i-1]+abs(a[i-1].first-a[i].second)+a[i].first;
            dp1[i]=max(dp2[i-1]+abs(a[i-1].second-a[i].first)+a[i].second,dp1[i]);
            dp2[i]=max(dp2[i-1]+abs(a[i-1].second-a[i].second)+a[i].first,dp2[i]);
    }
    cout<<max(dp1[n-1],dp2[n-1]);
}
