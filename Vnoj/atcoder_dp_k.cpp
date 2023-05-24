#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,k;
bool dp[N+5];
int a[101];
int main() {
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=0;i<=k;i++) dp[i]=true;
    for (int i=0;i<=k;i++) {
        for (int j=1;j<=n;j++) {
            if (a[j]<=i&&dp[i-a[j]]) dp[i]=false;
        }
    }
    if (!dp[k]) cout<<"First";
    else cout<<"Second";
}
