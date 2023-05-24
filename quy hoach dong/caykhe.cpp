#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int w[101];
int c[101];
int dp[101][101];
void truyvet(int i, int j) {
    if(i == 0 || j == 0) return;
    if(w[i] <= j && dp[i][j] == dp[i-1][j-w[i]] + c[i])
    {
        v.push_back(i);
        truyvet(i-1,j-w[i]);
    }
    else
    {
        truyvet(i-1,j);
    }
}
int main() {
    int n,W;
    cin>>n>>W;
    for (int i=1;i<=n;i++) cin>>c[i]>>w[i];
    for (int i=0;i<=n;i++) dp[i][0]=0;
    for (int i=0;i<=W;i++) dp[0][i]=0;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=W;j++) {
            dp[i][j]=dp[i-1][j];
            if (j>=w[i]&&dp[i-1][j-w[i]]+c[i]>dp[i][j]) {
                dp[i][j]=dp[i-1][j-w[i]]+c[i];
            }
            //cout<<dp[i][j]<<' ';
        }
        //cout<<endl;
    }
    cout<<dp[n][W]<<endl;
    truyvet(n,W);
    for (int i=v.size()-1;i>=0;i--) cout<<v[i]<<' ';
}
