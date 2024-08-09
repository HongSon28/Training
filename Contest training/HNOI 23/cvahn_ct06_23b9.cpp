#include<bits/stdc++.h>
using namespace std;
const int N=200;
int n,k;
long long mod=111539786;
long long dp[N+5][(1<<10)+5];
string p[10];
int main() {
    //freopen("ASTR2.INP","r",stdin);
    //freopen("ASTR2.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while(cin>>n>>k) {
        for (int i=0;i<k;i++) {
            cin>>p[i];
            //p[i]=' '+p[i];
        }
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
    }
}
