#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    s="a"+s;
    int dp[n+2][n+2];
    for (int i=1;i<=n;i++) dp[i][i]=0;
    for (int i=1;i<=n-1;i++) {
        if (s[i]==s[i+1]) dp[i][i+1]=0;
        else dp[i][i+1]=1;
    }
    for (int len=3;len<=n;len++) {
        for (int i=1;i<=n-len+1;i++) {
            int j=i+len-1;
            if (s[i]==s[j]) {
                dp[i][j]=dp[i+1][j-1];
            } else {
                dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
            }
        }
    }
    cout<<dp[1][n];
}
