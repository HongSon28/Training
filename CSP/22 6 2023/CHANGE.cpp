#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int s,n;
int dp[N+5];
int a[101];
int main() {
    freopen("CHANGE.INP","r",stdin);
    freopen("CHANGE.OUT","w",stdout);
    cin>>s>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=N;i++) dp[i]=INT_MAX;
    for (int i=1;i<=n;i++) {
        for (int j=0;j<=N-a[i];j++) dp[j+a[i]]=min(dp[j+a[i]],dp[j]+1);
    }
    for (int i=1;i<=n;i++) {
        for (int j=a[i];j<=N;j++) dp[j-a[i]]=min(dp[j-a[i]],dp[j]+1);
    }
    cout<<dp[s];
}
