#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5;
ll dp[N+5];
ll n,w;
ll res=0;
ll weight[N+5],value[N+5];
int main() {
    cin>>n>>w;
    for (int i=1;i<=N;i++) dp[i]=1e12;
    for (int i=1;i<=n;i++) cin>>weight[i]>>value[i];
    for (int i=1;i<=n;i++) {
        for (int j=N;j>=value[i];j--) {
            dp[j]=min(dp[j],dp[j-value[i]]+weight[i]);
        }
    }
    for (int i=1;i<=N;i++) {
        if (dp[i]<=w&&i>res)res=i;
        //cout<<dp[i]<<' ';
    }
    cout<<res;
}
