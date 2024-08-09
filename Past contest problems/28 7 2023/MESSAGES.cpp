#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,m;
long long c[N+5][N+5],dp[N+5][N+5],cnt[N+5];
long long inf=1e9;
int main() {
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>c[i][j];
    for (int i=1;i<=n;i++) dp[i][0]=inf;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            dp[i][j]=inf;
            for (int k=0;k<=i;k++) {
                dp[i][j]=min(dp[i][j],dp[i-k][j-1]+c[k][j]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
    int i=n,j=m;
    while (i>0&&j>0) {
        for (int k=0;k<=i;k++) {
            if (dp[i][j]==dp[i-k][j-1]+c[k][j]) {
                cnt[j]=k;
                i-=k;
                j--;
                break;
            }
        }
    }
    for (int i=1;i<=m;i++) cout<<cnt[i]<<endl;
}
