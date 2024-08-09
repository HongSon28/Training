#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int m,n;
string x,y;
int dp[N+5][N+5];
int main() {
    cin>>x>>y;
    m=x.size(),n=y.size();
    x=' '+x,y=' '+y;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (x[i]==y[j]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<m+n-dp[m][n];
}
