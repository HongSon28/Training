#include<bits/stdc++.h>
using namespace std;
int a[100001];
int dp[100001];
int main() {
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++) cin>>a[i];
    dp[0]=0;
    dp[1]=abs(a[1]-a[0]);
    for (int i=2;i<n;i++) {
        int temp=INT_MAX;
        for (int j=1;j<=k;j++) {
            if (j<=i) temp=min(temp,dp[i-j]+abs(a[i]-a[i-j]));
        }
        dp[i]=temp;
    }
    cout<<dp[n-1];
}

