#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
vector<vector<int>>adj(N+5);
long long mod=1e9+7;
long long dfs(int u) {
    long long ans=1;
    for (auto v:adj[u]) {
        ans*=dfs(v);
        ans%=mod;
    }
    //cout<<u<<' '<<ans+1<<endl;
    return (ans+1)%mod;
}
int main() {
    freopen("BAI4.INP","r",stdin);
    freopen("BAI4.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<n;i++) {
        int t;
        cin>>t;
        adj[t].push_back(i);
    }
    if (n==1) {
        cout<<1;
        return 0;
    }
    cout<<((dfs(n)-1)+mod)%mod;
}
