#include<bits/stdc++.h>
using namespace std;
const int N=5e3;
string s;
int n;
int dp[N+5],mn[N+5][N+5],g[N+5][N+5],inf=1e9;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s;
    n=s.size();
    s=' '+s;
    for (int i=1;i<=n;i++) dp[i]=inf;
    for (int i=1;i<=n;i++)
        for (int j=i;j<=n;j++)
            mn[i][j]=j-i+1;
    for (int u=n;u>=1;u--) {
        for (int v=n;v>=1;v--) {
            if (s[u]==s[v]) g[u][v]=g[u+1][v+1]+1;
            else g[u][v]=0;
        }
    }
    for (int u=1;u<=n;u++) {
        for (int v=u;v<=n;v++) {
            //cout<<u<<' '<<v<<' '<<mn[u][v]<<endl;
            if (mn[u][v]==v-u+1) {
                int k=v-u+1;
                for (int l=u+k;l+k-1<=n;l+=k) {
                    int r=l+k-1;
                    //cout<<u<<' '<<v<<' '<<l<<' '<<r<<' '<<g[l][u]<<endl;
                    if (g[l][u]>=k) mn[u][r]=min(mn[u][r],k);
                    else break;
                }
            }
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=0;j<i;j++) {
            dp[i]=min(dp[i],dp[j]+mn[j+1][i]);
        }
    }
    cout<<dp[n];
}
