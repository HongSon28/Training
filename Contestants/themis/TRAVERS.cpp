#include<bits/stdc++.h>
using namespace std;
const int N=1e5,maxN=1e8;
int bit[maxN+5];
int n,h,res;
int a[N+5],dp[N+5];
int mod=9901;
int getsum(int p) {
    int idx=p,ans=0;
    while (idx>0) {
        ans+=bit[idx];
        ans%=mod;
        idx-=(idx&(-idx));
    }
    return ans;
}
void update(int u,int v) {
    int idx=u;
    while (idx<=maxN) {
        bit[idx]+=v;
        bit[idx]%=mod;
        idx+=(idx&(-idx));
    }
}
int main() {
    freopen("TRAVERS.INP","r",stdin);
    freopen("TRAVERS.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>h;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
        dp[i]=1;
        dp[i]+=getsum(min(a[i]+h,maxN))-getsum(max(a[i]-h-1,0));
        update(a[i],dp[i]);
        res+=dp[i];
        res%=mod;
    }
    cout<<(((res-n)%mod)+mod)%mod;
}
