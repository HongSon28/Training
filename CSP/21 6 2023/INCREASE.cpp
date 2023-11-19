#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n;
long long a[N+5],dp[N+5];
long long res;
int main(){
    freopen("INCREASE.INP","r",stdin);
    freopen("INCREASE.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        dp[i]=1;
    }
    for (int i=2;i<=n;i++) {
        if (a[i]>a[i-1]) dp[i]=dp[i-1]+1;
        res+=dp[i];
    }
    cout<<res+1;
}
