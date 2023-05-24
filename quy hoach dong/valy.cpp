#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>v;
int w[101];
int c[101];
int dp[101][101];
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
        v.push_back(make_pair(i,cnt));
        truyvet(i-1,j-weight);
    }
}
int main() {
    int n,W;
    cin>>n>>W;
    for (int i=1;i<=n;i++) cin>>w[i]>>c[i];
    for (int i=0;i<=n;i++) dp[i][0]=0;
    for (int i=0;i<=W;i++) dp[0][i]=0;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=W;j++) {
            dp[i][j]=dp[i-1][j];
            int val=c[i];
            int weight=w[i];
            while (weight<=j) {
                dp[i][j]=max(dp[i-1][j-weight]+val,dp[i][j]);
                weight+=w[i];
                val+=c[i];
            }
            //cout<<dp[i][j]<<' ';
        }
        //<<endl;
    }
    cout<<dp[n][W]<<endl;
    truyvet(n,W);
    for (int i=v.size()-1;i>=0;i--) cout<<v[i].first<<' '<<v[i].second<<endl;
}
