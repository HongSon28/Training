#include<bits/stdc++.h>
using namespace std;
const int N=2500;
int n;
pair<long long, long long>p[N+5];
bool comp (pair<int,int>a,pair<int,int>b) {
    return a.first+a.second<b.first+b.second;
}
long long dp[N+5][N+5];
long long inf=1e18;
int res;
int main() {
    freopen("STACK.INP","r",stdin);
    freopen("STACK.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i].first;
    for (int i=1;i<=n;i++) cin>>p[i].second;
    sort(p+1,p+1+n,comp);
    for (int i=0;i<=N;i++)
        for (int j=0;j<=N;j++)
            dp[i][j]=inf;
    for (int i=0;i<=n;i++) dp[i][0]=0;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            dp[i][j]=dp[i-1][j];
            if (dp[i-1][j-1]<=p[i].second) dp[i][j]=min(dp[i][j],dp[i-1][j-1]+p[i].first);
            //cout<<dp[i][j]<<' ';
        }
        //cout<<endl;
    }
    for (int i=1;i<=n;i++)
        if (dp[n][i]!=inf) res=max(res,i);
    cout<<res;
}
