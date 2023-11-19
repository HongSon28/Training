#include<bits/stdc++.h>
using namespace std;
const int N=3000,M=N*12;
int n,t[N+5],d[N+5],sum,s;
int dp[N+5][M+5],inf=1e9;
vector<int>v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>t[i]>>d[i];
        sum+=t[i]+d[i];
    }
    s=sum/2+6;
    for (int i=0;i<=N;i++)
        for (int j=0;j<=s;j++)
            dp[i][j]=inf;
    dp[0][0]=0;
    for (int i=1;i<=n;i++) {
        for (int j=0;j<=s;j++) {
            if (j>=t[i]) dp[i][j]=min(dp[i][j],dp[i-1][j-t[i]]);
            if (j>=d[i]) dp[i][j]=min(dp[i][j],dp[i-1][j-d[i]]+1);
        }
    }
    for (int i=sum/2;i>=0;i--) {
        if (dp[n][i]!=inf&&dp[n][sum-i]!=inf) {
            s=i;
            break;
        }
    }
    cout<<sum-s*2<<'\n'<<dp[n][s]<<'\n';
    while (n>0&&s>0) {
        if (dp[n-1][s-t[n]]==dp[n][s]) {
            s-=t[n];
            n--;
        } else {
            s-=d[n];
            v.push_back(n);
            n--;
        }
    }
    reverse(v.begin(),v.end());
    for (auto i:v) cout<<i<<'\n';
}
