#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long mod=123456789;
int n;
long long f[N+5],a[N+5],res,sum;
map<long long,int>mp;
int main() {
    freopen("CSUBSEQ.INP","r",stdin);
    freopen("CSUBSEQ.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    f[1]=1;
    f[0]=1;
    mp[a[1]]=1;
    mp[-1]=0;
    sum=2;
    for (int i=2;i<=n;i++) {
        f[i]=sum;
        if (mp[a[i]]!=0)
            sum=(sum+mod-f[mp[a[i]]])%mod;
        mp[a[i]]=i;
        sum+=f[i];
        sum%=mod;
        //cout<<f[i]<<' '<<sum<<'\n';
    }
    for (auto j=mp.begin();j!=mp.end();j++) {
        res+=f[j->second];
        res%=mod;
    }
    cout<<res;
}
