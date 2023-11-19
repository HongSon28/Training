#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
string k;
int d;
int n;
long long mod=1e9+7;
long long dp[N+5][2][100];
long long f(int i,bool les,int md) {
    if (i==n) return md==0;
    if (dp[i][les][md]!=-1) return dp[i][les][md];
    long long ans=0;
    for (char c='0';c<='9';c++) {
        if (les||c<=k[i+1]) {
            ans+=f(i+1,les||c<k[i+1],(md+(int)(c-'0'))%d);
            ans%=mod;
        }
    }
    dp[i][les][md]=ans;
    return ans;
}
int main() {
    freopen("DIGITSUM.INP","r",stdin);
    freopen("DIGITSUM.OUT","w",stdout);
    memset(dp,-1,sizeof(dp));
    cin>>k>>d;
    n=k.size();
    k=' '+k;
    cout<<(f(0,0,0)-1+mod)%mod;
}
