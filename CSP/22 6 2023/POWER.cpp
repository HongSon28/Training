#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
long long n,k;
long long res=1;
long long a[N+5];
map<long long,long long>mp;
int main() {
    freopen("POWER.INP","r",stdin);
    freopen("POWER.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    long long lcm=a[1];
    for (int i=2;i<=n;i++) {
        long long t=__gcd(lcm,a[i]);
        lcm=lcm*a[i]/t;
    }
    long long div=2;
    while (lcm>1) {
        while (lcm%div==0) {
            mp[div]++;
            lcm/=div;
        }
        div++;
    }
    for (auto i=mp.begin();i!=mp.end();i++) {
        long long f=i->first,s=i->second;
        long long t;
        if (s%k==0) t=s;
        else t=(s/k+1)*k;
        long long j=t/k;
        for (int m=1;m<=j;m++) res*=f;
    }
    cout<<res;
}
