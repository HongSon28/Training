#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    int a[n+1];
    for (int i=1;i<=n;i++)
        cin>>a[i];
    int dp[n+2];
    dp[0]=0;
    int ans=0;
    deque<int> dq;
    dq.push_back(0);
    for (int i=1;i<=n+1;i++) {
        ans+=a[i];
        while (!dq.empty()&&dq.front()<i-k) dq.pop_front();
        dp[i]=dp[dq.front()]+a[i];
        while (!dq.empty()&&dp[dq.back()]>=dp[i]) dq.pop_back();
        dq.push_back(i);
    }
    cout<<ans-dp[n+1];
}
