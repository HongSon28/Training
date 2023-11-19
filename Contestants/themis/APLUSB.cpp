#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
string c;
int n;
long long mod=1e9+7;
long long dp[N+5][10][10][2];
long long f(int i,int a,int b,int rem) {
    if (i==1) return (a!=0&&b!=0);
    if (dp[i][a][b][rem]!=-1) return dp[i][a][b][rem];
    int temp=c[i-1]-'0';
    long long ans=0;
    for (int x=0;x<=9;x++) {
        if (x==a) continue;
        int y=temp-x-rem;
        if (y==b) continue;
        if (y<0) continue;
        ans+=f(i-1,x,y,0);
        ans%=mod;
    }
    if (i!=2) {
        temp+=10;
        for (int x=0;x<=9;x++) {
            if (x==a) continue;
            int y=temp-x-rem;
            if (y==b) continue;
            if (y<0||y>=10) continue;
            ans+=f(i-1,x,y,1);
            ans%=mod;
        }
    }
    dp[i][a][b][rem]=ans;
    //cout<<i<<' '<<a<<' '<<b<<' '<<rem<<' '<<ans<<endl;
    return ans;
}
int main() {
    freopen("APLUSB.INP","r",stdin);
    freopen("APLUSB.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(dp,-1,sizeof(dp));
    cin>>c;
    n=c.size();
    c=' '+c;
    cout<<f(n+1,-1,-1,0);
}
