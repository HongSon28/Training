#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,s;
    cin>>n>>s;
    int tv[s+1]={};
    int a[n+1];
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    int dp[s+1]={};
    dp[0]=1;
    for (int i=1;i<=n;i++) {
        for (int j=s;j>=a[i];j--) {
            if (dp[j]==0&&dp[j-a[i]]==1) {
                dp[j]=1;
                tv[j]=i;
            }
        }
    }
    if (dp[s]==1) {
        cout<<"YES"<<endl;
        set<int>kq;
        kq.insert(tv[s]);
        int temp=s-a[tv[s]];
        while (true) {
            if (temp==0) break;
            kq.insert(tv[temp]);
            temp-=a[tv[temp]];
        }
        for (auto i:kq) cout<<i<<' ';
    } else {
        cout<<"NO";
    }
}
