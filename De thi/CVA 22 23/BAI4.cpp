#include<bits/stdc++.h>
using namespace std;
const int N=500;
int m,n,ii,jj;
int a[N+5][N+5],dp[N+5][N+5];
int main() {
    cin>>m>>n>>ii>>jj;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
        }
    }
    for (int i=m;i>=1;i--) {
        for (int j=1;j<=n;j++) {
            if (a[i][j]==0||(i==m&&j==1)) continue;
            if (a[i+1][j-1]==1) dp[i][j]=max(dp[i][j],dp[i+1][j-1]+1);
            if (a[i+1][j]==1) dp[i][j]=max(dp[i][j],dp[i+1][j]);
            if (a[i][j-1]==1) dp[i][j]=max(dp[i][j],dp[i][j-1]);
        }
    }
//    for (int i=1;i<=m;i++) {
//        for (int j=1;j<=n;j++) cout<<dp[i][j]<<' ';
//        cout<<endl;
//    }
    int res=dp[m-ii][jj+1];
    cout<<res+ii-res+jj-res<<' '<<res;
}
/*
8 10
6 5
0 1 0 0 0 0 0 0 1 0
0 0 0 0 1 1 0 0 0 0
0 0 1 1 0 1 0 0 0 0
0 1 0 0 1 1 0 0 0 0
0 1 0 1 0 1 0 0 0 0
0 1 1 0 0 1 0 0 0 0
0 1 0 0 1 1 0 0 0 0
1 1 1 1 1 1 0 0 0 0
*/
