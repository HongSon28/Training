#include<bits/stdc++.h>
using namespace std;
const int N=11000000,INF=1e9;
int m,q,temp,dp[N+5];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>m>>q;
    while (m--) {
        cin>>temp;
        for (int i=temp-1;i<=N;i+=temp) dp[i]=max(dp[i],temp-1);
    }
    for (int i=N-1;i>=0;i--) dp[i]=max(dp[i+1]-1,dp[i]);
    for (int i=1;i<=N;i++) {
        if (dp[i]>0) dp[i]=1+dp[i-dp[i]];
        else dp[i]=INF;
    }
    while (q--) {
        cin>>temp;
        if (dp[temp]>=INF) cout<<"oo"<<'\n';
        else cout<<dp[temp]<<'\n';
    }
}
