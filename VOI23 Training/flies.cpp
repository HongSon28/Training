#include<bits/stdc++.h>
using namespace std;
const int N=5e3;
int n,k;
double dp[N+5][N/2+5];
double f(int c1,int c2) {
    if (dp[c1][c2]>=0) return dp[c1][c2];
    int fly=n-c1-c2-c2;
    if (fly==0) return dp[c1][c2]=1;
    int bowl=k-c1-c2;
    if (c1>0) return dp[c1][c2]=(f(c1+1,c2)*bowl+f(c1-1,c2+1)*c1)/k;
    return dp[c1][c2]=f(c1+1,c2)*bowl/k;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (cin>>n>>k) {
        memset(dp,-1,sizeof(dp));
        cout.precision(6);
        if (n>=k*3) cout<<fixed<<1.0;
        else cout<<fixed<<1-f(0,0);
        cout<<'\n';
    }
}
