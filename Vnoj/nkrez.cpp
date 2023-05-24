#include<bits/stdc++.h>
using namespace std;
int main() {
    long long res=0;
    int n;
    cin>>n;
    pair<long long,long long>p[n+1];
    long long dp[n+1]={};
    for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    sort(p+1,p+1+n);
    for (int i=1;i<=n;i++) {
        dp[i]=p[i].second-p[i].first;
        for (int j=1;j<i;j++) {
            if(p[j].second<=p[i].first) dp[i]=max(dp[i],dp[j]+p[i].second-p[i].first);
        }
        res=max(res,dp[i]);
    }
    cout<<res;
}
