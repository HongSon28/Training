#include<bits/stdc++.h>
using namespace std;
int dp[2001][2001];
int main() {
    string a,b;
    cin>>a>>b;
    int n=a.size(),m=b.size();
    a='0'+a;
    b='0'+b;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if (a[i]==b[j]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
        }
    }
    cout<<dp[n][m];
}
