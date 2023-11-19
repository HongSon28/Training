#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e3;
int n,m;
ll a[N+5],b[N+5];
ll dp[N+5][N+5],mn[N+5][N+5];
int main() {
    freopen("GLOVE.INP","r",stdin);
    freopen("GLOVE.OUT","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) cin>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            dp[i][j]=1e18;
    for (int i=1;i<=n;i++) {
        for (int j=i;j<=m;j++) {
            dp[i][j]=min(dp[i][j],mn[i-1][j-1]+abs(a[i]-b[j]));
        }
        mn[i][i-1]=1e18;
        for (int j=i;j<=m;j++) mn[i][j]=min(mn[i][j-1],dp[i][j]);
    }
//    for (int i=1;i<=n;i++) {
//        for (int j=1;j<=m;j++)
//            cout<<dp[i][j]<<' ';
//        cout<<endl;
//    }
    cout<<mn[n][m];
}
