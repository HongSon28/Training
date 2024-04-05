#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long a[N+5],b[N+5],dp[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i]>>b[i];
    dp[1]=a[1];
    for (int i=2;i<=n;i++) dp[i]=min(dp[i-1]+a[i],dp[i-2]+b[i-1]);
    cout<<dp[n];
}