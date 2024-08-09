#include<bits/stdc++.h>
using namespace std;
const int N=100,M=10;
int m,n,s,k;
long long dp[N+1][M+1][4*N*M+1],mod=111539786;
bool block[N+1][M+1];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>m>>n>>k>>s;
    int vertice=(m+1)*(n+1),mx=vertice*3-6;
    k+=s+1;
    int edge=vertice-2+k;
    while (s--) {
        int i,j;
        cin>>i>>j;
        block[i][j]=true;
    }
    for (int i=0;i<=n;i++) dp[0][i][i]=1;
    for (int i=1;i<=m;i++) {
        for (int j=0;j<mx;j++) {
            dp[i][0][j+1]+=dp[i-1][n][j];
            dp[i][0][j+1]%=mod;
        }
        for (int j=1;j<=n;j++) {
            for (int t=0;t<mx;t++) {
                if (!block[i][j]) {
                    if (i<m&&!block[i+1][j]) {
                        dp[i][j][t+1]+=dp[i][j-1][t]; //chon N
                        dp[i][j][t+1]%=mod;
                    }
                    if (j<n&&!block[i][j+1]) {
                        dp[i][j][t+1]+=dp[i][j-1][t]; //chon D
                        dp[i][j][t+1]%=mod;
                    }
                }
                if (t+2<=mx) {
                    dp[i][j][t+2]+=dp[i][j-1][t]; //chon DN
                    dp[i][j][t+2]%=mod;
                }
            }
        }
    }
    cout<<dp[m][n][edge];
}
