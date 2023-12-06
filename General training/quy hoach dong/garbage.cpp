#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1001][1001];
int dp[1001][1001];
vector<int>t;
void truyvet(int i, int j) {
    if (i==1||j==1) return;
    else {
        if (dp[i][j]==dp[i-1][j]+a[i][j]) {
            t.push_back(j);
            truyvet(i-1,j);
        } else if (dp[i][j]==dp[i-1][j-1]+a[i][j]) {
            t.push_back(j-1);
            truyvet(i-1,j-1);
        } else {
            t.push_back(j+1);
            truyvet(i-1,j+1);
        }
    }
}
int main() {
    int res=INT_MIN;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin>>a[i][j];
    //cout<<endl;
    for (int i=0;i<=n;i++) dp[i][0]=0;
    for (int i=0;i<=m;i++) dp[0][m]=0;
    for (int j=1;j<=m;j++) {
        for (int i=1;i<=n;i++) {
            dp[i][j]=max(dp[i-1][j-1],dp[i][j-1]);
            dp[i][j]=max(dp[i][j],dp[i+1][j-1]);
            dp[i][j]+=a[i][j];
            //cout<<dp[i][j]<<' ';
        }
        //cout<<endl;
    }
    for (int i=1;i<=m;i++) res=max(res,dp[n][i]);
    cout<<res<<endl;
    //t.push_back(j);
    //truyvet(i,j);
    //for (int k=t.size()-1;k>=0;k--) cout<<t[k]<<endl;
}
