#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6;
ll dp[N+5];
ll n,w;
ll res=0;
ll weight[N+5],value[N+5];
int main() {
    freopen("TRAVELAD.INP","r",stdin);
    freopen("TRAVELAD.OUT","w",stdout);
    cin>>n>>w;
    for (ll i=1;i<=N;i++) dp[i]=1e18;
    for (ll i=1;i<=n;i++) cin>>weight[i]>>value[i];
    for (ll i=1;i<=n;i++) {
        for (ll j=N;j>=value[i];j--) {
            dp[j]=min(dp[j],dp[j-value[i]]+weight[i]);
        }
    }
    for (ll i=1;i<=N;i++)
        if (dp[i]<=w&&i>res) res=i;
    cout<<res;
}
