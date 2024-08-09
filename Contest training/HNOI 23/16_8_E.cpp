#include<bits/stdc++.h>
using namespace std;
const int N=500;
int dp[N+5][N+5],mn[N+5][N+5],mx[N+5][N+5];
int a[N+5];
int inf=1e9;
int n;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        dp[i][i]=0,mn[i][i]=mx[i][i]=a[i];
    }
    for (int len=2;len<=n;len++){}
}
