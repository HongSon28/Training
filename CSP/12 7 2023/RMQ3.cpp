#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
const int MX=20;
long long mod=1e9+7;
int n,s;
int a[N+5];
int rm1[N+5][MX+1],rm2[N+5][MX+1];
long long dp[N+5],sum[N+5];
bool check(int l,int r) {
    int len=r-l+1;
    int k=__lg(len);
    int mn=min(rm1[l][k],rm1[r-(1<<k)+1][k]);
    int mx=max(rm2[l][k],rm2[r-(1<<k)+1][k]);
    if (mx-mn<=s) return true;
    return false;
}
int bs(int i) {
    int res;
    int lo=1,hi=i;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (check(mid,i)) {
            res=mid;
            hi=mid-1;
        } else lo=mid+1;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("RMQ3.INP","r",stdin);
    freopen("RMQ3.OUT","w",stdout);
    cin>>n>>s;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        rm1[i][0]=a[i];
        rm2[i][0]=a[i];
    }
    for (int j=1;j<=MX;j++) {
        for (int i=1;i<=n-(1<<j)+1;i++) {
            rm1[i][j]=min(rm1[i][j-1],rm1[i+(1<<(j-1))][j-1]);
            rm2[i][j]=max(rm2[i][j-1],rm2[i+(1<<(j-1))][j-1]);
        }
    }
    sum[0]=1;
    for (int i=1;i<=n;i++) {
        int j=bs(i);
        //sum[0]=0;566666
        if (j>=2)
            dp[i]=(((sum[i-1]-sum[j-2])%mod)+mod)%mod;
        else
            dp[i]=sum[i-1]%mod;
        sum[i]=(sum[i-1]+dp[i])%mod;
        //cout<<j<<' '<<i<<' '<<dp[i]<<' '<<sum[i]<<endl;
    }
    cout<<dp[n]%mod;
}
