#include<bits/stdc++.h>
using namespace std;
const int N=400;
int dp[N+5][N+5][N+5];
int main() {
    //freopen("Xauchung3.inp","r",stdin);
    //freopen("Xauchung3.out","w",stdout);
    string a,b,c;
    cin>>a>>b>>c;
    int n=a.size(),m=b.size(),p=c.size();
    a=' '+a,b=' '+b,c=' '+c;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            for (int k=1;k<=p;k++) {
                dp[i][j][k]=max({dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1]});
                if (a[i]==b[j]&&a[i]==c[k]) {
                    dp[i][j][k]=max(dp[i-1][j-1][k-1]+1,dp[i][j][k]);
                }
            }
        }
    }
    cout<<dp[n][m][p];
}
