#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("OVERPASS.INP","r",stdin);
    freopen("OVERPASS.OUT","w",stdout);
    int n,res=0;
    cin>>n;
    char s[n+5];
    for (int i=1;i<=n;i++) cin>>s[i];
    int dp1[n+5],dp2[n+5];
    dp1[0]=0,dp2[0]=1;
    for (int i=1;i<=n;i++) {
        if (s[i]=='L') {
            dp1[i]=min(dp1[i-1]+1,dp2[i-1]+1);
            dp2[i]=min(dp1[i-1]+1,dp2[i-1]);
        } else if (s[i]=='R') {
            dp1[i]=min(dp1[i-1],dp2[i-1]+1);
            dp2[i]=min(dp1[i-1]+1,dp2[i-1]+1);
        } else {
            dp1[i]=min(dp1[i-1]+1,dp2[i-1]+2);
            dp2[i]=min(dp1[i-1]+2,dp2[i-1]+1);
        }
    }
    cout<<min(dp1[n]+1,dp2[n]);
}
