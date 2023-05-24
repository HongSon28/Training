#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,m,ans=0;
    cin>>n>>m;
    int dp[n+5];
    vector<vector<int>>adj(n+5);
    for (int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    for (int i=1;i<=n;i++) dp[i]=1;
    for (int i=1;i<=n;i++) {
        stack<int>s;
        for (auto j:adj[i]) {
            s.push(j);
        }
        while (!s.empty()) {
            int t=s.top();
            s.pop();
            dp[i]=max(dp[i],dp[t]+1);
            for (auto j:adj[t]) s.push(j);
        }
    }
    for (int i=1;i<=n;i++) ans=max(ans,dp[i]);
    cout<<ans;
}
