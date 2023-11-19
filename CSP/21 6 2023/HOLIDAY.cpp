#include<bits/stdc++.h>
using namespace std;
const int N=5e3;
int n;
long long a[N+5];
long long dp[N+5];
long long sum[N+5];
long long cost(int l,int r) {
    if ((r-l+1)%2==0) {
        int left=l,right=l+(r-l)/2;
        return (sum[right]-sum[left-1])*2;
    } else {
        int mid=(r+l)/2;
        return sum[mid]-sum[l-1]+sum[mid-1]-sum[l-1];
    }
}
int main() {
    freopen("HOLIDAY.INP","r",stdin);
    freopen("HOLIDAY.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for (int i=1;i<=n;i++) {
        for (int j=i-1;j>=0;j--) {
            dp[i]=max(dp[i],dp[j]+cost(j+1,i-1));
        }
    }
    cout<<dp[n];
}
