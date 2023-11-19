#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q;
long long c[N+5],v[N+5],dp[N+5],a,b,inf=1e18;
int main() {
    freopen("BALLS.INP","r",stdin);
    freopen("BALLS.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>v[i];
    for (int i=1;i<=n;i++) cin>>c[i];
    while (q--) {
        cin>>a>>b;
        for (int i=1;i<=n;i++) dp[i]=-inf;
        long long mx1=0,mx2=0,res=0;
        long long col1=0,col2=0;
        for (int i=1;i<=n;i++) {
            dp[c[i]]=max(dp[c[i]],dp[c[i]]+v[i]*a);
            if (col1!=c[i]) dp[c[i]]=max(dp[c[i]],mx1+v[i]*b);
            if (col2!=c[i]) dp[c[i]]=max(dp[c[i]],mx2+v[i]*b);
            if (c[i]!=col1&&c[i]!=col2) {
                if (mx2<dp[c[i]]) {
                    mx2=dp[c[i]];
                    col2=c[i];
                }
            } else if (c[i]==col1) {
                if (mx1<dp[c[i]]) {
                    mx1=dp[c[i]];
                    col1=c[i];
                }
            } else if (c[i]==col2) {
                if (mx2<dp[c[i]]) {
                    mx2=dp[c[i]];
                    col2=c[i];
                }
            }
            if (mx1<mx2) {
                swap(mx1,mx2);
                swap(col1,col2);
            }
        }
        for (int i=1;i<=n;i++) res=max(res,dp[i]);
        cout<<res<<'\n';
    }
}
