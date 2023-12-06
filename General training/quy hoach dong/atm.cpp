#include<bits/stdc++.h>
using namespace std;
int n,s;
int d[101],k[101];
int dp[10001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,0,sizeof(dp));
    cin>>n>>s;
    for (int i=1;i<=n;i++) cin>>d[i];
    for (int i=1;i<=s;i++) {
        int temp=1000000;
        for (int j=1;j<=n;j++) {
            if (d[j]<=i) temp=min(temp,dp[i-d[j]]+1);
        }
        if (dp[i]==1000000) dp[i]=0;
        else dp[i]=temp;
    }
    cout<<dp[s]<<endl;
    int i=s;
    while (i>0) {
        for (int j=1;j<=n;j++) {
            if (i>=d[j]) {
                if (dp[i]==dp[i-d[j]]+1) {
                    k[j]++;
                    i-=d[j];
                    break;
                }
            }
        }
    }
    for (int i=1;i<=n;i++) cout<<k[i]<<' ';
}
