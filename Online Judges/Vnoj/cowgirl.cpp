#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--) {
        int m,n;
        cin>>m>>n;
        long long dp[m+1][n+1];
        for (int i=0;i<=m;i++)
            for (int j=0;j<=n;j++)
                dp[i][j]=1;
        dp[0][0]=0;
        for (int i=1;i<=m;i++) {
            for (int j=1;j<=n;j++) {
                dp[i][j]=dp[i-1][j]+dp[i][j-1]+dp[i-1][j-1];
                cout<<dp[i][j]<<' ';
            }
            cout<<endl;
        }
        cout<<dp[m][n]<<endl;
    }
}
