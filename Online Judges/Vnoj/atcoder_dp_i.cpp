#include<bits/stdc++.h>
using namespace std;
const int N=3e3;
int n;
double p[N];
double dp[N][N];
double res;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i];
    dp[0][0]=1;
    for (int i=1;i<=n;i++) dp[i][0]=dp[i-1][0]*(1-p[i]);
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=i;j++) {
            if (i==j) dp[i][j]=dp[i-1][j-1]*p[i];
            else dp[i][j]=dp[i-1][j-1]*p[i]+dp[i-1][j]*(1-p[i]);
        }
    }
    for (int i=n/2+1;i<=n;i++) res+=dp[n][i];
    cout.precision(10);
    cout<<fixed<<res;
}
