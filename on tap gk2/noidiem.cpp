#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,t,mx=0;
    cin>>n;
    int d[n+1]={},dp[n+1]={},trace[n+1]={};
    for (int i=1;i<=n;i++) cin>>d[i];
    for (int i=1;i<=n;i++) {
        for (int j=0;j<i;j++) {
            if (d[j]<d[i]) {
                if (dp[i]<dp[j]+1) {
                    dp[i]=dp[j]+1;
                }
            }
        }
        if (dp[i]>mx) {
            mx=dp[i];
            t=i;
        }
        //cout<<dp[i]<<' ';
    }
    cout<<mx<<endl;
    vector<int>v;
    v.push_back(t);
    int cnt=1;
    int temp=mx;
    while (true) {
        //cout<<dp[t]<<' ';
        if (dp[t]==temp-1) {
            cnt++;
            temp--;
            v.push_back(t);
        }
        if (cnt==mx) break;
        t--;
    }
    for (int i=v.size()-1;i>=0;i--) {
        cout<<d[v[i]]<<' ';
        cout<<v[i]<<endl;
    }
}
