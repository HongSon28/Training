#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int c[N+5],a[N+5];
int st[N*4+5];
long long mod=1e9+7,res;
long long dp[N+5],sum[N+5];
void build(int id,int l,int r) {
    if (l==r) {
        st[id]=__gcd(a[l],a[l+1]);
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id]=__gcd(st[id*2],st[id*2+1]);
}
int get(int id,int l,int r,int u,int v) {
    if (v<u) return a[u];
    if (u>r||v<l) return 0;
    if (u<=l&&r<=v) return st[id];
    int mid=(l+r)/2;
    return __gcd(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>c[i];
    int dif=-1;
    if (__gcd(c[n],c[1])>1) {
        for (int i=1;i<n;i++) {
            if (__gcd(c[i],c[i+1])==1) {
                dif=i;
                break;
            }
        }
    } else dif=0;
    if (dif==-1) {
        res=1;
        for (int i=1;i<=n;i++) res*=2;
        res%=mod;
        if (res==0) res=mod-1;
        else res--;
        cout<<res;
        return 0;
    }
    for (int i=1;i<=n;i++) {
        int temp=i+dif;
        if (temp>n) temp-=n;
        a[i]=c[temp];
    }
    build(1,1,n-1);
    sum[0]=1;
    for (int i=1;i<=n;i++) {
        int l=i,lo=1,hi=i;
        while (lo<=hi) {
            int mid=(lo+hi)/2;
            if (get(1,1,n-1,mid,i-1)>1) {
                l=mid;
                hi=mid-1;
            } else lo=mid+1;
        }
        l--;
        if (l==0) dp[i]=sum[i-1];
        else dp[i]=((sum[i-1]-sum[l-1])%mod+mod)%mod;
        sum[i]=(sum[i-1]+dp[i])%mod;
    }
    cout<<dp[n];
}
