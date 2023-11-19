#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>v;
int w[1001];
int c[1001];
int cnt[1001];
int dp[1001][10001];
int res[1001];
void truyvet(int i, int j) {
    if(i == 0 || j == 0) return;
    if (dp[i][j]==dp[i-1][j]) truyvet(i-1,j);
    else {
        int val=c[i];
        int weight=w[i];
        int cnt=1;
        while (dp[i][j]!=dp[i-1][j-weight]+val) {
            cnt++;
            val+=c[i];
            weight+=w[i];
        }
        res[i]=cnt;
        truyvet(i-1,j-weight);
    }
}
int main() {
    freopen("CHONDO3.INP","r",stdin);
    freopen("CHONDO3.OUT","w",stdout);
    int n,W;
    cin>>n>>W;
    for (int i=1;i<=n;i++) cin>>w[i]>>c[i]>>cnt[i];
    for (int i=0;i<=n;i++) dp[i][0]=0;
    for (int i=0;i<=W;i++) dp[0][i]=0;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=W;j++) {
            dp[i][j]=dp[i-1][j];
            int val=c[i];
            int t=1;
            int weight=w[i];
            while (weight<=j&&t<=cnt[i]) {
                dp[i][j]=max(dp[i-1][j-weight]+val,dp[i][j]);
                weight+=w[i];
                val+=c[i];
                t++;
            }
            //cout<<dp[i][j]<<' ';
        }
        //<<endl;
    }
    cout<<dp[n][W]<<endl;
    truyvet(n,W);
    for (int i=1;i<=n;i++)cout<<res[i]<<'\n';
}
/*
10 14
10 10 1
2 3 3
9 3 3
3 6 4
5 10 4
4 7 2
5 6 5
1 1 3
9 6 6
7 6 5
*/
