#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
const int mod=1e9+7;
int t,n;
int d[N+5], p[N+5];
int a[N+5];
void sang() {
    iota(d,d+N+5,0);
    for (int i=2; i*i<=N;i++) {
        if (d[i]==i)
            for (int j=i*i;j<=N;j+=i)
                if (i<d[j]) d[j]=i;
    }
}
int main() {
    freopen("SQRMUL.INP","r",stdin);
    freopen("SQRMUL.OUT","w",stdout);
    sang();
    cin>>t;
    while (t--) {
        long long res=1;
        map<long long,long long>mp;
        cin>>n;
        for (int i=0;i<n;i++) cin>>a[i];
        for (int i=0;i<n;i++) {
            a[i]=abs(a[i]);
            while (a[i]>1) {
                long long div=d[a[i]];
                long long t=0;
                for (;a[i]%div==0;a[i]/=div) t++;
                if (mp[div]<t) mp[div]=t;
            }
        }
        for (auto i=mp.begin();i!=mp.end();i++) {
            long long f=i->first;
            long long s=i->second;
            if (s%2==1) s++;
            //cout<<f<<' '<<s<<endl;
            for (int j=1;j<=s;j++) {
                res*=f;
                res%=mod;
            }
        }
        cout<<res<<endl;
    }
}
